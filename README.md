# RTL8812AU_ASUS

ASUS USB-AC56 driver from [Asus downloads](http://dlcdnet.asus.com/pub/ASUS/wireless/USB-AC56/DR_USB_AC56_4314_Linux.zip?_ga=1.223083801.321763280.1465209400)

Modified to compile against kernels > 3.18 - tested on Archlinux x86_64 against kernel 4.6.2 - should also compile for
earlier kernels. Builds on x86_64 as default. Change platform as needed in the MakeFile under section "Platform Related".

Updated to support VHT (802.11ac) mode using changes from [uminokoe](https://github.com/diederikdehaas/rtl8812AU/pull/14/commits/445b475ac5c1372e458134d9a7394b882b0bbb1f).
The card then connects in 802.11ac mode (previously would connect as 802.11n on Linux).

Issues:
- although the bit rate is listed as 867 Mb/s I have been unable in my tests to get
throughput greater than 250-350Mbs (give or take a few megabits) on my setup (Asus RT-3200 router).
 If you manage to get greater speeds I'd appreciate you telling me about your setup,  test and
 any driver changes you made.
- Although the USB AC-56 is supposed to be USB 3.0 capable, `lsusb` lists it as a 2.0 USB
device. Windows 10 appears to also see it as as USB 2.0 device using Windows stock drivers.
The adapter is first recognized as a USB 3.0 (Superspeed) device after installing the Asus
specific drivers. This may indicate that specific code exists in the Windows driver to switch
ths USB mode from 2.0 to 3.0 which is not present in the source version provided by Asus.
If so it's a shame because it means that the  USB AC-56 is then actually bound to the USB 2.0
max throughput of 480Mbs on Linux making it a good but expensive 802.11n adapter. Again any insights
would be greatly appreciated.

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
