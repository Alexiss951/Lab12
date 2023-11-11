//Sanchez Santos B. Alexis 367714
//11/NOVIEMBRE/2023
//CREAR, SOBRESCRIBIR Y/O CARGAR ARCHIVOS CON INFOMACION CREADA AUTOMATICAMENTE O CON INFORMACION MODIFICADA
//ARCHIVOS Y BANDERAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "libreria.h"

typedef struct _alum
{
    int status;
    int matricula;
    char appat[30];
    char apmat[30];
    char nombre[30];
    char genero[10];
    int edad;
} Talum;

int lee_arch(Talum vect[1500], int i, int banda);
int genreg(Talum vect[1500], int i);
int vali_vec2(Talum vect[1500], int x, int j);
void eliminar(Talum vect[1500], int i);
int busq_seq2(Talum vect[1500], int n, int num);
int ordenado(Talum vect[1500], int n, int bandera);
void impreg(Talum vect[1500], int inicio, int bande);
void nombarch(char nomb[30]);
void created(Talum vect[1500], int i, char nomb[30]);
void createdf(Talum vect[1500], int i);

int main()
{
    Talum vct[1500];
    srand(time(NULL));
    int opc, subopc, i, encontrar, matro, bandera, banda, nombre, tipo;
    char archivo[30];
    i = 0;
    nombre = 0;
    banda = 0;
    bandera = 0;
    tipo = 0;
    system("CLS");
    do
    {
        subopc = vali_num(0, 8, "Elige una opcion\n1-->Cargar archivo\n2-->Agregar\n3-->Eliminar\n4-->Buscar\n5-->Ordenar\n6-->Mostrar todo\n7-->Generar archivo\n8-->Registros borrados ", "Esa opcion no es valida");
        switch (subopc)
        {
        case 1:
            i = lee_arch(vct, i, banda);
            banda = 1;
            bandera = 0;
            break;
        case 2:
            i = genreg(vct, i);
            bandera = 0;
            break;
        case 3:
            eliminar(vct, i);
            break;
        case 4:
            matro = vali_num4(300000, 399999, "Que matricula buscas? \nRecuerda que la matricula va de 300000 a 399999 ", "Esa matricula no es valida o agrego 0s a la izquierda", 6);
            encontrar = busq_seq2(vct, i, matro);
            if (encontrar != -1)
            {
                printf("\nLa matricula: %d esta en la posicion %d \n", matro, encontrar);
                system("PAUSE");
            }
            else
            {
                printf("Esa matricula no existe\n");
                system("PAUSE");
            }
            break;
        case 5:
            bandera = ordenado(vct, i, bandera);
            break;
        case 6:
            tipo = 1;
            impreg(vct, i, tipo);
            break;
        case 7:
            if (nombre == 0)
            {
                nombarch(archivo);
                nombre = 1;
            }
            created(vct, i, archivo);
            system("PAUSE");
            break;
        case 8:
            tipo = 2;
            impreg(vct, i, tipo);
            break;
        default:
            createdf(vct, i);
            printf("Adios,se creo un archivo con los registros que diste de baja...");
            break;
        }
    } while (subopc != 0);
    return 0;
}

int lee_arch(Talum vect[1500], int i, int banda)
{
    Talum reg;
    FILE *fa;
    char basu;
    system("cls");
    if (banda == 0)
    {
        fa = fopen("datos.txt", "r");
        if (fa)
        {
            do
            {
                fscanf(fa, "%d %d %s %s %s %d %s", &basu, &reg.matricula, &reg.nombre, &reg.appat, &reg.apmat, &reg.edad, &reg.genero);
                reg.status = 1;
                vect[i++] = reg;

            } while (!feof(fa));
            fclose(fa);
            printf("archivo cargado\n");
            system("PAUSE");
        }
    }
    else
    {
        printf("El archivo ya estaba cargado\n");
        system("PAUSE");
    }
    return i;
}

int genreg(Talum vect[1500], int i)
{
    Talum reg;
    char nombresm[][20] = {{"GIDEON"}, {"OFNIR"}, {"GODWYN"}, {"GODFREY"}, {"RADAGON"}, {"ALEXANDER"}, {"KALE"}, {"GODRIK"}, {"ROGIER"}, {"THOPS"}, {"KENNETH"}, {"SELUVIS"}, {"RYKARD"}, {"RADAHN"}, {"PARCHES"}, {"MORGOTT"}, {"MOHG"}, {"MALIKETH"}, {"MARGIT"}, {"HEWG"}, {"IJI"}, {"BLAIDD"}, {"MIRIEL"}, {"VARRE"}, {"YURA"}, {"CORHYM"}, {"AZUR"}, {"GOWRY"}};
    char nombresf[][20] = {{"FIA"}, {"SELLEN"}, {"HYETTA"}, {"IRINA"}, {"TANITH"}, {"RYA"}, {"RODERIKA"}, {"RENNALA"}, {"MARIKA"}, {"RANNI"}, {"NEPHELI"}, {"MIQUELLA"}, {"MILICENT"}, {"MELINA"}, {"MALENIA"}, {"LATENNA"}, {"ISIDORA"}, {"ANTONELA"}, {"EMILIA"}, {"MADISON"}, {"AVA"}, {"OLIVIA"}, {"ISABELA"}, {"EMMA"}, {"SOPHIA"}, {"ELIZABETH"}, {"ELENA"}, {"SAMARA"}};
    char apellidos[][20] = {{"SODEBERG"}, {"MIKKONEN"}, {"WALLGREN"}, {"HEGG"}, {"GEMBALLA"}, {"HELDEN"}, {"SCHLEGEL"}, {"GREYWOLF"}, {"DORN"}, {"FALCONCINI"}, {"FILIA"}, {"CAVALIERI"}, {"HOGLAN"}, {"WALTS"}, {"ALATRIZ"}, {"GONTIER"}, {"BASS"}, {"KERCH"}, {"SHADOWS"}, {"CRAHAN"}, {"JORDISON"}, {"FAGENSON"}, {"SOUZA"}, {"MOMSEN"}, {"ROSES"}, {"OSBORNE"}, {"TAYLOR"}, {"BLINK"}, {"FORGE"}, {"MAY"}, {"DEACON"}, {"LEE"}, {"DRAIMAN"}, {"DONEGAN"}, {"MOYER"}, {"HARRIS"}, {"MURRAY"}};
    int gen, rango, rango2, j, matro, subopc;
    j = 0;
    rango2 = 60 - 18;
    system("CLS");
    while (j < 10 && i < 1500)
    {
        reg.status = 1;
        gen = rand() % 2;
        if (gen == 0)
        {
            strcpy(reg.genero, "MASCULINO");
            strcpy(reg.nombre, nombresm[rand() % 28]);
        }
        else
        {
            strcpy(reg.genero, "FEMENINO");
            strcpy(reg.nombre, nombresf[rand() % 28]);
        }
        strcpy(reg.appat, apellidos[rand() % 37]);
        strcpy(reg.apmat, apellidos[rand() % 37]);
        reg.edad = (rand() % rango2) + 18;
        do
        {
            matro = (rand() % rango) + 300000;
            subopc = vali_vec2(vect, matro, i);
            if (subopc == 0)
            {
                reg.matricula = matro;
            }

        } while (subopc == 1);
        vect[i] = reg;
        i++;
        j++;
    }
    printf("\nSe han agregado correctamente 10 registros\n");
    system("PAUSE");

    return i;
}

int vali_vec2(Talum vect[1500], int x, int j)
{
    int i;
    for (i = 0; i < j; i++)
    {
        if (vect[i].matricula == x)
        {
            return 1;
        }
    }
    return 0;
}

void eliminar(Talum vect[1500], int i)
{
    system("CLS");
    printf("\nEliminacion ");
    int num, encontrado, opc;
    num = vali_num4(300000, 399999, "Que matricula quieres eliminar? \nRecuerda que la matricula va de 300000 a 399999 ", "Esa matricula no es valida o agrego 0s a la izquierda", 6);
    encontrado = busq_seq2(vect, i, num);
    if (encontrado == -1)
    {
        printf("\nEsa matricula no esta en el sistema\n");
        system("PAUSE");
    }
    else
    {
        opc = vali_num(1, 2, "Registro encontrada, ¿Quieres eliminarlo?\n1-->No\n2-->Si ", "Esa opcion no es valida");
        if (opc == 2)
        {
            vect[encontrado].status = 0;
            printf("\nRegistro eliminado\n");
            system("PAUSE");
        }
        else
        {
            printf("\nNo se a eliminado\n");
            system("PAUSE");
        }
    }
}

int busq_seq2(Talum vect[1500], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i].matricula == num)
        {
            return i;
        }
    }
    return -1;
}

int ordenado(Talum vect[1500], int n, int bandera)
{
    int i, j;
    Talum temp;
    system("CLS");
    if (bandera == 0)
    {
        for (i = 0; i < (n - 1); i++)
        {
            for (j = (i + 1); j < n; j++)
            {
                if (vect[j].matricula < vect[i].matricula)
                {
                    temp = vect[i];
                    vect[i] = vect[j];
                    vect[j] = temp;
                }
            }
        }
        printf("ORDENADO\n");
        system("PAUSE");
    }
    else
    {
        printf("Ya esta ordenado\n");
        system("PAUSE");
    }
    return 1;
}

void impreg(Talum vect[1500], int inicio, int bande)
{
    int i;
    system("CLS");
    printf("IMPRESION\n");
    if (bande == 1)

    {
        printf("Registros validos\n");
        printf("   MATRICULA   NOMBRE  APPATERNO  APMATERNO EDAD    SEXO\n");
        for (i = 0; i < inicio; i++)
        {
            if (vect[i].status == 1)
            {
                printf("%4d %d %9s %10s %10s %3d %9s\n", i, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].genero);
            }
            if (i % 40 == 0)
            {
                printf("\n\n");
            }
        }
    }
    else
    {
        printf("Registros eliminados\n");
        printf("   MATRICULA   NOMBRE  APPATERNO  APMATERNO EDAD    SEXO\n");
        for (i = 0; i < inicio; i++)
        {
            if (vect[i].status == 0)
            {
                printf("%4d %d %9s %10s %10s %3d %9s\n", i, vect[i].matricula, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].genero);
            }
            
        }
    }

    system("PAUSE");
}

void nombarch(char nomb[30])
{
    int largo;
    lee_cad2(nomb, "Como quieres nombrar el archivo?");
    largo = largo_cadena(nomb);
    nomb[largo] = '.';
    nomb[largo + 1] = 't';
    nomb[largo + 2] = 'x';
    nomb[largo + 3] = 't';
    nomb[largo + 4] = '\0';
}

void created(Talum vect[1500], int i, char nomb[30])
{
    FILE *fa;
    int j;
    fa = fopen(nomb, "w");
    for (j = 0; j < i; j++)
    {
        if (vect[j].status == 1)
        {
            fprintf(fa, "%4d %d %9s %10s %10s %3d %9s\n", j, vect[j].matricula, vect[j].nombre, vect[j].appat, vect[j].apmat, vect[j].edad, vect[j].genero);
        }
        if (j % 40 == 0)
        {
            fprintf(fa, "\n\n");
        }
    }
    fclose(fa);
}

void createdf(Talum vect[1500], int i)
{
    FILE *fa;
    int j;
    fa = fopen("Baja.txt", "w");
    for (j = 0; j < i; j++)
    {
        if (vect[j].status == 0)
        {
            fprintf(fa, "%4d %d %9s %10s %10s %3d %9s\n", j, vect[j].matricula, vect[j].nombre, vect[j].appat, vect[j].apmat, vect[j].edad, vect[j].genero);
        }
        if (j % 40 == 0)
        {
            fprintf(fa, "\n\n");
        }
    }
    fclose(fa);
}