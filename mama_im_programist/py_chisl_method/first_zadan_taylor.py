import numpy as np
import matplotlib.pyplot as plt 
import scipy as sc
import sympy as sp
import math

x = sp.symbols('x')     #vvedeniye peremenoy

f = sp.Pow(math.e, 1/(x-1)) #functsiya v bukvennom vide(moy variant - 3), Pow - steepen

a = 2       #otkuda stroim  
b = 0.8     #okrestnost
n = int(input('Введите значение n - точность разложения по тейлору:' )) #glubina razlosheniya

# poluchiniye ryada teylora
taylor_ser = sp.series(f, x,a, n+1).removeO()   #removeО() убирает член из ряда 0(f(x)) -o eto O a ne nole
taylor_num = sp.lambdify(x, taylor_ser, 'numpy')  #preobrazovaniye v chislenuyu functsiyu ryada
f_x = sp.lambdify(x, f,'numpy')      #preobrazovaniye v chislenuyu functsiyu ishodnuyu functsiyu


#polucheniye tochek y dlya grafika
x_taylor = np.linspace(a-b, a+b, 100)       #polucheniye tochek dlya prostranstva
y_f = f_x(x_taylor)                         #postroyeniye functsii na okrestnosti(tochkax)
y_taylor = taylor_num(x_taylor)             #postroyenie ryada na okrestnosti (tochkax)

plt.figure(figsize=(10, 6))


# Postroenie grafikov 
plt.plot(
x_taylor,
y_f,
color = 'blue'
    )


plt.plot(
    x_taylor,
    y_taylor,
    color = 'red'
)


#Konec / vivod grafika

plt.xlabel('x')
plt.ylabel('y')
plt.title('Ряд Тейлора для exp(1/(x-1))')
plt.show()