CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = HTU21D.o HTU21D-example.o
HUMIDITYOBJ = HTU21D.o humidity.o
TEMPERATUREOBJ = HTU21D.o temperature.o

EXTRA_LIBS=-lwiringPi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

HTU21D: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

temperature: $(TEMPERATUREOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

humidity: $(HUMIDITYOBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f HTU21D $(OBJ) 
