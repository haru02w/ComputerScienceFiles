def main():
    matrix = [[7, 1, 5],[4, 3, 5],[6, 1, 2]]
    print("\nMatriz inicial (A): ");
    print(matrix)

    result_vec = [27, 21, 9]
    print("\nVetor de Resultados (b): ", result_vec)

    lu_matrix, permut_vec, det_sign = lu_decomposition_by_gauss_elimination(matrix)
    print("\nMatrix LU: ", lu_matrix)

    det = find_det(lu_matrix, det_sign)
    print("\nDeterminante da matriz A: ", det)

    result = solve_lu_matrix(lu_matrix, result_vec, permut_vec)
    print("\nSolução do sistema: ", result)

def find_det(lu_matrix, det_sign):
    result = det_sign
    for i in range(len(lu_matrix)):
        result *= lu_matrix[i][i]
    return result

def solve_lu_matrix(lu_matrix, result_arr, permut_vec):
    # find y in Ly = b
    y = forward_sub(lu_matrix, result_arr, permut_vec)

    # find x in Ux = y
    x = backward_sub(lu_matrix, y)

    return x

def lu_decomposition_by_gauss_elimination(matrix):
    size = len(matrix)
    permut_vec = [i for i in range(size)]
    det_sign = 1

    for i in range(size):
        max_ind = find_max_ind_below(matrix, i, size)
        if(max_ind > i):
            det_sign = -det_sign
            swap_row(matrix, i, max_ind)
            swap_row(permut_vec, i, max_ind)

        pivot = matrix[i][i]

        # take the lower matrix to solve
        # ex: 3x3  turns into 2x3, 1x3
        for j in range(i + 1, size):
            factor = matrix[j][i] / pivot
            for k in range(i+1, size):
                matrix[j][k] -= factor * matrix[i][k]
            matrix[j][i] = factor
    return matrix, permut_vec, det_sign

# find the max element the the `row` comparing only the elements below it.
def find_max_ind_below(system, row, size):
    max_id = row

    for i in range(row + 1, size):
        if abs(system[i][row]) > abs(system[max_id][i]):
            max_id = i

    return max_id

def swap_row(matrix, row_1, row_2):
    matrix[row_1], matrix[row_2] = matrix[row_2], matrix[row_1]

def forward_sub(lu_matrix, result_vec, permut_vec):
    size = len(lu_matrix)
    y = [0.0] * size
    y[0] = result_vec[permut_vec[0]]
    for i in range(1, size):
        sum = 0.0
        for j in range(i):
            sum += y[j] * lu_matrix[i][j]
        y[i] = result_vec[permut_vec[i]] - sum

    return y

def backward_sub(lu_matrix, result_vec):
    size = len(lu_matrix)
    x = [0] * size

    x[size - 1] = result_vec[size - 1] / lu_matrix[size - 1][size - 1]
    for i in range(size - 2, -1, -1):
        sum = 0.0
        for j in range(i + 1, size):
            sum += x[j] * lu_matrix[i][j]
        x[i] = (result_vec[i] - sum) / lu_matrix[i][i]

    return x

if __name__ == "__main__":
    main()
