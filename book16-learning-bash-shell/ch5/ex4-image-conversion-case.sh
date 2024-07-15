#!/bin/bash

for filename in "$@"; do
  pnmfile=${filename%.*}.pnm

  echo "Converting: $filename"
  case $filename in
    *.jpg ) exit 0 ;;
    *.tga ) tgatopnm $filename > $pnmfile ;;
    *.xpm ) xpmtopnm $filename > $pnmfile ;;
    *.pcx ) pcxtopnm $filename > $pnmfile ;;
    *.tif ) tifftopnm $filename > $pnmfile ;;
    *.gif ) giftopnm $filename > $pnmfile ;;
    * ) echo "$0: $filename is an unknown graphics file."
      exit 1 ;;
  esac

  outfile=${filename%.*}.jpg
  pnmtojpeg $pnmfile > $outfile
  rm $pnmfile
done
