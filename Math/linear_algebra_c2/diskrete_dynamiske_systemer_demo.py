import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from sympy import Matrix


def generate_maparray(A, amount_of_elements, x_0=Matrix([2, 1])):
    maparray = []
    x_k = x_0

    for _ in range(amount_of_elements):
        maparray.append(x_k)
        x_k = A * x_k

    return maparray


# Initial parameters
a, b = 0.4, -0.3
c, d = 0.3, 0.4

x_0 = Matrix([2, 1])
n = 10


fig, ax = plt.subplots()
plt.subplots_adjust(bottom=0.35)


def update(_):
    # Construct A from current slider values
    A = Matrix([
        [slider_a.val, slider_b.val],
        [slider_c.val, slider_d.val]
    ])
    # Construct A from current slider values
    A = Matrix([
        [slider_a.val, -slider_b.val],
        [slider_b.val, slider_a.val]
    ])

    print(A.eigenvals())

    # Generate vectors
    vectors = generate_maparray(A, n, x_0)

    # Extract coordinates for plotting
    X = [float(x[0]) for x in vectors]
    Y = [float(x[1]) for x in vectors]

    # Clear and redraw
    ax.clear()

    ax.plot(X, Y, "o-")

    # Draw vectors
    for k, x in enumerate(vectors):
        ax.quiver(
            0, 0,
            float(x[0]), float(x[1]),
            angles="xy",
            scale_units="xy",
            scale=1,
            alpha=0.4
        )

        ax.text(float(x[0]), float(x[1]), f"$x_{k}$")

    ax.axhline(0, color="black", linewidth=0.5)
    ax.axvline(0, color="black", linewidth=0.5)

    ax.set_aspect("equal")
    ax.grid()

    fig.canvas.draw_idle()


# Slider positions
ax_a = plt.axes([0.15, 0.25, 0.7, 0.03])
ax_b = plt.axes([0.15, 0.19, 0.7, 0.03])
ax_c = plt.axes([0.15, 0.13, 0.7, 0.03])
ax_d = plt.axes([0.15, 0.07, 0.7, 0.03])

slider_a = Slider(ax_a, "a", -1, 1, valinit=a)
slider_b = Slider(ax_b, "b", -1, 1, valinit=b)
slider_c = Slider(ax_c, "c", -1, 1, valinit=c)
slider_d = Slider(ax_d, "d", -1, 1, valinit=d)

# Update whenever a slider changes
slider_a.on_changed(update)
slider_b.on_changed(update)
slider_c.on_changed(update)
slider_d.on_changed(update)

# Initial plot
update(None)

plt.show()
