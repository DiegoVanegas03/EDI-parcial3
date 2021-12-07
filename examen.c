#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

    char nombre[40];
    char pais[25];

}DatosPersonales;

typedef struct{
    DatosPersonales datos;
    char deporte[30];
    int numMedallas;

}Deportista;

void FuncionDeLectura(FILE *archivo, Deportista deportistas[100]);
void FuncionCOntadoraDeMedallas(Deportista deporstistas[100]);

int main()
{
    FILE *archivo;
    Deportista deportistas[100];
    
    FuncionDeLectura(&archivo, deportistas);
    FuncionCOntadoraDeMedallas(deportistas);

    system("pause");
    return 0;
}

void FuncionDeLectura(FILE *archivo, Deportista deportistas[100])
{
    int cerrado;
    fopen("deportistas.txt", "r");
    for (int i = 0; i < 100; i++)
    {
        fscanf(archivo, "%s", deportistas[i].datos.nombre);
        fscanf(archivo, "%s", deportistas[i].datos.pais);
        fscanf(archivo, "%s", deportistas[i].deporte);
        fscanf(archivo, "%d", deportistas[i].numMedallas);
    }
    
    cerrado = fclose(archivo);
}

void FuncionCOntadoraDeMedallas(Deportista deporstistas[100])
{
    int numNat, numAtle, numCi, numGim, numEqu, numEs;
    for (int i = 0; i < 100; i++)
    {
        switch (*deporstistas[i].deporte)
        {
        case 'Natación':
         numNat = numNat + 1;
            break;
        case 'Atletismo':
            numAtle = numAtle + 1;
            break;
        case 'Ciclismo':
            numCi = numCi + 1;
            break;
        case 'Gimnasia':
            numGim = numGim + 1;
            break;
        case 'Equitacion':
            numEqu = numEqu + 1;
            break;
        case 'Esgrima':
            numEs = numEs + 1;
            break;
        default:
            break;
        }
    } 

    printf("%d medallas de Natacion", numNat);
    printf("%d medallas de Atletismo",numAtle);
    printf("%d medallas de Ciclismo",numCi);
    printf("%d medallas de Gimnasia",numGim);
    printf("%d medallas de Equitacion",numEqu);
    printf("%d medallas de Esgrima",numEs);
}