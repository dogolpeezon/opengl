PATH=$PATH:/home/media/dogol/Maxtor/myshit/myprog/glsample
printf "Enter the file.c name to compile.. then file name of exe. \n"
read bfile exfile
echo
printf "file to be compile \n"
printf  $bfile " " $exfile
echo
printf '%s\n' \ bfile $bfile \ exfile $exfile > list.txt
g++ $bfile -lglut -lGL -lGLEW -lGLU -o $exfile
./$exfile
