# RTL8812AU_ASUS

ASUS USB-AC56 driver from [Asus downloads](http://dlcdnet.asus.com/pub/ASUS/wireless/USB-AC56/DR_USB_AC56_4314_Linux.zip?_ga=1.223083801.321763280.1465209400)

Modified to compile against kernels > 3.18 - tested on Archlinux x86_64 against kernel 4.6.2 - should also compile for
earlier kernels. Builds on x86_64 as default. Change platform as needed in the MakeFile under section "Platform Related".

Updated to support VHT (802.11ac) mode using changes from [uminokoe](https://github.com/diederikdehaas/rtl8812AU/pull/14/commits/445b475ac5c1372e458134d9a7394b882b0bbb1f).
Using the changed the card then connects in 802.11ac mode (previously would connect as 802.11n on Linux).

Here's  the output of sudo iwconfig on my ArchLinux x64:

 ```
 IEEE 802.11AC  ESSID:"MySID"  Nickname:"<WIFI@REALTEK>"
    Mode:Managed  Frequency:5.22 GHz  Access Point: MyAccesspointMAC
    Bit Rate:867 Mb/s   Sensitivity:0/0
    Retry:off   RTS thr:off   Fragment thr:off
    Encryption key:****-****-****-****-****-****-****-****   Security mode:open
    Power Management:off
    Link Quality=98/100  Signal level=88/100  Noise level=0/100
    Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0
    Tx excessive retries:0  Invalid misc:0   Missed beacon:0
```

Issues:
- although the bit rate is listed as 867 Mb/s I have been unable in my tests to get
speeds greater than 250-300Mbs (give or take a few megabits). The reasons for this
are yet unclear - if you manage to get greater speeds please tell me about your setup /
test / changes.
- Although the USB AC-56 is supposed to be USB 3.0 capable, `lsusb` lists it as a 2.0 USB
device. Same on Windows 10 using Windows stock drivers. The adapter is first shown as as USB 3.0
(Superspeed) device after installing the Asus specific drivers. Again the reason for this is not
yet clear to me - any insights appreciated.

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
