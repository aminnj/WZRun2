import math, os, sys


def divErrors(a,b,da,db):
    # return error on a/b
    return (1.0*a/b)*math.sqrt( (da/a)**2.0 + (db/b)**2.0 )

def latexNames(cutName):
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

def SRtoCuts(srcode):
    srcode = srcode.replace("SR","")
    srtype = ""
    srtype2 = ""
    if( "A" in srcode ):
        srcode = srcode.replace("A","")
        srtype = "A"
    else:
        srcode = srcode.replace("B","")
        srtype = "B"

    if( "a" in srcode ):
        srcode = srcode.replace("a","")
        srtype2 = "a"
    elif( "b" in srcode ):
        srcode = srcode.replace("b","")
        srtype2 = "b"
    else: pass

    srnum = int(srcode)

    # srtype will be A,B,C
    # 1 Njets
    # 2 Nbtags
    # 3 MET
    # 4 ht
    # 5 mtmin
    # 6 hh,hl
    cuts = []
    # orCuts = []

    if( srtype == "A" ):
        if( srnum in [9,10,12,13,14,15] ): cuts.append(2)
        if( srnum in [4,6,12,14] ): cuts.append(1)
        if( srnum in [5,6,13,14] ): cuts.append(3)
        if( srnum in [7,15] ): cuts.append(5)
        if( srnum in [2,4,5,6,7,10,12,13,14,15] ): cuts.append(4)

        if( srnum == 3 ):
            if( srtype2 == "a"): cuts += [3]
            if( srtype2 == "b"): cuts += [5]
        if( srnum == 8 ):
            cuts += [3,5]
        if( srnum == 11 ):
            if( srtype2 == "a"): cuts += [2,3]
            if( srtype2 == "b"): cuts += [2,5]
        if( srnum == 16 ):
            cuts += [2,3,5]

            
    else:
        cuts.append(6)
        if( srnum in [7,8,10,11,12] ): cuts.append(2)
        if( srnum in [4,6,10,12] ): cuts.append(1)
        if( srnum in [5,6,11,12] ): cuts.append(3)
        if( srnum in [2,4,5,6,8,10,11,12] ): cuts.append(4)

        if( srnum == 3 ):
            cuts += [3] 
        if( srnum == 9 ):
            cuts += [3,2] 

    # if(len(cuts) > 0): orCuts.append(cuts)
    # return orCuts
    return cuts

def SRerrors(cuts,initialWZ):
    finalWZ = 0.0
    finalErrSq = 0.0
    for cut in cuts:
        WZ1, WZ2, relErrorWZ = mainCutCountErr[cut]
        finalErrSq += relErrorWZ**2.0
    finalRelErr = math.sqrt(finalErrSq)
    return finalWZ, finalRelErr



def cutsToStr(cuts):
    # orStrings = []
    # for andCuts in cuts:
        # orStrings.append( " && ".join([cutStrDict[cut] for cut in andCuts]) )
    # return "("+") || (".join(orStrings)+")"
    return " && ".join([cutStrDict[cut] for cut in cuts])

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

def purity(sampleCounts):
    nWZ = sampleCounts["WZ"][0]
    nAll = sum([sampleCounts[sample][0] for sample in allsamples])
    return nWZ/nAll*100

lines = open("counter.txt","r").readlines()
# allsamples = ["TTBAR","DY","TTW","TTZ","WJets","WZ","ZZ","Data"] 
allsamples = ["TTBAR","DY","TTW","TTZ","WJets","WZ","ZZ"] 
cutStrDict = { 1: "njets>=5", 2: "nbtags>=1", 3: "met>=200", 4: "ht>=300", 5: "mtmin>=120", 6: "HL" }
mainCutCountErr = { }
totalWZ = 0.0

cutCounts = {}
for line in lines:
    if("WZ" in line and ("_" not in line)): totalWZ = float(line.split()[1])
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

# move HT pair to end
indexOfHtPair = [i for i in range(len(cutCountsPairs)) if "ht" in cutCountsPairs[i][0][0]][0]
cutCountsPairs += [cutCountsPairs.pop(indexOfHtPair)]

print "- | Events | WZ Count | WZ Purity | WZ Above Threshold | $\\delta $WZ/WZ"
print ""
for i,pair in enumerate(cutCountsPairs):
    elem1, elem2 = pair
    cutName1 = elem1[0].split(":")[-1]
    cutName2 = elem2[0].split(":")[-1]

    # 0 cut
    # 1 counts total
    # 2 err total
    # 3 counts WZ
    # 4 err WZ
    # 5 purity WZ


    # want elem1 to be the lower one
    if(">" in cutName1 or "HL" in cutName1):
    # if(elem2[1] > elem1[1]):
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

    errStat = math.sqrt(WZ2)
    errStatSyst = math.sqrt( dT2**2.0 + dNonWZ2**2.0 )
    errSyst = math.sqrt(errStatSyst**2 - errStat**2)

    # print errStatSyst, WZ2, pair
    relErrorWZ = errStatSyst / WZ2

    # print cutName1, cutName2
    if( cutName2.startswith("njets") )  : mainCutCountErr[1] = [WZ1, WZ2, relErrorWZ]
    if( cutName2.startswith("nbtags") ) : mainCutCountErr[2] = [WZ1, WZ2, relErrorWZ]
    if( cutName2.startswith("met") )    : mainCutCountErr[3] = [WZ1, WZ2, relErrorWZ]
    if( cutName2.startswith("ht") )     : mainCutCountErr[4] = [WZ1, WZ2, relErrorWZ]
    if( cutName2.startswith("mtmin") )  : mainCutCountErr[5] = [WZ1, WZ2, relErrorWZ]
    if( cutName2.startswith("HL") )     : mainCutCountErr[6] = [WZ1, WZ2, relErrorWZ]

    if( "ht" in cutName2 ): print ""

    cutName1 = latexNames(cutName1)
    cutName2 = latexNames(cutName2)
    print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | multirow 2 $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | multirow 2 %.2f " \
            % (cutName1, elem1[1], dT1, elem1[3], elem1[5], WZ2, errStat, errSyst, relErrorWZ)
    print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ " % (cutName2, elem2[1], dT2, elem2[3], elem2[5])


srYieldsHH = open("srYieldsHHtable.txt","w")
srYieldsHL = open("srYieldsHLtable.txt","w")

yieldsContent = open("yields.tex","r").read()
yieldsFile = open("yieldsFilled.tex","w")

srStrings = ["SR1A","SR2A","SR3Aa","SR3Ab","SR4A","SR5A","SR6A","SR7A","SR8A","SR9A","SR10A","SR11Aa","SR11Ab","SR12A","SR13A","SR14A","SR15A","SR16A","SR1B","SR2B","SR3B","SR4B","SR5B","SR6B","SR7B","SR8B","SR9B","SR10B","SR11B","SR12B"]
for srString in srStrings:
    if(srString == "SR1A"): continue

    finalWZ, finalRelErr = SRerrors(SRtoCuts(srString),totalWZ)
    srYieldsHH.write( "%s | %.3f | %.2f \n" % (srString, finalWZ, finalRelErr) )
    yieldsContent = yieldsContent.replace(srString,str(round(finalRelErr,2)))


# print yieldsContent
yieldsFile.write(yieldsContent)

yieldsFile.close()
