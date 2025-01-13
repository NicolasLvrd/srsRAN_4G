Setup for RCA
======
### First install
```
sudo apt-get update
sudo apt-get install -y build-essential cmake libfftw3-dev libmbedtls-dev libboost-program-options-dev libconfig++-dev libsctp-dev libuhd-dev uhd-host
sudo apt install -y git
sudo git clone https://github.com/NicolasLvrd/srsRAN_4G.git
cd srsRAN_4G
sudo mkdir build
cd build
sudo apt install -y cmake
sudo cmake ../
sudo make
sudo make install
sudo uhd_images_downloader
sudo srsran_install_configs.sh user
```

### Build a new version
```
git pull
cd build
make
sudo make install
```

srsRAN
======

[![Build Status](https://github.com/srsran/srsRAN_4G/actions/workflows/ccpp.yml/badge.svg?branch=master)](https://github.com/srsran/srsRAN_4G/actions/workflows/ccpp.yml)
[![CodeQL](https://github.com/srsran/srsRAN_4G/actions/workflows/codeql.yml/badge.svg?branch=master)](https://github.com/srsran/srsRAN_4G/actions/workflows/codeql.yml)
[![Coverity](https://scan.coverity.com/projects/28268/badge.svg)](https://scan.coverity.com/projects/srsran_4g_agpl)

srsRAN is an open source 4G software radio suite developed by [SRS](http://www.srs.io). For 5G RAN, see our new O-RAN CU/DU solution - [srsRAN Project](https://www.github.com/srsran/srsran_project).

See the [srsRAN 4G project pages](https://www.srsran.com) for information, guides and project news.

The srsRAN suite includes:
  * srsUE - a full-stack SDR 4G UE application with prototype 5G features
  * srsENB - a full-stack SDR 4G eNodeB application
  * srsEPC - a light-weight 4G core network implementation with MME, HSS and S/P-GW

For application features, build instructions and user guides see the [srsRAN 4G documentation](https://docs.srsran.com/projects/4g/).

For license details, see LICENSE file.

Support
=======

Mailing list: https://lists.srsran.com/mailman/listinfo/srsran-users

