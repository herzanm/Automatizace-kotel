// ovladaci piny pro sepinani rele na ovladani kotle a cerpadla - OUTPUT
#define kotelRele 12
#define cerpadlo1NP 11
#define cerpadlo2NP 10

// tlacitka na prepinani mezi modama - INPUT
#define buttonOFF 9
#define buttonONAUTO 8

// ledky ukazujici current mod a kotel
#define ledRED 7
#define ledBLUE 6
#define ledGREEN 5
#define ledKOTEL 4

// detekce rele z termostatu
#define termostat1NP 3
#define termostat2NP 2


// Displej pouziva dva analogovy piny



int statusTermostat1 = 0;
int statusTermostat2 = 0;
// flag na prepinani mezi ON a AUTO modem
int onAutoCounter = 0;
int buttonOFFstate = 0;
int buttonONstate = 0;


void setup() {
  // rele outputs - default set to HIGH = OFF
  pinMode(kotelRele, OUTPUT);
  pinMode(cerpadlo1NP, OUTPUT);
  pinMode(cerpadlo2NP, OUTPUT);
  digitalWrite(kotelRele, HIGH);
  digitalWrite(cerpadlo1NP, HIGH);
  digitalWrite(cerpadlo2NP, HIGH);

  //setup tlacitek
  pinMode(buttonOFF, INPUT);
  pinMode(buttonONAUTO, INPUT);


  // setup ledek, default RED ON other OFF
  pinMode(ledRED, OUTPUT);
  pinMode(ledBLUE, OUTPUT);
  pinMode(ledGREEN, OUTPUT);
  pinMode(ledKOTEL, OUTPUT);
  digitalWrite(ledRED, HIGH);
  digitalWrite(ledBLUE, LOW);
  digitalWrite(ledGREEN, LOW);
  digitalWrite(ledKOTEL, LOW);

  pinMode(termostat1NP, INPUT);
  pinMode(termostat2NP, INPUT);

}

// the loop function runs over and over again forever
void loop() {
    if(digitalRead(termostat1NP) == HIGH){
      delay(300);
      digitalWrite(cerpadlo1NP, LOW);
    } 
    else{
      digitalWrite(cerpadlo1NP, HIGH);
    }

    if(digitalRead(termostat2NP) == HIGH){
      delay(300);
      digitalWrite(cerpadlo2NP, LOW);
    }
    else{
      digitalWrite(cerpadlo2NP, HIGH);
    }

  // pokud je zapnutý kotel kontrolka svítí
  if(digitalRead(termostat1NP) == HIGH || digitalRead(termostat2NP) == HIGH){

    delay(1000);
    digitalWrite(kotelRele, LOW);
    digitalWrite(ledKOTEL, HIGH);
    digitalWrite(ledGREEN, HIGH);
    digitalWrite(ledRED, LOW);
        
  }
  else{
    digitalWrite(ledRED, HIGH);
    digitalWrite(ledGREEN, LOW);    
    delay(1000);
    digitalWrite(kotelRele, HIGH);
    digitalWrite(ledKOTEL, LOW);

    
  }
}

