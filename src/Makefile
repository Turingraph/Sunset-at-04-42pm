
# *** variable ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42
LIB_DIR = ../include/
LIBRARY = $(LIB_DIR)sunset442pm.a
SRC_all = $(wildcard */*/*.c)
OBJ_all = $(patsubst %.c, obj/%.o, $(SRC_all))

# *** create library ***

all: $(LIBRARY)

$(LIB_DIR)sunset442pm.a: $(OBJ_all)
	@mkdir -p $(@D)
	ar rcs $@ $^

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/input/get_next_line/%.o: input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f obj/
	rm -f $(LIB_DIR)sunset442pm.a

re: clean
	all

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean re
