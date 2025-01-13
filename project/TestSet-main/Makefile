# Variables
CC=gcc
CFLAGS=-Wall -Iinclude -fno-stack-protector
LIBFLAGS=$(patsubst lib/lib%.so,-l%,$(wildcard lib/lib*.so))
LDFLAGS=-Llib 
SRCDIR=src
BINDIR=bin
LIBDIR=lib
INCDIR=include

# Find all .c and .cpp files in src/bin and src/lib
BIN_SOURCES=$(wildcard $(SRCDIR)/bin/*.c $(SRCDIR)/bin/*.C $(SRCDIR)/bin/*.cpp $(SRCDIR)/bin/*.CPP)
LIB_SUBDIRS=$(wildcard $(SRCDIR)/lib/*)

# Convert source file names to executable and .so shared library files
BIN_EXECUTABLES=$(patsubst $(SRCDIR)/bin/%.c,$(BINDIR)/%,$(BIN_SOURCES)) $(patsubst $(SRCDIR)/bin/%.C,$(BINDIR)/%,$(BIN_SOURCES)) $(patsubst $(SRCDIR)/bin/%.cpp,$(BINDIR)/%,$(BIN_SOURCES)) $(patsubst $(SRCDIR)/bin/%.CPP,$(BINDIR)/%,$(BIN_SOURCES))
LIB_OBJECTS=$(patsubst $(SRCDIR)/lib/%,$(LIBDIR)/lib%.so,$(LIB_SUBDIRS))

# Default rule
all: directories includes  $(LIB_OBJECTS) $(BIN_EXECUTABLES) 

# Rule to create necessary directories
directories:
	mkdir -p $(BINDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(INCDIR)

# Rule to compile executables in bin directory
$(BINDIR)/%: $(SRCDIR)/bin/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBFLAGS)

$(BINDIR)/%: $(SRCDIR)/bin/%.C
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBFLAGS)

$(BINDIR)/%: $(SRCDIR)/bin/%.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBFLAGS)

$(BINDIR)/%: $(SRCDIR)/bin/%.CPP
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@ $(LIBFLAGS)

# Rule to compile .so files in lib directory
$(LIBDIR)/lib%.so: $(SRCDIR)/lib/%
	$(CC) $(CFLAGS) -shared -fPIC $(wildcard $</*.c $</*.C $</*.cpp $</*.CPP) -o $@

# Copy all header files to include directory
includes:
	find $(SRCDIR)/lib -name '*.h' -exec cp {} $(INCDIR) \;

# Add lib to LD_LIBRARY_PATH
#ld_path:
#	export LD_LIBRARY_PATH=$(PWD)/$(LIBDIR):$$LD_LIBRARY_PATH

# Rule to clean the build
clean:
	rm -f $(BINDIR)/*
	rm -f $(LIBDIR)/*
	rm -f $(INCDIR)/*
