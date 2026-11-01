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
    int pacientesAtendidos = 0; //cuantos pacientes ya se atendieron
    long long sumaEsperas = 0; //suma de lo que esperaron los atendidos (long long porque puede crecer mucho)

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
                        //lo que espero = la orden que lo atiende menos la orden en que llego
                        sumaEsperas += reloj - paciente.llegada;
                        pacientesAtendidos++;
                        printf("%s\n", paciente.nombre);
                    }
                    else
                    {
                        printf("nadie espera\n");
                    }
                }
                else if (strcmp(orden, "ESPERAN") == 0)
                {
                    //cuantos pacientes siguen en la sala
                    printf("%d\n", cantidad(salaEspera));
                }
                else if (strcmp(orden, "PROMEDIO") == 0)
                {
                    //si nadie ha sido atendido se escribe 0.0 (decision del grupo)
                    double promedioEspera = 0.0;
                    if (pacientesAtendidos > 0)
                    {
                        //(double) para que la division tenga decimales y no sea entera
                        promedioEspera = (double)sumaEsperas / pacientesAtendidos;
                    }
                    printf("%.1f\n", promedioEspera);
                }
            }
            //se libera la memoria que reservo crearCola
            destruirCola(salaEspera);
        }
    }
    return 0;
}