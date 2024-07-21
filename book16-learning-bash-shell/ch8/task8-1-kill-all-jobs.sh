#!/bin/bash

job_pids=()
for ((i=0; i < 10; i++)); do
  printf "Launching job $i: PID="
  sleep 120 &
  job_pid=$!
  job_pids[$i]=$job_pid
  printf "%d\n" ${job_pids[$i]}
done

kill $(jobs -p)
