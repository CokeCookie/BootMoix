#include <string.h>
#include <stdio.h>

#include <switch.h>

void attemptBoot(s8 mode){
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
        
        bpcExit();
    }
}

s8 checkConfig(void){
    FILE * pFile;
    
    pFile = fopen("reboot","r");
    if (pFile != NULL)
    {
        fclose (pFile);
        return 1;
    }
    pFile = fopen("reboot.txt","r");
    if (pFile != NULL)
    {
        fclose (pFile);
        return 1;
    }
    pFile = fopen("shutdown","r");
    if (pFile != NULL)
    {
        fclose (pFile);
        return 2;
    }
    pFile = fopen("shutdown.txt","r");
    if (pFile != NULL)
    {
        fclose (pFile);
        return 2;
    }
    
    return 0;
}


int main(int argc, char **argv)
{
    s8 mode = 0;

    gfxInitDefault();
    consoleInit(NULL);
    
    mode = checkConfig();

    printf("Hello!\n\n");
    printf("Press \x1b[33mA\x1b[0m for \x1b[32mreboot\x1b[0m\n");
    printf("Press \x1b[33mB\x1b[0m for \x1b[31mshutdown\x1b[0m\n");

    // Main loop
    while(appletMainLoop())
    {
        if (mode > 0){
            printf("Mode from config: %d", mode);
            // break;
        }
        
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

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

    attemptBoot(mode);

    gfxFlushBuffers();
    gfxSwapBuffers(); 
    gfxWaitForVsync();
    gfxExit();
    return 0;
}

