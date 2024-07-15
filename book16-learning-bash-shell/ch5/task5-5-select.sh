#!/bin/bash

selectd()
{
  PS3='directory? '
  select selection in $DIR_STACK; do
    if [ $selection ]; then
      echo 'misc statements'
      break
    else
      echo 'invalid selection'
    fi
  done
}

DIR_STACK="/usr /home /bin"
selectd
