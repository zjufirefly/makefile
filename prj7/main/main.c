#include <stdio.h>
#include <src_module1.h>
#include <src_module2.h>
#include <lib_module1.h>
#include <lib_module2.h>


int main(int argc, char* argv[])
{
	printf("main\n\n");
	
	src_module1_file1_func1();
	printf("\n");
	src_module2_file1_func1();
	printf("\n");

	lib_module1_file1_func1();
	printf("\n");
	lib_module2_file1_func1();
	printf("\n");

	return 0;	
}

