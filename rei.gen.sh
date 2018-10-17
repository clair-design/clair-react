#!/bin/bash
# SEE https://reasonml.chat/t/how-to-automatically-generate-interface-for-all-files/766/3
rm -rf lib/bs/rei
mkdir -p lib/bs/rei

filepath(){
  FILENAME=`echo $(basename $1)  | cut -d'-' -f 1`
  echo "lib/bs/rei/$FILENAME.rei"
}

for i in $(find lib/bs/src -name '*.cmi');do
   bsc -bs-re-out "$(pwd)/$i" > "$(filepath $i)"
done
