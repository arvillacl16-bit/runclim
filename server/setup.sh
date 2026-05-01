sudo apt update
sudo apt install -y \
    software-properties-common

sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt update
sudo apt install -y \
    python3.9 \
    python3.9-venv \
    python3.9-dev \
    gfortran \
    g++ \
    make \
    openmpi-bin \
    libopenmpi-dev \
    libnetcdf-dev \
    python3-pip \
    netcdf-bin

python3.9 -m venv .venv
source .venv/bin/activate
pip install exoplasim
