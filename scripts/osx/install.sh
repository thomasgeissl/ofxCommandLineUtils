#!/bin/sh

curl -O https://openframeworks.cc/versions/v0.10.1/of_v0.10.1_osx_release.zip
unzip -a -qq of_v0.10.1_osx_release.zip
rm of_v0.10.1_osx_release.zip
cd of_v0.10.1_osx_release/addons

git clone https://github.com/thomasgeissl/ofxCommandLineUtils.git
cd ofxCommandLineUtils

for d in example*/ ; do
    echo "$d"
    cd $d
    make
    cd ..
done