# EdgeDebounceLite
Just replace digitalRead() with debounce.pin()

EdgeDebounceLite is a lightweight yet capable switch debouncer and EMF filter. It is also very fast. It can confirm that a switch is not bouncing within 90 microseconds, and return at most after 180 microseconds after bouncing or EMF disturbances end.

The algorithm was inpired by an article that can be found at: http://www.ganssle.com/debouncing.htm

Step 1 : Read the pin 16 times

Step 2 : If all the reads are identical return what has been read

Step 3 : If not, go back to step 1

The number of times the pin is read in step 1 can be adjusted between 1 and 32
