import numpy as np
import matplotlib.pyplot as plt

def mnk(x, y):
    """
    Ищет линейную зависимость:

        y = k*x + b

    Возвращает:
        k - коэффициент наклона
        b - свободный член
        r - коэффициент корреляции
    """

    # np.polyfit(..., 1) ищет прямую первой степени:
    #
    # y = k*x + b
    #
    k, b = np.polyfit(x, y, 1)

    # Коэффициент корреляции Пирсона.
    r = np.corrcoef(x, y)[0, 1]

    return k, b, r

A_c = np.array([0, 0.2, 0.4, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6
])

A_anod = np.array([9.774193548, 9.677419355,
8.612903226, 7.064516129,
4.161290323, 2.806451613,
1.935483871, 1.451612903,
0.967741935, 0.677419355,
0.483870968, 0.387096774,
0.290322581, 0.290322581
])
A_anod = A_anod*10**-3


#znacheniya min 
A_anod_min = np.array([0.483870968, 0.387096774,
0.290322581, 0.290322581])
A_anod_min = A_anod_min*10**-3
A_c_min = np.array([2, 2.2, 2.4, 2.6])
k_min, b_min, r_min = mnk(A_c_min, A_anod_min)



#vichisleniye naibolshego padeniya
A_c_krit = np.array([0.4, 0.6, 0.8])
A_anod_krit = np.array([8.612903226, 7.064516129,
4.161290323])
A_anod_krit = A_anod_krit*10**-3
k, b, r = mnk(A_c_krit, A_anod_krit)
fig, ax = plt.subplots()
ax.plot(
    A_c,
    A_anod
)

x_znach_naib = np.linspace(0, 1.2, 100)
y_znach_naibolsh = k*x_znach_naib+b
x_znach_min = np.linspace(0.6, 2.6, 100)
y_znach_min = k_min*x_znach_min+b_min

ax.set_title("U = 50В")
ax.set_xlabel("I_соленоида")
ax.set_ylabel("I_анода*10^-3")
ax.grid(
    True,
    alpha=0.3
)

ax.plot(
    x_znach_naib,
    y_znach_naibolsh,
    label=f"МНК максимальное падение: y={k:.5f}x + {b:+.5f},\nкоэфф корреляции = {r}"
)


ax.plot(
    x_znach_min,
    y_znach_min,
    label=f"МНК минимальные значения: y={k_min:.5f}x + {b_min:+.5f},\nкоэфф корреляции = {r_min}"
)

ax.legend(
    loc="best"
)
fig.tight_layout()
plt.show()