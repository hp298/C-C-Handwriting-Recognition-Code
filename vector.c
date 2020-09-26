//========================================================================
// vector.c
//========================================================================
// Baseline implementation of the vector functions
//
//--------------------!!! IMPORTANT NOTE !!!------------------------------
//
// You need to use ece2400_malloc and ece2400_free in your implementation
// in order to get memory usage for eval!
//
//------------------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// vector_int_construct
//------------------------------------------------------------------------
// Construct the vector_int_t and initialize the fields inside

void vector_int_construct( vector_int_t* this )
{
  this->size = 0;
  this->maxsize = 0;
  this->array = ece2400_malloc( sizeof(int) );
}

//------------------------------------------------------------------------
// vector_int_destruct
//------------------------------------------------------------------------
// Destruct the vector_int_t, freeing any dynamically allocated memory if
// necessary

void vector_int_destruct( vector_int_t* this )
{
  ece2400_free( this->array );
}

//------------------------------------------------------------------------
// vector_int_size
//------------------------------------------------------------------------
// Get the number of elements in the vector.

size_t vector_int_size( vector_int_t* this )
{
  return this->size;
}

//------------------------------------------------------------------------
// vector_int_push_back_v1
//------------------------------------------------------------------------
// Push a new value into the vector_int_t, allocate just enough memory if
// the internal array is full.

void vector_int_push_back_v1( vector_int_t* this, int value )
{
  int n = this->size;
  // space in vector
  if ( this->size < this->maxsize ) {
    this->array[n] = value;
    this->size += 1;
  }
  // empty
  else if ( n == 0 ) {
    this->size = 1;
    this->maxsize = 1;
    this->array[0] = value;
  }
  // no space, not empty
  else {
    // keep old vector, make new, increase maxsize(by 1) & size
    int* a = this->array;  
    this->size += 1;
    this->maxsize += 1;
    int max = this->maxsize;
    this->array = ece2400_malloc( max * sizeof(int) );
    
    // copy old vector to new
    for ( int i = 0; i < ( max - 1 ); i++ ) {
      this->array[i] = a[i];
    }
    
    // free old vector
    ece2400_free( a );
    
    // add new value
    this->array[max - 1] = value;
    
  }
}

//------------------------------------------------------------------------
// vector_int_push_back_v2
//------------------------------------------------------------------------
// Push a new value into the vector_int_t, doubles the size of the
// internal array if vector is full.

void vector_int_push_back_v2( vector_int_t* this, int value )
{
    int n = this->size;
  // space in vector
  if ( this->size < this->maxsize ) {
    this->array[n] = value;
    this->size += 1;
  }
  // empty
  else if ( n == 0 ) {
    this->size = 1;
    this->maxsize = 1;
    this->array[0] = value;
  }
  // no space, not empty
  else {
    // keep old vector, make new, increase maxsize(by 2x) & size
    int* a = this->array;  
    this->maxsize = 2 * this->size;
    this->size += 1;
    int max = this->maxsize;
    int size = this->size;
    this->array = ece2400_malloc( max * sizeof(int) );
    
    // copy old vector to new
    for ( int i = 0; i < ( size - 1 ); i++ ) {
      this->array[i] = a[i];
    }
    
    // free old vector
    ece2400_free( a );
    
    // add new value
    this->array[size - 1] = value;
    
  }
}

//------------------------------------------------------------------------
// vector_int_at
//------------------------------------------------------------------------
// Access the internal array and return the value at the given index
// If the index is out of bound, then return 0

int vector_int_at( vector_int_t* this, size_t idx )
{
  // idx not in bound
  if ( idx >= this->size ) {
    return 0;
  }
  // idx in bound
  else {
    return this->array[idx];
  }

}

//------------------------------------------------------------------------
// vector_int_find
//------------------------------------------------------------------------
// Search the vector for a value and return whether a value is found or
// not. Returning 1 means found, and 0 means not found.

int vector_int_find( vector_int_t* this, int value )
{
  int n = this->size;

  // empty vector
  if ( n == 0) {
    return 0;
  }
  
  for ( int i = 0; i < n; i++) {
    int v = this->array[i];
    if ( v == value ) {
      return 1;
    }
  }
  return 0;

}

//------------------------------------------------------------------------
// vector_int_print
//------------------------------------------------------------------------
// Print out the content of vector_int_t

void vector_int_print( vector_int_t* this )
{
  int n = this->size;
  for ( int i = 0; i < n; i++) {
    int v = this->array[i];
    printf("%i, ", v);
  }
  
}
