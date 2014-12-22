srcs:=$(wildcard *.c)
objs:=$(srcs:%.c=%.o)
deps:=$(srcs:.c=.d)
incs:=-I../src_module1/include -I../src_module2/include
vpath %.o ./obj

CFLAGS=-c -g -Wall $(incs)


.PHONY: obj_files
obj_files:$(objs)

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<


.PHONY: clean
clean:$(subdirs_clean)
	rm -rf obj/*.o dep/*.d

