//========================================================================
// merge-sort-main.c
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include "ece2400-stdlib.h"
#include "merge-sort.h"

int main()
{
  size_t size = 4;
  int    a[]  = { 95, 19, 4, 23 };

  // Print out array before

  printf( "Before sorting: " );

  ece2400_print_array( a, size );

  // Call sort

  merge_sort( a, size );

  // Print out array after

  printf( "After sorting:  " );

  ece2400_print_array( a, size );

  return 0;
}
