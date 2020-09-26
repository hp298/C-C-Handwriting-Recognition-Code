//========================================================================
// sqrt-recur-directed-test.c
//========================================================================
// This file contains the directed tests that target different categories
// for the sqrt_recur function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-recur.h"
#include <limits.h> // for INT_MAX

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Test case with simple inputs.
void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 0 ), 0 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 1 ), 1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 4 ), 2);
  UTST_ASSERT_INT_EQ( sqrt_recur( 9 ), 3);
  UTST_ASSERT_INT_EQ( sqrt_recur( 16 ), 4);
  UTST_ASSERT_INT_EQ( sqrt_recur( 25 ), 5);
  UTST_ASSERT_INT_EQ( sqrt_recur( 36 ), 6);
  UTST_ASSERT_INT_EQ( sqrt_recur( 49 ), 7);
  UTST_ASSERT_INT_EQ( sqrt_recur( 64 ), 8);
  UTST_ASSERT_INT_EQ( sqrt_recur( 81 ), 9);
  UTST_ASSERT_INT_EQ( sqrt_recur( 100 ), 10);
}

//------------------------------------------------------------------------
// test_case_2_negative
//------------------------------------------------------------------------
// Test case with negative inputs.
void test_case_2_negative()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( -10 ), -1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( -20 ), -1 );
}

//------------------------------------------------------------------------
// test_case_3_complex
//------------------------------------------------------------------------
// Test cases with complex (not round) numbers
void test_case_3_complex()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 2 ), 1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 3 ), 1 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 5 ), 2 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 6 ), 2 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 7 ), 2 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 8 ), 2 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 10 ), 3 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 13 ), 3 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 15 ), 3 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 17 ), 4 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 20 ), 4 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 24 ), 4 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 26 ), 5 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 35 ), 5 );
}

//------------------------------------------------------------------------
// test_case_4_large_nums
//------------------------------------------------------------------------
// Test cases with large numbers
void test_case_4_large_nums()
{
  printf( "\n%s\n", __func__ );
  UTST_ASSERT_INT_EQ( sqrt_recur( 176400), 420 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 152399025 ), 12345 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 99980001 ), 9999 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 400000000 ), 20000 );
  UTST_ASSERT_INT_EQ( sqrt_recur( 44435556 ), 6666 );
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );
  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_simple();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_negative();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_complex();
  if ( ( n == 0 ) || ( n == 4 ) ) test_case_4_large_nums();
  return 0;
}
