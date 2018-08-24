int pin_ir = 10;
int leitura_ir = 0;
void setup() {
  pinMode(pin_ir, INPUT);
  Serial.begin(9600);

}
int cont = 0;
void loop() {
  leitura_ir = digitalRead(pin_ir);
  Serial.print(leitura_ir);
  if (leitura_ir == 0)
  { while (cont < 200) {
    
      leitura_ir = digitalRead(pin_ir);
      Serial.print(leitura_ir);
        cont++;

    }
    delay(2000000000);
  }
}
