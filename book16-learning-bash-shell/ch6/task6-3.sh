#!/bin/bash

dump_array() 
{
  values=$1
  sz=${#values[@]}
  for (( i=0; i < sz; i++ )); do
    echo -ne "${values[$i]} "
  done
  echo
}

selection_sort() 
{
  values=$1
  num_values=${#values[@]}

  for (( i=0; i < num_values; i++ )); do
    lowest=$i
    
    for (( j=i; j < num_values; j++ )); do
      if [ ${values[j]} -le ${values[$lowest]} ]; then
        lowest=$j
      fi
    done

    temp=${values[i]}
    values[i]=${values[lowest]}
    values[lowest]=$temp
  done
}

values=(39 5 36 12 9 3 2 30 4 18 22 1 28 25)
dump_array $values
selection_sort $values
dump_array $values
