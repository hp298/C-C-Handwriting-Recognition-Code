//========================================================================
// pow-iter.c
//========================================================================
// iterative version of power function (base ^ exponent)

#include "pow-iter.h"
#include <stdio.h>

//------------------------------------------------------------------------
// pow_iter_helper( base, exponent)
//------------------------------------------------------------------------
// for loop that multiplies the base by itself exponent amount of times
double pow_iter_helper( double base, int exponent)
{
  double total = 1;
  for ( int i = 0; i < exponent; i++) {
      total = total * base;
  }
  return total;
}

double pow_iter( double base, int exponent )
{
  // math rule, if exponent 0, answer always 1
  if ( exponent == 0 ) {
    return 1;
  } 
  // exponent is negative
  else if ( exponent < 0 ) {
    // finds the pow as if it was postive, then one over that value
    return ( 1 / pow_iter_helper( base, exponent * -1 ) );
  }
  // exponent is positive
  else if ( exponent > 0 ) {
    // finds pow
    return pow_iter_helper( base, exponent );
  }
  else {
    return 0;
  }
}
