.PHONY: all

FLAGS	:= -O2 -DHOSTTEST
TEST	:= build/heap_test.o
SRC	:= heap.c heap_test.c

all: $(SRC)
	@mkdir -p $(dir $(TEST))
	$(CC) $(FLAGS) $(SRC) -o $(TEST)
	./$(TEST)
