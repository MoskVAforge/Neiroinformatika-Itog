from InfoFileLab8 import vectoryLic, klassovyeGruppy, soedinenieKlassov
import numpy as np
import copy
import random
import matplotlib.pyplot as plt


def Obuchenie(obuchDannie, vybrannyeKlassy=[], pokazGrafiki=False, pokazVesa=False, mestoDlyaCiklaSShagom=""):
    dannieDlyaObucheniya = copy.deepcopy(obuchDannie)
    skorostObucheniya = 0.2
    klassy = list(range(0, len(vybrannyeKlassy)))

    for i, (klass, atributy) in enumerate(dannieDlyaObucheniya):
        dannieDlyaObucheniya[i] = (klass, np.array(atributy) / 50.0 - 1)
    dannye = []
    for klass, atributy in dannieDlyaObucheniya:
        if klass in vybrannyeKlassy:
            dannye.append([klassy[vybrannyeKlassy.index(klass)], atributy])
        else:
            dannye.append([klassy[vybrannyeKlassy.index(-1)], atributy])
    for i in range(6):
        dannye += dannye

    random.shuffle(dannye)
    vesa = [np.random.uniform(-0.1, 0.1, size=len(dannye[0][1])) for _ in klassy]
    poteriPoKlassam = {klass: [] for klass in klassy}
    tochnostPoKlassam = {klass: [] for klass in klassy}
    znacheniyaEpokh = []
    luchshieVesa = None

    for epokha in range(1, 200):
        obshayaPoteria = 0
        summarnyePoteriPoKlassam = {klass: 0 for klass in klassy}
        pravilnoOpredelennyeKlass = {klass: 0 for klass in klassy}
        vsegoPoKlassam = {klass: 0 for klass in klassy}

        for klass, atributy in dannye:
            summyVesov = [np.dot(ves, atributy) for ves in vesa]
            maxSumma = np.max(summyVesov)
            eksponenty = np.exp(summyVesov - maxSumma)
            softmax = eksponenty / np.sum(eksponenty)
            oneHot = np.zeros(len(vesa))
            oneHot[klass] = 1
            poteria = -np.sum(oneHot * np.log(softmax))
            obshayaPoteria += poteria
            summarnyePoteriPoKlassam[klass] += poteria
            vsegoPoKlassam[klass] += 1
            oshibka = softmax - oneHot
            grad = np.outer(oshibka, atributy)
            vesa -= skorostObucheniya * grad

        matricaSputannosti = [[0 for klass in klassy] for klass in klassy]

        for testKlass, testVector in dannye:
            summResultat = raspoznaniePerc(testVector, vesa)
            predskazannyiKlass = max(summResultat, key=summResultat.get)
            matricaSputannosti[predskazannyiKlass][testKlass] += 1

            if predskazannyiKlass == testKlass:
                pravilnoOpredelennyeKlass[testKlass] += 1

        for klass in klassy:
            ideal = True
            if vsegoPoKlassam[klass] > 0:
                tochnost = pravilnoOpredelennyeKlass[klass] / vsegoPoKlassam[klass]
                if tochnost != 1:
                    ideal = False
                sredPoteria = summarnyePoteriPoKlassam[klass] / vsegoPoKlassam[klass]
                tochnostPoKlassam[klass].append(tochnost)
                poteriPoKlassam[klass].append(sredPoteria)
            else:
                tochnostPoKlassam[klass].append(0)
                poteriPoKlassam[klass].append(0)

        znacheniyaEpokh.append(epokha)

        if ideal and luchshieVesa is None:
            luchshieVesa = vesa

    if luchshieVesa is None:
        luchshieVesa = vesa

    if pokazGrafiki:
        plt.figure(figsize=(10, 6))
        for klass in klassy:
            plt.plot(znacheniyaEpokh, tochnostPoKlassam[klass], label=f'{"Класс: " + str(vybrannyeKlassy[klass] + 1) if vybrannyeKlassy[klass] != -1 else "Остальные классы"}')
        plt.xlabel("Эпоха")
        plt.ylabel("Точность")
        plt.title("Точность персептрона по классам")
        plt.legend()
        plt.grid(True)
        plt.show()

    if pokazVesa:
        print("\nВеса:")
        for klass, ves in enumerate(luchshieVesa):
            print(f"Класс: {vybrannyeKlassy[klass] + 1}, Веса: {ves.tolist()}")

    return luchshieVesa

def raspoznaniePerc(vhodnoiVektor, vesa):
    vzveshennyeSummy = [np.dot(ves, vhodnoiVektor) for ves in vesa]
    softmax = np.exp(vzveshennyeSummy) / np.sum(np.exp(vzveshennyeSummy))
    return {i: softmax[i] for i in range(len(vesa))}

def normirovkaPriznakov(priznaki):
    normirovannyePriznaki = (priznaki - np.mean(priznaki)) / np.std(priznaki)
    return normirovannyePriznaki

def kaskadnayaKlassifikaciya(priznaki, spisokVesov, indeksSoedineniyaKlassov):
    tekushiePriznaki = normirovkaPriznakov(np.array(priznaki))
    rezultaty = []
    for i, ves in enumerate(spisokVesov):
        if ves is None:
            raise ValueError(f"Персептрон {i + 1}: Оптимальные веса отсутствуют!")
        vyrabotki = np.dot(ves, tekushiePriznaki)
        maksimalnyiIndeks = np.argmax(vyrabotki)
        if maksimalnyiIndeks == len(ves) - 1:
            rezultaty.append(f"Персептрон {i + 1}: Дальше")
            continue
        else:
            klassRezultata = indeksSoedineniyaKlassov[i][maksimalnyiIndeks]
            rezultaty.append(f"Персептрон {i + 1} {klassRezultata}")
            return rezultaty
    finalnyiKlass = indeksSoedineniyaKlassov[-1][maksimalnyiIndeks]
    rezultaty.append(f"Персептрон {len(spisokVesov)} {finalnyiKlass}")
    return rezultaty

def filtrDannie(udalyaemyeKlassy):
    novyiDataset = []
    for klass, attr in vectoryLic:
        if klass in udalyaemyeKlassy:
            continue
        novyiDataset.append([klass, attr])
    return novyiDataset


if __name__ == "__main__":
    priznaki = list(map(float, input("Введите вектор данных человека (20 признаков через пробел): ").split()))
    ispolzuemyeKlassy = []
    spisokVesov = []
    pokazGrafiki = input("Отобразить графики (да/нет)? ").strip().lower() == 'да'
    pokazVesa = input("Вывести веса персептронов (да/нет)? ").strip().lower() == 'да'

    for shag, klassSet in enumerate(klassovyeGruppy):
        dannyeObucheniya = [d for d in vectoryLic if d[0] not in ispolzuemyeKlassy]
        vesa = Obuchenie(dannyeObucheniya, klassSet, pokazGrafiki, pokazVesa, f"Шаг {shag + 1}")
        spisokVesov.append(vesa)
        ispolzuemyeKlassy += klassSet

    resultaty = kaskadnayaKlassifikaciya(priznaki, spisokVesov, soedinenieKlassov)
    for resultat in resultaty:
        print(resultat)

    print("Автор - Москаленко Виталий Александрович УИБ-311")
