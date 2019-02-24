sim: shell.c sim.c
	gcc -g -O2 $^ -o $@
	./sim add.mem
.PHONY: clean
clean:
	rm -rf *.o *~ sim
