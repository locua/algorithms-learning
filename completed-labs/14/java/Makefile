include ../../java.mk

TESTCLASSFILES = GraphVertexTest.class GraphEdgeTest.class GraphMSTCostTest.class GraphMSTTest.class # SPCostTest.class SPTest.class
CLASSFILES = Edge.class Vertex.class Graph.class $(TESTCLASSFILES)

CLASSPATHS += ../../00/java

all: $(CLASSFILES)

clean:
	-rm -f $(CLASSFILES) test.xml
test: all
	(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

.PHONY: test all clean
