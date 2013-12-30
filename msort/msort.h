#include <stddef.h>

typedef int (*comparator)(void* prev, void* next);

int merge(void* destination, void* left, void* right, size_t leftLength, size_t rightLength, size_t elementSize,comparator cmp);
void msort(void* base, int numberOfElements, int elementSize, comparator comp);