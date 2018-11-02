buscaminas.out: funciones_juego.o funciones_juego_1.o  pro.o
	gcc -Wall -g -o buscaminas.out funciones_juego.o funciones_juego_1.o pro.o `pkg-config --cflags --clibs gtk+-2.0`

funciones_juego.o: funciones_juego.c
	gcc -g -c funciones_juego.c `pkg-config --cflags gtk+-2.0`

funciones_juego_1.o: funciones_juego_1.c
	gcc -g -c funciones_juego_1.c `pkg-config --cflags gtk+-2.0`

pro.o: pro.c
	gcc -g -c pro.c `pkg-config --cflags gtk+-2.0`

Clean: 
	rm*.o