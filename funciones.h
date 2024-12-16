#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Libro 
{
    int id;
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    char estado[20]; 
};

void registrarLibros(struct Libro libros[], int i);
void mostrarLibros(struct Libro libros[], int n);
void buscarLibroId(struct Libro libros[], int n, int id);
void buscarLibroTitulo(struct Libro libros[], int numLibros, const char *titulo);
void actualizarEstadoLibro(struct Libro libros[], int numLibros, int id);
void eliminarLibro(struct Libro libros[], int numLibros, int id);


#endif
