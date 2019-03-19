//
// Created by dos DRTT on 3/17/19.
//

#include <zconf.h>
#include <fcntl.h>
#include <vector>
#include "Boot.hpp"

namespace gun_std {
    int GunRedisServer::init() {
        sockaddr_in server_addr{};
        int check_code = this->first_check(server_addr);
        if (check_code == 0) {
            std::cout << "server init succeed socket fd:" << this->socketfd << std::endl;
        } else {
            std::cout << "server init faile erro rcode :" << check_code << std::endl;
        }
        return check_code;
    }


    int GunRedisServer::first_check(sockaddr_in &server_addr) {
        int on = 1;
        if ((this->socketfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            std::cout << "create socket err \n";
        }

        this->init_parameters(server_addr);

        if (setsockopt(this->socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
            std::cerr << "bind socket error: " << strerror(errno) << "(errno:" << errno << ")";
            return -1;
        }
        if (bind(this->socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            std::cerr << "bind socket error: " << strerror(errno) << "(errno:" << errno << ")";
            return -2;
        }
        if (listen(this->socketfd, 20) == -1) {
            std::cerr << "listen socket error: " << strerror(errno) << "errno: " << errno << ")";
            return -4;
        }

        return 0;
    }

    inline int GunRedisServer::init_parameters(sockaddr_in &server_addr) {
        memset(&server_addr, 0, addrlen);
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(PORT);
        return 0;
    }

    void GunRedisServer::operator+(GunRedisServer &server) {
        std::cerr << "operator invdia" << std::endl;
    }

    int GunRedisServer::sync() {
        int pid;
        int connetfd;
        sockaddr_in client_addr{};
        int flags;
        std::vector<int> vectorfd;
        while (this->serveron) {
            if ((connetfd = accept(this->socketfd, (struct sockaddr *) &client_addr, &addrlen)) == -1) {
                std::cerr << "accept socket error: %s(errno: %d)", strerror(errno), errno;
                continue;
            }
            std::cout << "host connected %d" << connetfd << std::endl;

            /* set NONBLOCK */
            flags = fcntl(connetfd, F_GETFL, 0);
            fcntl(connetfd, F_SETFL, flags | O_NONBLOCK);
            signal(SIGCHLD, SIG_IGN);
            vectorfd.push_back(connetfd);
            pid = fork();

            if (pid == -1) {
                std::cerr << "fork err \n";
            }

            if (pid == 0) {
                while (select(static_cast<int>(vectorfd.size() + 1), reinterpret_cast<fd_set *>(&vectorfd[0]), nullptr,
                              nullptr, nullptr) > 0) {
                    std::cout << "data created";
                }
            } else {
                continue;
            }

        }
        return 0;
    }

    GunRedisServer::GunRedisServer(int port) : port(port) {

    }

}