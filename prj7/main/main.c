#include <stdio.h>
#include <src_module1.h>
#include <src_module2.h>

int main(int argc, char* argv[])
{
	printf("main\n");
	
	src_module1_file1_func1();
	src_module2_file1_func1();

	return 0;	
}

