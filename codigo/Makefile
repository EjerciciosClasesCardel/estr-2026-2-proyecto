# Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
# Compilación del proyecto Ajuste FUENTES con los archivos que escriba.
CC      = g++
CFLAGS  = -Wall -Wextra -O2
FUENTES = principal.cpp Fabrica.cpp ListaArticulos.cpp Articulo.cpp
CABECERAS = Articulo.h Inventario.h ListaArticulos.h Fabrica.h
PROGRAMA = proyecto

all: $(PROGRAMA)

$(PROGRAMA): $(FUENTES) $(CABECERAS)
	$(CC) $(CFLAGS) $(FUENTES) -o $(PROGRAMA)

# Corre cada entrada de ../datos/ y compara con su salida esperada
pruebas: $(PROGRAMA)
	@for entrada in ../datos/*.in; do \
	  esperada="$${entrada%.in}.out"; \
	  if [ -f "$$esperada" ]; then \
	    ./$(PROGRAMA) < "$$entrada" > /tmp/salida.txt; \
	    if diff -q /tmp/salida.txt "$$esperada" > /dev/null; then \
	      echo "  OK   $$(basename $$entrada)"; \
	    else \
	      echo "  FALLA $$(basename $$entrada)"; \
	      diff /tmp/salida.txt "$$esperada" | head -5; \
	    fi; \
	  fi; \
	done

clean:
	rm -f $(PROGRAMA) *.o

.PHONY: all pruebas clean
