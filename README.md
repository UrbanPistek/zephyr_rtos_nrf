# Zephyr NRF BLE Project 

## Zephyr Setup 

Follow: 
https://docs.zephyrproject.org/latest/getting_started/index.html

After getting Zephyr and installing Python dependencies once you reached the installing toolchains section, go to: https://docs.zephyrproject.org/latest/getting_started/toolchain_3rd_party_x_compilers.html#gnu-arm-embedded

Going to use the GNU arm embedded toolchain since the NRF is an ARM based SoC.
Install gcc-arm-none-eabi-10-2020-q4-major from the GNU website. 
Extract and copy the files: 
```
tar -xf gcc-arm-none-eabi-10-2020-q4-major-x86_64-linux.tar.bz2
mkdir ~/toolchains
cp -r gcc-arm-none-eabi-10-2020-q4-major ~toolchains 
```

Once you have the toolchain, you can add it to your PATH, by setting the following enviroment variables.

Add to `~/.zshrc` or `~/.bashrc`:
```
export ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb.
export GNUARMEMB_TOOLCHAIN_PATH=~/toolchains/gcc-arm-none-eabi-10-2020-q4-major/
```

## Install J-link and NRF Command Line Tools
From: https://docs.zephyrproject.org/latest/guides/tools/nordic_segger.html#nordic-nrf5x-segger-j-link
Install: 
 - J-Link: https://www.segger.com/jlink-software.html
 - NRF Command Line Tools: https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF-Command-Line-Tools

### Build and flash sample app
For the nrf52833 DK board: 
```
cd /zephyrproject/zephyr/ 
source venv/bin/activate
west build -p auto -b nrf52833dk_nrf52833 samples/basic/blinky
west flash 
```

### Zephyr App Example
https://github.com/zephyrproject-rtos/example-application

## Project Setup 
Note: Depending on the OS, you maybe need to resolve pip depenacy conflicts.
```
python -m venv venv
source venv/bin/activate
pip install west 
west init
west update
pip install -r zephyr/scripts/requirements.txt
```

## Build and Flash App
```
west build -b nrf52833dk_nrf52833 app --pristine
west flash
```

## Troubleshooting
On ubuntu or debian systems, you may need to install: 
```
sudo apt install python3.8-venv
```
In order to create a virtual environment:
```
python -m venv venv
source venv/bin/activate
```

Note: If running conda on your system, ensure the base enviroment is not activated. 
```
CONDA_AUTO_ACTIVATE_BASE=false
```
