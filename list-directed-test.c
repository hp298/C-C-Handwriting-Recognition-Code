//========================================================================
// list-directed-test.c
//========================================================================
// This section contains directed tests for list-related functions.

#include <stdio.h>
#include "utst.h"
#include "list.h"

//------------------------------------------------------------------------
// test_case_1_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests one element push back.

void test_case_1_simple_push_back()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );

  list_int_push_back( &lst, 0x22222bad );
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), 1          );
  UTST_ASSERT_INT_EQ( list_int_at  ( &lst, 0 ), 0x22222bad );

  list_int_destruct( &lst );
}

//------------------------------------------------------------------------
// test_case_2_simple_find
//------------------------------------------------------------------------
// Push 2 elements and see if they can still be found.

void test_case_2_simple_find()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );

  // Push back some elements
  for ( int i = 0; i < 2; i++ )
    list_int_push_back( &lst, i );

  // Try finding them
  for ( int i = 0; i < 2; i++ )
    UTST_ASSERT_TRUE( list_int_find( &lst, i ) );

  // Check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 2 );

  list_int_destruct( &lst );
}
//------------------------------------------------------------------------
// test_case_3_size
//------------------------------------------------------------------------
//
void test_case_3_size()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
    // Push back some elements
  for ( int i = 0; i < 6; i++ )
    list_int_push_back( &lst, i );
    
    //check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 6);
  
  list_int_destruct( &lst );
}
//------------------------------------------------------------------------
// test_case_4_size_0
//------------------------------------------------------------------------
//
void test_case_4_size_0()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
  // check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 0 );  
  
  list_int_destruct( &lst );
}
//------------------------------------------------------------------------
// test_case_5_push_back_more
//------------------------------------------------------------------------
//
void test_case_5_push_back_more()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
  list_int_push_back( &lst, 0x22222bad );
  list_int_push_back( &lst, 0x22222bac );
  list_int_push_back( &lst, 0x22222bab );
  UTST_ASSERT_INT_EQ( list_int_size( &lst    ), 3          );
  UTST_ASSERT_INT_EQ( list_int_at  ( &lst, 0 ), 0x22222bad );
  UTST_ASSERT_INT_EQ( list_int_at  ( &lst, 1 ), 0x22222bac );
  UTST_ASSERT_INT_EQ( list_int_at  ( &lst, 2 ), 0x22222bab );
  
  list_int_destruct( &lst );
}
//------------------------------------------------------------------------
// test_case_6_at
//------------------------------------------------------------------------
//
void test_case_6_at()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
  // Push back some elements
  for ( int i = 0; i < 6; i++ )
    list_int_push_back( &lst, i );
  
  // check at
  UTST_ASSERT_INT_EQ( list_int_at( &lst, 0 ) , 0 ); 
  UTST_ASSERT_INT_EQ( list_int_at( &lst, 4 ) , 4 ); 
  
  list_int_destruct( &lst );
}
//------------------------------------------------------------------------
// test_case_7_at_out_of_bounds
//------------------------------------------------------------------------
//
void test_case_7_out_of_bounds()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
  // Push back some elements
  for ( int i = 0; i < 6; i++ )
    list_int_push_back( &lst, i );
  
  // check out of bounds
  UTST_ASSERT_INT_EQ( list_int_at( &lst, 10 ) , 0 );
  UTST_ASSERT_INT_EQ( list_int_at( &lst, -1 ) , 0 );
  
  list_int_destruct( &lst );
}//------------------------------------------------------------------------
// test_case_8_find_empty
//------------------------------------------------------------------------
//
void test_case_8_find_empty()
{
  printf( "\n%s\n", __func__ );

  list_int_t lst;
  list_int_construct( &lst );
  
  //check find
  UTST_ASSERT_INT_EQ( list_int_find( &lst, 0 ) , 0 );
  
  list_int_destruct( &lst );
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
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_size_0();
  if ( ( __n == 0 ) || ( __n == 5 ) ) test_case_5_push_back_more();
  if ( ( __n == 0 ) || ( __n == 6 ) ) test_case_6_at();
  if ( ( __n == 0 ) || ( __n == 7 ) ) test_case_7_out_of_bounds();
  if ( ( __n == 0 ) || ( __n == 8 ) ) test_case_8_find_empty();

  return 0;
}
