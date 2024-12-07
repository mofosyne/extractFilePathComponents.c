all: clean test

test: $(OBJS)
	$(CC) filenameExtractPathAndExtension.c test.c -std=c99 -Wall -Werror -o test
	./test

clean:
	rm -f test

.PHONY: test