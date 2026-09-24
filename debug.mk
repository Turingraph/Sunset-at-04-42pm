# https://stackoverflow.com/questions/12057852/multiple-makefiles-in-one-directory

all:
	$(MAKE) -C src -f debug.mk
	$(MAKE) -C unit_test -f Makefile

clean:
	$(MAKE) -C src -f debug.mk clean
	$(MAKE) -C unit_test -f Makefile clean

re:
	make -f debug.mk clean
	make -f debug.mk all

.PHONY: all clean re

# make -f debug.mk all
