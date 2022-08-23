# WifiConnection
This is a repository dedicated to setup a ssh connection between two computers, a host and a Single Board Computer (referred as SBC)

## The Host Computer:
In the host computer run the following setup:

```bash
git clone git@github.com:SkyRats/WifiConnection.git
cd WifiConnection/
bash host-setup.bash
```

To use this repository, simply run ```./WIFICONNECTION.sh start``` whenever you want to become a hotspot. To disable the hotspot feature run ```./WIFICONNECTION.sh stop```

## The Single Board Computer:
In the SBC run the following setup:
> The hotspot of the host computer must be turned on and withing wifi range for this to work.
```bash
git clone git@github.com:SkyRats/WifiConnection.git
cd WifiConnection/
bash sbc-setup.bash
```
The SBC should automatically connect to your hotspot whenever it is available on boot.