#ifndef PRIVATE_ARENA_H
#define PRIVATE_ARENA_H

#include <stddef.h>


struct CJR_Arena {
    void * begin;
    size_t size;
    size_t offset;
};

#endif
