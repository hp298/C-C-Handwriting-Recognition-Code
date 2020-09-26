//========================================================================
// list-random-test.c
//========================================================================
// This file contains the tests with randomly generated inputs

#include <stdio.h>
#include "utst.h"
#include "list.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------
//
void test_case_1_simple()
{
  printf( "\n%s\n", __func__ );
  srand( 0x8badF00D );

  // cerate list
  list_int_t lst;
  list_int_construct( &lst );
  
  // create an array to referece back to for check
  int a[100];
  
  // create list with random inputs
  for ( int i = 0; i < 100; i++ ) {
    int x = rand();
    a[i] = x;
    list_int_push_back( &lst, x );
  }
    
  // loops for check
  for ( int j = 0; j < 100; j++ ) {
    UTST_ASSERT_INT_EQ( list_int_at( &lst, j ), a[j] );
    UTST_ASSERT_INT_EQ( list_int_find( &lst, a[j] ), 1 );
  }
  
  // check size
  UTST_ASSERT_INT_EQ( list_int_size( &lst ), 100 );
  
  //
  
  list_int_destruct( &lst );
}


//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple();

  return 0;
}
