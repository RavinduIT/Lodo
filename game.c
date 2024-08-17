#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"
#include "types.h"

int main () {
	int piece;
	int CurrentRoll;
	srand(time(0));

	SetValues();  // set values to starting point
	intro();
	ChooseFirstPlayer();

	for(int k =1;k<=11; k++){
		CurrentRoll = Roll();	
		piece = SelectPiece();		

		if(CurrentRoll == 6){
			CurrentRoll = BaseToBoard(piece);
			if(CurrentRoll = 6){
				piece = SelectPiece();
				CurrentRoll = BaseToBoard(piece);
				if(CurrentRoll == 6){
					CurrentRoll == 0;
				}
			}
		}
		CurrentRoll = CaptureIfCan(Player,piece,CurrentRoll);
		Move(Player,piece,CurrentRoll);
		MakeBlockIfCan();



		Player++;	
		if(Player > 4){
			Player == 1;
		}
	}
	printf("Won the game !!");
    
    return 0;
}
