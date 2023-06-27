#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
//#include <windows.h>
//#define pi 3.14
#define T_M 100
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include "fonction imp.h "


typedef struct Cellule Cellule ;
typedef struct Liste Liste ;

struct Cellule {
    int data ;
    Cellule *suivant ;

};

struct Liste{

    Cellule *premier;
};

Liste *initialisation()
{
    Liste* liste = malloc(sizeof(Liste));
    Cellule* cellule = malloc(sizeof(Cellule));

    if(cellule != NULL && liste != NULL)
    {
        (*cellule).data = 0 ;
        (*cellule).suivant = NULL ;
        (*liste).premier = cellule ;

    }
    else
        exit(EXIT_FAILURE);
    return cellule ;
}

void ajoutD (Liste* liste , int nbr)
{
    Cellule* el = malloc(sizeof(Cellule));
    if(el!= NULL && liste != NULL)
    {
        (*el).data = nbr ;
        (*el).suivant = (*liste).premier;
        (*liste).premier = el ;
    }
    else
        exit(EXIT_FAILURE);
}

void affichage(Liste* liste)
{
    if(liste!= NULL)
    {
        Cellule* p = (*liste).premier;
        while(p!= NULL)
        {
            printf("%d -- = ",(*p).data);
            p = (*p).suivant;
        }
        printf("NULL\n");
    }
    else
        exit(EXIT_FAILURE);
}

void supD(Liste* liste )
{
    if(liste != NULL)
    {
        Cellule* asupp ;
        if((*liste).premier != NULL)
        {
            asupp = (*liste).premier ;
            (*liste).premier = (*asupp).suivant ;
            free(asupp);
        }
        else
            printf("laliste est vide ");
    }
    else
        exit(EXIT_FAILURE);
}

void insF(Liste*  liste , int nbr )
{
    Cellule* el = malloc(sizeof(Cellule));

    if(el != NULL)
    {
        (*el).data = nbr ;
        (*el).suivant = NULL;
        if(liste == NULL)
            liste = el;
        else
        {
            Cellule* p = (*liste).premier;
            while(p!= NULL)
                p = (*p).suivant ;
            (*p).suivant = el ;
        }
    }
    else
        exit(EXIT_FAILURE);
}





int main()
{



}



