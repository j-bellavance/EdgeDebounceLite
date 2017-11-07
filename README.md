# EdgeDebounceLite
Just replace digitalRead(myPin); with debounce.pin(myPin);

EdgeDebounceLite is a lightweight (26 bytes of RAM) yet capable switch debouncer and EMF filter. It is also very fast. It can confirm that a switch is not bouncing within 90 microseconds, and return at most 180 microseconds after bouncing or EMF disturbances end. 

It can debounce any/all pins of any/all arduinos, with just one instance. There no need to create an instance of the debouncer for each switch you need to use.

The algorithm was inpired by an article that can be found at: http://www.ganssle.com/debouncing.htm

Step 1 : Read the pin 16 times;

Step 2 : If all the reads are identical return what has been read;

Step 3 : If not, go back to step 1.

The number of times the pin is read in step 1 can be adjusted between 1 and 32.
