import math

def divErrors(a,b,da,db):
    # return error on a/b
    return (1.0*a/b)*math.sqrt( (da/a)**2.0 + (db/b)**2.0 )

def convertNames(cutName):
    cutName = cutName.replace(">=","\\geq ")
    cutName = cutName.replace("<=","\\leq ")
    cutName = cutName.replace("ht","H_\\mathrm{T}")
    cutName = cutName.replace("mtmin","m^\\mathrm{T}_\\mathrm{min}")
    cutName = cutName.replace("njets","\\mathrm{Njets}")
    cutName = cutName.replace("met","\\met")
    cutName = cutName.replace("HH","\\mathrm{HH}")
    cutName = cutName.replace("HL","\\mathrm{HL}")
    cutName = cutName.replace("nbtags","\\mathrm{Nbtags}")
    return cutName

def countsAndErrors(sampleCounts):
    tot = 0.0
    totErr = 0.0

    tot = sampleCounts["WZ"][0]
    totErr = sampleCounts["WZ"][1]

    return round(tot,2),round(totErr,2)

def purity(sampleCounts):
    nWZ = sampleCounts["WZ"][0]
    nAll = sum([sampleCounts[sample][0] for sample in allsamples])
    return nWZ/nAll*100


lines = open("input.txt","r").readlines()
allsamples = ["TTBAR","DY","TTW","TTZ","WJets","WZ","ZZ","Data"] 

cutCounts = {}
for line in lines:
    if("_" not in line): continue
    line = line.strip()
    cut = line.split()[0].split("_")[0]
    sample = line.split()[0].split("_")[1]
    count = line.split()[1]
    error = line.split()[2]

    if(cut not in cutCounts):
        cutCounts[cut] = { }
        for all in allsamples: cutCounts[cut][all] = [ 0.0, 0.0 ]

        cutCounts[cut][sample] = [ float(count), float(error) ]
    else: 
        cutCounts[cut][sample] = [ float(count), float(error) ]


# group them into pairs
cutCountsList = []
for cut in cutCounts.keys():
    cAndE = countsAndErrors(cutCounts[cut])
    # print purity(cutCounts[cut])
    cutCountsList.append( [cut, cAndE[0], cAndE[1], purity(cutCounts[cut])] )

cutCountsList.sort()

cutCountsPairs = zip(cutCountsList[0::2],cutCountsList[1::2])

print "- | Events | WZ Purity | Threshold efficiency"
print ""
for pair in cutCountsPairs:
    elem1, elem2 = pair
    # want elem1 to have larger counts
    if(elem2[1] > elem1[1]):
        elem1, elem2 = elem2, elem1

    # compute efficiency and error
    eff = elem2[1]/elem1[1]
    effErr = divErrors(elem2[1],elem1[1],elem2[2],elem1[2])

    cutName1 = convertNames(elem1[0].split(":")[-1])
    cutName2 = convertNames(elem2[0].split(":")[-1])

    print "$%s$ | $ %.2f \\pm %.2f $ | $ %.1f \\%% $ | multirow 2 $ %.2f\\pm %.2f $" % (cutName1, elem1[1], elem1[2], elem1[3], eff, effErr)
    print "$%s$ | $ %.2f \\pm %.2f $ | $ %.1f \\%% $ " % (cutName2, elem2[1], elem2[2], elem2[3])

