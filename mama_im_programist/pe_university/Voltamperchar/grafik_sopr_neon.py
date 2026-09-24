import numpy as np
import matplotlib.pyplot as plt

# U znach
x_vals = np.array([
135,
136,
137,
138,
139,
140,
141,
142,
143,
144,
145,
146,
147,
148,
149,
150,
])

#r srednee pri vpered
y_vals_A_1 = np.array([
91.2,
89.5,
85.6,
82.1,
78.9,
76.1,
75.0,
72.4,
71.5,
67.9,
67.1,
65.2,
62.3,
61.7,
60.1,
58.6,
])

#r_diff pri vpered
y_vals_A_2 = np.array([
1.3,
16.7,
12.5,
12.5,
12.5,
16.7,
16.7,
16.7,
12.5,
12.5,
16.7,
10.0,
12.5,
16.7,
12.5,
12.5,

])

#r_sr pri nazad
y_vals_B_1 = np.array([
88.8,
85.0,
81.5,
80.2,
77.2,
74.5,
73.4,
71.0,
68.8,
67.9,
65.9,
64.0,
62.3,
60.7,
60.1,
58.6,

])


# r_diff pri nazad
y_vals_B_2 = np.array([
16.7,
12.5,
16.7,
16.7,
12.5,
16.7,
16.7,
12.5,
16.7,
16.7,
12.5,
12.5,
12.5,
16.7,
16.7,
12.5,

])


#sozdayem object grafikov
fig, axes = plt.subplots(nrows = 2)


#obrabotka grafikov
axes[0].set_ylabel("R, кОм", fontsize=8)
axes[0].set_xlabel("U, В", fontsize=8)
axes[0].grid(alpha = 0.5)


axes[1].set_ylabel("R, кОм", fontsize=8)
axes[1].set_xlabel("U, В", fontsize=8)
axes[1].grid(alpha = 0.5)

axes[0].set_title(
    "R при продвижени вперёд",
    fontsize=10,
    # x=0.92,      #koordinati podpisi
    # y=-0.1      #koordinati podpisi
)

axes[1].set_title(
    "R при продвижении назад",
    fontsize=10,
    # x=0.92, 
    # y=-0.1
)

# fig.get_tight_layout()


# plt.setp(
#     axes[1].get_xticklabels(),
#     rotation=45
# )

#risuem grafiki
axes[0].scatter(
    x_vals,
    y_vals_A_1,
    color = "red",
    marker = ".",
    alpha = 0.5,
    label = "- R_среднее"
)

axes[0].scatter(
    x_vals,
    y_vals_A_2,
    color = "green",
    marker = "^",
    alpha = 0.5,
    label = "- R_дифф"
)

axes[1].scatter(
    x_vals,
    y_vals_B_1,
    color = "red",
    marker = ".",
    alpha = 0.5,
    label = "- R_среднее"
)

axes[1].scatter(
    x_vals,
    y_vals_B_2,
    color = "green",
    marker = "^",
    alpha = 0.5,
    label = "- R_дифф"
)

axes[0].legend(
    loc="best",
    fontsize=9
)

axes[1].legend(
    loc="best",
    fontsize=9
)

plt.show()