# Relatório do Mini Projecto de Introdução a Computação
#### Realizado por: Marco Domingos, 21901309
#### Nome do grupo: *Nameless Jeff*
---
Este relatório pretende explicar e descrever a solução do problema de construção do programa em *convert.c*. 

## Descrição da solução
> Para iniciar a solução, foram iniciadas as variáveis *score*, *stage*, e *plays*. Estas irão tratas da pontuação, dos níveis, e do número de rondas respetivamente. 
Dentro de um ciclo *while()*, que permeia a função *main()*. Toda vez que o ciclo *while* é quebrado, este mostra a mensagem **"Game Over."**, e com excessão do branch *if* do *input* 'q', (que demonstra a mensagem **"Bye"** e depois utiliza a função *exit(0)*) todas as funções que quebram o ciclo têm **"Game Over"** após. As primeiras verificações são feitas por *if*s, uma que vê se o nível do jogador é 6 (terminando assim o jogo, sendo o nível limite 5), e outra que observa se o número de rondas do jogador é maior do que 30, imprimindo a *MSG_MAX* e terminando também o jogo. Após isto a introdução **"WELCOME TO SORTIFY!"** é imprimida junto com o menu, escaneando após isto uma **char** que o jogador irá digitar, e comparando esta char com vários *if*s e *else if*s para determinar o input correto que o jogador fez.

> Existem múltiplas funções que existem com o propósito de cumprir metas da solução, por exemplo: 
A função *level_status()* irá receber os pontos atuais do jogador e o ponteiro do seu nível atual, e através de um conjunto de *if*s e *else if*s, irá mudar o valor do nível consoante a esses pontos. Esta função é sempre chamada após a função *challenge()*, que irá modificar os pontos.
Ainda em tópico, a função *challenge()* irá receber um ponteiro de *score*, um **int** de *stage*, e outro ponteiro de *plays*. Esta irá inicializar um vetor com números aleatórios (que irá chamar outra função para cada um dos quatro números aleatórios, a *random_number_level()*) e irá ordená-los com um ciclo duplo *for*. verificará, então, se o input do jogador condiz com o vetor ordenado, e no caso do jogador acertar, irá iterar 5 pontos à *score* e 1 ponto à *plays*, terminando assim o programa. No caso do jogador errar, este apenas itera 1 ponto à *plays*
A última função de grande relevância, a *random_number_level()*, irá, como já escrito mais acima, receber o valor do nível, e com um *switch case* determinar o número mínimo e máximo que deve retornar dentro da função *rand_number()*, mudando assim a *range* de números que irá ser apresentado ao jogador de acordo com o nível.
---

## Estrutura do software

### **Antes da função _main()_**
> São incluidas as bibliotécas, definidas as mensagens de jogo, e declaradas todas as funções.

### **Função _main()_**
> A primeira parte da função é verificar se o jogador implementou uma *seed* ou não, que irá determinar a utilização da função *srand()* com esta *seed*. Se esta não tiver sido implementada, a função *time()* será utilizada para gerar a tal *seed*.

> Após isto, é inicializada a variável **char _a_**, que irá guardar o input do jogador, e as **int**s *score*, *stage*, e *plays*, que irão quardar a pontuação, o nível, e o número de rondas respetivamente ao longo do jogo.
É imprimido, então, a mensagem de boas-vindas e o menu do jogo.

> Dentro da função main há um loop *while* que irá repetir enquanto o input do jogador é diferente de *q*, ou quando este ganha/perde o jogo. Foi utilizada a função *scanf()*, atribuida à variável *int a*,para escanear o *input* do usuário.

> Após isto, foram utilizados *if*s, *else if*s e um *else* para igualar o input do jogador a várias funções.

#### *_Input_ p*
> O *input* p leva o jogador a um *if* que adentra à função *challenge()*, que irá realizar uma ronda de jogo, e depois à função *level_status*, que irá atualizar ou não o nível consoante aos pontos do jogador. São dados os valores de memória das variáveis *score*, *stage* e *plays* para serem utilizados ponteiros em ambas as funções, com o intuito de modificar as variáveis em sí.

#### *_Input_ m*
> O *input* m irá chamar novamente a função *print_menu()* e irá demonstrar o menu para o jogador.

#### *_Input_ s*
> Irá chamar a função *print_status()*, com as variáveis *score*, *stage* e *plays*, para demonstrar numa tabela os vários *stats* do jogador.

#### *_Input_ q*
> Irá imprimir uma mensagem que diz adeus ao jogador, e fecha então o programa.

#### *_Unknown Input_*
> Caso o *input* do jogador não seja nenhum daqueles referidos acima, o programa imprime uma mensagem com *"Unknown input"*.

### **Função _rand number()_**
> Função incluida no código base. Recebe dois números (mínimo e máximo) e devolve um número aleatório entre eles. Utiliza a função *rand()*, que foi dada uma *seed* no inicio do programa com a função *srand()*.

### **Função _level status()_**
> Obtém um **int** *a* e o ponteiro de um **int** *b*, e muda o valor de *b* consoante o valor de *a*. É utilizada para trocar o valor do nível consoante o valor dos pontos do jogador.

### **Função _random number level()_**
> Utiliza um *switch case* e recebe um valor **int** *level*, retornando um número randómico dependendo do valor de *level* (1-5). O valor randómico retornado chama a função *rand_number()*, com os valores inseridos na função sendo aqueles presentes na tabela do enunciado deste projecto.

### **Função _print status()_**
> Função incluida no código base. Recebe 3 **const int**, *level*, *score* e *plays*, e imprime uma tabela que demonstra estes valores para o jogador.

### **Função _print menu()_**
> Função incluida no código base. Não recebe e nem devolve nada (void), e apenas imprime a tabela de opções do jogo.

### **Função _challenge()_**
> Função crucial do programa. Esta irá receber dois ponteiros **int** (de *score* e *plays*) e uma **int** de *stage*, e irá utilizar *stage*, o nível do jogo, para decidir a *range* mínima e máxima de números randómicos que adiciona ao vetor *game_number*, com 4 elementos. Após isto, é inicializado o vetor *player_number*, também com 4 elementos, que irá ser utilizado mais a frente para verificar se a resposta do jogador é igual ao de *game_number* ordenado. O jogo imprime uma mensagem pedido para o jogador ordenar os números em *game_number*. 
É, então, imprimido o vetor *game_number* desordenado, e feito um ciclo duplo *for* (isto é, *for* dentro de um *for*).

> O ciclo mais interno irá observar se o elemento seguinte daquele que irá ser iterado é maior do que ele, e se for, irá trocar a órdem dos dois no vetor (ou seja, *j* transforma-se em *j+1* e vice-versa), repetindo este processo quatro vezes para cobrir todo o vetor.

> O ciclo mais externo irá fazer com que o ciclo interno se repita quatro vezes, para no caso de o menor número estar no final da lista, este ser trocado com o anterior vezes suficientes para ficar corretamente ordenado.

> Quando o vetor *game_number* já foi ordenado, o programa irá pedir o input do jogador com um *scanf()*, e guardar a sua resposta no vetor *player_number()*. Após isto um *if* irá verificar se um/múltiplos dos valores que o jogador digitou não estão presentes no vetor *game_number*, e se este for o caso, irá pedir para este ordenar os números novamente. Um outro *if*, então, irá verificar se todos os valores do vetor *player_number* são iguais aos valores de *game_number*. Se isto for verídico, o programa imprime uma mensagem de congratulação, e itera os pontos do jogador e as rondas do jogador, retornando assim. Caso contrário, no *else*, este imprime uma mensagem a dizer que o jogador falhou, e apenas itera as rondas, sem mexer nos pontos, retornando assim.

---

## Conclusões e matéria aprendida
> A construção deste programa foi feita em, aproximadamente, um dia. Com revisões aqui e ali, fico feliz com o resultado do programa (tirando certas excessões como alguns *if*s presentes na função *challenge()*), e acredito que a realização deste programa tenha adicionado ao meu conhecimento de funções, ciclos, e o mais importante, ponteiros, o conceito que mais fez-me pensar enquanto trabalhava nisto.
Acredito que o processo de *debugging* e a otimização parcial do código adicinou também ao meu conhecimento, assim como os *commits* feitos no git, e a passagem destes para o repositório remoto do *GitHub*.

---

## Referências
> As bibliotecas utilizadas neste código foram: *stdio.h*, *stdlib.h*, *math.h*, *time.h*, e *conio.h*. A ideia do código para a ordenação do vetor de números randómicos foi parcialmente retirada de uma discussão com o colega Daniel Fernandes do curso de *Videojogos* no primeiro ano da Universidade Lusófona, e de uma das questões finais do primeiro teste da UC de *Fundamentos de Programação*, lecionado pelo professor Diogo Andrade também da Universidade Lusófona.
Também gostaria de agradecer ao colega (da mesma Universidade) Pedro Dias Marques, que deu-me dicas sobre a utilização da função *scanf()* para a retirada do input inicial do jogador no menu principal.