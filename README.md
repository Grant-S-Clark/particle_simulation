# particle_simulation
Very rudimentary particle simulation using SFML.

To build the program into an executable, you need to first install SFML.
Next, you will need to navigate to the makefile, and replace all instances
of "-I/usr/local/SFML/include" and "-L/usr/local/SFML/lib" with the path to
your specific SFML installation. Then you can execute "make e" to build the
program, and then "make r" to run it.

Controls:
left click - place particles
right click - erase particles
'1' key - change particle to be placed to sand
'2' key - change particle to be placed to water
'3' key - change particle to be placed to wood
'r' key - reset canvas
'\[' key - shrink place/erase cursor size
'\]' key - grow place/erase cursor size
Shift + '\[' - shrink canvas (can also be done by clicking the "SHRINK" button)
Shift + '\]' - grow canvas (can also be done by clicking the "GROW" button)
Space (hold) - slow motion (reduce max FPS to 10)
