import math

def multDivErrors(a,b,da,db):
    # return error on a*b or a/b
    return 1.0*math.sqrt( (da/a)**2.0 + (db/b)**2.0 )

def convertNames(cutName):
    cutName = cutName.replace(">=","\\geq ")
    cutName = cutName.replace("<=","\\leq ")
    cutName = cutName.replace("ht","H_\\mathrm{T}")
    cutName = cutName.replace("mtmin","m^\\mathrm{T}_\\mathrm{min}")
    cutName = cutName.replace("njets","\\mathrm{Njets}")
    cutName = cutName.replace("met","\\mathrm{ME_T}")
    cutName = cutName.replace("HH","\\mathrm{HH}")
    cutName = cutName.replace("HL","\\mathrm{HL}")
    cutName = cutName.replace("nbtags","\\mathrm{Nbtags}")
    return cutName

def countsAndErrors(sampleCounts):
    tot = 0.0
    totErr = 0.0

    # for sampleCount in sampleCounts:
    #     sample, count = sampleCount
    #     tot += count
    # print sampleCounts
    tot = sampleCounts["WZ"][0]
    # tot = sampleCounts["WZ"] + \
          # sampleCounts["DY"] + \
          # sampleCounts["TTW"] + \
          # sampleCounts["TTZ"] + \
          # sampleCounts["WJets"] + \
          # sampleCounts["TTBAR"] + \
          # sampleCounts["ZZ"] 
    totErr = sampleCounts["WZ"][1]
    # print tot

    return round(tot,2),round(totErr,2)


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
        # cutCounts[cut].append( [sample,float(count)] )
    else: 
        # cutCounts[cut].append( [sample,float(count)] )
        cutCounts[cut][sample] = [ float(count), float(error) ]



for cut in cutCounts.keys():
    # print cut, cutCounts[cut], countsAndErrors(cutCounts[cut])
    # print cut, countsAndErrors(cutCounts[cut])
    cAndE = countsAndErrors(cutCounts[cut])
    print "$%s$ | %.2f | %.2f" % (convertNames(cut), cAndE[0], cAndE[1])
    # print cut, countsAndErrors(cutCounts[cut])

