# Vigne Felix & Vinot Colin & Roquet Denys

# Compte-Rendu TP Informatique Arduino

## PWM : 

Remplacer l'utilisation du PWM matériel par un PWM logiciel:

```
int led = 13;
float periode = 30.0;
float rapport = 0.01;
float somme = 0.01;

void setup(){
  
  pinMode(led, OUTPUT);
  
}

void loop(){
  
  
  digitalWrite(led, HIGH);
  delay(periode*rapport);
  digitalWrite(led, LOW);
  delay(periode-periode*rapport);
  rapport += somme;
  
  if(rapport >= 1)
    somme = -0.01;
   else if(rapport <= 0)
     somme = 0.01;
  
}
```
## Bouton Poussoir :

Réalisation du schéma : (On travaille sur la led de l'arduino(pin 13))

Algorithme: 

Si PIN 2 == 1 alors envoyer 1 au PIN 13 (PIN 13 = 1)
	      sinon envoyer 0 au PIN 13 (PIN 13 = 0) 

## Potentiométre & Communication série: : 

Réalisation du schéma :

Modification du sketck avec communication série: 

```
int sensorPin = 0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue); 
  // turn the ledPin on
  digitalWrite(ledPin, HIGH); 
  // stop the program for  milliseconds:
  delay(sensorValue); 
  // turn the ledPin off: 
  digitalWrite(ledPin, LOW);
  // stop the program for for  milliseconds:
  delay(sensorValue); 
}
```

## ServoMoteur : 

Avec un servomoteur on peut choisir l'angle de sa rotation.
On utilise le schéma de Horner pour pouvoir communiquer avec le servomoteur : 

```
#include <Servo.h>

Servo moteur;
int angle = 0;

void setup(){
  Serial.begin(9600);
  moteur.attach(9);
  
  
}



void loop(){
  
 if(Serial.available())
   angle = Serial.read() - 48;
   
 while(Serial.available())
   angle = angle*10 + Serial.read() - 48;
   
 moteur.write(angle);
 
 delay(200);
   
  
}

```

## Buzzer : 

Un buzzer permet d'émettre un son quand on lui envoie une tension

Exemple : 

```
int buzzer =2;// Borne de sortie

void setup()
{
	pinMode(buzzer,OUTPUT);// Définir la sortie du buzzer
}

void loop()
{
	int i;// Définir 1 variable pour faire des boucles

	while(1)
	{

		for(i=0; i<80; i++)// Premier son à une fréquence
		{
			digitalWrite(buzzer, HIGH);// Faire du bruit
			delay(10);// Attendre 10ms
			digitalWrite(buzzer, LOW);// Silence
			delay(10);// Attendre 10ms
		}

		for(i=0; i<40; i++)// Deuxième son à une autre fréquence
		{
			digitalWrite(buzzer,HIGH);// Faire du bruit
			delay(20);// Attendre 20ms
			digitalWrite(buzzer,LOW);// Silence
			delay(20);// Attendre 20ms
		}

	}
}
```

## LCD

Le LCD permet d'afficher du texte en fonction des algorithmes de l'arduino.

Exemple : 

```
void loop(void) { 
	LcdClear();
	LcdString("Pokemons");
	delay(500);
	LcdString("Attrapez les tous");
	delay(500);
} 
```

## DEBOUNCE : 


Code explicite (Trouvé sur internet : http://www.mon-club-elec.fr/pmwiki_reference_arduino/pmwiki.php?n=Main.ExempleDebounce)
```

const int buttonPin = 2;    // crée un identifiant pour la broche utilisée avec le bouton poussoir
const int ledPin =  13;      // crée un identifiant pour la broche utilisée avec la LED

// Les variables sont modifiées au cours du programme
int ledState = HIGH;         // Variable pour l'état courant de la LED
int buttonState;             //Variable pour l'état actuel du bouton poussoir
int lastButtonState = LOW;   // Variable pour l'état précédent du bouton poussoir

// les variables suivantes sont de type long car le temps, mesuré en millisecondes
// devient rapidement un nombre qui ne peut pas être stocké dans un type int.
long lastDebounceTime = 0;  // variable pour mémoriser le temps écoulé depuis le dernier changement de la LED
long debounceDelay = 50;    //intervalle anti-rebond

void setup() {
  pinMode(buttonPin, INPUT); // met la broche en entrée
  pinMode(ledPin, OUTPUT); // met la broche en sortie
}

void loop() {
  // lit l'état du bouton poussoir et le stocke dans une variable locale type int
  int reading = digitalRead(buttonPin);

  // vérifie si le bouton poussoir vient d'être appuyé
  // c'est à dire si la broche est passée de HAUT à BAS,  puis on attend
  // suffisamment longtemps pour ignorer le rebond

  // Si l'état du bouton poussoir est changé ou si il y a du bruit
  if (reading != lastButtonState) {
    // mémorise le moment où l'appui détecté
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // quelque soit l'état de la broche lu, tant que le délai n'est pas écoulé
    // le bouton poussoir est considéré comme étant dans le dernier état pris en compte
    buttonState = reading;
  }

  //// modifie l'état de la LED en utilisant l'état du bouton 
  digitalWrite(ledPin, buttonState);

  // Mémorise la valeur de l'état du bouton poussoir lue. Lors du prochain passage
  // dans la boucle loop, ce sera la variable lastButtonState
  lastButtonState = reading;
}
 ```

## Utilisation de attachInterrupt et Mesure de temps entre 2 fronts montants d'un signal générés

En utilisant la fonction attachInterupt on mesure le temps entre 2 fronts montants d'un signal générés : 

```
void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(7), mesure, RISING);
}


void loop() {
  digitalWrite(7, HIGH); 
  delay(1000);
  digitalWrite(7, LOW); 
  delay(1000);
  
}

void mesure(){
  Serial.println(millis());
}
```
