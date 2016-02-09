#include "file.bi"

dim as string fileName = "test.txt"
dim as integer fileLength
var ff = freefile
if fileExists(fileName) then
    fileLength = fileLen(fileName)
    print fileLength
else
    print "File does not exist!"
end if

sleep