#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED


FILE *fp        ;
int existe = 0  ;
char nom   [20] ;
char prenom[20] ;
char tel   [20] ;
int  age        ;
int  numPlaceReserve  ;


void AfficherLesServices()
{

        printf   ("      +------------------Services-------------------------+            \n");
        printf   ("      |                =============                      |            \n");
        printf   ("      |            [1] Reserver un ticket                 |            \n");
        printf   ("      |            [2] Annulation d'une Reservation       |            \n");
        printf   ("      |            [3] films propos%cs                     |            \n",130);
        printf   ("      |            [4] modification de reservation        |            \n");
        printf   ("      |            [3] XXXXXX                             |            \n");
        printf   ("      +---------------------------------------------------+            \n");
}

typedef struct informationClient
{
        char nom   [20];
        char prenom[20];
        char tel   [20];
        int  age       ;
        int  numPlace  ;
        //char carte [10];


} clients ;

int  testCode(int numeroPl )
{
    fp = fopen("new.TXT","r+");
    if(fp == NULL)
        printf(" IMPOSSIBLE D 'ouvrire le fichier !!! \n ");
    else
    {
      while(!feof(fp))
      {
          fscanf(fp,"%s\t%s\t%s\t%d\t%d\n",nom,prenom,tel,&age,&numPlaceReserve);
          if(numPlaceReserve == numeroPl)
          {existe = 1 ;
            break ;
          }
      }

}
   return existe ;

void reserverUnTicket(char nom[] ,char pre[], char tel[] , int age ,int numeroPlace )
{
        fp = fopen("clientResrve.TXT","a+");
        if(fp == NULL)
            printf("impossible d'ouvrir le fichier !!!! ");
        else
        {
        fprintf(fp,"%s\t%s\t%s\t%d\t%d\n",nom,pre,tel,age,numeroPlace);
        fclose(fp);
        }

}

void FilmPop()
{
    FILE *fp = fopen("filmp.TXT","r");
    if(fp == NULL)
        printf("Impossible d'ouvrir le fichier (filmp) .");


}







#endif // FONCTIONS_H_INCLUDED
