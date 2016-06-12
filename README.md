# RTL8812AU_ASUS

ASUS USB-AC56 driver from [Asus downloads](http://dlcdnet.asus.com/pub/ASUS/wireless/USB-AC56/DR_USB_AC56_4314_Linux.zip?_ga=1.223083801.321763280.1465209400)

Modified to compile against kernels > 3.18 - tested on Archlinux x86_64 against kernel 4.6.2 - should also compile for
earlier kernels. Builds on x86_64 as default. Change platform as needed in the MakeFile under section "Platform Related".

To build:

```
make clean
make
```

To install (as root or sudo):

```
make install
```

To activate (as root or sudo):

```
modprobe 8812au
```
