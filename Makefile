# GENERIC
NAME = prog
CC = gcc
CFLAGS = -Wall -Wextra

# INCLUDES
#INC = 

# SOURCES
SRCDIR =	$(wildcard src/*.c)
#vpath=../src:../src/game
#SRC = main.c test.c

# OBJECTS
#OBJDIR = src/tmp/
#OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
OBJ = $(SRCDIR:.c=.o)


# OS DEPENDANT VARIABLES
$(info Compiling for Windows.)
EXT = .exe
DEL = del /q
FixPath = $(subst /,\,$1)
SDLPATH = -Iinclude/SDL2
LIB = -Linclude/SDL2 -lmingw32 -lib/lSDL2main -lib/SlSDL2



# RULES
all: $(NAME)

$(NAME): 
	gcc $(SRCDIR) -o Game.exe -I include/SDL2 -L lib -lmingw32 -lSDL2main -lSDL2.dll
	Game.exe

%.o: %.c
#	$(info Compiling $< into $@)
	$(CC) $(CFLAGS) -c $(call FixPath, $<) -o $(call FixPath, $@) $(call FixPath, $(SDLPATH))

linux:
	clear && gcc src/*.c -lm -o Game `sdl2-config --cflags --libs` && ./Game

clean:
	$(DEL) $(call FixPath, $(OBJ))

fclean: clean
	$(DEL) $(call FixPath, $(NAME)$(EXT))

re: fclean all


.PHONY: err, all, clean, fclean, re
