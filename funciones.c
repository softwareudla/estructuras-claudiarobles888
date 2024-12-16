#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibros(struct Libro libros[], int i)
{
    int len;


    while (libros[i].id<0)
    {
        printf("ID ERROR\nIngrese el ID del libro: ");
        scanf("%d", &libros[i].id);
        if (libros[i].id>=0)
        {
            break;
        }
    }
    

    getchar();

    printf("Ingrese el titulo del libro: ");
    fgets(libros[i].titulo, 50, stdin);
    len = strlen(libros[i].titulo) - 1;
    libros[i].titulo[len] = '\0';

    printf("Ingrese el autor del libro: ");
    fgets(libros[i].autor, 50, stdin);
    len = strlen(libros[i].autor) - 1;
    libros[i].autor[len] = '\0';

    printf("Ingrese el anio de publicacion del libro: ");
    scanf("%d", &libros[i].anio_publicacion);

    strcpy(libros[i].estado, "Disponible");
}

void mostrarLibros(struct Libro libros[], int n)
{
    printf("%-10s %-20s %-20s %-10s %-10s\n", "ID", "Titulo", "Autor", "Año de publicacion", "Estado");

    for (int i = 0; i < n; i++)
    {
        if (strcmp(libros[i].estado, "Libro eliminado") != 0)
        {
            // Imprimir información del libro
            printf("%-10d %-20s %-20s %-10d %-10s\n",
                   libros[i].id,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio_publicacion,
                   libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (libros[i].id == id)
        {
            printf("Libro encontrado:\n");
            printf("%-10d %-20s %-20s %-10d %-10s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio_publicacion, libros[i].estado);
            return;
        }
    }
    printf("Libro con ID %d no encontrado.\n", id);
}

void buscarLibroTitulo(struct Libro libros[], int numLibros, const char *titulo)
{
    for (int i = 0; i < numLibros; i++)
    {
        if (strcasecmp(libros[i].titulo, titulo) == 0)
        {
            printf("\nLibro encontrado:\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio_publicacion, libros[i].estado);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void actualizarEstadoLibro(struct Libro libros[], int numLibros, int id)
{
    int opcion;
    for (int i = 0; i < numLibros; i++)
    {
        if (libros[i].id == id)
        {
            printf("Libro encontrado:\n");
            printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado actual: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio_publicacion, libros[i].estado);

            printf("Ingrese el nuevo estado del libro:\n");
            printf("1. Disponible\n");
            printf("2. No disponible\n");
            printf("3. Reservado\n");
            printf("4. Prestado\n");
            printf ("Ingrese el estado del libro que desea actualizar: ");
            scanf ("%d", &opcion);

            switch (opcion)
            {
            case 1:
                strcpy(libros[i].estado, "Disponible");
                printf("El estado se actulizo a: Disponible\n");
                break;
            case 2:
                strcpy(libros[i].estado, "No disponible");
                printf("El estado se actulizo a: No disponible\n");
                break;
            case 3:
                strcpy(libros[i].estado, "Reservado");
                printf("El estado se actulizo a: Reservado\n");
                break;
            case 4:
                strcpy(libros[i].estado, "Prestado");
                printf("El estado se actulizo a: Prestado\n");
                break;
            default:
                printf("Opción no válida. No se realizó ningún cambio.\n");
                return;
                break;
            }
            return;
        }
        else
        {
            printf("Libro con ID %d no encontrado.\n", id);
        }
    }
}

void eliminarLibro(struct Libro libros[], int numLibros, int id)
{
    for (int i = 0; i < numLibros; i++)
    {
        if (libros[i].id == id)
        {
            printf("Libro a eliminar encontrado");
            printf("ID: %d\nTitulo: %s\nAutor: %s\nAnio de publicacion: %d\nEstado: %s", libros[i].id, libros[i].autor, libros[i].anio_publicacion, libros[i].estado);
            strcpy(libros[i].estado, "Libro eliminado");
            printf("El libro con ID %d ha sido eliminado exitosamente\n", id);
            return;
        }
    }
    printf("Libro con ID %d no encontrado", id);
}
