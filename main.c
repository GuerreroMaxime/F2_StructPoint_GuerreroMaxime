
/**********************\
    liste.c        *
\**********************/

#include "liste.h"

int main (void)
{
  char choix;
  char *nom;
  Liste *liste;
  //Element *courant;

  if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
    return -1;
  if ((nom = (char *) malloc (50)) == NULL)
    return -1;

  //courant = NULL;
  choix = 'o';

  initialisation (liste);
  int pos, k;

  while (choix != 7){
      choix = menu (liste, &k);
      switch (choix){
         case 1:
          printf ("Entrez X\n");
          scanf ("%s", nom);
          getchar ();
          if (liste->taille == 0){
            insListeVide(liste, nom);

           printf ("Entrez Y\n");
           scanf ("%s", nom);
           getchar ();
           insFinListe (liste, liste->fin, nom);


           printf ("Entrez Z\n");
           scanf ("%s", nom);
           getchar ();
           insFinListe (liste, liste->fin, nom);
          }

          else{
            insDebutListe (liste, nom);

            pos=1;
            printf ("Entrez Y\n");
            scanf ("%s", nom);
            getchar ();
            insListe (liste, nom, pos);

            pos=2;
            printf ("Entrez Z\n");
            scanf ("%s", nom);
            getchar ();
            insListe (liste, nom, pos);
          }

          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->donnee, liste->fin->donnee);
          affiche (liste);
          break;

        case 2:
          printf ("Entrez X\n");
          scanf ("%s", nom);
          getchar ();
          if (liste->taille == 0)
            insListeVide(liste, nom);
          else
            insFinListe (liste, liste->fin, nom);

          printf ("Entrez Y\n");
          scanf ("%s", nom);
          getchar ();
          insFinListe (liste, liste->fin, nom);


          printf ("Entrez Z\n");
          scanf ("%s", nom);
          getchar ();
          insFinListe (liste, liste->fin, nom);
          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->donnee, liste->fin->donnee);
          affiche (liste);
          break;
        case 3:
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          if (liste->taille == 1 || pos == liste->taille){
              k = 1;
              printf("-----------------------------------------------\n");
              printf("Insertion echouée.Utilisez le menu {1|2}  \n");
              printf("-----------------------------------------------\n");
              break;
     }
          printf ("Entrez X\n");
          scanf ("%s", nom);
          getchar ();

          insListe (liste, nom, pos);

            pos=pos+1;
            printf ("Entrez Y\n");
            scanf ("%s", nom);
            getchar ();
            insListe (liste, nom, pos);

            pos=pos+1;
            printf ("Entrez Z\n");
            scanf ("%s", nom);
            getchar ();
            insListe (liste, nom, pos);

          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->donnee, liste->fin->donnee);
          affiche (liste);
          break;



        case 4:
          suppDebut (liste);
          if (liste->taille != 0)
            printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                    liste->debut->donnee, liste->fin->donnee);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 5:
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          suppDansListe (liste, pos);
          if (liste->taille != 0)
            printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                    liste->debut->donnee, liste->fin->donnee);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 6:
          detruire (liste);
          printf ("la liste a ete detruite : %d elements\n", liste->taille);
          break;
      }
  }
  return 0;
}
