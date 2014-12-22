src_modules:=src_module1 src_module2 main
lib_modules:=lib_module1 lib_module2
so_module:=so_module1 so_module2
lib_files:=$(lib_modules:%=-l%)

prog:$(src_modules) $(lib_modules)
	gcc obj/*.o -L./lib $(lib_files) -o prog


.PHONY:$(src_modules)
$(src_modules):
	make -C $@
	cp $@/obj/* ./obj/

.PHONY:$(lib_modules)
$(lib_modules):
	make -C $@
	cp $@/lib/* ./lib/


.PHONY: clean
clean:
	rm -rf obj/*.o lib/*.a prog
	for dir in $(src_modules) $(lib_modules);do make clean -C $$dir; done
