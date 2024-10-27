CROSS_COMPILE = Native

ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
		lib=aarch64-none-linux-gnu-gcc
	else
		lib=cc
	endif

writer: writer.o
	$(lib) writer.o  -o writer

writer.o: writer.c
	$(lib) -c writer.c  -o writer.o


clean:
	rm -f writer
	rm *.o