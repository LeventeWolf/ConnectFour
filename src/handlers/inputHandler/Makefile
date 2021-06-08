libinputHandler_LIB:=libinputHandler.a
libinputHandler_SRCS:=inputHandler.c
libinputHandler_OBJS:=$(patsubst %.c,%.o,$(libinputHandler_SRCS))
libinputHandler_DEPS:=$(patsubst %.c,%.d,$(libinputHandler_SRCS))

all: $(libinputHandler_LIB)

$(libinputHandler_OBJS): %.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

$(libinputHandler_DEPS): %.d: %.c
	$(CC) -MM $(CPPFLAGS) $< -MF $@

$(libinputHandler_LIB): $(libinputHandler_OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -rf $(libinputHandler_LIB) $(libinputHandler_OBJS) $(libinputHandler_DEPS)

.PHONY: all clean

include $(libinputHandler_DEPS)
