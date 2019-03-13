int pino = 7;

void setup()
{

  pinMode(pino, INPUT);
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(pino));
}
