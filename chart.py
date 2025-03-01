import matplotlib.pyplot as plt
import numpy as np

# Tên các thuật toán và dữ liệu thời gian thực hiện từ bảng
labels = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'Trung bình']
quicksort = [90, 117, 95, 92, 98, 107, 93, 92, 93, 92, 96.9]
heapsort = [312, 425, 420, 403, 419, 456, 418, 327, 417, 417, 402.2]
mergesort = [464, 448, 492, 547, 532, 545, 568, 493, 517, 517, 509.5]
cpp_sort = [213, 157, 174, 207, 146, 242, 186, 218, 154, 154, 193.9]
numpy_sort = [86, 75, 77, 82, 75, 77, 77, 74, 80, 80, 78.7]

x = np.arange(len(labels))  # vị trí các cột

width = 0.15  # độ rộng của mỗi cột

# Vẽ biểu đồ
fig, ax = plt.subplots(figsize=(12, 6))

ax.bar(x - 2*width, quicksort, width, label='Quicksort', color='dodgerblue')
ax.bar(x - width, heapsort, width, label='Heapsort', color='orange')
ax.bar(x, mergesort, width, label='Mergesort', color='gray')
ax.bar(x + width, cpp_sort, width, label='sort (C++)', color='yellowgreen')
ax.bar(x + 2*width, numpy_sort, width, label='sort (numpy)', color='crimson')

# Thêm các thông tin hiển thị
ax.set_xlabel('Bộ dữ liệu')
ax.set_ylabel('Thời gian thực hiện (ms)')
ax.set_title('So sánh thời gian thực hiện các thuật toán sắp xếp')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()

# Hiển thị giá trị trên mỗi cột (tuỳ chọn)
def add_labels(bars):
    for bar in bars:
        height = bar.get_height()
        plt.annotate(f'{height:.1f}',
                     xy=(bar.get_x() + bar.get_width() / 2, height),
                     xytext=(0, 3),  # 3 points offset
                     textcoords="offset points",
                     ha='center', va='bottom', fontsize=8)

for bar_group in ax.containers:
    add_labels(bar_group)

plt.tight_layout()

# Lưu hoặc hiển thị
plt.savefig('comparison_chart.png', dpi=300)
plt.show()
