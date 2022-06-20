
# Projekt pri predmetu VIN (Vremenska postaja) 

# Osnovna ideja 

Za projekt sem si izbral prenosno vremensko postajo. 
Vremenska postaja ima zaslon na katerem se prikaže trenutna temperatura in vlažnost. 
Dodal sem tudi preproste "ikone/simbole", ki ponazarjajo trenutno stanje. 

# Pinout 

Za ogled povezav med komponentami sem pripravil shemo. Na voljo tudi v direktoriju "shema" 
![image](https://i.imgur.com/FtSCrnu.png)

# Komponente 

Uporabil sem sledeče komponente: 
 - Arduino Uno 
 - 16x2 lcd zaslon 
 - i2c modul 
 - DHT11 seznor 
 - 9V baterija 

# Opis komponent 
Arduino Uno

![image](https://jeulin.com/media/catalog/product/p/l/platine_uno_arduino_275601_1_fb33.jpg?optimize=high&bg-color=255,255,255&fit=bounds&height=700&width=700&canvas=700:700)
  
  Je mikrokrmilnik, ki nam omogoča povezovanje V/I naprav. Na arduino se lahko priključi razne tipke, zaslone, senzorje in mnogo več kar omogoča preprost razvoj raznih   prototipnih ali pa tudi končnih izdelkov. Programe na Arduino naložimo prek razvojnega okolja ARDUINO IDE v katerem tuki programiramo. Programski jezik je v resnici   C++, oznaka arduino datotek pa je .ino. 

DHT11 senzor

![image](https://www.primeproductions.lk/wp-content/uploads/2021/12/dht-11-sensor-module-india-800x800-1.jpg)

Omogoča zaznavanje temperature in vlažnosti. 


16x2 LCD zaslon

![image](https://i.imgur.com/GneXRWo.png)

Zaslon, ki lahko prikaže dve vrstici po 16 znakov. Vsak znak je sestavljen iz 8x5 pixlov. 

Na zaslonu se pri mojem projektu prikaže temperatura v stopinjah celzija in vlažnost zraka v odstotkih. Poleg tega pa se v levem spodnjem kotu prikaže tudi "smiley", ki ponazarja kako toplo je. Glede na temperaturo se spremeni v: "😊", "😐" & "🙁", prikazan pa je v 8x5 obliki. 

i2c modul

![image](https://aaloktech.in/wp-content/uploads/2021/06/i2c-module-for-16x2-lcd-800x800-1.jpg)

Poenostavi povezovanje LCD zaslona z arduinom. Vsak PIN je poravnan s portom na LCDju. Vse kar je treba narediti je, da se prilota pine (ali pa tudi ne). Jaz sem jih, da se LCD slučajno ne odklopi. 

# Video delovanja 
Pripravil sem video v katerem pokažem kako vremenska postaja deluje.
[![Video delovanja](https://img.youtube.com/vi/mlg3efceNSU/maxresdefault.jpg)](https://www.youtube.com/watch?v=mlg3efceNSU) 

# Knjižnice 
Za komunikacijo z LCD zaslonom sem uporabil knjižnico LiquidCrystal_I2C, ki je dostopna prek povezave: https://registry.platformio.org/libraries/marcoschwartz/LiquidCrystal_I2C in v ARDUINO IDE v library managerju. 

-Jorg Cimperman 
