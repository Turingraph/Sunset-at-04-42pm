#-----------------------------------------------------------------------------------------------
# *** coding coding_examples src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)
# get_obj_files = $(filter %.o, $1)
# get_lib_a_files = $(filter %.a, $^)

OUT_DIR = out/
SRC_WINDOW = $(wildcard graphic/window/*.c)
OUT_WINDOW = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC_WINDOW))
SRC_PAINT = $(wildcard editor/paint/*.c)
OUT_PAINT = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC_PAINT))
# https://stackoverflow.com/questions/10276202/exclude-source-file-in-compilation-using-makefile
SRC = $(filter-out $(SRC_PAINT) $(wildcard graphic/*/*.c) $(SRC_LINE), $(wildcard */*/*.c))
OUT = $(patsubst %.c, $(OUT_DIR)%.out, $(SRC))

#-----------------------------------------------------------------------------------------------
# *** obj and out ***
all: $(OUT) $(OUT_PAINT) $(OUT_USE_TABLE) $(OUT_WINDOW)
	@echo $^

$(OUT_PAINT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a ../src/lib/table.a ../src/lib/mathart.a -lm

$(OUT_WINDOW): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a \
	../src/lib/paint.a ../src/lib/table.a ../include/libmlx42.a -ldl -lglfw -pthread -lm

$(OUT): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/$(basename $(notdir $(call remove_slash, $(dir $@)).c)).a -lm

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

.PHONY: all clean
