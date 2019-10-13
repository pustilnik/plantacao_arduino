#define turn_on 9
#define humidity_analog A0
#define on_command 8
#define tempo_aquisicao 36000000000
#include <TimerOne.h>


volatile int umidade;
volatile int dig_umidade;
int counter = 0;

void meter(){
  
  
  if (digitalRead(on_command) != HIGH && counter == 10)
    {digitalWrite(on_command,HIGH);}
  while (digitalRead(on_command)!=1)
    {}
  umidade = analogRead(humidity_analog);
  dig_umidade = digitalRead(11);
  Serial.println("Umidade:");
  Serial.println(umidade);
  //Serial.println("\n");
  Serial.println(dig_umidade);
 
  counter++;
  Serial.println("Contagem:");
  Serial.println(counter);
  if (counter == 10)
    {
    digitalWrite(on_command,LOW);
    counter = 0;
    }
 // 
}

void setup() {

  Serial.begin(9600); 
  pinMode(humidity_analog, INPUT);
  pinMode(on_command,OUTPUT); 
  pinMode(11,INPUT);
  Timer1.initialize(tempo_aquisicao);
  Timer1.attachInterrupt(meter);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
