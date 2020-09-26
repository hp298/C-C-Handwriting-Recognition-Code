//========================================================================
// bucket-sort.c
//========================================================================
// Implementation of the bucket sort function
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include <limits.h> // INT_MAX & INT_MIN
#include "ece2400-stdlib.h"
#include "vector.h"
#include "bucket-sort.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Define K as the number of buckets
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
#define K 4

//------------------------------------------------------------------------
// bucket_sort
//------------------------------------------------------------------------
// Sorts the array with bucket sort

void bucket_sort( int* a, size_t size )
{
  int min = INT_MAX;
  int max = INT_MIN;
  
  // find min and max of arr
  for( size_t i = 0; i < size; i++) {
    if ( a[i] < min ) {
      min = a[i];
    }
    if ( a[i] > max ) {
      max = a[i];
    }
  }

  
  // bucket ranges
  int range = ( ( max - min) / K );
  
  // make the buckets
  vector_int_t bucket1;
  vector_int_t bucket2;
  vector_int_t bucket3;
  vector_int_t bucket4;
  
  vector_int_construct( &bucket1 ); 
  vector_int_construct( &bucket2 ); 
  vector_int_construct( &bucket3 ); 
  vector_int_construct( &bucket4 ); 
  
  // place the values of the array into each bucket
  for( size_t i = 0; i < size; i++) {
    
    // buckets
    if ( ( a[i] >=   min ) && 
         ( a[i] <  ( min + range ) ) ) {
      vector_int_push_back( &bucket1, a[i] );
    }
    else if ( ( a[i] >= ( min + range ) ) && 
              ( a[i] <  ( min + ( 2 * range ) ) ) ) {
      vector_int_push_back( &bucket2, a[i] );
    }
    else if ( ( a[i] >= ( min + ( 2 * range ) ) ) && 
              ( a[i] <  ( min + ( 3 * range ) ) ) ) {
      vector_int_push_back( &bucket3, a[i] );
    }
    else {
      vector_int_push_back( &bucket4, a[i] );
    }
  }

  // sort each bucket
  vector_int_sort( &bucket1 );
  vector_int_sort( &bucket2 );
  vector_int_sort( &bucket3 );
  vector_int_sort( &bucket4 );

  // get size of each bucket
  size_t size1 = vector_int_size( &bucket1 );
  size_t size2 = vector_int_size( &bucket2 );
  size_t size3 = vector_int_size( &bucket3 );
  //size_t size4 = vector_int_size( &bucket4 );
  
  size_t b1 = 0;
  size_t b2 = 0;
  size_t b3 = 0;
  size_t b4 = 0;
  
  // write sorted values in order
  for (size_t i = 0; i < size; i++) {
    
    // buckets
    if ( i < size1 ) {
      a[i] = vector_int_at( &bucket1, b1 );
      b1 += 1;
    }
    else if ( i < ( size1 + size2 ) ) {
      a[i] = vector_int_at( &bucket2, b2 );
      b2 += 1;
    }
    else if ( i < ( size1 + size2 + size3 ) ) {
      a[i] = vector_int_at( &bucket3, b3 );
      b3 += 1;
    }
    else {
      a[i] = vector_int_at( &bucket4, b4 );
      b4 += 1;
    }
  }
  
  // destruct all buckets
  vector_int_destruct( &bucket1 );
  vector_int_destruct( &bucket2 );
  vector_int_destruct( &bucket3 );
  vector_int_destruct( &bucket4 );
}
