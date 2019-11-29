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
void challenge(int *, int *, int *);
int rand_number_level(int);
void level_status(int *, int *);


int main()
{
	//'a' é a variável que decide que comando o usuário põe.
	char a;
	int score = 0, stage = 1, plays = 0;

	puts(MSG_WELCOME);
	print_menu();

	while(1){

		// Verifica se o nível é igual a 6, e caso for, mostra uma mensagem de que o jogador ganhou o jogo e termina o programa.
		if (stage == 6){
			puts(MSG_WIN);
			break;
		}

		// Verifica se o número de rondas é maior do que 30, e caso for, mostra uma mensagem que o jogador chegou a o limite de jogadas e termina o programa.
		if (plays > 30){
			puts(MSG_MAX);
			print_status(stage, score, plays);
			break;
		}

		// Verifica o input primário do jogador.
		a = getch();
		printf("%c\n", a);
		/*scanf("%s", &a);

		// Arruma o input do jogador para apenas verificar o primeiro input da letra.
		for (int g = 0; a[g] != "\0"; g++){
			if (a[g] == ' '){
				*a = &a[g];
			}
			else {
				a[g+1] = '\0';
				break;
			}
		} 

		printf("%s", a); */

		if (a == 'p'){
			challenge(&score, &stage, &plays);
			level_status(&score, &stage);
			continue;
		}

		else if (a == 'm'){
			print_menu();
			continue;
		}

		else if (a == 's'){
			print_status(stage, score, plays);
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

	puts(MSG_OVER);
	return 0;
}

/* Gera uma integral random entre min e max */
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
void challenge (int * points, int * level, int * rounds){

	// Cria os números randómicos que irão ser propostos ao jogador.
	int game_number[4] = {
		random_number_level(*level), 
		random_number_level(*level), 
		random_number_level(*level), 
		random_number_level(*level)  
	};

	// Vetor inicializado para ser trocado pelos inputs do jogador.
	int player_answer[4];

	puts(MSG_SORT);

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

	// Um if que verifica se um dos números do jogador não está em game_number, e após isto dá outra possibilidade do jogador modificar a resposta.
	if ((player_answer[0] != game_number[0] && player_answer[0] != game_number[1] && player_answer[0] != game_number[2] && player_answer[0] != game_number[3]) 
	|| (player_answer[1] != game_number[0] && player_answer[1] != game_number[1] &&  player_answer[1] != game_number[2] && player_answer[1] != game_number[3]) 
	|| (player_answer[2] != game_number[0] && player_answer[2] != game_number[1] && player_answer[2] != game_number[2] && player_answer[2] != game_number[3]) 
	|| (player_answer[3] != game_number[0] && player_answer[3] != game_number[1] && player_answer[3] != game_number[2] && player_answer[3] != game_number[3])){
		puts(MSG_SORT2);
		scanf("%d %d %d %d", &player_answer[0], &player_answer[1], &player_answer[2], &player_answer[3]);
	}

	// Verifica se o jogador respondeu corretamente.
	if (player_answer[0] == game_number[0] && player_answer[1] == game_number[1] && player_answer[2] == game_number[2] && player_answer[3] == game_number[3]){
		puts(MSG_WELL);
		*points += 5;
		*rounds += 1;
		return;
	}

	// Else para verificar caso o jogador erre a mensagem.
	else {
		puts(MSG_WRONG);
		*rounds += 1;
		return;
	}
}

/* Função que atualiza o nível consoante os pontos*/
void level_status(int * a, int * b){
	if (*a < 10) {
		*b = 1;
	}
	
	else if (*a >= 10 && *a < 20){
		*b = 2;
	}

	else if (*a >= 20 && *a < 30){
		*b = 3;
	}

	else if (*a >= 30 && *a < 40){
		*b = 4;
	}

	else if (*a >= 40 && *a < 50){
		*b = 5;
	}

	else if (*a >= 50 && *a < 60){
		*b = 5;
	}

	else if (*a >= 60){
		*b = 6; 
	}

	return;
}

/* Imprime o número randómico de um nível específico */
int random_number_level(int level){
	switch (level){
		case 1:
			return rand_number(0, 10);
		case 2:
			return rand_number(0, 30);
		case 3:
			return rand_number(-50, 10);
		case 4:
			return rand_number(-100, 0);
		case 5:
			return rand_number(-200, -100);
	}
	return 0;
}
/* Imprime o estado atual do jogo */
void print_status(const int level, const int score, const int plays)
{
	puts("+-----------------------------+");
	printf("| level:  %02d                  |\n", level);
	printf("| points: %02d                  |\n", score);
	printf("| plays:  %02d                  |\n", plays);
	puts("+-----------------------------+");
}

/* Imprime o menu de opções */
void print_menu()
{
	puts("+-----------------------------+");
	puts("| SORTIFY                     |");
	puts("| p - next challenge          |");
	puts("| q - quit                    |");
	puts("| m - print this information  |");
	puts("| s - show your status        |");
	puts("+-----------------------------+");
}