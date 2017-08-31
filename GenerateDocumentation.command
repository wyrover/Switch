echo "Generate Switch Documentation version 0.3.0, copyright GAMMA Soft, 2017"
echo ""

echo "Generate documentations..."
cd ~/Projects/Switch/bin
rm -r ~/Projects/Switch/bin/Help
xcodebuild -target documentation -configuration Debug
