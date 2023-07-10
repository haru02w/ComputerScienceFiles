SRC_FILES := $(shell find . -name '*.java')
CLASS_FOLDER := ./classes

all:
	@javac -d $(CLASS_FOLDER) $(SRC_FILES)
run: all
	@java -cp $(CLASS_FOLDER) Main
