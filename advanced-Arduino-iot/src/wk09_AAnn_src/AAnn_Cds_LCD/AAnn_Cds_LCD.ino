/*
 빛 입력 및 LCD 모니터링
*/
// LCD 라리브러리 설정
#include <LiquidCrystal.h>
// LCD 설정
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // rs,en,d4,d5,d6,d7
// 0번 아날로그핀을 CdS 셀 입력으로 설정한다.
const int CdSPin = 0;

void setup() { 
// 16X2 LCD 모듈 설정하고 백라이트를 켠다.
  lcd.begin(16,2);
// 메세지를 표시한다.
  lcd.print("AA00");
  lcd.setCursor(0,1);
  lcd.print("CdS Cell Test");
// 3초동안 메세지를 표시한다.
  delay(3000);
// 모든 메세지를 삭체한 뒤
// 숫자를 제외한 부분들을 미리 출력시킨다.
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AA00,ADC: ");
  lcd.setCursor(0,1);
  lcd.print("Light:  ");
  lcd.setCursor(13,1);
  lcd.print("%");  // 수정
}

void loop(){
  int adcValue; // 실제 센서로부터 읽은 값 (0~1023)
  int illuminance; // 현재의 밝기. 0~100%
      
  // CdS cell을 통하여 입력되는 전압을 읽는다.
  adcValue = analogRead(CdSPin);
  // 아날로그 입력 값을 0~100%의 범위로 변경한다..
  illuminance = map(adcValue, 0,1023, 0, 100);

  // 전에 표시했던 내용을 지운다.  
  lcd.setCursor(12,0);
  lcd.print("    "); 
  // ADC 값을 표시한다  
  lcd.setCursor(12,0);
  lcd.print(adcValue);
  // 전에 표시했던 내용을 지운다.
  lcd.setCursor(9,1);  
  lcd.print("   ");
  // 밝기를 %표시한다  
  lcd.setCursor(9,1);  
  lcd.print(illuminance);   // 수정
  delay(1000);
}

//Voltage to LuxLux
double luminosity (int RawADC0){
  double Vout=RawADC0*0.0048828125;  // 5/1024 (Vin = 5 V)
  int lux=(2500/Vout-500)/10;  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}

