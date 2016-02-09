#include "crt.bi"
#include "file.bi"
#include "Station.bas"
#include "Stations.bas"

dim as w2.Station mySt = "Stations.dat"

dim as integer argc = __FB_ARGC__
dim as zstring ptr ptr argv = __FB_ARGV__

printf(!"\nCommand Line : ")
for i as integer = 0 to argc-1
    printf(!"%s ",argv[i])
next i
printf(!"\n")

sleep