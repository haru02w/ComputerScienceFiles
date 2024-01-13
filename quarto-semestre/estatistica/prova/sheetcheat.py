import pandas as pd
import matplotlib.pyplot as plt

def describe(df):
    q1 = df.quantile(0.25)
    q3 = df.quantile(0.75)
    iq = q3 - q1
    return pd.concat([
                      df.mode().iloc[0].rename('mode'),
                      df.describe().T,
                      df.var().rename('var'),
                      iq.rename('IQ'),
                      ((df.std() / df.mean())*100).rename('CV'),
                      df.skew().rename("cof asim"),
                      (q1 - (1.5*iq)).rename('lim inf'),
                      (q3 + (1.5*iq)).rename('lim sup')
                     ], axis=1).T

df = pd.read_csv("data.csv")

df.head() # primeiros elementos
df.tail() # ultimos elementos

df.info() # tipos de dados e dados nao nulos
df.describe() # estatisticas sumarizadas

value = 3 #ignore

df[df['column'] > value] # filtrando valores

df.groupby('column') # agrupando (tira repetidos somando)

df['column'].sum() # soma todos os dados da coluna

# plots

#####
ax = df.plot(x='Categories', kind='bar', width=0.7, position=0, label='Set 1')
df.plot(x='Categories', kind='bar', width=0.7, position=1, ax=ax, label='Set 2')

plt.xlabel('Categories')
plt.ylabel('Values')
plt.title('Comparison of Categories')
plt.legend()
######

fig,axes = plt.subplots(1,5,sharex=True,sharey=True) # mesma escala pros subgraficos

# ax=subplot que vc quer colocar
df.plot(x="x_column",y="y_column",ax=axes[0]) # grafico de linha 
df.plot.scatter(x="x_column",y="y_column",ax=axes[1]) # dotplot
df['column'].plot(kind='bar',ax=axes[2]) # grafico de barras
df['column'].plot.hist(ax=axes[3], bins=[1,2,3,4,5]) # histograma (bins = barras)
df.boxplot(column='column',ax=axes[4]) # boxplot
df['column'].value_counts().plot_pie(ax=axes[5]) # grafico pizza

# seta uma legenda em comum dos graficos
fig.text(0.04, 0.5, 'Y-axis Label', va='center', rotation='vertical')

plt.show() # mostrar
plt.savefig('filename.png') # salvar

