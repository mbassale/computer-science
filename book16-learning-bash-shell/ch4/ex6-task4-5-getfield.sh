#!/bin/bash

getfield() {
  field=$1
  case "$field" in 
    "band")
      echo 1
      ;;
    "album")
      echo 2
      ;;
    "record")
      echo 3
      ;;
    "year")
      echo 4
      ;;
    *)
      echo 0
  esac
}

datafile=${1:? 'Error: datafile missing.'}
fieldname=${2:? 'Error: missing field name.'}
field=$(getfield $fieldname)
if [ $field -eq 0 ]; then
  echo "Invalid field, select one of: band, album, record or year."
  exit 1
fi

echo "Reading from $datafile, field: $fieldname, column index: $field"

cut -f$field -d\| $datafile


