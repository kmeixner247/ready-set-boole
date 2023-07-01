NAME		=	build/librsb.a
TEST_NAME	=	build/test/rsbTest
RED			:= \033[0;31m
PINK		:= \033[0;35m
CLEAR		:= \033[0m

all: $(NAME)

$(NAME):
	@cmake -B build
	@cmake --build build --target rsb -j 10
	@echo "$(PINK)Library successfully built to path \"$(NAME)\"!$(CLEAR)"

test: $(TEST_NAME)

$(TEST_NAME):
	@cmake -B build
	@cmake --build build --target rsbTest -j 10
	@echo "$(PINK)Library successfully built to path \"$(NAME)\"!$(CLEAR)"
	@echo "$(PINK)Tester successfully built to path \"$(TEST_NAME)\"!$(CLEAR)"

clean:
	@rm -rf build
	@echo "$(RED)... build directory successfully cleaned!$(CLEAR)"

re: clean all

.PHONY: all test clean re