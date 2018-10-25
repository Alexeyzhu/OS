#!/usr/bin/env bash
if [ ! -d ~/CLionProjects/OS/week10/tmp ]; then
    mkdir -p ~/CLionProjects/OS/week10/tmp;
    echo "FILE 1" > ~/CLionProjects/OS/week10/tmp/file1.txt
    echo "FILE 2" > ~/CLionProjects/OS/week10/tmp/file2.txt
    ln ~/CLionProjects/OS/week10/tmp/file1.txt ~/CLionProjects/OS/week10/tmp/link1.txt
    ls -i
fi;
