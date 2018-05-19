#include "Solicitud.h"
#include "PaqueteDatagrama.h"
#include "mensaje.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(7000);
}
char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments){
	//Puntero para el mensaje
	struct mensaje * msg = (struct mensaje *) malloc(sizeof(struct mensaje));
	//Llenado de la info
	msg[0].messageType = 0;
	msg[0].requestId = 1;
	memcpy(msg[0].IP, IP, strlen(IP));
	msg[0].puerto = puerto;
	msg[0].operationId = 1;
	memcpy(msg[0].arguments, arguments, TAM_MAX_DATA);
	printf("%s\n", msg[0].arguments);
	//Creacion del paquete
	PaqueteDatagrama pack((char *)msg, sizeof(struct mensaje), IP, puerto);
	socketlocal[0].envia(&pack);

	printf("Esperando respuesta\n");
	PaqueteDatagrama pack2(sizeof(struct mensaje));
	socketlocal[0].recibe(&pack2);
	msg = (struct mensaje *) pack2.obtieneDatos();
	return msg[0].arguments;
} 