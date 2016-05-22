#!/bin/sh

for i in `seq 1 31`
do
     if [ $i -lt 10 ]
     then
         commit_date="2015-10-0$i 23:59:59"
     else
         commit_date="2015-10-$i 23:59:59"
     fi
    echo $commit_date

    echo "good" >> test.txt
    git add test.txt
    git commit -m "nonsense" --date="$commit_date"
done

git pull origin dev
git push origin dev

