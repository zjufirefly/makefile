srcs:=src1.c src2.c src3.c
objs:=$(srcs:.c=.o)
deps:=$(srcs:.c=.d)

vpath %.a ./lib
vpath %.o ./obj

CFLAGS=-c -g -Wall -fPIC

prog:libprog.so prog.o
	gcc obj/prog.o -L./lib -lprog -o prog 


libprog.so:$(objs)
	gcc -shared -fPIC -o lib/libprog.so $(objs:%=obj/%)

-include dep/prog.d
prog.o:prog.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<

-include $(deps:%=dep/%)
$(objs):%.o:%.c
	gcc $(CFLAGS) -MMD -MP -MF"$(@:%.o=dep/%.d)" -MT"$@" -o obj/$@ $<



.PHONY: clean
clean:
	rm -rf prog *.o *.d *.so lib/*.so obj/*.o dep/*.d


