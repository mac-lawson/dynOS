./clean.sh
./headers.sh
./iso.sh
zenity --info --width 300 --text "dynOS built. Booting ISO on QEMU."
./qemu.sh
