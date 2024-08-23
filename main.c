#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int nbMesures;
    float diffMax ;

    printf("Entrer le nombre de mesures : ");
    scanf("%d", &nbMesures);

    printf("Veuillez saisir la difference maximale : ");
    scanf("%f", &diffMax);

    float mesuresI[nbMesures];
    float tempMesures[nbMesures];

    for (int i = 0 ; i < nbMesures ; i++){
        printf("Mesure %d : ", i+1);
        scanf("%f", &mesuresI[i]);
    }


    int nombreDeLissages = 0;
    int continueLissage;

    do {
        continueLissage = 0;

        for(int i = 0 ; i < nbMesures ; i++){
            tempMesures[i] = mesuresI[i];
        }

        for (int i = 1 ; i < nbMesures - 1 ; i++){
            mesuresI[i] = ( tempMesures[i-1] + tempMesures[i+1] ) / 2;
        }

            for(int i = 1 ; i < nbMesures ; i++){
            if(fabs(mesuresI[i] - mesuresI[i-1]) > diffMax){
                continueLissage = 1;
                break;
            }
        }
        nombreDeLissages ++;
    } while(continueLissage);


    printf("Le nombre de lissages est : %d\n", nombreDeLissages);

    return 0;
}



