#include <MsTimer2.h>

#define SCK (10)
#define RCK (12)
#define SER (11)
#define A   (6)
#define B   (7)
#define C   (8)
#define EN  (9)

#define HIGH 1 
#define LOW  0

#define N 0
#define G 2
#define R 1
#define Y 3

byte Vram[8][8] = {{0}
  /*{N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},
  {N, G, R, Y, N, G, R, Y},*/
  };

byte Vram2[8][200] = {

//[8]*[16]
  /*{G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},
  {G, R, Y, N, G, R, Y, N, G, G, R, R, Y, Y, N, N},*/

//[8]*[92]
  /*{N, N, N, N, N, N, N, N, N, N, N, G, G, G, N, N, G, N, N, G, G, N, N, N, N, G, G, G, N, N, N, G, N, N, G, N, N, N, N, G, N, N, N, N, Y, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, R, N, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, G, N, G, N, G, N, N, G, N, N, N, N, N, N, G, N, G, N, G, G, N, N, N, N, G, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, Y, N, N, N, Y, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, G, N, N, G, N, N, N, G, N, N, G, N, N, N, G, N, N, G, G, N, N, N, N, G, N, N, N, N, Y, N, N, Y, N, N, N, N, N, N, N, N, Y, N, Y, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, N, R, R, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, G, N, N, N, N, N, N, G, G, G, G, N, N, N, N, G, N, N, N, G, N, N, N, N, N, Y, N, Y, N, Y, N, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, R, N, R, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, G, N, N, N, N, N, G, N, N, N, N, N, N, N, G, G, G, N, N, G, N, N, N, N, N, Y, N, N, Y, N, N, N, N, N, N, N, Y, N, Y, N, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, R, R, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, G, N, N, N, N, N, N, G, N, N, N, N, N, N, G, N, N, N, N, N, G, N, N, N, N, Y, N, N, N, Y, N, N, N, N, N, Y, N, N, N, Y, N, N, N, N, N, N, N, R, N, N, N, N, N, N, N, N, N, R, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, N, G, N, N, N, G, G, G, G, G, G, N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, Y, Y, Y, Y, N, Y, N, Y, N, N, N, N, N, Y, N, N, R, R, R, R, R, R, R, N, R, N, R, N, R, R, R, R, R, R, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
  {N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, N, G, N, N, N, N, N, G, N, N, N, N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, Y, N, N, N, Y, N, Y, N, N, N, N, N, N, N, Y, N, N, N, N, N, N, N, N, R, N, R, N, N, N, N, N, R, N, N, N, N, Y, Y, N, N, N, N, N, N, N, N, N, N},
*/

//[8]*[60]
//{N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, G, G, G, G, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, G, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, N, G, G, G, G, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}
//{N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N}



//[8]*[130] こうけんへようこそ
{N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,N,N,N,N,N,N,N,N,R,N,N,N,N,N,N,R,R,N,N,R,N,N,N,N,N,R,N,N,N,N,R,R,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,G,G,N,N,G,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,G,G,G,G,G,N,N,N,N,N,N,N,G,G,N,N,N,N,Y,N,Y,N,N,N,N,N,G,Y,R,G,Y,R,G,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,N,N,R,N,N,N,N,R,N,N,N,N,R,N,N,N,R,N,N,R,N,N,N,N,N,N,N,N,N,N,N,Y,Y,N,N,G,N,N,N,G,G,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,G,G,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,G,Y,R,G,Y,R,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,R,N,N,N,N,N,R,N,N,N,N,R,N,N,N,R,N,N,R,N,N,N,N,N,N,N,N,N,N,Y,N,N,N,N,N,G,G,G,G,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,Y,N,Y,N,N,N,N,N,Y,R,G,Y,R,G,Y,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,R,N,N,N,N,N,R,N,N,N,N,N,R,R,R,R,N,N,R,N,N,N,Y,Y,N,N,N,N,Y,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,Y,N,Y,N,N,N,N,N,G,Y,R,G,Y,R,G,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,N,N,R,N,N,N,R,N,N,R,R,R,R,R,N,N,N,N,R,N,N,N,N,N,R,N,N,N,N,N,Y,N,N,Y,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,G,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,G,G,G,G,G,G,N,N,N,Y,N,Y,N,N,N,N,N,R,G,Y,R,G,Y,R,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,N,N,N,N,R,N,N,N,N,N,R,N,N,N,N,N,R,N,N,N,N,N,N,N,N,N,N,N,N,Y,Y,N,N,N,N,N,N,N,N,N,N,N,G,G,G,G,N,N,N,N,G,G,G,G,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,Y,N,Y,N,N,N,N,N,Y,R,G,Y,R,G,Y,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,R,N,N,N,N,R,N,N,N,N,N,N,R,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,G,N,N,N,N,N,N,G,G,N,N,N,N,N,Y,N,Y,N,N,N,N,N,G,Y,R,G,Y,R,G,N,N,N,N,N,N,N},
{N,N,N,N,N,N,N,N,N,N,N,R,R,R,R,R,R,N,N,N,N,N,N,N,R,R,R,R,N,N,N,N,N,R,N,N,N,N,R,N,N,N,N,N,N,R,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,N,G,N,N,N,N,N,N,N,N,G,G,G,G,N,N,N,N,N,G,G,G,G,G,N,N,N,N,N,N,G,G,G,G,G,N,N,N,N,Y,N,Y,N,N,N,N,N,R,G,Y,R,G,Y,R,N,N,N,N,N,N,N}




};
  

void drawled(){  //timer割込み

  byte i;
  
  static byte raw = 0;
  digitalWrite(SCK, LOW);
  digitalWrite(RCK, LOW);


 for (byte i=0; i<8; i++){

  digitalWrite(SER, (Vram[raw][i] & G)? LOW:HIGH); //ビットマスク
  delayMicroseconds(10);
  digitalWrite(SCK, HIGH);
  delayMicroseconds(10);
  digitalWrite(SCK, LOW);
  digitalWrite(SER, (Vram[raw][i] & R)? LOW:HIGH); //ビットマスク&参考演算子
  delayMicroseconds(10);
  digitalWrite(SCK, HIGH);
  delayMicroseconds(10);
  digitalWrite(SCK, LOW);
};

  digitalWrite(EN, LOW);
  digitalWrite(RCK, HIGH);

  digitalWrite(A, raw & 0b00000001);
  digitalWrite(B, raw & 0b00000010);
  digitalWrite(C, raw & 0b00000100);

  digitalWrite(EN, HIGH);

  raw =(raw + 1)%8;
  
}


void setup() {
  pinMode(SCK, OUTPUT);
  pinMode(RCK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(EN, OUTPUT);

  MsTimer2::set(1, drawled);
  MsTimer2::start();
  
}

void loop() {
    byte i=0;
    byte j=0;
    
//    for(i=0;i<8;i++){
//     Vram[4][4]=R;   //一点出力
//     delay(500);

     for (i=0; i<123; i++){
//     for (i=0; i<00; i++){
      Vram;
     delay(100);
     memcpy(Vram[0], (Vram2[0]+j), 8);
     memcpy(Vram[1], (Vram2[1]+j), 8);
     memcpy(Vram[2], (Vram2[2]+j), 8);
     memcpy(Vram[3], (Vram2[3]+j), 8);
     memcpy(Vram[4], (Vram2[4]+j), 8);
     memcpy(Vram[5], (Vram2[5]+j), 8);
     memcpy(Vram[6], (Vram2[6]+j), 8);
     memcpy(Vram[7], (Vram2[7]+j), 8);
     j = j+1;
    };
}
