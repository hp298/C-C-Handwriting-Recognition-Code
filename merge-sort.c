//========================================================================
// merge-sort.c
//========================================================================
// Implementation of the merge sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include "merge-sort.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// merge
//------------------------------------------------------------------------
// Helper function that merges two sorted arrays.

void merge( int* dst,
            int* src0, size_t begin0, size_t end0,
            int* src1, size_t begin1, size_t end1 )
{
  unsigned int size = (end0 - begin0) + (end1 - begin1);
  unsigned int idx0 = begin0;
  unsigned int idx1 = begin1;
  
  for ( unsigned int i = 0; i < size; i++ ) {
    
    // src0 is done
    if ( idx0 == end0 ) {
      dst[i] = src1[idx1];
      idx1 += 1;
    }
    
    // src1 is done
    else if ( idx1 == end1 ) {
      dst[i] = src0[idx0];
      idx0 += 1;
    }
    
    // scr0 < src1
    else if ( src0[idx0] < src1[idx1] ) {
      dst[i] = src0[idx0];
      idx0 += 1;
    }
    
    // src1 < src0
    else {
      dst[i] = src1[idx1];
      idx1 += 1;
    }
    
  }
}

//------------------------------------------------------------------------
// merge_sort
//------------------------------------------------------------------------
// Sorts the array with merge sort.

void merge_sort( int* arr, size_t size )
{
  // base case
  if ( size <= 1 ) {
    return;
  }
  
  size_t size_h1 = size / 2;
  size_t size_h2 = size - size_h1;
  
  int* arr1 = ece2400_malloc( size_h1 * sizeof(int) );
  int* arr2 = ece2400_malloc( size_h2 * sizeof(int) );
  
  // split the array into two arrays
  for ( unsigned int i = 0; i < size_h1; i++ ) {
    arr1[i] = arr[i];
  }
  
  for ( unsigned int i = 0; i < size_h2; i++ ) { 
    arr2[i] = arr[i + size_h1];
  }
  
  // partitions the arrays
  merge_sort( arr1, size_h1 );
  merge_sort( arr2, size_h2 );
  
  // merges the individual partitions
  int* temp = ece2400_malloc( size * sizeof(int));
  merge( temp, arr1, 0, size_h1, arr2, 0, size_h2 );
  
  // copy temp array to input array
  unsigned int j = 0;
  for ( unsigned int i = 0; i < size; i++ ) {
    arr[i] = temp[j];
    j += 1;
  }
  ece2400_free(arr1);
  ece2400_free(arr2);
  ece2400_free(temp);
  
}
