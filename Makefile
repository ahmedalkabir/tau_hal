VPATH = src include
CC=gcc

%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

# %:
%: %.c
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@