import numpy as np
import matplotlib.pyplot as plt

x_vals = np.array([35, 70, 105, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150
])

y_vals_vpered = np.array([0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.48, 1.52, 1.6, 1.68, 1.76, 1.84, 1.88, 1.96, 2, 2.12, 2.16, 2.24, 2.36, 2.4, 2.48, 2.56
])

y_vals_nazad = np.array([0, 0, 0, 0, 0.04, 0.04, 0.04, 0.08, 0.08, 0.12, 0.68, 0.84, 0.92, 1, 1.04, 1.12, 1.2, 1.28, 1.32, 1.4, 1.48, 1.52, 1.6, 1.68, 1.72, 1.8, 1.88, 1.92, 2, 2.08, 2.12, 2.2, 2.28, 2.36, 2.44, 2.48, 2.56
])

fig, ax = plt.subplots()

ax.scatter(x_vals,
            y_vals_vpered,
            marker = 'o',
            label = "- При прохождении вперёд")

ax.scatter(x_vals,
            y_vals_nazad,
            marker = '^',
            label = "- При прохождении назад")

ax.set_xlabel('U, В')
ax.set_ylabel('I, mA')
ax.set_title('ВАХ неоновой лампы')


ax.grid(
    True,
    alpha=0.3
)

ax.legend(
    loc="best",
    fontsize=9
)
plt.show()