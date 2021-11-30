rpi-gpio-libc: rpi-gpio-libc.c 
	gcc rpi-gpio-libc.c -o rpi-gpio-libc -I ~/Documents
rpi-gpio: rpi-gpio-wpi.c
	gcc rpi-gpio-wpi.c -o rpi-gpio -I ~/Documents -lwiringPi