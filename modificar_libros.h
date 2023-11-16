#include <stdio.h>
#include "lista_simple.h"
#include "utils.h"
#ifndef MODIFICARLIBROS 
#define MODIFICARLIBROS

void modificarLibros(lista_cab *li)
{
    Libro libro;
    char palabra[20];
    char id[15];
    char titulo[100];
    char editorial[50];
    char genero[20];
    int anoInicio;
    int anoFin;
    int anoEdicion;
    int cantPag;
    Autor autor;
    int opcion = opcionAcceder();

    Nodo *actual = li->com->prox;
    int i;
    int libroEncontrado;

    switch (opcion)
    {
    case 1:
        printf("Modificar el titulo del libro\n");
        strcpy(id, ingresarId());
        i = 0;
        libroEncontrado = 0;
        printf("Ingrese el titulo nuevo\n");
        scanf("%s", titulo);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarTitulo(&(actual->li), titulo);
                libroEncontrado = 1;
                printf("El titulo modificado es %s\n", actual->li.titulo);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;

    case 2:
        printf("Modificar nombre del autor1\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el nombre del autor1 nuevo:\n");
        scanf("%s", autor.nombre);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor1nombre(&(actual->li), autor.nombre);
                libroEncontrado = 1;
                printf("El nombre del autor1 modificado es %s\n", actual->li.autor1.nombre);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }

        break;
    case 3:
        printf("Modificar apellido del autor1\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el apellido del autor1 nuevo:\n");
        scanf("%s", autor.apellido);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor1apellido(&(actual->li), autor.apellido);
                libroEncontrado = 1;
                printf("El apellido del autor1 modificado es %s\n", actual->li.autor1.apellido);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }

        break;
    case 4:
        printf("Modificar nombre del autor2\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el nombre del autor2 nuevo:\n");
        scanf("%s", autor.nombre);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor2nombre(&(actual->li), autor.nombre);
                libroEncontrado = 1;
                printf("El nombre del autor2 modificado es %s\n", actual->li.autor2.nombre);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 5:
        printf("Modificar apellido del autor2\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el apellido del autor2 nuevo:\n");
        scanf("%s", autor.apellido);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor2apellido(&(actual->li), autor.apellido);
                libroEncontrado = 1;
                printf("El apellido del autor2 modificado es %s\n", actual->li.autor2.apellido);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 6:
        printf("Modificar nombre del autor3\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el nombre del autor3 nuevo:\n");
        scanf("%s", autor.nombre);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor3nombre(&(actual->li), autor.nombre);
                libroEncontrado = 1;
                printf("El nombre del autor3 modificado es %s\n", actual->li.autor3.nombre);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 7:
        printf("Modificar apellido del autor3\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el apellido del autor3 nuevo:\n");
        scanf("%s", autor.apellido);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAutor3apellido(&(actual->li), autor.apellido);
                libroEncontrado = 1;
                printf("El apellido del autor2 modificado es %s\n", actual->li.autor3.apellido);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 8:
        printf("Modificar Editorial\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese la Editorial nueva:\n");
        scanf("%s", editorial);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarEditorial(&(actual->li), editorial);
                libroEncontrado = 1;
                printf("La editorial nueva es: %s\n", actual->li.editorial);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 9:
        printf("Modificar Ano Edicion\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el ano nuevo de edicion\n");
        scanf("%d", &anoEdicion);

        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarAnoEdicion(&(actual->li), anoEdicion);
                libroEncontrado = 1;
                printf("El ano nuevo de edicion es: %d\n", actual->li.anoEdicion);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 10:
        printf("Modificar Cantidad de Paginas\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese la cantidad de paginas a cambiar\n");
        scanf("%d", &cantPag);

        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarCantPags(&(actual->li), cantPag);
                libroEncontrado = 1;
                printf("La cantidad de paginas es: %d\n", actual->li.cantidadPaginas);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    case 11:
        printf("Modificar Genero\n");
        strcpy(id, ingresarId());
        i = 0;
        printf("Ingrese el Genero literario nuevo:\n");
        scanf("%s", genero);
        while (i < (li->len))
        {
            if (strcmp(actual->li.isbn, id) == 0)
            {
                modificarGenero(&(actual->li), genero);
                libroEncontrado = 1;
                printf("El genero nuevo es: %s\n", actual->li.genero);
                break;
            }
            actual = actual->prox;
            i++;
        }

        if (!libroEncontrado)
        {
            printf("Libro con ISBN %s no encontrado.\n", id);
        }
        break;
    default:
        printf("La opcion ingresada no es correcta");
        break;
    }
}

#endif 