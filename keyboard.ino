#include <HID-Project.h>
#include <HID-Settings.h>


byte rows[] = {4,5,6};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
byte colums[] = {1,2};
const int columCount = sizeof(colums)/sizeof(colums[0]);
bool done = false;
int layer = 0;
int mod = true;

bool keysDown[rowCount][columCount] = {
    {false,false},
    {false,false},
    {false,false},
};


//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define _BASE 0
#define _FN1 1

KeyboardKeycode key[][rowCount][columCount] = {
    [0] = {

        {KEY_LEFT_WINDOWS ,KEY_D},
        {KEY_D, KEY_D},
        {KEY_LEFT_SHIFT, KEY_BACKSPACE}
    },

    [1] = {

        {KEYPAD_C,KEY_2},
        {KEY_B, KEY_C},
        {KEY_LEFT_SHIFT, KEY_BACKSPACE}
    },

    [2] = {

        {KEYPAD_B,KEY_1},
        {KEY_D, KEY_E},
        {KEY_LEFT_SHIFT, KEY_BACKSPACE}
    }

};

void setup() {
    // put your setup code here, to run once:

    Serial.begin(19200);
    for(int i = 0; i < columCount; i++){    //declaring all the colums and setting them high
        pinMode(colums[i],OUTPUT);
        digitalWrite(colums[i],HIGH);
    }
    for(int i=0; i < rowCount; i++){     //declaring all the rows and activating the internal pullup resistor
        pinMode(rows[i],INPUT_PULLUP);
    }
    Keyboard.begin();
}



void loop() {
    // put your main code here, to run repeatedly:
    keyCheck();

}

void keyCheck()
{

    //Keyboard.press(KEY_LEFT_SHIFT);
    for (int i=0; i < rowCount; i++){
        digitalWrite(colums[i],LOW);
        for (int j = 0; j < columCount; j++)
        {
            if(digitalRead(rows[j]) == LOW && keysDown[j][i] == false)
            {      
                // key is pressed
                keysDown[j][i] = true;
                if (key[layer][j][i] == KEYPAD_A ) {
                    Serial.println("KEYPAD_B PRESSED");
                    layer = 1;
                }

                if (key[layer][j][i] == KEYPAD_B ) {
                    Serial.println("KEYPAD_C PRESSED");
                    layer = 2;
                }

                if (key[layer][j][i] == KEYPAD_C ) {
                    Serial.println("KEYPAD_C PRESSED");
                    layer = 3;
                }
                if (key[layer][j][i] == KEYPAD_D ) {
                    Serial.println("KEYPAD_C PRESSED");
                    layer = 4;
                }
                if (key[layer][j][i] == KEYPAD_E ) {
                    Serial.println("KEYPAD_C PRESSED");
                    layer = 5;
                }
                if (key[layer][j][i] == KEYPAD_F ) {
                    Serial.println("KEYPAD_C PRESSED");
                    layer = 6;
                }

                if (key[layer][j][i] == KEY_LEFT_WINDOWS ) {
                    mod = true;
                    Keyboard.press(MOD_LEFT_GUI);
                }

                Keyboard.press(key[layer][j][i]);
                Serial.println(layer);
                Serial.println("key is written");

            }else if(digitalRead(rows[j]) == HIGH && keysDown[j][i] == true)
            {
                // key was pressed and will be released
                Serial.println("key was pressed and will be released");

                // reset all layer 
                if (key[layer][j][i] == 
                        (KEYPAD_A || 
                         KEYPAD_B ||
                         KEYPAD_C ||
                         KEYPAD_D ||
                         KEYPAD_E ||
                         KEYPAD_F
                        )
                   ) {
                    layer = 0;
                }
                mod = false;
                Keyboard.release(key[layer][j][i]);
                keysDown[j][i] = false;
            }
        }
        digitalWrite(colums[i], HIGH);
    }
}
