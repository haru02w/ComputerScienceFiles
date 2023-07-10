echo "what's the Main class? (default: App)"
read MAIN_CLASS
if [[ $MAIN_CLASS = "" ]]; then 
	MAIN_CLASS=App
fi
mvn clean package && clear && \
	java -cp target/classes com.lucas.ribas.$MAIN_CLASS
