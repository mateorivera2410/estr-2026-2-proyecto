# Compila la sala con la cola y con el montículo, y el programa que mide.
CC      = g++
CFLAGS  = -Wall -Wextra -O2

all: proyecto_cola proyecto_monticulo medir_cola medir_monticulo prueba_cola

proyecto_cola: principal.cpp cola.cpp sala.h
	$(CC) $(CFLAGS) principal.cpp cola.cpp -o proyecto_cola

proyecto_monticulo: principal.cpp monticulo.cpp sala.h
	$(CC) $(CFLAGS) principal.cpp monticulo.cpp -o proyecto_monticulo

medir_cola: medir.cpp cola.cpp sala.h
	$(CC) $(CFLAGS) medir.cpp cola.cpp -o medir_cola

medir_monticulo: medir.cpp monticulo.cpp sala.h
	$(CC) $(CFLAGS) medir.cpp monticulo.cpp -o medir_monticulo

# Prueba la cola con solo 3 casillas, para que el indice de la vuelta y la sala se llene
prueba_cola: prueba_cola.cpp cola.cpp sala.h
	$(CC) $(CFLAGS) prueba_cola.cpp cola.cpp -o prueba_cola

# Corre cada entrada de ../datos/ y compara con su salida esperada
pruebas: proyecto_cola proyecto_monticulo prueba_cola
	@echo "Cola:"
	@for entrada in ../datos/*.in; do \
	  esperada="$${entrada%.in}.out"; \
	  if [ -f "$$esperada" ]; then \
	    ./proyecto_cola < "$$entrada" > /tmp/salida.txt; \
	    if diff -q /tmp/salida.txt "$$esperada" > /dev/null; then \
	      echo "  OK   $$(basename $$entrada)"; \
	    else \
	      echo "  FALLA $$(basename $$entrada)"; \
	      diff /tmp/salida.txt "$$esperada" | head -5; \
	    fi; \
	  fi; \
	done
	@echo "Cola con 3 casillas (la vuelta del indice):"
	@./prueba_cola
	@echo "Montículo:"
	@for entrada in ../datos/monticulo/*.in; do \
	  esperada="$${entrada%.in}.out"; \
	  if [ -f "$$esperada" ]; then \
	    ./proyecto_monticulo < "$$entrada" > /tmp/salida.txt; \
	    if diff -q /tmp/salida.txt "$$esperada" > /dev/null; then \
	      echo "  OK   $$(basename $$entrada)"; \
	    else \
	      echo "  FALLA $$(basename $$entrada)"; \
	      diff /tmp/salida.txt "$$esperada" | head -5; \
	    fi; \
	  fi; \
	done

clean:
	rm -f proyecto_cola proyecto_monticulo medir_cola medir_monticulo prueba_cola *.o *.exe

.PHONY: all pruebas clean