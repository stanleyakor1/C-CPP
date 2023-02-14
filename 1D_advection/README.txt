This folder contains the solution to a 1-D advection equation. The main code is in c++ (advection.cpp) while the python script is for visualizing the result.

To compile the code, type the following commands from the terminal:

$ g++ -o advection.o advection.cpp
$ ./advection.o

The terminal prompt will ask for the spatial and temporal step sizes (dx,h).

Once the above are supplied, the code would produce an output.

In order to visualize the solution, do:

$ python plot.py

The resulting 1D_advection.png file shows the solution.

