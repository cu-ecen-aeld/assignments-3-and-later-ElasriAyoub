ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	CC := $(CROSS_COMPILE)gcc
else
	CC := cc
endif

all: writer

writer: writer.o
	$(CC) -o writer writer.o

writer.o: writer.c
	$(CC) -c writer.c

	
# Clean target: safely remove generated files
clean:
	@if [ -f writer ]; then rm -f writer; fi
	@if [ -f writer.o ]; then rm -f writer.o; fi