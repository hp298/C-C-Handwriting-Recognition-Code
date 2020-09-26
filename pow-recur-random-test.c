//========================================================================
// pow-recur-random-test.c
//========================================================================
// This file contains tests with randomly generated inputs for the
// pow_recur function.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utst.h"
#include "pow-recur.h"

//------------------------------------------------------------------------
// test_case_1_big_base
//------------------------------------------------------------------------
// tests many big bases
void test_case_1_big_base()
{
  printf("\n%s\n", __func__  );
  // seed for rand
  srand( 0xd00d);
  // loops over 10000 random numbers
  for (int i = 0; i < 10000; i++) {
    double base = ( ( (double)rand() / (double)RAND_MAX ) * 1000.0);
    int expo = rand() % 3;
    double power = pow(base,expo);
    UTST_ASSERT_FLOAT_EQ( pow_recur( base, expo) / power, 1.0000, 0.0001 );
  }
}
//------------------------------------------------------------------------
// test_case_2_big_expo
//------------------------------------------------------------------------
// tests many big exponents
void test_case_2_big_expo()
{
  printf("\n%s\n", __func__  );
  // seed for rand
  srand( 0xd00d);
  // loops over 10000 random numbes
  for (int i = 0; i < 10000; i++) {
    double base = ( ( (double)rand() / (double)RAND_MAX ) * 3.0);
    int expo = rand() % 14;
    double power = pow( base, expo);
    UTST_ASSERT_FLOAT_EQ( pow_recur( base, expo) / power, 1.0000, 0.0001 );
  }
}
//------------------------------------------------------------------------
// test_case_3_negative
//------------------------------------------------------------------------
// test negative exponents
void test_case_3_negative()
{
  printf("\n%s\n", __func__  );
  // seed for rand
  srand( 0xd00d);
  // loops over 10000 random numbers
  for (int i = 0; i < 10000; i++) {
    double base = ( ( (double)rand() / (double)RAND_MAX ) * 3.0);
    int expo = (rand() % 14) * -1;
    double power = pow( base, expo);
    UTST_ASSERT_FLOAT_EQ( pow_recur( base, expo) / power, 1.0000, 0.0001 );
  }
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------
int main( int argc, char* argv[] ) {

  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );
  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_big_base();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_big_expo();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_negative();
  printf("\n");
  return 0;
}

