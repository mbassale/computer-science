#!/bin/bash

until cp $1 $2; do
  echo 'Attempt to copy failed. waiting...'
  sleep 5
done
