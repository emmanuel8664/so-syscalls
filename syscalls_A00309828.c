#include <errno.h>
#include <stdio.h>
#include <unistd.h>


/*Se debe ingresar el archivo como parametro para conocer sus permisos */
int main (int argc, char* argv[])
{
    /*El primer argumento se guarda en path*/
    char* path = argv[1];

    /*Sirve para verificar los permisos de un archivo */
    int valorPrueba;
    /* Chequear existencia del archivo.*/
    valorPrueba = access (path, F_OK);

     /*En caso de no encontrar problemas al acceder a un archivo*/
    if (valorPrueba == 0) 
        printf ("%s el archivo o directorio existe\n", path);
     /*En caso de encontrar un problema al acceder al archivo*/       
    else {
        if (errno == ENOENT) 
            printf ("%s El archivo o directorio no existe (or Error NO ENTity)\n", path);
        else if (errno == EACCES) 
            printf ("%s Permiso denegado para acceder al archivo o directorio\n", path);
        return 0;
    }
    /* Chequear permiso de lectura. */
    valorPrueba = access (path, R_OK);

    /* En caso de tener permisos de lectura. */
    if (valorPrueba == 0)
        printf ("%s tiene permiso de lectura\n", path);
    else
        printf ("%s no tiene permiso de lectura (acceso denegado)\n", path);
    
    /* Chequear permiso de escritura. */
    valorPrueba = access (path, W_OK);

    /* En caso de tener permisos de escritura. */
    if (valorPrueba == 0)
        printf ("%s tiene permiso de escritura\n", path);
    else if (errno == EACCES)
        printf ("%s no tiene permiso de escritura (acceso denegado)\n", path);
    else if (errno == EROFS)
        printf ("%s no tiene permiso de escritura (solo lectura)\n", path);
    return 0;
}