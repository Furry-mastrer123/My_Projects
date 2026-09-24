import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
import scipy as sc
#bazovie znacheniya
a = 0       #otkuda stroim  
d = 1     #okrestnost
n = int(input('Введите значение n - точность разложения по фурье:' )) #glubina razlosheniya
x = sp.symbols('x')
func = sp.Pow(x, 2)
Even = bool(input('введите четное ли разложение фурье будет или нет(1 или 0)?'))        #chetnoe razlosheniye ili net

#privideniye 
x_func = sp.lambdify(x, func, 'numpy')    #privedeniye funcii ot koordinaty 
if(Even == True):  
    f_even = sp.Piecewise((func,x>a ), (func, x<a), (func, x==a) )          #sozdaniye functsii s nastraivaemoy chetnostyi
    x_furie = sp.fourier_series(f_even, (x, a, d) ).truncate(n)         #truncate(n) - privesti k n chlenu ryada
else:
    f_even = sp.Piecewise((func,x>a ), (-func, x<a), (func, x==a) )         #sozdaniye functsii s nastraivaemoy chetnostyi
    x_furie = sp.fourier_series(f_even, (x, a, d) ).truncate(n)         #truncate(n) - privesti k n chlenu ryada
x_furie_func = sp.lambdify(x, x_furie, 'numpy')
    

#vichisleniye tochek znacheniy
x_points = np.linspace(-d,d, 100)   #sozdayem znacheniya x
y_znach = x_func(x_points)          #schitayem y dlya funcii
y_furie_znach = x_furie_func(x_points)  #schitaem y dlya ryada furie


#grafik
fig, ax = plt.subplots(figsize=(12, 6))
ax.plot(
x_points,
y_znach,
color = 'blue'
)


ax.plot(
x_points,
y_furie_znach,
color = 'red'
)


#oformleniye
plt.xlabel('x')
plt.ylabel('y')
plt.title('Ряд Фурье для x^2')
plt.show()