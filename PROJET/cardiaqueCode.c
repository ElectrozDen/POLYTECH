#include "lcd/cardiqualcd.h" /* on importe le lcd */
const int PIN=3;

int compteur=0;  /* compteur pour les 3 dernieres durées pour la moyenne flottante */
long valeur[3]={-1,-1,-1}; /* tableau des 3 dernieres durées */
long dernier_temps=0; /* temps du premier front montant */
long temps_suivants=0; /* temps du deuxieme front montant */
long Temps_Front_Montant=0; /* durée entre 2 fronts montant*/

/****INITIALISATION******/

void setup() {
 Serial.begin(9600); 
 pinMode(PIN,INPUT);
 attachInterrupt(digitalPinToInterrupt(PIN),rising,RISING); /* Detection d'un front montant*/
 LcdInitialise();
 LcdClear();
 
}

/****Boucle principal de l'arduino******/

void loop() {

}


/****Gérer l'ecran du lcd******/

void afficherLCD(int BattParMinute){
   LcdInitialise();
   LcdClear();

   /****Convertier un int en char pour le lcd******/
   int dec = 0;
   float BMP = (float)BattParMinute;
   int ABMP=0;
   while(BMP > 9.99){
    dec++;
    BMP/=10.0;
   }
   while(BMP != BattParMinute){
    LcdCharacter('0'+ (int)(BMP-ABMP));
    ABMP = (int)(BMP)*10;
    BMP*=10.0;
   }
   LcdCharacter('0'+ (int)(BMP-ABMP));
   LcdString(" BMP");

   displayHEART();
  
}
/****Retourne la moyenne flottante******/
float Moyenne() {
  return (valeur[0]+valeur[1]+valeur[2])/3.0;
}

/****Retourne le battement par minute******/
int BattParMinute (float moyenne) {
  return (1000/moyenne)*60; 
}
/****Fonction lorsque qu'un front montant est detecte******/
void rising(){
  /****Calcul de la duree et des moyennes flottantes******/
  if(dernier_temps==0){
     dernier_temps=millis();
  }else if ((millis()-dernier_temps)>300){
    temps_suivants=millis();
    Temps_Front_Montant=temps_suivants-dernier_temps;
    valeur[compteur]=Temps_Front_Montant;
    compteur++;
    if (compteur ==3)   compteur=0;
    Serial.println(Temps_Front_Montant);/*On affiche la durée entre les 2 derniers front montants*/
    dernier_temps=temps_suivants;  
  }  
  /****Affichage des infos sur le lcd******/
  if( valeur[2]!=-1){
    Serial.println(Moyenne());
    Serial.println(BattParMinute(Moyenne()));
    afficherLCD(BattParMinute(Moyenne()));
  }
    
}

