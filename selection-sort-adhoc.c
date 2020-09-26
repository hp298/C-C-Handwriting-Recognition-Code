//========================================================================
// selection-sort-main.c
//========================================================================

#include <stdio.h>
#include <stdlib.h>
#include "ece2400-stdlib.h"
#include "selection-sort.h"

int main()
{
  size_t size = 4;
  int    a[]  = { 19, 95, 4, 23 };

  // Print out array before

  printf( "Before sorting: " );

  //ece2400_print_array( a, size );
  for( unsigned int i = 0; i < size; i++) { 
    printf("%d, ", a[i]);
  }

  // Call sort

  selection_sort( a, size );

  // Print out array after

  printf( "\nAfter sorting:  " );

  //ece2400_print_array( a, size );
  for( unsigned int i = 0; i < size; i++) { 
    printf("%d, ", a[i]);
  }

  return 0;
}
