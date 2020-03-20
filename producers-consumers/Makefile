CC = gcc
CFLAGS = -O3 -g -Wall -std=c99 -std=gnu99 -pthread -lm
SDIR = ./src
LDIR = ./lib
IDIR = ./inc
INCLUDES = -I$(IDIR)
LIBRARIES = -L$(LDIR)
EXE = $(SDIR)/exec
LIBS = $(LDIR)/$(MAIN).a
MAIN=main


all:	$(EXE)

lib: $(LIBS)

$(SDIR)/exec: $(SDIR)/$(MAIN).c $(LDIR)/$(MAIN).a
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBRARIES) -o $@ $^




$(LDIR)/%.a: $(SDIR)/%.o $(SDIR)/functions.o $(SDIR)/queue.o $(SDIR)/prod_cons.o
	ar rcs $@ $^



$(SDIR)/main.o: $(SDIR)/$(MAIN).c
	$(CC) $(INCLUDES) -o $@ -c $^

$(SDIR)/functions.o: $(SDIR)/functions.c
	$(CC) $(INCLUDES) -o $@ -c $^

$(SDIR)/queue.o: $(SDIR)/queue.c
	$(CC) $(INCLUDES) -o $@ -c $^

$(SDIR)/prod_cons.o: $(SDIR)/prod_cons.c
	$(CC) $(INCLUDES) -o $@ -c $^


clean:
	rm -f $(SDIR)/*.o $(EXE) $(LIBS)
