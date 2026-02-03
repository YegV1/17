void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
long A=0;
long B=0;
bool generate=1;
long Bin=0;
void loop() {

  Serial.flush();
  while(!Serial.available()){
    if(generate){
      A=0;
      B=0;
      Bin=random(65535);
      Serial.println();
      Serial.print("Convert to decmal: ");
      Serial.print(Bin,BIN);
      generate=0;
    }
  }
while(Serial.available()){
  A=Serial.read()-'0';
  A=A+B;
  B=(A*10);
  delay(5);
}
if(A==Bin){
  Serial.println();
  Serial.print("correct");
  generate=1;
}
if(A!=Bin){
  Serial.println();
  Serial.print("incorrect");
  Serial.print(Bin);
  generate=1;
}
}