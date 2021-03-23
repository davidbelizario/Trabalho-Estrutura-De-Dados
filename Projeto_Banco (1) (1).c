//nome: David Belizario Rodrigues – prontuário: gu3011631 – Turma: ADS2ºSEM.

//nome: Felipe Saldanha de Souza – prontuário: gu3011801 – Turma: ADS2ºSEM.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Bibliotecas básicas de C + a de string(string.h), que vai servir para a manipulação de strings.
 typedef struct conta{
        int id;
        char nome[30];
        char tipo[15];
        float saldo;
}CONTA;
//-------------------------------
/*
Criação da estrutura conta com o tipo sendo definido como 'CONTA',
Tal possui 3 variavéis:
'nome' do tipo char suportando 30 caracteres.
'tipo' do tipo char suportando 15 caracteres.
'saldo' do tipo float.

Essa estrutura irá ser o alicerce do código, sendo o corpo de todos os dados que vão entrar.
*/
//-------------------------------
CONTA *alocaMemoria(int n){
CONTA *vetor;
vetor = (CONTA*) malloc (n * sizeof(CONTA));
if (vetor == NULL){
    printf("ERRO: sem memória;");
    exit(1);

}
}
//-------------------------------
/*
Função *alocaMemoria tem como parâmetro int 'n' que ditará o tamanho da alocação dinâmica na memória
Dentro da função é declarado o ponteiro 'vetor' do tipo CONTA, que será o ponteiro que será usado pelo código todo.
É feita a função malloc encima desse 'vetor', levando como parâmetro o n (tamanho) e o sizeof('tamanho de' em questão de bytes) do tipo 'CONTA'.
Existe a condição de caso o 'vetor' retorne do malloc vazio, nesse caso é um problema de falta de memória, o programa será fechado pelo exit(1).
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
Função coletaDados criada sem parâmetro para conseguir os valores de cada variável da estrutura conta.
É criado uma variável do tipo CONTA que irá armazenar, para retornar, os valores dos atributos de CONTA.
É usado comandos como scanf(), printf() e gets() para orientar e extrair os valores inseridos.
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
Função sem retorno imprimeConta, tem como parâmetros o ponteiro 'vet' do tipo CONTA e n do tipo inteiro.
Servirá para imprimir no console os valores dos atributos de CONTA vet da posição n.
Por existir um for repetindo até chegar perto de n, n será atualizado e assim a impressão também, imprimindo todos os valores de CONTA vet.
Apos imprimir todos os atributos do CONTA vet, o sistema será pausado para a visualização dos valores.
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
O main() será responsável por:
1.Declarar as variavéis i e n do tipo inteiro, onde i servirá para ser usado como contador no for seguinte e n para determinar o numero de CONTAs que serão criadas, além de declarar o ponteiro 'arq' do tipo FILE que servirá para executar a função de escrita no arquivo ArqBin;
2.Exigir o valor de 'n';
3.Chamar o alocaMemoria com o parâmetro n para determinar certas posições na memória e entregar esse endereço para o ponteiro CONTA '*vet';
4.Declarar o for que irá coletar todos os dados dos n CONTAs declarados, isso a partir da função coletaDados, e que limpará a tela a cada inserção para não poluir a visualização;
5.Chamar a função imprimeConta com os parâmetros vet e n, para executar uma impressão na tela de todos os valores de CONTA.
6.Preencher o ponteiro arq com a função fopen, que vai abrir o arquivo binário ArqBin.bin para escrita de forma binária.
7.Convocar a função fwrite para escrever no arquivo ArqBin.bin todos os CONTAS declarados.
8.Convocar a função fclose com o paramêro arq para proteger o arquivo depois da alteração.
9.Convocar a função free() com o paramêro vet para limpar o espaço na memória usado por esse ponteiro.
*/
//-------------------------------
