CC=gcc
CFLAGS=-g -O0 -Wall
OUT=test
FILES=test.c surveil.c

build: $(FILES)
	$(CC) $(CFLAGS) -o $(OUT) $(FILES)

clean:
	rm -f $(OUT)
	rm -rf $(OUT).DSYM
