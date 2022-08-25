if [ -d "/lib" ]
then
    if[-z "$( ls -A /lib )" ]
    then
	clang src/*.c -Iheaders -llib/*.so -o bin/ 
