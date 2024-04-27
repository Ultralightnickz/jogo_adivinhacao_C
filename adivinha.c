#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("**********************************\n");
    printf("*Bem vindo ao jogo de adivinhação*\n");
    printf("**********************************\n");

    int segundos = time(0); // função que devolve o num de segundos passados desde 01/01/70
    srand(segundos);
    int numeromaximo = 100;
    int numerosecreto = (rand() % numeromaximo) + 1; //porcentagem traz apenas o resto da divisão
    int chute = 0;
    int tentativas = 1;

    double pontos = 1000;

    int nivel;
    printf("Qual é o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int limitetentativas;
    if(nivel == 1) {
        limitetentativas = 12;
    } 
    else if(nivel == 2) {
        limitetentativas = 8;
    }
    else {
        limitetentativas = 5;
    }

    printf("Adivinhe o número entre 1 e %d.\n", numeromaximo);

    while (tentativas <= limitetentativas) {

        printf("Tentativa %d de %d.\n", tentativas, limitetentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d.\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }
        else if(chute == numerosecreto) {
            break;
        }
        else if(chute > numerosecreto) {
            printf("Você errou.\n O número secreto é menor que %d.\n", chute);
        }
        else {
            printf("Você errou.\n O número secreto é maior que %d.\n", chute);
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
printf("Fim de jogo!\n");
if(chute == numerosecreto) {
    printf("Parabéns! Você acertou!\n O número secreto é %d!\n", chute);
        if(tentativas == 1) {
            printf("Você acertou em %d tentativa!\n", tentativas);
        } else {
            printf("Você acertou em %d tentativas!\n", tentativas);
        }
    printf("Total de pontos: %.2f\n", pontos);
}
else {
    printf("Você perdeu! Acabaram as tentativas!\n");
    printf("Tente de novo!");
}
return 0;
}