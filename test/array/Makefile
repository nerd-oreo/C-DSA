# Makefile syntax
# targets:dependencies
#	command
SRC_DIR := ../../src

# compile main.c
output.out:common.o stack.o main.c
	gcc -Wall common.o stack.o main.c -o output.out -I $(SRC_DIR)
	mkdir -p obj
	mv *.o obj

# compile stack.c
stack.o:$(SRC_DIR)/stack/stack.c
	gcc -Wall -c $(SRC_DIR)/stack/stack.c -o stack.o

# compile common.c
# -c: compile without linking.
# -o file.o: output to object file.
common.o:$(SRC_DIR)/common/common.c
	gcc -Wall -c $(SRC_DIR)/common/common.c -o common.o

clean:
	rm -f *.out
	rm -rf obj