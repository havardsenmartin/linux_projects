from sympy import Matrix, pprint

A = Matrix([[0.4,0.2,0.3],
            [0.3,0.6,0.3],
            [0.3,0.2,0.4]])

A.det()
A.inv()
A.rref()
A.nullspace()
A.columnspace()
A.eigenvals()

for i in range(10):
    pprint(A)
    A.multiply(A)
