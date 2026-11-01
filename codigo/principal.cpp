// Autores: Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703
// Escenario D para los turnos de una clinica.
// Lee las ordenes de la entrada y atiende a los pacientes por orden de llegada (cola circular).
#include <cstdio>
#include <cstring>
#include "cola.h"

int main()
{
    int totalOrdenes = 0; //cuantas ordenes vienen
    int reloj = 0;//numero de la orden que se esta leyendo, sube 1 con cada orden
    char orden[20];//la palabra de la orden: LLEGA, ATIENDE, ESPERAN o PROMEDIO
    Paciente paciente; //el paciente que llega o el que se atiende
    Cola *salaEspera = NULL;

    if (scanf("%d", &totalOrdenes) == 1)
    {
        //a lo sumo llegan totalOrdenes pacientes, asi que con esa capacidad nunca se llena
        salaEspera = crearCola(totalOrdenes);
        if (salaEspera != NULL)
        {
            //se lee hasta completar las ordenes o hasta que se acabe la entrada
            while (reloj < totalOrdenes && scanf("%19s", orden) == 1)
            {
                reloj++;
                if (strcmp(orden, "LLEGA") == 0)
                {
                    //se guarda en que orden llego para despues saber cuanto espero
                    if (scanf("%50s %d", paciente.nombre, &paciente.urgencia) == 2)
                    {
                        paciente.llegada = reloj;
                        registrar(salaEspera, paciente);
                    }
                }
                else if (strcmp(orden, "ATIENDE") == 0)
                {
                    //atender devuelve 1 si habia alguien y lo deja en paciente
                    if (atender(salaEspera, &paciente) == 1)
                    {
                        printf("%s\n", paciente.nombre);
                    }
                    else
                    {
                        printf("nadie espera\n");
                    }
                }
            }
            //se libera la memoria que reservo crearCola
            destruirCola(salaEspera);
        }
    }
    return 0;
}