 #include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "fonctionsCinema.h"


int main()
{
    clients client[100]        ;
    int choix2,choix1,choix3   ;
    int i   ,  c               ;
    int nbrTicket              ;
    int numPlace     ,prix     ;
    int nbrTentation = 0       ;
    char telSearch[20]         ;
    int modi , *p              ;
    char Pass[11],chaine[11]   ;
    char film[20] ;

    //system("cls");


    printf   ("                                                                                                               \n");
    printf   ("                                                                                                              \n");
    printf   ("                                                                                                              \n");
    printf   ("                                                                                                             \n");
    printf   ("                                                                                                             \n");
    printf   ("                                        \3 Bienvenue sur MOVIE PLANET  \3                                    \n");
    printf   ("                                                                                                             \n");
    printf   ("                                                                                                              \n");
    Sleep(2000);
    system("cls");

    printf   ("                                                                                                               \n");
    printf   ("                                                                                                              \n");
    printf   ("                             Le film propos%c par notre cin%cma cette semaine est :                                                         \n",130,130);

    printf   ("                                                                                                             \n");
    printf   ("                                                                                                             \n");
    printf   ("                                             \3  S C R E A M  \3                                               \n",film);
    printf   ("                                                                                                             \n");
    printf   ("                                                                                                              \n");
    Sleep(2000);
    system("cls");
    mode :
    LesModes();


    printf(" Veuillez saisir le num%cro correspendant %c votre choix  :   \n",130,133);
    printf("\n             ====>>>>    ");
    scanf("%d",&choix1);
    //getch();
    system("cls");


    if(choix1 == 1)
{
    service :
        AfficherLesServices() ;
        printf(" Veuillez saisir le num%cro correspendant %c votre choix  :   \n",130,133);
        printf("\n             ====>>>>    ");
        scanf("%d",&choix2);
        system("cls");

    switch(choix2)
    {
    case 1 :

        printf  ("\t\n\n*-*-*\tVeuillez saisir le nombre de tickets d%csir%c . ET Merci : \n\n",130,130);
        printf  ("\t            ====>>>>    ");
        scanf   ("%d",&nbrTicket);
        printf  ("\t\n**************************************************************************\n\n");
        for(i = 0 ; i != nbrTicket ; i++)
        {
            printf  ("Veuillez saisir votre nom svp         :   \n");
            printf  ("\t            ====>>>>    ");
            scanf   ("%s",client[i].nom);

            printf  (" Veuillez saisir votre pr%cnom        :   \n",130);
            printf  ("\t            ====>>>>    ");
            scanf   ("%s",client[i].prenom);

            printf  (" Veuillez saisir votre age           :   \n");
            printf  ("\t             ====>>>>    ");
            scanf   ("%d",&client[i].age);
            if(client[i].age < 12 /*|| client[i].age < 0*/ )
            {
                printf("\t\n\n*-*-*\t Le film propos%c ne convient pas aux spectateurs ayant un age inf%crieur a 12ans. \n\n",130,130);
                printf(" \n-/**/**/- Tapez pour continuer  .\n\n   ");
                getch();
                //system("cls");

                //goto rep ;
            }

            else
            {
            printf  (" Veuillez saisir votre num%cro de t%cl%cphone:   \n",130,130,130);
            printf  ("\t             ====>>>>    ");
            scanf   ("%s",client[i].tel);


            printf(" Veuillez saisir le num%cro de la place que vous souhaitez r%cserver :   \n",130);
            printf("\t            ====>>>>    ");
            scanf ("%d",&client[i].numPlace);
            testCode( client[i].numPlace ) ;


            if( testCode( client[i].numPlace ) == 0 && client[i].numPlace <= 100 && 0 < client[i].numPlace )
                {
                reserver(client[i].nom ,client[i].prenom, client[i].tel , client[i].age , client[i].numPlace);
                printf ("\n Cher(e) %s %s ,\n",client[i].prenom,client[i].nom);
                printf("Le num%cro de votre place est %d . Et Merci\n\n",130,client[i].numPlace);
                //Recu(client[i].numPlace);
                if(i + 1 < nbrTicket)
                {
                     printf(" \n-/**/**/- Tapez pour r%cs%crv%ce . Et Merci\n\n   ",130,130,130);
                     getch();
                     system("cls");
                }
                }

            else if (testCode( client[i].numPlace ) == 1 && client[i].numPlace <= 100 )
                {printf("\t\n\n*-*-*\tCette place est d%cj%c r%cs%crv%ce . Et Merci\n\n",130,133,130,130,130);
                break ;}

            else
            {printf("\t\n\n*-*-*\tLe nombre des places est limit%c %c 100 places (1 -> 100). \n\n",130,133);
            break ;}
            }

        }

        printf(" \n-/**/**/- Tapez pour continuer . Et Merci\n\n   ");
        getch();
        system("cls");

        goto service ;



        break ;

    case 2 :
       printf  ("\t\n\n*-*-*\tVeuillez entrer le num%cro de votre place . ET Merci :  ",130);
       printf("\n             ====>>>>    ");
       scanf("%d",&numPlace);
       //printf("\n ex = %d\n",testCode(numPlace));
       if(testCode( numPlace ) == 1   )
       {
          annullerUneResrvation(numPlace);
          printf("\t\n\n*-*-*\tAnnullation confirm%ce . Et Merci\n\n",130);
       }
       else if(numPlace > 100 || 0 > numPlace )
          printf("\t\n\n*-*-*\tLe nombre des places est limit%c a 100 places (1 -> 100) . Et Merci\n\n",130);
       else
          printf("\t\n\n*-*-*\tCette place n'est pas encore r%cs%crv%ce .\n\n",130,130,130);


        printf(" \n-/**/**/- Tapez pour continuer . Et Merci\n\n   ");
        getch();
        system("cls");

       goto service ;
       break ;
    case 3 :
       printf("cher(e) , \n");
       printf  ("\t\n\n*-*-*\tVeuillez entrer svp votre num%cro de t%cl%cphone : \n\n",130,130,130);
       printf("\n             ====>>>>    ");
       scanf("%s",telSearch);
       afficherNumDuPlace(telSearch);
       printf(" \n-/**/**/- Tapez pour continuer . Et Merci\n\n   ");
       getch();
       system("cls");
       goto service ;

    case 4 :
    printf  ("\t\n\n*-*-*\tVeuillez saisir le num%cro de votre place  : \n\n",130);
    printf("\n             ====>>>>    ");
    scanf("%d",&numPlace);
    //printf("\n ex = %d\n",testCode(numPlace));
    if(testCode( numPlace ) == 1 && numPlace <= 100 && 0 < numPlace )
    {
        printf  ("\t\n\n*-*-*\tVeuillez modifier vos informations :   \n");
        printf  ("\t\t\t [1].nom\n");
        printf  ("\t\t\t [2].prenom\n");
        printf  ("\t\t\t [3].age\n");
        printf  ("\t\t\t [4].telephone\n");
        printf  ("\t\t\t [5].num%cro de la place souhait%c",130,130);
        printf  ("\t\n\n*-*-*\tchoix :   ");
        scanf  ("%d",&c);
        system("cls");
         switch(c){
        case 1 :
            modifierNom(numPlace);
            printf  ("\t\n\n*-*-*\tLa modification a %ct%c %cff%cctu%ce  : \n\n",130,130,130,130,130);
            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
            goto service ;
        case 2 :
            modifierPrenom(numPlace);
            printf  ("\t\n\n*-*-*\tLa modification a %ct%c %cff%cctu%ce  : \n\n",130,130,130,130,130);
            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");

            goto service ;
        case 3 :

             p = &modi ;
             modifierAge(numPlace,&modi) ;
             printf("%d",modi);
            if( modi == 1  )
                printf  ("\t\n\n*-*-*\tLa modification a %ct%c %cff%cctu%ce  : \n\n",130,130,130,130,130);
            else if(modi == 0)
                printf  ("\t\n\n*-*-*\t Votre age doit %tre sup%crieur %c 12 ans  : \n\n",136,130,133);


            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
             goto service;

        case 4 :
             modifierTel(numPlace);
             printf  ("\t\n\n*-*-*\tLa modification a %ct%c %cff%cctu%ce  : \n\n",130,130,130,130,130);
             printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
             getch();
             system("cls");
             goto service ;

        case 5 :
             printf(" \n-/**/**/- la modification n%ccessite une annulation de la r%cservation \n\n   ",130,130);
             /*modifierNumPlace(numPlace);
             printf  ("\t\n\n*-*-*\tmodification a ete effectue . ET Merci : \n\n");*/
             printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
            goto service ;

        default :
            printf  ("\t\n\n*-*-*\tChoix invalide !  \n\n");
            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
            goto service ;

         }
         }
         else if (numPlace > 100 || 0 > numPlace)
            {printf("\t\n\n*-*-*\tLe nombre des places est limit%c a 100 places (1 -> 100)\n\n",130);
            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
            goto service ;
            }
         else
            {printf("\t\n\n*-*-*\tCette place n'est pas encore r%cserv%ce \n\n",130,130);
            printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
            getch();
            system("cls");
            goto service ;
            }



    case 5 :
        afficherNbrDePlaceRestante();
        printf(" \n-/**/**/- Tapez pour continuer \n\n   ");
        getch();
        system("cls");
        goto service ;
    case 6 :
        goto mode ;
    case 7 :
        FilmProch();
        printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
        getch();
        system("cls");
        goto service;
    case 8 :
        exit(0);


    default :
        {
        printf  (" \t            *******************************                      \n");
        printf  (" \t              !!!!!! Choix incorrect                                \n");
        printf  (" \t        Veuillez saisir un nombre entre  1 et 9.               \n");
        printf  ("        ===================================================            \n");
        printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
        getch();
        system("cls");
        goto service ;

        break ;
        }

    }

}

if(choix1 == 2  )
{
    nbrTentation = 0 ;
    FILE *fp = fopen("password.TXT","r");
    fgets(chaine,11,fp);
    if(fp==NULL)
        exit(0);

do{
    printf("\t Mot de passe :   ");
    scanf("%s",Pass);

    if(strcmp(chaine,Pass) == 0)
        break ;
    else
        {
         printf(" \n-/**/**/-  mot de passe invalide \n\n   ");
        }
    nbrTentation++ ;
}while(  3 > nbrTentation) ;
if(nbrTentation == 3)
{
    printf(" \n-/**/**/- Mot de passe %crron%c \n\n   ",130,130);
    printf(" \n-/**/**/- Tapez pour changer le mot de Passe  . \n\n   ");
    getch();
    system("cls");
    printf(" \n\t\t\t-/**/**/- changement du mot de passe  .\n\n   ");
    changerPassw();
}
printf(" \n-/**/**/- Tapez pour continuer vers le mode developpeur  . \n\n   ");
getch();
system("cls");
dev :
modeDev();
printf("Veuillez saisir votre choix svp :   \n");
printf("\n             ====>>>>    ");
scanf("%d",&choix3);

    if(choix3 == 1)
    {
        LesClientsReserve();
        printf(" \n-/**/**/- Tapez pour continuer \n\n   ");
        getch();
        system("cls");
        goto dev ;
    }
    else if(choix3 == 2)
    {
        viderLeCinema();
        printf(" \n-/**/**/- Toutes les places sont vides .\n\n   ");
        printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
        getch();
        system("cls");
        goto dev ;

    }

    else if (choix3 == 3)
    {
       //printf(" \n-/**/**/- changement du mot de passe  .\n\n   ");
       changerPassw();
    }

    else if(choix3 == 4)
    {
        printf(" \n-/**/**/- Tapez pour continuer   . \n\n   ");
        getch();
        system("cls");
        goto mode ;

    }
    else//if(choix1 != 3 || choix1 != 2 || choix1 != 1)

{
        printf  (" \t               *******************************                         \n");
        printf  (" \t                      Choix incorrect !                               \n");
        printf  (" \t       Veuillez resaisir un num%cro entre 1 et 3                 \n",130);
        printf  ("        ===================================================               \n");
        printf(" \n-/**/**/- Tapez pour continuer . \n\n   ");
        getch();
        goto dev ;
}
}
return 0 ;

}






