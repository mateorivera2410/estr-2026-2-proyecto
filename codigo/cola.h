// Autores:  Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703

#ifndef COLA_H
#define COLA_H
#define MAX_NOMBRE  50

struct Paciente{

    char nombre[MAX_NOMBRE + 1];
    int urgencia;
    int llegada;

};
struct Cola
{
    Paciente *datos;
    int capacidad;
    int frente;
    int cantidad;

};

Cola * crearCola(int capacidad);

void destruirCola(Cola *c);

int registrar(Cola* c, Paciente p);

int atender(Cola* c, Paciente* p);

int cantidad(const Cola* c);

int estaVacia(const Cola* c);

int estaLlena(const Cola * c);





#endif