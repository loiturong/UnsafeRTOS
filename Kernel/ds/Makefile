.PHONY: stack

FLAGS	:= -O2 -Wall -g -std=c11 -DHOSTTEST
TEST	:= build/stack_test.o
ST_SRC	:= stack.c stack_test.c

stack: $(ST_SRC)
	@mkdir -p $(dir $(TEST))
	$(CC) $(FLAGS) $(ST_SRC) -o $(TEST)
	./$(TEST)

