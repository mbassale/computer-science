#!/bin/bash

for ((;;))
do
  read var
  if [ "$var" = "." ]; then
    break
  fi
done
