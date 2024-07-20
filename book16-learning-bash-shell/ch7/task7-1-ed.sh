#!/bin/bash

ed $1 << EOF
1,/^[ ]*$/d
w
q
EOF

