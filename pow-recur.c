//========================================================================
// pow-recur.c
//========================================================================
// Alternative implementation of the pow function

#include "pow-recur.h"
#include <stdio.h>

double pow_recur( double base, int exponent )
{
  // base case
  if ( exponent == 0 ) {
    return 1;
  }
  // base case
  else if ( exponent == 1 ) {
    return base;
  }
  // the exponent is positive
  else if ( exponent > 0 ) {
    // if the exponent is even
    if (( exponent % 2 ) == 0 ) {
      return pow_recur( (base * base), (exponent / 2) );
    }
    // if the exponent is odd
    else {
      return base * pow_recur(base,(exponent - 1));
    }
  }
  // the exponent is negative
  else if ( exponent < 0 ) {
    return 1/ ( pow_recur( base, ( exponent * -1) ) );
  }
  else {
    return 1;
  }
}

