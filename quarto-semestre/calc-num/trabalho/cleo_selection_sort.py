import math
import pandas as pd
import matplotlib.pyplot as plt

def least_squares(x, y):
    if len(x) != len(y):
        ValueError("As listas x e y devem ter o mesmo tamanho.")

    # calcula o tamanho do intervalo
    n = len(x)
    sum_x = sum(x) # somatoria todos os valores do eixo x
    sum_y = sum(y) # somatoria de todos os valores do eixo y
    sum_x_squared = sum(xi**2 for xi in x) # somatoria dos valores do eixo x ao quadrado
    sum_xy = sum(xi * yi for xi, yi in zip(x, y)) # somatoria do produto de cada x com cada y

    # Calcula os coeficientes da linha de aproximação
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x ** 2)
    a = (sum_y - b * sum_x) / n

    return a, b

def least_squares_error(y, y_pred):
    # Calcula a soma dos quadrados dos resíduos (RSS)
    return sum((yi - y_predi) ** 2 for yi, y_predi in zip(y, y_pred))


# Exemplo de uso
df = pd.read_csv('./results.csv')
x = df['iteracao']
y = df['tempo']
plt.scatter(x, y, label='pontos conhecidos') # plota os pontos no grafico

# Calcula a reta aproximada
a, b = least_squares(x, y)
# calcula os pontos para g(x)
g = [a + b*xi for xi in x]
# calcula o erro entre os pontos de f(x) e g(x)
rss = least_squares_error(y, g)
# mostra na tela
print(f"Equação: y = {a}+{b}x")
print(f"Erro: {rss}")

# faz a linha representando a função g(x) no grafico
plt.plot(x, g,label='aproximacao linear',linewidth=2,color='black')
print()
print()

# faz ln(f(x)) para todos os valores obtidos de f(x)
ln_y = [math.log(yi) for yi in y]
# calcula a função exponencial usando ln(f(x))
a1, a2 = least_squares(x, ln_y)

# transforma `a1` e `a2` para `a` e `b`
a = math.exp(a1)
b = a2

# calcula os pontos na g(x) encontrada
g = [a * math.exp(b * xi) for xi in x]

# calcula o erro entre os pontos de f(x) e g(x)
rss = least_squares_error(y, g)
# mostra na tela
print(f"Equação: y = {a}e^({b}x)")
print(f"Erro: {rss}")

# coloca a linha de g(x) no grafico
plt.plot(x, g,label='aproximacao exponencial',linewidth=2,color='orange')

print()
print()

# faz ln(f(x)) para todos os valores obtidos de f(x)
ln_y = [math.log(yi) for yi in y if y[0] != yi]
# faz ln(x) para todos os valores obtidos de x
ln_x = [math.log(xi) for xi in x if xi != 0]

# calcula a função polinomial usando ln(f(ln(x)))
a1, a2 = least_squares(ln_x, ln_y)
a = math.exp(a1)
b = a2

# calcula os pontos na g(x) encontrada
g = [a * xi ** b for xi in x]

# calcula o erro entre os pontos de f(x) e g(x)
rss = least_squares_error(y, g)
# mostra na tela
print(f"Equação: y = {a}x^{b})")
print(f"Erro: {rss}")

# coloca a linha de g(x) no grafico
plt.plot(x, g, label='aproximacao polinomial',linewidth=2,color='red')

# define os nomes dos eixos e titulo do grafico
plt.xlabel("x")
plt.ylabel("y")
plt.title("Método dos Quadrados Minimos")
plt.legend()
# mostra o grafico
plt.savefig('selection.png')
