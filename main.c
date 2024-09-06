//includes
#include <avr/io.h>
#include "Display.h"
#include "Timer1.h"

//defines
#define TEXTLAENGE 66

//Deklaration von Variablen
unsigned char ucNamenZaehler = 0;
unsigned char ucDankeZaehler = 0;
unsigned char ucNamen[66] = "Anastasia, Ariana, Daniel, Eva, Ferdinand, Hannah, Irem, Johannes, ";
unsigned char ucSIA[16] = " SIA 2023/2024  ";
unsigned char ucDanke[16] = "  Vielen Dank!  ";

void Texte(void);

int main(void)
{
	Display_Init();
	Timer1_Init();
	while (1)
	{
		if(Timer1_get_500msState() == TIMER_TRIGGERED){
			if (ucNamenZaehler == TEXTLAENGE){
				ucNamenZaehler = 0;
			}
			if(ucDankeZaehler == 20){
				ucDankeZaehler = 0;
			}
			Texte();
		}
	}
}

void Texte(void){
	Display_SetCursor(1, 0);
	for(unsigned char i = 0; i <= 16; i++){
		if (ucNamenZaehler + i + 1 <= TEXTLAENGE){
			Display_Write(ucNamen[ucNamenZaehler + i]);
			}else{
			Display_Write(ucNamen[ucNamenZaehler + i - TEXTLAENGE]);
		}
	}
	ucNamenZaehler++;
	
	if((ucDankeZaehler % 10) == 0){
		Display_SetCursor(0, 0);
		if(ucDankeZaehler == 0){
			Display_Print(ucSIA, 16);
		}
		if(ucDankeZaehler == 10){
			Display_Print(ucDanke, 16);
		}
	}
	ucDankeZaehler++;
	
	Display_SetCursor(0, 16);
}