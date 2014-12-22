#subdirs:=$(shell ls -l| grep "^d" |awk '{print $$9}' )

subdirs:=src_dir1 src_dir2
srcs:=$(wildcard *.c)
objs:=$(srcs:%.c=%.o)
deps:=$(srcs:.c=.d)
vpath %.o ./obj

CFLAGS=-c -g -Wall

.PHONY: obj_files $(subdirs)
obj_files:$(objs) $(subdirs)

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<

.PHONY: $(subdirs)
$(subdirs):
	make -C $@
	cp $@/obj/* ./obj/

.PHONY: clean
clean:
	rm -rf obj/*.o dep/*.d
	for dir in $(subdirs);do make clean -C $$dir; done	

