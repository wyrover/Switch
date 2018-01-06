#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                                                git check
if [[ -n $(git diff --check HEAD^) ]]; then
  echo "You must remove whitespace before submitting a pull request"
  echo ""
  git diff --check HEAD^
  exit -1
fi
