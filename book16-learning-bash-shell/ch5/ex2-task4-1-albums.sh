#!/bin/bash
# sorts the file lines in reverse order

if [ -z "$1" ]; then
  echo "usage: $0 filename [-N]"
  exit 1
fi

header="-h"
filename=${1:?"missing filename"}
number_lines=${2:--10}

echo -e -n ${header:+"Albums Artist\n"}
sort -nr $filename | head ${number_lines}
