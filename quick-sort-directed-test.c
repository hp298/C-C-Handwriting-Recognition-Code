//========================================================================
// quick-sort-directed-tests.c
//========================================================================
// This file contains the tests for the quick sort function

#include <stdio.h>
#include <stdlib.h>
#include "utst.h"
#include "quick-sort.h"

//------------------------------------------------------------------------
// test_case_1_helper
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_helper()
{
  printf( "\n%s\n", __func__ );

  size_t size = 8;
  int    a[]  = {1, 9, 9, 5, 0, 4, 2, 3};
  size_t p    = partition( a, 0, size );

  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ )
    UTST_ASSERT_TRUE( a[i] <= a[p] )

  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ )
    UTST_ASSERT_TRUE( a[i] >= a[p] )
}

//------------------------------------------------------------------------
// test_case_2_helper
//------------------------------------------------------------------------
// Simple test case for the helper function.
void test_case_2_helper()
{
  printf( "\n%s\n", __func__ );

  size_t size = 2;
  int    a[]  = {10, 9};
  size_t p    = partition( a, 0, size );

  // Check if elements to the left of pivot is not greater than the pivot
  for ( size_t i = 0; i < p; i++ )
    UTST_ASSERT_TRUE( a[i] <= a[p] )

  // Check if elements to the right of pivot is not smaller than the pivot
  for ( size_t i = p; i < size; i++ )
    UTST_ASSERT_TRUE( a[i] >= a[p] )
}

//------------------------------------------------------------------------
// test_case_3_basic
//------------------------------------------------------------------------
// Basic quick_sort test.
void test_case_3_basic()
{
  printf( "\n%s\n", __func__ );

  // initialize size, unsorted array, and sorted one
  size_t size = 8;
  int    a[]  = {1, 9, 43, 2, 27, 99, 6, 0};
  int    b[]  = {0, 1, 2, 6, 9, 27, 43, 99};
  
  // sort unsorted array with quicksort
  quick_sort( a, size );
  
  // check if they are the same
  for( int i = 0; i < 8; i++ ) {
    UTST_ASSERT_INT_EQ( a[i] , b[i] );
  }
}

//------------------------------------------------------------------------
// test_case_4_negative
//------------------------------------------------------------------------
// Basic quick sort test with some negative numbers
void test_case_4_negative()
{
  printf( "\n%s\n", __func__ );

  // initialize size, unsorted array, and sorted one
  size_t size = 8;
  int    a[]  = {1, 9, -43, -2, 27, 99, 6, 0};
  int    b[]  = {-43, -2, 0, 1, 6, 9, 27, 99};
  
  // sort unsorted array with quicksort
  quick_sort( a, size );
  
  // check if they are the same
  for( int i = 0; i < 8; i++ ) {
    UTST_ASSERT_INT_EQ( a[i] , b[i] );
  }
}

//------------------------------------------------------------------------
// test_case_5_one
//------------------------------------------------------------------------
// sort one element
void test_case_5_one()
{
  printf( "\n%s\n", __func__ );

  // initialize size, unsorted array, and sorted one
  size_t size = 1;
  int    a[]  = {4};
  int    b[]  = {4};
  
  // sort unsorted array with quicksort
  quick_sort( a, size );
  
  // check if they are the same
  UTST_ASSERT_INT_EQ( a[0] , b[0] );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_helper();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_helper();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_basic();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_negative();
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_one();

  

  return 0;
}
