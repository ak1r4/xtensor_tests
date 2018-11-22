import numpy as np
from xtensor_python_test import *

arr = np.array([(1, 2), (3, 4), (5, 6)], dtype=Point.dtype)
pc = PointCollection(arr)
print(pc.points)
