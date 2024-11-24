import numpy as np
import matplotlib.pyplot as plt

# Данные
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

def PoiskDistantMatrica(matrica):
    n=len(matrica)
    distantMatrica=np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            if i!=j:
                distantMatrica[i][j]=np.sqrt(np.sum((matrica[i]-matrica[j])**2))
            else:
                distantMatrica[i][j]=np.inf
    return distantMatrica

def PoiskMinDistant(distantMatrica):
    minDist=np.inf
    minIndixes=(-1, -1)
    n=distantMatrica.shape[0]
    for i in range(n):
        for j in range(i+1, n):
            if distantMatrica[i][j]<minDist:
                minDist=distantMatrica[i][j]
                minIndixes=(i, j)
    return minIndixes, minDist

def ObnovMatrica(distantMatrica, cluster1, cluster2):
    n=distantMatrica.shape[0]
    for i in range(n):
        if i!=cluster1 and i!=cluster2:
            distantMatrica[cluster1][i]=distantMatrica[i][cluster1]=min(distantMatrica[cluster1][i], distantMatrica[cluster2][i])
    distantMatrica=np.delete(distantMatrica, cluster2, axis=0)
    distantMatrica=np.delete(distantMatrica, cluster2, axis=1)
    return distantMatrica

def MetodSliyaniy(matrica, KolvoClusters):
    Сlusters=[[i] for i in range(len(matrica))]
    distantMatrica=PoiskDistantMatrica(matrica)
    Distances=[]
    Distances.append(np.max(distantMatrica))
    while len(Сlusters)>KolvoClusters:
        (cluster1, cluster2), Mindist=PoiskMinDistant(distantMatrica)
        Distances.append(Mindist)
        Сlusters[cluster1].extend(Сlusters[cluster2])
        del Сlusters[cluster2]
        distantMatrica=ObnovMatrica(distantMatrica, cluster1, cluster2)

    return Distances, Сlusters

VseDistant, FinalClasters = MetodSliyaniy(matrica, KolvoClusters=2)
VseDistant4Clasters, Clasters4 = MetodSliyaniy(matrica, KolvoClusters=4)

plt.figure(figsize=(10, 6))
plt.plot(range(1, len(VseDistant)+1), VseDistant, linestyle='-')
plt.xlabel('Количество кластеров')
plt.ylabel('Расстояние между кластерами')
plt.title('Кривая Торндайка')
OrigrTiks = plt.xticks()[0]
NewTiks = OrigrTiks[::-1]
plt.xticks(OrigrTiks, NewTiks.astype(int))
plt.xlim(0, 60)
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 6))
colors = ['r', 'g', 'b', 'c', 'm', 'y', 'k']
for cluster_idx, cluster in enumerate(Clasters4):
    cluster_points = matrica[cluster]
    plt.scatter(cluster_points[:, 0], cluster_points[:, 1], color=colors[cluster_idx % len(colors)], label=f'Кластер {cluster_idx + 1}')
plt.xlabel('Признак 3')
plt.ylabel('Признак 4')
plt.title('Метод последовательных слияний')
plt.legend()
plt.grid(True)
plt.show()

print("Author - Moskalenko Vitaly Alexandrovich UIB-311")