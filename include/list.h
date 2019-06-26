#ifndef DATASTRUCTURES_LIST_H
#define DATASTRUCTURES_LIST_H

#include <stdbool.h> // bool

typedef struct s_list {
	
	void *value;
	struct s_list *next;

} * list_t;

// creates empty list
// order 1
list_t list_create(void);

// adds value to the end of the list
// order n
void list_add(list_t *head, void *value);

// adds value to the begining of the list
// order 1
void list_frontadd(list_t *head, void *value);

// returns the value of the node
// order 1
void* list_value(list_t node);

// return the next node
// order 1
list_t list_next(list_t node);

// removes value from list without freeing its values
// order n
void list_remove(list_t *head, void *value);

// removes value from list without freeing its values
// order n
void list_removev(list_t *head, void *value);

// clear list of all its nodes
// order n
void list_clear(list_t *head);

// clear list of all its nodes and free its values
// order n
void list_clearv(list_t *head);

// frees all nodes on the list without freeing its values
// order n
void list_free(list_t *head);

// frees all nodes on the list and its values
// order n
void list_freev(list_t *head);

// returns true if list is empty
// order 1
bool list_is_empty(list_t head);

// returns true if value is in list
// order n
bool list_contains(list_t head, void* value);

// return a c string representing the list an its values, assums this is a
// list of char*
// order n
char* list_tostr(list_t head);

// print list pointer addresses
// order n
void list_printaddr(list_t head);

// print list nodes assuming they are char*
// order n
void list_printcstr(list_t head);


// returns length of list
// order n
unsigned int list_len(list_t head);

#endif