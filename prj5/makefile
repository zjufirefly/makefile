srcs:=$(wildcard *.c)
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

CFLAGS=-c -g -Wall -fPIC

prog:libprog.so
	gcc -L. -lprog -o prog 

libprog.so:$(objs)
	gcc -shared -fPIC $(objs) -o libprog.so 

-include $(deps)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" $< -o $@


.PHONY: clean
clean:
	rm -rf prog *.o *.d *.so


