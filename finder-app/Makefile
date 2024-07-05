CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -O2

LD = $(CROSS_COMPILE)gcc
LDFLAGS =

SRCS = writer.c

OBJDIR = build
OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
OUTDIR = bin

TARGET = $(OUTDIR)/writer

$(TARGET): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(LD) $(LDFLAGS) -o $@ $^
	ln -fs $@ `basename $@`

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OUTDIR)
	rm -r $(OBJDIR)

.PHONY: clean
