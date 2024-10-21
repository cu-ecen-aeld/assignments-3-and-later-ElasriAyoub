#!/bin/sh

set -e
set -u

if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required."
    exit 1
else
    echo "Passed : Two arguments verified"
fi

filesdir=$1
searchstr=$2

if [ -d "$filesdir" ]; then
    echo "Passed : $filesdir est un répertoire."
else
    echo "Error: $filesdir n'est pas un répertoire valide."
    exit 1
fi

number_files=$(find "$filesdir" -type f | wc -l)
number_matches=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $number_files and the number of matching lines are $number_matches"