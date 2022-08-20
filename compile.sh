if [ -d "/bin" ]
then
    clang src/*.c -Iheaders -o bin/cpk
else
    mkdir bin & clang src/*.c -Iheaders -o bin/cpk
fi
