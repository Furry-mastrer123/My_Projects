import numpy as np
import matplotlib.pyplot as plt

x_vals = np.array([5, 10,
15, 20,
25, 30,
35, 40,
45, 50,
55, 60,
65, 70,
75, 80,
85, 90,
95, 100,
105, 110,
115, 120,
])
# r srednee
y_vals_vpered = np.array([0.14, 0.2,
0.23, 0.27,
0.28, 0.30,
0.33, 0.35,
0.36, 0.37,
0.39, 0.40,
0.42, 0.42,
0.44, 0.46,
0.46, 0.47,
0.49, 0.50,
0.50, 0.51,
0.52, 0.53,
])
# r diff
y_vals_nazad = np.array([0.33, 0.33,
0.40, 0.50,
0.40, 0.50,
0.66, 0.50,
0.50, 0.66,
0.66, 0.66,
0.66, 0.66,
1.00, 0.66,
0.66, 1.00,
1.00, 0.66,
0.66, 1.00,
1.00, 1.00,
])

fig, ax = plt.subplots()

ax.scatter(x_vals,
            y_vals_vpered,
            marker = 'o',
            label = "- R_среднее")

ax.scatter(x_vals,
            y_vals_nazad,
            marker = '^',
            label = "- R_дифф")

ax.set_xlabel('U, В')
ax.set_ylabel('R, кОм')
ax.set_title('Сопротивление лампы накаливания')


ax.grid(
    True,
    alpha=0.3
)

ax.legend(
    loc="best",
    fontsize=9
)
plt.show()