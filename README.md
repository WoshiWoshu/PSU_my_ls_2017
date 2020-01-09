# PSU_my_ls_2017
First year mini project in which the goal is to re-code the ls UNIX system call/command. It can handle most of the ls options in either order as "-lRdrt". It can also pass a list of files/folders as parameter.

USAGE :

1) Make 2) ./my_ls [OPTIONS] [FILES] [FOLDERS]

exemple :

./my_ls -l -R

> total 4
>
>-rwxr-xr-x 1 stallman operator 606 Oct 29 10:45 my_ls
>
>-rw-r--r-- 1 stallman prof 860 Oct 19 11:11 bdsh
>
>-rw-r--r-- 2 stallman operator 830 Oct 13 14:11 bdsh~
>
>-rwxr-xr-x 1 stallman operator 497 Oct 13 14:00 stream.a*
