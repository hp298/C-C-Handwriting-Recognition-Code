//========================================================================
// pow-iter-directed-test.c
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utst.h"
#include "pow-iter.h"

//------------------------------------------------------------------------
// test_case_1_small_large
//------------------------------------------------------------------------
// Directed tests for small base with large exponent

void test_case_1_small_large()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter(   1, 100 ), 1.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1.1, 300 ) / 2617010996188.4634, 1.0, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_2_zero_small
//------------------------------------------------------------------------
// Directed tests for 0 base with small exponent

void test_case_2_zero_small()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0.0, 1 ), 0.0000, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0.0, 2 ), 0.0000, 0.0001 );
}

//------------------------------------------------------------------------
// test_case_3_negative_bases
//------------------------------------------------------------------------
// Directed tests for negative bases
void test_case_3_negative_bases()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, 1 )/-5, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, 2 )/25, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, 3 )/-125, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, 4 )/625, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, 5 )/-3125, 1.0, 0.0001 );
}
//------------------------------------------------------------------------
// test_case_4_negative_exponents
//------------------------------------------------------------------------
// Directed tests for negative exponents
void test_case_4_negative_exponents()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 5.0, -1 )*5, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 5.0, -2 )*25, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 5.0, -3 )*125, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 5.0, -4 )*625, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 5.0, -5 )*3125, 1.0, 0.0001 );
}
//------------------------------------------------------------------------
// test_case_5_both_negative
//------------------------------------------------------------------------
// Directed tests for negative bases & exponents
void test_case_5_both_negative()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, -1 )*-5, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, -2 )*25, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, -3 )*-125, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, -4 )*625, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -5.0, -5 )*-3125, 1.0, 0.0001 );
}
//------------------------------------------------------------------------
// test_case_6_base_zero
//------------------------------------------------------------------------
// Directed tests for zero exponents 
void test_case_6_exponent_zero()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( -10.0, 0 ), 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 12.0, 0 ), 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 0.0, 0 ), 1.0, 0.0001 );
}
//------------------------------------------------------------------------
// test_case_7_large_base_small_exp
//------------------------------------------------------------------------
// Directed tests for zlarge bases 
void test_case_7_large_base_small_exp()
{
  printf("\n%s\n", __func__  );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 2000000000, 1 )/2000000000, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 44000, 2 )/1936000000, 1.0, 0.0001 );
  UTST_ASSERT_FLOAT_EQ( pow_iter( 1234, 3 )/1879080904, 1.0, 0.0001 );
}
//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------
int main( int argc, char* argv[] )
{

  int n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( n == 0 ) || ( n == 1 ) ) test_case_1_small_large();
  if ( ( n == 0 ) || ( n == 2 ) ) test_case_2_zero_small();
  if ( ( n == 0 ) || ( n == 3 ) ) test_case_3_negative_bases();
  if ( ( n == 0 ) || ( n == 4 ) ) test_case_4_negative_exponents();
  if ( ( n == 0 ) || ( n == 5 ) ) test_case_5_both_negative();
  if ( ( n == 0 ) || ( n == 6 ) ) test_case_6_exponent_zero();
  if ( ( n == 0 ) || ( n == 7 ) ) test_case_7_large_base_small_exp();

  printf( "\n" );
  return 0;
}
