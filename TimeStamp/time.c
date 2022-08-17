#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>



time_t getTime(time_t temp_actuel)
{
    // time_t temp_actuel;

    time (&temp_actuel);
    printf ("L'heure actuelle est: %ld\n", temp_actuel);

  return temp_actuel;
}

int setTime(time_t temp_actuel)
{
    int annee, mois, jour;
    time(&temp_actuel);
    //time_t a = temp_actuel;
    //printf("%ld\n", temp_actuel);
    struct tm *tm;
    tm = localtime(&temp_actuel);
    printf ("Entrer l'annee: \n"); scanf ("%d",&annee);
    printf ("Entrer le mois: \n"); scanf ("%d",&mois);
    printf ("Entrer le jour: \n"); scanf ("%d",&jour);
    tm->tm_year = annee - 1900;
    tm->tm_mon = mois;
    tm->tm_mday = jour;

    temp_actuel = mktime(tm);
    printf ("L'heure modifie est: %s\n", ctime(&temp_actuel));
}

int humanFormat(time_t temp_actuel)
{

    time (&temp_actuel);
    printf ("L'heure actuelle est: %s\n", ctime (&temp_actuel));

  return 0; 
}

int diffTime(time_t t1, time_t t2)
{
  time_t temp_actuel;
  t1 = getTime(t1);
    /*unsigned long t1 = time(&time1);
    unsigned long t2 = time(&time2);
    unsigned long t3 = abs(t1 - t2);
    printf("La difference entre %s et %s est %ld", ctime(&time1), ctime(&time2), t3);

    return 0;

    time_t time1 = time( NULL );
        
    // Do something
    sleep( 2 );   // Is a POSIX funcztion - defined in <unistd.h>
        
    time_t time2 = time( NULL);
    unsigned long secondes = (unsigned long) difftime(time1, time2 );
    printf( "Finished in %d sec\n", abs(secondes) );  */
    t2 = getTime(t2);
    printf("La difference de temps est %f \n", difftime(t1, t2));
            
    return 0;

}

int main()
{
    time_t temp_actuel, t1, t2;
    int choix;
    printf("1. getTime \n");
    printf("2. setTime \n");
    printf("3. humanFormat \n");
    printf("4. diffTime \n");
    printf("Entrer votre choix \n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
      getTime(temp_actuel);
      break;
    
    case 2:
      setTime(time(&temp_actuel));
      break;
    
    case 3:
      humanFormat(temp_actuel);
      break;

    case 4:
      diffTime(t1,t2);
      break;

    default:
      break;
    }
}