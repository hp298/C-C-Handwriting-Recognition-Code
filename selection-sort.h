//========================================================================
// selection-sort.h
//========================================================================
// Declarations for selection sort

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stdlib.h>

size_t find_min( int* arr, size_t begin, size_t end );
void   selection_sort( int arr[], size_t size );

#endif  // SELECTION_SORT_H
