#include <stdio.h>
#include "lista_simple.h"
#include "biblioteca.h"
#include "Libro.h"
#include "menu.h"
#include "utils.h"
#include "modificar_libros.h"
#include "accederGetters.h"
#include "listado.h"

int main()
{
    lista_cab *li;
    crearLista(li);
    int opcion;
    Libro libro;
    int listaVacia = 1;
    do
    {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese los datos del libro:\n");
            ingresarDatos(&libro);
            insertar(li, libro);
            listaVacia = esListaVacia(li);
            break;

        case 2:
            if (listaVacia == 1)
            {
                printf("La lista esta vacia. Inserte al menos un libro primero.\n");
            }
            else
            {
                printf("Ingrese los datos del libro a insertar despues del actual:\n");
                ingresarDatos(&libro);
                insertar_Despues(li, libro);
            }
            break;

        case 3:
            if (listaVacia == 1)
            {
                printf("La lista esta vacia. Inserte al menos un libro primero.\n");
            }
            else
            {
                printf("Ingrese los datos del libro a insertar antes del actual:\n");
                ingresarDatos(&libro);
                insertar_Antes(li, libro);
            }
            break;

        case 4:
            if (listaVacia == 1)
            {
                printf("La lista esta vacia. No hay libros para eliminar.\n");
            }
            else
            {
                printf("Ingrese el ISBN del libro a eliminar:\n");
                scanf("%s", libro.isbn);
                eliminar(li, &libro);
                li->len--;
            }
            break;

        case 5:
            if (listaVacia == 1)
            {
                printf("La lista esta vacia. No hay libros para mostrar.\n");
            }
            else
            {
                printf("Libro Actual:\n");
                mostrarLibro(verActual(li));
            }
            break;

        case 6:
            if (listaVacia)
            {
                printf("La lista esta vacia. No hay libros para acceder a los getters.\n");
            }
            else
            {
                mostrarOpcionesGetters();
                accederGetters(li);
            }
            break;
        case 7:
            if (listaVacia)
            {
                printf("La lista esta vacia. No hay libros para acceder a los getters.\n");
            }
            else
            {
                mostrarListados();
                accederListados(li);
            }
            break;
        case 8:
            printf("Modificar libro");
            modificadorMenu();
            modificarLibros(li);
            break;

        case 9:
            printf("Volviendo al men principal.\n");
            break;

        case 10:
            printf("Saliendo del programa.\n");
            break;

        default:
            printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
            break;
        }
    } while (opcion != 10);
    return 0;
}
