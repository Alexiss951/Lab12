#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>

int vali_num3(int ri, int rf, char *msge, char *msge2, char *msge3)
{
    char xnum[30];
    int num;
    do
    {
        system("CLS");
        printf("%s\n", msge3);
        printf("%s", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    } while (num < ri || num > rf);
    return num;
}

int vali_num4(int ri, int rf, char *msge, char *msge2, int dif)
{
    char xnum[30];
    int num;
    do
    {
        system("CLS");
        printf("%s", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf || strlen(xnum) != dif)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    } while (num < ri || num > rf || strlen(xnum) != dif);
    return num;
}

int vali_num(int ri, int rf, char *msge, char *msge2)
{
    char xnum[30];
    int num;
    do
    {
        system("CLS");
        printf("%s", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    } while (num < ri || num > rf);
    return num;
}

void ordenar(int vect[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = (i + 1); j < n; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

int busq_seq(int vect[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vect[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int largo_cadena(char caracf[30])
{
    int i;
    i = 0;
    while (caracf[i] != '\0')
    {
        i++;
    }
    return i;
}

void mayusculas(char carac[30], int n, int o)
{
    int i;
    char copia[30];
    strcpy(copia, carac);
    for (i = 0; i < n; i++)
    {
        if (copia[i] >= 'a')
        {
            if (copia[i] <= 'z')
            {
                copia[i] = copia[i] - 32;
            }
        }
    }
    copia[n] = '\0';
    if (o == 1)
    {
        strcpy(carac, copia);
    }
}

void vali_cad(char carac[30], char *msge)
{
    int n, i, largo, letra;
    letra = 164;

    do
    {
        system("CLS");
        i = 0;
        n = 0;
        printf("%s\nEn caso de que su nombre lleve %c tendra que cambiarla por una X,(en vez de nu%ces, sera nuxes) ", msge, letra, letra);
        fflush(stdin);
        gets(carac);
        largo = largo_cadena(carac);
        carac[largo] = '\0';
        if (carac[0] == ' ' || carac[largo - 1] == ' ')
        {
            n = 1;
        }
        if (n == 0)
        {
            do
            {
                if (carac[i] < 'A')
                {
                    if (carac[i] != ' ')
                    {
                        if (carac[i] != '/')
                        {
                            if (carac[i] != '.')
                            {
                                if (carac[i] != '-')
                                {
                                    n = 1;
                                    carac[i] = '\0';
                                }
                            }
                        }
                    }
                }
                if (carac[i] > 'Z')
                {
                    if (carac[i] < 'a')
                    {
                        n = 1;
                        carac[i] = '\0';
                    }
                }

                if (carac[i] > 'z')
                {
                    n = 1;
                    carac[i] = '\0';
                }
                if (carac[i] == ' ')
                {
                    if (carac[i + 1] == ' ')
                    {
                        n = 1;
                        carac[i] = '\0';
                    }
                }
                i++;
            } while (carac[i] != '\0');
            mayusculas(carac, largo, 1);
            if (n == 1)
            {
                printf("\nFavor de seguir las instrucciones proporcionadas\n");
                system("PAUSE");
            }
        }
        else
        {
            printf("\nNi el primer caracter ni el ultimo pueden ser espacio");
            system("PAUSE");
        }
    } while (n != 0);
}

int vali_num2(int ri, int rf, char *msge, char *msge2, char xnum[30], int min)
{
    int num;
    do
    {
        system("CLS");
        printf("%s", msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf || strlen(xnum) != min)
        {
            printf("\n%s \n", msge2);
            system("PAUSE");
        }
    } while (num < ri || num > rf || strlen(xnum) != min);
    return num;
}

int vali_vec(int vec[11], int x, int j)
{
    int i;
    for (i = 0; i < j; i++)
    {
        if (vec[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

void lee_cad(char nomb[30], char *msge)
{
    int tecla, i, esp, arre;
    esp = 1;
    do
    {
        printf("%s \n", msge);
        i = 0;
        do
        {
            tecla = getch();
            tecla = toupper(tecla);
            if (isalpha(tecla))
            {
                printf("%c", tecla);
                nomb[i] = tecla;
                esp = 0;
                i++;
            }
            else
            {
                if (tecla == 32)
                {
                    if (esp == 0)
                    {
                        printf("%c", tecla);
                        nomb[i] = tecla;
                        esp = 1;
                        i++;
                    }
                }
                else
                {
                    if (tecla == 39 || tecla == 45 || tecla == 46 || tecla == 47)
                    {
                        printf("%c", tecla);
                        nomb[i] = tecla;
                        esp = 0;
                        i++;
                    }
                }
            }
            if (tecla == 13)
            {
                if (esp == 1)
                {
                    tecla == 39;
                }
            }

        } while (tecla != 13);
        arre = vali_num3(1, 2, "Asi se escribe el nombre?\n1-->No\n2-->Si ", "Esa opcion no es valida", nomb);

    } while (arre == 1);
}

void lee_cad2(char nomb[30], char *msge)
{
    int tecla, i, esp, arre;
    esp = 1;
    do
    {
        printf("%s \n", msge);
        i = 0;
        do
        {
            tecla = getch();
            tecla = toupper(tecla);
            if (isalpha(tecla))
            {
                printf("%c", tecla);
                nomb[i] = tecla;
                esp = 0;
                i++;
            }
            else
            {
                if (tecla == 32)
                {
                    if (tecla == 95 || tecla == 45 || tecla == 47)
                    {
                        printf("%c", tecla);
                        nomb[i] = tecla;
                        esp = 0;
                        i++;
                    }
                }
            }

        } while (tecla != 13);
        arre = vali_num3(1, 2, "Asi quieres nombrar el archivo?\n1-->No\n2-->Si ", "Esa opcion no es valida", nomb);

    } while (arre == 1);
}