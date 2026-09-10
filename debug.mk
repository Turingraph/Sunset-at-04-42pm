# https://stackoverflow.com/questions/12057852/multiple-makefiles-in-one-directory

all:
	make -f src/debug.mk
	make -f unit_test/Makefile

clean:
	make -f src/debug.mk clean
	make -f unit_test/Makefile clean

.PHONY: all clean
