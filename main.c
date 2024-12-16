#include <stdio.h>
#include "funciones.h"

int main()
{

    struct Libro libros[20];
    int opc;
    int i = 0;
    int id;

    char titulo[100];
    do
    {
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Buscar libro por título\n");
        printf("5. Actualizar estado de un libro\n");
        printf("6. Eliminar libro\n");
        printf("Ingrese la opcion a realizar: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            registrarLibros(libros, i);
            i++;
            break;
        case 2:
            mostrarLibros(libros, i);
            break;
        case 3:
            printf("Ingrese el id del libro a buscar: ");
            scanf("%d", &id);
            buscarLibroId(libros, i, id);
            break;
        case 4:
            printf("Ingrese el titulo del libro a buscar: ");
            scanf("%s", titulo);
            buscarLibroTitulo(libros, i, titulo);
            break;
        case 5:
            printf("Ingrese el id del libro cuyo estado desea actualizar: ");
            scanf("%d", &id);
            actualizarEstadoLibro(libros, i, id);
            break;
        case 6:
            printf("Ingrese el id del libro cuyo estado desea eliminar: ");
            scanf("%d", &id);
            eliminarLibro(libros, i, id);
            break;
        default:
            printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opc != 7);

    return 0;
}
