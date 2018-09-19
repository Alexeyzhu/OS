#!/bin/bash
counter=0
while [ $counter -lt 100 ]
do
    counter=$(( $counter + 1 ))
	num=$( tail -n 1 numbers.txt )
	echo "$((num +1))" >> numbers.txt
done
