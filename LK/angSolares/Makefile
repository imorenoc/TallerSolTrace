
# Compilador usado
CC = gcc

objects = run.o db.o

db: $(objects)
	gcc -o run $(objects) -lm

$(objects): db.h

.PHONY: clean
clean:
	-rm run $(objects)
