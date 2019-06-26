#define TOTAL_TESTS 0
#define DEBUG_PRINT_OUTPUT false

const char *_case_output[TOTAL_TESTS] = {

};

/*
 * case i: test_function_name
 * test description
 * setup:
 * out:
 */
int _case_i(void)
{
	return 1;
}

typedef int (*_case_ptr)(void);

_case_ptr _case_table[TOTAL_TESTS] = {
	
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