#include "list.h"

#include <stdio.h>   // printf
#include <string.h>  // strlen
#include <stdlib.h>  // malloc
#include <stdbool.h> // bool

#define TOTAL_TESTS 21
#define DEBUG_PRINT_OUTPUT false

static void* _vstr(const char* txt)
{
	char *str = (char*)malloc(strlen(txt) + 1);
	strcpy(str, txt);
	return (void*)str;
}

static int _testdiff(const char *out, list_t final)
{
	char *repr = list_tostr(final);
	int diff = strcmp(out, repr);
	free(repr);
	return diff;
}

const char *_case_output[TOTAL_TESTS] = {
	"{  }",
	"{ \"1\" }",
	"{ \"1\", \"2\" }",
	"{ \"1\", \"2\", \"3\" }",
	"{ \"1\", \"2\" }",
	"{ \"2\", \"3\" }",
	"{ \"1\", \"3\" }",
	"{ \"1\" }",
	"{ \"2\", \"1\" }",
	"{ \"3\", \"2\", \"1\" }",
	"{  }",
	"{  }",
	"{  }",
	"true",
	"false",
	"false",
	"false",
	"true",
	"0",
	"1",
	"10"
};

/*
 * case 0: list_create
 * create empty list
 * setup: -
 * out: {  }
 */
int _case_0(void)
{
	list_t l = list_create();

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[0], l);
	list_freev(&l);
	return diff;
}

/*
 * case 1: list_add
 * add node to list of size 0
 * setup: {  }
 * out: { "1" }
 */
int _case_1(void)
{
	// setup
	list_t l = list_create();

	list_add(&l, _vstr("1"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[1], l);
	list_freev(&l);
	return diff;
}

/*
 * case 2: list_add
 * add node to list of size 1
 * setup: { "1" }
 * out: { "1", "2" }
 */
int _case_2(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr("1"));

	list_add(&l, _vstr("2"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[2], l);
	list_freev(&l);
	return diff;
}

/*
 * case 3: list_add
 * test add node to list of size 2
 * setup: { "1", "2" }
 * out: { "1", "2", "3" }
 */
int _case_3(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr("1"));
	list_add(&l, _vstr("2"));

	list_add(&l, _vstr("3"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[3], l);
	list_freev(&l);
	return diff;
}

/*
 * case 4: list_removev
 * remove last node and free its value
 * setup: { "1", "2", "3" }
 * out: { "1", "2" } 
 */
int _case_4(void)
{
	// setup
	list_t l = list_create();
	void *target = _vstr("3");
	list_add(&l, _vstr("1"));
	list_add(&l, _vstr("2"));
	list_add(&l, target);

	list_removev(&l, target);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[4], l);
	list_freev(&l);
	return diff;
}

/*
 * case 5: list_removev
 * remove first node and free its value 
 * setup: { "1", "2", "3" }
 * out: { "2", "3" } 
 */
int _case_5(void)
{
	// setup
	list_t l = list_create();
	void *target = _vstr("1");
	list_add(&l, target);
	list_add(&l, _vstr("2"));
	list_add(&l, _vstr("3"));

	list_removev(&l, target);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);

	int diff = _testdiff(_case_output[5], l);
	list_freev(&l);
	return diff;
}

/*
 * case 6: list_removev
 * remove middle node in list
 * setup: { "1", "2", "3" }
 * out: { "1", "3" } 
 */
int _case_6(void)
{
	// setup
	list_t l = list_create();
	void *target = _vstr("2");
	list_add(&l, _vstr("1"));
	list_add(&l, target);
	list_add(&l, _vstr("3"));

	list_removev(&l, target);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[6], l);
	list_freev(&l);
	return diff;
}

/*
 * case 7: list_frontadd
 * add a node to the front of list of size 0
 * setup: {  }
 * out: { "1" } 
 */
int _case_7(void)
{
	// setup
	list_t l = list_create();

	list_frontadd(&l, _vstr("1"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[7], l);
	list_freev(&l);
	return diff;
}

/*
 * case 8: list_frontadd
 * add a node to the front of list of size 1
 * setup: { "1" }
 * out: { "2", "1" } 
 */
int _case_8(void)
{
	// setup
	list_t l = list_create();
	list_frontadd(&l, _vstr("1"));

	list_frontadd(&l, _vstr("2"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[8], l);
	list_freev(&l);
	return diff;
}

/*
 * case 9: list_frontadd
 * add a node to the front of list of size 2
 * setup: { "2", "1" }
 * out: { "3", "2", "1" } 
 */
int _case_9(void)
{
	// setup
	list_t l = list_create();
	list_frontadd(&l, _vstr("1"));
	list_frontadd(&l, _vstr("2"));

	list_frontadd(&l, _vstr("3"));

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[9], l);
	list_freev(&l);
	return diff;
}

/*
 * case 10: list_clearv
 * clear a list of size 0 and free its values
 * setup: {  }
 * out: {  } 
 */
int _case_10(void)
{
	// setup
	list_t l = list_create();
	
	list_clearv(&l);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[10], l);
	list_freev(&l);
	return diff;
}

/*
 * case 11: list_clearv
 * clear a list of size 1 and free its values
 * setup: { "clear me" }
 * out: {  } 
 */
int _case_11(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr("clear me"));
	
	list_clearv(&l);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[11], l);
	list_freev(&l);
	return diff;
}

/*
 * case 12: list_clearv
 * clear a list of size 2 and free its values
 * setup: { "clear me", "clear me" }
 * out: {  } 
 */
int _case_12(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr("clear me"));
	list_add(&l, _vstr("clear me"));
	
	list_clearv(&l);

	if (DEBUG_PRINT_OUTPUT)
		list_printcstr(l);
	
	int diff = _testdiff(_case_output[12], l);
	list_freev(&l);
	return diff;
}

/*
 * case 13: list_is_empty
 * check if list is empty when its empty
 * setup: {  }
 * out: "true"
 */
int _case_13(void)
{
	// setup
	list_t l = list_create();

	char *anwser = list_is_empty(l) ? "true" : "false";
	
	int diff = strcmp(_case_output[13], anwser);
	list_freev(&l);
	return diff;
}

/*
 * case 14: list_is_empty
 * check if list is empty when its not empty
 * setup: { "" }
 * out: "false"
 */
int _case_14(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr(""));

	char *anwser = list_is_empty(l) ? "true" : "false";
	
	int diff = strcmp(_case_output[14], anwser);
	list_freev(&l);
	return diff;
}

/*
 * case 15: list_contains
 * check if list contains value when list is empty
 * setup: { }
 * out: "false"
 */
int _case_15(void)
{
	// setup
	list_t l = list_create();
	void *txt_value = _vstr("val");

	char *anwser = list_contains(l, txt_value) ? "true" : "false";
	
	int diff = strcmp(_case_output[15], anwser);
	list_freev(&l);
	free(txt_value);
	return diff;
}

/*
 * case 16: list_contains
 * check if list contains value when its not empty and doesn't contain value
 * setup: { "not val", "not val", "not val" }
 * out: "false"
 */
int _case_16(void)
{
	// setup
	list_t l = list_create();
	list_frontadd(&l, _vstr("not val"));
	list_frontadd(&l, _vstr("not val"));
	list_frontadd(&l, _vstr("not val"));
	void *txt_value = _vstr("val");

	char *anwser = list_contains(l, txt_value) ? "true" : "false";
	
	int diff = strcmp(_case_output[16], anwser);
	list_freev(&l);
	free(txt_value);
	return diff;
}

/*
 * case 17: list_contains
 * check if list contains value when its not empty and contains the value
 * setup: { "not val", "val", "not val" }
 * out: "true"
 */
int _case_17(void)
{
	// setup
	list_t l = list_create();
	void *txt_value = _vstr("val");
	list_frontadd(&l, _vstr("not val"));
	list_frontadd(&l, txt_value);
	list_frontadd(&l, _vstr("not val"));

	char *anwser = list_contains(l, txt_value) ? "true" : "false";
	
	int diff = strcmp(_case_output[17], anwser);
	list_freev(&l);
	return diff;
}

/*
 * case 18: list_len
 * get length of empty list
 * setup: {  }
 * out: "0"
 */
int _case_18(void)
{
	// setup
	list_t l = list_create();

	char anwser[16];
	sprintf(anwser, "%u", list_len(l));
	
	int diff = strcmp(_case_output[18], anwser);
	list_freev(&l);
	return diff;
}

/*
 * case 19: list_len
 * get length of list with only one node
 * setup: { "" }
 * out: "1"
 */
int _case_19(void)
{
	// setup
	list_t l = list_create();
	list_add(&l, _vstr(""));

	char anwser[16];
	sprintf(anwser, "%u", list_len(l));
	
	int diff = strcmp(_case_output[19], anwser);
	list_freev(&l);
	return diff;
}

/*
 * case 20: list_len
 * get length of list with a bunch of items
 * setup: { "", "", "", "", "", "", "", "", "", "" }
 * out: "10"
 */
int _case_20(void)
{
	// setup
	list_t l = list_create();
	for(int i = 0; i < 10; i++)
		list_add(&l, _vstr(""));

	char anwser[16];
	sprintf(anwser, "%u", list_len(l));
	
	int diff = strcmp(_case_output[20], anwser);
	list_freev(&l);
	return diff;
}

typedef int (*_case_ptr)(void);

_case_ptr _case_table[TOTAL_TESTS] = {
	// create
	_case_0,
	// add
	_case_1, _case_2, _case_3,
	// removev
	_case_4, _case_5, _case_6, 
	// frontadd
	_case_7, _case_8, _case_9,
	// clearv
	_case_10, _case_11, _case_12,
	// is_empty
	_case_13, _case_14,
	// contains
	_case_15, _case_16, _case_17,
	// length
	_case_18, _case_19, _case_20
};

int main(int argc, char *argv[])
{

	for (int i = 0; i < TOTAL_TESTS; i++) {
		int diff = _case_table[i]();
		printf("test %d...", i);
		if(diff != 0)
			printf("fail.\n");
		else
			printf("pass.\n");
	}

	return 0;

}