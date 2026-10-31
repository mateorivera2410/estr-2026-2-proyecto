// Autores:  Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703

#ifndef COLA_H
#define COLA_H
#define MAX_NOMBRE  50

struct Paciente{

    char nombre[MAX_NOMBRE + 1]; // es mas uno por el '\0'
    int urgencia; //de 1 a 5, donde 5 es el mas urgente
    int llegada; //el numero de la orden en que llego, de ahi se calcula la espera

};
struct Cola
{
    Paciente *datos; //un arreglo donde estan los pacientes, se reserva con malloc
    int capacidad; // cuantos caben (seria el N de la entrada)
    int frente; // posicion del arreglo  proximo a atender
    int cantidad; // cuantos esperan ahora

};
// c= cola sobre la cual trabaja la funcion, p = el paciente

// Reserva la cola y su arreglo para "capacidad" pacientes y la deja vacia. Devuelve NULL si malloc falla
Cola * crearCola(int capacidad);


// Libera el arreglo de pacientes y luego la cola
void destruirCola(Cola *c);
// Mete a p al final de la cola. Devuelve 1 si entro, 0 si estaba llena
int registrar(Cola* c, Paciente p);
// Saca al proximo paciente y lo copia en *p. Devuelve 1 si habia alguien, 0 si estaba vacia
int atender(Cola* c, Paciente* p);
// Devuelve cuantos pacientes esperan en la cola
int cantidad(const Cola* c);
// Devuelve 1 si no hay nadie esperando, 0 si hay alguien
int estaVacia(const Cola* c);
// Devuelve 1 si la cola llego a su capacidad, 0 si todavia cabe alguien
int estaLlena(const Cola * c);





#endif