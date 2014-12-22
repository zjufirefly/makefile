srcs:=$(wildcard *.c)
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

vpath %.o ./obj
CFLAGS=-c -g -Wall


.PHONY:obj_files
obj_files:$(objs)

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<


.PHONY: clean
clean:
	rm -rf dep/*.d obj/*.o
