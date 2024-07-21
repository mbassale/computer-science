#!/bin/bash

cleanup() {
  if [ -e $msgfile ]; then
    mv $msgfile dead.letter
  fi
  exit
}

trap cleanup INT TERM

msgfile=/tmp/msg$$
cat > $msgfile
echo "Sending..."
cat $msgfile
echo "Sent."
rm $msgfile

