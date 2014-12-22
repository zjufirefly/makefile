src_modules:=src_module1 src_module2 main
lib_modules:=lib_module1 lib_module2
so_module:=so_module1 so_module2


prog:$(src_modules)
	gcc obj/*.o -o prog


.PHONY:$(src_modules)
$(src_modules):
	make -C $@
	cp $@/obj/* ./obj/


.PHONY: clean
clean:
	rm -rf obj/*.o
	for dir in $(src_modules);do make clean -C $$dir; done
