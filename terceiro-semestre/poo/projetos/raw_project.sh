# Shell script to create projects without maven or gradle
echo "enter the project name: "
read PROJECT_FOLDER 

echo "enter Main class name: (default Main) "
read MAIN_CLASS 

if [[ $MAIN_CLASS = "" ]]; then 
	MAIN_CLASS=Main
fi

mkdir -p $PROJECT_FOLDER/.git

cat << EOF >> $PROJECT_FOLDER/GNUmakefile
SRC_FILES := \$(shell find . -name '*.java')
CLASS_FOLDER := ./classes

all:
	@javac -d \$(CLASS_FOLDER) \$(SRC_FILES)
run: all
	@java -cp \$(CLASS_FOLDER) $MAIN_CLASS
EOF

cat << EOF >> $PROJECT_FOLDER/$MAIN_CLASS.java
public class $MAIN_CLASS {
	public static void main(String[] args) {
		System.out.println("Hello World");
	}
}
EOF
cd $PROJECT_FOLDER
make run --no-print-directory
