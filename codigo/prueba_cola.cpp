// Autores: Mateo Rivera Prados 9033302, Diego Alejandro Calvo 9038021, Jan Pieter Lelie 9035703
#include "sala.h"
#include <cstdio>
#include <cstring>

// Imprime OK o FALLA segun la condicion, y devuelve 1 si fallo
int revisar(int condicion, const char *mensaje)
{
    int fallo = 0;
    if (condicion)
    {
        printf("  OK    %s\n", mensaje);
    }
    else
    {
        printf("  FALLA %s\n", mensaje);
        fallo = 1;
    }
    return fallo;
}

// Arma un paciente con el nombre y la llegada que se le pasan
Paciente paciente(const char *nombre, int llegada)
{
    Paciente p;
    strncpy(p.nombre, nombre, MAX_NOMBRE);
    p.nombre[MAX_NOMBRE] = '\0'; // asegurar el '\0'
    p.urgencia = 1;              // en la cola la urgencia no importa
    p.llegada = llegada;
    return p;
}

// Prueba la cola con solo 3 casillas, para que el indice de la vuelta y la sala se llene.
// Con capacidad N (como en principal.cpp) el % nunca se ejerce, por eso se prueba aparte
int main()
{
    int fallas = 0;
    Paciente p;
    Sala *sala = crearSala(3);

    // Paso 1: se llena la sala de 3 casillas (ana en la 0, beto en la 1, caro en la 2)
    registrar(sala, paciente("ana", 1));
    registrar(sala, paciente("beto", 2));
    registrar(sala, paciente("caro", 3));
    fallas += revisar(estaLlena(sala), "con 3 pacientes la sala esta llena");

    // Paso 2: rama de sala llena, dani no entra
    fallas += revisar(registrar(sala, paciente("dani", 4)) == 0, "registrar con la sala llena devuelve 0");

    // Paso 3: se atiende a ana y queda libre la casilla 0 (el frente pasa a la 1)
    atender(sala, &p);
    fallas += revisar(strcmp(p.nombre, "ana") == 0, "atiende a ana, la primera en llegar");

    // Paso 4: eli entra en (1 + 2) % 3 = 0, el % de registrar da la vuelta
    registrar(sala, paciente("eli", 5));
    fallas += revisar(strcmp(sala->datos[0].nombre, "eli") == 0, "eli entra en la casilla 0: registrar da la vuelta");

    // Paso 5: salen beto y caro, y el frente pasa de la casilla 2 a la 0, el % de atender da la vuelta
    atender(sala, &p);
    fallas += revisar(strcmp(p.nombre, "beto") == 0, "atiende a beto");
    atender(sala, &p);
    fallas += revisar(strcmp(p.nombre, "caro") == 0, "atiende a caro");
    fallas += revisar(sala->frente == 0, "el frente vuelve a la casilla 0: atender da la vuelta");
    atender(sala, &p);
    fallas += revisar(strcmp(p.nombre, "eli") == 0, "atiende a eli, que estaba en la casilla 0");

    // Paso 6: rama de sala vacia
    fallas += revisar(atender(sala, &p) == 0, "atender con la sala vacia devuelve 0");

    destruirSala(sala);
    return fallas;
}