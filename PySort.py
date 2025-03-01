import numpy as np
import time

with open("output.txt", "w") as output_file:

    input_files = [
        "Test_1.txt", "Test_2.txt", "Test_3.txt", 
        "Test_4.txt", "Test_5.txt", "Test_6.txt", 
        "Test_7.txt", "Test_8.txt", "Test_9.txt", 
        "Test_10.txt"
    ]

    for file_name in input_files:
        with open(file_name, "r") as f:
            numbers = np.fromfile(f, sep=" ", dtype=np.int64)

        start = time.time()
        numbers.sort()
        end = time.time()

        duration_ms = (end - start) * 1000

        output_file.write(f"Thoi gian thuc thi file {file_name}: {duration_ms:.2f} ms\n")

        print(f"Thoi gian thuc thi file {file_name}: {duration_ms:.2f} ms")
