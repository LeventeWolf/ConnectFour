libboard_LIB:=libboard.a
libboard_SRCS:=board.c
libboard_OBJS:=$(patsubst %.c,%.o,$(libboard_SRCS))
libboard_DEPS:=$(patsubst %.c,%.d,$(libboard_SRCS))

all: $(libboard_LIB)

$(libboard_OBJS): %.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(libboard_DEPS): %.d: %.c
	$(CC) -MM $(CPPFLAGS) $< -MF $@

$(libboard_LIB): $(libboard_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(libboard_LIB) $(libboard_OBJS) $(libboard_DEPS)

.PHONY: all clean

include $(libboard_DEPS)
