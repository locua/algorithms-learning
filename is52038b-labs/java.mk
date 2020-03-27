ifeq ($(OS),Windows_NT)
  ifneq ($(wildcard /c/Program\ Files/Java/jdk1.8*),)
    JDIR = $(wordlist 1,2,$(wildcard /c/Program\ Files/Java/jdk1.8*))
    JAVAC = "$(JDIR)"/bin/javac
    JAVA = "$(JDIR)"/bin/java
  else
    ifneq ($(wildcard /c/Program\ Files/Java/jdk-9*),)
      JDIR = $(wordlist 1,2,$(wildcard /c/Program\ Files/Java/jdk-9*))
      JAVAC = "$(JDIR)"/bin/javac
      JAVA = "$(JDIR)"/bin/java
    else
      ifneq ($(wildcard /c/Program\ Files/Java/jdk-10*),)
        JDIR = $(wordlist 1,2,$(wildcard /c/Program\ Files/Java/jdk-10*))
        JAVAC = "$(JDIR)"/bin/javac
        JAVA = "$(JDIR)"/bin/java
      else
        ifneq ($(wildcard /c/Program\ Files/Java/jdk-11*),)
          JDIR = $(wordlist 1,2,$(wildcard /c/Program\ Files/Java/jdk-11*))
          JAVAC = "$(JDIR)"/bin/javac
          JAVA = "$(JDIR)"/bin/java
        else
          ## remove the # symbols from the two lines below, and write in
          ## the path to javac and java on your system, such as
          # JAVAC = /c/Program\ Files/Java/jdk-18.3/bin/javac
          # JAVA = /c/Program\ Files/Java/jdk-18.3/bin/java
        endif
      endif
    endif
  endif
else
  JAVAC = javac
  JAVA = java
endif

CP = -cp
CLASSPATHS = . ../../00/java ../../00/java/junit-4.12.jar ../../00/java/hamcrest-core-1.3.jar

empty :=
space := $(empty) $(empty)
CLASSPATH = $(subst $(space),:,$(CLASSPATHS))

%.class: %.java
	$(JAVAC) $(CP) $(CLASSPATH) $^
