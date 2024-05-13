# Makefile syntax
# targets:dependencies
#	command
SRC_DIR := ../../src

# compile main.c
output.out:common.o array.o main.c
	gcc -Wall common.o array.o main.c -o output.out -I $(SRC_DIR)
	mkdir -p obj
	mv *.o obj

# compile array.c
array.o:$(SRC_DIR)/array/array.c
	gcc -Wall -c $(SRC_DIR)/array/array.c -o array.o

# compile common.c
# -c: compile without linking.
# -o file.o: output to object file.
common.o:$(SRC_DIR)/common/common.c
	gcc -Wall -c $(SRC_DIR)/common/common.c -o common.o

run:
	./output.out

clean:
	rm -f *.out
	rm -rf obj