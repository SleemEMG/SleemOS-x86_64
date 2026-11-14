// Sleem Operating System x86_64 1.0 BETA (informally SleemOS)
// BITNXG 1.0
// credits: v3x, osdev (credits for software used outside this file in other files)

#include <stdint.h>
#include "../include/shal.h"
#include "../include/strcmp.h"
#define newline uartcharacterplacement("\r\n")
#include "../include/limine.h"
__attribute__((used, section(".limine_requests")))
static volatile uint64_t liminerevision[] = LIMINE_BASE_REVISION(2);

__attribute__((used, section(".limine_requests")))
static volatile limine_framebuffer_request fbruh = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

__attribute__((used, section(".limine_requests")))
static volatile limine_hhdm_request ehehdeem = {
    .id = LIMINE_HHDM_REQUEST_ID,
    .revision = 0
};

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t liminemarkings[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limineendmarkings[] = LIMINE_REQUESTS_END_MARKER;


// they should rename limine to lemon


const char* comans;
int peniscum5000 = 0;
int peniscum6000;
int overwarn = 0;
volatile uint32_t tiks = 0;
uint64_t hhdmoffset;

extern "C" void systrickcounter() {
  tiks++;
}

void pleaseputacharacter(char okillputacharacter) {
hal_pleaseputacharacter(okillputacharacter);
}

void uartcharacterplacement(const char *okillplaceit) {

  while (*okillplaceit != '\0') {
    pleaseputacharacter(*okillplaceit);
    okillplaceit++; // this took me like 10 fucking minutes to figure out + 5 for the braces
  }
}

void uint32tonumber(uint32_t number) {
  if(number == 0) {
    uartcharacterplacement("0");
  }
  char table[11];
  int counter = 0;
  while(number != 0) {
  table[counter] = number % 10 + '0';
  counter++;
  number = number / 10; // I FUCKING HATE CPP
  // ill fucking jump off a bridge if it doesnt work next try
  }
  int counterminus1 = counter - 1; // no fucking shit
  while(counterminus1 >= 0) {
  pleaseputacharacter(table[counterminus1]);
  counterminus1 --; // im ENDING IT if this doesnt work
  // IM GONNA SERIOUSLY FUCKING DO IT
  }
}
 /*   void uint32tohex(uint32_t hex) {

      for(int eyee = 0; eyee < 8; eyee++) {
      int ihatewritingthisshit = (hex >> 28) & 0xF;
      pleaseputacharacter(forhexdumping2[ihatewritingthisshit]);
      hex = hex << 4;
      }
    }
*/

volatile char storag[64];
volatile int writeindia = 0;
volatile int readindia = 0;

char givcharacter() {
  while (readindia == writeindia) {
  hal_idle(); // Penis.
  }
  char okiassignedit = storag[readindia];
  readindia = (readindia + 1) & 63;
  return okiassignedit;  // tuff
}
char maxinput[256];
int howmanycharacterscurrently = 0;

void startanewterm() { 
    hal_colorsettingss(vga_colors(colorss_minus_magenta, colorss_black));
    uartcharacterplacement("SleemSH> ");
    hal_colorsettingss(vga_colors(colorss_white, colorss_black));
 } // hacker green prompt // it is purple

void copyshit(char* destination, const char* sourc) {
  while ((*destination++ = *sourc++));
}

char uparrowshit[256];
int FUCKTHISBULLSHIT = 1;
int lengthofuparrowshit = 0;

void typepls() {
  peniscum6000 = 0;
  while (1) {
    char userinputprobably = givcharacter();
    if(userinputprobably == '\n' && peniscum5000 == 1) {
      peniscum5000 = 0;
      continue;
    }
    peniscum5000 = 0;
    if(peniscum6000 == 1) {
      if(userinputprobably == '[') {
        peniscum6000 = 2;
        continue;
      }
      else if(userinputprobably == '\x1b') {
        continue;
      }
      else {
        peniscum6000 = 0;
      }
    }
    else if (peniscum6000 == 2) {
      if(userinputprobably == 'A') {
        peniscum6000 = 0;
        if(FUCKTHISBULLSHIT == 1) {
          lengthofuparrowshit = 0;
          while(uparrowshit[lengthofuparrowshit] != '\0') {
            lengthofuparrowshit++;
          }
          while(howmanycharacterscurrently != 0) {
            uartcharacterplacement("\b \b");
            howmanycharacterscurrently--;
          }
          uartcharacterplacement(uparrowshit);
          copyshit(maxinput, uparrowshit);
          howmanycharacterscurrently = lengthofuparrowshit;
        }
        continue;
      }
      else if(userinputprobably >= 0x40 && userinputprobably <= 0x7E) {
        peniscum6000 = 0;
        continue;
      }
      else if(userinputprobably >= 0x20 && userinputprobably <= 0x3F) {
        continue;
      }
      else {
        peniscum6000 = 0;
      }
    }
    if (userinputprobably == '\n' || userinputprobably == '\r') {
      maxinput[howmanycharacterscurrently] = '\0';
      if(FUCKTHISBULLSHIT == 1) {
        if(howmanycharacterscurrently > 0) {
          copyshit(uparrowshit, maxinput);
        }
      }
      howmanycharacterscurrently = 0;
      overwarn = 0;
      if (userinputprobably == '\r') {
        peniscum5000 = 1;
      }
      return;
    }
    else if (userinputprobably == '\b' || userinputprobably == 0x7f) {
      if(howmanycharacterscurrently > 0) {
        howmanycharacterscurrently--;
        uartcharacterplacement("\b \b");
      }
    }
    else if (userinputprobably == '\x1b') {
      peniscum6000 = 1;
    }
    else if (howmanycharacterscurrently < 255) {
      maxinput[howmanycharacterscurrently] = userinputprobably;
      howmanycharacterscurrently++;
      pleaseputacharacter(userinputprobably);
    }
    else {
      if(overwarn == 0) {
        overwarn = 1;
        newline;
        uartcharacterplacement("you have typed too much shit and caused an overflow.");
        newline;
      }
    }
  }
}

int echolaid(const char* lllllline, const char* prefik) {
    while (*prefik != '\0') {
      if (*lllllline != *prefik) {
        return 0;
      }
      lllllline++;
      prefik++;
    }
    return 1;
}

int returnvalue; // commit


  void termcommandsssss() {
    if (strcmp(comans, "help") == 0) {
      uartcharacterplacement("\r\nCommands: help, neofetch, clear, uptime, echo, write (SleemFS, TEMPORARILY NOT IN OS), touch (SleemFS, TEMPORARILY NOT IN OS), cat (SleemFS, TEMPORARILY NOT IN OS), ls (SleemFS, TEMPORARILY NOT IN OS), rm (SleemFS, TEMPORARILY NOT IN OS), edit (SleemFS, TEMPORARILY NOT IN OS), panik, reboot, run (SleemInt x86_64, TEMPORARILY NOT IN OS), hexdump (SleemFS, TEMPORARILY NOT IN OS), badapple (TEMPORARILY NOT IN OS)\r\n");
    }
    else if (strcmp(comans, "neofetch") == 0) {
      char cpuname[49];

      uartcharacterplacement("\r\nOS: SleemOS x86_64 \r\nBuild: 1.0 \r\nKernel: BITNXG 1.0 ");
      uartcharacterplacement("\r\nCPU: ");
      hal_isitgenuineamdorintelsomething(cpuname);
      uartcharacterplacement(cpuname);
      newline;
    }
    else if (strcmp(comans, "clear") ==  0) {
      hal_clearingshit(); // idk why is it in characters but still its kinda cool
    }
    else if (strcmp(comans, "") ==  0) {
        uartcharacterplacement("\r\n");
    }
/*   else if(echolaid(comans, "touch ") == 1) {
      nameofshit = 6;
      if(comans[nameofshit] == '\0') {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Filename cannot be empty!");
        uartcharacterplacement("\r\n");

      }
      else {
      returnvalue = createshit(comans + nameofshit);
      uartcharacterplacement("\r\n");
              if(returnvalue == 1) {
      saveshit();
              }
            }
          }
     

    else if (strcmp(comans, "ls") ==  0) {
      listshit(0);
      }
    
    else if (strcmp(comans, "badapple") == 0) {
      uartcharacterplacement("\r\n");
      uartcharacterplacement("\r\n");
      badappl();
    }



    else if (echolaid(comans, "ls ") == 1) {
      if(strcmp(comans + 3, "-l") == 0) {
        listshit(1);
      }
      else {
        listshit(0);
    }
  }
    else if (echolaid(comans, "cat ") == 1) {
      nameofshit = 4;
      readshit();
    }
    else if (echolaid(comans, "run ")) {
      nameofshit = 4;
      sleemintprint(comans + 4);
      }
    else if (echolaid(comans, "write ") == 1) {
      nameofshit = 6;
      FUCKTHISBULLSHIT = 0;
      returnvalue = writeshit();
      FUCKTHISBULLSHIT = 1;
              if(returnvalue == 1) {
      saveshit();
              }
 // this is fucking evil bro
      }
      else if (echolaid(comans, "hexdump ") == 1) {
        nameofshit = 8;
        hexshitdump();
    }    
    */
      else if (strcmp(comans, "reboot") == 0) {
        uartcharacterplacement("\r\n");
        hal_resettingshit();
        while(1);
      } 
      /*
      else if (echolaid(comans, "rm ") == 1) {
        nameofshit = 3;
        returnvalue = removeshit();
        if(returnvalue == 1) {
        saveshit();
        }
        uartcharacterplacement("\r\n");
      }
    */
    else if (strcmp(comans, "uptime") == 0) {
      uint32_t localtiks = tiks;
      uartcharacterplacement("\r\nUptime: "); // this better fucking work OR FUCKINE ELSE
      if(localtiks < 60000) {
      uint32tonumber(localtiks / 1000);
      uartcharacterplacement("s");
      }
      else {
        uint32tonumber((localtiks / 1000) / 60);
        uartcharacterplacement("m ");
        uint32tonumber((localtiks / 1000) % 60);
        uartcharacterplacement("s");
      }

      uartcharacterplacement("\r\n"); // now i have FUCKING LINKER ERRORS IM GONNA HAVE AFUCKING MENTAL BREAKDOWN
 } // IM FUCKING ENDING IT IT DIDNT BOOT
    else if (echolaid(comans, "echo ") == 1) {
      uartcharacterplacement("\r\n");
      uartcharacterplacement(comans + 5);
      uartcharacterplacement("\r\n"); // i fucking DESPISE semicolons
}
  else if (strcmp(comans, "panik") == 0) {
    __asm volatile ("ud2");
  }
  /*
  else if (echolaid(comans, "edit ") == 1) {
    nameofshit = 5;
    if(findshit(comans + 5) == -1) {
        uartcharacterplacement("\r\n");
        uartcharacterplacement("Invalid file!");
        uartcharacterplacement("\r\n");
      }
      else {
    uartcharacterplacement("\r\n");
    uartcharacterplacement("Current file contents: ");
    readshit();
    uartcharacterplacement("\r\n");
    uartcharacterplacement("Changes:");
    FUCKTHISBULLSHIT = 0;
    returnvalue = writeshit();
    FUCKTHISBULLSHIT = 1;
      if(returnvalue == 1) {
    saveshit();
      }
    
      }
  }
     */
    else {
      uartcharacterplacement("\r\nNot implemented.\r\n");
    }
    }


extern "C" void sleemmf() { 
  if(fbruh.response == nullptr) {
  while (1){} 
  }
  limine_framebuffer* efbee = fbruh.response->framebuffers[0];
  framebufferingaddress = (uint8_t*)efbee->address;
  pitchingshit = efbee->pitch;
  wih = efbee->width;
  high = efbee->height;
  hal_clearingshit();
  uartcharacterplacement(
      "Welcome to SleemOS x86_64 1.0!\r\n");
 // checkif();
  hhdmoffset = ehehdeem.response->offset;
  hal_initializinginterrupts();
  while(1) {
    startanewterm();
    typepls();
    comans = maxinput;
    termcommandsssss();
}
}



// FUCK PCPCPPCPCPCPCPCPCPC
// YESSS IT WORKED