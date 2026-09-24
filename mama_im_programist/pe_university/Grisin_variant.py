import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from sympy import symbols, series, fourier_series, cot, lambdify, pi, Piecewise

a = 0.6
b = 0.5
d = 1
d_val = float(d)

x = symbols("x")

f_x = cot(x**2 + 1)
f_origin = lambdify((x), f_x, 'numpy')

F_x = 1 - x**2
F_origin = lambdify((x), F_x, 'numpy')
mode = "odd"

x_vals_taylor = np.linspace(a - b, a + b, 50)

if mode == "none":
    x_vals_fourier = np.linspace(0, d_val, 100)  
else:
    x_vals_fourier = np.linspace(-2 * d_val, 3 * d_val, 400)

result_f = f_origin(x_vals_taylor)
result_F = F_origin(x_vals_fourier)

n_start = 1

if mode == "none":
    expr, low, high = F_x, 0, d
    period = d_val
elif mode == "even":
    expr = Piecewise((F_x, x >= 0), (F_x.subs(x, -x), x < 0))
    low, high = -d, d
    period = 2 * d_val
else:
    expr = Piecewise((F_x, x >= 0), (-F_x.subs(x, -x), x < 0))
    low, high = -d, d
    period = 2 * d_val

fs_object = fourier_series(expr, (x, low, high))

def compute_taylor(n):
    taylor_seria = series(f_x, x, a, n).removeO()
    f_t = lambdify((x), taylor_seria, 'numpy')
    y = f_t(x_vals_taylor)
    if np.isscalar(y) or np.shape(y) == ():
        y = np.full_like(x_vals_taylor, y, dtype=float)
    return y

def true_periodic(x_arr):
    if mode == "none":
        xm = np.mod(x_arr, period)
        return F_origin(xm)
    else:
        xm = np.mod(x_arr + d_val, period) - d_val 
        if mode == "even":
            return F_origin(np.abs(xm))
        else:  
            sign = np.sign(xm)
            sign[sign == 0] = 1
            return sign * F_origin(np.abs(xm))
        
def compute_fourier(n):
    truncated = fs_object.truncate(n)
    F_t = lambdify(x, truncated, 'numpy')
    y = F_t(x_vals_fourier)
    if np.isscalar(y) or np.shape(y) == ():
        y = np.full_like(x_vals_fourier, y, dtype=float)
    return y

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
plt.subplots_adjust(bottom=0.25, wspace=0.3)

line_f, = ax1.plot(x_vals_taylor, result_f, label="Исходная функция", color="blue", linewidth=2)
line_ft, = ax1.plot(x_vals_taylor, compute_taylor(n_start), label="Ряд Тейлора", color="red", linewidth=2)

ax1.set_xlim(a - b, a + b)
ax1.set_ylim(min(result_f), max(result_f))
ax1.set_title("Тейлор")
ax1.set_xlabel("x")
ax1.set_ylabel("y")
ax1.grid(True)
ax1.legend()

result_F_true = true_periodic(x_vals_fourier)
line_F, = ax2.plot(x_vals_fourier, result_F_true, label="Периодическое продолжение", color="blue", linewidth=2)
line_Ft, = ax2.plot(x_vals_fourier, compute_fourier(n_start), label="Ряд Фурье", color="green", linewidth=2)
ax2.set_xlim(x_vals_fourier[0], x_vals_fourier[-1])
ax2.set_ylim(-3, 3)
ax2.set_title(f"Фурье (режим: {mode})")
ax2.grid(True)
ax2.legend()

ax_slider1 = plt.axes([0.1, 0.08, 0.35, 0.03])
slider_taylor = Slider(ax_slider1, "n (Тейлор)", valmin=1, valmax=15, valinit=n_start, valstep=1)

ax_slider2 = plt.axes([0.55, 0.08, 0.35, 0.03])
slider_fourier = Slider(ax_slider2, "n (Фурье)", valmin=1, valmax=15, valinit=n_start, valstep=1)

def update_taylor(val):
    n = int(slider_taylor.val)
    line_ft.set_ydata(compute_taylor(n))
    fig.canvas.draw_idle()

def update_fourier(val):
    n = int(slider_fourier.val)
    line_Ft.set_ydata(compute_fourier(n))
    fig.canvas.draw_idle()

slider_taylor.on_changed(update_taylor)
slider_fourier.on_changed(update_fourier)

plt.show()