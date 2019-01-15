import numpy as np
import matplotlib.pyplot as plt
from sys import argv

d = np.fromfile(argv[1], dtype=np.int32)
d4 = d.reshape((d.size//4, 4))

plt.figure();
plt.plot(d4[:,0]);

plt.figure();
plt.plot(d4[:,1]);

plt.figure();
plt.plot(d4[:,2]);

plt.figure();
plt.plot(d4[:,3]);

plt.show()

