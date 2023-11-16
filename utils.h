#include <stdio.h>
#include <stdlib.h>

#ifndef UTILIDADES
#define UTILIDADES
int opcionAcceder()
{
    int opcion;
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
char *ingresarId()
{
    char *id = (char *)malloc(15 * sizeof(char));
    if (id == NULL)
    {
        fprintf(stderr, "Error al asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese un codigo ISBN: ");
    scanf("%s", id);
    return id;
}

char *ingresarTitulo()
{
    char *titulo = (char *)malloc(15 * sizeof(char));
    if (titulo == NULL)
    {
        fprintf(stderr, "Error al asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    printf("Ingrese un titulo: ");
    scanf("%s", titulo);
    return titulo;
}

#endif 