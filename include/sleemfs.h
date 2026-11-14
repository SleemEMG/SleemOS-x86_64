#pragma once
#include <stdint.h>

int findshit(const char* forfindingshit);
int createshit(const char* shitforcreating);
void listshit(int modesssst);
int writeshit();
void checkif();
void saveshit();
void loadshit();
int readshit();
int removeshit();
void hexshitdump();
struct filings {
    char namings[52];
    uint32_t firstchicken;
    uint32_t sizeofdoomscroll;
    uint8_t ifusedornotused;
    uint8_t paddingshit[3]; // rip to the old file array sure will miss you mate
}; 
extern filings shit[15];
extern int nameofshit;
extern int forwritingshit;
extern int forremovingshit;
extern int forlistingshit;
extern int forhexdumpingshit;

struct superblocking {
    char magik[8];
    uint32_t versioning;
    uint32_t sectoringtotalling;
    uint32_t startoftable;
    uint32_t theentries;
    uint32_t thesectors;
    uint32_t humancentipede;
    uint32_t humancentipedesectors;
    uint32_t startofdata;
    uint32_t blocksofdata;
    uint8_t paddingshit[468];
}
__attribute__((packed));