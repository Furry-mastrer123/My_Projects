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



def func_dlya_x (z):
    return(1/z - 5/pow(z, 2) +1)



#raschet shuma na y
for y in range(11):
    for x_1 in range(len(x_prom[y])):
        z = random.random()
        k = -1 if z< 0.5 else 1
        y_znach_func[y].append(func_schet(x_prom[y][x_1])*(1+k*z/c))



#raschet summ x^(i+j) dlya sostavleniy matrici A i vectorov C iz summ znacheniy x_i na znacheniye functsiy v etoy tochke
x_summ_matrix = [[[] for z in range(12)] for y in range(11)]
for x_m in range (11):        #matrica koeff
    for x_array in range(7):
        for x_collomns in range(7):
            x_summ_matrix[x_m][x_array].append(
            sum([pow(znach,x_collomns+x_array) for znach in x_prom[x_m]])
        )



#stolbec chiselok
b_stolb = [[]for x in range(11)]
for x_3 in range(11):
    for x_arr in range(7):
        b_stolb[x_3].append(
            sum( [y_znach_func[x_3][index]*pow(x_prom[x_3][index],x_arr) for index in range(len(x_prom[x_3])) ])
        )


def kvadratichnoye_otkloneniye(func_dlya_x, func_approximate, x_arr):
    kv_otkl = []
    for i in range(len(x_arr)):
        kv_otkl.append(pow((func_dlya_x(x_arr[i])-func_approximate(x_arr[i])), 2))
    return kv_otkl

#methodi

def method_gaussa(A_orig, B_orig, kolvo_tochek, maks_stepen_polinoma):
    A = [row[:] for row in A_orig] # Вот теперь это полностью независимая матрица в памяти!
    B = B_orig.copy()
    C_vector = [0 for i in range(maks_stepen_polinoma+1)]
    for x in range(maks_stepen_polinoma+1):

        max_arr = x
        for y in range(x, maks_stepen_polinoma+1):
            if abs(A[y][x]) > abs(A[max_arr][x]): max_arr = y 


        pivot = A[max_arr][x]
        B[max_arr] = B[max_arr]/pivot



        
        #privedeniye k tipu a_11/a_11, a_12/a_11 i tak dalee
        for y in range(x, maks_stepen_polinoma+1):
                A[max_arr][y] = A[max_arr][y]/pivot



        #menyaem stroki mestami
        A[max_arr], A[x] = A[x], A[max_arr]
        B[x], B[max_arr] = B[max_arr],B[x]


        #vichisleniye podobiya a_11*a_21
        for y in range(x+1, maks_stepen_polinoma+1):
            pivot_2 = A[y][x]
            B[y] = B[y] - pivot_2*B[x]
            for z in range (x, maks_stepen_polinoma+1):
                A[y][z] = A[y][z] - A[x][z]*pivot_2



    for i in range(maks_stepen_polinoma, -1, -1):
        if(i == maks_stepen_polinoma+1): C_vector[i] = B[i] 
        else: 
            C_vector[i] = B[i]
            for it in range(maks_stepen_polinoma, i, -1):
                C_vector[i] = C_vector[i] - C_vector[it]*A[i][it]
    return C_vector





Koeff_matrix = [[[] for index in range(12)] for x in range(11)]
for i in range (11):
    for y in range(7):
        Koeff_matrix[i][y] = method_gaussa(x_summ_matrix[i], b_stolb[i], 10+i, y) 

func_matrix = [[[] for m in range(12)]for i in range(11)]



for i in range(11):
    for x_2 in range(7):
       polynom_sum = 0
       for coeff in range(x_2 + 1):
            polynom_sum += Koeff_matrix[i][x_2][coeff] * sp.Pow(x, coeff)
       func_matrix[i][x_2] = polynom_sum


func_schet_matrix = [[[]for m in range(12)]for i in range(11)]
for i in range(11):
    for m in range(7):
        func_schet_matrix[i][m] = sp.lambdify(x,func_matrix[i][m] ,"numpy")



fig, ax = plt.subplots()        #sama fucntsiya
fig_2, ax_2 = plt.subplots()    #tablica dlya vsego

ax_2.axis("off")
ax.grid(alpha=0.4)


ishodnaya_func_plot, = ax.plot(         #zapataya pozvalyaet poluchit dostup napryamuyu k risuemoy linii(raspakovka nazivaetsa)
    x_prom[0],
    y_znach_func[0]
)

approksimaciya_plot, = ax.plot(
    x_prom[0],
    func_schet_matrix[0][1](np.array(x_prom[0]))
)


ax_slider_1 = fig.add_axes([0.25, 0.05, 0.5, 0.02 ])        #Добавляем оси для ползунков (насечки [left, bottom, width, height])
ax_slider_2 = fig.add_axes([0.25, 0.10, 0.5, 0.02])


#sozdayem tablici
table = ax_2.table(
    loc= "best",
    cellLoc="center",
    rowLabels=["f(x)", "Approximation", "kvadratichnoye otkloneniye"],
    colLabels=[f"{val:.2f}" for val in x_prom[0]],
    cellText = [
            [f"{val:.3f}" for val in y_znach_func[0]],
            [f"{val:.3f}" for val in (func_schet_matrix[0][1](np.array(x_prom[0])))],
            [f"{val:.3f}" for val in kvadratichnoye_otkloneniye(func_dlya_x, func_schet_matrix[0][1], x_prom[0])]
]
)
table.auto_set_font_size(False)
table.set_fontsize(8)      #razmeer shrifta
table.scale(0.9, 0.8)      #nastroyka razmera uacheek table.scale(width, height)


# Создаем сами ползунки
slider_1 = widget.Slider(
    ax=ax_slider_1,
    label='Количество доп точек после 10-той',
    valmin=0,
    valmax=10,
    valstep = 1,
    valfmt = "%d",
    valinit = 0
)


slider_2 = widget.Slider(
    ax=ax_slider_2,
    label='Старшая степень многочлена',
    valmin=1,
    valmax=6,
    valstep = 1,
    valfmt = "%d",
    valinit = 1
)



#pri obnovlenii - slot i functsiya obrabotki
def update_slider_1(val):
    n_tochek = int(slider_1.val)

    global approksimaciya_plot
    global ishodnaya_func_plot
    global table

    ishodnaya_func_plot.set_xdata(np.array(x_prom[n_tochek]))
    ishodnaya_func_plot.set_ydata(y_znach_func[n_tochek])
    approksimaciya_plot.set_xdata(np.array(x_prom[n_tochek]))
    approksimaciya_plot.set_ydata(func_schet_matrix[int(n_tochek)][int(slider_2.val)](np.array(x_prom[n_tochek])))


    table.remove()
    table = ax_2.table(
    loc= "best",
    cellLoc="center",
    rowLabels=["f(x)", "Approximation", "kvadratichnoye otkloneniye"],
    colLabels=[f"{val:.2f}" for val in x_prom[int(slider_1.val)]],
    cellText = [
            [f"{val:.3f}" for val in y_znach_func[int(slider_1.val)]],
            [f"{val:.3f}" for val in (func_schet_matrix[int(slider_1.val)][int(slider_2.val)](np.array(x_prom[int(slider_1.val)])))],
            [f"{val:.3f}" for val in kvadratichnoye_otkloneniye(func_dlya_x, func_schet_matrix[int(slider_1.val)][int(slider_2.val)], x_prom[int(slider_1.val)])]
]
)
    
    fig.canvas.draw_idle()
    fig_2.canvas.draw_idle()




def update_slider_2(val):
    n_glubina_polinoma = int(slider_2.val)

    global table
    global approksimaciya_plot


    approksimaciya_plot.set_ydata(func_schet_matrix[int(slider_1.val)][n_glubina_polinoma](np.array(x_prom[slider_1.val])))


    table.remove()
    table = ax_2.table(
    loc= "best",
    cellLoc="center",
    rowLabels=["f(x)", "Approximation", "kvadratichnoye otkloneniye"],
    colLabels=[f"{val:.2f}" for val in x_prom[int(slider_1.val)]],
    cellText = [
            [f"{val:.3f}" for val in y_znach_func[int(slider_1.val)]],
            [f"{val:.3f}" for val in (func_schet_matrix[int(slider_1.val)][n_glubina_polinoma](np.array(x_prom[int(slider_1.val)])))],
            [f"{val:.3f}" for val in kvadratichnoye_otkloneniye(func_dlya_x, func_schet_matrix[int(slider_1.val)][int(slider_2.val)], x_prom[int(slider_1.val)])]
]
)


    fig.canvas.draw_idle()
    fig_2.canvas.draw_idle()


#obiedinyaem method s obnovleniyem
slider_1.on_changed(update_slider_1)
slider_2.on_changed(update_slider_2)




plt.show()