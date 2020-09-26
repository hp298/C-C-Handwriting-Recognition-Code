//========================================================================
// vector-directed-test.c
//========================================================================
// This file contains directed tests for vector-related functions.

#include <stdio.h>
#include "utst.h"
#include "vector.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests one element push back.

void test_case_1_simple_push_back()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  vector_int_push_back( &vec, 0xbad22222 );
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 1 );
  UTST_ASSERT_INT_EQ( vector_int_at( &vec, 0 ), 0xbad22222 );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_2_simple_find
//------------------------------------------------------------------------
// Push 2 elements and see if they can still be found.

void test_case_2_simple_find()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // Push back some elements
  for ( int i = 0; i < 2; i++ )
    vector_int_push_back( &vec, i );

  // Try finding them
  for ( int i = 0; i < 2; i++ )
    UTST_ASSERT_TRUE( vector_int_find( &vec, i ) )

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 2 );

  vector_int_destruct( &vec );
}
//------------------------------------------------------------------------
// test_case_3_size
//------------------------------------------------------------------------
// check size
void test_case_3_size()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // empty vector
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 0 );
  
  // Push back some elements
  for ( int i = 0; i < 6; i++ )
    vector_int_push_back( &vec, i );

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 6 );

  vector_int_destruct( &vec );
}
// test_case_4_simple_push_back
//------------------------------------------------------------------------
// 

void test_case_4_simple_push_back()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  vector_int_push_back( &vec, 0xbad22222 );
  UTST_ASSERT_INT_EQ( vector_int_size( &vec    ), 1          );
  UTST_ASSERT_INT_EQ( vector_int_at  ( &vec, 0 ), 0xbad22222 );

  vector_int_destruct( &vec );
}
//------------------------------------------------------------------------
// test_case_5_push_back
//------------------------------------------------------------------------
// 

void test_case_5_push_back()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // Push back some elements
  for ( int i = 0; i < 8; i++ )
    vector_int_push_back( &vec, i );

  // Try finding them
  for ( int i = 0; i < 8; i++ ) {
    UTST_ASSERT_INT_EQ( vector_int_at  ( &vec, i ), i);
    UTST_ASSERT_TRUE( vector_int_find( &vec, i ));
  }

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 8 );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// test_case_6_at
//------------------------------------------------------------------------
// 

void test_case_6_at()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // Push back some elements
  for ( int i = 0; i < 10; i++ )
    vector_int_push_back( &vec, i );

  // Find them, and use at
  for ( int i = 0; i < 10; i++ ) {
    UTST_ASSERT_TRUE( vector_int_find( &vec, i ));
    UTST_ASSERT_INT_EQ( vector_int_at( &vec, i), i );
  }

  // Check size
  UTST_ASSERT_INT_EQ( vector_int_size( &vec ), 10 );

  vector_int_destruct( &vec );
}
//------------------------------------------------------------------------
// test_case_7_at_specific
//------------------------------------------------------------------------
// 
void test_case_7_at_specific()
{
  printf( "\n%s\n", __func__ );

  vector_int_t vec;
  vector_int_construct( &vec );

  // check at empty (out of bounds)
  UTST_ASSERT_INT_EQ( vector_int_at( &vec, 0 ), 0 );
  
  // Push back some elements
  vector_int_push_back( &vec, 12345 );
  vector_int_push_back( &vec, 67890 );

  // find it
  UTST_ASSERT_INT_EQ( vector_int_at( &vec, 0 ), 12345 );
  UTST_ASSERT_INT_EQ( vector_int_at( &vec, 1 ), 67890 );
  
  // out of bounds
  UTST_ASSERT_INT_EQ( vector_int_at( &vec, 2 ), 0 );

  vector_int_destruct( &vec );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple_push_back();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_simple_find();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_size();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_simple_push_back();
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_push_back();
  if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_at();
  if ( ( __n == 0 ) || ( __n == 7 ) ) test_case_7_at_specific();

}

