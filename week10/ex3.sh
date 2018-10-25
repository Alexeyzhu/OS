#!/usr/bin/env bash
echo "I'm _ex3.txt" > _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod u=rwx,o=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 660 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 775 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 777 _ex3.txt
ls -l _ex3.txt >> ex3.txt
rm _ex3.txt


