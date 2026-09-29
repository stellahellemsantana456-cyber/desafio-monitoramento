# desafio-monitorament# Desafio de Monitoramento de Temperatura

## 1. Identificação
* **Nome do aluno:** [Seu Nome Completo]
* **Disciplina:** Algoritmos e Programação
* **Professora:** Profa. Karla Sartin
* **Título do projeto:** Sistema de Monitoramento de Temperatura em C

## 2. Objetivo
O programa tem como objetivo controlar e monitorar leituras de temperatura em tempo real, calculando estatísticas gerais (média, maior, menor, quantidade e percentual) e identificando situações de risco quando há três leituras consecutivas acima de um limite estipulado pelo usuário.

## 3. Funcionamento do programa
* **Limite de temperatura:** Definido pelo usuário logo no início da execução.
* **Leituras:** O programa solicita inserções de temperatura de forma contínua.
* **Valores inválidos:** Caso o usuário digite letras ou valores fora da faixa aceitável (-50°C a 150°C), o programa avisa o erro e exige uma nova entrada.
* **Acima do limite:** Ocorrência em que o valor digitado é maior que o limite configurado.
* **Contagem consecutiva:** Um contador acumula quantas vezes seguidas o limite foi ultrapassado. Caso uma temperatura normal seja informada no meio, o contador é zerado.
* **Condição de encerramento:** O monitoramento para se o usuário digitar `-999` ou se atingir automaticamente três temperaturas consecutivas acima do limite.

## 4. Estruturas de repetição utilizadas
Foi utilizada a estrutura `do...while` em duas frentes: no laço principal do sistema e na validação das entradas.
* **Justificativa:** Escolhi o `do...while` porque ele garante que o bloco de comandos seja executado ao menos uma vez antes de realizar qualquer validação, o que se encaixa perfeitamente na necessidade de pedir a temperatura ao usuário antes de testar se ela é válida ou se o programa deve continuar rodando.

## 5. Como executar
Para compilar e rodar o programa via terminal:

```bash
gcc monitoramento.c -o monitoramento
./monitoramento
