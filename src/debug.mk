
#-----------------------------------------------------------------------------------------------
# *** command ***

CC = cc -Wall -Wextra -Werror
BUFFER_SIZE = 42
# get_obj_files = $(filter %.o, $1)
# get_lib_a_files = $(filter %.a, $^)

#-----------------------------------------------------------------------------------------------
# https://stackoverflow.com/questions/9488256/use-directory-path-of-target-in-list-of-prerequisites-in-makefile
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:

# *** library ***
LIBRARY = $(patsubst %, lib/%.a, debug \
	ascii decimal get_next_line table \
	aura convolve gradient spots \
	libft taylor \
	motif proj2d raster render window)

# *** atom src ***
SRC_libft = $(wildcard utils/libft/*.c)
SRC_taylor = $(wildcard utils/taylor/*.c)
SRC_get_next_line = $(wildcard input/get_next_line/*.c)

# *** composed src ***
SRC_debug = $(wildcard debug/debug/*.c)
SRC_ascii = $(wildcard input/ascii/*.c)
SRC_decimal = $(wildcard input/decimal/*.c)
SRC_table = $(wildcard input/table/*.c)

SRC_aura = $(wildcard paint/aura/*.c)
SRC_convolve = $(wildcard paint/convolve/*.c)
SRC_gradient = $(wildcard paint/paint/*.c)
SRC_spots = $(wildcard paint/spots/*.c)

SRC_raster = $(wildcard visualize/raster/*.c)
SRC_motif = $(wildcard visualize/motif/*.c)
SRC_proj2d = $(wildcard visualize/proj2d/*.c)
SRC_render = $(wildcard visualize/render/*.c)
SRC_window = $(wildcard visualize/window/*.c)

#-----------------------------------------------------------------------------------------------

# *** elementary obj ***
OBJ_libft = $(patsubst %.c, obj/%.o, $(SRC_libft))
OBJ_taylor = $(patsubst %.c, obj/%.o, $(SRC_taylor)) $(OBJ_libft)
OBJ_get_next_line = $(patsubst %.c, obj/%.o, $(SRC_get_next_line))

# *** composed obj ***
OBJ_debug = $(patsubst %.c, obj/%.o, $(SRC_debug)) $(OBJ_decimal)
OBJ_ascii = $(patsubst %.c, obj/%.o, $(SRC_ascii)) $(OBJ_libft) $(OBJ_get_next_line)
OBJ_decimal = $(patsubst %.c, obj/%.o, $(SRC_decimal)) $(OBJ_ascii)
OBJ_table = $(patsubst %.c, obj/%.o, $(SRC_table)) $(OBJ_decimal)

OBJ_aura = $(patsubst %.c, obj/%.o, $(SRC_aura)) $(OBJ_taylor)
OBJ_convolve = $(patsubst %.c, obj/%.o, $(SRC_convolve)) $(OBJ_table) $(OBJ_taylor)
OBJ_gradient = $(patsubst %.c, obj/%.o, $(SRC_gradient)) $(OBJ_taylor)
OBJ_spots = $(patsubst %.c, obj/%.o, $(SRC_spots)) $(OBJ_taylor)

OBJ_raster = $(patsubst %.c, obj/%.o, $(SRC_raster)) $(OBJ_taylor) $(OBJ_table)
OBJ_motif = $(patsubst %.c, obj/%.o, $(SRC_motif)) $(OBJ_raster)
OBJ_proj2d = $(patsubst %.c, obj/%.o, $(SRC_proj2d)) $(OBJ_table) $(OBJ_taylor)
OBJ_render = $(patsubst %.c, obj/%.o, $(SRC_render)) $(OBJ_proj2d) $(OBJ_raster)
OBJ_window = $(patsubst %.c, obj/%.o, $(SRC_window)) $(OBJ_render)

# https://stackoverflow.com/questions/59465799/avoid-gnu-make-automatic-file-deletion
# This command will preserve the selected files.
# .PRECIOUS: $(OBJ_libft) $(OBJ_get_next_line)

#-----------------------------------------------------------------------------------------------
# *** create library ***

all: $(LIBRARY)

# ChatGPT recommended me this solution.
# The takes away is reading the functions for files name section of Makefile manual first
# (a.k.a. https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_node/make_79.html )
# if you have to manipulating the string of the files/folders name according to correct 
# format like this, for example you might want to split string as arrays of string,
# with `,` or `/` as the separators.
lib/%.a: $$(OBJ_$$(notdir $$(basename $$@)))
	@mkdir -p $(@D)
	ar rcs $@ $^

# *** create object files. ***
# https://stackoverflow.com/questions/1950926/create-directories-using-make-file
obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

obj/input/get_next_line/%.o: input/get_next_line/%.c
	@mkdir -p $(@D)
	$(CC) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
# https://askubuntu.com/questions/802996/how-to-remove-directory-with-all-of-its-contents
clean:
	rm -r -f lib/
	rm -r -f obj/

# Lol, both Makefile tutorial and Suisei already cover .PHONY
# https://youtu.be/N029UUlH1Dc?si=8PragRfDm3MzFOBc
.PHONY: all clean
