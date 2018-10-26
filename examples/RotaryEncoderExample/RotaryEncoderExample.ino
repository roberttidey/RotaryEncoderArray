/*
 R. J. Tidey 2019/10/26
 Rotary Encoder Example
 */
#define ESP8266

#include <RotaryEncoderArray.h>

#define dfltROTARY_PIN1 5
#define dfltROTARY_PIN2 4
#define dfltROTARY_BUTTON 12

int lastRotaryPosition;

/*
  Set up
*/
void setup() {
	Serial.begin(115200);
	//initialise encoder library, interrupts on
	rotaryEncoderInit(1);
	// Define GPIO for encoder 0
	setRotaryEncoderPins(0, dfltROTARY_PIN1, dfltROTARY_PIN2, dfltROTARY_BUTTON);
	// Set limits for encoder 0
	setRotaryLimits(0, 0, 99);
	lastRotaryPosition = 50;
	setRotaryPosition(0, lastRotaryPosition);
	Serial.println("Set up complete");
}


/*
  Main loop
*/
int position;
int pulse;
void loop() {
	position = getRotaryPosition(0);
	pulse = getRotaryButtonPulse(0);
	if((lastRotaryPosition != position) || (pulse > 0)) {
		Serial.println("Rotary position = " + String(position));
		Serial.println("Rotary direction = " + String(getRotaryDirection(0)));
		Serial.println("Button pulse = " + String(pulse));
		lastRotaryPosition = position;
	}
}

