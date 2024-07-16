#!/bin/bash

if [ -z $1 ]; then
  echo 'usage: highest -N filename'
  exit 1
elif [ -n "$(echo $1 | grep '^-[0-9][0-9]*$')" ]; then
  howmany=$1
  shift
elif [ -n "$(echo $1 | grep '^-')" ]; then
  echo 'usage: highest -N filename'
  exit 1
else
  howmany="-10"
fi

filename=$1
sort -nr $filename | head $howmany
