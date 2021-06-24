# http://gazebosim.org/gzweb.html#install-collapse-0

sudo apt install libjansson-dev libboost-dev imagemagick libtinyxml-dev mercurial cmake build-essential -y

 # install nvm
 curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash

 # source .bashrc so we can use the nvm cmd
 source ~/.bashrc

 # install node. Supported versions are 8 to 11. 
 nvm install 11


# git clone https://github.com/osrf/gzweb
# git checkout gzweb_1.4.1
# source /usr/share/gazebo/setup.sh
# npm run deploy --- -m -t
# npm start

# gzweb color issue
# https://support.yonohub.com/t/gzweb-media-directory-is-missing/144
# copy /usr/share/gazebo-9/media to ~/gzweb/http/client/assets
# cp -r /usr/share/gazebo-9/media/* {your gzweb src path}/gzweb/http/client/assets