include ../../java.mk

TESTCLASSFILES = 
CLASSFILES = ../../04/java/SLList.class ListVisualiser.class ListVisualiserDriver.class $(TESTCLASSFILES)

CLASSPATHS += ../../04/java

all: $(CLASSFILES)

clean:
	-rm -f $(TESTCLASSFILES) test.xml

%.class: %.java
	$(JAVAC) $(CP) $(CLASSPATH) $^

test: all
	$(JAVA) -Xss10m $(CP) $(CLASSPATH) ListVisualiserDriver

.PHONY: test all clean
