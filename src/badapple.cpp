// Bad Apple designed for SleemOS x86_64
// credits: v3x (credits for software used outside this file in other files)

#include "../include/badapple_frames.h"
#include "../include/kernel.h"
#include "../include/shal.h"




void badappl() {
    int censored5milion = 0;
for (int frejm = 0; frejm < 120; frejm++) {
    uint32_t censored3 = tiks;
    for (censored5milion = 0; censored5milion < 64; censored5milion++) {
    for (int lemonih = 0; lemonih < 8; lemonih++) {
    if ((badapple_bin[(frejm * 64) + censored5milion] & (0x80 >> lemonih)) != 0)
        uartcharacterplacement("##");
    if ((badapple_bin[(frejm * 64) + censored5milion] & (0x80 >> lemonih)) == 0) {
        uartcharacterplacement("  ");
    }
}
if ((censored5milion + 1) % 4 == 0) {
uartcharacterplacement("\r\n");

}
}

while ((tiks - censored3) < 125) {
}
if(frejm < 119) {
hal_cursoringsuppings(16);
}


    }
    readindia = writeindia;

}
