import matplotlib.pyplot as plt
import numpy as np

x_znach = np.array([10, 22, 32, 44, 55, 66, 77, 88, 98,])
y_znach = np.array([26.90878386, 53.68233018, 80.32165592, 106.8277679, 133.2016627, 159.4443274, 185.5567388, 211.5398643, 237.3946618, ])

k_c, b_c = np.polyfit(x_znach, y_znach, 1)
coef_cor = np.corrcoef(x_znach, y_znach)[0,1]

fig, ax = plt.subplots()
ax.scatter(
    x_znach,
    y_znach,
    label = f"МНК I_g={k_c:.3f}n + {b_c:.3f}, коэф кор = {coef_cor:.3f}"
)

x_mnk = np.linspace(0, 100, 100)
y_mnk = x_mnk*k_c + b_c
ax.plot(
    x_mnk, 
    y_mnk
)

ax.set_title("Вычисление c графическим методом(мнк)")
ax.set_xlabel("n, ед")
ax.set_ylabel("I, мкА")
ax.legend(loc = "best", fontsize = 14)
ax.grid(alpha = 0.4)
plt.show()