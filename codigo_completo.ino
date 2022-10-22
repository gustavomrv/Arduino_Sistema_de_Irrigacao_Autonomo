// Bibliotecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int sensorPin = A0;  // Seleciona o pino de entrada analogico que o sensor de agua está utilizando
int sensorPinUmidade = A2;  // Seleciona o pino de entrada analogico que o sensor de umidade está utilizando
int sensorValue = 0; // Armazena o valor que está recebendo do sensor
int leituraSensorUmidade;

// Setar o nº de colunas e linhas do display
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void printar_lcd(double res){
  // Serial.println(res); 
  lcd.setCursor(0, 0);
  if(res <= 180){
    lcd.print("Nivel baixo");
  }
  else if(res <= 360){
    lcd.print("Nivel medio");
  }
  else {
    lcd.print("Nivel alto");
  }

  lcd.setCursor(0, 1);
  lcd.print("Aprox. ");
  lcd.print(res);
  lcd.print(" ml");  
}

void setup() {
  //Atuador
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);   // desliga a bomba      

  Serial.begin(9600); // Define o tempo de interação entre o arduino e o serial ArduinoIDE                       -
  lcd.init();
}

void loop() {
  lcd.setBacklight(HIGH); // Liga a luz de fundo do LCD
  sensorValue = analogRead(sensorPin); // Faz a leitura do valor que o sensor de nível está enviando
  leituraSensorUmidade = analogRead(A2); // Faz a leitura do sensor umidade

  //Verifica se o solo está umido
  if(leituraSensorUmidade <= 400){
    digitalWrite(12, HIGH);   // desliga a bomba      
  }else{
    digitalWrite(12, LOW); // liga a bomba
    delay(1000);
    digitalWrite(12, HIGH); // desliga a bomba 
  }


// Exibe a quantidade de ml no display LCD conforme o valor lido pelo sensor de nivel


  if(sensorValue <= 256 ){
    printar_lcd(0);
  }
  else if(sensorValue <= 305){ //50 ml
    double res = (sensorValue-250)*1;
    printar_lcd(res);
  }
  else if(sensorValue <= 325){ //100 ml
    double res = (sensorValue-200)*0.85;
    printar_lcd(res);
  }
  else if(sensorValue <= 345){ //150 ml
    double res = (sensorValue-200)*1.15;
    printar_lcd(res);
  }
  else if(sensorValue <= 361){ //200 ml
    double res = (sensorValue-200)*1.4;
    printar_lcd(res);
  }
  else if(sensorValue <= 375){ //250 ml
    double res = (sensorValue-200)*1.5;
    printar_lcd(res);
  }
  else if(sensorValue <= 390){ //300 ml
    double res = (sensorValue-200)*1.6;
    printar_lcd(res);
  }
  else if(sensorValue <= 398){ //350 ml
    double res = (sensorValue-200)*1.8;
    printar_lcd(res);
  }
  else if(sensorValue <= 425){ //400 ml
    double res = (sensorValue-200)*1.85;
    printar_lcd(res);
  }
  else if(sensorValue <= 460){ //450 ml
    double res = (sensorValue-200)*1.8;
    printar_lcd(res);
  }
  else if(sensorValue <= 485){ //500 ml
    double res = (sensorValue-200)*2.05;
    printar_lcd(res);
  }
  else if(sensorValue <= 550){ //550 ml
    double res = (sensorValue-200)*2.3;
    printar_lcd(res);
  }
  else{
    //double res = (sensorValue-400)*5;
    lcd.setCursor(0, 0);
    lcd.print("Calculando nivel: ");
    lcd.setCursor(0, 1);
    lcd.print("Carregando infos");
    //lcd.print(res);
    lcd.print(" ml");
  }
  

 Serial.println(sensorValue); 
 Serial.println(); 
 //Serial.println(leituraSensorUmidade); 
 delay(1000); // Atraso de 1 segundo
 lcd.clear(); // Limpa o display LCD
}
