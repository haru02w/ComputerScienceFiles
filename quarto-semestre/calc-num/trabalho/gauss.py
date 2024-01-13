"""
It's all wrong
"""
n = int(input("Digite o tamanho da matriz: "))

A = []
b = []
x = []

for i in range(0, n):
    A.append([])
    for j in range(0, n):
        print("Digite o valor da matrix[", i + 1, ",", j + 1, "]: ")
        A[i].append(float(input()))

for i in range(0, n):
    print("Digite o valor de b[", i + 1, "]: ")
    b.append(float(input()))

k = 0
while k < n:
    for i in range(k, n):
        mult = A[i][k] / A[k][k]
        for j in range(k, n):
            A[i][j] = A[i][j] - mult * A[k][j]
        b[i] = b[i] - mult * b[k]
    k = k + 1
x[n] = b[n] / A[n][n]
for i in range(n, 0, -1):
    sum = 0
    for j in range(i, n):
        sum = sum + A[i][j] * x[j]
    x[i] = (b[i] - sum) / A[i][i]
