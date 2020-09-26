//========================================================================
// bucket-sort-directed-tests.c
//========================================================================
// This file contains the tests for the bucket sort function

#include <stdio.h>
#include <stdlib.h>
#include "utst.h"
#include "bucket-sort.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Simple test case that sorts 4 numbers.

void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );

  int size    = 4;
  int a[]     = {20, 0, 11, 7};
  int a_ref[] = {0, 7, 11, 20};
  bucket_sort( a, size );

  for ( int i = 0; i < size; i++ )
    UTST_ASSERT_INT_EQ( a[i], a_ref[i] );
}

//------------------------------------------------------------------------
// test_case_2_one
//------------------------------------------------------------------------
// Simple test case that sorts 1 number

void test_case_2_one()
{
  printf( "\n%s\n", __func__ );

  int size    = 1;
  int a[]     = {20};
  int a_ref[] = {20};
  bucket_sort( a, size );

  UTST_ASSERT_INT_EQ( a[0], a_ref[0] );
}

//------------------------------------------------------------------------
// test_case_3_negative
//------------------------------------------------------------------------
// Simple test case that sorts 4 numbers, some negative.

void test_case_3_negative()
{
  printf( "\n%s\n", __func__ );

  int size    = 4;
  int a[]     = {-20, 0, 11, -7};
  int a_ref[] = {-20, -7, 0, 11};
  bucket_sort( a, size );

  for ( int i = 0; i < size; i++ )
    UTST_ASSERT_INT_EQ( a[i], a_ref[i] );
}

//------------------------------------------------------------------------
// test_case_4_large_range
//------------------------------------------------------------------------
// Simple test case that sorts 4 numbers that have a large range.

void test_case_4_large_range()
{
  printf( "\n%s\n", __func__ );

  int size    = 4;
  int a[]     = {20000, 0, 11, -70000};
  int a_ref[] = {-70000, 0, 11, 20000};
  bucket_sort( a, size );

  for ( int i = 0; i < size; i++ )
    UTST_ASSERT_INT_EQ( a[i], a_ref[i] );
}

//------------------------------------------------------------------------
// test_case_5_small_range
//------------------------------------------------------------------------
// Simple test case that sorts 4 numbers that are a small range

void test_case_5_small_range()
{
  printf( "\n%s\n", __func__ );

  int size    = 4;
  int a[]     = {1, 0, 2, 3};
  int a_ref[] = {0, 1, 2, 3};
  bucket_sort( a, size );

  for ( int i = 0; i < size; i++ )
    UTST_ASSERT_INT_EQ( a[i], a_ref[i] );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_one();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_negative();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_large_range();
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_small_range();

  return 0;
}
