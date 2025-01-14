CC = gcc
CFLAGS = -Wall -Wextra -pedantic
CCFLAGS = -I/usr/local/include -I/usr/include/SDL2 -D_REENTRANT -L/usr/local/lib -lm -lSDL2 -g3 -lGL

PROJECTNAME = pxed

SRCDIR = src
OBJDIR = obj

TARGET   = $(PROJECTNAME)
CSOURCES = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c)))
OBJS     = $(CSOURCES:%.c=$(OBJDIR)/%.o)

all: rm-elf prepare $(TARGET)

clean:
	rm -rf $(OBJDIR)

rm-elf:
	-rm -f $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(CCFLAGS)

prepare:
	mkdir -p $(OBJDIR)
