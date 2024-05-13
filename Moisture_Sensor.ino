int ledPinB = 32;
int ledPinW = 33;
int analogPin = 34; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int val = 0;
void setup() {
  pinMode(ledPinB, OUTPUT);  // sets the pin as output
  pinMode(ledPinW, OUTPUT);  // sets the pin as output
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);  //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ Soil Moisture Sensor Module v1
  int mappedValue = map(val, 0, 2920, 0, 100);
  Serial.print("percen = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(mappedValue); // พิมพ์ค่าของตัวแปร val
  if (mappedValue < 60) { 
    digitalWrite(ledPinW, HIGH); // สั่งให้ LED ที่ Pin3 ติดสว่าง
    delay(1000);
    digitalWrite(ledPinW, LOW); // สั่งให้ LED ที่ Pin2 ดับ
    delay(1000);
  }
  else {
    digitalWrite(ledPinB, HIGH); // สั่งให้ LED ที่ Pin2 ติดสว่าง
    delay(1000);
    digitalWrite(ledPinB, LOW); // สั่งให้ LED ที่ Pin3 ดับ
    delay(1000);
  }
  delay(100);
}