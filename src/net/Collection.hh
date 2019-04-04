//
// Created by dos DRTT on 4/3/19.
//

#ifndef GUNREDIS_COLLECTION_HH
#define GUNREDIS_COLLECTION_HH
#endif
#ifdef __APPLE__
#include <AvailabilityMacros.h>

#endif
#ifdef __linux__
#define HAVE_EPOLL 1
#endif

#ifdef HAVE_EVPORT
#define dd
#endif
#ifdef HAVE_KQUEUE

class Collection {

};


#endif //GUNREDIS_COLLECTION_HH
