import matplotlib.pyplot as plt
import numpy as np
import sympy as sc          #prishlos ibo dlya raboty s numpy i pri vivode nushno, esli obichnuyu func(np.linspace) on uprametsa
import math

#vvodim peremenniye 
a = 0                   #levaya granica 
b = math.pi/2           #pravaya granica
x = sc.symbols('x')     
f = sc.sin(1+sc.Pow(x, 2))
n = int(input("Vvtdite znacheniye otrezkov na scolko razbivaem: "))
func = sc.lambdify(x, f, 'numpy')

#opredeleniye samix methogov
def method_trap(func, a, b, n):        #f - functsia, a - levaya granica, b - pravaya granica, n - kol-va otrezkov na kotoraye razbyvayem
    i = 1
    h = (b-a)/n
    summa = func(a)/2+func(b)/2
    x_vals = np.linspace(a, b, n)
    y_vals = func(x_vals)
    while i!=n:
        summa =summa + func(a+h*i)
        i+=1
    axes[0,1].bar(                 #risuem grafiki
        x_vals,
        y_vals,
        width = h,
        color = 'green'
    )
    axes[1,1].bar(                 #risuem grafiki
            x_vals,
            y_vals,
            width = h,
            color = 'green'
        )
    # axes[1,1].plot(               #Grafika pryam v vide trapeziy
    #         x_vals,
    #         y_vals,
    #         color = 'green'
    #     )
    # axes[1, 1].fill(
    #         x_vals,
    #         y_vals
    #     )
    return h*(summa)

def method_simpson(func, a, b, n):
    if (n%2!= 0): 
        print ("Метод симпсона не работает! N - нечетное")
        return 0
    else:
        h = (b-a)/n
        summa = func(a) + func(b)
        i = 1
        while i!= n:
            if i % 2 != 0:
                summa = summa + 4*func(a+h*i)
                i+=1
            else:
                summa = summa + 2*func(a+h*i)
                i+=1
        return (h/3)*summa      

# grafik dlya simpsona sdelal brat svat chat gpt
def plot_simpson(func, a, b, n):
    if n % 2 != 0:
        print("Для Симпсона n должно быть чётным")
        return
    h = (b-a)/n
    x_points = np.linspace(a, b, n + 1)
    y_points = func(x_points)
    for i in range(0, n, 2):

        # Берём три соседние точки
        x0 = x_points[i]
        x1 = x_points[i + 1]
        x2 = x_points[i + 2]

        y0 = y_points[i]
        y1 = y_points[i + 1]
        y2 = y_points[i + 2]

        # Коэффициенты параболы
        A = (y0 - 2*y1 + y2) / (2*h**2)
        B = (y2 - y0) / (2*h)
        C = y1

        # Создаём много точек между x0 и x2
        x_part = np.linspace(x0, x2, 5)

        # Считаем значения параболы
        y_parabola = (
            A * (x_part - x1)**2
            + B * (x_part - x1)
            + C
        )

        # Рисуем параболу
        axes[1, 0].plot(
            x_part,
            y_parabola,
            color="blue",
            linewidth=2
        )

#tochki dlya isxodnoy functsii
x_linscpace = np.linspace(a, b, 100)
y_func_vals = func(x_linscpace)

#sozdayem grafiki
fig, axes = plt.subplots(nrows=2, ncols=2, sharex=True, sharey=True, figsize = (8, 8))
plt.xlim(a, b)
axes[0,0].grid(alpha=0.4)
axes[0,1].grid(alpha=0.4)
axes[1,0].grid(alpha=0.4)
axes[1,1].grid(alpha=0.4)
axes[0,0].set_title("Исходный график")
axes[0,1].set_title("Метод трапеций")
axes[1,0].set_title("Метод Симпсона")
axes[1,1].set_title("Всё сразу")


axes[0,0].plot(
        x_linscpace,
        y_func_vals,
        color = 'red'
              )
axes[1,1].plot(
        x_linscpace,
        y_func_vals,
        color = 'red'
              )



#vichisleniye integralov
res_meth_trap = method_trap(func, a, b, n)
print(res_meth_trap)
res_meth_simspsona = method_simpson(func, a, b, n)
print(res_meth_simspsona)
plot_simpson(func, a, b, n)
plt.show()