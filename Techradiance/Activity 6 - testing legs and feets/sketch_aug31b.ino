
void setup() 
{
  pinMode(13,OUTPUT);
}
void loop() 
{
  digitalWrite(13, HIGH);
  delay(300);   //wait for a second
  digitalWrite(13, LOW);
  delay(300);   //wait for a second
}