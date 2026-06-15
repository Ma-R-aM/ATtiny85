#include <avr/wdt.h>
#include <avr/sleep.h>

const int s = 100; //trvanie efektu v milisec
unsigned long startTime;
const unsigned long RUN_TIME = 19000; // 30 sekúnd

// LED 
void allHighZ() {
  for (int i = 0; i <= 4; i++) {
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  }
}

void lightLED(uint8_t anode, uint8_t cathode) {
  allHighZ();
  pinMode(anode, OUTPUT);
  digitalWrite(anode, HIGH);
  pinMode(cathode, OUTPUT);
  digitalWrite(cathode, LOW);
}

// vypnutie
void goSleep() {
  allHighZ();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu(); 
}

//zaciatok
void setup() {
  // reset z watchdog?
  if (MCUSR & _BV(WDRF)) {
    MCUSR = 0;
    wdt_disable();
    goSleep();   // ak ano, vypnúť
  }

  MCUSR = 0;
  wdt_enable(WDTO_8S);   // watchdog 8 s
  startTime = millis();
  allHighZ();
}

//loopik
void loop() {

  // cas behu je viac nez nastaveny watchdog? vypni / dalsi loop
  if (millis() - startTime > RUN_TIME) {
    allHighZ();
    while (1);  // watchdog urobí reset
  }

  //beh animacie
  lightLED(2,3); delay(s); wdt_reset();
  lightLED(3,2); delay(s); wdt_reset();

  lightLED(1,3); delay(s); wdt_reset();
  lightLED(3,1); delay(s); wdt_reset();

  lightLED(0,3); delay(s); wdt_reset();
  lightLED(3,0); delay(s); wdt_reset();

  lightLED(2,4); delay(s); wdt_reset();
  lightLED(4,2); delay(s); wdt_reset();

  lightLED(1,4); delay(s); wdt_reset();
  lightLED(4,1); delay(s); wdt_reset();

  lightLED(0,4); delay(s); wdt_reset();
  lightLED(4,0); delay(s); wdt_reset();

  lightLED(2,3); delay(s); wdt_reset();

  lightLED(4,0); delay(s); wdt_reset();
  lightLED(0,4); delay(s); wdt_reset();

  lightLED(4,1); delay(s); wdt_reset();
  lightLED(1,4); delay(s); wdt_reset();

  lightLED(4,2); delay(s); wdt_reset();
  lightLED(2,4); delay(s); wdt_reset();

  lightLED(3,0); delay(s); wdt_reset();
  lightLED(0,3); delay(s); wdt_reset();

  lightLED(3,1); delay(s); wdt_reset();
  lightLED(1,3); delay(s); wdt_reset();

  lightLED(3,2); delay(s); wdt_reset();

  lightLED(2,3); delay(s); wdt_reset();

  delay(s/2);

unsigned long zac = millis(); //premenna na time

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }


  lightLED(2,4); delay(s); wdt_reset();


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  lightLED(2,3); delay(s); wdt_reset();

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(2,3); wdt_reset();
      lightLED(3,2); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(1,3); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(3,1); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(0,3); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(3,0); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(2,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(2,4); wdt_reset();
      lightLED(4,2); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,2); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(1,4); wdt_reset();
      lightLED(4,1); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,1); wdt_reset();
      lightLED(0,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(0,4); wdt_reset();
      lightLED(4,0); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,0); wdt_reset();
      lightLED(2,3); wdt_reset();
    }


  lightLED(2,3); delay(s); wdt_reset();


  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,0); wdt_reset();
      lightLED(2,3); wdt_reset();
    }


  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(0,4); wdt_reset();
      lightLED(4,0); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,1); wdt_reset();
      lightLED(0,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(1,4); wdt_reset();
      lightLED(4,1); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(4,2); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(2,4); wdt_reset();
      lightLED(4,2); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(2,4); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(3,0); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(0,3); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(3,1); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(1,3); wdt_reset();
    }

  zac = millis();
  while (millis() - zac < s) 
    {
      lightLED(2,3); wdt_reset();
      lightLED(3,2); wdt_reset();
    }


  lightLED(2,3); delay(s); wdt_reset();


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }


  lightLED(2,4); delay(s); wdt_reset();


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  lightLED(2,3); delay(s); wdt_reset();





  //dvojite srdecko
  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();

      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();

      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();

      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
      
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }


  lightLED(2,4); delay(s); wdt_reset();


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();

      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,0); wdt_reset();
      lightLED(4,2); wdt_reset();

      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
    }


  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(0,3); wdt_reset();
      lightLED(1,4); wdt_reset();
      
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,1); wdt_reset();
      lightLED(4,1); wdt_reset();

      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();
    }

zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(1,3); wdt_reset();
      lightLED(0,4); wdt_reset();

      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }

  zac = millis();

  while (millis() - zac < s) 
    {
      lightLED(3,2); wdt_reset();
      lightLED(4,0); wdt_reset();
    }


  lightLED(2,3); delay(s); wdt_reset();
  
}
