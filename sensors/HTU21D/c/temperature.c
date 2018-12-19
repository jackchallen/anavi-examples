#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <string.h>
#include <unistd.h>

#include "HTU21D.h"

int main()
{
	wiringPiSetup();
    int success = 0;
	int fd;
    do {
	    fd = wiringPiI2CSetup(HTU21D_I2C_ADDR);
	    if ( 0 > fd )
	    {
		    fprintf(stderr, "ERROR: Unable to access HTU21D sensor module: %s\n", strerror (errno));
            success = 0;
            sleep(1);
            continue;
	    }

	    // Retrieve temperature and humidity
	    double temperature = 0;
	    double humidity = 0;
	    if ( (0 > getHumidity(fd, &humidity)) || (0 > getTemperature(fd, &temperature)) )
	    {
		    fprintf(stderr, "ERROR: HTU21D sensor module not found\n");
            success = 0;
            sleep(1);
            continue;
	    }
        success=1;
    } while (success != 1);
	// Print temperature and humidity on the screen
	printf("%5.2f\n", temperature);
//	printf("%5.2f%%rh\n", humidity);
	
	return 0;
}
