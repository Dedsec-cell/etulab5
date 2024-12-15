import math
import matplotlib.pyplot as plt
import matplotlib.image as mpimg  # Для загрузки изображения

# Новая функция
def func(x):
    return math.sin(x)**2 - math.cos(x)**2

# Новые границы интервала
x_start = math.pi / 2
x_end = 7 * math.pi

# Создаем список значений x на интервале
x_values = []
step = (x_end - x_start) / 999  # Шаг между точками
current_x = x_start
while current_x <= x_end:
    x_values.append(current_x)
    current_x += step

# Вычисляем соответствующие значения функции
y_values = [func(x) for x in x_values]

# Находим минимальное и максимальное значения функции на интервале
min_y = min(y_values)
max_y = max(y_values)

# Загрузка изображения для фона
image_path = "/Users/davidmehtiev/Downloads/б.png"
bg_image = mpimg.imread(image_path)

# Создаем график
fig, ax = plt.subplots()

# Добавляем изображение на фон
ax.imshow(bg_image, extent=[x_start, x_end, min_y, max_y], aspect='auto', alpha=0.5)

# Строим график поверх изображения
ax.plot(x_values, y_values, label=r'$\sin^2(x) - \cos^2(x)$', color='blue')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title(r'$\sin^2(x) - \cos^2(x)$')
ax.grid(True)

# Отмечаем точки минимума и максимума
min_x = x_values[y_values.index(min_y)]
max_x = x_values[y_values.index(max_y)]

ax.scatter(min_x, min_y, color='green', zorder=5)
ax.text(min_x, min_y, f'Мин: ({min_x:.2f}, {min_y:.2f})', color='green', zorder=5)

ax.scatter(max_x, max_y, color='red', zorder=5)
ax.text(max_x, max_y, f'Макс: ({max_x:.2f}, {max_y:.2f})', color='red', zorder=5)

# Выводим информацию о минимальном и максимальном значениях функции
print(f"Минимальное значение функции на интервале [{x_start:.2f}, {x_end:.2f}] : {min_y:.2f}")
print(f"Точка минимума: x = {min_x:.2f}")

print(f"Максимальное значение функции на интервале [{x_start:.2f}, {x_end:.2f}] : {max_y:.2f}")
print(f"Точка максимума: x = {max_x:.2f}")

# Показываем легенду и график
ax.legend()
plt.show()