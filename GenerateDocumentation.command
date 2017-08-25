echo "Generate Pcf Documentation version 0.3.0, copyright GAMMA Soft, 2017"
echo ""

echo "Generate documentations..."
cd ~/Projects/Pcf/bin
rm -r ~/Projects/Pcf/bin/Help
xcodebuild -target documentation -configuration Debug
