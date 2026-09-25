#-----------------------------------------------------------------------------------------------
# *** src ***

CC = cc -Wall -Wextra -Werror
remove_slash = $(patsubst %/,%,$1)

SRC_get_next_line = $(wildcard input/get_next_line/*.c)
SRC_load = $(wildcard input/load/*.c)
SRC_table = $(wildcard input/table/*.c)
SRC_libft = $(wildcard utils/libft/*.c)
SRC_green_counts = $(wildcard utils/green_counts/*.c)

SRC_convolve = $(wildcard editor/convolve/*.c)
SRC_paint = $(wildcard editor/paint/*.c)
SRC_evenodd = $(wildcard editor/evenodd/*.c)

SRC_motif = $(wildcard graphic_mlx/motif/*.c)
SRC_window = $(wildcard graphic_mlx/window/*.c)

OUT_paint = $(patsubst %.c, out/%.out, $(SRC_paint))
OUT_motif = $(patsubst %.c, out/%.out, $(SRC_motif))
OUT_window = $(patsubst %.c, out/%.out, $(SRC_window))
OUT_evenodd = $(patsubst %.c, out/%.out, $(SRC_evenodd))

LIB_GRAPHIC = $(patsubst %, ../include/%.a, libmlx42)
GRAPHIC_CONFIG = -ldl -lglfw -pthread
LIB_paint = $(patsubst %, ../src/lib/%.a, paint table)
LIB_motif = $(patsubst %, ../src/lib/%.a, motif) $(LIB_GRAPHIC)
LIB_window = $(patsubst %, ../src/lib/%.a, paint table window) $(LIB_GRAPHIC)
LIB_evenodd = $(patsubst %, ../src/lib/%.a, paint table window evenodd) $(LIB_GRAPHIC)

OUT_LIB = $(OUT_motif) $(OUT_window) $(OUT_evenodd)
OUT_BASIC = $(patsubst %.c, out/%.out,	\
	$(SRC_get_next_line) $(SRC_convolve)\
	$(SRC_load) $(SRC_table) $(SRC_libft) $(SRC_green_counts))

#-----------------------------------------------------------------------------------------------
# *** get input clone file ***

INPUT_FIGLET = $(wildcard ../input_examples/figlet_rozzo/*)
INPUT_FDF = $(wildcard ../input_examples/fdf/*)
INPUT_GNL = $(wildcard input/get_next_line/input/*)

CLONE_FIGLET_LOAD = $(patsubst ../input_examples/figlet_rozzo/%, input/load/clone_input_ascii/%, $(INPUT_FIGLET))
CLONE_FIGLET_TABLE = $(patsubst ../input_examples/figlet_rozzo/%, input/table/clone_input_ascii/%, $(INPUT_FIGLET))
CLONE_FIGLET = $(CLONE_FIGLET_LOAD) $(CLONE_FIGLET_TABLE)
CLONE_FDF_LOAD = $(patsubst ../input_examples/fdf/%, input/load/clone_input_fdf/%, $(INPUT_FDF))
CLONE_FDF_TABLE = $(patsubst ../input_examples/fdf/%, input/table/clone_input_fdf/%, $(INPUT_FDF))
CLONE_FDF = $(CLONE_FDF_LOAD) $(CLONE_FDF_TABLE)
CLONE_GNL = $(patsubst input/get_next_line/input/%, input/get_next_line/clone_input/%, $(INPUT_GNL))

#-----------------------------------------------------------------------------------------------
# *** obj, out, and lib ***
all: all_out all_clone

all_out: $(OUT_BASIC) $(OUT_LIB) $(OUT_paint)
	@echo $^

$(OUT_LIB): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. $(LIB_$(notdir $(call remove_slash, $(dir $@)))) $(GRAPHIC_CONFIG)

$(OUT_BASIC): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. ../src/lib/debug.a ../src/lib/$(notdir $(call remove_slash, $(dir $@))).a

$(OUT_paint): out/%.out: obj/%.o
	@mkdir -p $(@D)
	$(CC) -o $@ $^ -L. $(LIB_paint)

obj/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@

#-----------------------------------------------------------------------------------------------
# *** create output file ***

all_clone: $(CLONE_FDF) $(CLONE_FIGLET) $(CLONE_GNL)
	@echo $^

$(CLONE_FDF): ../input_examples/fdf/$(notdir $@)
	@mkdir -p $(@D)
	touch $@

$(CLONE_FIGLET): ../input_examples/figlet_rozzo/$(notdir $@)
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
	rm -r -f $(CLONE_FIGLET) $(CLONE_FDF) $(CLONE_GNL)

.PHONY: all all_out all_clone clean clean_out clean_clone
