include ../../cpp.mk

NaiveStringMatchTest: NaiveStringMatchTest.o StringMatchTest.o StringMatch.o NaiveStringMatch.o ../../00/cpp/OpCounter.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

RKStringMatchTest: RKStringMatchTest.o StringMatchTest.o StringMatch.o RKStringMatch.o  ../../00/cpp/OpCounter.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

KMPStringMatchTest: KMPStringMatchTest.o StringMatchTest.o StringMatch.o KMPStringMatch.o ../../00/cpp/OpCounter.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

test: NaiveStringMatchTest
	./NaiveStringMatchTest

StringMatchCount: StringMatchCount.o StringMatch.o NaiveStringMatch.o RKStringMatch.o KMPStringMatch.o ../../00/cpp/OpCounter.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@

.PHONY: test
