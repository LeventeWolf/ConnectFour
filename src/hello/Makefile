hello_PROG:=hello
hello_SRCS:=main.c
hello_OBJS:=$(patsubst %.c,%.o,$(hello_SRCS))
hello_DEPS:=$(patsubst %.c,%.d,$(hello_SRCS))

hello_CPPFLAGS:=-I../libhello $(CPPFLAGS)
hello_CFLAGS:=$(CFLAGS)
hello_LDFLAGS:=-L../libhello $(LDFLAGS)
hello_LDLIBS:=-lhello $(LDLIBS)

all: $(hello_PROG)

$(hello_OBJS): %.o: %.c
	$(CC) -c $(hello_CPPFLAGS) $(hello_CFLAGS) $< -o $@

$(hello_DEPS): %.d: %.c
	$(CC) -MM $(hello_CPPFLAGS) $< -MF $@

$(hello_PROG): $(hello_OBJS)
	$(CC) $(hello_CFLAGS) $(hello_LDFLAGS) $^ $(hello_LDLIBS) -o $@

clean:
	rm -rf $(hello_PROG) $(hello_OBJS) $(hello_DEPS)

.PHONY: all clean

include $(hello_DEPS)
