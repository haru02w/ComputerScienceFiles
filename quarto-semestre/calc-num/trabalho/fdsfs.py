

for j in range(1,n+1):
    U[1][j] = A[1][j];
for i in range(2, n+1):
    L[i][1] = A[i][1] / U[1][1]

for k in range(2,n):
    for j in range(k,n+1):
        sj = 0.0
        for ir in range(1,k):
            sj = sj + L[k][ir] * U[ir][j]
        U[k][j] = A[k][j] - sj
    for i in range(k+1,n+1:)
        si = 0.0
        for ir in range(1,k):
            si = si + L[i][ir] * U[ir][k]
        L[i][k] = (A[i][k] - si)/U[k][k]
sj = 0.0
for ir in range(1,n):
    sj = sj + L[n][ir] * U[ir][n]
    U[n][n] = A[n][n] - sj

