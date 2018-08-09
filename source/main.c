#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    s8 mode = 0;

    gfxInitDefault();
    consoleInit(NULL);

    printf("Hello!\n\n");
    printf("Press \x1b[33mA\x1b[0m for \x1b[32mreboot\x1b[0m\n");
    printf("Press \x1b[33mB\x1b[0m for \x1b[31mshutdown\x1b[0m\n");

    // Main loop
    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // Your code goes here

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

	if (kDown & KEY_A){
	    mode = 1; // reboot mode
	    break;
	}

	if (kDown & KEY_B){
	    mode = 2; // shutdown mode
	    break;
	}

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }


    Result rc = bpcInitialize();
    if (R_FAILED(rc))
        printf("bpcInit: %08X\n", rc);
    else
    {
        printf("bpc Init Successful!\n\n");
	if (mode == 1){
	    printf("reboot");
	    bpcRebootSystem();
	}
	else if (mode == 2){
	    printf("shutdown");
	    bpcShutdownSystem();
	}
    }


    gfxFlushBuffers();
    gfxSwapBuffers(); 
    gfxWaitForVsync();

    bpcExit();
    gfxExit();
    return 0;
}

