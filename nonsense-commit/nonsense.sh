#!/bin/sh

echo "good" >> test.txt
git add test.txt
git commit -m "nonsense" --date='2016-02-09 23:59:59'

echo "good" >> test.txt
git add test.txt
git commit -m "nonsense" --date='2016-02-10 23:59:59'

