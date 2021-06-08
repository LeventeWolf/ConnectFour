libmodeHandler_LIB:=libmodeHandler.a
libmodeHandler_SRCS:=modeHandler.c
libmodeHandler_OBJS:=$(patsubst %.c,%.o,$(libmodeHandler_SRCS))
libmodeHandler_DEPS:=$(patsubst %.c,%.d,$(libmodeHandler_SRCS))

all: $(libmodeHandler_LIB)

$(libmodeHandler_OBJS): %.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(libmodeHandler_DEPS): %.d: %.c
	$(CC) -MM $(CPPFLAGS) $< -MF $@

$(libmodeHandler_LIB): $(libmodeHandler_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(libmodeHandler_LIB) $(libmodeHandler_OBJS) $(libmodeHandler_DEPS)

.PHONY: all clean

include $(libmodeHandler_DEPS)
