
void setup() 
{
  pinMode(13,OUTPUT);
}
void loop() 
{
  digitalWrite(13, HIGH);
  delay(1000);   //wait for a second
  digitalWrite(13, LOW);
  delay(1000);   //wait for a second
}                 
