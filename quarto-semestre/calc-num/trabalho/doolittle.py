import numpy as np

def doolittle_lu_decomposition(A):
    n = len(A)
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    for i in range(n):
        L[i, i] = 1.0

        for j in range(i, n):
            U[i, j] = A[i, j] - np.dot(L[i, :i], U[:i, j])

        for j in range(i + 1, n):
            L[j, i] = (A[j, i] - np.dot(L[j, :i], U[:i, i])) / U[i, i]

    return L, U

def solve_with_doolittle(L, U, b):
    n = len(L)
    y = np.zeros(n)
    x = np.zeros(n)

    # Forward substitution: Ly = b
    for i in range(n):
        y[i] = b[i] - np.dot(L[i, :i], y[:i])

    # Backward substitution: Ux = y
    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - np.dot(U[i, i + 1:], x[i + 1:])) / U[i, i]

    return x

# Example usage
A = np.array([[2, -1, 1],
              [3, 3, 9],
              [3, 3, 5]])
b = np.array([2, 12, 14])

L, U = doolittle_lu_decomposition(A)
x = solve_with_doolittle(L, U, b)

print("Matrix L:")
print(L)
print("Matrix U:")
print(U)
print("Solution x:")
print(x)

