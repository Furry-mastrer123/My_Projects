import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.widgets as widget 
import sympy as sp
import random


#zadayem peremenniye
x = sp.symbols('x')
a = 1
b = 2
c = 3

#schitaem functsiyu
func = 1/x -5/sp.Pow(x, 2) + 1
func_schet = sp.lambdify(x, func, "numpy")
x_prom = [np.linspace(a, b, 10+x).tolist() for x in range(11)]
y_znach_func = [[] for x in range(11)]
tablica_coeff = [[] for x in range(20)]

#raschet shuma na y
for y in range(11):
    for x in range(len(x_prom[y])):
        z = random.random()
        k = -1 if z< 0.5 else 1
        y_znach_func[y].append(func_schet(x_prom[y][x])*(1+k*z/c))

#raschet summ x^(i+j) dlya sostavleniy matrici A i vectorov C iz summ znacheniy x_i na znacheniye functsiy v etoy tochke
#no tut she ne 11 polynomov nado, a tolko n chet tam, prochitay methodichku!
x_summ_matrix = [[[]]]
for x in range (11):
    for x_array in range(len(x_prom[x])):
        x_summ_matrix[x][x_array].append(
            sum([pow(znach,x+x_array)] for znach in x_prom[x])
        )

#methodi






fig, ax = plt.subplots()        #sama fucntsiya
fig_2, ax_2 = plt.subplots()    #tablica dlya vsego

ax_2.axis("off")
ax.grid(alpha=0.4)


ishodnaya_func_plot, = ax.plot(         #zapataya pozvalyaet poluchit dostup napryamuyu k risuemoy linii(raspakovka nazivaetsa)
    x_prom[0],
    y_znach_func[0]
)


ax_slider = fig.add_axes([0.25, 0.05, 0.5, 0.02 ])        #Добавляем оси для ползунков (насечки [left, bottom, width, height])


# #sozdayem tablici
# table = ax_2.table(
#     loc= "best",
#     cellLoc="center",
#     rowLabels=["f(x)", "Approximation"],
#     colLabels=x_prom,
#     cellText=[y_znach_func[0], approximation[0]]
# )
# table.auto_set_font_size(False)
# table.set_fontsize(8)      #razmeer shrifta
# table.scale(0.9, 0.8)      #nastroyka razmera uacheek table.scale(width, height)


# Создаем сами ползунки
slider = widget.Slider(
    ax=ax_slider,
    label='Количество доп точек после 10-той',
    valmin=0,
    valmax=10,
    valstep = 1,
    valfmt = "%d",
    valinit = 0
)

#pri obnovlenii - slot i functsiya obrabotki
def update_slider(val):
    n_tochek = int(slider.val)

    ishodnaya_func_plot.set_xdata(x_prom[n_tochek])
    ishodnaya_func_plot.set_ydata(y_znach_func[n_tochek])
    
    fig.canvas.draw_idle()
    fig_2.canvas.draw_idle()


#obiedinyaem method s obnovleniyem
slider.on_changed(update_slider)




plt.show()