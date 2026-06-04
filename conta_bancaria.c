#include <stdio.h>
#include <string.h>

// Conceito: Struct (Estrutura de Dados)
// Agrupa variaveis de tipos diferentes sob um mesmo nome, mas NÃO possui métodos/funções dentro dela
typedef struct {
    char titular[50];
    int numero;
    float saldo;
} Conta;

// Conceito: funções com passagem de parâmetros por ponteiro
// Usamos o operador '*' para receber o endereço da memória da struct
// Isso permite que as alterações feitas aqui persistam fora da função

void depositar(Conta *c, float valor) {
    if (valor > 0) {
        c->saldo += valor; // O operador '->' é usado para acessar campos de um ponteiro 
        printf("Deposito de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Valor de deposito inválido!\n");
    }
}

// Conceito: Controle de fluxo (if/else) para validação de regras de negócio

void sacar(Conta *c, float valor) {
    if (valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
}

// Usamos 'const' para garantir que esta função apenas LEIA os dados, sem alterá-los

void exibirExtrato(const Conta *c) {
    printf("\n=== Extrato bancario ===\n");
    printf("Titular: %s\n", c->titular);
    printf("conta numero: %d\n", c->numero);
    printf("Saldo Atual: R$ %.2f\n", c->saldo);
}

//Inicialização da struct Conta
int main() {
    Conta minhaConta;
    strcpy(minhaConta.titular, "Fulano de Tal");
    minhaConta.numero = 123456;
    minhaConta.saldo = 500.00; //Saldo inicial

// CONCEITO: Controle de fluxo (loop do-while) para o Menu Principal
    int opcao;
    float valor;

    do {
        printf("\n--- Menu BANCO C ---\n");
        printf("1. Depositar\n");
        printf("2. Sacar;\n");
        printf("3. Exibir Extrato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);
    
        
// Conceito: Conrole de fluxo (switch-case) para direcionar a escolha do usuário
        switch (opcao) {   
            case 1:
                printf("Digite o valor a ser depositado:\n");
                scanf("%f", &valor);

                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor do saque:\n");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                exibirExtrato(&minhaConta);
                break;
            case 0:
                printf("Saindo do sistema... Ate logo!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente!\n");
        }
    }while (opcao != 0);

    return 0;
}