srcs:=src1.c src2.c src3.c
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

vpath %.a ./lib
vpath %.o ./obj

CFLAGS=-c -g -Wall

prog:libprog.a prog.o
	gcc obj/prog.o -L./lib -lprog -o prog 


libprog.a:$(objs)
	ar r lib/libprog.a $(objs:%=obj/%)

-include dep/prog.d
prog.o:prog.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<



.PHONY: clean
clean:
	rm -rf prog *.o *.d *.a lib/*.a obj/*.o dep/*.d


