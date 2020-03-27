include ../../cpp.mk

SetupTest: SetupTest.o ../../00/cpp/RunTests.o

test: SetupTest
	@echo "Running test of CppUnit"
	@./SetupTest
	@echo "Tests passed: C++ setup apparently OK"

.PHONY: test
