# Relatório do Mini Projecto de Introdução a Computação
#### Realizado por: Marco Domingos, 21901309
#### Nome do grupo: *Nameless Jeff*
---
Este relatório pretende explicar e descrever a solução do problema de construção do programa em *convert.c*. 

## Descrição da solução

---

## Estrutura do software

### **Antes da função _main()_**
> São incluidas as bibliotécas, definidas as mensagens de jogo, e declaradas todas as funções.

### **Função _main()_**
> A primeira parte da função é verificar se o jogador implementou uma *seed* ou não, que irá determinar a utilização da função *srand()* com esta *seed*. Se esta não tiver sido implementada, a função *time()* será utilizada para gerar a tal *seed*.

> Após isto, é inicializada a variável **char _a_**, que irá guardar o input do jogador, e as **int**s *score*, *stage*, e *plays*, que irão quardar a pontuação, o nível, e o número de rondas respetivamente ao longo do jogo.
É imprimido, então, a mensagem de boas-vindas e o menu do jogo.

> Dentro da função main há um loop *while* que irá repetir enquanto o input do jogador é diferente de *q*, ou quando este ganha/perde o jogo. Foi utilizada a função *getch()*, atribuida à variável *int a*,para escanear o *input* do usuário.

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
> Obtém os ponteiros de dois **int**s *a* e *b*, e muda o valor de *b* consoante o valor de *a*. É utilizada para trocar o valor do nível consoante o valor dos pontos do jogador.

### **Função _random number level()_**
> Utiliza um *switch case* e recebe um valor **int** *level*, retornando um número randómico dependendo do valor de *level* (1-5). O valor randómico retornado chama a função *rand_number()*, com os valores inseridos na função sendo aqueles presentes na tabela do enunciado deste projecto.

### **Função _print status()_**
> Função incluida no código base. Recebe 3 **const int**, *level*, *score* e *plays*, e imprime uma tabela que demonstra estes valores para o jogador.

### **Função _print menu()_**
> Função incluida no código base. Não recebe e nem devolve nada (void), e apenas imprime a tabela de opções do jogo.

### **Função _challenge()_**

---

## Conclusões e matéria aprendida

---

## Referências

