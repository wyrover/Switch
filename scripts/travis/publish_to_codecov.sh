#!/bin/bash

set -ev

# publish to codecov
export CODECOV_TOKEN="6f14306e-b89d-4ee1-a370-4549f15a14b6"
# codecov deactivated if not the job exceeds the maximum time limit.
#bash <(curl -s https://codecov.io/bash) > /dev/null 2>&1
