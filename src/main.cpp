#include <xc.h>

#pragma config FPLLIDIV=DIV_2
#pragma config FPLLMUL=MUL_20
#pragma config FPLLODIV=DIV_2
#pragma config FNOSC=FRCPLL
#pragma config FSOSCEN=OFF
#pragma config IESO=OFF
#pragma config FPBDIV=DIV_1
#pragma config FWDTEN=OFF
#pragma config JTAGEN=OFF



int main() {
	ANSELA = ANSELB = 0;
	TRISA = 0b1000; // RA3 is input
	TRISB = 0b100; // RB2 is input
	LATA = LATB = 0;
        
    while (1) {
        
    }
}
