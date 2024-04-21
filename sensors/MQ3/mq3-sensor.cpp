#include <wiringPi.h>
#include <iostream>

#define MQ3_PIN 2
#define RED_PIN 5
#define GREEN_PIN 8


int main() {
    // Initialize WiringPi library
    if (wiringPiSetup() == -1) {
        std::cerr << "Failed to initialize WiringPi library" << std::endl;
        return 1;
    }

    // Set pin mode to input
    pinMode(RED_PIN, OUTPUT);
    // Set pin for leds mode to output
    pinMode(GREEN_PIN, OUTPUT);
    // Clear led status
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);

    while (true) {
        // Read digital value from sensor
        int sensorValue = digitalRead(MQ3_PIN);

        // Print the sensor value
        std::cout << "MQ-3 Sensor Digital Output: " << sensorValue << std::endl;
        if (sensorValue == 0) 
        { 

            std::cout << "Alcohol is detected! " << std::endl;
            digitalWrite(GREEN_PIN, LOW);
            digitalWrite(RED_PIN, HIGH);
        }
        else if (sensorValue == 1)
        { 
            std::cout << "No Alcohol detected! " << std::endl; 
            digitalWrite(GREEN_PIN, HIGH);
            digitalWrite(RED_PIN, LOW);
        }

        // Delay for some time before reading again
        delay(2000); // Delay for 2 seconds
    }

    return 0;
}
