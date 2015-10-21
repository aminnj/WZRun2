import math

fh = open("counter.txt","r")
lines = fh.readlines()
fh.close()


# DY 0.264807 0.700612
# TTBAR 0.124506 0.088039
# TTZ 0.530238 0.0386037
# WZ 8.5534 0.13467
# ZZ 0.933068 0.0144527
# Data 8.0 2.3

nonWZcounts = []
nonWZerrors = []
WZcount, WZerr = 0.0,0.0
datacount, dataerr = 0.0, 0.0

for line in lines:
    line = line.strip()
    if(len(line) < 2): continue
    if("_" in line): continue

    # print line
    sample, count, err = line.split()
    count, err = float(count), float(err)
    print sample, count, err


    if(sample in ["DY", "TTBAR", "TTZ", "ZZ"]):
        nonWZcounts.append(count)
        nonWZerrors.append(err)
    elif(sample in ["WZ"]):
        WZcount = count
        WZerr = err
    elif(sample in ["Data"]):
        datacount = count
        dataerr = err

# print nonWZcounts, nonWZerrors
nonWZcount = sum(nonWZcounts)
nonWZerr = math.sqrt(sum(map(lambda x: x**2.0, nonWZerrors)) + (1.0*nonWZcount)**2)
# print nonWZcount, nonWZerr
# print WZcount, WZerr
# print datacount, dataerr

print
print "DATA"
print "data = %.2f pm %.2f" % (datacount, dataerr)

print
print "WZ"
print "wz = %.2f pm %.2f" % (WZcount, WZerr)

print
print "NONWZ"
print "non-wz = %.2f pm %.2f" % (nonWZcount, nonWZerr)

print
print "SCALE FACTOR"
sf = (datacount-nonWZcount)/WZcount
sferr = (1.0/WZcount)*math.sqrt(dataerr**2 + nonWZerr**2 + sf**2 * WZerr**2)
print "data/MC = %.3f pm %.3f" % (sf, sferr)

