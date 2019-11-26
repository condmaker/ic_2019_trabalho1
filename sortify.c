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
void challenge(int, int, int);


int main(int argc, char **argv)
{
	puts(MSG_WELCOME);
	puts(print_menu);
	while(1){

		/* 'a' is the variable that decides what command the user inputs*/
		char a;

		scanf("%c", &a);

		if (a == 'p'){
			/* Has no arguments but is supposed to have: points, level, coiso*/
			challenge();
		}

		else if (a == 'm'){
			puts(print_menu);
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

void challenge (void){

	char game_number[4] = {
		rand_number(0, 10),
		rand_number(0, 10),
		rand_number(0, 10),
		rand_number(0, 10)
	};

	for (int j = 0; j < 4; j++){

		char game_number_compare[4];
		int retard_number = INFINITY;
		int index;

		for(int i = 0; i < sizeof(game_number); i++){
			if(game_number[i] < retard_number){
				retard_number = game_number;
				index = i;
			}
		}

		game_number_compare[j] = retard_number;
		game_number[index] = INFINITY;
		
		// printf para Debugging, verificar se está a comparar e a ordenar os números corretamentes
		printf("%s", game_number_compare);
		printf("%s", game_number);
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
void print_menu(void)
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next chalenge           |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}