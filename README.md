# Proyecto — Estructuras de Datos 2026-2

Repositorio base del proyecto del curso. **Haga fork de este
repositorio** y trabaje sobre su copia.

El enunciado completo, con los cuatro escenarios, lo que se entrega en
cada fecha y cómo se califica, está en
[`enunciado/20262-estr-proyecto.pdf`](enunciado/20262-estr-proyecto.pdf).

## Lo primero

1. Fork de este repositorio con el botón **Fork**.
2. Llene [`AUTOR.md`](AUTOR.md) con su nombre completo y su código. Sin
   eso el repositorio no se puede asociar a nadie.
3. Escriba en `AUTOR.md` cuál de los cuatro escenarios escogió.

## Fechas

| Entrega | Cierre | Vale |
|---|---|---|
| Avance | viernes 30 de octubre de 2026 | 10 % del curso |
| Final | lunes 16 de noviembre de 2026, 23:59 | 20 % con la sustentación |

Se califica el último commit anterior a la hora de cierre. La historia
de commits cuenta: un repositorio con un solo commit el día del cierre
no muestra avance.

## Qué va en cada carpeta

| Carpeta | Qué contiene |
|---|---|
| `informe/` | el informe, en LaTeX o Markdown, y su PDF |
| `codigo/` | las fuentes en C o C++ y el `Makefile` |
| `datos/` | las entradas de prueba y los datos de los experimentos |
| `bitacora.md` | una entrada fechada por sesión de trabajo |

## Cómo se compila

Desde `codigo/`:

```bash
make            # produce los ejecutables
make pruebas    # corre los casos de prueba
make clean
```

El código se compila con `gcc -Wall -Wextra` o `g++ -Wall -Wextra` sin
advertencias, usa solo la biblioteca estándar, no lleva `break`,
`continue` ni `goto`, tiene un solo `return` al final de cada función y
libera toda la memoria que reserva.
