//========================================================================
// sqrt-iter.c
//========================================================================
// Baseline implementation of the sqrt function

#include "sqrt-iter.h"
#include <stdio.h>
#include <limits.h> // for INT_MAX

int sqrt_iter( int x )
{
  // loops from 0 to x i * i
  for (int i = 0; i <= x; i++) {
    // finding the exact sqrt
    if ( ( i * i ) == x ) {
      return i;
    }
    // finding the sqrt 
    else if ( ( i * i ) > x ) {
      return i - 1;
    }
  }
  return -1;
}

