#!/bin/bash

filename=$1
if [ -z $filename ]; then
  echo "$0: No file specified."
  exit 1
fi

extension=${filename##*.}
pnmfile=${filename%.*}.pnm
outfile=${filename%.*}.jpg

echo "Converting: $filename => $outfile"
if [ $extension = jpg ]; then
  exit 0
elif [ $extension = tga ]; then
  tgatopnm $filename > $pnmfile
elif [ $extension = xpm ]; then
  xpmtopnm $filename > $pnmfile
elif [ $extension = pcx ]; then
  pcxtopnm $filename > $pnmfile
elif [ $extension = tif ]; then
  tifftopnm $filename > $pnmfile
elif [ $extension = gif ]; then
  giftopnm $filename > $pnmfile
else
  echo "$0: $filename is an unknown graphics file."
  exit 1
fi

pnmtojpeg $pnmfile > $outfile
rm $pnmfile

