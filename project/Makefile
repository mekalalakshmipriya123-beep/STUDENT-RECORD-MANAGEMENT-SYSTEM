exe: main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o
	cc main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c -o exe

main.o: main.c student.h
	cc -c main.c

stud_add.o: stud_add.c student.h
	cc -c stud_add.c

stud_del.o: stud_del.c student.h
	cc -c stud_del.c

stud_show.o: stud_show.c student.h
	cc -c stud_show.c

stud_mod.o: stud_mod.c student.h
	cc -c stud_mod.c

stud_save.o: stud_save.c student.h
	cc -c stud_save.c

stud_sort.o: stud_sort.c student.h
	cc -c stud_sort.c

clean:
	rm -f *.o exe student.dat
