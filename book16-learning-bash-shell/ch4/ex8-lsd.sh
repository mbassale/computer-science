#!/bin/bash

# ls by modified date
function lsd
{
  date=$1
  ls -l | grep -i "^.*$date" | cut -c50-
}
