import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('data.csv')


first_col = df['volume (ml)']

mean = first_col.mean()
median = first_col.median()

std = first_col.std()
var = first_col.var()

q1 = df.quantile(0.25).iloc[0]
mode = first_col.mode().iloc[0]
q3 = df.quantile(0.75).iloc[0]

iq = q3 - q1

print("Media: ",end='')
print(mean)
print("Moda: ",end='')
print(mode)
print()
print("Desvio Padrão: ",end='')
print(std)
print("Variancia: ",end='')
print(var)
print("Coeficiente de Variancão: ",end='')
print(f"{(std / mean) * 100 :.4f}%")

print()
print("Primeiro Quartil: ",end='')
print(q1)
print("Mediana: ",end='')
print(median)
print("Terceiro Quartil: ",end='')
print(q3)
print("IQ: ",end='')
print(iq)
print("Limite Inf: ",end='')
print(q1 - (1.5*iq))
print("Limite Sup: ",end='')
print(q3 + (1.5*iq))

print()
print("Minimo: ",end='')
print(first_col.min())
print("Maximo: ",end='')
print(first_col.max())

df.boxplot()
plt.show()
