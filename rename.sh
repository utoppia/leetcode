#!/bin/bash

IFS=$'\t\n'

for f in `ls *.py`
do
    echo "$f"
    new_string=$(echo "$f" | sed -r 's/_/-/g')
    echo "$new_string"
    git mv $f $new_string
done
