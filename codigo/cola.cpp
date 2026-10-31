// Autores: Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703
#include "cola.h"
#include <cstdlib>

// Reserva la cola y su arreglo de pacientes, y la deja vacia. Devuelve NULL si no hay memoria disponible
Cola *crearCola(int capacidad)
{
    // se asegura que al menos tenga 1, ya que malloc en 0 puede devolver NULL
    if (capacidad < 1)
    {
        capacidad = 1;
    }
    //se reserva la estructura de la cola
    Cola *c = (Cola *)malloc(sizeof(Cola));
    if (c != NULL)
    {
        // se reserva el arreglo donde se guardan los pacientes
        c->datos = (Paciente *)malloc(sizeof(Paciente) * capacidad);
        // si el arreglo no se pudo reservar se libera la cola para no dejar memoria perdida
        if (c->datos == NULL)
        {
            free(c);
            c = NULL;
        }
        // si se pudo reservar, es decir todo salio bien, el frente va 0 (esta en la posicion 0), y no hay nadie esperando (se inicia)
        else
        {
            c->capacidad = capacidad;
            c->frente = 0;
            c->cantidad = 0;
        }
    }
    // devuelve la cola creada, o NULL si algo fallo
    return c;
}
// libera la memoria de la cola: primero el arreglo de pacientes y despues la cola 
void destruirCola(Cola *c)
{
    if (c != NULL){
        // se liberan primero los datos porque una vez liberes c, no puedes ver los c->datos
        free(c->datos);
        free(c);
    }
}
// devuelve 1 si no hay nadie esperando y 0 si hay alguien
int estaVacia(const Cola *c)
{
    return c->cantidad == 0;
}
// devuelve 1 si la cola llego a su capacidad y 0 si todavia cabe alguien
int estaLlena(const Cola *c)
{
    return c->cantidad == c->capacidad;
}

// devuelve cuantos pacientes estan esperando
int cantidad(const Cola *c)
{
    return   c -> cantidad;
}
// mete un paciente al final de la cola. Devuelve 1 si entro y 0 si la cola estaba llena(no pudo entrar)
int registrar(Cola *c, Paciente p)
{
    // empieza en 0 (todavia no ha entrado) y solo cambia a 1 si hay espacio; asi solo hay 1 return
    int ok = 0;
    // se verifica que aun quepa alguien
    if (!estaLlena(c)){
        // el final de la cola esta en frente + cantidad, el % hace que la posicion de la vuelta
        //al inicio del arreglo cuando se pasa del final(eso es lo que la hace circular)
        int pos = (c->frente + c-> cantidad)% c-> capacidad;
        //se guarda el paciente en esa casilla y hay uno mas esperando, porque registra uno nuevo
        c->datos[pos] = p;
        c -> cantidad +=1;
        ok = 1;

    }
    return ok;
}
// Saca al paciente que esta en el frente y lo copia en *p. Devuelve 1 si habia alguien, 0 si la cola estaba vacia
int atender(Cola *c, Paciente *p)
{
    // ok empieza en 0 (no se atendio a nadie) y solo cambia a 1 si habia alguien; asi solo hay un return
    int ok =0;
    // solo atiende si hay alguien en la espera(en la cola)
    if (!estaVacia(c)){
        // Se copia en *p el paciente que sale, para que cuando se llame la funcion sepa su nombre y en que orden llego
        *p = c -> datos[c ->frente];
        // El frente avanza una casilla y el % lo hace dar la vuelta al inicio del arreglo.
        // Nadie se mueve dentro del arreglo, por eso atender cuesta O(1)
        c ->frente = (c->frente + 1)% c->capacidad;
        // Hay uno menos esperando y se marca que si se ha atendido a alguien
        c ->cantidad -=1;
        ok = 1;
    }
    return ok;

}