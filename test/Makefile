#-----------------------------------------------------------------------------------------------
# *** src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)

SRC_get_next_line = $(wildcard input/get_next_line/*.c)
SRC_decimal = $(wildcard input/decimal/*.c)
SRC_table = $(wildcard input/table/*.c)
SRC_libft = $(wildcard utils/libft/*.c)
SRC_taylor = $(wildcard utils/taylor/*.c)

SRC_convolve = $(wildcard paint/convolve/*.c)
SRC_paint = $(wildcard paint/paint/*.c)

SRC_motif = $(wildcard visualize/motif/*.c)
SRC_window = $(wildcard visualize/window/*.c)

OUT_paint = $(patsubst %.c, out/%.out, $(SRC_paint))
OUT_motif = $(patsubst %.c, out/%.out, $(SRC_motif))
OUT_window = $(patsubst %.c, out/%.out, $(SRC_window))
OUT_convolve = $(patsubst %.c, out/%.out, $(SRC_convolve))

LIB_GRAPHIC = $(patsubst %, ../include/%.a, libmlx42)
GRAPHIC_CONFIG = -ldl -lglfw -pthread
LIB_motif = $(patsubst %, ../src/lib/%.a, motif) $(LIB_GRAPHIC)
LIB_window = $(patsubst %, ../src/lib/%.a, gradient window) $(LIB_GRAPHIC)
LIB_paint = $(patsubst %, ../src/lib/%.a, gradient debug table window aura convolve) $(LIB_GRAPHIC)
LIB_convolve = $(patsubst %, ../src/lib/%.a, debug convolve) $(LIB_GRAPHIC)

OUT_LIB = $(OUT_motif) $(OUT_window) $(OUT_paint) $(OUT_convolve)
OUT_BASIC = $(patsubst %.c, out/%.out,	\
	$(SRC_get_next_line) \
	$(SRC_decimal) $(SRC_table) $(SRC_libft) $(SRC_taylor))

#-----------------------------------------------------------------------------------------------
# *** get input clone file ***

INPUT_FIGLET = $(wildcard ../corpus/figlet_rozzo/*)
INPUT_FDF = $(wildcard ../corpus/fdf/*)
INPUT_GNL = $(wildcard input/get_next_line/input/*)

CLONE_FIGLET_decimal = $(patsubst ../corpus/figlet_rozzo/%, input/decimal/clone_input_ascii/%, $(INPUT_FIGLET))
CLONE_FIGLET_TABLE = $(patsubst ../corpus/figlet_rozzo/%, input/table/clone_input_ascii/%, $(INPUT_FIGLET))
CLONE_FIGLET = $(CLONE_FIGLET_decimal) $(CLONE_FIGLET_TABLE)
CLONE_DECIMAL_decimal = $(patsubst ../corpus/fdf/%, input/decimal/clone_input_fdf/%, $(INPUT_FDF))
CLONE_DECIMAL_TABLE = $(patsubst ../corpus/fdf/%, input/table/clone_input_fdf/%, $(INPUT_FDF))
CLONE_DECIMAL = $(CLONE_DECIMAL_decimal) $(CLONE_DECIMAL_TABLE)
CLONE_GNL = $(patsubst input/get_next_line/input/%, input/get_next_line/clone_input/%, $(INPUT_GNL))

#-----------------------------------------------------------------------------------------------
# *** obj, out, and lib ***
all: all_out all_clone

all_out: $(OUT_BASIC) $(OUT_LIB)
	@echo $^

$(OUT_LIB): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. $(LIB_$(notdir $(call remove_slash, $(dir $@)))) $(GRAPHIC_CONFIG)

$(OUT_BASIC): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/debug.a ../src/lib/$(notdir $(call remove_slash, $(dir $@))).a

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** create output file ***

all_clone: $(CLONE_DECIMAL) $(CLONE_FIGLET) $(CLONE_GNL)
	@echo $^

$(CLONE_DECIMAL): ../corpus/fdf/$(notdir $@)
	@mkdir -p $(@D)
	touch $@

$(CLONE_FIGLET): ../corpus/figlet_rozzo/$(notdir $@)
	@mkdir -p $(@D)
	touch $@

$(CLONE_GNL): input/get_next_line/input/$(notdir $@)
	@mkdir -p $(@D)
	touch $@

#-----------------------------------------------------------------------------------------------
# *** clean ***
clean: clean_out clean_clone

clean_out:
	rm -r -f out/
	rm -r -f lib/
	rm -r -f obj/

clean_clone:
	rm -r -f $(CLONE_FIGLET) $(CLONE_DECIMAL) $(CLONE_GNL)

.PHONY: all all_out all_clone clean clean_out clean_clone
