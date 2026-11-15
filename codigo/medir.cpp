// Autores: Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703
// Mide la sala de espera (la cola o el montículo, según con cuál se compile) contra priority_queue.
// Las tres reciben exactamente la misma secuencia de órdenes.
// Escribe una línea CSV por tamaño: los tiempos en milisegundos y las esperas promedio.
#include <cstdio>
#include <cstring>
#include <ctime>
#include <queue>
#include "sala.h"

#define REPETICIONES 3       // cuántas veces se mide cada tamaño para sacar el promedio
#define CANT_TAMANOS 5       // cuántos tamaños hay en el arreglo tamanos
#define PRIMO 100003         // primo mayor que el tamaño más grande, para la fórmula de la urgencia
#define MULTIPLICADOR 7919   // número fijo de la fórmula de la urgencia

// Suma de esperas y cantidad de atendidos por urgencia (casillas 1 a 5; la 0 no se usa)
struct Esperas
{
    long long suma[6];
    long long atendidos[6];
};

// priority_queue saca al MAYOR según operator<, así que a < b es verdadero cuando a va DESPUÉS que b:
// a tiene menor urgencia, o tiene la misma urgencia pero llegó después (mayor llegada).
// Es la misma regla del montículo, para que la comparación sea justa
bool operator<(const Paciente &a, const Paciente &b)
{
    return a.urgencia < b.urgencia || (a.urgencia == b.urgencia && a.llegada > b.llegada);
}

// Urgencia del paciente que llega en la orden i, entre 1 y 5.
// Es una fórmula fija: para el mismo i siempre da lo mismo, así las tres estructuras reciben los mismos pacientes
int urgenciaDe(int i)
{
    // long long porque i * MULTIPLICADOR no cabe en un int cuando i es grande
    int residuo = (int)(((long long)i * MULTIPLICADOR) % PRIMO);
    return 1 + residuo % 5;
}

// De cada 5 órdenes, 3 son LLEGA (residuo 0, 1 o 2) y 2 son ATIENDE (residuo 3 o 4).
// Llegan más de los que se atienden, así la sala se va llenando y el orden de atención sí importa
int esLlegada(int i)
{
    return i % 5 < 3;
}

// Arma el paciente que llega en la orden i. El nombre no se usa para medir, por eso es fijo
Paciente crearPaciente(int i)
{
    Paciente p;
    strcpy(p.nombre, "p");
    p.urgencia = urgenciaDe(i);
    p.llegada = i;
    return p;
}

// Pone en cero las sumas y los contadores de espera
void limpiarEsperas(Esperas *e)
{
    int u;
    for (u = 0; u <= 5; u++)
    {
        e->suma[u] = 0;
        e->atendidos[u] = 0;
    }
}

// Anota lo que esperó el paciente p, que se atiende en la orden i
void anotarEspera(Esperas *e, Paciente p, int i)
{
    e->suma[p.urgencia] += i - p.llegada;
    e->atendidos[p.urgencia] += 1;
}

// Promedio con decimales; si no se atendió a nadie da 0.0, para no dividir entre cero
double promedio(long long suma, long long cuantos)
{
    double resultado = 0.0;
    if (cuantos > 0)
    {
        resultado = (double)suma / cuantos;
    }
    return resultado;
}

// Corre las n órdenes con la sala (cola o montículo).
// Solo usa las funciones de sala.h, por eso sirve igual con la cola y con el montículo.
// Devuelve los milisegundos que tardó, o -1 si no hubo memoria
double medirSala(int n, Esperas *e)
{
    double milisegundos = -1.0;
    Paciente paciente;
    int i;
    // a lo sumo llegan n pacientes, así que con capacidad n nunca se llena
    Sala *sala = crearSala(n);
    if (sala != NULL)
    {
        limpiarEsperas(e);
        clock_t inicio = clock();
        for (i = 1; i <= n; i++)
        {
            if (esLlegada(i))
            {
                registrar(sala, crearPaciente(i));
            }
            else if (atender(sala, &paciente) == 1)
            {
                anotarEspera(e, paciente, i);
            }
        }
        clock_t fin = clock();
        milisegundos = (fin - inicio) * 1000.0 / CLOCKS_PER_SEC;
        destruirSala(sala);
    }
    return milisegundos;
}

// Las mismas n órdenes con priority_queue de la biblioteca, usada tal cual.
// También anota las esperas, para que haga el mismo trabajo que la sala.
// Devuelve los milisegundos que tardó
double medirReferencia(int n, Esperas *e)
{
    std::priority_queue<Paciente> sala;
    int i;
    limpiarEsperas(e);
    clock_t inicio = clock();
    for (i = 1; i <= n; i++)
    {
        if (esLlegada(i))
        {
            sala.push(crearPaciente(i));
        }
        else if (!sala.empty())
        {
            anotarEspera(e, sala.top(), i);
            sala.pop();
        }
    }
    clock_t fin = clock();
    return (fin - inicio) * 1000.0 / CLOCKS_PER_SEC;
}

int main()
{
    int tamanos[CANT_TAMANOS] = {1000, 5000, 10000, 50000, 100000};
    Esperas esperasSala;
    Esperas esperasReferencia;
    int todoBien = 1;   // pasa a 0 si una sala no se pudo crear, y así se dejan de medir los demás
    int t;
    int r;

    printf("n,tiempo_sala_ms,tiempo_pq_ms,espera_u5,espera_u1\n");
    for (t = 0; t < CANT_TAMANOS && todoBien; t++)
    {
        double totalSala = 0.0;
        double totalReferencia = 0.0;
        for (r = 0; r < REPETICIONES && todoBien; r++)
        {
            double tiempoSala = medirSala(tamanos[t], &esperasSala);
            if (tiempoSala < 0)
            {
                todoBien = 0;
            }
            else
            {
                totalSala += tiempoSala;
                totalReferencia += medirReferencia(tamanos[t], &esperasReferencia);
            }
        }
        if (todoBien)
        {
            // los tiempos son el promedio de las repeticiones; las esperas salen iguales en todas
            printf("%d,%.3f,%.3f,%.1f,%.1f\n", tamanos[t],
                   totalSala / REPETICIONES, totalReferencia / REPETICIONES,
                   promedio(esperasSala.suma[5], esperasSala.atendidos[5]),
                   promedio(esperasSala.suma[1], esperasSala.atendidos[1]));
        }
        else
        {
            printf("no hubo memoria para %d ordenes\n", tamanos[t]);
        }
    }
    return 0;
}