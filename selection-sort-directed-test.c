//========================================================================
// selection-sort-directed-tests.c
//========================================================================
// This file contains the tests for the selection sort function

#include <stdio.h>
#include <stdlib.h>
#include "utst.h"
#include "selection-sort.h"

//------------------------------------------------------------------------
// test_case_1_helper
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_helper()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {11, 7, 20, 0};
  UTST_ASSERT_INT_EQ( find_min( arr, 0, 4 ), 3  );
  UTST_ASSERT_INT_EQ( find_min( arr, 0, 3 ), 1 );
  UTST_ASSERT_INT_EQ( find_min( arr, 0, 2 ), 1 );
  UTST_ASSERT_INT_EQ( find_min( arr, 0, 1 ), 0 );
}

//------------------------------------------------------------------------
// test_case_2_helper
//------------------------------------------------------------------------
// Test from non 0 begin

void test_case_2_helper()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {11, 7, 20, 0, 4, 9, 15, 19};
  UTST_ASSERT_INT_EQ( find_min( arr, 1, 8 ), 3 );
  UTST_ASSERT_INT_EQ( find_min( arr, 2, 8 ), 3 );
  UTST_ASSERT_INT_EQ( find_min( arr, 3, 8 ), 3 );
  UTST_ASSERT_INT_EQ( find_min( arr, 4, 8 ), 4 );
}

//------------------------------------------------------------------------
// test_case_3_sort
//------------------------------------------------------------------------
// Simple test case for selection sort

void test_case_3_sort()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {11, 7, 20, 0};
  int sort_arr[] = {0, 7, 11, 20};
  selection_sort( arr, 4 );
  for( int i = 0; i < 4; i++ ) {
    UTST_ASSERT_INT_EQ( arr[i] , sort_arr[i] );
  }
  
}

//------------------------------------------------------------------------
// test_case_4_sort_multi
//------------------------------------------------------------------------
// Test case where the array has multiple of the same number

void test_case_4_sort_multi()
{
  printf( "\n%s\n", __func__ );
  int arr[] = {0, 11, 99, 30, 1, 17, 22, 11, 6, 66, 3, 7, 20, 0, 11};
  int sort_arr[] = {0, 0, 1, 3, 6, 7, 11, 11, 11, 17, 20, 22, 30, 66, 99};
  selection_sort( arr, 15 );
  for( int i = 0; i < 15; i++ ) {
    UTST_ASSERT_INT_EQ( arr[i] , sort_arr[i] );
  }
}


//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_helper();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_helper();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_sort();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_sort_multi();

  return 0;
}
