//========================================================================
// merge-sort.h
//========================================================================
// Declarations for merge sort

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// #include <stdlib.h>

void merge( int* dst,
            int* src0, size_t begin0, size_t end0,
            int* src1, size_t begin1, size_t end1 );

void merge_sort( int* arr, size_t size );

#endif  // MERGE_SORT_H
