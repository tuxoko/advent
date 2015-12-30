TARGET=day01 day02 day03 day04 day05 day06 day07 day09 day10 day12 day13 day14 day15 day16 day17
GEN_TARGET=day07.c
CFLAGS=-O2 -Wall -lcrypto

ifeq ($(V),1)
  quiet=
else
  quiet=q_
endif

call_cmd=@echo "$($(quiet)$(1)_cmd)"; $($(1)_cmd)

cc_cmd=$(CC) $(CFLAGS) $< -o $@
q_cc_cmd="CC $@"

gen_cmd=python3 $< < $(word 2,$^) > $@
q_gen_cmd="GEN $@"

all: $(TARGET)

run: all
	@for i in $(TARGET); do echo $$i; if [ -f $$i.input ]; then ./$$i < $$i.input; else ./$$i; fi; echo; done

$(GEN_TARGET): %.c: %.py %.input
	$(call call_cmd,gen)

% : %.c
	$(call call_cmd,cc)

clean:
	$(RM) $(TARGET) $(GEN_TARGET)
