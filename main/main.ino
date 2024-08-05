/***************************************************************************/
/****该代码采集了Arudino的六个AD引脚，是可以读取6个肌肉电模块的程序***************/
/****如不修改代码而仅使用单块传感器，请注意传感器SIG引脚接入哪个Arduino的AD引脚****/
/**************************************************************************/
int analogInput[6] = {A0, A1, A2, A3, A4, A5};
int value[6] = {0, 0, 0, 0, 0, 0};  
 
void setup()
{
  for(int i=0;i<6;i++)
  {
  	pinMode(analogInput[i], INPUT);  
  }
  Serial.begin(9600);
}

void loop()
{
  for(int i=0;i<6;i++)
  {
    value[i] = analogRead(analogInput[i]);
  }
  Serial.print(value[0]);Serial.print(",");
  Serial.print(value[1]);Serial.print(",");
  Serial.print(value[2]);Serial.print(",");
  Serial.print(value[3]);Serial.print(",");
  Serial.print(value[4]);Serial.print(",");
  Serial.println(value[5]);
  delay(10);
}