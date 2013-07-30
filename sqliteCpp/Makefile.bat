@echo off 
if not exist sqlite3.o (
	gcc -c sqlite3.c
) 

g++ main.cpp sqlite3.o -o main.exe

rem in unix environment
rem g++ main.cpp sqlite3.o -o main -L/usr/lib -lpthread -ldl

