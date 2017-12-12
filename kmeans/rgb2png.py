#!/usr/bin/env python

import sys
import numpy as np
from PIL import Image

if len(sys.argv) < 3:
    print('Usage: prog input output')
    sys.exit()

f = open(sys.argv[1])

[w,h] = map(int, f.readline().split(','))

print("Input:")
print(sys.argv[1])
print("Output:")
print(sys.argv[2])

pixels_all = []

for i in range(0, h):
    line = f.readline()
    pixels = map(int, line.split(','))
    pixels_all += pixels

pixels_np = np.array(pixels_all)
pixels_np = pixels_np.reshape(512,512,3)

im = Image.fromarray(np.uint8(pixels_np))
im.save(sys.argv[2])
