import matplotlib.pyplot as plt 
import matplotlib.widgets as widget
import numpy as np 
import sympy as sp
import math as math



#zadaem bazu
x = sp.symbols("x")
f = 1/x
a = 0.1
b = 1 
#h opredelim vnutri rascheta, i budet v zadannix predelax
x_j = np.linspace(0.02, 0.4, 20)    #tochki dlya kotorix sravnivaem



#schitaem f(x_j) i tochki dlya vsego grafika
func = sp.lambdify(x,f, "numpy")
y_j = func(x_j)
x_znach = np.linspace(a, b, 100)
y_znach = func (x_znach)


#konechnaya raznost
def kon_raznostr(func, a, b, n):
    h = (b-a)/n         #shag
    it = 1              #nado
    c = a               #dlya prohoda nado
    kon_raznost_1 = [[0.0] * n for _ in range(n)]    #zubchatiy massiv s rezultatami konechnix raznostey
    for i in range(n):  
        kon_raznost_1[0][i] = func(c + h) - func(c)     #vichislyaem raznosti pervogo porydka
        c = c + h  
    while it != n:
        for  i in range(n-it):
            kon_raznost_1[it][i] = kon_raznost_1[it-1][i+1] - kon_raznost_1[it-1][i]            #zapolnyaem vse raznosti
        it+=1   
    kon_raznost_arr = list()        #itogoviy massiv 
    for i in range(n):
        kon_raznost_arr.append(kon_raznost_1[i][0])     #zapolnyaem itogoviy massiv
    return kon_raznost_arr


#functsiya vichiskeniya functsiyii interpolyacii
def interpolate_neut(func, a, b, n_tochek, x_0 = a):
    kon_raznitsi_arr = list(kon_raznostr(func, a, b, n_tochek))
    h = (b-a)/n_tochek
    x = sp.symbols('x')
    func_neut = func(a)
    baz_slagaem = (x-x_0)/h
    for i in range(1, n_tochek+1):
        func_neut += kon_raznostr[i-1]*baz_slagaem/math.factorial(i) 
        baz_slagaem *= (x-x_0 - i*h)/h
    return sp.lambdify(x, func_neut, "numpy")





#massiv functsiy dlya raznix razlosheniy
func_arr = list()
for n in range(4, 17):
    func_arr.append(interpolate_neut(func, a, b, n))

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