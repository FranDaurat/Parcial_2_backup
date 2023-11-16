#include <stdio.h>

#ifndef MENUS
#define MENUS

void mostrarMenu()
{
    printf("\n--- Menu ---\n");
    printf("1. Insertar Libro\n");
    printf("2. Insertar Libro Despues del Actual\n");
    printf("3. Insertar Libro Antes del Actual\n");
    printf("4. Eliminar Libro\n");
    printf("5. Mostrar Libro Actual\n");
    printf("6. Acceder a datos de un Libro \n");
    printf("7. Listar libros\n");
    printf("8. Modificar Libro\n");
    printf("9. Volver al Menu Principal\n");
    printf("10. Salir\n");
}

void mostrarOpcionesGetters()
{
    printf("\n--- Menu Datos Libro ---\n");
    printf("1. Acceder al titulo de un Libro\n");
    printf("2. Acceder al Autor Elija uno dos o tres \n");
    printf("3. Acceder al libro por ISBN \n");
    printf("4. Acceder a la cantidad de paginas del libro \n");
    printf("5. Acceder al ano de la edicion \n");
    printf("6. Acceder el genero del libro \n");
    printf("7. Acceder a la editorial\n");
    printf("8. Acceder \n");
}

void mostrarListados()
{
    printf("\n--- Menu Listar Datos ---\n");
    printf("1. Listar todos los autores existentes\n");
    printf("2. Listar todos los libros existentes\n");
    printf("3. Listar todos los libros de un genero determinado.\n");
    printf("4. Listar todos los libros que posee un autor determinado.\n");
    printf("5. Listar todos los libros de una editorial determinada.\n");
    printf("6. Listar todos los libros de una editorial determinada en un rango de anos de edicion.\n ");
    printf("7. Listar todos los autores de una determinada editorial.\n");
    printf("8. Listar todos los libros que fueron editados en un determinado ano.\n");
    printf("9. Listar todos los libros de los autores cuyos apellidos comienzan con una letra determinada. \n");
    printf("10. Listar todos los libros cuyos titulos contengan una palabra determinada.\n ");
}

void modificadorMenu()
{
    printf("\n--- Menu Modificar Libro ---\n");
    printf("1. Modificar Titulo\n");
    printf("2. Modificar Autor1 Nombre\n");
    printf("3. Modificar Autor1 Apellido\n");
    printf("4. Modificar Autor2 Nombre\n");
    printf("5. Modificar Autor2 Apellido\n");
    printf("6. Modificar Autor3 Nombre\n");
    printf("7. Modificar Autor3 Apellido\n");
    printf("8. Modificar Editorial\n");
    printf("9. Modificar Ano Edicion\n");
    printf("10. Modificar cantidad de paginas\n");
    printf("11. Modificar genero\n");
}


#endif 