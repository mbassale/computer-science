#!/bin/bash

BYTES_IN_MB=1048576
BYTES_IN_KB=1024

for dir in ${*:-.}; do
  if [ -e $dir ]; then
    echo "Evaluating dir: $dir"
    result=$(du -s $dir | cut -f 1)
    let total=$result*1024
    echo -n "Total for $dir = $total bytes"

    if [ $total -ge $BYTES_IN_MB ]; then
      echo " ($((total/$BYTES_IN_MB)) Mb)"
    elif [ $total -ge $BYTES_IN_KB ]; then
      echo " ($((total/$BYTES_IN_KB)) Kb)"
    fi
  fi
done
