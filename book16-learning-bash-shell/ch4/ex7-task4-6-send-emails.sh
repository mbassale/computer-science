#!/bin/bash

mail $(who | cut -d' ' -f1)

