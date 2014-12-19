srcs:=$(wildcard *.c)
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

CFLAGS=-c -g -Wall

prog:libprog.a
	gcc -L. -lprog -o prog 

libprog.a:$(objs)
	ar r libprog.a $(objs)

-include $(deps)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -o $@ $<


.PHONY: clean
clean:
	rm -rf prog *.o *.d *.a


