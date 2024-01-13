import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("dados.csv")

_, ax2 = plt.subplots(nrows=1,ncols=3)

bins = 5
x_range = (87.4,88.4)
df['maquina A'].hist(ax=ax2[0],range=x_range,bins=bins)
df['maquina B'].hist(ax=ax2[1],range=x_range,bins=bins)

max_y = 15
ax2[0].set_ylim(0, max_y)
ax2[1].set_ylim(0, max_y)

df[['maquina A','maquina B']].boxplot(ax=ax2[2])

plt.show()
