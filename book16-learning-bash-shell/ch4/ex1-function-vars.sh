#!/bin/bash

func1() {
  IFS=,
  echo '$*: ' "$*"
  echo '$@: ' $@
  echo '$0: ' $0
  echo '$1: ' $1
  echo '$2: ' $2
  second_arg=$1

  local third_arg=$2
}

func1 'uno' 'due' 'tre'
echo 'second_arg: ' $second_arg
echo 'third_arg: ' $third_arg
