//========================================================================
// sqrt-recur.c
//========================================================================
// Alternative implementation of the sqrt function

#include "sqrt-recur.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX
//------------------------------------------------------------------------
// sqrt_recur_helper( y, low, high)
//------------------------------------------------------------------------
// completes the recursive for sqrt, has extra inputs for better recursion
unsigned int sqrt_recur_helper( unsigned int y, unsigned int low, unsigned int high)
{
  // helpful variables to reduce clutter
  unsigned int half = ( high - low ) / 2;
  unsigned int test = low + half;
  unsigned int guess = test * test;
  
  // the difference between the max and mix is 3 or less
  if ( ( high - low ) < 4) {
    // the sqrt is between max + 1 and max (including max)
    if ( ( high * high ) <= y ) {
      return high;
    }
    // the sqrt is between max and max - 1 (including max - 1)
    else if ( ( ( high - 1 ) * ( high - 1 ) ) <= y ) {
      return (high - 1);
    }
    // the sqrt is between max - 1 and min + 1 (including min + 1 )
    else if ( ( ( low + 1 ) * ( low + 1 ) ) <= y) {
      return (low + 1);
    }
    // the sqrt is between min + 1 and min (includeing min)
    else if ( ( low * low ) <= y ) {
      return low;
    }
    // will never reached, but stops warnings
    else {
      return 0;
    }
  }
  // base case, find the exact sqrt
  else if ( ( guess ) == y ) {
    return test;
  }
  // recur case, x bigger than the guess
  else if ( ( guess ) < y ) {
    return sqrt_recur_helper( y, test, high);
  }
  // recur case, x smaller than the guess
  else if ( ( guess ) > y ) {
    return sqrt_recur_helper( y, low, test);
  }
  // will never reach, but an exit for no warnings
  else {
    return 0;
  }
}

int sqrt_recur( int x )
{
  // rules for sqrt_recur
  if ( x == 0 ) {
    return 0;
  }
  else if ( x < 0 ) {
    return -1;
  }
  // seperate function for the actual recur
  else {
    unsigned int y = x;
    return sqrt_recur_helper( y, 0, y);
  }
}
