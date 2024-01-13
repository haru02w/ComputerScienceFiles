import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

csv_file = 'analise_mercado.csv'
df = pd.read_csv(csv_file)

df = df[(df['NÚMERO DE QUARTOS'] >= 3) & 
        (df['VALOR DA CASA'] <= 350000) &
        (df['NÚMERO DE BANHEIROS'] >= 2)]

# grouped_data = df.groupby('BAIRRO').count()
# recommended_bairros = grouped_data.sort_values('VALOR DA CASA', ascending=True)
colors = np.where(df['EDICULA'], 'blue', 'red')
plt.scatter(df['BAIRRO'],df['VALOR DA CASA'],c=colors)

plt.ylabel('Preço')
plt.xlabel('Bairros')
plt.title('Dot Plot: Valor da Casa por Bairro')
plt.xticks(rotation=-90)

legend_labels = ['Sem Edicula', 'Com Edicula']
colors = ['red', 'blue']
legend_elements = [plt.Line2D([0], [0], marker='o', color='w', label=label, markerfacecolor=color, markersize=10) for label, color in zip(legend_labels, colors)]
plt.legend(handles=legend_elements, title='Significado das Cores', loc='upper right')


plt.show()
