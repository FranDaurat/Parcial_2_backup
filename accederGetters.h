#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"
#include "lista_simple.h"
#include "menu.h"
#include "utils.h"
#include "biblioteca.h"

#ifndef GETTERS
#define GETTERS

void accederGetters(lista_cab *li)
{
    Libro libro;
    char id[15];
    char titulo[100];
    char editorial[50];
    int anoEdicion;
    int cantPaginas;
    int opcion = opcionAcceder();
    switch (opcion)
    {
    case 1:
        printf("Acceder al titulo del libro\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        if (strcmp(libro.isbn, "") != 0)
        {
            strcpy(titulo, getTitulo(&libro));
            printf("lo del libro es: %s\n", titulo);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;

    case 2:
        printf("Acceder al autor buscado. Opciones validas (1, 2 o 3) \n");
        int opcion = opcionAcceder();
        if (opcion == 1 || opcion == 2 || opcion == 3)
        {
            Autor autor;
            printf("Ingrese el numero de ISBN para buscar el libro:\n");
            strcpy(id, ingresarId());
            buscarLibroPorISBN(li, id, &libro);

            if (opcion == 1)
            {
                autor = getAutor1(&libro);
                printf("El nombre del autor es: %s %s\n", autor.nombre, autor.apellido);
            }
            else if (opcion == 2)
            {
                autor = getAutor2(&libro);
                printf("El nombre del autor es: %s %s\n", autor.nombre, autor.apellido);
            }
            else
            {
                autor = getAutor3(&libro);
                printf("El nombre del autor es: %s %s\n", autor.nombre, autor.apellido);
            }
        }
        else
        {
            printf("La opcion no es valida\n");
        }
        break;

    case 3:
        printf("Acceder al ISBN del libro\n");
        printf("Ingrese el titulo del libro\n");
        strcpy(titulo, ingresarTitulo());
        buscarLibroPorTitulo(li, titulo, &libro);
        if (strcmp(libro.titulo, "") != 0)
        {
            strcpy(titulo, getTitulo(&libro));
            printf("El isbn del libro es: %s\n", libro.isbn);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;

    case 4:
        printf("Acceder a la cantidad de paginas del libro\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        if (existe_Libro(li, &libro, id))
        {
            printf("La cantida de paginas del libro son: %d\n", libro.cantidadPaginas);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;

    case 5:
        printf("Acceder al ano de edicion del libro\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        if (existe_Libro(li, &libro, id))
        {
            printf("El ano de edicion %d", libro.anoEdicion);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;

    case 6:
        printf("Acceder al genero del libro\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        if (strcmp(libro.isbn, "") != 0)
        {
            char *genero = getGenero(&libro);
            printf("El genero del libro es: %s \n", genero);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;

    case 7:
        printf("Acceder a la editorial del libro\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        if (strcmp(libro.isbn, "") != 0)
        {
            strcpy(editorial, getEditorial(&libro));
            printf("El editorial del libro es: %s\n", libro.editorial);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;
    case 8:
        printf("Acceder al ano de edicion\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        char anoEdicion[10];
        if (strcmp(libro.isbn, "") != 0)
        {
            int ano = getAnoEdicion(&libro);
            sprintf(anoEdicion, "%d", ano);
            printf("El ano de edicion es: %s\n", anoEdicion);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;
    case 9:
        printf("Acceder a la cantidad de paginas\n");
        printf("Ingrese el numero de ISBN para buscar el libro:\n");
        strcpy(id, ingresarId());
        buscarLibroPorISBN(li, id, &libro);
        char cantPaginas[10];
        if (strcmp(libro.isbn, "") != 0)
        {
            int cantPags = getCantPag(&libro);
            sprintf(cantPaginas, "%d", cantPags);
            printf("El libro tiene: %s paginas\n", cantPaginas);
        }
        else
        {
            printf("Libro no encontrado.\n");
        }
        break;
    default:
        printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        break;
    }
}

#endif