#! /bin/bash

printf '\ncopy with 8 bytes'
gcc -o copy8 -DBUF_SIZE=8 copy.c
time ./copy8 pas.txt dest.txt


printf '\ncopy with 128 bytes'
gcc -o copy128 -DBUF_SIZE=128 copy.c
time ./copy128 pas.txt dest.txt


printf '\ncopy with 1024 bytes'
gcc -o copy1024 -DBUF_SIZE=1024 copy.c
time ./copy1024 pas.txt dest.txt


printf '\ncopy with 8 bytes with syncronization'
gcc -o copy8s -DBUF_SIZE=8 -DSYNC copy.c
time ./copy8s pas.txt dest.txt

printf '\ncopy with 128 bytes with syncronization'
gcc -o copy128s -DBUF_SIZE=128 -DSYNC copy.c
time ./copy128s pas.txt dest.txt

printf '\ncopy with 1024 bytes with syncronization'
gcc -o copy1024s -DBUF_SIZE=1024 -DSYNC copy.c
time ./copy1024s pas.txt dest.txt
