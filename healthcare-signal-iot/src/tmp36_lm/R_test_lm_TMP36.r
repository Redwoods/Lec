
tc = c(0, 50)
vo = c(500, 1000)

df = data.frame(tc, vo)

df

lm(tc~vo, data=df)

# Tc = -50 + 0.1*Vo
# Tc = (Vo - 500)/10