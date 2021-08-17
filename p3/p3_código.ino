#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

int valorX = 0; // VARIABLE DE LECTURA DEL EJE X
int pinJX = A0; // EJE X CONECTADO AL PIN ANALOGICO A0
int pinJY = A1; // EJE Y COENCTADO AL PIN ANALOGIC0 A1
 
// Secuencia de pasos (par máximo)
int clockwise [4][4] = {
  {0, 0, 1, 1},
  {0, 1, 1, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 1}
};

int counterclockwise [4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

int Delay;

void setup(){
  // Todos los pines en modo salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
};

void turnright(){
  for (int i = 0; i < 4; i++){
     Delay = map (valorX, 500, 0, 250, 1);
     digitalWrite(IN1, clockwise[i][0]);
     digitalWrite(IN2, clockwise[i][1]);
     digitalWrite(IN3, clockwise[i][2]);
     digitalWrite(IN4, clockwise[i][3]);
     delay(Delay); 
  }
}
void turnleft(){
  for (int i = 0; i < 4; i++){
     Delay = map (valorX, 520, 1023, 250, 1);
     digitalWrite(IN1, counterclockwise[i][0]);
     digitalWrite(IN2, counterclockwise[i][1]);
     digitalWrite(IN3, counterclockwise[i][2]);
     digitalWrite(IN4, counterclockwise[i][3]); 
     delay(Delay);
  }
} 
void loop(){ 
    valorX = analogRead ( pinJX); // LECTURA DEL PUERTO ANALOG. A0 DEL EJE X
    
    if (valorX < 500){
      turnright(); 
    } 
      
    if (valorX > 520) {
      turnleft();
    } 
}
