#!/bin/bash
if test $# -eq 0
then
    dir = .
else
    dir = $1
fi
find $dir -name "[ab]*" | grep -v ~