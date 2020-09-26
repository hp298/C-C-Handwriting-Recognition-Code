//========================================================================
// sqrt-iter-random-test.c
//========================================================================
// This file contains the tests with randomly generated inputs for the
// sqrt_iter function.

#include <stdio.h>
#include <math.h>
#include "utst.h"
#include "sqrt-iter.h"
#include <limits.h> // for INT_MAX

//------------------------------------------------------------------------
// test_case_1_rand
//------------------------------------------------------------------------
// checks 10000 random numbers
void test_case_1_rand()
{
  printf("\n%s\n", __func__  );
  // seed for rand
  srand( 0xd00d);
  for (int i = 0; i < 10000; i++) {
    int num = rand() % 2000;
    int square = sqrt(num);
    UTST_ASSERT_INT_EQ( sqrt_iter(num), square);
  }
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------
int main( int argc, char* argv[] ) {

  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );
  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_rand();
  printf("\n");
  return 0;
}
