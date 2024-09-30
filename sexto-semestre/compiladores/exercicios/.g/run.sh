#!/bin/sh
flex ./lex.l
gcc -o lex ./lex.yy.c
./lex
