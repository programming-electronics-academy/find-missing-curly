/*
  
  You're job is to find all the missing curly braces in this code.

  When you have doen this successfully, the code should compile without errors.

  Good luck!

  -Programming Electronics Academy
*/


const int buttonPin = 2;   // the pin that the pushbutton is attached to
const int fadeLEDPin = 9;  // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;  // counter for the number of button presses
int buttonState = 0;        // current state of the button
int lastButtonState = 0;    // previous state of the button

// constants won't change. Used here to set a pin number:
const int buttonLEDPin = 13;  // the number of the LED pin
const int millisLEDPin = 12;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds)


void setup() 
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(fadeLEDPin, OUTPUT);
  pinMode(buttonLEDPin, OUTPUT);
  pinMode(millisLEDPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) 
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else 
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 0) 
    digitalWrite(buttonLEDPin, HIGH);
    Serial.println("You wouldn't...");
  } else 
    digitalWrite(buttonLEDPin, LOW);
  }

  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) 
    // sets the value (range from 0 to 255):
    analogWrite(fadeLEDPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
    Serial.println("How dare you!");
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) 
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(millisLEDPin, ledState);
  }
}
