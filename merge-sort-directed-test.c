//========================================================================
// selection-sort-directed-tests.c
//========================================================================
// This file contains the tests for the selection sort function

#include <stdio.h>
#include <stdlib.h>
#include "utst.h"
#include "merge-sort.h"

//------------------------------------------------------------------------
// test_case_1_helper
//------------------------------------------------------------------------
// Simple test case for the helper function.

void test_case_1_helper()
{
  printf( "\n%s\n", __func__ );
  int a[] = {19, 95};
  int b[] = {4, 23};

  int c[4] = {0};

  merge( c, a, 0, 2, b, 0, 2 );

  UTST_ASSERT_INT_EQ( c[0], 4 );
  UTST_ASSERT_INT_EQ( c[1], 19 );
  UTST_ASSERT_INT_EQ( c[2], 23 );
  UTST_ASSERT_INT_EQ( c[3], 95 );
}
//------------------------------------------------------------------------
// test_case_2_helper
//------------------------------------------------------------------------
// tests when go from one array to another merge

void test_case_2_helper()
{
  printf( "\n%s\n", __func__ );
  int a[] = {80, 81, 82, 83, 84};
  int b[] = {0, 1, 2, 3, 4};

  int c[10] = {0};

  merge( c, a, 0, 5, b, 0, 5 );

  UTST_ASSERT_INT_EQ( c[0], 0 );
  UTST_ASSERT_INT_EQ( c[1], 1 );
  UTST_ASSERT_INT_EQ( c[2], 2 );
  UTST_ASSERT_INT_EQ( c[3], 3 );
  UTST_ASSERT_INT_EQ( c[4], 4 );
  UTST_ASSERT_INT_EQ( c[5], 80 );
  UTST_ASSERT_INT_EQ( c[6], 81 );
  UTST_ASSERT_INT_EQ( c[7], 82 );
  UTST_ASSERT_INT_EQ( c[8], 83 );
  UTST_ASSERT_INT_EQ( c[9], 84 );
}

//------------------------------------------------------------------------
// test_case_3_helper
//------------------------------------------------------------------------
// test if both are 1 length

void test_case_3_helper()
{
  printf( "\n%s\n", __func__ );
  int a[] = {60};
  int b[] = {9};

  int c[2] = {0};

  merge( c, a, 0, 1, b, 0, 1 );

  UTST_ASSERT_INT_EQ( c[0], 9 );
  UTST_ASSERT_INT_EQ( c[1], 60 );
}

//------------------------------------------------------------------------
// test_case_4_merge_sort
//------------------------------------------------------------------------
// simple merge sort test

void test_case_4_merge_sort()
{
  printf( "\n%s\n", __func__ );
  int a[] = {3, 0, 2, 1};
  size_t size = 4;

  merge_sort( a, size );

  UTST_ASSERT_INT_EQ( a[0], 0 );
  UTST_ASSERT_INT_EQ( a[1], 1 );
  UTST_ASSERT_INT_EQ( a[2], 2 );
  UTST_ASSERT_INT_EQ( a[3], 3 );
}

//------------------------------------------------------------------------
// test_case_5_merge_sort
//------------------------------------------------------------------------
// merge sort with one number
void test_case_5_merge_sort()
{
  printf( "\n%s\n", __func__ );
  int a[] = {0};
  size_t size = 1;

  merge_sort( a, size );

  UTST_ASSERT_INT_EQ( a[0], 0 );
}

//------------------------------------------------------------------------
// test_case_6_merge_sort
//------------------------------------------------------------------------
// merge negative numbers

void test_case_6_merge_sort()
{
  printf( "\n%s\n", __func__ );
  int a[] = {-3, 0, 2, -1};
  size_t size = 4;

  merge_sort( a, size );

  UTST_ASSERT_INT_EQ( a[0], -3 );
  UTST_ASSERT_INT_EQ( a[1], -1 );
  UTST_ASSERT_INT_EQ( a[2], 0 );
  UTST_ASSERT_INT_EQ( a[3], 2 );
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_helper();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_helper();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_helper();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_merge_sort();
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_merge_sort();
  if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_merge_sort();

  

  return 0;
}
