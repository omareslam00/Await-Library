To set up your library in Arduino IDE 
first you need to put this folder inside documents/Arduino/libraries 
if libraries folder doesn't exit create one with the name libraries
then you can use the class Await in your sketches

to define objects in the class:
ex: Await wait1;
ensure it's global

there are 4 main methods:
set( interval ): which set a timer on a certain interval when it's reached it returns true until it's reset
time(): shows you elapsed time since the method is called until it's reset
count( interval ): counts how many times the interval has passed until it's reset
reset( "method" ): resets the chosen method from the previous three methods 
