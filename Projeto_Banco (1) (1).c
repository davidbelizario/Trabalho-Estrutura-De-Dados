//nome: David Belizario Rodrigues � prontu�rio: gu3011631 � Turma: ADS2�SEM.

//nome: Felipe Saldanha de Souza � prontu�rio: gu3011801 � Turma: ADS2�SEM.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Bibliotecas b�sicas de C + a de string(string.h), que vai servir para a manipula��o de strings.
 typedef struct conta{
        int id;
        char nome[30];
        char tipo[15];
        float saldo;
}CONTA;
//-------------------------------
/*
Cria��o da estrutura conta com o tipo sendo definido como 'CONTA',
Tal possui 3 variav�is:
'nome' do tipo char suportando 30 caracteres.
'tipo' do tipo char suportando 15 caracteres.
'saldo' do tipo float.

Essa estrutura ir� ser o alicerce do c�digo, sendo o corpo de todos os dados que v�o entrar.
*/
//-------------------------------
CONTA *alocaMemoria(int n){
CONTA *vetor;
vetor = (CONTA*) malloc (n * sizeof(CONTA));
if (vetor == NULL){
    printf("ERRO: sem mem�ria;");
    exit(1);

}
}
//-------------------------------
/*
Fun��o *alocaMemoria tem como par�metro int 'n' que ditar� o tamanho da aloca��o din�mica na mem�ria
Dentro da fun��o � declarado o ponteiro 'vetor' do tipo CONTA, que ser� o ponteiro que ser� usado pelo c�digo todo.
� feita a fun��o malloc encima desse 'vetor', levando como par�metro o n (tamanho) e o sizeof('tamanho de' em quest�o de bytes) do tipo 'CONTA'.
Existe a condi��o de caso o 'vetor' retorne do malloc vazio, nesse caso � um problema de falta de mem�ria, o programa ser� fechado pelo exit(1).
*/
//-------------------------------
 CONTA coletaDados(){
    CONTA cont;
    printf("Informe o no. da conta: ");
    scanf("%d", &cont.id);
    printf("Informe o nome da conta: ");
    getchar();
    gets(cont.nome);
    printf("Informe o tipo da conta: ");
    gets(cont.tipo);
    printf("Informe o saldo da conta: ");
    scanf("%f", &cont.saldo);
    return cont;
}
//-------------------------------
/*
Fun��o coletaDados criada sem par�metro para conseguir os valores de cada vari�vel da estrutura conta.
� criado uma vari�vel do tipo CONTA que ir� armazenar, para retornar, os valores dos atributos de CONTA.
� usado comandos como scanf(), printf() e gets() para orientar e extrair os valores inseridos.
*/
//-------------------------------
 void imprimeConta(CONTA *vet, int n){
    int i;
    printf("\t**** CONTAS BANCARIAS *****\n\n");
    for(i = 0; i < n; i++){
        printf("Codigo de identificacao: %d\n", vet[i].id);
        printf("Nome do cliente: %s\n", vet[i].nome);
        printf("Tipo de conta: %s\n", vet[i].tipo);
        printf("Saldo na conta: %.2f\n", vet[i].saldo);
        printf("\n\n");
    }
    printf("\n\n\n\n");
    system("pause");

}
//-------------------------------
/*
Fun��o sem retorno imprimeConta, tem como par�metros o ponteiro 'vet' do tipo CONTA e n do tipo inteiro.
Servir� para imprimir no console os valores dos atributos de CONTA vet da posi��o n.
Por existir um for repetindo at� chegar perto de n, n ser� atualizado e assim a impress�o tamb�m, imprimindo todos os valores de CONTA vet.
Apos imprimir todos os atributos do CONTA vet, o sistema ser� pausado para a visualiza��o dos valores.
*/
//-------------------------------

int main(){
    int i, n;
    FILE *arq;

printf("Digite a quantidade de contas a ser gerenciada pelo software:");
scanf("%d", &n);

CONTA *vet = alocaMemoria(n);

 for(i = 0; i < n; i++){
        vet[i] = coletaDados();
        system("cls");
}
 imprimeConta(vet, n);


arq = fopen("ArqBin.bin", "wb");

fwrite(vet,sizeof(CONTA),n, arq);
fclose(arq);

free(vet);

system("pause");
return (0);
}
//-------------------------------
/*
O main() ser� respons�vel por:
1.Declarar as variav�is i e n do tipo inteiro, onde i servir� para ser usado como contador no for seguinte e n para determinar o numero de CONTAs que ser�o criadas, al�m de declarar o ponteiro 'arq' do tipo FILE que servir� para executar a fun��o de escrita no arquivo ArqBin;
2.Exigir o valor de 'n';
3.Chamar o alocaMemoria com o par�metro n para determinar certas posi��es na mem�ria e entregar esse endere�o para o ponteiro CONTA '*vet';
4.Declarar o for que ir� coletar todos os dados dos n CONTAs declarados, isso a partir da fun��o coletaDados, e que limpar� a tela a cada inser��o para n�o poluir a visualiza��o;
5.Chamar a fun��o imprimeConta com os par�metros vet e n, para executar uma impress�o na tela de todos os valores de CONTA.
6.Preencher o ponteiro arq com a fun��o fopen, que vai abrir o arquivo bin�rio ArqBin.bin para escrita de forma bin�ria.
7.Convocar a fun��o fwrite para escrever no arquivo ArqBin.bin todos os CONTAS declarados.
8.Convocar a fun��o fclose com o param�ro arq para proteger o arquivo depois da altera��o.
9.Convocar a fun��o free() com o param�ro vet para limpar o espa�o na mem�ria usado por esse ponteiro.
*/
//-------------------------------
