#ifndef FONCTION_IMP_H_INCLUDED
#define FONCTION_IMP_H_INCLUDED

typedef struct Element Element ;
typedef struct Controle Controle ;

struct Element
{
    int data ;
    Element* suivant ;
};

struct Controle
{
    Element* premier ;
};


Controle* initialisation()
{
   Element*  element = malloc(sizeof(Element));
   Controle* controle = malloc(sizeof(Controle));

   if(controle == NULL || element == NULL)
        exit(EXIT_FAILURE);

   (*element).data = 0 ;
   (*element).suivant = NULL ;
   (*controle).premier = element ;

   return controle ;

}

void insertionDebut (Controle* controle , int nouveau_element)
{
    Element* nv_ele = malloc(sizeof(Element));

    if(nv_ele != NULL && controle != NULL)

{
    (*nv_ele).data = nouveau_element ;
    (*nv_ele).suivant = (*controle).premier ;
    (*controle).premier = nv_ele ;
}
    else
        exit(EXIT_FAILURE);

}

void supprimerDebut ( Controle* controle)
{
     if (controle == NULL)
        exit(EXIT_FAILURE);

     Element* asupp ;
     if((*controle).premier != NULL)
     {
         asupp = (*controle).premier ;
        (*controle).premier = (*asupp).suivant ;
         free(asupp);
     }

}

void afficher ( Controle* controle )
{
    Element *actuel ;
     if (controle == NULL)
        exit(EXIT_FAILURE);

    actuel = (*controle).premier ;
    while(actuel != NULL)
    {
        printf("%d -- ",(*actuel).data);
        actuel = (*actuel).suivant ;
    }
    printf("NULL");

}

void insertionFin (Controle* controle , int nv_nbr)
{
    Element *nv_ele , *p ;

    nv_ele = malloc(sizeof(Element));

     if(controle == NULL || nv_ele == NULL)
        exit(EXIT_FAILURE);

     (*nv_ele).data = nv_nbr;
     (*nv_ele).suivant = NULL ;



     if(controle == NULL)
        controle = nv_ele;
     else
     { p = (*controle).premier ;
     while(p != NULL)
        p = (*p).suivant ;
     (*p).suivant = nv_ele ;
     }

}


#endif // FONCTION_IMP_H_INCLUDED
