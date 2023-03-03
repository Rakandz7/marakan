executable: autotests.o consigne.o regulation.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o
	gcc autotests.o consigne.o regulation.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o -o executable

executable_test: autotests.o consigne.o regulation.o simulateur.o main.o visualisationC.o visualisationT.o
	gcc autotests.o consigne.o regulation.o simulateur.o main.o visualisationC.o visualisationT.o -o executable_test

main.o: main.c define.h
	gcc -Wall -c main.c -o main.o

autotests.o: autotests.c autotests.h
	gcc -Wall -c autotests.c -o autotests.o

consigne.o: consigne.c consigne.h
	gcc -Wall -c consigne.c -o consigne.o

regulation.o: regulation.c regulation.h
	gcc -Wall -c regulation.c -o regulation.o

simulateur.o: simulateur.c simulateur.h
	gcc -Wall -c simulateur.c -o simulateur.o

test_simulateur.o: test_simulateur.c define.h
	gcc -Wall -c test_simulateur.c -o test_simulateur.o

visualisationC.o: visualisationC.c visualisationC.h
	gcc -Wall -c visualisationC.c -o visualisationC.o

visualisationT.o: visualisationT.c visualisationT.h
	gcc -Wall -c visualisationT.c -o visualisationT.o

cleanw:
	del *.o *.exe

cleantest:
	rm -f *.o executable_test

cleanexe:
	rm -f *.o executable