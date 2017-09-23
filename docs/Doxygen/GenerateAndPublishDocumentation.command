echo "Generate and publish Switch Documentation version 0.3.4, copyright GAMMA Soft, 2017"
echo ""

echo "Generate documentation..."
cd ~/Projects/Switch/bin
rm -r ~/Projects/Switch/bin/Help
xcodebuild -target documentation -configuration Debug

echo "Publish documentation..."
cd ~/Projects/Switch-Doc
git pull
rm -r ~/Projects/Switch-Doc/docs
cp -R ~/Projects/Switch/bin/Help/html/. ~/Projects/Switch-Doc/docs
git add --all
git commit -m "add documentation"
git push
