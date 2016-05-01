# LAPLANTE Juliette & ROQUET Denys

# PROJET PHYSICAL COMPUTING - Rythme Cardiaque

## Partie Electronique

## Emetteur(Led)

### 1-
La tension maximal de seuil pour Vdiode est 2.2V

### 2-

Loi des mailles : Vcc-Vdiode - Rc.Ic = 0</br>
-> Rc = (Vcc-Vdiode)/Ic = (5-2.2)/0.050 = 56 Ohm 
### Rc = 56 Ohm

### 3 -
Nous savons que Ic = Beta*Ib</br>
->Ib=Ic/Beta = 0.050/130 = 0.4 mA
Loi des mailles : Rb=(Ve-Vbe)/Ib = (5-0.6)/0.0004 = 11kOhm
### Rb = 11kOhm

### 4-

Realisation du montage : 

![Alt text](https://raw.githubusercontent.com/ElectrozDen/POLYTECH/master/PROJET/img.png "")

### 5-

On trouve Ic = 49-50 mA selon notre mesure

## Alimentation et conversion courant-tension

### 6-

Grâce à la documentation technique, on trouve : 

### Vo = 300 mV

On en deduit que Rpol = (Vcc+Vphoto)/Ip = 1.06 MOhm

### Rpol = 1.06 MOhm

### 7-

Realisaton du montage : 

![Alt text](https://raw.githubusercontent.com/ElectrozDen/POLYTECH/master/PROJET/img2.png "")

### 8- 

Vérification Oscilloscope : 

![Alt text](https://raw.githubusercontent.com/ElectrozDen/POLYTECH/master/PROJET/photo.JPG "")

### 9-

On trouve l'odre de grandeur de Vf = 10¨-1 (entre 0.62 et 0.72)

### 10-

Loi des mailles : Rd = (Vcc-1.2)/I = (5-1.2)/0.005 = 3800Ohm

### Rd = 3.8 kOhm

### 11-

Nous obtenons bien la presence de 1.2V

### 12-

Nous savons que Rhp = 1/(C*2*PI*f)

### Rhp = 28 kOhm

### 13 - 14 

Vérification réussi, tout est fonctionnel

## Filte passe bas

### 15 - 16

Aprés avoir simplifier les expressions (dur et trés long de faire la demo sur un ordinateur) , noous trouvons pour f0 = 10Hz et m = 1 :

### C2=C4=150 nF

### 17 - 18

Vérification réussi! Le signal montre que la phtotdiode capte bien la pulsation

## Amplificateur

19 - 20

Aprés 3h d'archanement , nous avons réussi pour que le signal sur l'oscilloscope montre bien notre pulsation

# Partie Programmation


