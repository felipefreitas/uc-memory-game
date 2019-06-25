#include<xc.h>

#define _XTAL_FREQ 20000000      // 20MHz necessário para as funções de delay

// LEDS CONFIG
#define LED_0   PORTDbits.RD0
#define LED_1   PORTDbits.RD1
#define LED_2   PORTDbits.RD2
#define LED_3   PORTDbits.RD3
#define LED_4   PORTDbits.RD4
#define LED_5   PORTDbits.RD5
#define LED_6   PORTDbits.RD6
#define LED_7   PORTDbits.RD7
#define LED_DELAY   100

// BITS DE CONFIGURAÇÃO
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HS
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config MCLRE = ON
#pragma config PWRT = ON

void leds_loading_game();
void leds_win_game();
void leds_lose_game();

int main(void) {

    //CONFIGURANDO os PINOS D como saida:
    // pin mode: 0 = saída, 1 = entrada
    //(obs. notacao para binario/ configurando o registrador TRIS D)
    TRISD = 0b00000000;

    // -- Escrevendo "0" em todas as saidas (nivel baixo
    // todos os pinos iniciam em nivel baixo
    // (obs, notacao para hexa/ configurando o registrador PORT Dinteiro))
    PORTD = 0x00; // 0b 0000 0000

    // --- LOOP infinito: roda a rotina principal
    while (1) {
        leds_lose_game();
    }

    return 0;
}

/*  This method should be called every start or restart game waiting
*   for user push the button to start.
*/
void leds_loading_game() {
    LED_0 = 1;
    LED_3 = 0;
    __delay_ms(LED_DELAY);
    LED_1 = 1;
    LED_4 = 0;
    __delay_ms(LED_DELAY);
    LED_2 = 1;
    LED_5 = 0;
    __delay_ms(LED_DELAY);
    LED_3 = 1;
    LED_6 = 0;
    __delay_ms(LED_DELAY);
    LED_4 = 1;
    LED_7 = 0;
    __delay_ms(LED_DELAY);
    LED_5 = 1;
    LED_0 = 0;
    __delay_ms(LED_DELAY);
    LED_6 = 1;
    LED_1 = 0;
    __delay_ms(LED_DELAY);
    LED_7 = 1;
    LED_2 = 0;
    __delay_ms(LED_DELAY);
}

/*  This method should be called for every user wins memory problem
*/
void leds_win_game() {
    PORTD = 0;
    __delay_ms(LED_DELAY);
    PORTD = 255;
    __delay_ms(LED_DELAY);
}

/*  This method should be called for every user wrong memory problem
*/
void leds_lose_game() {
    LED_0 = 1;
    LED_1 = 0;
    LED_2 = 1;
    LED_3 = 0;
    LED_4 = 1;
    LED_5 = 0;
    LED_6 = 1;
    LED_7 = 0;
    __delay_ms(LED_DELAY);
    LED_0 = 0;
    LED_1 = 1;
    LED_2 = 0;
    LED_3 = 1;
    LED_4 = 0;
    LED_5 = 1;
    LED_6 = 0;
    LED_7 = 1;
    __delay_ms(LED_DELAY);
}
