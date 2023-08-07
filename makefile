zad9.exe: zad9.o ulist.o Student.o
	gcc -o zad9.exe zad9.o ulist.o Student.o
ulist.o: ulist.c ulist.h
	gcc -c ulist.c -Wall
Student.o: Student.c Student.h ulist.h
	gcc -c Student.c -Wall
zad9.o: zad9.c ulist.h Student.h
	gcc -c zad9.c -Wall
	
