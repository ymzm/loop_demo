OBJS = main.o \
	   time_assist_routine.o

main: $(OBJS)
%.o : %.c
	gcc -c $^ -o $@

clean:
	-rm -rf $(OBJS)
