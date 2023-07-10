# Shell script to create projects 'cause a hate Netbeans

echo "Project ID (org.project.example): "
read PROJECT_ID

echo "Project Name (Example): "
read PROJECT_NAME

mvn archetype:generate -DgroupId=$PROJECT_ID \
	-DartifactId=$PROJECT_NAME \
	-DarchetypeArtifactId=maven-archetype-quickstart \
	-DinteractiveMode=false

sed '$d' -i $PROJECT_NAME/pom.xml
cat << EOF >> $PROJECT_NAME/pom.xml
  <properties>
    <maven.compiler.source>18</maven.compiler.source>
    <maven.compiler.target>18</maven.compiler.target>
  </properties>
</project>
EOF

cat << EOF >> $PROJECT_NAME/run.sh
echo "what's the Main class? (default: App)"
read MAIN_CLASS
if [[ \$MAIN_CLASS = "" ]]; then 
	MAIN_CLASS=App
fi
mvn clean package && clear && \\
	java -cp target/classes $PROJECT_ID.\$MAIN_CLASS
EOF
chmod +x $PROJECT_NAME/run.sh
