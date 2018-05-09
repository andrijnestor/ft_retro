CC = clang++

NAME = ft_retro

FLAGS = -Wall -Wextra -Werror -std=c++98

IDIR = ./inc

DIR_S = ./src

DIR_O = ./obj

EXTENSIONS = $(addprefix $(IDIR)/,$(EXT))

EXT	= ft_ 

SOURCES =  main.cpp \
		   Asteroid.cpp \
		   Entity.cpp \
		   Hero.cpp \
		   Enemy.cpp \
		   Bullet.cpp \
		   Game.cpp

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) -lncurses

obj:
	mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.cpp
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS) -I./inc/

clean:
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.SILENT:
