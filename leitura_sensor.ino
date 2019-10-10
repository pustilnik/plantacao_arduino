#define humidity_digital 9
#define humidity_analog A0
#define on_command 8
#define tempo_aquisicao 3600000000
#include <TimerOne.h>
volatile float umidade;

void meter(){
  umidade = analogRead(humidity_analog);
  Serial.print("teste");
}

void setup() {

  Serial.begin(9600);  
  Timer1.initialize(tempo_aquisicao);
  Timer1.attachInterrupt(meter);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
