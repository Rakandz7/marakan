all: executable_usb

executable_usb: autotests.o consigne.o regulation.o simulateur.o test_usb.o visualisationC.o visualisationT.o releve.o commande.o
	gcc autotests.o consigne.o regulation.o simulateur.o test_usb.o visualisationC.o visualisationT.o releve.o commande.o ftd2xx.lib -o executable_usb

executable: autotests.o consigne.o regulation.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o releve.o commande.o
	gcc autotests.o consigne.o regulation.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o releve.o commande.o -o executable

test_usb.o: test_usb.c define.h
	gcc -Wall -c test_usb.c -o test_usb.o

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

releve.o: releve.c releve.h
	gcc -Wall -c releve.c -o releve.o

commande.o: commande.c commande.h
	gcc -Wall -c commande.c -o commande.o

cleanw:
	del *.o *.exe

