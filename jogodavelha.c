#include <stdio.h>

char jogo[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'}
};

char jogadoratual = 'X';
char vencedor = 'A';
int fimdejogo = 0;
int jogadas = 0;

void mostrartabuleiro(){
    int i, j;
    printf("\n-----\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c ", jogo[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
}

void alterarjogador(){
    jogadoratual = (jogadoratual=='X') ? 'O':'X';
    /*
    Utilizando o operador ternário
    variável = (condição) ? valor se verdadeiro: valor se falso
    */
}

void fazerjogada(){
    int l, c, erro=0;
    printf("\nVez do jogador %c.\n", jogadoratual);
    do{
        printf("Digite a linha:  ");
        scanf("%d", &l);
        printf("Digite a coluna:  ");
        scanf("%d", &c);

        if(jogo[l][c] != '-'){
            printf("\nEspaco ocupado, digite novamente.\n\n");
            erro = 1;
        }
        else{
            erro = 0;
        }
    }
    while(erro == 1);
    jogo[l][c] = jogadoratual;
    jogadas++;

}

void verificarlinha(){
    int i;
    for(i=0;i<3;i++){
        if(jogo[i][0] == jogadoratual && jogo[i][1] == jogadoratual && jogo[i][2] == jogadoratual){
            vencedor = jogadoratual;
            break;
        }
    }
}
void verificarcoluna(){
    int i;
    for(i=0;i<3;i++){
        if(jogo[0][i] == jogadoratual && jogo[1][i] == jogadoratual && jogo[2][i] == jogadoratual){
            vencedor = jogadoratual;
            break;
        }
    }
}

void verificardiagonal(){
    if(jogo[0][0] == jogadoratual && jogo[1][1] == jogadoratual && jogo[2][2] == jogadoratual){
        vencedor = jogadoratual;
    }
    else if(jogo[2][0] == jogadoratual && jogo[1][1] == jogadoratual && jogo[0][2] == jogadoratual){
        vencedor = jogadoratual;
    }
}

void verificarvencedor(){
    verificarcoluna();
    verificarlinha();
    verificardiagonal();

    if(vencedor == 'X' || vencedor == 'O'){
        printf("\nO vencendor eh o %c!!!", vencedor);
        fimdejogo = 1;
    }
    else if(jogadas == 9){
        printf("Empate!!!");
        fimdejogo = 1;
    }
}

int main(){
    while(fimdejogo == 0){
        mostrartabuleiro();
        fazerjogada();
        verificarvencedor();
        alterarjogador();
    }

    return 0;
}

