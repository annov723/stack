
#first option
#zad9.exe: zad9.o Student.o ulist.o
#	gcc -o zad9.exe zad9.o Student.o ulist.o
#ulist.o: ulist.c ulist.h
#	gcc -c ulist.c -Wall
#Student.o: Student.c Student.h ulist.h
#	gcc -c Student.c -Wall
#zad9.o: zad9.c ulist.h Student.h
#	gcc -c zad9.c -Wall

#second option
OBJECTS = zad9.out ulist.out Student.out

zad9.exe: $( OBJECTS )
	gcc -o $@ $( OBJECTS ) -lm
ulist.out: ulist.h
Student.out: Student.h ulist.h
zad9.out: Student.h ulist.h

.PHONY: clean
clean:
	rm $( OBJECTS )
