int pino = 7;
int leituraPino = 0;
int palvraBinaria[200];
int tempo_total = 0;
int meutempo = 0;
void setup()
{

  pinMode(pino, INPUT);
  Serial.begin(9600);
  
}
void loop()
{
  
  leituraPino = digitalRead(pino);
  //Serial.println(leituraPino);
  
  if(leituraPino == 0)
  {
    meutempo = millis();
    while(tempo_total < 2000)
    {   
      
      tempo_total = millis() - meutempo;
      Serial.print(tempo_total);
      Serial.print(" ");
      Serial.println("Nildao");
    }
    
  }
}

