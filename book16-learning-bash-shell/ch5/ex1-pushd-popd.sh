#!/bin/bash

cd()
{
  builtin cd "$@"
  retval=$?
  echo "$OLDPWD --> $PWD"
  return $retval
}

pushd()
{
  dirname=$1
  if [ -n "$dirname" ] && [ \( -d "$dirname" \) -a \( -x "$dirname" \) ]; then
    DIR_STACK="$dirname ${DIR_STACK:-"$PWD "}"
    cd "$dirname"
    echo "$DIR_STACK"
  else
    echo "still in $PWD"
  fi
}

popd()
{
  if [ -n "$DIR_STACK" ]; then
    DIR_STACK=${DIR_STACK#* }
    cd ${DIR_STACK%% *}
    echo "$PWD"
  else
    echo "stack empty, still in $PWD."
  fi
}

export DIR_STACK

