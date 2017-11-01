echo "Generate and publish Switch Documentation, copyright GAMMA Soft, 2017"
echo ""

echo "Generating documentation..."
cd ~/Projects/Switch/build
rm -r ~/Projects/Switch/build/Help
xcodebuild -target documentation -configuration Debug

echo "Publishing documentation..."
cd ~/Projects/Switch-Doc
git pull
rm -r ~/Projects/Switch-Doc/docs
cp -R ~/Projects/Switch/build/Help/html/. ~/Projects/Switch-Doc/docs
git add --all
git commit -m "add documentation"
git push
