//
// Created by dos DRTT on 3/17/19.
//

#ifndef GUNREDIS_BOOT_HPP
#define GUNREDIS_BOOT_HPP

#endif //GUNREDIS_BOOT_HPP

#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>

#define PORT 7769

namespace gun_std {

    class Server {
    public:
        virtual int init() = 0;
        virtual int sync() = 0;

        virtual void operator+(Server &server) = 0;

        virtual void operator+(Server *server) = 0;

    };

    /**
     *
     */
    class GunRedisServer : public Server {
    public:

        GunRedisServer() = default;

        explicit GunRedisServer(int port);

        ~GunRedisServer() = default;

        int init() override;

        inline int init_parameters(sockaddr_in &server_addr);

        int first_check(sockaddr_in &server_addr);

        void operator+(Server &server) override ;

        void operator+(Server *server) override ;

        int sync() override ;


    private:
        bool serveron = true;
        int socketfd = 0;
        socklen_t addrlen = sizeof(struct sockaddr_in);
        int port =PORT;


    };
}