srcs=src1.c src2.c prog.c
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

CFLAGS=-c -g -Wall

prog:$(objs)
	gcc -o prog $^

-include $(deps)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -o $@ $<


.PHONY: clean
clean:
	rm -rf prog *.o *.d


