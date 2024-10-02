# X6100 LVGL GUI

This is part of an alternative firmware for X6100 using the LVGL library

## Installation

0. If you're running a previous version of R1CBU,
   insert the card into your computer
   and backup the files from the `DATA` partition.
1. Download the `sdcard.img.zip` from the
   [Releases](https://github.com/gdyuldin/x6100_gui/releases/latest) page.
2. Unzip the file to find `sdcard.img`.
3. Burn the `sdcard.img` file to a microSD card
   with your choice of writer software:
  * [balenaEtcher](https://etcher.balena.io/) on many platforms
  * [Rufus](https://rufus.ie/en/) on Windows
  * `dd` on Linux
4. Insert the card into the X6100 transceiver.
5. Boot the radio to start the new firmware and have a new `DATA` partition created.
6. Shutdown the radio.
7. Insert the card back into your computer and open the new `DATA` partition.
7. Restore copies of your `params.db` and other files you backed up to the `DATA`
   partition.

## Importing ADI log

The application can mark callsigns youve already worked in the UI.
To import previous QSOs, copy your ADI log to the `DATA` partition
and rename it to `incoming_log.adi`.
The application will import records to its own log on the next boot
and rename `incoming_log.adi` to `incoming_log.adi.bak`.

*Note*: `DATA` partition will be created after first launch transceiver with inserted SD card.


## Exporting ADI log

The application stores FT8/FT4 QSOs to the `ft_log.adi` file
on the `DATA` partition of SD card. This file might be used
to load QSOs to online log.


## Building


* Clone repositories

```
mkdir x6100
cd x6100
git clone https://github.com/gdyuldin/AetherX6100Buildroot
git clone https://github.com/gdyuldin/x6100_gui
```

* Build buildroot

```
cd AetherX6100Buildroot
./br_build.sh
cd ..
```

* Build app

```
cd x6100_gui
git submodule init
git submodule update
cd buildroot
./build.sh
```
