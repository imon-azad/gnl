
SRCS		= get_next_line.c get_next_line_utils.c
all: $(SRCS)
	gcc -D BUFFER_SIZE=1 $(SRCS)
debug: $(SRCS)
	gcc -g3 -Wall -Wextra -Werror -D BUFFER_SIZE=1 -fsanitize=address $(SRCS) && ./a.out