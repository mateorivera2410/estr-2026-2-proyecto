# Bitácora


## 2026-11-02

- Quiénes: Jan Pieter Lelie
- Qué hicimos:
  - Se completó la Sección 5 del informe de avance, documentando la tabla de validación con los 5 casos de prueba (3 funcionales y 2 límite) y redactando la justificación de los casos límite elegidos, estructura vacía y con un solo elemento.


## 2026-11-02

- Quiénes: Diego Alejandro Calvo
- Qué hicimos:
  - Escribimos la sección 1 del informe del avance: el escenario con un ejemplo propio de dos pacientes y cómo se mide la espera.
  - Escribimos la sección 2: qué guardan `Paciente` y `Cola`, la tabla de operaciones con su precondición, y por qué `PROMEDIO` lo calcula el `main` y no la cola.
- Qué quedó pendiente: La sección 5 del informe (Jan Pieter) y la revisión final antes del cierre.

## 2026-11-01

- Quiénes: Mateo Rivera Prados
- Qué hicimos:
  - Revisamos lo que subieron Diego y Jan Pieter: compila sin advertencias con `-Wall -Wextra` y `make pruebas` da OK en los 5 casos. También revisamos a mano que las salidas esperadas estuvieran bien calculadas.
  - Corregimos el formato de la entrada de Jan Pieter en la bitácora.
  - Escribimos la sección 3 del informe del avance: por qué escogimos la cola circular frente a la pila, el arreglo normal y la lista enlazada, el costo de cada operación con su razón, el invariante y un diagrama en Mermaid de la cola dando la vuelta. La cita es a Thareja, capítulo 8, sección 8.4.1.
  - Escribimos la sección 4 del informe: qué vamos a medir en la entrega final, con qué tamaños de entrada y qué esperamos ver.
- Qué quedó pendiente: Revisar las secciones 1 y 2 (Diego) y 5 (Jan Pieter) del informe cuando las suban.

## 2026-11-01

- Quiénes: Jan Pieter Lelie
- Qué hicimos:
  - Se clonó el repositorio y se revisó la implementación de la cola circular y el `principal.cpp`.
  - Se completó `principal.cpp` con las órdenes `ESPERAN` (cuántos pacientes hay en la sala) y `PROMEDIO` (el promedio de espera de los atendidos, con un decimal).
  - Se crearon los 5 casos de prueba en `datos/`: 3 funcionales y 2 límite (sala vacía y un solo paciente). Todos pasan con `make pruebas`.
- Qué quedó pendiente: Escribir el informe de avance seccion 5.

## 2026-11-01

- Quiénes: Diego Alejandro Calvo
- Qué hicimos:
  - Se clonó el repositorio y se revisó lo que ya estaba de la cola circular.
  - Se escribió `principal.cpp`: lee cuántas órdenes vienen, crea la cola con esa capacidad y lee las órdenes con un `while` hasta completarlas.
  - `LLEGA` guarda al paciente con el número de la orden en que llegó, para poder calcular después cuánto esperó.
  - `ATIENDE` saca al primero de la cola y escribe su nombre, o `nadie espera` si la cola está vacía.
  - Se arregló el `Makefile` para que compile también `cola.cpp`. Se probó con el ejemplo del enunciado y compila sin advertencias.
- Qué quedó pendiente: `ESPERAN` y `PROMEDIO` (los hace Jan Pieter), subir los casos de prueba a `datos/` y escribir el informe de avance.

## 2026-10-30

- Quiénes: Mateo Rivera Prados
- Qué hicimos:
  - Se llenó el README con los datos de los tres integrantes y el escenario D (Turnos de una clínica).
  - Se corrigió el `.gitignore`: ignoraba todos los archivos `.out`, incluidas las salidas esperadas de `datos/`. Se agregó la excepción `!datos/*.out`.
  - Se tomaron las decisiones del grupo:
    - La cola se crea con capacidad N, la primera línea de la entrada.
    - Si la cola está llena, `LLEGA` ignora al paciente.
    - `PROMEDIO` sin atendidos escribe `0.0`.
    - Los nombres tienen máximo 50 caracteres.
  - Se crearon los structs `Paciente` y `Cola` y se declararon las funciones de la cola en `codigo/cola.h`.
  - Se implementaron las 7 funciones de la cola circular en `codigo/cola.cpp`: `crearCola`, `destruirCola`, `estaVacia`, `estaLlena`, `cantidad`, `registrar` y `atender`. 
- Qué quedó pendiente: Integrar la cola con el `principal.cpp`, actualizar `FUENTES` en el `Makefile` y correr `make pruebas` con los casos de Jan Pieter.

## 2026-10-14

- Quiénes: Mateo Rivera Prados
- Qué hicimos: Fork del repositorio base del curso, clon local y se agregaron los colaboradores.
- Qué quedó pendiente: Llenar el README.