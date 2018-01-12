import lib
from lib import *

arr  = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024.0]
arr2 = []
for i in range(0, len(arr)):
    arr2.append(0)

squares(arr, arr2)
bycyclic(arr, 4)
print(arr, "\n", arr2)
