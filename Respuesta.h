#ifndef _RESPUESTA_H
#define _RESPUESTA_H
#include "SocketDatagrama.h"
class Respuesta{
public:
	Respuesta(int pl);
	struct mensaje *getRequest(void);
	void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
private:
	SocketDatagrama *socketlocal;
};
#endif