//========================================================================
// quick-sort.c
//========================================================================
// Implementation of the quick sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include "quick-sort.h"

//------------------------------------------------------------------------
// partition
//------------------------------------------------------------------------
// Helper functino for quick_sort.

size_t partition( int* arr, size_t begin, size_t end )
{
  int pivot = arr[end - 1];
  
  size_t idx = begin;
  for ( unsigned int i = begin; i < end; i++ ) {
    int temp = 0;
    
    // switched when smaller than pivot
    if ( arr[i]  <= pivot ) {
      temp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = temp;
      idx += 1;
    }
  }

  return idx - 1;
}

//------------------------------------------------------------------------
// quick_sort_h
//------------------------------------------------------------------------
// helps call partition, runs the recursion
void quick_sort_h( int* arr, size_t begin, size_t end )
{
  //size_t size = end - begin;
  
  // base case
  if ( begin >= end ) {
    return;
  }
  
  size_t part = partition( arr, begin, end );
  quick_sort_h( arr, begin, part );
  quick_sort_h( arr, part + 1, end );
}

//------------------------------------------------------------------------
// quick_sort
//------------------------------------------------------------------------
// Sorts the array with quick sort.

void quick_sort( int* arr, size_t size )
{
  if ( size == 1 ) {
    return;
  }
  quick_sort_h( arr, 0, size);
}
