//========================================================================
// ece2400-stdlib.c
//========================================================================
// Utility functions to support memory and performance profiling.
//
// Note:
//
// DO NOT CHANGE THE FOLLOWING CODE!
//
// Author: Yanghui Ou
//   Date: Sep 7, 2019

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "ece2400-stdlib.h"

#define MILLION 1000000.0;

//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------

size_t mem_usage  = 0;
size_t peak_usage = 0;

struct timeval start_time;
struct timeval end_time;

//------------------------------------------------------------------------
// ece2400_malloc
//------------------------------------------------------------------------
// Allocate memory of size mem_size. Return a pointer to the newly
// allocated memory or NULL if the allocation fails.

void* ece2400_malloc( size_t mem_size )
{
  void* ptr = malloc( mem_size + sizeof( size_t ) );

  if ( ptr ) {
    // Update current usage
    mem_usage += mem_size;

    // Update peak usage
    if ( mem_usage > peak_usage )
      peak_usage = mem_usage;
  }
  else
    return NULL;

  ( (size_t*)ptr )[0] = mem_size;

  return (void*)( ( (size_t*)ptr ) + 1 );
}

//------------------------------------------------------------------------
// ece2400_free
//------------------------------------------------------------------------
// Free the memory block that is allocated using ece2400_malloc. According
// to C standard, if ptr is NULL, no action occurs.

void ece2400_free( void* ptr )
{
  if ( ptr ) {
    mem_usage -= ( (size_t*)ptr )[-1];
    free( ( ( (size_t*)ptr ) - 1 ) );
  }
}

//------------------------------------------------------------------------
// ece2400_print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void ece2400_print_array( int* a, size_t size )
{
  if ( size > 0 )
    printf( "%d", a[0] );
  for ( size_t i = 1; i < size; i++ )
    printf( ", %d", a[i] );
  printf( "\n" );
}

//------------------------------------------------------------------------
// less_than
//------------------------------------------------------------------------
// Comparison function for qsort.

int less_than( const void* a_p, const void* b_p )
{
  int left  = *(const int*)a_p;
  int right = *(const int*)b_p;

  if ( left > 0 && right < 0 )
    return 1;
  else if ( left < 0 && right > 0 )
    return -1;
  else
    return left - right;
}

//------------------------------------------------------------------------
// ece2400_sort
//------------------------------------------------------------------------
// A reference sorting function that sorts an array of integer in
// ascending order.

void ece2400_sort( int* a, size_t size )
{
  qsort( (void*)a, size, sizeof( int ), less_than );
}

//------------------------------------------------------------------------
// ece2400_mem_reset
//------------------------------------------------------------------------

void ece2400_mem_reset()
{
  mem_usage  = 0;
  peak_usage = 0;
}

//------------------------------------------------------------------------
// ece2400_mem_get_usage
//------------------------------------------------------------------------
// Return the amount of heap space that has been allocated so far in a
// program.

size_t ece2400_mem_get_usage()
{
  return mem_usage;
}

//------------------------------------------------------------------------
// ece2400_mem_get_peak
//------------------------------------------------------------------------
// Return the peak heap usage.

size_t ece2400_mem_get_peak()
{
  return peak_usage;
}

//------------------------------------------------------------------------
// ece2400_timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void ece2400_timer_reset()
{
  gettimeofday( &start_time, NULL );
}

//------------------------------------------------------------------------
// ece2400_timer_get_elapsed
//------------------------------------------------------------------------
//  Return the elapased time in seconds.

double ece2400_timer_get_elapsed()
{
  gettimeofday( &end_time, NULL );
  double elapsed_time = ( end_time.tv_sec - start_time.tv_sec ) +
                        ( end_time.tv_usec - start_time.tv_usec ) / MILLION;
  return elapsed_time;
}
