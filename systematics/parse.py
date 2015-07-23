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

def countsAndErrors(sampleCounts, WZonly=False):
    tot = 0.0
    totErr = 0.0

    if(WZonly):
        tot = sampleCounts["WZ"][0]
        totErr = sampleCounts["WZ"][1]
    else:
        tot = sum([sampleCounts[sample][0] for sample in allsamples])
        totErr = math.sqrt(sum([sampleCounts[sample][1]**2.0 for sample in allsamples]))

    return tot,totErr
    # return round(tot,4),round(totErr,4)

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
    cAndEWZ = countsAndErrors(cutCounts[cut],WZonly=True)
    cAndE = countsAndErrors(cutCounts[cut])
    cutCountsList.append( [cut, cAndE[0], cAndE[1], cAndEWZ[0], cAndEWZ[1], purity(cutCounts[cut])] )

cutCountsList.sort()

cutCountsPairs = zip(cutCountsList[0::2],cutCountsList[1::2])

# print "- | WZ Events | WZ Purity | Threshold efficiency"
print "- | Events | WZ Events | WZ Purity | WZ Above Threshold | $\\delta $WZ/WZ"
print ""
for pair in cutCountsPairs:
    elem1, elem2 = pair

    # 0 cut
    # 1 counts total
    # 2 err total
    # 3 counts WZ
    # 4 err WZ
    # 5 purity WZ
    # want elem1 to have larger counts

    if(elem2[1] > elem1[1]):
        elem1, elem2 = elem2, elem1

    WZ1 = elem1[3]
    WZ2 = elem2[3]

    T1, dT1 = elem1[1], math.sqrt(elem1[1])
    T2, dT2 = elem2[1], math.sqrt(elem2[1])

    NonWZ1 = T1 - WZ1
    NonWZ2 = T2 - WZ2

    pctSyst = 0.3
    dNonWZ1 = pctSyst * NonWZ1
    dNonWZ2 = pctSyst * NonWZ2

    eff = WZ2
    effErrStat = math.sqrt(WZ2)
    effErrStatSyst = math.sqrt( dT2**2 + dNonWZ1**2)
    effErrSyst = math.sqrt(effErrStatSyst**2 - effErrStat**2)

    relErrorWZ = effErrStatSyst / WZ2

    cutName1 = convertNames(elem1[0].split(":")[-1])
    cutName2 = convertNames(elem2[0].split(":")[-1])

    # print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f \\pm %.2f $ | $ %.1f \\%% $ | multirow 2 $ %.2f\\pm %.2f~\\mathrm{(stat)}~\\pm %.2f~\\mathrm{(syst)} $ | multirow 2 %.2f " \
    #         % (cutName1, elem1[1], elem1[2], elem1[3], elem1[4], elem1[5], eff, effErrStat, effErrSyst, effErrStatSyst)
    # print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f \\pm %.2f $ | $ %.1f \\%% $ " % (cutName2, elem2[1], elem2[2], elem2[3], elem2[4], elem2[5])

    print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | multirow 2 $ %.2f\\pm %.2f~\\mathrm{(stat.)}\\pm %.2f~\\mathrm{(syst.)} $ | multirow 2 %.2f " \
            % (cutName1, elem1[1], dT1, elem1[3], elem1[5], eff, effErrStat, effErrSyst, relErrorWZ)
    print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ " % (cutName2, elem2[1], dT2, elem2[3], elem2[5])

