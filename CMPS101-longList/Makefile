# Makefile for intstack module - by DPH, modified Spring 2014
# It compiles the module and creates the intstackdr executable

store : store.o longList.o
	gcc -ansi -Wall -Wextra -pedantic -o store store.o longList.o

longListDr : longListDr.o longList.o
	gcc -ansi -Wall -Wextra -pedantic -o longListDr longListDr.o longList.o

longList.o : longList.h longList.c
	gcc -c -ansi -Wall -Wextra -pedantic longList.c

store.o : longList.h store.c
	gcc -c -ansi -Wall -Wextra -pedantic store.c

longListDr.o : longList.h longListDr.c
	gcc -c -ansi -Wall -Wextra -pedantic longListDr.c

clean :
	rm longListDr longListDr.o longList.o

# an old version of the makefile used the additional gcc option
# -I/usr/lang/SC1.0/ansi_include but it is not needed on my system
# we should double check that that option is not needed on the cats system
