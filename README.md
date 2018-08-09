# BootMoix

Simple Shutdown/Reboot Homebrew for Nintendo Switch using libnx.  
It even has a scene-appropriate totally legit french name. Enjoy!  
  
This is a slightly modified version of a [libnx example](https://github.com/switchbrew/switch-examples) that uses calls to the bpc service to shutdown/reboot your Switch.  
Just download a release or compile it yourself. Use with hbmenu like any other homebrew and follow the onscreen instructions.  
  
_Shutdown mode is currently not recommended! The first boot after using it always fails. Don't panic if it happens to you, just press power and inject your RCM payload again._
    
__DISCLAIMER: I am not responsible for bricked switches, corrupted Nands/SD cards or any otherwise f*ed up things that happen to you. Use at your own risk!__
  
## How to install

+ release version: 
  1. Extract the provided .zip file. 
  2. Copy the `BootMoix` folder to the `switch` folder on your SD card. 
  
+ compiled version:
  1. Clone this repository.
  2. Compile using `make`.
  3. Copy the `BootMoix` folder inside the `out` folder to the `switch` folder on your SD card.

+ configuration:
  + Create a file called `reboot` inside the `BootMoix` folder on your SD card to skip straight to reboot.
  + ~~Create a file called `shutdown` inside the `BootMoix` folder on your SD card to skip straight to shutdown.~~

_Shutdown mode is currently not recommended! The first boot after using it always fails. Don't panic if it happens to you, just press power and inject your RCM payload again._


## How to compile

1. Set up your dev environment using [this guide](http://switchbrew.org/index.php?title=Setting_up_Development_Environment). I suggest using Docker.
2. Clone [XorTroll's fork](https://github.com/XorTroll/libnx) of libnx.
3. `cd libnx`
4. `make` (should finish without errors)
5. `make install`
6. `cd ..`
7. Clone this repository.
8. `cd BootMoix`
9. `make`
  
## Credits

Thanks to all the people responsible for libnx and hbmenu!
