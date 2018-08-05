#!/bin/bash
find '(' -name CMakeFiles -or -name CMakeCache.txt -or -name build ')' -exec rm -rf  {} \; -quit
