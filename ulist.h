#ifndef ULIST_H
#define ULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>

/**
 * @brief Defines CMP as pointer to comparision function that returns:
 * - negative int value if the first argument to compare is "less" than the second
 * - positive int value if the first argumrnt to compare is "greater" than the second
 * - 0 when the arguments are equivalent.
 * Arguments to compare are pointed by the parameters of the function.
 */ 
typedef int ( *CMP )( const void *,  const void * );  

/**
 * @brief Defines PRINT as pointer to a function that prints a content of an element,
 * to which the parameter points.
*/
typedef void ( *PRINT )( const void * );

/**
 * @brief Node structure containing:
 * - data, pointer to data stored in the node
 * - next, pointer to the next node in the list.
*/
typedef struct _Node
{
  void *data;
  struct _Node *next;
} Node;

/**
 * @brief UnorderedList structure that contains the only information needed to enter the list:
 * - head, pointer to the first node in the list
 * - the list is unsorted.
*/
typedef struct _UnorderedList
{
  Node *head;
} UnorderedList;

/**
 * @brief Initializes the empty list.
 * 
 * @param list pointer to the list that should be initialized as an empty list
*/
void initialize_list( UnorderedList *list );

/**
 * @brief Adds a new element to the beginning of the list.
 * 
 * @param list pointer to the list
 * @param data  pointer to the new data that should be stored in the list
*/
void add_begin( UnorderedList *list, void *data );

/**
 * @brief Adds a new element to the end of the list.
 * 
 * @param list pointer to the list
 * @param data  pointer to the new data that should be stored in the list
*/
void add_end(UnorderedList *list, void *data);

/**
 * @brief Deletes the element from the beginning of the list.
 * 
 * @param list pointer to the list
*/
void *delete_begin(UnorderedList *list);

/**
 * @brief Deletes the element from the end of the list.
 * 
 * @param list pointer to the list
*/
void *delete_end(UnorderedList *list);

/**
 * @brief Prints all the data stored in the list to stdout.
 * 
 * @param list pointer to the list
 * @param print pointer to function that print the content of the data stored in an element (node) of the list
*/
void print_list(const UnorderedList *list, PRINT print);

/**
 * @brief Delete whole list.
 * 
 * @param list pointer to the list
*/
void delete_all( UnorderedList *list );

#endif