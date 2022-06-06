!#/bin/bash

sudo make clean install || sudo rm config.h && sudo make clean install
sudo mkdir -p /usr/share/xsessions/ || echo "xsessions folder already exist. Skipping...."
sudo cp elh-dwm.desktop /usr/share/xsessions/ || echo "elh-dwm.desktop already exist. Skipping...."
echo "Done."
