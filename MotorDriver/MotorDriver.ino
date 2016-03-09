void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void run_motor_forward(int enable, int forward, int backward, int percentage) {
    digitalWrite(enable, HIGH);
    digitalWrite(backward, LOW);
    
    int delay = 10 * percentage;
    digitalWrite(forward, HIGH);
    delayMicroseconds(delay);
    digitalWrite(forward, LOW);
    delayMicroseconds(1000 - delay);
}

void run_motor_backward(int enable, int forward, int backward, int percentage) {
    digitalWrite(enable, HIGH);
    digitalWrite(forward, LOW);
    
    int delay = 10 * percentage;
    digitalWrite(backward, HIGH);
    delayMicroseconds(delay);
    digitalWrite(backward, LOW);
    delayMicroseconds(1000 - delay);
}

void motor_stop(int enable, int forward, int backward){
  digitalWrite(enable, LOW);
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);
}

unsigned long startTime = 0;

void loop() {
    /*run_motor_forward(2, 3, 4, 100);
    delay(2000);
    run_motor_forward(2, 3, 4, 50);
    delay(2000);
    run_motor_forward(2, 3, 4, 30);
    delay(2000);*/
    //delay(1000);
    //motor_stop(2, 3, 4);
    //delay(1000);
   // run_motor_backward(2, 3, 4, 100);
    unsigned long loopTime = millis() - startTime; //Calculate the time since last time the cycle was completed
 
    if (loopTime <= 4000) //Check if the time is less than 1000 millis, and if so, run loop 1
    {
      //Serial.println("Loop 1");
      run_motor_forward(2, 3, 4, 100);
    }
    else if (loopTime > 4000 && loopTime <= 8000) //If time is over 1000 millis and less than/or 2000 millis, run loop 2
    {
      //Serial.println("Loop 2");
      run_motor_forward(2, 3, 4, 50);
    }
    else if(loopTime > 8000 && loopTime <= 12000) //If time is over 2000 millis, set the startTime to millis so the loop time will be reset to zero
    {
      //startTime = millis();
      run_motor_forward(2, 3, 4, 20);
    }
    else
    {
      startTime = millis();
    }
 
 //delay(250); //Only here to prevent spamming serial monitor too much
}

