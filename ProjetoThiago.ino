
//importa o arquivo com as notas
#include "notas.h"

//define o tempo das notas
#define t4 1500
#define t2 1000
#define t1 700
#define t05 350
#define t025 125


//Controla a Velocidade do hino
int ritimo = 1;

//Array com as notas do hino
int musica []={
NOTE_D6,NOTE_G6,
NOTE_A6,NOTE_B6,
NOTE_A6,NOTE_B6,
NOTE_C6,NOTE_A6,
NOTE_G6,NOTE_A6,
NOTE_B6,NOTE_G6,


NOTE_D6,NOTE_G6,
NOTE_B6,NOTE_D6,
NOTE_C6,NOTE_D6,
NOTE_E6,NOTE_C6,
NOTE_B6,NOTE_C6,
NOTE_D6,NOTE_B6,
//NOTE_A6,NOTE_B6,

NOTE_G6,NOTE_G6,
NOTE_E6,NOTE_D6,
NOTE_E6,NOTE_D6,
NOTE_C6,NOTE_E6,
NOTE_E6,NOTE_D6,
NOTE_C6,NOTE_D6,
NOTE_C6,NOTE_B6,

NOTE_D6,NOTE_G6,
NOTE_A6,NOTE_B6,
NOTE_A6,NOTE_B6,
NOTE_C6,NOTE_A6,
NOTE_G6,NOTE_A6,
NOTE_B6,NOTE_G6,
//NOTE_G6

};
// array com as durações das Notas
int duracoes[]={
t05,t1,
t05,t1,
t05,t05,
t05,t1,
t05,t05,
t05,t4,


t05,t05,
t05,t1,
t05,t05,
t05,t1,
t05,t05,
t05,t4,
//t1,t2,

t05,t05,
t1,t05,
t05,t05,
t2,t05,
t05,t1,
t05,t05,
t05,t2,

t05,t05,
t05,t1,
t05,t05,
t05,t1,
t05,t05,
t05,t4,
//t1
};

//Variavel de controle para tocar o hino apenas ao amanhecer
int tocar = 1;

void setup() {

pinMode(7,OUTPUT);
pinMode(8,INPUT_PULLUP);
pinMode(9,OUTPUT);

}

  void loop() {
                
                int ldr = analogRead(0);
                int bt = digitalRead(8);
                
                // Toca o Hino sempre que precionar o Botão
                if(!bt){
                      repetirHino();
                }
                
                //Quanto amanhecer liga o motor e toca o hino uma vez
                if(ldr >= 600){
                     digitalWrite(9,HIGH);
                     if(tocar == 1){
                      repetirHino();
                     }
                     
                 // quanto anoitecer desliga o motor e prepara a variavel para tocar o hino quando amanhecer
                }else{
                    digitalWrite(9,LOW);
                    delay(50);
                    tocar = 1;
                }
                
  }

// Função que toca o Hino 
void tocarHino(){
      for(int nota = 0; nota< sizeof(musica)/sizeof(int); nota++){
          int duracaonota = duracoes[nota]/ritimo;
          tone(7,musica[nota],duracaonota);
          delay(duracaonota*1.3);
          noTone(7);
      }
 
      delay(1000);
}

// Função para Repetir o Hino 3 vezes 
void repetirHino(){
     for(int i = 0; i< 1; i++){
        tocarHino();
     }

     tocar = 0;
}
