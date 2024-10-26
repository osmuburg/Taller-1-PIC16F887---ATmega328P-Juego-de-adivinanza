#line 1 "D:/pc/OneDrive/OneDrive - Escuela Superior Politécnica del Litoral/ESPOL/6to Semestre PAO-2 2024/Embebidos/Talleres/Taller-1-PIC16F887---ATmega328P-Juego-de-adivinanza/PIC16F887/main.c"


void Tone1() {
 Sound_Play(659, 250);
}

void Tone2() {
 Sound_Play(698, 250);
}

void Tone3() {
 Sound_Play(784, 250);
}

void Melody_Win() {
 Tone1(); Tone2(); Tone3(); Tone3();
 Tone1(); Tone2(); Tone3(); Tone3();
 Tone1(); Tone2(); Tone3();
 Tone1(); Tone2(); Tone3(); Tone3();
 Tone1(); Tone2(); Tone3();
 Tone3(); Tone3(); Tone2(); Tone2(); Tone1();
}

void ToneA() {
 Sound_Play(880, 50);
}

void ToneC() {
 Sound_Play(1046, 50);
}

void ToneE() {
 Sound_Play(1318, 50);
}

void Melody_Lose() {
 unsigned short i;
 for (i = 9; i > 0; i--) {
 ToneA(); ToneC(); ToneE();
 }
}

void main() {

 ANSEL = 0;
 ANSELH = 0;
 C1ON_bit = 0;
 C2ON_bit = 0;

 TRISB = 0xFF;
 TRISA = 0xFF;
 TRISC = 0x00;
 TRISD = 0x00;

 Sound_Init(&PORTC, 3);
 int numero_seleccionado = 0;
 int numero_aleatorio = 0;


 while (Button(&PORTB, 7, 1, 1) == 0) {
 PORTD = 0x00;
 }


 PORTD = 0x01;
 while (Button(&PORTB, 7, 1, 1) == 1);


 if (Button(&PORTA, 0, 1, 1)) numero_seleccionado = 1;
 else if (Button(&PORTA, 1, 1, 1)) numero_seleccionado = 2;
 else if (Button(&PORTB, 0, 1, 1)) numero_seleccionado = 3;
 else if (Button(&PORTB, 1, 1, 1)) numero_seleccionado = 4;
 else if (Button(&PORTB, 2, 1, 1)) numero_seleccionado = 5;
 else if (Button(&PORTB, 3, 1, 1)) numero_seleccionado = 6;
 else if (Button(&PORTB, 4, 1, 1)) numero_seleccionado = 7;
 else if (Button(&PORTB, 5, 1, 1)) numero_seleccionado = 8;
 else if (Button(&PORTB, 6, 1, 1)) numero_seleccionado = 9;


 while (PORTA.F0 == 0 || PORTA.F1 == 0 || PORTB.F0 == 0 || PORTB.F1 == 0 ||
 PORTB.F2 == 0 || PORTB.F3 == 0 || PORTB.F4 == 0 || PORTB.F5 == 0 || PORTB.F6 == 0);


 numero_aleatorio = (rand() % 9) + 1;


 if (numero_seleccionado == numero_aleatorio) {

 PORTC.F0 = 1;
 PORTC.F1 = 0;
 Melody_Win();
 } else {

 PORTC.F0 = 1;
 PORTC.F1 = 1;
 Melody_Lose();
 }


 PORTC = (PORTC & 0x03) | (numero_seleccionado << 2);
}
