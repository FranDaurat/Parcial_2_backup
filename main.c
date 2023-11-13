#include <stdio.h>
#include "test.h"
#include "lista_simple.h"
#include "biblioteca.h"
#include "Libro.h"
#include "menu.h"

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

int opcionAcceder()
{
    int opcion;
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

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
        printf("Libros editados en determinado año\n");
        printf("Ingrese el año de edicion:\n");
        scanf("%s", anoEdicion);
        listarLibrosAnoEdicion(li, anoEdicion);
        break;

    case 9:
        printf("Listar autores con una determinada letra en el apellido\n");
        printf("Ingrese la letra para buscar en el apellido de los autores:\n");
        scanf("%s", letra);
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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

        while (i <= (li->len - 1))
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

        while (i <= (li->len - 1))
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
        while (i <= (li->len - 1))
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

void accederGetters(lista_cab *li)
{
    Libro libro;
    char id[15];
    char titulo[100];
    char editorial[50];
    int anoEdicion;
    int cantPaginas;
    mostrarOpcionesGetters();
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
            printf("El titulo del libro es: %s\n", titulo);
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
            li->len++;
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
                li->len++;
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
                li->len++;
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
                accederGetters(li);
            }
            break;
        case 8:
            printf("Modificar libro");
            modificadorMenu();
            modificarLibros(li);
            break;

        case 9:
            printf("Volviendo al menú principal.\n");
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
