#subdirs:=$(shell ls -l| grep "^d" |awk '{print $$9}' )

subdirs:=lib_dir1 lib_dir2
srcs:=$(wildcard *.c)
objs:=$(srcs:%.c=%.o)
deps:=$(srcs:.c=.d)
libname:=$(shell pwd |sed 's/^\(.*\)[/]//' )
vpath %.o ./obj

CFLAGS=-c -g -Wall

lib$(libname).a:$(objs) $(subdirs)
	ar r lib/lib$(libname).a ./obj/*.o

#.PHONY: obj_files $(subdirs)
#obj_files:$(objs) $(subdirs)

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<

.PHONY:$(subdirs)
$(subdirs):
	make -C $@
	cp $@/obj/* ./obj/

.PHONY: clean
clean:
	rm -rf obj/*.o dep/*.d lib/*.a
	for dir in $(subdirs);do make clean -C $$dir; done	

