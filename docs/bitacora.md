# Bitácora

## 2026-11-01

- Quiénes: Jan Pieter Lelie
- Qué hicimos:
- Se clonó el repositorio y se reviso la implementación previa de la cola circular y el archivo 'principal.cpp'.
- Se completo 'principal.cpp' implementando las ordenes 'ESPERAN' (consulta cuantos pacientes hay en sala.) y 'PROMEDIO'(calcula el tiempo promedio de espera de los atendidos con decimales).
- Se crearon y subieron los 5 casos de prueba a la carpeta 'datos/' (3 funcionales y 2 limite: sala vacía y un solo paciente), validando que todos pasen correctamente con `make pruebas`.
- Qué quedó pendiente: Llenar la tabla de casos de prueba en el informe de avance (`docs/informe-avance.md`).

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