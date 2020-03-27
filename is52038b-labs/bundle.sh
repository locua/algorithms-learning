#!/bin/sh

# I'm not proud of this

set -e

DESTDIR=${HOME}/Goldsmiths/is52038b-labs/

rsync -avh $(git ls-files . | grep -v /) ${DESTDIR}

for subdir in "$@"
do
    rsync -avhR $(git ls-files "${subdir}") ${DESTDIR}
done

cd ${DESTDIR}

git add .

if [ $# -gt 0 ]
then
    git commit -m "updates to $*"
else
    git commit -m "updates to generic infrastructure"
fi
