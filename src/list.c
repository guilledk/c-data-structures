#include "list.h"

#include <stdio.h>  // printf
#include <stddef.h> // NULL
#include <stdlib.h> // malloc, calloc
#include <string.h> // strlen

static list_t _list_create_node(void* value, list_t next)
{
	list_t ret = (list_t)malloc(sizeof(struct s_list));
	ret->value = value;
	ret->next = next;
	return ret;
}

list_t list_create(void)
{

	return NULL;

}

void list_add(list_t *head, void *value)
{

	list_t iter = (*head);

	list_t nnode = _list_create_node(value, NULL);

	// if list is empty
	if(list_is_empty(iter)) {
		*head = nnode;
		return;
	}

	// find last item
	while(!list_is_empty(list_next(iter)))
		iter = list_next(iter);

	iter->next = nnode;

}

void list_frontadd(list_t *head, void *value)
{

	list_t nnode = _list_create_node(value, (*head));
	*head = nnode;

}

void* list_value(list_t node)
{
	return node->value;
}

list_t list_next(list_t node)
{
	return node->next;
}

void list_remove(list_t *head, void *value)
{

	list_t prev = NULL;
	list_t iter = (*head);

	while(!list_is_empty(iter) && !(list_value(iter) == value)) {
		prev = iter;
		iter = list_next(iter);
	}

	if (!list_is_empty(iter)) {
		if(!list_is_empty(prev))
			prev->next = list_next(iter);
		else
			(*head) = (*head)->next;

		free(iter);
	}

}

void list_removev(list_t *head, void *value) {

	list_t prev = NULL;
	list_t iter = (*head);

	while(!list_is_empty(iter) && !(list_value(iter) == value)) {
		prev = iter;
		iter = list_next(iter);
	}

	if (!list_is_empty(iter)) {
		if(!list_is_empty(prev))
			prev->next = list_next(iter);
		else
			(*head) = (*head)->next;

		free(list_value(iter));
		free(iter);
	}

}

void list_clear(list_t *head)
{
	list_free(head);
	(*head) = list_create();
}

void list_clearv(list_t *head)
{
	list_freev(head);
	(*head) = list_create();
}

void list_free(list_t *head)
{

	list_t iter = (*head);

	while(iter) {
		list_t tmp = iter->next;
		free(iter);
		iter = tmp;
	}

}

void list_freev(list_t *head)
{

	list_t iter = (*head);

	while(iter) {
		list_t tmp = list_next(iter);
		free(list_value(iter));
		free(iter);
		iter = tmp;
	}

}

bool list_is_empty(list_t head)
{
	return head == NULL;
}

bool list_contains(list_t head, void* value) {

	if(list_is_empty(head))
		return false;

	list_t iter = head;

	while(!list_is_empty(iter) && !(list_value(iter) == value))
		iter = list_next(iter);

	/*
	 * if we didn't found the value iter will be null,
	 * else we found it.
	 */
	return !list_is_empty(iter);

}

char* list_tostr(list_t head)
{
	// first count how many chars its going to take
	unsigned int len = 2; // "{ "
	list_t iter = head;
	while(!list_is_empty(iter)) {
		len += strlen(list_value(iter)) + 2; // "\"(value)\""
		iter = list_next(iter);

		if(!list_is_empty(iter))
			len += 2; // ", "
	}
	len += 3; // " }\n"

	// same algorithm as list_print* but instead of printf, strcat to buf
	char *ret = (char*)calloc(1, len + 1);
	strcat(ret, "{ ");
	iter = head;
	while(!list_is_empty(iter)) {
		strcat(ret, "\"");
		strcat(ret, (char*)iter->value);
		strcat(ret, "\"");

		iter = list_next(iter);

		if(!list_is_empty(iter))
			strcat(ret, ", ");
	}
	strcat(ret, " }");

	return ret;
}

void list_printaddr(list_t head)
{
	printf("{ ");
	list_t iter = head;
	while(!list_is_empty(iter)) {
		printf("%p", list_value(iter));
		iter = list_next(iter);

		if(!list_is_empty(iter))
			printf(", ");
	}
	printf(" }");
}

void list_printcstr(list_t head)
{
	printf("{ ");
	list_t iter = head;
	while(!list_is_empty(iter)) {
		printf("\"%s\"", (char*)list_value(iter));
		iter = list_next(iter);

		if(!list_is_empty(iter))
			printf(", ");
	}
	printf(" }");
}

unsigned int list_len(list_t head) {
	unsigned int len = 0;
	list_t iter = head;
	while(!list_is_empty(iter)) {
		len++;
		iter = list_next(iter);
	}
	return len;
}