CXX = /usr/bin/gcc
CXXFLAGS = -pedantic -Iinc -Llib -O3 -pg -std=c99
LDFLAGS = -lm -lfp

BINDIR = bin
LIBDIR = lib
SRCDIR = ./src
INCDIR = ./inc
TSTDIR = ./test
TESTSC:=$(wildcard test/*.c)
TESTSINC=$(basename $(TESTSC))

all: clean $(BINDIR) $(LIBDIR) library

complete: clean all pi $(TESTSINC) testrun

$(BINDIR):
	@mkdir -p $(BINDIR)
	@mkdir -p $(BINDIR)/test

$(LIBDIR):
	@mkdir -p $(LIBDIR)

library: $(SRCDIR)/fp.c $(INCDIR)/fp.h
	@echo "[sefp] Compiling process started"
	@$(CXX) -c $(CXXFLAGS) -o $(BINDIR)/fp.o $<
	@ar r $(LIBDIR)/libfp.a $(BINDIR)/fp.o 2>/dev/null
	@ranlib $(LIBDIR)/libfp.a
	@echo "[sefp] Library successfully compiled"

$(TESTSINC): $(TESTSC)

$(TESTSINC) : test/% : test/%.c
	@$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $< $(LDFLAGS) 

testrun :
	@echo "Test execution:"
	@$(TSTDIR)/execute

pi: $(SRCDIR)/pi.c
	@$(CXX) $(CXXFLAGS) -o $(BINDIR)/pi $(SRCDIR)/pi.c $(LDFLAGS)

clean:
	@rm -rf $(BINDIR) $(LIBDIR) gmon.out
