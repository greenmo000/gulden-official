#Gulden#

###About###
Gulden is a simple and very powerful payment system. Gulden uses blockchain technology to improve financial systems, speed up transactions and offer a cost-effective solution to all things finance. Our software is open source, meaning you can implement Gulden in your own software and build tools and services that help accomplish our goal; creating a stable and blockchain-based financial system built on a trustless and permissionless network that connects with all our financial needs.

###Community###

Connect with the community through one or more of the following:

|Website:|https://gulden.com|
|:-----------|:-------|
|Slack:|https://guldenpay.slack.com/|
|Twitter:|http://twitter.com/gulden|
|Facebook:|http://facebook.com/guldenpay|
|IRC:|https://webchat.freenode.net/?channels=Gulden|


###Building###
First, reconsider whether it is actually necessary for you to build. Linux binaries are provided by us (for UI as well as the daemon) and are sufficient for most cases.
A lot of headaches can be saved by simply using these, especially if you are not an experienced developer.

Gulden is autotools based, to build Gulden from this repository please follow these steps:
* ./autogen.sh
* automake
* ./configure
* make

Prerequisites:
> &gt;=g++-4.8 pkg-config autoconf libtool automake gperf bison flex

Required dependencies:
> bdb-4.8.30 boost-1_61_0 expat-2.1.1 openssl-1.0.1k miniupnpc-2.0 protobuf-2.6.1 zeromq-4.1.4

Optional dependencies (depending on configure - e.g. qt only for GUI builds):
> dbus-1.8.6 fontconfig-2.11.1 freetype-2.6.3 icu-58.1 libevent-2.0.22 libX11-1.6.2 libXau-1.0.8 libxcb-1.10 libXext-1.3.2 libXrender-0.9.10  qrencode-3.4.4 qt-5.6.1 renderproto-0.11 xcb_proto-1.10 xextproto-7.3.0 xproto-7.0.26 xtrans-1.3.4


Troubleshooting:

For older distributions with outdated autotools the above process may fail, a source tarball is available for these distributions.
* https://github.com/Gulden/gulden-binaries/raw/master/Gulden-1.6.1.tar.gz
To build from source tarball follow these steps:
* tar -zxvf Gulden-1.6.1.tar.gz
* cd Gulden-1.6.1
* ./configure
* make

If your distro (e.g. Ubuntu 14.04) does not have boost 1.61 you can do the following to build it
> wget https://sourceforge.net/projects/boost/files/boost/1.61.0/boost_1_61_0.tar.bz2 && tar -xvf boost_1_61_0.tar.bz2 && cd boost_1_61_0/ && ./bootstrap.sh && ./b2 --prefix=/boost166 cxxflags=-fPIC cflags=-fPIC install

And then add it to your configure flags
> ./configure --with-boost=/boost166 ...

To run after doing the above
> LD_LIBRARY_PATH=/boost166/lib src/GuldenD ...

If your distro is missing Berkley DB 4.8 (error: Found Berkeley DB other than 4.8, required for portable wallets)
Either configure with an incompatible bdb (Your wallet may not be portable to machines using older versions in this case):
> ./configure --with-incompatible-bdb ...
Or compile your own:
> mkdir /db-4.8 wget 'http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz' && tar -xzvf db-4.8.30.NC.tar.gz && cd db-4.8.30.NC/build_unix/ && ../dist/configure --enable-cxx --disable-shared --with-pic --prefix=/db-4.8/ && make install

> ./configure LDFLAGS="-L/db-4.8/lib/" CPPFLAGS="-I/db-4.8/include"

Binaries are output as follows by the build process:

|Binary|Location|
|:-----------|:---------|
|Qt wallet|src/qt/Gulden|
|Gulden Daemon/RPC server|src/GuldenD|
|Gulden RPC client|src/Gulden-cli|
|Gulden tx utility|src/Gulden-tx|

Alternatively binaries are also available https://developer.gulden.com/apps/


###Additional technical information###


|Technical specifications - Main network||
|:-----------|:---------|
|Algorithm:|Scrypt proof of work, with DELTA difficulty adjustment|
|Transaction confirmations:|6|
|Total coins:|1680M|
|Premine reserved for development, marketing and funding of community projects:|170M (10%)|
|Starting diff:|0.00244|
|Block reward:|100 NLG|
|Block time:|150 seconds|
|P2P Port|9231|
|RPC Port|9232|
|P2P Network Header|fcfef7e0|
|Address version byte|38|
|BIP44 coin type|87 0x80000057|

|Technical specifications - Testnet||
|:-----------|:---------|
|P2P Port|9923|
|RPC Port|9924|
|P2P Network Header|fcfef700|
|Address version byte|98|

|Infrastructure||
|:-----------|:---------|
|Official block explorer|blockchain.gulden.com|
|Community block explorer|guldenchain.com|
|Electrum server 1|electrum1.gulden.com:5038|
|Electrum server 2|electrum2.gulden.com:5038|
|DNS Seed 1|seed.gulden.com|
|DNS Seed 2|amsterdam.gulden.com|
|DNS Seed 3|seed.gulden.network|
|DNS Seed 4|rotterdam.gulden.network|
|DNS Seed 5|seed.gulden.blue|
|Seed node 1|seed-000.gulden.com|
|Seed node 2|seed-001.gulden.blue|
|Seed node 3|seed-002.gulden.network|
|Seed node 4|seed-003.gulden.com|
|Seed node 5|seed-004.gulden.blue|
|Seed node 6|seed-005.gulden.network|
|Testnet DNS Seed 1|testseed.gulden.blue|
|Testnet DNS Seed 2|testseed.gulden.network|
|Testnet Seed node 1|testseed-00.gulden.blue|
|Testnet Seed node 2|testseed-01.gulden.network|
