#!/bin/bash
# sorts the file lines in reverse order

header="-h"
filename=${1:?"missing filename"}
number_lines=${2:-10}

echo -e -n ${header:+"Albums Artist\n"}
sort -nr $filename | head -${number_lines}
