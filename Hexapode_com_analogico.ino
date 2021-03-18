//08/01/2017 atualizado em 09/06/2017.
#include <Servo.h>

#define COXA_SOBE 105     //105
#define COXA_DESCE 70     //70
#define PERNA_SOBE 92     //92
#define PERNA_DESCE 125   //125
#define TEMPO1 200
#define TEMPO2 200
#define TEMPO3 200
#define TEMPO4 200
#define TEMPO5 100

int SOBE = PERNA_SOBE;
int DESCE = PERNA_DESCE;
int portay; //cima
int portax; //baixo
int opcao=0;  //manter amostra
int opcao1=110;  //eixo(y) frente
int opcao2=0;  //eixo(y) traz
int opcao3=120;  //eixo(x) esquerda
int opcao4=0;  //eixo(x) direita 

Servo CoxaEsquerdaTraseira;
Servo PernaEsquerdaTraseira;
Servo CoxaDireitaMeio;
Servo PernaDireitaMeio;
Servo CoxaEsquerdaFrente;
Servo PernaEsquerdaFrente;
Servo coxaDireitaFrente;
Servo pernaDireitaFrente;
Servo CoxaEsquerdaMeio;
Servo PernaEsquerdaMeio;
Servo CoxaDireitaTraseira;
Servo PernaDireitaTraseira;

void setup()
{
  Serial.begin(9600);
  //======================LOCALIZAÇÃO DOS PINOS NO ARDUINO===========================//
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(2, OUTPUT);
  digitalWrite(3, OUTPUT);
  digitalWrite(4, OUTPUT);
  digitalWrite(5, OUTPUT);
  digitalWrite(6, OUTPUT);
  digitalWrite(7, OUTPUT);
  digitalWrite(8, OUTPUT);
  digitalWrite(9, OUTPUT);
  digitalWrite(10, OUTPUT);
  digitalWrite(11, OUTPUT);
  digitalWrite(12, OUTPUT);
  digitalWrite(13, OUTPUT);
 
  CoxaEsquerdaTraseira.attach(2);
  PernaEsquerdaTraseira.attach(3);
  CoxaDireitaMeio.attach(10);
  PernaDireitaMeio.attach(11);
  CoxaEsquerdaFrente.attach(6);
  PernaEsquerdaFrente.attach(7);
  coxaDireitaFrente.attach(12);
  pernaDireitaFrente.attach(13);
  CoxaEsquerdaMeio.attach(4);
  PernaEsquerdaMeio.attach(5);
  CoxaDireitaTraseira.attach(8);
  PernaDireitaTraseira.attach(9);
}
 //=================================================================================//
 
void loop(){
  
   Controle(); //x,y
   /*
   for (int i=0; i<=10; i++){
       AndarParaFrente();
    }
      for (int i=0; i<=2; i++){
        Apresentacao();    
      }
        for (int j=0; j<=3; j++){
           AndarParaTras();
        }
          for (int k=0; k<=3; k++){
             IrParaEsquerda();
          }
             for (int k=0; k<=3; k++){
               IrParaDireita();
            } */

    Serial.println(portay, portax);
}

 void Controle(){    
   int val = analogRead(0); //porta A0
   int val_y = analogRead(1); //porta A1
   portax = map(val,0,1023,0,180);
   portay = map(val_y,0,1023,0,180);
       if(portay>=opcao1){ //eixo(y) frente
          AndarParaFrente();
      }else if(portay==opcao2){ //eixo(y) traz
         AndarParaTras();
      }else if(portax>=opcao3){  //eixo(x) esquerda
         IrParaDireita();
      }else if(portax==opcao4){ //eixo(x) direita 
        IrParaEsquerda(); 
      }else{
        //Apresentacao();
      }
 }

void Apresentacao(){
  Amostra1();
}
void AndarParaFrente() {
  PASSO1(); PASSO2(); PASSO3(); PASSO4();
}
void AndarParaTras() {
   Tras4(); Tras3(); Tras2(); Tras1(); 
}
void IrParaEsquerda() {
  Vire_A_ESQUERDA1(); Vire_A_ESQUERDA2(); Vire_A_ESQUERDA3(); Vire_A_ESQUERDA4();
}
void IrParaDireita() {
  Vire_A_DIREITA1(); Vire_A_DIREITA2(); Vire_A_DIREITA3(); Vire_A_DIREITA4();
}

void Amostra1(){
  CoxaEsquerdaFrente.write(40);
  delay(100);
  coxaDireitaFrente.write(155);
  delay(100);
  CoxaEsquerdaTraseira.write(100);
  delay(100);
  CoxaDireitaTraseira.write(75);
  delay(100);
  CoxaEsquerdaMeio.write(120);
  delay(100);
  CoxaDireitaMeio.write(120);
  delay(100);
  PernaEsquerdaTraseira.write(70);
  delay(100);
  PernaDireitaTraseira.write(130);
  delay(100);
  PernaDireitaMeio.write(100);
  delay(100);
  PernaEsquerdaMeio.write(130);
  delay(100);
  pernaDireitaFrente.write(60);
  delay(100);
  PernaEsquerdaFrente.write(75);
  delay(100);
}

void PASSO1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void PASSO2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void PASSO3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void PASSO4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void  Tras1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void  Tras2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void  Tras3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void  Tras4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void Vire_A_ESQUERDA1() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO1);
};
void Vire_A_ESQUERDA2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void Vire_A_ESQUERDA3() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO3);
};
void Vire_A_ESQUERDA4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};

void Vire_A_DIREITA1() {
  CoxaEsquerdaFrente.write(COXA_SOBE);
  CoxaDireitaMeio.write(COXA_SOBE);
  CoxaEsquerdaTraseira.write(COXA_SOBE);
  coxaDireitaFrente.write(COXA_DESCE);
  CoxaEsquerdaMeio.write(COXA_DESCE);
  CoxaDireitaTraseira.write(COXA_DESCE);
  delay(TEMPO1);
};
void Vire_A_DIREITA2() {
  PernaEsquerdaFrente.write(DESCE);
  PernaDireitaMeio.write(DESCE);
  PernaEsquerdaTraseira.write(DESCE);
  pernaDireitaFrente.write(SOBE);
  PernaEsquerdaMeio.write(SOBE);
  PernaDireitaTraseira.write(DESCE);
  delay(TEMPO2);
};
void Vire_A_DIREITA3() {
  CoxaEsquerdaFrente.write(COXA_DESCE);
  CoxaDireitaMeio.write(COXA_DESCE);
  CoxaEsquerdaTraseira.write(COXA_DESCE);
  coxaDireitaFrente.write(COXA_SOBE);
  CoxaEsquerdaMeio.write(COXA_SOBE);
  CoxaDireitaTraseira.write(COXA_SOBE);
  delay(TEMPO3);
};
void Vire_A_DIREITA4() {
  PernaEsquerdaFrente.write(SOBE);
  PernaDireitaMeio.write(SOBE);
  PernaEsquerdaTraseira.write(SOBE);
  pernaDireitaFrente.write(DESCE);
  PernaEsquerdaMeio.write(DESCE);
  PernaDireitaTraseira.write(SOBE);
  delay(TEMPO4);
};
