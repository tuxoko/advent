TARGET=day01 day02 day03 day04 day05 day06 day07 day09 day10 day12 day13 day14 day15 day16 day17
CFLAGS=-O2 -Wall -lcrypto

all: $(TARGET)

run: all
	@for i in $(TARGET); do echo $$i; if [ -f $$i.input ]; then ./$$i < $$i.input; else ./$$i; fi; echo; done

day07.c: day07.py day07.input
	@python3 $< < $(word 2,$^) > $@
	@echo "GEN $@"

% : %.c
	@$(CC) $(CFLAGS) $< -o $@
	@echo "CC $@"

clean:
	$(RM) $(TARGET) day07.c
