from sympy import Matrix, pprint

A = Matrix([[1.25,-0.75],
            [-0.75,1.25]])
eigeninfo = A.eigenvects()

v1 = eigeninfo[0][2][0]
lambda1 = eigeninfo[0][0]
v2 = eigeninfo[1][2][0]
lambda2 = eigeninfo[1][0]

print("λ_1:" + str(lambda1))
print("λ_2:" + str(lambda2))

print("v1 = ")
pprint(v1)
print("v2 = ")
pprint(v2)

P = Matrix.hstack(v1,v2)
D = Matrix([[lambda1, 0],
            [0, lambda2]])
Pinv = P.inv()

pprint(P)
pprint(D)
pprint(Pinv)

