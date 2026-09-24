import numpy as np
import matplotlib.pyplot as plt


x_vals = np.array([
    0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75,
    80, 85, 90, 95, 100, 105, 110, 115, 120
])

#dlya sxemi a prohod vpered
y_vals_A_1 = np.array([
    0, 35, 50, 65, 75, 85, 100, 105, 115, 125, 135, 140, 150, 155,
    165, 170, 175, 185, 190, 195, 200, 210, 215, 220, 225
])

#dlya sxemi a prohod nazad
y_vals_A_2 = np.array([
    0, 35, 50, 65, 75, 90, 100, 105, 115, 125, 135, 140,150, 155, 
    165, 170, 175, 185, 190, 195, 200, 210, 215, 220, 225
])

#dlya sxemi b prohod vpered
y_vals_B_1 = np.array([
    0, 35, 45, 60, 70, 80, 90, 100, 105, 115, 120, 130, 135, 145, 150,
    155, 160, 170, 175, 180, 190, 190, 200, 205, 210
])
# dlya sxe,i b poroh nazad
y_vals_B_2 = np.array([
    0, 35, 50, 60, 70, 75, 90, 100, 110, 115, 125, 130, 135, 145, 150, 160, 165, 170,
    175, 180, 190, 190, 200, 205, 210
])


#sozdayem object grafikov
fig, axes = plt.subplots(nrows = 2)


#obrabotka grafikov
axes[0].set_ylabel("I, мА", fontsize=8)
axes[0].set_xlabel("U, В", fontsize=8)
axes[0].grid(alpha = 0.5)


axes[1].set_ylabel("I, мА", fontsize=8)
axes[1].set_xlabel("U, В", fontsize=8)
axes[1].grid(alpha = 0.5)

axes[0].set_title(
    "ВАХ на схеме А",
    fontsize=10,
    # x=0.92,      #koordinati podpisi
    # y=-0.1      #koordinati podpisi
)

axes[1].set_title(
    "ВАХ на схеме Б",
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
    label = "- при повышении напряжения"
)

axes[0].scatter(
    x_vals,
    y_vals_A_2,
    color = "green",
    marker = "^",
    alpha = 0.5,
    label = "- при понижении напряжения"
)

axes[1].scatter(
    x_vals,
    y_vals_B_1,
    color = "red",
    marker = ".",
    alpha = 0.5,
    label = "- при повеышении напряжения"
)

axes[1].scatter(
    x_vals,
    y_vals_B_2,
    color = "green",
    marker = "^",
    alpha = 0.5,
    label = "- при понижении напряжения"
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