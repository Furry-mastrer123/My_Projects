import numpy as np
import matplotlib.pyplot as plt
import math 
import sympy as sp

t = sp.symbols("t")

#constanti
electron = 1.6*10**-19
mass_electron = 9.1*10**-31
omega = electron/mass_electron

t_values = np.linspace(0, 10, 100)

#functsii
x_pos = sp.lambdify(t,sp.sqrt(2)/(2*omega) * (1-sp.cos(omega*t)), "numpy")
y_pos = sp.lambdify(t,sp.sqrt(2)/(2*omega) *sp.sin(omega*t), "numpy")
z_pos = sp.lambdify(t,sp.sqrt(2)/(2*omega) + electron*t*t/2, "numpy")

x_values = x_pos(t_values)
y_values = y_pos(t_values)
z_values = z_pos(t_values)

fig, ax = plt.subplots(nrows=3)

ax[0].set_ylabel("x, м")
ax[1].set_ylabel("y, м")
ax[2].set_ylabel("z, м")
ax[0].set_xlabel("t, с")
ax[1].set_xlabel("t, с")
ax[2].set_xlabel("t, с")


ax[0].plot(
    t_values,
    x_values
)

ax[1].plot(
    t_values,
    y_values
)

ax[2].plot(
    t_values,
    z_values
)


plt.show()