#!/usr/bin/env sh


if [ "$#" -ne 2 ]; then
    echo "Usage: $0 filesdir searchstring" >&2
    exit 1
fi

filesdir=$1
searchstring=$2

if [ ! -d "$filesdir" ]; then
    echo "No directory found: $1" >&2
    exit 1
fi

# `grep` here prints each matching line
#   `-F` treats the searchstring as a plain string (rather than regex)
#   `-r` executes it recursively over each file in filesdir and it's sub directories
# `wc -l` counts the number of lines output by grep
matchinglines=$(grep -Fr $searchstring $filesdir | wc -l)

# `find` here prints a line for each file (`type -f`)
filessearched=$(find $filesdir -type f | wc -l)

echo "The number of files are $filessearched and the number of matching lines are $matchinglines"
