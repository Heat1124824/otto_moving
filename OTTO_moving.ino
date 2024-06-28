//馬達 搖桿 VCC:13V(5V) Data：12S Command：11S Clock：13S Attention：10S GND:13G
#include "PS2X_lib.h"  // 引入PS2X庫
#include <Servo.h>     // 引入伺服馬達庫
#include <Otto.h>      // 引入Otto機器人庫
#include <CuteBuzzerSounds.h>  // 引入蜂鳴器聲音庫
#include <Ultrasonic.h>

PS2X ps2x;  // 創建PS2控制器對象
int error;
int X, Y, Val;
int i = 0;
Otto Otto;  // 創建Otto機器人對象
Ultrasonic ultrasonic(8, 9);

// 定義伺服馬達接腳
#define LeftLeg 2      // 左腿
#define RightLeg 3     // 右腿
#define LeftFoot 4     // 左腳
#define RightFoot 5    // 右腳
#define PIN_AL 6       // 左手
#define PIN_AR 7       // 右手

#define Buzzer A5     // 蜂鳴器接腳
Servo servo_2, servo_3, servo_4, servo_5, AL, AR;  // 定義伺服馬達對象

// 超聲波測距簡單實現函數
int ultrasound_distance_simple() {
  int distance;
  distance = ultrasonic.read();
  Serial.println(distance);
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(A5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  cute.init(Buzzer);
  cute.play(S_CONNECTION);
  servo_2.attach(LeftLeg);
  servo_3.attach(RightLeg);
  servo_4.attach(LeftFoot);
  servo_5.attach(RightFoot);
  AL.attach(PIN_AL);
  AR.attach(PIN_AR);
  delay(100);

  servo_2.write(90);
  servo_3.write(90);
  servo_4.write(90);
  servo_5.write(90);
  AL.write(90); 
  AR.write(90);

  delay(50);
  servo_2.detach();
  servo_3.detach();
  servo_4.detach();
  servo_5.detach();
  AL.detach();
  AR.detach();
  Serial.println("Set up ");

  do {
    //GamePad(clock, command, attention, data, Pressures?, Rumble?)
    error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    if (error == 0) {
      Serial.println("Gamepad found!");
      break;
    }
    else {
      delay(100);
    }
  } while (1);
}

void forward(){
    servo_2.attach(2);
    servo_3.attach(3);
    servo_4.attach(4);
    servo_5.attach(5);

    //Right foot step
    for (int i = 90 ; i <= 120; i += 2) {
        servo_4.write(i);
        delay(5);
    }
    for (int i = 90 ; i <= 120; i += 2) {
        servo_5.write(i);
        delay(5);
    }
    for (int i = 90 ; i <= 120; i += 1) {
        servo_3.write(180-i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_5.write(i);
        delay(5);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_4.write(i);
        delay(5);
    }
    for (int i = 120 ; i >= 90; i -= 1) {
        servo_3.write(180-i);
        delay(10);
    }
    //Left foot step
    for (int i = 90 ; i <= 110; i += 2) {
        servo_5.write(180-i);
        delay(5);
    }
    for (int i = 90 ; i <= 110; i += 2) {
        servo_4.write(180-i);
        delay(5);
    }
    for (int i = 90 ; i <= 110; i += 1) {
        servo_2.write(i);
        delay(10);
    }
    for (int i = 110 ; i >= 90; i -= 2) {
        servo_4.write(180-i);
        delay(5);
    }
    for (int i = 110 ; i >= 90; i -= 2) {
        servo_5.write(180-i);
        delay(5);
    }
    for (int i = 110 ; i >= 90; i -= 1) {
        servo_2.write(i);
        delay(10);
    }
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
}

void back(){
    servo_2.attach(2);
    servo_3.attach(3);
    servo_4.attach(4);
    servo_5.attach(5);
    //Right foot
    for (int i = 90 ; i <= 120; i += 2) {
        servo_4.write(i);
        delay(5);
    }
    for (int i = 90 ; i <= 120; i += 2) {
        servo_5.write(i);
        delay(5);
    }
    for (int i = 90 ; i <= 120; i += 1) {
        servo_3.write(i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_5.write(i);
        delay(5);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_4.write(i);
        delay(5);
    }
    for (int i = 120 ; i >= 90; i -= 1) {
        servo_3.write(i);
        delay(10);
    }
    // Left foot
    for (int i = 90 ; i <= 110; i += 2) {
        servo_5.write(180-i);
        delay(5);
    }
    for (int i = 90 ; i <= 110; i += 2) {
        servo_4.write(180-i);
        delay(5);
    }
    for (int i = 90 ; i <= 110; i += 1) {
        servo_2.write(180-i);
        delay(10);
    }
    for (int i = 110 ; i >= 90; i -= 2) {
        servo_4.write(180-i);
        delay(5);
    }
    for (int i = 110 ; i >= 90; i -= 2) {
        servo_5.write(180-i);
        delay(5);
    }
    for (int i = 110 ; i >= 90; i -= 1) {
        servo_2.write(180-i);
        delay(10);
    }
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
}

void right(){
    servo_2.attach(2);
    servo_3.attach(3);
    servo_4.attach(4);
    servo_5.attach(5);

    //Right foot step
    for (int i = 90 ; i <= 120; i += 2) {
        servo_4.write(i);
        delay(10);
    }
    for (int i = 90 ; i <= 120; i += 2) {
        servo_5.write(i);
        delay(10);
    }
    for (int i = 90 ; i <= 120; i += 1) {
        servo_3.write(180-i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_5.write(i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_4.write(i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 1) {
        servo_3.write(180-i);
        delay(20);
    }
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
}

void left(){
    servo_2.attach(2);
    servo_3.attach(3);
    servo_4.attach(4);
    servo_5.attach(5);

    for (int i = 90 ; i <= 120; i += 2) {
        servo_5.write(180-i);
        delay(10);
    }
    for (int i = 90 ; i <= 120; i += 2) {
        servo_4.write(180-i);
        delay(10);
    }
    for (int i = 90 ; i <= 110; i += 1) {
        servo_2.write(i);
        delay(20);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_4.write(180-i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 2) {
        servo_5.write(180-i);
        delay(10);
    }
    for (int i = 120 ; i >= 90; i -= 1) {
        servo_2.write(i);
        delay(10);
    }
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
}

void loop() {
  ps2x.read_gamepad(false, 0);

  if (ps2x.Button(PSB_START))  {
    Serial.println("Start is being held");
    
  }
  else if (ps2x.Button(PSB_SELECT)) {
    AL.attach(PIN_AL);
    AR.attach(PIN_AR);
    servo_4.attach(4);
    servo_5.attach(5);
    for (int i = 90; i <= 135; i += 2) {
        AL.write(i);
        AR.write(i);
        servo_4.write(i);
        servo_5.write(i);
        delay(30);
    }
    delay(3000);
    for (int i = 135; i >= 90; i -= 2) {
        AL.write(i);
        AR.write(i);
        servo_4.write(i);
        servo_5.write(i);
        delay(30);
    }
    AL.detach();
    AR.detach();
    servo_4.detach();
    servo_5.detach();
    delay(200);
  }
  else if (ps2x.Button(PSB_PAD_UP)) {
    Serial.println("FOR");
    forward();
    if (ultrasound_distance_simple() < 10) {
      cute.play(S_CONFUSED);
      for (int count = 0 ; count < 2 ; count++) {
        back();
      }
      delay(50);
    }
    delay(200);
  }
  else if (ps2x.Button(PSB_PAD_DOWN)) {
    back();
    delay(200);
  }
  else if (ps2x.Button(PSB_PAD_RIGHT)) {
    right();
    delay(200);
  }
  else if (ps2x.Button(PSB_PAD_LEFT)) {
    left();
    delay(200);
  }
  else if (ps2x.Button(PSB_TRIANGLE)) {
    AR.attach(PIN_AR);
    cute.play(S_HAPPY);
    for (int i = 90 ; i <= 150; i += 3) {
        AR.write(180-i);
        delay(10);
    }
    AR.detach();
    delay(100);
  }
  else if (ps2x.Button(PSB_SQUARE)) {
    AL.attach(PIN_AL);
    AR.attach(PIN_AR);
    for (int i = 90 ; i <= 150; i += 3) {
        AL.write(i);
        AR.write(180-i);
        delay(10);
    }
    cute.play(S_SURPRISE);
    AL.detach();
    AR.detach();
    delay(100);
  }
  else if (ps2x.Button(PSB_CROSS)) {
    AL.attach(PIN_AL);
    AR.attach(PIN_AR);
    servo_4.attach(4);
    servo_5.attach(5);
    cute.play(S_SAD);
    for (int i = 90 ; i <= 150; i += 3) {
        AL.write(180-i);
        AR.write(i);
        servo_4.write(180-i);
        servo_5.write(i);
        delay(30);
    }
    delay(20);
    cute.play(S_SLEEPING);
    for (int i = 150 ; i >= 90; i -= 3) {
        AL.write(180-i);
        AR.write(i);
        servo_4.write(180-i);
        servo_5.write(i);
        delay(30);
    }
    AL.detach();
    AR.detach();
    servo_4.detach();
    servo_5.detach();
    delay(100);
  }
  else if (ps2x.Button(PSB_CIRCLE)) {
    servo_2.attach(2);
    servo_3.attach(3);
    servo_4.attach(4);
    servo_5.attach(5);
    cute.play(S_OHOOH);
    for (int i = 90 ; i <= 150; i += 3) {
        servo_2.write(i);
        servo_3.write(i);
        delay(20);
    }
    for (int i = 150 ; i >= 90; i -= 3) {
        servo_2.write(i);
        servo_3.write(i);
        delay(20);
    }
    for (int i = 90 ; i <= 150; i += 3) {
        servo_2.write(180-i);
        servo_3.write(180-i);
        delay(20);
    }
    for (int i = 150 ; i >= 90; i -= 3) {
        servo_2.write(180-i);
        servo_3.write(180-i);
        delay(20);
    }
    for (int k = 1; k <= 2; k++){
      for (int i = 90 ; i <= 150; i += 3) {
          servo_4.write(i);
          servo_5.write(180-i);
          delay(20);
      }
      for (int i = 150 ; i >= 90; i -= 3) {
          servo_4.write(i);
          servo_5.write(180-i);
          delay(20);
      }
    }
    servo_2.detach();
    servo_3.detach();
    servo_4.detach();
    servo_5.detach();
    delay(100);
  }
  else{
  servo_2.attach(LeftLeg);
  servo_3.attach(RightLeg);
  servo_4.attach(LeftFoot);
  servo_5.attach(RightFoot);
  AL.attach(PIN_AL);
  AR.attach(PIN_AR);
  delay(100);

  servo_2.write(90);
  servo_3.write(90);
  servo_4.write(90);
  servo_5.write(90);
  AL.write(90); 
  AR.write(90);

  delay(50);
  servo_2.detach();
  servo_3.detach();
  servo_4.detach();
  servo_5.detach();
  AL.detach();
  AR.detach();

  }
  
}
