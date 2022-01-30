SRCS   =	get_next_line_utils.c \
			get_next_line.c \
			ft_itoa.c \
			s_map.c \
			s_map_compteurs.c \
			s_vars_fleche.c \
			s_vars_key.c \
			s_vars_refresh.c \
			main.c


OBJS   = ${SRCS:.c=.o}

NAME   = so_long

CC     = gcc
RM     = rm -f

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=400
OFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
