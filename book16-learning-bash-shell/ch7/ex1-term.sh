#!/bin/bash

{
  TERM=vt100
  line='tty01'
  while read dev termtype; do
    if [ -z "$(echo $dev | grep ^#)" ] && [ "$dev" = "$line" ]; then
      TERM=$termtype
      echo "TERM set to $TERM."
      break 
    fi
    done
} < ./ex1-data.txt
