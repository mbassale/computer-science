#!/bin/bash

makecmd()
{
  read target colon sources
  for src in $sources; do
    echo "$src"
    if [ $src -nt $target ]; then
      while read cmd ; do
        echo "$cmd"
        eval ${cmd#\t}
      done
      break
    fi
  done
}


