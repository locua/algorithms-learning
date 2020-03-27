include ../../cpp.mk

GraphTest: Edge.o Vertex.o Graph.o GraphVertexTest.o GraphEdgeTest.o GraphMSTCostTest.o GraphMSTTest.o ../../00/cpp/RunTests.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) $^ $(LOADLIBES) $(LDLIBS) -o $@


test: GraphTest
	./GraphTest

.PHONY: test
