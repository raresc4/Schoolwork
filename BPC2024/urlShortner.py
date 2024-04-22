import sys

baseShortLink = "https://ShortURL.ro/"

numbers = ['0','1','2','3','4','5','6','7','8','9']
smallLeters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
bigLeters = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

fullList = numbers + bigLeters + smallLeters

def shortenURL(nr):
    shortURL = baseShortLink
    k = 4
    l = ""
    while(nr != 0):
        k -= 1
        l += fullList[nr % 62]
        nr = nr // 62
    for i in range(k):
        shortURL += '0'
    shortURL += l[::-1]
    return shortURL

print(shortenURL(1000))

shortenURLs = {}
nrlongUrls = 0

ok = 0
for i in sys.stdin:
    line = i.strip()
    splitLine = line.split()
    if(ok == 0):
        nrOfLines = splitLine[0]
        ok = 1
    else:
        if(splitLine[0] == '1'):
            print(shortenURL(nrlongUrls))
            shortenURLs[splitLine[1]] = shortenURL(nrlongUrls)
            nrlongUrls += 1
        else:
            var = 0
            keys = list(shortenURLs.keys())
            for i in range(nrlongUrls):
                if(shortenURLs[keys[i]] == splitLine[1]):
                    print(keys[i])
                    var = 1
                    break
            if(var == 0):
                print("nu exista")