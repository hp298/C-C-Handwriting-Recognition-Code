//========================================================================
// vector-random-test.c
//========================================================================
// This file contains contains random tests for vector-related functions.

#include <stdio.h>
#include "utst.h"
#include "vector.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
// Students: This test case does nothing. You need to replace this test
// case with your own random test case.

void test_case_1_v1()
{
  printf( "\n%s\n", __func__ );
  srand( 0xDeadFa11 );
  
  vector_int_t vec;
  vector_int_construct( &vec );

  // array to keep track
  int a[100];

  // Push back some random elements
  for ( int i = 0; i < 100; i++ ) {
    int x = rand();
    a[i] = x;
    vector_int_push_back_v1( &vec,  x);
  }

  // Try finding them
  for ( int i = 0; i < 100; i++ ) {
    vector_int_print(&vec);
    UTST_ASSERT_INT_EQ( vector_int_at  ( &vec, i ), a[i]);
    UTST_ASSERT_TRUE( vector_int_find( &vec, a[i] ) );
  }

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 100 );

  vector_int_destruct( &vec );
}

void test_case_2_v2()
{
   printf( "\n%s\n", __func__ );
  srand( 0xDeadFa11 );
  
  vector_int_t vec;
  vector_int_construct( &vec );

  // array to keep track
  int a[100];

  // Push back some random elements
  for ( int i = 0; i < 100; i++ ) {
    int x = rand();
    a[i] = x;
    vector_int_push_back_v2( &vec, x );
  }

  // Try finding them
  for ( int i = 0; i < 100; i++ ) {
    UTST_ASSERT_INT_EQ( vector_int_at  ( &vec, i ), a[i]);
    UTST_ASSERT_TRUE( vector_int_find( &vec, a[i] ) );
  }

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 100 );

  vector_int_destruct( &vec );
}

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_v1();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_v2();
  
  return 0;
}
