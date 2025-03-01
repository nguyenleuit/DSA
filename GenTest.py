import numpy as np
import os

# Thư mục lưu trữ file
folder = 'TestCase/'
os.makedirs(folder, exist_ok=True)

# Số phần tử mỗi dãy
n = 1_000_000

# Khoảng giá trị [-10^9, 10^9]
low = -10**9
high = 10**9

# Dãy 1 - Sắp xếp tăng dần
seq1 = np.random.randint(low, high, n, dtype=np.int64)
seq1.sort()
np.savetxt(f'{folder}Test_1_TangDan.txt', seq1, fmt='%d')

# Dãy 2 - Sắp xếp giảm dần
seq2 = np.random.randint(low, high, n, dtype=np.int64)
seq2.sort()
seq2 = seq2[::-1]
np.savetxt(f'{folder}Test_2_GiamDan.txt', seq2, fmt='%d')

# Dãy 3 đến 10 - Ngẫu nhiên
for i in range(3, 11):
    seq = np.random.randint(low, high, n, dtype=np.int64)
    np.savetxt(f'{folder}Test_{i}.txt', seq, fmt='%d')

print(f'Đã tạo xong 10 file dãy số nguyên trong thư mục "{folder}"')
