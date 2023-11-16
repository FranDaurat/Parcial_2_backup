#include <stdio.h>
#include <stdlib.h>
#include "autor.h"
#ifndef LIBRO_H
#define LIBRO_H
typedef struct
{
    char titulo[100];
    Autor autor1;
    Autor autor2;
    Autor autor3;
    int cantidadPaginas;
    char isbn[15];
    int anoEdicion;
    char editorial[50];
    char genero[20];
} Libro;

char *getTitulo(Libro *lib)
{
    return lib->titulo;
}

Autor getAutor1(Libro *lib)
{
    return lib->autor1;
}
Autor getAutor2(Libro *lib)
{
    return lib->autor2;
}
Autor getAutor3(Libro *lib)
{
    return lib->autor3;
}

char *getIsbn(Libro *lib)
{
    return lib->isbn;
}

int getCantPag(Libro *lib)
{
    return lib->cantidadPaginas;
}

int getAnoEdicion(Libro *lib)
{
    return lib->anoEdicion;
}

char *getEditorial(Libro *lib)
{
    return lib->editorial;
}

char *getGenero(Libro *lib)
{
    return lib->genero;
}

void modificarTitulo(Libro *lib, char *nuevoTitulo)
{
    strcpy(lib->titulo, nuevoTitulo);
}

void modificarAutor1nombre(Libro *lib, char *nuevoAutor1)
{
    strncpy(lib->autor1.nombre, nuevoAutor1, sizeof(lib->autor1.nombre) - 1);
    lib->autor1.nombre[sizeof(lib->autor1.nombre) - 1] = '\0';
}

void modificarAutor2nombre(Libro *lib, char *nuevoAutor2)
{
    strncpy(lib->autor2.nombre, nuevoAutor2, sizeof(lib->autor2.nombre) - 1);
    lib->autor2.nombre[sizeof(lib->autor2.nombre) - 1] = '\0';
}

void modificarAutor3nombre(Libro *lib, char *nuevoAutor3)
{
    strncpy(lib->autor3.nombre, nuevoAutor3, sizeof(lib->autor3.nombre) - 1);
    lib->autor3.nombre[sizeof(lib->autor3.nombre) - 1] = '\0';
}

void modificarAutor1apellido(Libro *lib, char *nuevoAutor1)
{
    strncpy(lib->autor1.apellido, nuevoAutor1, sizeof(lib->autor1.apellido) - 1);
    lib->autor1.apellido[sizeof(lib->autor1.apellido) - 1] = '\0';
}

void modificarAutor2apellido(Libro *lib, char *nuevoAutor2)
{
    strncpy(lib->autor2.apellido, nuevoAutor2, sizeof(lib->autor2.apellido) - 1);
    lib->autor2.apellido[sizeof(lib->autor2.apellido) - 1] = '\0';
}

void modificarAutor3apellido(Libro *lib, char *nuevoAutor3)
{
    strncpy(lib->autor3.apellido, nuevoAutor3, sizeof(lib->autor3.apellido) - 1);
    lib->autor3.apellido[sizeof(lib->autor3.apellido) - 1] = '\0';
}

void modificarEditorial(Libro *lib, char *nuevaEditorial)
{
    strncpy(lib->editorial, nuevaEditorial, sizeof(lib->editorial) - 1);
    lib->editorial[sizeof(lib->editorial) - 1] = '\0';
}

void modificarAnoEdicion(Libro *lib, int ano)
{
    lib->anoEdicion = ano;
}

void modificarCantPags(Libro *lib, int pags)
{
    lib->cantidadPaginas = pags;
}

void modificarGenero(Libro *lib, char *nuevoGenero)
{
    strncpy(lib->genero, nuevoGenero, sizeof(lib->genero) - 1);
    lib->genero[sizeof(lib->genero) - 1] = '\0';
}

void mostrarLibro(Libro lib)
{
    printf("ISBN: %s\n", lib.isbn);
    printf("Titulo: %s\n", lib.titulo);
    printf("Ano de Publicacion: %d\n", lib.anoEdicion);
    printf("Editorial: %s\n", lib.editorial);
    printf("Genero: %s\n", lib.genero);
    printf("\n");
}

void ingresarDatos(Libro *libro)
{

    printf("Titulo: ");
    scanf("%s", &libro->titulo);

    printf("Autor 1 Nombre: ");
    scanf("%s", &libro->autor1.nombre);

    printf("Autor 1 Apellido: ");
    scanf("%s", &libro->autor1.apellido);

    printf("Autor 2 Nombre: ");
    scanf("%s", &libro->autor2.nombre);

    printf("Autor 2 Apellido: ");
    scanf("%s", &libro->autor2.apellido);

    printf("Autor 3 Nombre: ");
    scanf("%s", &libro->autor3.nombre);

    printf("Autor 3 Apellido: ");
    scanf("%s", &libro->autor3.apellido);

    printf("Cantidad de Paginas: ");
    scanf("%d", &libro->cantidadPaginas);

    printf("ISBN: ");
    scanf("%s", &libro->isbn);

    printf("Ano de Edicion: ");
    scanf("%d", &libro->anoEdicion);

    printf("Editorial: ");
    scanf("%s", &libro->editorial);

    printf("Genero: ");
    scanf("%s", &libro->genero);
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    ungetc('\n', stdin);
}

// void ingresarDatos(Libro *libro)
// {
//     printf("Titulo: ");
//     fgets(libro->titulo, sizeof(libro->titulo), stdin);
//     limpiarBuffer();

//     printf("Autor 1 Nombre: ");
//     fgets(libro->autor1.nombre, sizeof(libro->autor1.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 1 Apellido: ");
//     fgets(libro->autor1.apellido, sizeof(libro->autor1.apellido), stdin);
//     limpiarBuffer();

//     printf("Autor 2 Nombre: ");
//     fgets(libro->autor1.nombre, sizeof(libro->autor1.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 2 Apellido: ");
//     fgets(libro->autor1.apellido, sizeof(libro->autor1.apellido), stdin);
//     limpiarBuffer();

//     printf("Autor 3 Nombre: ");
//     fgets(libro->autor1.nombre, sizeof(libro->autor1.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 3 Apellido: ");
//     fgets(libro->autor1.apellido, sizeof(libro->autor1.apellido), stdin);
//     limpiarBuffer();

//     printf("ISBN: ");
//     scanf("%s", &libro->isbn);
//     limpiarBuffer();

//     printf("Ano de Edicion: ");
//     scanf("%d", &libro->anoEdicion);
//     limpiarBuffer();

//     printf("Genero: ");
//     fgets(libro->genero, sizeof(libro->genero), stdin);
//     limpiarBuffer();
// }
// void ingresarDatos(Libro *libro) {
//     printf("Titulo: ");
//     fgets(libro->titulo, sizeof(libro->titulo), stdin);
//     limpiarBuffer();

//     printf("Autor 1 Nombre: ");
//     fgets(libro->autor1.nombre, sizeof(libro->autor1.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 1 Apellido: ");
//     fgets(libro->autor1.apellido, sizeof(libro->autor1.apellido), stdin);
//     limpiarBuffer();

//     printf("Autor 2 Nombre: ");
//     fgets(libro->autor2.nombre, sizeof(libro->autor2.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 2 Apellido: ");
//     fgets(libro->autor2.apellido, sizeof(libro->autor2.apellido), stdin);
//     limpiarBuffer();

//     printf("Autor 3 Nombre: ");
//     fgets(libro->autor3.nombre, sizeof(libro->autor3.nombre), stdin);
//     limpiarBuffer();

//     printf("Autor 3 Apellido: ");
//     fgets(libro->autor3.apellido, sizeof(libro->autor3.apellido), stdin);
//     limpiarBuffer();

//     printf("ISBN: ");
//     fgets(libro->isbn, sizeof(libro->isbn), stdin);
//     limpiarBuffer();

//     printf("Ano de Edicion: ");
//     scanf("%d", &libro->anoEdicion);
//     limpiarBuffer();

//     printf("Genero: ");
//     fgets(libro->genero, sizeof(libro->genero), stdin);
//     limpiarBuffer();
// }


#endif
