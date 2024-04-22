import sys
import functools

sys.setrecursionlimit(10000)

minList = []

def min(l):
    min = l[0]
    for i in l:
        if(i < min):
            min = i
    return min

def scoateMin(l):
    minim = min(l)
    l.remove(minim)
    return minim

def rec(l,k = 1):
    if(len(l) == 1):
        return l[0] + functools.reduce(lambda a,b: a+b, minList) 
    else:
        if(k == 1):
            m = scoateMin(l)
            l[l.index(min(l))] += m
            k = 0
            return rec(l,k)
        else:
            m = scoateMin(l)
            minList.append(m)
            l[l.index(min(l))] += m
            return rec(l,k)

ok = 0
for i in sys.stdin:
    line = i.strip()
    splitLine = line.split()
    if(ok == 0):
        nrOfLines = splitLine[0]
        ok = 1
    else:
        splitLine = list(map(int, splitLine))
        print(rec(splitLine))
