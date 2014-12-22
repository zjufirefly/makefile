subdirs:=so_dir1 so_dir2
srcs:=$(wildcard *.c)
objs:=$(srcs:%.c=%.o)
deps:=$(srcs:.c=.d)
libname:=$(shell pwd |sed 's/^\(.*\)[/]//' )
vpath %.o ./obj
vpath $.so ./so

CFLAGS=-c -g -Wall -fPIC

lib$(libname).so:$(objs) $(subdirs)
	gcc -shared -fPIC -o so/lib$(libname).so ./obj/*.o

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
	rm -rf obj/*.o dep/*.d so/*.so
	for dir in $(subdirs);do make clean -C $$dir; done	

