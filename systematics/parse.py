import math, os, sys


def divErrors(a,b,da,db):
    # return error on a/b
    return a/b,(1.0*a/b)*math.sqrt( (da/a)**2.0 + (db/b)**2.0 )

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
    srcode, srtype, srtype2 = srcode.replace("SR",""), "", ""

    if( "A" in srcode ): srcode, srtype = srcode.replace("A",""), "A"
    else: srcode, srtype = srcode.replace("B",""), "B"

    if( "a" in srcode ): srcode, srtype2 = srcode.replace("a",""), "a"
    elif( "b" in srcode ): srcode, srtype2 = srcode.replace("b",""), "b"
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

    if( srtype == "A" ):
        if( srnum in [9,10,12,13,14,15,16] ): cuts.append(2)
        if( srnum in [4,6,12,14] ): cuts.append(1)
        if( srnum in [5,6,8,13,14,16] ): cuts.append(3)
        if( srnum in [7,8,15,16] ): cuts.append(5)
        if( srnum in [2,4,5,6,7,10,12,13,14,15] ): cuts.append(4)
        if( srnum in [1,3,11] ): cuts.append(-4)

        if( srnum == 3 ):
            if( srtype2 == "a"): cuts += [3]
            if( srtype2 == "b"): cuts += [5]
        if( srnum == 11 ):
            if( srtype2 == "a"): cuts += [2,3]
            if( srtype2 == "b"): cuts += [2,5]
            
    else:
        cuts.append(6)
        if( srnum in [7,8,9,10,11,12] ): cuts.append(2)
        if( srnum in [4,6,10,12] ): cuts.append(1)
        if( srnum in [3,5,6,9,11,12] ): cuts.append(3)
        if( srnum in [2,4,5,6,8,10,11,12] ): cuts.append(4)
        if( srnum in [1,3,7,9] ): cuts.append(-4)

    return cuts

def SRerrors(cuts):
    finalWZ = totalWZ
    final = total
    finalErrSq = 0.0
    for cut in cuts:
        T1, T2, WZ1, WZ2, relErrorWZ = mainCutCountErr[cut]
        finalErrSq += relErrorWZ**2
        finalWZ *= WZ2/WZ1
        final *= T2/T1

    finalErrSq += (scaleFactorError/scaleFactor)**2
    finalRelErr = math.sqrt(finalErrSq)
    return final, finalWZ, finalRelErr



def cutsToStr(cuts):
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

cutCounts = {}
for line in lines:
    # if("WZ" in line and ("_" not in line)): totalWZ = float(line.split()[1])
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

    # 0 cut
    # 1 counts total
    # 2 err total
    # 3 counts WZ
    # 4 err WZ
    # 5 purity WZ

    cutCountsList.append( [cut, cAndE[0], cAndE[1], cAndEWZ[0], cAndEWZ[1], purity(cutCounts[cut])] )

cutCountsList.sort()

cutCountsPairs = zip(cutCountsList[0::2],cutCountsList[1::2])

# move H_T pair to end
indexOfHtPair = [i for i in range(len(cutCountsPairs)) if "ht" in cutCountsPairs[i][0][0]][0]
cutCountsPairs += [cutCountsPairs.pop(indexOfHtPair)]

indexOfHHPair = [i for i in range(len(cutCountsPairs)) if "HH" in cutCountsPairs[i][0][0]][0]
total, totalWZ = cutCountsPairs[indexOfHHPair][0][1], cutCountsPairs[indexOfHHPair][0][3]

# compute scale factor after background subtraction
w,t = totalWZ, total
b = t-w
dw, dt, db = math.sqrt(w), math.sqrt(t), 0.3*b
s = (t-b)/w
scaleFactor,scaleFactorError = s,s*math.sqrt( (dw/w)**2 + (dt/w)**2 + (db/w)**2 )
# print "%.2f \\pm %.2f" % (scaleFactor, scaleFactorError)

# scaleFactor, scaleFactorError = 1.00, 0.00

print "\\textbf{Unscaled} | Events | WZ Count | WZ Purity | WZ Above Threshold | $\\delta $WZ/WZ"
# print "\\textbf{SF}: $%.2f \\pm %.2f$ | Events | WZ Count | WZ Purity | WZ Above Threshold | $\\delta $WZ/WZ" % (scaleFactor,scaleFactorError)
# print " - | Events | WZ Count | WZ Purity | WZ Above Threshold | $\\delta $WZ/WZ" 
print ""
for i,pair in enumerate(cutCountsPairs):
    elem1, elem2 = pair
    cutName1 = elem1[0].split(":")[-1]
    cutName2 = elem2[0].split(":")[-1]


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

    errStat2 = math.sqrt(WZ2)
    errStatSyst2 = math.sqrt( dT2**2.0 + dNonWZ2**2.0 )
    errSyst2 = math.sqrt(errStatSyst2**2 - errStat2**2)

    relErrorWZ2 = errStatSyst2 / WZ2

    errStat1 = math.sqrt(WZ1)
    errStatSyst1 = math.sqrt( dT1**2.0 + dNonWZ1**2.0 )
    errSyst1 = math.sqrt(errStatSyst1**2 - errStat1**2)
    relErrorWZ1 = errStatSyst1 / WZ1

    if( cutName2.startswith("njets") ) : mainCutCountErr[1]  = [T1, T2, WZ1, WZ2, relErrorWZ2]
    if( cutName2.startswith("nbtags") ): mainCutCountErr[2]  = [T1, T2, WZ1, WZ2, relErrorWZ2]
    if( cutName2.startswith("met") )   : mainCutCountErr[3]  = [T1, T2, WZ1, WZ2, relErrorWZ2]
    if( cutName2.startswith("mtmin") ) : mainCutCountErr[5]  = [T1, T2, WZ1, WZ2, relErrorWZ2]
    if( cutName2.startswith("HL") )    : mainCutCountErr[6]  = [T1, T2, WZ1, WZ2, relErrorWZ2]

    if( cutName2.startswith("ht") )    : mainCutCountErr[-4] = [T1+T2, T1, WZ1+WZ2, WZ1, relErrorWZ1]
    if( cutName2.startswith("ht") )    : mainCutCountErr[4]  = [T1+T2, T2, WZ1+WZ2, WZ2, relErrorWZ2]

    cutName1 = latexNames(cutName1)
    cutName2 = latexNames(cutName2)

    if( i == len(cutCountsPairs)-1 ):
        print ""

        print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | %.2f " \
                % (cutName1, elem1[1], dT1, elem1[3], elem1[5], WZ1, errStat1, errSyst1, relErrorWZ1)
        print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | %.2f " \
                % (cutName2, elem2[1], dT2, elem2[3], elem2[5], WZ2, errStat2, errSyst2, relErrorWZ2)
    else:
        # print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | multirow 2 $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | multirow 2 %.2f " \
        #         % (cutName1, elem1[1], dT1, elem1[3], elem1[5], WZ2, errStat2, errSyst2, relErrorWZ2)
        # print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ " % (cutName2, elem2[1], dT2, elem2[3], elem2[5])

        print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | %.2f " \
                % (cutName1, elem1[1], dT1, elem1[3], elem1[5], WZ2, errStat2, errSyst2, relErrorWZ2)
        print "$%-35s$ | $ %.2f \\pm %.2f $ |$ %.2f $ | $ %.1f \\%% $ | $ %.2f\\pm %.2f~\\mathrm{(stat)}\\pm %.2f~\\mathrm{(sys)} $ | %.2f " \
                % (cutName2, elem2[1], dT2, elem2[3], elem2[5], WZ2, errStat2, errSyst2, relErrorWZ2)

# read in SS SR yields
srCodes = {}
lines = open("sryields.txt","r").readlines()
for line in lines:
    if("_" not in line): continue
    line = line.strip()
    srCode = line.split()[0].split("_")[0]
    sample = line.split()[0].split("_")[1]
    count = float(line.split()[1])

    if(srCode not in srCodes):
        srCodes[srCode] = [ count, 0.0 ]
    else: 
        srCodes[srCode][0] += count

    if(sample == "WZ"): srCodes[srCode][1] += count


srStrings = ["SR1A","SR2A","SR3Aa","SR3Ab","SR4A","SR5A","SR6A","SR7A","SR8A","SR9A","SR10A","SR11Aa","SR11Ab","SR12A","SR13A","SR14A","SR15A","SR16A","SR1B","SR2B","SR3B","SR4B","SR5B","SR6B","SR7B","SR8B","SR9B","SR10B","SR11B","SR12B"]

# relative errors
yieldsContent1 = open("yields.tex","r").read()
yieldsContent2 = yieldsContent1[:]
yieldsContent3 = yieldsContent1[:]
yieldsContent4 = yieldsContent1[:]

yieldsFile1 = open("yieldsFilled1.tex","w")
yieldsFile2 = open("yieldsFilled2.tex","w")
yieldsFile3 = open("yieldsFilled3.tex","w")
yieldsFile4 = open("yieldsFilled4.tex","w")

yieldsContent1 = yieldsContent1.replace("TITLEHH", "$\\delta$WZ/WZ for \\textbf{HighHigh}")
yieldsContent1 = yieldsContent1.replace("TITLEHL", "$\\delta$WZ/WZ for \\textbf{HighLow}")

yieldsContent2 = yieldsContent2.replace("TITLEHH", "Total (WZ) for \\textbf{HighHigh}")
yieldsContent2 = yieldsContent2.replace("TITLEHL", "Total (WZ) for \\textbf{HighLow}")

yieldsContent3 = yieldsContent3.replace("TITLEHH", "\\textbf{Total} (WZ) for \\textbf{HighHigh}")
yieldsContent3 = yieldsContent3.replace("TITLEHL", "\\textbf{Total} (WZ) for \\textbf{HighLow}")
yieldsContent3 = yieldsContent3.replace(" 30}", " 50}")

yieldsContent4 = yieldsContent4.replace("TITLEHH", "SS \\textbf{WZ} for \\textbf{HighHigh}")
yieldsContent4 = yieldsContent4.replace("TITLEHL", "SS \\textbf{WZ} for \\textbf{HighLow}")
yieldsContent4 = yieldsContent4.replace(" 30}", " 50}")

for srString in srStrings:
    finalT, finalWZ, finalRelErr = SRerrors(SRtoCuts(srString))
    total, WZ = srCodes[srString]

    yieldsContent1 = yieldsContent1.replace( srString, "\\textbf{%.2f} (%s)" % ( finalRelErr, srString ) )
    yieldsContent2 = yieldsContent2.replace( srString, "\\textbf{%.2f} (%.2f)" % ( finalT, scaleFactor*finalWZ) )
    yieldsContent3 = yieldsContent3.replace( srString, "\\textbf{%.2f} (%.2f)" % ( total, WZ ) )
    yieldsContent4 = yieldsContent4.replace( srString, "%.2f \\pm~%.2f" % ( WZ, finalRelErr*WZ ) )

yieldsFile1.write(yieldsContent1)
yieldsFile1.close()
yieldsFile2.write(yieldsContent2)
yieldsFile2.close()
yieldsFile3.write(yieldsContent3)
yieldsFile3.close()
yieldsFile4.write(yieldsContent4)
yieldsFile4.close()


