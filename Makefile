
SRCS		= get_next_line.c get_next_line_utils.c
all: $(SRCS)
	gcc -D BUFFER_SIZE=10 $(SRCS)