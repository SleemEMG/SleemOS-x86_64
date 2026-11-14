// SleemOS Hardware Abstraction Layer file
#define FONT8x16_IMPLEMENTATION
#include "../include/shal.h"
#include "../include/font8x16.h"

volatile uint16_t *textmodeshit = (volatile uint16_t *)0xB8000; // ts feels like writing byteos 1.0 all over again
int rows; 
int colums;
int colorssss = 0x0F;
extern volatile uint32_t tiks;
extern volatile char storag[64];
extern volatile int writeindia;
extern volatile int readindia;
extern const char forhexdumping2[] = "0123456789ABCDEF";
extern "C" void systrickcounter();
extern uint64_t hhdmoffset;
uint8_t* framebufferingaddress;
uint64_t pitchingshit;
uint64_t wih;
uint64_t high;
static bool isshiftheldornot;
static volatile bool uparrowornot = false;

static const uint32_t redgreenblueorsomeshi[16] = {
    0x000000, 0x0000AA, 0x00AA00, 0x00AAAA,
    0xAA0000, 0xAA00AA, 0xAA5500, 0xAAAAAA,
    0x555555, 0x5555FF, 0x55FF55, 0x55FFFF,
    0xFF5555, 0xCF9FFF, 0xFFFF55, 0xFFFFFF
};

/* All credits to GCC for memset and memcpy*/
#include <stddef.h>
extern "C" {
void *
memcpy (void *dest, const void *src, size_t len)
{

char *d = (char*)dest;
const char *s = (const char*)src; // fixing
  while (len--)
    *d++ = *s++;
  return dest;
}
}

#include <stddef.h>
extern "C" {
void *
memset (void *dest, int val, size_t len)
{
  unsigned char *ptr = (unsigned char*)dest; // fuck you CPP20
  while (len-- > 0)
    *ptr++ = val;
  return dest;
}
}

void hal_pleaseputacharacter(char charakters) {
    if(charakters == '\n') {
        colums = 0;
        rows = rows + 1; // Hi!
    }
    else if(charakters == '\r') {
        colums = 0;
         // Hi! No
    }
    else if(charakters == '\b') { // :B or some shi
        if(colums != 0) {
            colums = colums - 1;
        }
         // Hi! No Yes
    }
    // scrollings is outside now
    else {
        uint32_t foregroud = redgreenblueorsomeshi[colorssss & 0xF];
        uint32_t backgroundyshit = redgreenblueorsomeshi[colorssss >> 4];
        for(int why = 0; why < 16; why++) {
            font8x16[(uint8_t)charakters][why];
            for(int ex = 0; ex < 8; ex++) {
                uint8_t byteos = font8x16[(uint8_t)charakters][why];
                uint32_t imshittingpixels;
                if((byteos >> (7 - ex)) & 1) { // byteos reference
                    imshittingpixels = foregroud;
                }
                else {
                    imshittingpixels = backgroundyshit;
                }
                *(uint32_t*)(framebufferingaddress + (rows*16 + why)*pitchingshit + (colums*8 + ex)*4) = imshittingpixels;
            }
        }
        colums = colums + 1;
    }
    //  kebab time (wrapping)
    if(colums >= wih / 8) {
    colums = 0;
    rows = rows + 1; // almost forgot rows = 
    }
    if(rows >= high / 16) {
    memcpy(framebufferingaddress, framebufferingaddress + 16*pitchingshit, (high - 16) * pitchingshit); // coppyinggg
    uint32_t foregroud2 = redgreenblueorsomeshi[colorssss & 0xF];
    uint32_t backgroundyshit2 = redgreenblueorsomeshi[colorssss >> 4];
    for(int why3 = high - 16; why3 < high; why3++) {
        for(int why4 = 0; why4 < wih; why4++) {
            *(uint32_t*)(framebufferingaddress + why3*pitchingshit + why4*4) = backgroundyshit2;
        }
        }
    rows = high/16 - 1;
}
}



void hal_clearingshit() {
uint32_t backgroundyshit2 = redgreenblueorsomeshi[colorssss >> 4];
for(int rowingshit = 0; rowingshit < high; rowingshit++) {
    for(int rowingshit2 = 0; rowingshit2 < wih; rowingshit2++) {
        *(uint32_t*)(framebufferingaddress + rowingshit*pitchingshit + rowingshit2*4) = backgroundyshit2;
    }
}
rows = 0;
colums = 0;
}


void hal_colorsettingss(uint8_t colorshit) {
    colorssss =  colorshit;
}
uint32_t numberone;
uint32_t two;
uint32_t three;
uint32_t four;
uint32_t questionmark;



void hal_isitgenuineamdorintelsomething(char* cpuidbuffersss) {
    for(int countingshit = 0; countingshit < 3; countingshit++) {
    questionmark = 0x80000002 + countingshit;
    asm volatile("cpuid" : "=a"(numberone), "=b"(two), "=c"(three), "=d"(four) : "a"(questionmark));
    memcpy(cpuidbuffersss + countingshit*16, &numberone, 4); // coppyingg part 2
    memcpy(cpuidbuffersss + countingshit*16 + 4, &two, 4); // coppyingg part 2
    memcpy(cpuidbuffersss + countingshit*16 + 8, &three, 4); // coppyingg part 2
    memcpy(cpuidbuffersss + countingshit*16 + 12, &four, 4); // coppyingg part 2
    }
    cpuidbuffersss[48] = 0;
}

static inline uint8_t readingportshitt(uint16_t portss) { uint8_t vcensored; asm volatile("inb %1, %0" : "=a"(vcensored) : "Nd"(portss)); return vcensored; }
static inline void sendingportshit(uint16_t portss2, uint8_t valuingshit) { asm volatile("outb %0, %1" : : "a"(valuingshit), "Nd"(portss2)); }
static inline uint16_t twoxreadingportshitt(uint16_t portss) { uint16_t vcensored; asm volatile("inw %1, %0" : "=a"(vcensored) : "Nd"(portss)); return vcensored; }
static inline void twoxsendingportshit(uint16_t portss2, uint16_t valuingshit) { asm volatile("outw %0, %1" : : "a"(valuingshit), "Nd"(portss2)); }

void hal_sfs_readsectoringshit(uint32_t elballsa, uint16_t* bufferingshit2) { // its lba
    while(readingportshitt(0x1F7) & 0x80) {}
    sendingportshit(0x1F6, 0xE0 | ((elballsa >> 24) & 0x0F));
    sendingportshit(0x1F2, 1);
    sendingportshit(0x1F3, elballsa & 0xFF);
    sendingportshit(0x1F4, (elballsa >> 8) & 0xFF);
    sendingportshit(0x1F5, (elballsa >> 16) & 0xFF);
    sendingportshit(0x1F7, 0x20);
    uint8_t statusingshit = readingportshitt(0x1F7);
    while((statusingshit & 0x80) || !(statusingshit & 0x08)) {
        statusingshit = readingportshitt(0x1F7);
        if(statusingshit & 0x01) {
            return;
        }
    }
    for(int eye1milion = 0; eye1milion < 256; eye1milion++) {
        bufferingshit2[eye1milion] = twoxreadingportshitt(0x1F0);
    }
}

uint32_t hal_sfs_identifyingshit(uint16_t* bufferingshit2) { // its lba
    while(readingportshitt(0x1F7) & 0x80) {}
    sendingportshit(0x1F6, 0xA0);
    sendingportshit(0x1F2, 0);
    sendingportshit(0x1F3, 0);
    sendingportshit(0x1F4, 0);
    sendingportshit(0x1F5, 0);
    sendingportshit(0x1F7, 0xEC);
    if(readingportshitt(0x1F7) == 0) {
    return 0;
}
    uint8_t statusingshit = readingportshitt(0x1F7);
    while((statusingshit & 0x80) || !(statusingshit & 0x08)) {
        statusingshit = readingportshitt(0x1F7);
        if(statusingshit & 0x01) {
            return 0; // ya proshol sakupen circles
        }
    }
    for(int eye1milion = 0; eye1milion < 256; eye1milion++) {
        bufferingshit2[eye1milion] = twoxreadingportshitt(0x1F0);
    }
    return bufferingshit2[60] | ((uint32_t)bufferingshit2[61] << 16);
}

void hal_sfs_writingsectoringshit(uint32_t elballsa2, uint16_t* bufferingshit2) { // its lba
    while(readingportshitt(0x1F7) & 0x80) {}
    sendingportshit(0x1F6, 0xE0 | ((elballsa2 >> 24) & 0x0F));
    sendingportshit(0x1F2, 1);
    sendingportshit(0x1F3, elballsa2 & 0xFF);
    sendingportshit(0x1F4, (elballsa2 >> 8) & 0xFF);
    sendingportshit(0x1F5, (elballsa2 >> 16) & 0xFF);
    sendingportshit(0x1F7, 0x30);
    uint8_t statusingshit = readingportshitt(0x1F7);
    while((statusingshit & 0x80) || !(statusingshit & 0x08)) {
        statusingshit = readingportshitt(0x1F7);
        if(statusingshit & 0x01) {
            return;
        }
    }
    for(int eye1milion = 0; eye1milion < 256; eye1milion++) {
    twoxsendingportshit(0x1F0, bufferingshit2[eye1milion]);
    }
    sendingportshit(0x1F7, 0xE7);
    while(readingportshitt(0x1F7) & 0x80) {}
}

void hal_resettingshit() {
    while(readingportshitt(0x64) & 2) {}
    sendingportshit(0x64, 0xFE);
    while(1) {}
}

void hal_idle() {
    asm volatile("hlt");
}

void hal_cursoringsuppings(int eye8) {
    rows = rows - eye8;
    if(rows < 0) {
    rows = 0;
    }
    colums = 0;
}

// idt time (idt was made to torture people)

struct idtshit {
    uint16_t oppositeofhigh; 
    uint16_t selektor; 
    uint8_t staktable; 
    uint8_t flags; 
    uint16_t middle; 
    uint32_t oppositeoflow; 
    uint32_t zerow; 
} 
__attribute__((packed));

static idtshit ideetee[256];
struct idtpointercrate { 
    uint16_t size; 
    uint64_t basee; } 
    __attribute__((packed));

static void idt_set(int vektorr, void* handelr, uint16_t selektor) { // sleemos reference
uint64_t a = (uint64_t)handelr;
ideetee[vektorr] = { (uint16_t)a, selektor, 0, 0x8E, (uint16_t)(a >> 16), (uint32_t)(a >> 32), 0 };
}

void uint32tohex(uint32_t hex) {

      for(int eyee = 0; eyee < 8; eyee++) {
      int ihatewritingthisshit = (hex >> 28) & 0xF;
      hal_pleaseputacharacter(forhexdumping2[ihatewritingthisshit]);
      hex = hex << 4;
      }
    } // i have to adapt this bullshit so it doesnt need sleemfs // ok that was quick and painless

static void hal_epsonprinter(const char* stringcheese) {
    for(int indexesss = 0; stringcheese[indexesss] != '\0'; indexesss++) {
        hal_pleaseputacharacter(stringcheese[indexesss]);
    }
}

struct frejm { // sleemos flashbacks again
    uint64_t restinpeace;
    uint64_t counterstrike;
    uint64_t cpushit;
    uint64_t stakpointer;
    uint64_t ss; // oh no
};

__attribute__((interrupt))
void udee_handelr(frejm* f) { // gungus adventures
    hal_epsonprinter("opcode is invalid at: ");
    uint32tohex((uint32_t)(f->restinpeace >> 32));
    uint32tohex((uint32_t)f->restinpeace);
    while(1) {}
}

__attribute__((interrupt))
void general_handelr(frejm* f, uint64_t errorshit) {
    hal_epsonprinter("general protection fault at: ");
    uint32tohex((uint32_t)(f->restinpeace >> 32));
    uint32tohex((uint32_t)f->restinpeace);
    hal_epsonprinter("the cpu gifted u an error code which iss: ");
    uint32tohex(errorshit);
    while(1) {}
}

__attribute__((interrupt))
void thepageisstuck_handelr(frejm* f, uint64_t errorshit) {
    uint64_t ceear2;
    asm volatile("mov %%cr2, %0" : "=r"(ceear2));
    hal_epsonprinter("page fault at: ");
    uint32tohex((uint32_t)(f->restinpeace >> 32));
    uint32tohex((uint32_t)f->restinpeace);
    hal_epsonprinter("the cpu gifted u an error code which iss: ");
    uint32tohex(errorshit);
    hal_epsonprinter("cr2: ");
    uint32tohex((uint32_t)(ceear2 >> 32));
    uint32tohex((uint32_t)ceear2);
    while(1) {}
}
__attribute__((interrupt))
void hal_tikshandelr(frejm* f) {
    systrickcounter();
    sendingportshit(0x20, 0x20);
}


char hal_scat(uint8_t codess) { // scan code ascii to yes it is deliberate
    static const char scancodingshit[] =
    "\0\0" "1234567890-=\b"
    "\tqwertyuiop[]\n"
    "\0asdfghjkl;'`"
    "\0\\zxcvbnm,./"
    "\0*\0 ";
    static const char shiftilingsscancodingshit[] =
    "\0\0" "!@#$%^&*()_+\b"
    "\tQWERTYUIOP{}\n"
    "\0ASDFGHJKL:\"~"
    "\0|ZXCVBNM<>?"
    "\0*\0 ";
    if(codess >= sizeof(scancodingshit) - 1) {
        return '\0';
    }
    else {
    if(isshiftheldornot == true) {
        return shiftilingsscancodingshit[codess];
    }
    else {
        return scancodingshit[codess];
    }  
    }
}


void hal_remappingshit() {
    sendingportshit(0x20, 0x11);
    sendingportshit(0xA0, 0x11);
    sendingportshit(0x21, 0x20);
    sendingportshit(0xA1, 0x28);
    sendingportshit(0x21, 0x04);
    sendingportshit(0xA1, 0x02);
    sendingportshit(0x21, 0x01);
    sendingportshit(0xA1, 0x01);
    sendingportshit(0x21, 0xFC);
    sendingportshit(0xA1, 0xFF);
}
__attribute__((interrupt))
void hal_keyboardhandelr(frejm* f) {
    uint8_t readingkeyboardshit = readingportshitt(0x60);
    if(readingkeyboardshit == 0x2A || readingkeyboardshit == 0x36) {
    isshiftheldornot = true;
    sendingportshit(0x20, 0x20);
    return;
    }
    if(readingkeyboardshit == 0xAA || readingkeyboardshit == 0xB6) {
    isshiftheldornot = false;
    sendingportshit(0x20, 0x20);
    return;
    }
    if(readingkeyboardshit == 0xE0) {
    uparrowornot = true;
    sendingportshit(0x20, 0x20);
    return;
    }
    if(uparrowornot) {
        int nextshit = (writeindia + 1) % 64;
        uparrowornot = false;
            if(readingkeyboardshit == 0x48) {
                if(nextshit != readindia) {
                    storag[writeindia] = '\x1b';
                    writeindia = nextshit;
                }
                nextshit = (writeindia + 1) % 64;
                if(nextshit != readindia) {
                    storag[writeindia] = '[';
                    writeindia = nextshit;
                }
                nextshit = (writeindia + 1) % 64;
                if(nextshit != readindia) {
                    storag[writeindia] = 'A';
                    writeindia = nextshit;
                }
    }
    sendingportshit(0x20, 0x20);
    return;
    }
    int nextshit = (writeindia + 1) % 64;
    if(nextshit != readindia) {
    char readingkeyboardshit2 = hal_scat(readingkeyboardshit);
    if(readingkeyboardshit2 != '\0') {
    storag[writeindia] = readingkeyboardshit2;
    writeindia = nextshit;
    }
}
sendingportshit(0x20, 0x20);
}


void hal_initializinginterrupts() {
    uint16_t counterstrike;
    asm volatile("mov %%cs, %0" : "=r"(counterstrike));
    idt_set(6, (void*)udee_handelr, counterstrike);
    idt_set(13, (void*)general_handelr, counterstrike);
    idt_set(14, (void*)thepageisstuck_handelr, counterstrike);
    idt_set(33, (void*)hal_keyboardhandelr, counterstrike);
    idtpointercrate pointercrate2 = { sizeof(ideetee) - 1, (uint64_t)ideetee };
    asm volatile("lidt %0" : : "m"(pointercrate2));
    hal_remappingshit();
    readingportshitt(0x60);
    volatile uint32_t* dryerlint = (volatile uint32_t*)(hhdmoffset + 0xFEE00350);
    *dryerlint = *dryerlint & ~(1u << 16);
    sendingportshit(0x43, 0x36);
    sendingportshit(0x40, 1193 & 0xFF);
    sendingportshit(0x40, 1193 >> 8);
    idt_set(32, (void*)hal_tikshandelr, counterstrike);
    asm volatile("sti");
}

