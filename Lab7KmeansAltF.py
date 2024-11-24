import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

def Kmeans(matrica, k, Max=100, tol=1e-4):
    Centroids=matrica[np.random.choice(matrica.shape[0], size=1, replace=False)]
    for _ in range(1, k):
        Distants=np.linalg.norm(matrica[:, np.newaxis]-Centroids, axis=2)
        MinDistants=np.min(Distants, axis=1)
        NewCentroid=matrica[np.random.choice(matrica.shape[0], p=MinDistants/np.sum(MinDistants))]
        Centroids=np.vstack([Centroids, NewCentroid])
    for iteration in range(Max):
        Distants=np.linalg.norm(matrica[:, np.newaxis]-Centroids, axis=2)
        Labels=np.argmin(Distants, axis=1)
        NewCentroids=np.array([matrica[Labels==i].mean(axis=0) for i in range(k)])
        if np.all(np.abs(NewCentroids-Centroids)<tol):
            break
        Centroids=NewCentroids
    return Labels, Centroids

dannie = """
2 52
3 44
4 30
5 34
6 54
8 46
9 26
10 36
10 58
11 50
13 28
14 42
15 56
16 34
17 48
24 24
25 12
26 18
27 8
27 28
29 24
30 16
30 30
32 4
32 22
33 12
34 26
35 6
36 20
37 12
20 88
21 96
22 80
23 90
23 102
25 106
26 78
26 88
26 100
27 72
29 92
30 82
30 104
32 86
32 96
7 70
4 72
7 74
10 74
6 78
9 78
11 80
5 82
7 84
13 86
10 88
8 90
12 92
9 96
11 100
"""

matrica=np.array([list(map(int, line.split())) for line in dannie.strip().split("\n")])
Mashtab=StandardScaler()
MatricaNormal=Mashtab.fit_transform(matrica)
k=4
Labels, Centroids=Kmeans(MatricaNormal, k)
CentroidsOriginalMashtab=Mashtab.inverse_transform(Centroids)
plt.figure(figsize=(10, 6))
Scatter=plt.scatter(matrica[:, 0], matrica[:, 1], c=Labels)
for i in range(k):
    plt.scatter([], [], color=Scatter.cmap(Scatter.norm(i)), label=f'Кластер {i+1}')
plt.scatter(CentroidsOriginalMashtab[:, 0], CentroidsOriginalMashtab[:, 1], c='black', marker='X', s=200, label='Центроиды кластеров')
plt.title('Алгоритм k-средних')
plt.xlabel('Признак 3')
plt.ylabel('Признак 4')
plt.legend(loc='upper right')
plt.grid(True)
plt.show()

print("Author - Moskalenko Vitaly Alexandrovich UIB-311")