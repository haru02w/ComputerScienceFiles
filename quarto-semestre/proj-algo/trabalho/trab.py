import matplotlib.pyplot as plt
import random as rd
import time as t

start_time = 25045

# Selection sort in Python
# time complexity O(n*n)
#sorting by finding min_index
def selectionSort(array, size):
    start = t.time()
    for ind in range(size):
        min_index = ind

        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j
         # swapping the elements to sort the array
        (array[ind], array[min_index]) = (array[min_index], array[ind])
    return t.time() - start

for i in range(start_time,500000,5):
    arr = [rd.randint(0, 2**31 -1) for _ in range(i)]
    time = selectionSort(arr, len(arr))
    print(f'{i}, {time}')
    with open('results.txt','a') as f:
        f.write(f'{i},{time}\n')
