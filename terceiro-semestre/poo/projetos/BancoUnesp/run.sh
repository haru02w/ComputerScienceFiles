# Script to execute a Maven project in the terminal 
echo "what's the Main class? (default: App)"
read MAIN_CLASS
if [[ $MAIN_CLASS = "" ]]; then 
	MAIN_CLASS=App
fi
mvn clean package && clear && \
	java -cp target/classes god.help.us.$MAIN_CLASS
