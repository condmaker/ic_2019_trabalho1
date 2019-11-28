#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MSG_WELCOME "WELCOME TO SORTIFY!"
#define MSG_SORT "Sort the following numbers:"
#define MSG_SORT2 "Please sort the numbers"
#define MSG_WELL "Well done!"
#define MSG_WIN "Congratulations, you win!"
#define MSG_OVER "Game Over."
#define MSG_WRONG "Wrong answer."
#define MSG_MAX "You have reached the maximum number of moves."
#define MSG_BYE "Bye."
#define MSG_UNKNOWN "Unknown option."
/* Use puts() to print constant strings */

int rand_number(const int, const int);
void print_status(const int, const int, const int);
void print_menu(void);
void challenge(void);


int main()
{
	puts(MSG_WELCOME);
	print_menu();

	while(1){

		/* 'a' is the variable that decides what command the user inputs*/
		char a;

		scanf("%c/n", &a);

		if (a == 'p'){
			/* Has no arguments but is supposed to have: points, level, coiso*/
			challenge();
			continue;
		}

		else if (a == 'm'){
			print_menu();
			continue;
		}

		else if (a == 's'){
			/* Comentário abaixo para não lixar o código*/
			/*print_status(level, score, plays);*/
			continue;

		}

		else if (a == 'q'){
			puts(MSG_BYE);
			break;
		}

		else{
			puts(MSG_UNKNOWN);
			continue;
		}

	}
	return 0;
}

/* generate a random integer between min and max */
int rand_number(const int min, const int max)
{
	if (max < min)
	{
		puts("Max must be larger than Min");
		exit(0);
	}
	int n = abs(max - min) + 1;
	return (rand() % n) + min;
}

/* Recebe points, level, rounds*/ 
void challenge (void){

	// Cria os números randómicos que irão ser propostos ao jogador
	int game_number[4] = {
		rand_number(0, 10), // 4
		rand_number(0, 10), // 8
		rand_number(0, 10), // 9
		rand_number(0, 10)  // 3
	};

	int player_answer[4];

	puts(MSG_SORT"\n");

	// Mostra os números randómicos ao jogador.
	printf("%d, %d, %d, %d\n", game_number[0], game_number[1], game_number[2], game_number[3]); 

	/*  Estes dois ciclos for irão percorrer cada um dos números em game_number e trocar o número seguinte pelo outro se o tal seguinte for menor.  
		No fim do ciclo, o vetor game_number irá estar completamente ordenado.                                                                     */
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (game_number[j] > game_number [j+1]){
				int carry = game_number[j];
				game_number[j] = game_number[j+1];
				game_number[j+1] = carry;
			}
		}
	}
	
	// Este scanf guarda o input do jogador no vetor player_answer, que foi decalarada acima.
	scanf("%d %d %d %d", &player_answer[0], &player_answer[1], &player_answer[2], &player_answer[3]);

	if (player_answer[0] == game_number[0] && player_answer[1] == game_number[1] && player_answer[2] == game_number[2] && player_answer[3] == game_number[3]){
		puts(MSG_WELL"\n");
		return;
	}

	// Fazer um else if que verifique se um dos números do jogador não está em game_number

	else {
		puts(MSG_WRONG"\n");
		return;
	}
}

/* print the game status */
void print_status(const int level, const int score, const int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* print the option menu */
void print_menu()
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}