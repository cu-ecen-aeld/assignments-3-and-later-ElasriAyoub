#/bin/sh

set -e
set -u

if [ "$#" -ne 2 ]; then
    echo "Failed : Two arguments required"
    exit 1
else
    echo "Passed : Two arguments verified"   
fi

writefile=$1
writestr=$2
writedir=$(dirname "$writefile")

if [ ! -d "$writedir" ]; then
    mkdir -p "$writedir"
    if [ "$?" -ne 0 ]; then
        echo "Error: Could not create directory '$writedir'."
        exit 1
    else
        echo "Passed : Directory created"  
    fi
else
    echo "Passed : Directory exists"  
fi 

echo "$writestr" > "$writefile"
if [ "$?" -ne 0 ]; then
    echo "Error: Could not write to file '$writefile'."
    exit 1
else
    echo "Passed : Successfully wrote to '$writefile'." 
    exit 0
fi