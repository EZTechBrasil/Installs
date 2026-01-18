#!/bin/bash
echo "Connect serial cable from COM1 port to the USB RS232 converter"
echo "Press any key to continue."
read -r key

SERIAL_PORT="/dev/ttyAMA3"
stty -F "$SERIAL_PORT" 9600 cs8 -parenb -cstopb
stty -F "$SERIAL_PORT" raw -echo min 0 time 100 # 1 second timeout
echo "Testing $SERIAL_PORT tx..    Type anything and press enter>" > "$SERIAL_PORT"
echo "Waiting for input on $SERIAL_PORT..."
read -r -t 20 -n 100 SERIAL_DATA < "$SERIAL_PORT"
echo "Received: $SERIAL_DATA"

echo "Connect serial cable from COM2 port to the USB RS232 converter"
echo "Press any key to continue."
read -r key

SERIAL_PORT="/dev/ttyAMA4"
stty -F "$SERIAL_PORT" 9600 cs8 -parenb -cstopb
stty -F "$SERIAL_PORT" raw -echo min 0 time 100 # 1 second timeout
echo "Testing $SERIAL_PORT tx..    Type anything and press enter>" > "$SERIAL_PORT"
echo "Waiting for input on $SERIAL_PORT..."
read -r -t 20 -n 100 SERIAL_DATA < "$SERIAL_PORT"
echo "Received: $SERIAL_DATA"

echo " "
echo "Start RTC test"  
hwclock --verbose
echo " "
echo "Does the line above show the correct time and date ?"
echo "Press any key to continue."
read -r key

