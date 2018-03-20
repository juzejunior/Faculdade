"""
 It calculates square root with bisection method
"""

import sys

def f(x):
    return (x - 1) * (x - 10)

def bisection(a, b, tolerance):
    x1 = (a+b) / 2.0
    while(b-a) / 2.0 > tolerance:
        print("A: "+str(a))
        print("B: "+str(b))
        print("Tolerance aproximation: "+str((b-a)/2.0))
        if (f(x1) == 0):
            return x1
        elif f(a) * f(x1) < 0:
            b = x1
        else:
            a = x1
        x1 = (a+b) / 2.0
    return x1

if __name__ == '__main__':
    if (len(sys.argv) != 4):
		sys.exit('Usage: bisection.py <a> <b> <tolerance>')
    print("\nSquare root: "+str(bisection(float(sys.argv[1]), float(sys.argv[2]), float(sys.argv[3]))))
