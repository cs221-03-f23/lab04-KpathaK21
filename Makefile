OBJS = test.o lab04.o
PROG = lab04

%.o: %.c
	gcc -c -g -o $@ $<

$(PROG): $(OBJS)
	gcc -o $@ $^

clean:
	rm -f $(PROG) $(OBJS)
