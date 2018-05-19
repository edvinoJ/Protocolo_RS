#include "Respuesta.h"
Respuesta::Respuesta(int pl){
	socketlocal = new SocketDatagrama(pl);
}
struct mensaje * Respuesta::getRequest(void){
	PaqueteDatagrama pack(sizeof(struct mensaje));
	socketlocal[0].recibe(&pack);
	struct mensaje * msg = (struct mensaje *)malloc(sizeof(struct mensaje));
	msg = (struct mensaje *) pack.obtieneDatos();
	//Cambia los valores de IP y puerto al del cliente
	char * dir = pack.obtieneDireccion();
	memcpy(msg[0].IP, dir, strlen(dir));
	msg[0].puerto = pack.obtienePuerto();
	return msg;
}
void Respuesta::sendReply(char *respuesta, char *ipCliente, int puertoCliente){
	//Llenado de datos
	struct mensaje * msg = (struct mensaje *) malloc(sizeof(struct mensaje));
	msg[0].messageType = 1;
	msg[0].requestId = 2;
	memcpy(msg[0].IP, ipCliente, strlen(ipCliente));
	msg[0].puerto = puertoCliente;
	msg[0].operationId = 5;
	memcpy(msg[0].arguments, respuesta, strlen(respuesta));
	//Enviar los datos
	PaqueteDatagrama pack((char *)msg, sizeof(struct mensaje), ipCliente, puertoCliente);
	socketlocal[0].envia(&pack);
	return;
}