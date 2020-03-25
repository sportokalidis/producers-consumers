CC = gcc
CFLAGS = -O3 -g -Wall -std=c99 -std=gnu99 -lpthread -lm
SDIR = ./src
LDIR = ./lib
IDIR = ./inc
INCLUDES = -I$(IDIR)
LIBRARIES = -L$(LDIR)
EXE = $(SDIR)/exec
LIBS = $(LDIR)/$(MAIN).a
MAIN=prod_cons
CLEAN = clean

all: $(CLEAN)	$(EXE)

lib: $(LIBS)

$(SDIR)/exec: $(SDIR)/$(MAIN).c $(LDIR)/$(MAIN).a
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) -o $@ $^




$(LDIR)/%.a: $(SDIR)/%.o $(SDIR)/functions.o $(SDIR)/queue.o $(SDIR)/prod_cons.o
	ar rcs $@ $^



$(SDIR)/$(MAIN).o: $(SDIR)/$(MAIN).c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

$(SDIR)/functions.o: $(SDIR)/functions.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

$(SDIR)/queue.o: $(SDIR)/queue.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^



clean:
	rm -f $(SDIR)/*.o $(EXE) $(LIBS)
