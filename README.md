# 🏦 Sistema Bancário em C

Sistema de gerenciamento de conta bancária desenvolvido em linguagem C, com funcionalidades de saque, depósito e consulta de extrato por meio de um menu interativo no terminal.

---

## 📌 Sobre o Projeto

O projeto simula operações básicas de uma conta bancária, com foco na aplicação prática de conceitos fundamentais da linguagem C: structs, ponteiros, modularização por funções e controle de fluxo. O código foi escrito com comentários didáticos que explicam cada decisão técnica.

---

## ✅ Funcionalidades

- 💰 **Depositar** — adiciona um valor ao saldo, com validação de valor positivo
- 💸 **Sacar** — retira um valor do saldo, com validação de saldo suficiente
- 📄 **Ver Extrato** — exibe titular, número da conta e saldo atual
- 🔁 **Menu interativo** — loop contínuo até o usuário escolher sair

---

## 🛠️ Como Compilar e Executar

### Pré-requisitos
- GCC instalado ([MinGW](https://www.mingw-w64.org/) no Windows ou nativo no Linux/macOS)

### Passo a passo

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/nome-do-repositorio.git

# Acesse a pasta do projeto
cd nome-do-repositorio

# Compile
gcc main.c -o banco

# Execute
./banco
```

> **Windows:** use `banco.exe` no lugar de `./banco`

---

## 📚 Conceitos Aplicados

### 🔷 Struct (Estrutura de Dados)
Agrupa variáveis de tipos diferentes (`char`, `int`, `float`) sob um mesmo nome — neste caso, os dados de uma conta bancária — sem possuir métodos internos, diferente de classes em orientação a objetos.

```c
typedef struct {
    char titular[50];
    int numero;
    float saldo;
} Conta;
```

### 🔷 Passagem por Ponteiro
As funções `depositar` e `sacar` recebem um ponteiro (`Conta *c`) para que as alterações no saldo persistam fora da função. O operador `->` é usado para acessar os campos da struct via ponteiro.

```c
void depositar(Conta *c, float valor) {
    c->saldo += valor;
}
```

### 🔷 Uso de `const` para Proteção de Dados
A função `exibirExtrato` recebe `const Conta *c`, garantindo que ela apenas leia os dados da conta, sem permitir alterações acidentais.

```c
void exibirExtrato(const Conta *c) { ... }
```

### 🔷 Controle de Fluxo
- **`do-while`** para manter o menu ativo até o usuário escolher sair
- **`switch-case`** para direcionar a opção escolhida
- **`if-else`** nas funções para validação das regras de negócio (saldo suficiente, valor positivo)

---

## 🎓 Contexto Acadêmico

Projeto desenvolvido como trabalho avaliativo da disciplina de **Paradigmas de Linguagens de Programação** — Universidade Veiga de Almeida (UVA).

---

## 🚀 Melhorias Futuras

- [ ] Persistência de dados em arquivo (`.txt` ou binário)
- [ ] Suporte a múltiplas contas
- [ ] Histórico de transações
- [ ] Autenticação com senha
- [ ] Validação mais robusta de entradas (ex: letras no lugar de números)

---

## 👤 Autor

Feito por **Gabriel Schmitz** — conecte-se no LinkedIn (www.linkedin.com/in/gabriel-schmitz)!
