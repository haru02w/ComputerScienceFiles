import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('./ex2.csv')

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

print(describe(df))
