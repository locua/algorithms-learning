include ../../java.mk

TESTCLASSFILES = HelloTest.class
CLASSFILES = Hello.class $(TESTCLASSFILES)

all: $(CLASSFILES)

test: all
	@(((($(JAVA) $(CP) $(CLASSPATH) org.junit.runner.JUnitCore $(subst .class,,$(TESTCLASSFILES)); echo $$? >&3) | egrep -v \(org.junit\|sun.reflect\|java.lang.reflect\) >&4) 3>&1) | (read xs; exit $$xs)) 4>&1

clean:
	-rm *.class

.PHONY: test clean all
