import numpy as np
import matplotlib.pyplot as plt

f = lambda x, y: (x-y)/pow(x+y,3)

X = np.linspace(-2, 2, 300) # 1 dim
Y = np.linspace(-2, 2, 300) # 1 dim
X, Y = np.meshgrid(X, Y) # 2 dim

Z = f(X, Y)

fig = plt.figure()
ax = fig.add_subplot(projection="3d")

ax.plot_surface(X, Y, Z)

plt.show()
