SOURCES = PaqueteDatagrama.cpp SocketDatagrama.cpp 
OBJECTS = PaqueteDatagrama.o SocketDatagrama.o 

all: client server
client: $(OBJECTS) Solicitud.o Respuesta.o
	g++ Cliente.cpp $(OBJECTS) Solicitud.o -o cliente
	g++ Servidor.cpp $(OBJECTS) Respuesta.o -o server
$(OBJECTS):
	g++ -c $(SOURCES)
Solicitud.o:
	g++ -c Solicitud.cpp
Respuesta.o:
	g++ -c Respuesta.cpp
clean:
	RM *.o 