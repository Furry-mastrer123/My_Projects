import matplotlib.pyplot as plt
import sympy as sc
import numpy as np


##  Mnogo ne dorabotano 
##  Moshno sdelat rushnoy vvod granic
##  No mne eshe odin zavtra delat, tak chto sori

#zadayom uravneniya
x = sc.symbols('x')                     #peremennaya
f = 0.33*sc.sin(2.3*x) - 0.5*x -0.06    #functsiya
f_first_der = sc.diff(f, x,)                  #pervaya proizvodnaya
f_sec_der = sc.diff(f_first_der, x)           #vtoraya proizvodnaya
a = -1                                  #levaya granica
b = 0.5                                 #pravaya granica
 

#funcii math methodov
def neuton_method (func, first_derivative, second_derivative, a, b, tochnost, maks_iteraciy, reseniye_computera, first_point = a):       #derivative - proizvodnaya, first point, esli hotim proverit v drugoy tochke
    i = 0
    x_vals = list()
    y_vals = list()
    if (func(first_point)*second_derivative(first_point) <= 0):
        print("ошибка выбора начальной точки")
        return 0
    else:
        while i != maks_iteraciy:
            a = a - func(a)/first_derivative(a)
            x_vals
            if(abs(a-reseniye_computera)<tochnost):
                x_vals.append(a)
                y_vals.append(func(a))
                break
            else: 
                i += 1
                x_vals.append(a)
                y_vals.append(func(a))                
        axes[1,0].plot(
                x_vals,
                y_vals,
                color = "blue"
                      )
        axes[1,1].plot(
                x_vals,
                y_vals,
                color = "blue"
                      )
    return a


def half_division_method(func, a, b, tochnost, maks_iteraciy):     # derivative - proizvodnaya, first point opredelyaet tochrku, s kotoroy nachinaem - a ili b
    i = 0                   #dlya iteraciy po ciclu
    x_vals = list()         #dlya grafikov
    y_vals = list()         #dlya grafikov
    while i != maks_iteraciy:
        if func(a) * func(b) < 0 :
            if (i>=1):                  #proverka dlya smecheniye tochek
                if (func(a)*func(c)<0):
                    b = c
                else:
                    a = c
            c = (a+b)/2
            if (b-a < tochnost):
                x_vals.append(c)
                y_vals.append(func(c))
                break
            else:
                x_vals.append(c)
                y_vals.append(func(c))
                i += 1
        else:
            print("ошибка! Значения на концах отрезка - не разные")
            break
        axes[0, 1].plot(            #risuem na grafike kak dvigalis
        x_vals,
        y_vals,
        color = "red"
                    )
        axes[1, 1].plot(            #risuem 2
                x_vals,
                y_vals,
                color = "red"
                            )
    return (a+b)/2


#reshaem yravneniya analiticheski
x_1 = sc.nsolve(f, x, -1)
x_2 = sc.nsolve(f, x, 0.4)
x_3 = sc.nsolve(f, x, 0.5)
print(x_1, x_2, x_3)


#stroim grafiki
fig, axes = plt.subplots(nrows=2, ncols=2, sharex=True, sharey=True, figsize = (8, 8))
plt.xlim(a, b)
plt.ylim(-1, 1)
axes[0,0].grid(alpha=0.4)
axes[0,1].grid(alpha=0.4)
axes[1,0].grid(alpha=0.4)
axes[1,1].grid(alpha=0.4)
axes[0,0].set_title("Исходный график")
axes[0,1].set_title("Метод половинного деления")
axes[1,0].set_title("Метод Ньютона")
axes[1,1].set_title("Всё сразу")

#naxodi tochki dlya grafika
func_znac = sc.lambdify(x, f, "numpy")
first_derivative_znach = sc.lambdify(x, f_first_der, "numpy")
second_derivative_znach = sc.lambdify(x, f_sec_der, "numpy")
x_znach = np.linspace(a, b, 100)
y_znac_func = func_znac(x_znach)


#reshaem uravneniye s pomochiu chislennix methodov
tochnost = 1e-9
print(half_division_method(func_znac, a, 0, tochnost, 150))
print(neuton_method(func_znac, first_derivative_znach, second_derivative_znach, a, 0, tochnost, 150, x_1))

axes[0,0].plot(
    x_znach,
    y_znac_func,
    color = "green"
)
axes[1,1].plot(
    x_znach,
    y_znac_func,
    color = "green"
)

plt.show()