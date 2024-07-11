#!/bin/bash

filename=$1

outfile=${filename%.pcx}.jpg
echo $filename ' => ' $outfile
