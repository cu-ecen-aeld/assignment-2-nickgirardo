#!/usr/bin/env sh


if [ "$#" -ne 2 ]; then
    echo "Usage: $0 writefile writestr" >&2
    exit 1
fi

mkdir -p $(dirname $1)
echo $2 > $1
