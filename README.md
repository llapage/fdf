[MacOs] FdF

About
FdF is a project in which we convert a file with a grid of height values into a 3d wireframe using a simple graphics library called MiniLibX.

Installation
The program can be build with a simple "make" command (if you have mlx installed [42 infrastructure] !)

run the program

./fdf

Example
Simple example of functionality
The following is an example of a .fdf file we use as an input for our program where numbers grow depending of the height whished at x and y coordinate:

0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1


Here is a more complex example with a different map:

![fdf](https://github.com/user-attachments/assets/238dc0df-04dd-45e6-8f7a-2eb2cc0e98b0)
