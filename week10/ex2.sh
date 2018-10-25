#!/usr/bin/env bash
echo "I'm file.txt in week1" > ~/CLionProjects/OS/week1/file.txt
link ~/CLionProjects/OS/week1/file.txt _ex2.txt
a=$(ls -i ~/CLionProjects/OS/week1/file.txt | grep -o '[0-9]* ')
find ~/CLionProjects/OS/ -inum $a > ex2.txt
find ~/CLionProjects/OS/ -inum $a -exec rm {} \; >> ex2.txt