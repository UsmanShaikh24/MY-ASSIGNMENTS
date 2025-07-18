#!/bin/bash
if (( $1 > $2 && $1 > $3 )); then
    echo "$1 is the biggest"
elif (( $2 > $3 )); then
    echo "$2 is the biggest"
else
    echo "$3 is the biggest"
fi
