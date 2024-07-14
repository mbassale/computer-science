#!/bin/bash

$tab=""
$singletab="\t"

recls()
{
  tab=$tab$singletab
  for file in "$@"; do
    echo -e $tab$file
    thisfile=$thisfile/$file
    if [ -d "$thisfile" ]; then
      recls $(command ls $thisfile)
    fi

    thisfile=${thisfile%/*}
  done
  tab=${tab%"$singletab"}
}

recls $@
