SUBDIRS:=main board gamemaster handlers/inputHandler handlers/modeHandler

all clean:
	@for subdir in $(SUBDIRS); do $(MAKE) -C $$subdir $@; done

.PHONY: all clean
