#!/bin/bash

trap "echo 'You hit control-C!'" INT

while true; do
  sleep 60
done

