//========================================================================
// selection-sort.c
//========================================================================
// Implementation of the selection sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include "selection-sort.h"

//------------------------------------------------------------------------
// find_min
//------------------------------------------------------------------------
// find the index of the minimum number in the array.

size_t find_min( int* arr, size_t begin, size_t end )
{
  int min_value = arr[begin];
  unsigned int min_idx = begin;
  
  for( unsigned int i = begin; i < end; i++ ) {
    if ( arr[i] < min_value ) {
      min_value = arr[i];
      min_idx = i;
    }
  }
  
  return min_idx;
}

//------------------------------------------------------------------------
// selection_sort
//------------------------------------------------------------------------
// Sorts the array with selection sort

void selection_sort( int* arr, size_t size )
{
  int temp = 0;
  unsigned int idx = arr[0];
  
  if ( size <= 1 ) {
    return; 
  }
  
  for( unsigned int i = 0; i < size; i++ ) {
    idx = find_min( arr, i, size );
    temp = arr[i];
    arr[i] = arr[idx];
    arr[idx] = temp;
  }
  return;
}
