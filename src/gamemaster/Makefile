libgameMaster_LIB:=libgameMaster.a
libgameMaster_SRCS:=gameMaster.c
libgameMaster_OBJS:=$(patsubst %.c,%.o,$(libgameMaster_SRCS))
libgameMaster_DEPS:=$(patsubst %.c,%.d,$(libgameMaster_SRCS))

all: $(libgameMaster_LIB)

$(libgameMaster_OBJS): %.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(libgameMaster_DEPS): %.d: %.c
	$(CC) -MM $(CPPFLAGS) $< -MF $@

$(libgameMaster_LIB): $(libgameMaster_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(libgameMaster_LIB) $(libgameMaster_OBJS) $(libgameMaster_DEPS)

.PHONY: all clean

include $(libgameMaster_DEPS)
