include env

src_modules:=src_module1 src_module2 main
lib_modules:=lib_module1 lib_module2
so_modules:=so_module1 so_module2
lib_files:=$(lib_modules:%=-l%)
so_files:=$(so_modules:%=-l%)
export root_dir:=$(shell pwd)
export INCS:=-I./include
export CFLAGS

prog:$(src_modules) $(lib_modules) $(so_modules)
	gcc obj/*.o -L./lib $(lib_files) -L./so $(so_files) -o prog


.PHONY:$(src_modules)
$(src_modules):
	make -C $@
	cp $@/obj/* ./obj/

.PHONY:$(lib_modules)
$(lib_modules):
	make -C $@
	cp $@/lib/* ./lib/

.PHONY:$(so_modules)
$(so_modules):
	make -C $@
	cp $@/so/* ./so/

.PHONY: clean
clean:
	rm -rf obj/*.o lib/*.a so/*.so prog
	for dir in $(src_modules) $(lib_modules) $(so_modules) ;do make clean -C $$dir; done
