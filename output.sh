#!/bin/bash

str=""
for (( i=0; $i<${#1}; i=$(($i+1)) ))
do
  str=${str}${1:$i:1};
  echo -en "$3${1:$i:1}\033[m";
  sleep $2;
  echo -en "\b$4${1:$i:1}\033[m";
done
