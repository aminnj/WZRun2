import math, os, sys

def countsAndErrors(sampleCounts, WZonly=False):
    tot = 0.0

    if(WZonly):
        tot = sampleCounts["WZ"][0]
    else:
        tot = sum([sampleCounts[sample][0] for sample in allsamples])

    return tot


# lines = open("sryields.txt","r").readlines()
lines = open("sryieldsWZselec.txt","r").readlines()
allsamples = ["TTBAR","DY","TTW","TTZ","WJets","WZ","ZZ"] 

srCodes = {}
srStrings = ["SR1A","SR2A","SR3Aa", "SR3Ab","SR4A","SR5A","SR6A","SR7A","SR8A","SR9A","SR10A","SR11Aa", "SR11Ab","SR12A","SR13A","SR14A","SR15A","SR16A","SR1B","SR2B","SR3B","SR4B","SR5B","SR6B","SR7B","SR8B","SR9B","SR10B","SR11B","SR12B"]
for line in lines:
    if("_" not in line): continue
    if("Data" in line): continue
    line = line.strip()
    srCode = line.split()[0].split("_")[0]
    sample = line.split()[0].split("_")[1]
    count = float(line.split()[1])

    if(srCode not in srCodes):
        srCodes[srCode] = [ count, 0.0 ]
    else: 
        srCodes[srCode][0] += count

    if(sample == "WZ"): srCodes[srCode][1] += count

yieldsContent3 = open("yields.tex","r").read()
yieldsFile3 = open("yieldsFilled3.tex","w")
yieldsContent3 = yieldsContent3.replace("TITLEHH", "\\textbf{Total} (WZ) for \\textbf{HighHigh}")
yieldsContent3 = yieldsContent3.replace("TITLEHL", "\\textbf{Total} (WZ) for \\textbf{HighLow}")

for srString in srStrings:
    total, WZ = 0.0, 0.0
    try:
        total += srCodes[srString][0]
        WZ += srCodes[srString][1]
    except:
        print srCode,"empty"

    print srString, total, WZ

    yieldsContent3 = yieldsContent3.replace( srString, "\\textbf{%.2f} (%.2f)" % ( total, WZ ) )

yieldsFile3.write(yieldsContent3)
yieldsFile3.close()
