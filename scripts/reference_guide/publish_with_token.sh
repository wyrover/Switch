#!/usr/bin/env sh

# Publishing documentation
cd build/ReferenceGuide

# setup git
git config --global user.email "travis@travis-ci.org"
git config --global user.name "Travis CI"

git add --all
git commit -m "Generate Reference Guide:  $TRAVIS_BUILD_NUMBER"

git remote add origin-pages https://${GITHUB_TOKEN}@github.com/gammasoft71/switch-doc.git > /dev/null 2>&1
git push --quiet --set-upstream origin-pages gh-pages
