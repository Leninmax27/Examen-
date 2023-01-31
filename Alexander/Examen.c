#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
    char cedula[20];
    char nombres[20];
    char apellidos[20];
    };


void ingresarDatosEmpleado(struct registro *e){
    printf("Ingresa el numero de cedula: ");
    scanf("%s", e->cedula);
    printf("Ingresa los nombres: ");
    scanf("%s", e->nombres);
    printf("Ingresa los apellidos: ");
    scanf("%s", e->apellidos);
}


void guardarDatosEmpleado(struct registro *e){
    FILE *archivo;
    archivo = fopen("empleados.txt","a");
    fprintf(archivo, "%s %s %s\n", e->cedula , e->nombres, e->apellidos);
    fclose(archivo);
}


void buscarDatosEmpleado(char cedula[20]){
    FILE *archivo;
    archivo = fopen("empleados.txt","r");
    char linea[60];
    int encontrado = 0;
    while(fgets(linea, 60, archivo)){
        char *em = strtok(linea, " ");
        if(strcmp(em, cedula) == 0){
            encontrado = 1;
            printf("Los datos del empleado son: \n");
            printf("Numero de cedula: %s\n", em);
            em = strtok(NULL, " ");
            printf("Nombres: %s\n", em);
            em = strtok(NULL, "\n");
            printf("Apellidos: %s\n", em);
            break;
        }
    }
    if(encontrado == 0){
        printf("No se encontraron los datos del empleado\n");
    }
    fclose(archivo);
}


int main(){
    int opcion;
    char cedula[20];
    struct registro e;
    printf("Sistema de registro de talento humano\n");
    do{
        printf("\nSelecciona una opcion \n");
        printf("1. Desea ingresar datos del empleado \n");
        printf("2. Desea buscar datos del empleado \n");
        printf("3. Salir \n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                ingresarDatosEmpleado(&e);
                guardarDatosEmpleado(&e);
                break;
            case 2:
                printf("Ingresa el numero de cedula : ");
                scanf("%s", cedula);
                buscarDatosEmpleado(cedula);
                break;
            case 3:
                printf("Gracias por utilizar el sistema\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(opcion != 3);
    return 0;
}







 




 

