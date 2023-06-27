#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fonctionsCinema.h"

int main()
{
    clients client[100] ;
    int choix           ;
    int i               ;
    int nbrTicket       ;


    printf   ("                      \3 Bienvenue \3                                    \n");

    service :
    AfficherLesServices() ;
    printf(" ton choix svp :   \n");
    printf("\n             ====>>>>    ");
    scanf("%d",&choix);

    switch(choix)
    {
    case 1 :
        printf  ("\t\n\n*-*-*\tveuillez saisir le nombre de tickets d้sir้ . ET Merci : \n\n");
        printf  ("จจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจจ");
        printf  ("\n             ====>>>>    ");
        scanf   ("%d",&nbrTicket);

        for(i = 0 ; i != nbrTicket ; i++)
        {

        printf  (" Nom             :   \n");
        printf  ("\n             ====>>>>    ");
        scanf   ("%s",client[i].nom);

        printf(" prenom          :   \n");
        printf("\n             ====>>>>    ");
        scanf("%s",client[i].prenom);

        printf(" age             :   \n");
        printf("\n             ====>>>>    ");
        scanf("%d",&client[i].age);

        printf(" tel             :   \n");
        printf("\n             ====>>>>    ");
        scanf("%s",client[i].tel);


        printf(" Numero du place :   \n");
        printf("\n             ====>>>>    ");
        scanf("%d",&client[i].numPlace);



        reserverUnTicket(client[i].nom ,client[i].prenom, client[i].tel , client[i].age , client[i].numPlace);
        }

        break;
    case 2 :
       // annulerUneResrvation();
        break ;
    case 3 :
         //filmsProposes();
        break ;
    case 4 :
         //modifierMaRes();
        break ;
    default :
        printf  (" \t          *******************************                      \n");
        printf  (" \t              !!!!!! Choix incorrect                           \n");
        printf  (" \t       svp ressayer un nombre entre 0 -> 4 . ET Merci          \n");
        printf  ("        ===================================================       \n");
        goto service ;
        break ;

    }






}
