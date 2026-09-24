import matplotlib.pyplot as plt 
import matplotlib.widgets as widget
import numpy as np 
import sympy as sp

#zadaem bazu
x = sp.symbols("x")
f = 1/x
a = 0.1
b = 1 
#h opredelim vnutri rascheta, i budet v zadannix predelax
x_j = np.linspace(0.02, 0.4, 20)    #tochki otnositelno kotorix bydem stroit(x)

#schitaem f(x_j)
func = sp.lambdify(x,f, "numpy")
y_j = func(x_j)
x_znach = np.linspace(a,b,100)
y_znach = func (x_znach)

fig, ax = plt.subplots()

ax.plot(
    x_znach,
    y_znach
)


plt.show()