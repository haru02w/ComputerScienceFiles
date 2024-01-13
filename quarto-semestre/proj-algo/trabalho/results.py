import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('./results.txt')

tempo_esperado = [(xi*0.00014)**2 for xi in df['iteracao']]

df = df[tempo_esperado > df['tempo']]
print(df.iloc[0])

tempo_esperado = [(xi*0.00014)**2 for xi in df['iteracao']]

plt.plot(df['iteracao'], df['tempo'], label='tempo obtido')
plt.plot(df['iteracao'], tempo_esperado,label='tempo esperado')
plt.legend(loc="upper left")
plt.xlabel('Iteração')
plt.ylabel('Tempo (s)')
plt.title('Tempo por Iteração Selection Sort')
plt.grid(True)
plt.savefig("maior.png",dpi=300)
