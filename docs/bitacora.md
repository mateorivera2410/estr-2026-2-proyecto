# Bitácora

## 2026-11-15

- Quiénes: Mateo Rivera Prados
- Qué hicimos:
  - Corregimos lo que señaló la realimentación del avance: `principal.cpp` ahora descarta lo que sobra de un nombre de más de 50 letras, para que no se desfase el reloj (caso `caso7-limite-nombre-largo`), y agregamos `codigo/prueba_cola.cpp`, que usa una sala de 3 casillas para que el módulo de la cola dé la vuelta y se ejerzan las ramas de sala llena y vacía. `make pruebas` la corre.
  - Escribimos las secciones 1, 2 y 6 del informe final, y la tabla resumen de costos de las tres estructuras. En la sección 2, cada caso límite quedó ligado con la rama del código que ejercita.
  - Revisión final: compila sin advertencias, `make pruebas` da 22 OK y no hay errores de memoria.
- Qué quedó pendiente: Entregar el enlace en el aula digital y preparar la sustentación.

## 2026-11-15

- Quiénes: Diego Alejandro Calvo
- Qué hicimos:
  - Escribimos `codigo/medir.cpp`: mide la sala (cola o montículo, según con cuál se compile) contra `priority_queue`, con la misma secuencia de órdenes para las tres. De cada 5 órdenes 3 son `LLEGA` y 2 `ATIENDE`, las urgencias salen de una fórmula fija y cada tamaño se repite 3 veces.
  - Con `medir.cpp`, `make` vuelve a compilar los 4 programas sin advertencias.
  - Lo probamos con los 5 tamaños: con la cola, los de urgencia 5 y 1 esperan casi lo mismo; con el montículo, los de urgencia 5 esperan unas 2 órdenes y ningún paciente de urgencia 1 alcanza a ser atendido, por eso `espera_u1` sale en 0.0.
  - Corrimos los experimentos en el MacBook Pro (Apple M5, macOS 26.6.2, Apple clang 21.0.0 con `-Wall -Wextra -O2`) y guardamos los resultados en `datos/resultados.csv`, con una fila por tamaño.
  - Escribimos las secciones 4 y 5 del informe final: las tablas de tiempos y de esperas, la gráfica `xychart-beta` y la comparación de lo medido contra lo predicho por el análisis.
- Qué quedó pendiente: Preparar la sustentación: mostrar `medir.cpp` corriendo y explicar los resultados.

## 2026-11-14

- Quiénes: Jan Pieter Lelie
- Qué hicimos:
  - Escribimos `codigo/monticulo.cpp`: el montículo binario de máximos en arreglo con las 7 funciones de `sala.h` (`subir` al registrar, `bajar` al atender), con desempate por menor `llegada`. Compila sin advertencias y da el resultado del enunciado.
  - Creamos `datos/monticulo/` con los 5 casos de la cola y el `caso6-empate-de-urgencias`, con las salidas calculadas a mano. `make pruebas` da OK en todos.
  - Escribimos el análisis formal del montículo en la sección 3 del informe final: invariante con cuantificadores, `registrar` y `atender` en $O(\log n)$, el resto en $O(1)$, y el diagrama Mermaid.
- Qué quedó pendiente: `medir.cpp` (Diego), llenar la tabla de resumen de costos con el análisis del montículo y completar las secciones 1, 2 y 6 del informe final.

## 2026-11-14

- Quiénes: Mateo Rivera Prados
- Qué hicimos:
  - Creamos la interfaz común `codigo/sala.h` para la cola y el montículo: se renombró `cola.h` y se adaptaron `cola.cpp` y `principal.cpp` a los nombres nuevos (`Sala`, `crearSala`, `destruirSala`), para que el mismo programa funcione con cualquiera de las dos.
  - Rehicimos el `Makefile`: `make` produce `proyecto_cola`, `proyecto_monticulo`, `medir_cola` y `medir_monticulo`, y `make pruebas` corre los casos de `datos/` con la cola y los de `datos/monticulo/` con el montículo. Se actualizó el `.gitignore` para los nuevos ejecutables y los `.out` del montículo.
  - Escribimos el análisis formal de la cola en el informe final: el invariante con cuantificadores y la demostración de las 7 operaciones, en tiempo y en espacio, con sus testigos.
  - Decisiones del grupo para la final: misma interfaz para las dos estructuras; en el montículo, si dos pacientes tienen la misma urgencia, pasa el que llegó primero; los casos del montículo van en `datos/monticulo/`; `medir.cpp` mide con `clock()`, urgencias con una fórmula fija y `priority_queue` tal cual.
- Qué quedó pendiente: Secciones 1, 2 y 6 del informe final, llenar la tabla resumen con el análisis del montículo, y revisar la integración cuando Pit suba `monticulo.cpp` y Diego `medir.cpp`.

## 2026-11-02

- Quiénes: Mateo Rivera Prados
- Qué hicimos:
  - Revisión final del avance con los criterios del profe: compila sin advertencias, `make pruebas` da OK en los 5 casos y el informe tiene las 5 secciones completas.
  - Comparamos la tabla de casos de la sección 5 con los archivos `.in` y `.out` de `datos/`: coinciden.
  - Unimos en una sola las dos entradas de Jan Pieter del 2 de noviembre, porque fueron la misma sesión, y aclaramos la entrada del 14 de octubre.
  - Agregamos la sección de Referencias al informe del avance, con lo que consultamos.
- Qué quedó pendiente: Empezar la entrega final: el montículo binario con las mismas funciones de la cola.

## 2026-11-02

- Quiénes: Jan Pieter Lelie
- Qué hicimos:
  - Se completó la sección 5 del informe de avance: la tabla con los 5 casos de prueba (3 funcionales y 2 límite), con su entrada, la salida esperada y la salida obtenida.
  - Se corrigió la sección 5: se detallaron las entradas y salidas de cada caso y se mejoró la justificación de los casos límite (estructura vacía y un solo elemento).
- Qué quedó pendiente: Revisión final en grupo del trabajo antes del cierre.

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
- Qué hicimos: Fork del repositorio base del curso, clon local y se agregaron los colaboradores. El fork no genera un commit, por eso no aparece en la historia de este día.
- Qué quedó pendiente: Llenar el README.