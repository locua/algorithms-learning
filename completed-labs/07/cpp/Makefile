include ../../cpp.mk

LDLIBS += -lm

ListVisualiserDriver: CPPFLAGS += -I ../../04/cpp
ListVisualiserDriver: ListVisualiser.o ../../04/cpp/SLList.o ListVisualiserDriver.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: ListVisualiserDriver
	./ListVisualiserDriver

.PHONY: test
