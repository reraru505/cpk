if [ -d "bin" ]
   
then
    gcc src/*.c -Iheaders -o bin/cpk
    
else
    
    mkdir bin && gcc src/*.c -Iheaders -o bin/cpk
fi
