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
x_j = np.linspace(0.02, 0.4, 20)    #tochki otnositelno kotorix bydem stroit functsiyu interpolirovaniya(x)

#schitaem f(x_j)
func = sp.lambdify(x,f, "numpy")
y_j = func(x_j)
x_znach = np.linspace(a, b, 100)
y_znach = func (x_znach)


#konechnaya raznost
def kon_raznostr(y_0, y_1):
    return y_1-y_0



#dlya podscheta summi dlya kolva elementov v massive
def summa_dlya_lista(chislo):
    if chislo == 1:
        return 1
    return chislo + summa_dlya_lista(chislo-1)



#functsiya vichiskeniya functsiyii interpolyacii
def interpolate_neut(func, a, b, n_tochek):
    h = (b-a)/n_tochek
    y_znach = func(x_znach)
    





#massiv functsiy dlya raznix razlosheniy
func_arr = list()
for n in range(4, 17):
    func_arr.append(interpolate_neut(func, x_j, n))

#nu chto tam s grafikom???
fig, ax = plt.subplots()

osnova = ax.plot(
    x_znach,
    y_znach
)



interpolaciya_plot = ax.plot(
    x_znach,
    func_arr[0](x_znach)
)

ax_slider = fig.add_axes([0.25, 0.05, 0.5, 0.01 ])        #Добавляем оси для ползунков (насечки [left, bottom, width, height])

# Создаем сами ползунки
slider = widget.Slider(
    ax=ax_slider,
    label='Количество точек',
    valmin=4,
    valmax=16,
    #valinit=
    valfmt = int
)


def update_slider(val):
    n_tochek = slider.val
    interpolaciya_plot.set_ydata(func_arr[1](np.linspace(a,b,100)))          
    fig.canvas.draw_idle()

slider.on_changed(update_slider)

plt.show()