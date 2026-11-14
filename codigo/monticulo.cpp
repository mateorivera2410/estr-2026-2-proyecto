// Autores: Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703
#include "sala.h"
#include <cstdlib>

// Montículo binario de máximos guardado en el arreglo datos, con índices desde 0.
// La casilla i tiene su padre en (i - 1) / 2 y sus hijos en 2*i + 1 y 2*i + 2.
// El que se atiende primero siempre está en la casilla 0, por eso frente vale siempre 0.

// Devuelve 1 si el paciente a se debe atender antes que el paciente b y 0 si no:
// va antes el de mayor urgencia y, si empatan, el que llegó antes (menor llegada).
// La regla está solo aquí para que subir y bajar siempre comparen igual
static int vaAntes(const Paciente *a, const Paciente *b)
{
    int antes = 0;
    if (a->urgencia > b->urgencia)
    {
        antes = 1;
    }
    else if (a->urgencia == b->urgencia && a->llegada < b->llegada)
    {
        antes = 1;
    }
    return antes;
}

// Intercambia los pacientes de las casillas i y j del arreglo
static void intercambiar(Sala *c, int i, int j)
{
    Paciente temporal = c->datos[i];
    c->datos[i] = c->datos[j];
    c->datos[j] = temporal;
}

// Sube al paciente de la casilla i mientras vaya antes que su padre.
// Hace a lo sumo un intercambio por nivel del árbol
static void subir(Sala *c, int i)
{
    // sigue vale false cuando el paciente ya no tiene que subir más
    bool sigue = true;
    while (sigue && i > 0)
    {
        int padre = (i - 1) / 2;
        if (vaAntes(&c->datos[i], &c->datos[padre]))
        {
            intercambiar(c, i, padre);
            i = padre;
        }
        else
        {
            sigue = false;
        }
    }
}

// Baja al paciente de la casilla i mientras algún hijo vaya antes que él,
// intercambiándolo con el hijo que vaya antes de los dos.
// Hace a lo sumo un intercambio por nivel del árbol
static void bajar(Sala *c, int i)
{
    // sigue vale false cuando el paciente ya está en su lugar
    bool sigue = true;
    while (sigue)
    {
        int izquierdo = 2 * i + 1;
        int derecho = 2 * i + 2;
        // mejor es la casilla del que va primero entre i y sus hijos
        int mejor = i;
        // antes de comparar se revisa que el hijo exista (que su casilla sea menor que cantidad)
        if (izquierdo < c->cantidad && vaAntes(&c->datos[izquierdo], &c->datos[mejor]))
        {
            mejor = izquierdo;
        }
        if (derecho < c->cantidad && vaAntes(&c->datos[derecho], &c->datos[mejor]))
        {
            mejor = derecho;
        }
        if (mejor != i)
        {
            intercambiar(c, i, mejor);
            i = mejor;
        }
        else
        {
            sigue = false;
        }
    }
}

// Reserva la sala y su arreglo de pacientes, y la deja vacia. Devuelve NULL si no hay memoria disponible
Sala *crearSala(int capacidad)
{
    // se asegura que al menos tenga 1, ya que malloc en 0 puede devolver NULL
    if (capacidad < 1)
    {
        capacidad = 1;
    }
    // se reserva la estructura de la sala
    Sala *c = (Sala *)malloc(sizeof(Sala));
    if (c != NULL)
    {
        // se reserva el arreglo donde se guarda el árbol de pacientes
        c->datos = (Paciente *)malloc(sizeof(Paciente) * capacidad);
        // si el arreglo no se pudo reservar se libera la sala para no dejar memoria perdida
        if (c->datos == NULL)
        {
            free(c);
            c = NULL;
        }
        // si todo salio bien: el próximo a atender está en la raíz (frente = 0) y no hay nadie esperando
        else
        {
            c->capacidad = capacidad;
            c->frente = 0;
            c->cantidad = 0;
        }
    }
    // devuelve la sala creada, o NULL si algo fallo
    return c;
}

// libera la memoria de la sala: primero el arreglo de pacientes y despues la sala
void destruirSala(Sala *c)
{
    if (c != NULL)
    {
        // se liberan primero los datos porque una vez liberes c, no puedes ver los c->datos
        free(c->datos);
        free(c);
    }
}

// devuelve 1 si no hay nadie esperando y 0 si hay alguien
int estaVacia(const Sala *c)
{
    return c->cantidad == 0;
}

// devuelve 1 si la sala llego a su capacidad y 0 si todavia cabe alguien
int estaLlena(const Sala *c)
{
    return c->cantidad == c->capacidad;
}

// devuelve cuantos pacientes estan esperando
int cantidad(const Sala *c)
{
    return c->cantidad;
}

// Mete un paciente en el montículo. Devuelve 1 si entro y 0 si la sala estaba llena (no pudo entrar)
int registrar(Sala *c, Paciente p)
{
    // empieza en 0 (todavia no ha entrado) y solo cambia a 1 si hay espacio; asi solo hay 1 return
    int ok = 0;
    if (!estaLlena(c))
    {
        // el paciente entra en la primera casilla libre, que es la última del árbol
        int i = c->cantidad;
        c->datos[i] = p;
        c->cantidad += 1;
        // y sube hasta que su padre vaya antes o igual que él
        subir(c, i);
        ok = 1;
    }
    return ok;
}

// Saca al paciente de la raíz (el que va primero) y lo copia en *p. Devuelve 1 si habia alguien, 0 si estaba vacia
int atender(Sala *c, Paciente *p)
{
    // ok empieza en 0 (no se atendio a nadie) y solo cambia a 1 si habia alguien; asi solo hay un return
    int ok = 0;
    if (!estaVacia(c))
    {
        // se entrega por p el paciente de la raíz
        *p = c->datos[0];
        // el último paciente del árbol pasa a la raíz y hay uno menos esperando
        c->datos[0] = c->datos[c->cantidad - 1];
        c->cantidad -= 1;
        // y baja hasta que ningún hijo vaya antes que él
        bajar(c, 0);
        ok = 1;
    }
    return ok;
}