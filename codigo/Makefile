# Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
# Compilación del proyecto ajuste FUENTES con los archivos que escriba
CC      = g++
CFLAGS  = -Wall -Wextra -O2
ESTRUCTURAS = Fabrica.cpp ListaArticulos.cpp TablaHash.cpp ReferenciaMap.cpp Articulo.cpp
FUENTES = principal.cpp $(ESTRUCTURAS)
CABECERAS = Articulo.h Inventario.h ListaArticulos.h TablaHash.h ReferenciaMap.h Fabrica.h
PROGRAMA = proyecto
MEDIDOR = medir

# Experimentos: 5 tamanos tabla pequena (101), una igual a n y un primo
# mayor que todos los n (200003); y el juego donde todo cae en una cubeta.
TAMANOS = 1000 5000 10000 50000 100000

all: $(PROGRAMA) $(MEDIDOR)

$(PROGRAMA): $(FUENTES) $(CABECERAS)
	$(CC) $(CFLAGS) $(FUENTES) -o $(PROGRAMA)

$(MEDIDOR): medir.cpp $(ESTRUCTURAS) $(CABECERAS)
	$(CC) $(CFLAGS) medir.cpp $(ESTRUCTURAS) -o $(MEDIDOR)

# Corre todas las mediciones y las guarda en ../datos/mediciones.csv
mediciones: $(MEDIDOR)
	@echo "tipo,n,cubetas,juego,consultas,ns_por_consulta" > ../datos/mediciones.csv
	@for n in $(TAMANOS); do \
	  ./$(MEDIDOR) lista $$n 1 normal >> ../datos/mediciones.csv; \
	  ./$(MEDIDOR) map $$n 1 normal >> ../datos/mediciones.csv; \
	  ./$(MEDIDOR) hash $$n 101 normal >> ../datos/mediciones.csv; \
	  ./$(MEDIDOR) hash $$n $$n normal >> ../datos/mediciones.csv; \
	  ./$(MEDIDOR) hash $$n 200003 normal >> ../datos/mediciones.csv; \
	  ./$(MEDIDOR) hash $$n 1009 colision >> ../datos/mediciones.csv; \
	  echo "  listo n = $$n"; \
	done 2> /dev/null
	@echo "  mediciones en ../datos/mediciones.csv"

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
	rm -f $(PROGRAMA) $(MEDIDOR) *.o

.PHONY: all pruebas mediciones clean
