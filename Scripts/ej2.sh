#!/bin/bash
routes=$(echo $PATH | tr ":"" ")
for i in routes
do
    if test -e $i/$1
    then
        echo $i/$1
        exit 
    fi
done
echo "No se encontro" $1