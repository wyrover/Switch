echo "Generate and publish Pcf Documentation version 0.3.0, copyright GAMMA Soft, 2017"
echo ""

echo "Generate documentation..."
cd ~/Projects/Pcf/bin
rm -r ~/Projects/Pcf/bin/Help
xcodebuild -target documentation -configuration Debug

echo "Publish documentation..."
cd ~/Projects/Pcf-Doc
git pull
rm -r ~/Projects/Pcf-Doc/docs
cp -R ~/Projects/Pcf/bin/Help/html/. ~/Projects/Pcf-Doc/docs
git add --all
git commit -m "add documentation"
git push
