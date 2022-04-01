// Mechatronics - Spring 2022
// Code to test three linear actuators using an Arduino Uno.
// Uses this quad motor shield: https://wiki.dfrobot.com/Quad_Motor_Driver_Shield_for_Arduino_SKU_DRI0039

// M1 controls the LA pair; M3 controls the solo LA

const int M1 = 1;
// const int M2 = 2;
const int M3 = 3;
// const int M4 = 4;

const int M1_SPEED = 3;
// const int M2_SPEED = 11;
const int M3_SPEED = 5;
// const int M4_SPEED = 6;

const int M1_DIRECTION = 4;
// const int M2_DIRECTION = 12;
const int M3_DIRECTION = 8;
// const int M4_DIRECTION = 7;

void setup()
{
  pinMode(M1_SPEED, OUTPUT);
  // pinMode(M2_SPEED, OUTPUT);
  pinMode(M3_SPEED, OUTPUT);
  // pinMode(M4_SPEED, OUTPUT);
  
  pinMode(M1_DIRECTION, OUTPUT);
  // pinMode(M2_DIRECTION, OUTPUT);
  pinMode(M3_DIRECTION, OUTPUT);
  // pinMode(M4_DIRECTION, OUTPUT);
}

void spin_motor(int motor, int speed)
{
  switch (motor)
  {
    case 1:
      if (speed < 0)
      {
        digitalWrite(M1_DIRECTION, HIGH); // go backwards
        analogWrite(M1_SPEED, abs(speed)); // change speed
      }
      else
      {
        digitalWrite(M1_DIRECTION, LOW); // go forwards
        analogWrite(M1_SPEED, speed); // change speed
      }
    break;
    
    // case 2:
    //   if (speed > 0)
    //   {
    //     digitalWrite(M2_DIRECTION, HIGH); // go forwards
    //     analogWrite(M2_SPEED, speed); // change speed
    //   }
    //   else
    //   {
    //     digitalWrite(M2_DIRECTION, LOW); // go backwards
    //     analogWrite(M2_SPEED, abs(speed)); // change speed
    //   }
    // break;
    
    case 3:
      if (speed < 0)
      {
        digitalWrite(M3_DIRECTION, HIGH); // go backwards
        analogWrite(M3_SPEED, abs(speed)); // change speed
      }
      else
      {
        digitalWrite(M3_DIRECTION, LOW); // go forwards
        analogWrite(M3_SPEED, speed); // change speed
      }
    break;
    
    // case 4:
    //   if (speed > 0)
    //   {
    //     digitalWrite(M4_DIRECTION, HIGH); // go forwards
    //     analogWrite(M4_SPEED, speed); // change speed
    //   }
    //   else
    //   {
    //     digitalWrite(M4_DIRECTION, LOW); // go backwards
    //     analogWrite(M4_SPEED, abs(speed)); // change speed
    //   }
    // break;
    
    default:
    break;
  }
}

void loop()
{
  // extend
  spin_motor(M1, 255);
  spin_motor(M3, 255);
  delay(5000);
  
  // retract
  spin_motor(M1, -255);
  spin_motor(M3, -255);
  delay(5000);
}
