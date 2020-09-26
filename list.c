//========================================================================
// list.c
//========================================================================
// Implementation of the list functions.
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
#include "list.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// list_int_construct
//------------------------------------------------------------------------
// Construct the list_int_t and initialize the fields inside.

void list_int_construct( list_int_t* this )
{
  this->head_ptr = NULL;
  this->tail_ptr = NULL;
  this->size = 0;
}

//------------------------------------------------------------------------
// list_int_destruct
//------------------------------------------------------------------------
// Destruct the list_int_t, freeing any dynamically allocated memory if
// necessary.

void list_int_destruct( list_int_t* this )
{
  while ( this->head_ptr != NULL ) {
    node_t* next_node = this->head_ptr->next_ptr;
    ece2400_free ( this->head_ptr );
    this->head_ptr = next_node;
  }
  this->size = 0;
}

//------------------------------------------------------------------------
// list_int_size
//------------------------------------------------------------------------
// Get the number of elements in the list.

size_t list_int_size( list_int_t* this )
{
  return this->size;
}

//------------------------------------------------------------------------
// list_int_push_back
//------------------------------------------------------------------------
// Push a new value into the list_int_t.

void list_int_push_back( list_int_t* this, int value )
{
  node_t* new_node = ece2400_malloc( sizeof(node_t) );
  new_node->value = value;
  
  // new node points to nothing
  new_node->next_ptr = NULL;
  
  // head ptr points to first node, first node has no previous
  if ( this->head_ptr == NULL ) {
    this->head_ptr = new_node;
    new_node->prev_ptr = NULL;
  }
  
  // all other pointers point to last one, and the prev node points to new
  if ( this->tail_ptr != NULL ) {
    new_node->prev_ptr = this->tail_ptr;
    this->tail_ptr->next_ptr = new_node;
  }
  
  // tail ptr points to new ptr
  this->tail_ptr = new_node;
  
  // add 1 to size
  this->size += 1;
}

//------------------------------------------------------------------------
// list_int_at
//------------------------------------------------------------------------
// Pointer chase and return the value at the given index
// If the index is out of bound, then return 0.

int list_int_at( list_int_t* this, size_t idx )
{
  // index ( 0 to idx) while size is from 1; idx 7 for size 7 dsnt wrk
  if ( idx >= this->size ) {
    return 0;
  }
  
  int v = 0;
  int x = idx;
  // idx on back half of the list
  if ( ( this->size / 2 ) < idx ) {
    node_t* temp_ptr = this->tail_ptr;
    
    // loops to check list; teaks v of node, then goes to prev until idx
    for ( int i = ( this->size - 1); i >= x; i--) {
      v = temp_ptr->value;
      temp_ptr = temp_ptr->prev_ptr;
    
    }
    return v;
  }
  // idx on front half of the list
  else {
    node_t* temp_ptr = this->head_ptr;
    
    // loops to check list; teaks v of node, then goes to next until idx
    for ( int i = 0; i <= x; i++) {
      v = temp_ptr->value;
      temp_ptr = temp_ptr->next_ptr;
    
    }
    return v;
    
  }

}

//------------------------------------------------------------------------
// list_int_find
//------------------------------------------------------------------------
// Search the list for a value and return whether a value is found or not.
// Returning 1 means found, and 0 means not found.

int list_int_find( list_int_t* this, int value )
{
  // empty list
  if ( this->size == 0 ) {
    return 0;
  }
  
  //temp
  node_t* temp_ptr = this->head_ptr;
  int x = this->size;
  
  // loops until found/not, exits as soon as found
  for ( int i = 0; i < x; i++) {
    if ( temp_ptr->value == value ) {
      return 1;
    }
    temp_ptr = temp_ptr->next_ptr;
  }
  return 0;
  
}

//------------------------------------------------------------------------
// list_int_print
//------------------------------------------------------------------------
// Print out the content of list_int_t.

void list_int_print( list_int_t* this )
{
  // temp
  node_t* temp_ptr = this->head_ptr;
  int x = this->size;
  
  // loop over and print
  for ( int i = 0; i < x; i++) {
    printf("%i, ", temp_ptr->value);
    temp_ptr = temp_ptr->next_ptr;
  }
}
