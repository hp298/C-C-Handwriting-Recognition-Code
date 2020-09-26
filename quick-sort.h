//========================================================================
// quick-sort.h
//========================================================================
// Declarations for quick sort

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdlib.h>

size_t partition( int* arr, size_t begin, size_t end );
void   quick_sort( int arr[], size_t size );

#endif  // QUICK_SORT_H
