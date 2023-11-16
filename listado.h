#include <stdio.h>
#include "Libro.h"
#include "biblioteca.h"
#include "utils.h"
#ifndef LISTADOS
#define LISTADOS 
    void accederListados(lista_cab *li)
    {
        Libro libro;
        char letra;
        char palabra[20];
        char id[15];
        char titulo[100];
        char editorial[50];
        char genero[20];
        char anoInicio[10];
        char anoFin[10];
        char anoEdicion[10];
        Autor autor;
        int opcion = opcionAcceder();
        switch (opcion)
        {
        case 1:
            printf("Lista de autores unicos:\n");
            listarAutoresUnicos(li);
            break;

        case 2:
            printf("Lista de libros existentes:\n");
            listarLibrosExistentes(li);
            break;

        case 3:
            printf("Lista de todos los libros de cierto genero:\n");
            printf("Ingrese el genero a buscar:\n");
            scanf("%s", genero);
            listarLibrosGenero(li, genero);
            break;
        case 4:
            printf("Lista de todos lo libro que poseen cierto autor:\n");
            printf("Ingrese el nombre del autor a buscar:\n");
            scanf("%s", autor.nombre);
            printf("Ingrese el apellido del autor a buscar:\n");
            scanf("%s", autor.apellido);
            listarLibrosAutor(li, autor);
            break;

        case 5:
            printf("Listar libros de editorial determianda\n");
            printf("Ingrese la editorial a buscar:\n");
            scanf("%s", editorial);
            listarLibrosEditorial(li, editorial);
            break;
        case 6:
            printf("Editorial en rango de edicion\n");
            printf("Ingrese la editorial a buscar:\n");
            scanf("%s", editorial);
            printf("Ingrese la fecha inicial:\n");
            scanf("%s", anoInicio);
            printf("Ingrese la fecha final:\n");
            scanf("%s", anoFin);
            listarLibrosEditorialAnoEdicion(li, editorial, anoInicio, anoFin);
            break;

        case 7:
            printf("Listar autores de una determinada editorial\n");
            printf("Ingrese la editorial para buscar a los autores:\n");
            scanf("%s", editorial);
            listarAutoresEditorial(li, editorial);
            break;

        case 8:
            printf("Libros editados en determinado ano\n");
            printf("Ingrese el ao de edicion:\n");
            scanf("%s", anoEdicion);
            listarLibrosAnoEdicion(li, anoEdicion);
            break;

        case 9:
            printf("Listar autores con una determinada letra en el apellido\n");
            printf("Ingrese la letra para buscar en el apellido de los autores:\n");
            scanf(" %c", &letra);
            listarLibrosPorInicialApellidoAutor(li, letra);
            break;

        case 10:
            printf("Listar libros con palabras similares en titulo\n");
            printf("Ingrese la palabra a buscar en el titulo de los libros:\n");
            scanf("%s", palabra);
            listarTitulosSimilares(li, palabra);
            break;

        default:
            printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
            break;
        }
    }
#endif 
