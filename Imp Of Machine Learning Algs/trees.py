from math import log
from collections import Counter

def calcShanon(dataset): #calcShanon = -sum(p_{i}*log_2(p_{i}))
    numentries = len(dataset)
    labelcounts = {}
    for vect in dataset: #vect is a row in the ds.
        currentlabel = vect[-1]
        if currentlabel not in labelcounts.keys():
            labelcounts[currentlabel] = 0 #initialize
        labelcounts[currentlabel] += 1
    shanonent = 0.0
    for key in labelcounts: #calc shanon's etropy for each class.
        prob = float(labelcounts[key]/numentries)
        shanonent -= prob * log(prob,2)
    return shanonent

def splitdataset(dataset,axis,value):
    retdataset = []
    for vect in dataset:
        if vect[axis] == value:
            redvect = vect[:axis]
            redvect.extend(vect[axis + 1:])
            retdataset.append(redvect)
    return retdataset

def choosebestfeaturetosplit(dataset):
    numfeatures = len(dataset[0]) -1
    base_ent = calcShanon(dataset)
    best_IG = 0
    best_feature = -1
    for i in range(numfeatures):
        classes = [row[i] for row in dataset]
        classes = set(classes) #getting to know the different classes.
        new_ent = 0
        for value in classes:
            sub_dataset = splitdataset(dataset,i,value)
            new_ent += calcShanon(sub_dataset) #calculating the entropy for the split.
        IG = base_ent - new_ent #the info gain of the split
        if (IG > best_IG):
            best_IG = IG
            best_feature = i
    return best_IG, best_feature

def majoritycounter(classlist):
    listt = Counter(classlist)
    return listt.most_common(1)[0][0]

listt = [[1, 1, 'yes'],
        [1, 1, 'yes'], 
        [1, 0, 'no'],
        [0, 1, 'no'],
        [0, 1, 'no']]

#print(calcShanon(listt))
'''lol = []
for vect in listt:
    if vect[1] == 1:
        redvect = vect[:0]
        redvect.extend(vect[1:])
        lol.append(redvect)
print(lol)

'''
print(choosebestfeaturetosplit(listt))