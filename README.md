# BootMoix

Simple Shutdown/Reboot Homebrew for Nintendo Switch using libnx.  
It even has a scene-appropriate totally legit french title. Enjoy!  
  
This is a slightly modified version of a [libnx example](https://github.com/switchbrew/switch-examples) that uses calls to the bpc service to Shutdown/Reboot your Switch.  
Just download a release or compile it yourself. Use with hbmenu like any other homebrew and follow the onscreen instructions.  
  
__DISCLAIMER: I am not responsible for bricked switches, corrupted SD cards or any otherwise f*ed up things that happen to you. Use at your own risk!__
  
## How to install

+ release version: 
  + Extract the provided .zip file. 
  + Copy the `BootMoix` folder to the `switch` folder on your SD card. 
  
+ compiled version:
  + Clone this repository.
  + Compile using `make`.
  + Copy the `BootMoix` folder inside the `out` folder to the `switch` folder on your SD card.

+ configuration:
  + Create a file called `reboot` inside the `BootMoix` folder on your SD card to skip straight to reboot.
  + ~~Create a file called `shutdown` inside the `BootMoix` folder on your SD card to skip straight to shutdown.~~

_Shutdown mode is currently not recommended! The first boot after using it always fails. Don't panic if it happens to you, just press power and inject your RCM payload again._


## How to compile
