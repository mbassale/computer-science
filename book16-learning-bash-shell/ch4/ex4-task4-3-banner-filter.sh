#!/bin/bash

pathname=$1

bannername=${pathname##*/}

echo $pathname ' => ' $bannername
