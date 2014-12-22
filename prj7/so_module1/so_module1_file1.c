#include <stdio.h>
#include "so_module1_file1.h"
#include "./so_dir1/so_module1_dir1_file1.h"
#include "./so_dir1/so_module1_dir1_file2.h"
#include "./so_dir2/so_module1_dir2_file1.h"
#include "./so_dir2/so_module1_dir2_file2.h"

void so_module1_file1_func1()
{
	printf("so_module1_file1_func1\n");

	so_module1_dir1_file1_func1();
	so_module1_dir1_file2_func1();
	so_module1_dir2_file1_func1();
	so_module1_dir2_file2_func1();

	return;
}
