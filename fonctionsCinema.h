#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <Windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int  testCode(int numeroPl ) ; // 40
void reserverUnTicket(char nom[] ,char pre[], char tel[] , int age ,int numeroPlace ) ; // 62
void annullerUneResrvation() ; // 84
void FilmPop() ; // 120

FILE *fp = NULL  ;
FILE *ft = NULL  ;
int existe = 0   ;
char nom   [20]  ;
char prenom[20]  ;
char tel   [20]  ;
int  age   ,p    ;
int  numPlaceReserve  ;

typedef struct informationClient{
        char nom   [20];
        char prenom[20];
        char tel   [20];
        int  age       ;
        int  numPlace  ;
        //char carte [10];


} clients ;


void LesModes(){
        printf   ("      +------------------Services-------------------------+            \n");
        printf   ("      |                =============                      |            \n");
        printf   ("      |               [1] Mode client                     |            \n");
        printf   ("      |                 [2] Mode developpeur              |            \n");
        printf   ("      |               [3] Quitter                         |            \n");
        printf   ("      +---------------------------------------------------+            \n");
}


void changerPassw()
{

FILE *f ;
  f = fopen("password.TXT","w");


 if (f== NULL)
 {
     printf("imp");
     exit(0);
 }

 char code[20] ;


 printf("\n\t\t \\\\\  ********   /////// \n");

 printf(" ** entrer le nouveau Password  :   ");
 scanf("%s",code);

 fprintf(f,"%s",code);

fclose(f);
printf(" \n-/**/**/- modification effectue   .\n\n   ");
printf(" \n-/**/**/- Tapez pour continuer  .\n\n   ");
getch();
exit(0);
}


void AfficherLesServices(){

        printf   ("      +--------------------Services-----------------------+            \n");
        printf   ("      |                  =============                    |            \n");
        printf   ("      |            [1] Reserver un ticket                 |            \n");
        printf   ("      |            [2] Annulation d'une Reservation       |            \n");
        printf   ("      |            [3] trouver mon numero du place        |            \n",130);
        printf   ("      |            [4] modification                       |            \n");
        printf   ("      |            [5] nombre des places restantes        |            \n");
        printf   ("      |            [6] retour a l'accueil                 |            \n");
        printf   ("      |            [7] Prochainement                      |            \n");
        printf   ("      |            [8] Quitter                            |            \n");
        printf   ("      +---------------------------------------------------+            \n");
}


void modeDev(){
        printf   ("      +---------------------Services----------------------+            \n");
        printf   ("      |                  =============                    |            \n");
        printf   ("      |               [1] Les Clients Reserves            |            \n");
        printf   ("      |               [2] Vider Le Cinema                 |            \n");
        printf   ("      |               [3] Changer le mot de passe         |            \n");
        printf   ("      |               [4] Retour                          |            \n");
        printf   ("      +---------------------------------------------------+            \n");
}











void Recu(int num){
        printf   ("      +---------------------------------------------------+            \n");
        printf   ("      |                   M E G A R A M A	             |            \n");
        printf   ("      |                BRAQUAGE A L'ITALIENNE             |            \n");
        printf   ("      |  salle  : %d                                     |            \n");
        printf   ("      |  seance : 20h00                                   |            \n");
        printf   ("      |  Prix   : 45 Dh                                   |            \n");
        printf   ("      +---------------------------------------------------+            \n");
        gotoxy(4,19);printf("%d",num);
}




void LesClientsReserve(){
    fp = fopen("clientResrve.TXT","r");
    if(fp == NULL)
    {
    printf("Impossible d'ouvrir le fichier  !!!! ");
    exit(0);
    }

    else
        while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
        {
            printf("Nom        : %s\n",nom);
            printf("Prenom     : %s\n",prenom);
            printf("Contact    : %s\n",tel);
            printf("age        : %d\n",age);
            printf("Place      : %d\n",numPlaceReserve);
            printf("\t * * * * \n");
        }
    fclose(fp);
}

void viderLeCinema(){
    ft = fopen("tmp.TXT","w");
    if(ft==NULL)
    {
         printf("Impossible d'ouvrir le fichier en mode ecriture (tmp)  !!!! ");
         exit(0);
    }
    fclose(ft);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}


int  testCode(int numeroPl ){
    fp = fopen("clientResrve.TXT","r");
    if(fp == NULL)
    {
    printf("Impossible d'ouvrir le fichier  !!!! ");
    exit(0);
    }

    else
    {
      while(!feof(fp))
      {
          fscanf(fp,"%s\t\t%s\t\t%d\t\t%s\t\t%d\n",nom,prenom,&age,tel,&numPlaceReserve);
          if(numPlaceReserve == numeroPl)
          {existe = 1 ;
            break ;
          }
      }fclose(fp);


}
   return existe ;
}

void reserver(char nom[] ,char pre[], char tel[] , int age ,int numeroPlace  ){
        fp = fopen("clientResrve.TXT","a");
        if(fp == NULL)
        {
        printf("Impossible d'ouvrir le fichier !!!! ");
        exit(0);
        }

        else
        {
        fprintf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,pre,tel,age,numeroPlace);
        fclose(fp);
        }

}


void annullerUneResrvation( numeroPlace ){
    fp = fopen("clientResrve.TXT","r");
    ft  = fopen("fichierTemp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier (clientResrve) !!!! ");
        exit(0);
    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier (fichierTemp) !!!! ");
        exit(0);

    }
    while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numeroPlace) == 5)
            if(numPlaceReserve != numeroPlace)
                fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numeroPlace);
    fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("fichierTemp.TXT","clientResrve.TXT");

    }


void afficherNumDuPlace(char telSearch[]){
        existe = 0 ;
        fp = fopen("clientResrve.TXT","r");
        if(fp == NULL)
        {
            printf(" IMPOSSIBLE d'ouvrir le fichier en mode lecture (clientResrve) !!!!! \n ");
            exit(0);

        }
        while(!feof(fp))
         {   fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve);
             if(strcmp(telSearch,tel) == 0  )
                       {
                         printf("\t nom et prenom  : %s %s\n",nom,prenom);
                         printf("\tNumero du place :    %d  \n",numPlaceReserve);

                         existe = 1 ;
                         break ;

                       }
         }

        if(existe == 0)
            printf("\t\n\n*-*-*\tCe contact n'existe pas dans notre cinema . Et Merci\n\n");
        fclose(fp);
    }


void afficherNbrDePlaceRestante(){
        int nbrDePlaceRESERVE = 0 ;
        fp = fopen("clientResrve.TXT","r");
        if(fp == NULL)
        {
            printf(" Impossible d'ouvrir le fichier (clientResrve) en mode lecture \n ");
            exit(0);

        }
        while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
           nbrDePlaceRESERVE += 1 ;
        if(nbrDePlaceRESERVE == 0)
            printf(" cinema vide ///// \n\n");
        printf("nombre des places restantes est : %d\n\n",100 - nbrDePlaceRESERVE);
        printf("####################################\n\n");
        fclose(fp);
    }


void modifierNom(int numPlace){

    fp = fopen("clientResrve.TXT","r");
    ft = fopen("tmp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !!!!!!!!\n\n ");
        exit(0);

    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode ecriture (tmp) !!!!!!!!\n\n ");
        exit(0);

    }
  while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
  {if(numPlace == numPlaceReserve)
  {
      printf  ("\t\n\n*-*-*\tVeuillez saisir votre nom svp  : \n\n");
      printf("\n             ====>>>>    ");
      scanf("%s",&nom);
  }fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numPlaceReserve);

  }

   fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}


void modifierPrenom(int numPlace){

    fp = fopen("clientResrve.TXT","r");
    ft = fopen("tmp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !\n\n ");
        exit(0);

    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode ecriture (tmp) !\n\n ");
        exit(0);

    }
  while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
  {if(numPlace == numPlaceReserve)
  {
      printf  ("\t\n\n*-*-*\tVeuillez saisir votre pr%cnom svp : \n\n",130);
      printf("\n             ====>>>>    ");
      scanf("%s",&prenom);
  }fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numPlaceReserve);

  }

   fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}


void modifierAge(int numPlace , int* modifie){
    *modifie = 0;
    int newAge ;
    fp = fopen("clientResrve.TXT","r");
    ft = fopen("tmp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !!!!!!!!\n\n ");
        exit(0);

    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode %ccriture (tmp) !\n\n ",130);
        exit(0);

    }
  while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
  {if(numPlace == numPlaceReserve)
  {
      printf  ("\t\n\n*-*-*\tVeuillez saisir votre age svp  : \n\n");
      printf("\n             ====>>>>    ");
      scanf("%d",&newAge);


  }
  if( 11 < newAge )
        {
         age = newAge;
        *modifie = 1 ;
        }
  fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numPlaceReserve);

  }

   fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}


void modifierTel(int numPlace){

    fp = fopen("clientResrve.TXT","r");
    ft = fopen("tmp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !!!!!!!!\n\n ");
        exit(0);

    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode ecriture (tmp) !!!!!!!!\n\n ");
        exit(0);

    }
  while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
  {if(numPlace == numPlaceReserve)
  {
      printf  ("\t\n\n*-*-*\tveuillez entrer svp votre tel . ET Merci : \n\n");
      printf("\n             ====>>>>    ");
      scanf("%s",&tel);
  }fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numPlaceReserve);

  }

   fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}


 void afficherGroup(){
   fp = fopen("groupe.TXT","r");
   if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !!!!!!!!\n\n ");
        exit(0);

    }
    char c  ;
    c = fgetc(fp);
    while(c != EOF)
        {

        printf("%c",c);

        }

}

void FilmProch(){
int c ;
    FILE *fp = fopen("filmp.TXT","r");
    if(fp == NULL)
    {
    printf("Impossible d'ouvrir le fichier (filmp) .");
    exit(0);
    }

while (( c=fgetc( fp )) != EOF)
    printf("%c",c);
fclose(fp);

}



/*
void modifierNumPlace(int numPlace)
{
    int newPlace ;
    fp = fopen("clientResrve.TXT","r");
    ft = fopen("tmp.TXT","w");
    if(fp == NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode lecture (clientResrve) !!!!!!!!\n\n ");
        exit(0);

    }
    if(ft==NULL)
    {
        printf("Impossible d'ouvrir le fichier en mode ecriture (tmp) !!!!!!!!\n\n ");
        exit(0);

    }
  while(fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,&age,&numPlaceReserve) == 5)
  {if(numPlace == numPlaceReserve)
  {
      printf  ("\t\n\n*-*-*\t votre numero  . ET Merci : \n\n");
      printf("\n             ====>>>>    ");
      scanf("%d",&newPlace);
      if(testCode(newPlace) == 1)
         {
              printf("\t\n\n*-*-*\tCe place est deja reserve . Et Merci\n\n");
              printf  ("\t\n\n*-*-*\tveuillez entrer svp un autre  . \n\n");
              //existe =1 ;
         }
      else
        numPlaceReserve = newPlace ;
  }fprintf(ft,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",nom,prenom,tel,age,numPlaceReserve);

  }

    fclose(ft);fclose(fp);
    remove("clientResrve.TXT");
    rename("tmp.TXT","clientResrve.TXT");
}
*/






#endif // FONCTIONS_H_INCLUDED
