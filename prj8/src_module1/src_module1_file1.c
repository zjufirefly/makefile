#include <stdio.h>
#include "src_module1_file1.h"
#include "./src_dir1/src_module1_dir1_file1.h"
#include "./src_dir1/src_module1_dir1_file2.h"
#include "./src_dir2/src_module1_dir2_file1.h"
#include "./src_dir2/src_module1_dir2_file2.h"

void src_module1_file1_func1()
{
	printf("src_module1_file1_func1\n");

	src_module1_dir1_file1_func1();
	src_module1_dir1_file2_func1();
	src_module1_dir2_file1_func1();
	src_module1_dir2_file2_func1();

	return;
}
