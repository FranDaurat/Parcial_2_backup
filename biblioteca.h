#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "lista_simple.h"
#include "autor.h"

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

int existe_Libro(lista_cab *l, Libro *Lib, char *id)
{
    Nodo *actual = l->com->prox;
    int i = 0;
    while (i <= (l->len - 1))
    {
        if (strcmp(actual->li.isbn, id) == 0)
        {
            return 1;
        }
        actual = actual->prox;
        i++;
    }
    return 0;
}

void buscarLibroPorISBN(lista_cab *l, char *id, Libro *lib)
{
    Nodo *actual = l->com->prox;
    int i = 0;
    while (i < l->len - 1)
    {
        if (strcmp(actual->li.isbn, id) == 0)
        {
            *lib = actual->li;
            return;
        }
        actual = actual->prox;
        i++;
    }
}

void buscarLibroPorTitulo(lista_cab *l, char *titulo, Libro *lib)
{
    Nodo *actual = l->com->prox;
    int i = 0;
    while (i < l->len - 1)
    {
        if (strcmp(actual->li.titulo, titulo) == 0)
        {
            *lib = actual->li;
            return;
        }
        actual = actual->prox;
        i++;
    }
}

void recorrerLista(lista_cab *l)
{
    Nodo *actual = l->com->prox;
    int i = 0;
    while (i <= (l->len - 1))
    {
        printf("Título: %s\n", actual->li.titulo);
        printf("Autor1: %s %s\n", actual->li.autor1.nombre, actual->li.autor1.apellido);
        printf("Autor2: %s %s\n", actual->li.autor2.nombre, actual->li.autor2.apellido);
        printf("Autor3: %s %s\n", actual->li.autor3.nombre, actual->li.autor3.apellido);
        printf("Cantidad de paginas: %d\n", actual->li.cantidadPaginas);
        printf("ISBN: %s\n", actual->li.isbn);
        printf("Ano de edicion: %d\n", actual->li.anoEdicion);
        printf("Editorial: %s\n", actual->li.editorial);
        printf("Género: %s\n", actual->li.genero);
        printf("\n");
        actual = actual->prox;
        i++;
    }
}

int existeAutor(Autor *autoresUnicos, int numAutoresUnicos, Autor *autor)
{
    for (int i = 0; i < numAutoresUnicos; i++)
    {
        if (strcmp(autoresUnicos[i].nombre, autor->nombre) == 0 &&
            strcmp(autoresUnicos[i].apellido, autor->apellido) == 0)
        {
            return 1;
        }
    }
    return 0;
}

//1)Listar todos los autores existentes. OK
void listarAutoresUnicos(lista_cab *li){
    Autor *autoresUnicos = malloc(li->len* sizeof(Autor));
    Nodo *actual = li->com->prox;
    int numAutoresUnicos = 0;
    int i = 0;
    int j = 0;
    
    if (autoresUnicos == NULL){
        return;
    }
    while (i < (li->len)){
        if (!existeAutor(autoresUnicos, numAutoresUnicos, &(actual->li.autor1)))
        {
            autoresUnicos[numAutoresUnicos] = actual->li.autor1;
            numAutoresUnicos++;
        }

        if (actual->li.autor2.nombre[0] != '\0' && actual->li.autor2.nombre[0] != '\n' && !existeAutor(autoresUnicos, numAutoresUnicos, &(actual->li.autor2))){
            autoresUnicos[numAutoresUnicos] = actual->li.autor2;
            numAutoresUnicos++;
        }

        if (actual->li.autor3.nombre[0] != '\0' && actual->li.autor3.nombre[0] != '\n' && !existeAutor(autoresUnicos, numAutoresUnicos, &(actual->li.autor3))){
            autoresUnicos[numAutoresUnicos] = actual->li.autor3;
            numAutoresUnicos++;
        }
        actual = actual->prox;
        i++;
    }
    printf("Numero total de autores en la lista: %d\n", li->len + 1);
    printf("Numero total de autores unicos: %d\n", numAutoresUnicos);
    if (numAutoresUnicos > 0){
        while (j < (numAutoresUnicos)){
            printf("Autor: %s %s\n", autoresUnicos[j].nombre, autoresUnicos[j].apellido);
            j++;
        }
    } 
    free(autoresUnicos);
}


// 2) ListarLibrosExistentes. OK
void listarLibrosExistentes(lista_cab *li)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len)){
        printf("ISBN: %s\n", actual->li.isbn);
        printf("Titulo: %s\n", actual->li.titulo);
        printf("Ano de Publicacion: %d\n", actual->li.anoEdicion);
        printf("Genero: %s\n", actual->li.genero);
        printf("\n");
        actual = actual->prox;
        i++;
    }
}

// 3) Listar libros de generos determinados. OK
void listarLibrosGenero(lista_cab *li, char *genero)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len))
    {
        if (strcmp(actual->li.genero, genero) == 0)
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de Publicacion: %d\n", actual->li.anoEdicion);
            printf("Genero: %s\n", actual->li.genero);
            printf("\n");
        }
        actual = actual->prox;
        i++;
    }
}

// 4) Listar todos los libros que posee un autor determinado. OK

void listarLibrosAutor(lista_cab *li, Autor autor)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len))
    {
        if (strcmp(actual->li.autor1.nombre, autor.nombre) == 0 || strcmp(actual->li.autor2.nombre, autor.nombre) == 0 || strcmp(actual->li.autor3.nombre, autor.nombre) == 0 || strcmp(actual->li.autor1.apellido, autor.apellido) == 0 || strcmp(actual->li.autor2.apellido, autor.apellido) == 0 || strcmp(actual->li.autor3.apellido, autor.apellido) == 0)
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de Publicacion: %d\n", actual->li.anoEdicion);
            printf("Genero: %s\n", actual->li.genero);
            printf("\n");
        }
        actual = actual->prox;
        i++;
    }
}

// 5) Listar todos los libros de una editorial determinada. OK
void listarLibrosEditorial(lista_cab *li, char *editorial)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len))
    {
        if (strcmp(actual->li.editorial, editorial) == 0)
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de Publicacion: %d\n", actual->li.anoEdicion);
            printf("Genero: %s\n", actual->li.genero);
            printf("\n");
        }
        actual = actual->prox;
        i++;
    }
}

// 6) Listar todos los libros de una editorial determinada en un rango de años de edición. OK

void listarLibrosEditorialAnoEdicion(lista_cab *li, char *editorial, char *anoInicio, char *anoFin)
{
    Nodo *actual = li->com->prox;
    int i = 0;

    while (i < (li->len))
    {
        int anoEdicion = actual->li.anoEdicion;

        if (strcmp(actual->li.editorial, editorial) == 0 &&
            anoEdicion >= atoi(anoInicio) &&
            anoEdicion <= atoi(anoFin))
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de Publicacion: %d\n", anoEdicion);
            printf("Editorial: %s\n", actual->li.editorial);
            printf("\n");
        }

        actual = actual->prox;
        i++;
    }
}

// 7) Listar todos los autores de una determinada editorial. OK
void listarAutoresEditorial(lista_cab *li, char *editorial)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len))
    {
        if (strcmp(actual->li.editorial, editorial) == 0)
        {
            printf("Autores:\n %s %s\n %s %s \n %s %s\n", actual->li.autor1.nombre, actual->li.autor1.apellido, actual->li.autor2.nombre, actual->li.autor2.apellido, actual->li.autor3.nombre, actual->li.autor3.apellido);
        }
        actual = actual->prox;
        i++;
    }
}

// 8) Listar todos los libros que fueron editados en un determinado

void listarLibrosAnoEdicion(lista_cab *li, char *anoEdicion)
{
    Nodo *actual = li->com->prox;
    int i = 0;

    while (i < (li->len))
    {
        int anoEdicionInt = atoi(anoEdicion);
        if (actual->li.anoEdicion == anoEdicionInt)
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de Publicacion: %d\n", actual->li.anoEdicion);
            printf("Editorial: %s\n", actual->li.editorial);
            printf("\n");
        }

        actual = actual->prox;
        i++;
    }
}

// 9) Listar todos los libros de los autores cuyos apellidos comienzan con una letra determinada. OK
void listarLibrosPorInicialApellidoAutor(lista_cab *li, char letraInicial)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    char primera = actual->li.autor1.apellido[0];
    while (i < (li->len))
    {
        char primeraLetraApellido1 = primera;
        if (toupper(primeraLetraApellido1) == toupper(letraInicial))
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de edicion: %d\n", actual->li.anoEdicion);
            printf("Autor: %s %s\n", actual->li.autor1.nombre, actual->li.autor1.apellido);
            printf("\n");
        }
        primera = actual->li.autor2.apellido[0];
        char primeraLetraApellido2 = primera;
        if (toupper(primeraLetraApellido2) == toupper(letraInicial))
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de edicion: %d\n", actual->li.anoEdicion);
            printf("Autor: %s %s\n", actual->li.autor2.nombre, actual->li.autor2.apellido);
            printf("\n");
        }
        primera = actual->li.autor3.apellido[0];
        char primeraLetraApellido3 = primera;
        if (toupper(primeraLetraApellido3) == toupper(letraInicial))
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de edicion: %d\n", actual->li.anoEdicion);
            printf("Autor: %s %s\n", actual->li.autor3.nombre, actual->li.autor3.apellido);
            printf("\n");
        }
        actual = actual->prox;
        i++;
    }
}

// 10) Listar todos los libros cuyos títulos contengan una palabra determinada.OK

void listarTitulosSimilares(lista_cab *li, char *palabra)
{
    Nodo *actual = li->com->prox;
    int i = 0;
    while (i < (li->len))
    {
        if (strstr(actual->li.titulo, palabra) != NULL)
        {
            printf("ISBN: %s\n", actual->li.isbn);
            printf("Titulo: %s\n", actual->li.titulo);
            printf("Ano de edicion: %d\n", actual->li.anoEdicion);
            printf("Autor: %s %s\n", actual->li.autor1.nombre, actual->li.autor1.apellido);
            printf("\n");
        }
        actual = actual->prox;
        i++;
    }
}

#endif