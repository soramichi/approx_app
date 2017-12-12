Original code: https://bitbucket.org/act-lab/axbench

- Library Dependency (Python)
PIL
$ pip install pillow

Numpy
$ pip intall numpy


- Library Dependency (C++)
None


- How to use
1. Build
$ make

2. Reduce the number of colors of an image using kmeans clustering
$ ./kmeans ./kmeans data/input/1.rgb 1_out.rgb

3. Convert the resulting .rgb into a visible image
$ ./rgb2png 1_out.rgb 1_out.png
