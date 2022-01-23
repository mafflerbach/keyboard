

build: 
	arduino-cli compile -b arduino:avr:leonardo -p /dev/ttyACM0 -P avr109 --build-path "/home/maren/development/keyboard/build" -v "/home/maren/development/keyboard/keyboard.ino" --verbose 



flash: 
	"/home/maren/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/bin/avrdude" "-C/home/maren/.arduino15/packages/arduino/tools/avrdude/6.3.0-arduino17/etc/avrdude.conf" -v -V -patmega32u4 -cavr109 -P/dev/ttyACM0 -b19200 "-Uflash:w:/home/maren/development/keyboard/build/keyboard.ino.hex:i"


# stty -F /dev/ttyACM0 cs8 19200 ignbrk -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

