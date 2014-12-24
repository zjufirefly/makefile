#include <stdio.h>
#include "lib_module1_file1.h"
#include "./lib_dir1/lib_module1_dir1_file1.h"
#include "./lib_dir1/lib_module1_dir1_file2.h"
#include "./lib_dir2/lib_module1_dir2_file1.h"
#include "./lib_dir2/lib_module1_dir2_file2.h"

void lib_module1_file1_func1()
{
	printf("lib_module1_file1_func1\n");

	lib_module1_dir1_file1_func1();
	lib_module1_dir1_file2_func1();
	lib_module1_dir2_file1_func1();
	lib_module1_dir2_file2_func1();

	return;
}
