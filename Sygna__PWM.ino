// Program pokazujący działanie sygnału PWM na przykładzie diody która rozbłyska oraz wygasa w dowolnym tempie przez nas wybranym. 

#define diodaPIN 3 // definiuje zmienna diode jako wyjscie 3.
 
int wypelnienie = 0;
int zmiana = 5;
int spr=0;
 
void setup() {
  pinMode(diodaPIN, OUTPUT);//Ustawiam pin jako wyjście.
}
 
void loop() {
  analogWrite(diodaPIN, wypelnienie); //tworzę sygnał o zadanym wypełnieniu.

  if (wypelnienie < 255 && spr == 0){ // jeżeli wypełnienie sygnału jest mniejsze niż 255 dodajemy 5. 

    wypelnienie = wypelnienie + zmiana;
    delay(100);
  }
   if (wypelnienie == 255){ // jeżeli wypełnienie sygnału jest maksymalne to zmienna spr=1
    spr = 1;
  }
   if (spr == 1){  // jeżeli wypełnienie sygnału było już maksymalne to teraz odejmujemy wartość 5 od wypełnienia maksymalnego.
    wypelnienie = wypelnienie - zmiana;
    delay(100);
  }
  if(spr==1 && wypelnienie == 0){ // jeżeli skończyliśmy już odejmować 5 od aktualnego wypełnienia i wypełnienie wynosi 0 oraz zmienna pomocnicza spr dalej ma wartość 1 zamieniamy ją wartość zmiennej spr na "0"
    spr = 0;
  }
 
  
}
