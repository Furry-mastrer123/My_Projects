import numpy as np

x = np.array([
0.22,	
0.71,	
1.23,	
1.64,	
2.015,
2.38,
])


y = np.array([
0.048,
0.172,	
0.342,	
0.446,	
0.542,	
0.635,
])

def mnk (x, y):
    k, b = np.polyfit(x, y, 1)

    r = np.corrcoef(x,y)[0,1]
    return k,b,r
k, b, r = mnk(x, y)
print(k, b, r)