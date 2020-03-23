#!/bin/sh

curl -O https://openframeworks.cc/versions/v0.10.1/of_v0.10.1_linux64gcc6_release.tar.gz
tar -zxf of_v0.10.1_linux64gcc6_release.tar.gz
rm of_v0.10.1_linux64gcc6_release.tar.gz
sudo of_v0.10.1_linux64gcc6_release/scripts/linux/ubuntu/install_dependencies.sh -y
of_v0.10.1_linux64gcc6_release/addons

git clone https://github.com/thomasgeissl/ofxCommandLineUtils.git
cd ofxCommandLineUtils

for d in example*/ ; do
    echo "$d"
    cd $d
    make
    cd ..
done

