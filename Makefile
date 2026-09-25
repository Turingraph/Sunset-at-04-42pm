all:
	$(MAKE) -C src -f Makefile all

clean:
	$(MAKE) -C src -f Makefile clean

re:
	$(MAKE) -C src -f Makefile clean
	$(MAKE) -C src -f Makefile all

.PHONY: all clean re

# make -f Makefile all
