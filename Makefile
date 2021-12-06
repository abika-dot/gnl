buf=0

all:
	@echo "$(buf)"
	@echo "$(buf)"
	gcc -g main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$(buf)
	./a.out