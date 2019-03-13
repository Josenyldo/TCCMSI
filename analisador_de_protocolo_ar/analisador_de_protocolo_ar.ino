int pino = 7;
int leituraPino = 0;
int palvraBinaria[200];
int tempo_total = 0;
int meutempo = 0;
int cont = 1;
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
    palvraBinaria[cont] = digitalRead(pino);
    meutempo = millis();
    cont++;
    while(1)
    {   
      leituraPino = digitalRead(pino);
      palvraBinaria[cont] = leituraPino;
      cont++;
      tempo_total = millis() - meutempo;
      if(leituraPino == 1 && tempo_total > 0.001 )
      {
        
      }
    }
    
  }
}

