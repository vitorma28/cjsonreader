#include <stddef.h>

#define KB(B) (B * 1024)

#define MB(B) KB(B * 1024)


typedef struct {
    const void * begin;
    const void * end;
    size_t size;
    size_t offset;
} Arena;
