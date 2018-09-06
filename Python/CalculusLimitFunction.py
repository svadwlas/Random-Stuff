
"""
Calculating Limits (Calculus) in Python
lim x→x0 - f(x) can be calculated using sympy
The symbol oo is used for a class defining mathematical infinity

"""



from sympy import *

limit(f(x), x, x0)


x = symbols('x')

r = limit((1+1/x)**x, x, 00)

print(r)



