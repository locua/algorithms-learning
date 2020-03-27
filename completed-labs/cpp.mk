LDLIBS += -lcppunit -lstdc++
CXXFLAGS += -std=c++11

ifeq ($(OS),Windows_NT)
  MYOS := Windows
else
  MYOS := $(shell uname -s)
endif

ifeq ($(MYOS),Darwin)
CPPUNITDIR = /Users/Shared/CppUnit
CPPFLAGS += -I$(CPPUNITDIR)/include -I/usr/local/include
LDFLAGS += -L$(CPPUNITDIR)/lib -L/usr/local/lib
endif

CPPFLAGS += -I../../00/cpp

OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
HPPS = $(wildcard *.hpp)

$(OBJECTS): %.o : %.cpp $(HPPS)
