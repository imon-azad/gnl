
SRCS		= get_next_line.c ft_substr.c ft_strchr.c ft_strjoin.c
all: $(SRCS)
	gcc -D BUFFER_SIZE=10 $(SRCS)