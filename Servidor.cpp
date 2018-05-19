#include "Respuesta.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include "mensaje.h"
#include <iostream>

using namespace std;
int main(int argc, char const *argv[]){
	if (argc < 2){
		printf("Error %s -puerto\n", argv[0]);
		return -1;
	}
	Respuesta servidor(atoi(argv[1]));
	struct mensaje * msg = servidor.getRequest();
	char * arg = NULL;
	char * acomodado = NULL;
	int len = strlen(msg[0].arguments);
	arg = (char *)malloc(sizeof(char)* len);
	memcpy(arg,msg[0].arguments, len);
	printf("ARG:%s\n", arg);
	string info = arg;
	char * array[TAM_MAX_DATA];
	char * palabra = strtok(arg, " ");
	int contador = 0;
	while( palabra!= NULL){
		array[contador] = palabra;
		palabra = strtok(NULL, " ");
		contador++;
	}
	string res = ""; 
	for (int i = 0; i < contador; ++i){
		printf("%s\n", array[i]);
		res += array[contador-i-1];
		res += " ";
	}
	printf("%s\n", res.c_str());
	servidor.sendReply((char *)res.c_str(), msg[0].IP, msg[0].puerto);
	return 0;
}