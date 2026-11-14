// Sleem File System Next Generation 1.0 (informally SleemFSNX/FSNX/SNX) designed for SleemOS x86_64
// credits: v3x, osdev (credits for software used outside this file in other files)

#include <stdint.h>
#include "../include/strcmp.h"
#include "../include/kernel.h"
#include "../include/sleemfs.h"
#include "../include/shal.h"
#define newline uartcharacterplacement("\r\n")
    int nameofshit; 
    int forwritingshit;
    int forremovingshit;
    int forlistingshit;
    int forhexdumpingshit;
filings shit[15];
superblocking superblocking2;
uint16_t buffershitidentity[256];
filings bufferoftables[8];
extern const char forhexdumping2[];
uint16_t bufferofdata[256];
uint32_t bufferofhumancentipede[128];



void copyshit2(char* destination, const char* sourc) {
  while ((*destination++ = *sourc++));
}


void saveshit() {
}

void formattingshit() {
    uint32_t tds = hal_sfs_identifyingshit(buffershitidentity); // tds = totaldisksize
    if(tds == 0) {
        newline;
        uartcharacterplacement("No disk!");
        newline;
    }
    else {
        uint8_t* clearingshit = (uint8_t*)&superblocking2;
        for(int i = 0; i < 512; i++) clearingshit[i] = 0;
        copyshit2(superblocking2.magik, "SLEEMNX");
        superblocking2.versioning = 1;
        superblocking2.sectoringtotalling = tds;
        superblocking2.theentries = tds / 32;
        superblocking2.thesectors = (superblocking2.theentries + 7) / 8;
        superblocking2.startoftable = 1;
        superblocking2.humancentipede = superblocking2.startoftable + superblocking2.thesectors;
        superblocking2.humancentipedesectors = (tds + 127) / 128;
        superblocking2.startofdata = superblocking2.humancentipede + superblocking2.humancentipedesectors;
        superblocking2.blocksofdata = tds - superblocking2.startofdata;
        hal_sfs_writingsectoringshit(0, (uint16_t*)&superblocking2); // gungus adventures
        uint16_t zeroshit[256] = {0};
        for(int eye5 = superblocking2.startoftable; eye5 < superblocking2.startofdata; eye5++) {
            hal_sfs_writingsectoringshit(eye5, zeroshit);
        }
    }
}

void loadshit() {
}


int createshit(const char* shitforcreating) {
    int shitforcreating2;
    if(findshit(shitforcreating) == -1) {
for(shitforcreating2 = 0; shitforcreating2 < superblocking2.thesectors; shitforcreating2++) {
    hal_sfs_readsectoringshit(superblocking2.startoftable + shitforcreating2, (uint16_t*)bufferoftables);
    for(int shitforcreating3 = 0; shitforcreating3 < 8; shitforcreating3++) {
    if(bufferoftables[shitforcreating3].ifusedornotused == false) { 
    copyshit2(bufferoftables[shitforcreating3].namings, shitforcreating);
    bufferoftables[shitforcreating3].sizeofdoomscroll = 0;
    bufferoftables[shitforcreating3].ifusedornotused = true;
    bufferoftables[shitforcreating3].firstchicken = 0xFFFFFFFF;
    hal_sfs_writingsectoringshit(superblocking2.startoftable + shitforcreating2, (uint16_t*)bufferoftables);
    return 1;
    }
}
}
    uartcharacterplacement("\r\n");
    uartcharacterplacement("Filesystem full!");
    uartcharacterplacement("\r\n");
    return 0;
    }
    uartcharacterplacement("\r\nFile already exists!\r\n");
    return 0;
}



    int findshit(const char* forfindingshit) {
        int forfindingshit2;
        for(forfindingshit2 = 0; forfindingshit2 < superblocking2.thesectors; forfindingshit2++) {
            hal_sfs_readsectoringshit(superblocking2.startoftable + forfindingshit2, (uint16_t*)bufferoftables);
            for(int coinsslot = 0; coinsslot < 8; coinsslot++) {
            if(bufferoftables[coinsslot].ifusedornotused == true) {
                if(strcmp(forfindingshit, bufferoftables[coinsslot].namings) == 0) {
                    return forfindingshit2 * 8 + coinsslot; // writing an fs is fucking stupid
                }
                
            }
            }
        }
        return -1;
    }
    

    void listshit(int modesssst) {
        if(modesssst == 0) {
        uartcharacterplacement("\r\n");
        for(forlistingshit = 0; forlistingshit < superblocking2.thesectors; forlistingshit++) {
            hal_sfs_readsectoringshit(superblocking2.startoftable + forlistingshit, (uint16_t*)bufferoftables);
            for(int forlistingshit2 = 0; forlistingshit2 < 8; forlistingshit2++)
            if(bufferoftables[forlistingshit2].ifusedornotused == true) {
                uartcharacterplacement(bufferoftables[forlistingshit2].namings);
                uartcharacterplacement("\r\n");
            }

        }
        


    }
        else if(modesssst == 1) {
                    uartcharacterplacement("\r\n");
        for(forlistingshit = 0; forlistingshit < superblocking2.thesectors; forlistingshit++) {
            hal_sfs_readsectoringshit(superblocking2.startoftable + forlistingshit, (uint16_t*)bufferoftables);
            for(int forlistingshit2 = 0; forlistingshit2 < 8; forlistingshit2++) {
            if(bufferoftables[forlistingshit2].ifusedornotused == true) {
                uartcharacterplacement(bufferoftables[forlistingshit2].namings);
                uartcharacterplacement(",");
                uartcharacterplacement(" ");
                uint32tonumber(bufferoftables[forlistingshit2].sizeofdoomscroll);
                uartcharacterplacement(" bytes");
                uartcharacterplacement("\r\n");
        }

        }
    }
    }
}


    void checkif() {
        hal_sfs_readsectoringshit(0, (uint16_t*)&superblocking2);
        int checkifshit = 1;
        for(int checkifshit2 = 0; checkifshit2 < 8; checkifshit2++) {
            if(superblocking2.magik[checkifshit2] != "SLEEMNX"[checkifshit2]) {
                checkifshit = 0;
            } 
        }
        if(checkifshit == 1) {
            if(superblocking2.versioning == 1) {
            loadshit();
            }
            else {
            uartcharacterplacement("Incompatible filesystem version! Writing SleemFS 1...");
            uartcharacterplacement("\r\n");
            formattingshit();
            }
        }
        else {
            uartcharacterplacement("Invalid filesystem, writing SleemFS Nextgen 1...");
            uartcharacterplacement("\r\n");
            formattingshit();
        }
    }


    int writeshit() {
      forwritingshit = findshit(comans + nameofshit); 
      if(forwritingshit == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
        return 0;
      }
      else {
        hal_sfs_readsectoringshit(superblocking2.startoftable + forwritingshit / 8, (uint16_t*)bufferoftables);
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Edit: ");
        typepls();
        int icutmyfuckingfinger = 0;
        while(comans[icutmyfuckingfinger] != '\0') {
        icutmyfuckingfinger++;
        }
        bufferoftables[forwritingshit % 8].sizeofdoomscroll = icutmyfuckingfinger;
        uartcharacterplacement("\r\n");
        uint32_t imshittingblocks = bufferoftables[forwritingshit % 8].firstchicken;
        if(imshittingblocks == 0xFFFFFFFF) {
            for(int eye6 = 0; eye6 < superblocking2.humancentipedesectors; eye6++) {
                hal_sfs_readsectoringshit(superblocking2.humancentipede + eye6, (uint16_t*)bufferofhumancentipede);
                for(int eye7 = 0; eye7 < 128; eye7++) {
                    if(bufferofhumancentipede[eye7] == 0) {
                        if(bufferofhumancentipede[eye7] == 0 && eye6 * 128 + eye7 < superblocking2.blocksofdata) {
                        imshittingblocks = eye6 * 128 + eye7; // Hi guys
                        bufferofhumancentipede[eye7] = 0xFFFFFFFF;
                        hal_sfs_writingsectoringshit(superblocking2.humancentipede + eye6, (uint16_t*)bufferofhumancentipede);
                        goto ishatmypants;
                        }
                    }

                }
            }
            newline;
            uartcharacterplacement("Disk full!");
            newline;
            return 0;
        }
        ishatmypants:
        memset(bufferofdata, 0, 512);
        copyshit2((char*)bufferofdata, comans);
        hal_sfs_writingsectoringshit(superblocking2.startofdata + imshittingblocks, (uint16_t*)bufferofdata);
        bufferoftables[forwritingshit % 8].firstchicken = imshittingblocks;
        hal_sfs_writingsectoringshit(superblocking2.startoftable + forwritingshit / 8, (uint16_t*)bufferoftables);
        
        return 1;
    }
    }


    void hexshitdump() {
    forhexdumpingshit = findshit(comans + nameofshit); 
    
      if(forhexdumpingshit == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
        return;
      }
    hal_sfs_readsectoringshit(superblocking2.startoftable + forhexdumpingshit / 8, (uint16_t*)bufferoftables);
        if(bufferoftables[forhexdumpingshit % 8].firstchicken != 0xFFFFFFFF) {
        hal_sfs_readsectoringshit(superblocking2.startofdata + bufferoftables[forhexdumpingshit % 8].firstchicken, bufferofdata);
      for(int eye = 0; eye < bufferoftables[forhexdumpingshit % 8].sizeofdoomscroll; eye++) {
        unsigned char hexshit = ((unsigned char*)bufferofdata)[eye];
      int hexup = hexshit >> 4;
      int hexlo = hexshit & 0x0F;
      char hexput[4];
      newline;
      uartcharacterplacement("0x");
      pleaseputacharacter(forhexdumping2[hexup]);
      pleaseputacharacter(forhexdumping2[hexlo]);
      newline;
      }
    }

      else {
        newline; // consistency or some shit
      }
    }


    int readshit() {

        int forreadingshit;
        forreadingshit = findshit(comans + nameofshit);
        if(forreadingshit == -1) {
          uartcharacterplacement("\r\n");
          uartcharacterplacement("Invalid file!");
          uartcharacterplacement("\r\n");
          return 0;
        }
        else {
        hal_sfs_readsectoringshit(superblocking2.startoftable + forreadingshit / 8, (uint16_t*)bufferoftables);
          if(bufferoftables[forreadingshit % 8].firstchicken == 0xFFFFFFFF) {
            newline;
            return 1;
            }
          hal_sfs_readsectoringshit(superblocking2.startofdata + bufferoftables[forreadingshit % 8].firstchicken, bufferofdata);
          uartcharacterplacement("\r\n");
          uartcharacterplacement((char*)bufferofdata);
          uartcharacterplacement("\r\n");
          return 1;
        }
    }

    int removeshit() {
        forremovingshit = findshit(comans + nameofshit);
      if(forremovingshit == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
        return 0;
      }
      else {
    hal_sfs_readsectoringshit(superblocking2.startoftable + forremovingshit / 8, (uint16_t*)bufferoftables);
    uint32_t shittingblocks2 = bufferoftables[forremovingshit % 8].firstchicken;
    bufferoftables[forremovingshit % 8].ifusedornotused = false;
    bufferoftables[forremovingshit % 8].sizeofdoomscroll = 0;
    bufferoftables[forremovingshit % 8].firstchicken = 0xFFFFFFFF;
    if(shittingblocks2 != 0xFFFFFFFF) {

    hal_sfs_readsectoringshit(superblocking2.humancentipede + shittingblocks2 / 128, (uint16_t*)bufferofhumancentipede);
    bufferofhumancentipede[shittingblocks2 % 128] = 0;
    hal_sfs_writingsectoringshit(superblocking2.humancentipede + shittingblocks2 / 128, (uint16_t*)bufferofhumancentipede);

      }
    hal_sfs_writingsectoringshit(superblocking2.startoftable + forremovingshit / 8, (uint16_t*)bufferoftables);
    return 1;
      }

    }