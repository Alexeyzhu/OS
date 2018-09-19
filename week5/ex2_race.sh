#!/bin/bash
while true; do
    if ! ln numbers.txt numbers.txt.lock
    then
       sleep 1
    else
        count=0
        while [[ $counter -lt 1000 ]]
        do
            counter=$(( $counter + 1 ))
            num=$( tail -n 1 numbers.txt )
	        echo "$((num +1))" >> numbers.txt
        done
            rm numbers.txt.lock
    fi
done

