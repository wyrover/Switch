#!/usr/bin/env sh

# generate and send coverage report to Codecov
export CODECOV_TOKEN="6f14306e-b89d-4ee1-a370-4549f15a14b6"
bash <(curl -s https://codecov.io/bash)
