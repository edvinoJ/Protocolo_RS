#include "Solicitud.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc < 3){
		printf("Falta de argumentos %s dirIP puerto\n", argv[0]);
		return -1;
	}
	Solicitud cliente1;
	int ordenaCadena = 0;
	char * cadenota = (char *)"HOla mundo en C++\0";
	printf("Iniciar\n");
	printf("La respuesta del servidor es <%s>\n",cliente1.doOperation (argv[1], atoi(argv[2]), ordenaCadena, cadenota));
	return 0;
}