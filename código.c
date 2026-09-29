#include <stdio.h>

int main() {
    float limite, temp;
    float soma = 0, maior = 0, menor = 0;
    int totalLeituras = 0, acimaLimite = 0;
    int consecutivas = 0;
    int entradaValida;

    // Define o limite de temperatura
    printf("Digite o limite de temperatura permitido: ");
    if (scanf("%f", &limite) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }
    // Limpa o buffer após ler o limite
    while (getchar() != '\n');

    printf("\n--- Inicio do Monitoramento ---\n");
    printf("Dica: Digite -999 para encerrar manualmente.\n\n");

    do {
        // Validação da entrada da temperatura usando do...while
        do {
            printf("Digite a temperatura atual: ");
            if (scanf("%f", &temp) != 1) {
                printf("Erro: insira um valor numerico valido.\n");
                while (getchar() != '\n'); // Limpa o buffer do teclado
                entradaValida = 0;
            } else {
                while (getchar() != '\n'); // Limpa o buffer após ler o número com sucesso
                if (temp == -999) {
                    entradaValida = 1;
                } else if (temp < -50 || temp > 150) {
                    printf("Temperatura invalida! Insira um valor entre -50 e 150.\n");
                    entradaValida = 0;
                } else {
                    entradaValida = 1;
                }
            }
        } while (!entradaValida);

        // Encerramento manual
        if (temp == -999) {
            break;
        }

        // Atualização das estatísticas
        totalLeituras++;
        soma += temp;
        if (totalLeituras == 1) {
            maior = temp;
            menor = temp;
        } else {
            if (temp > maior) maior = temp;
            if (temp < menor) menor = temp;
        }

        // Verificação de temperatura acima do limite
        if (temp > limite) {
            acimaLimite++;
            consecutivas++;
        } else {
            consecutivas = 0; // Reinicia o contador se a temperatura normalizar
        }

        // Condição de encerramento por 3 temperaturas consecutivas acima do limite
        if (consecutivas >= 3) {
            printf("\n[ALERTA] 3 temperaturas consecutivas acima do limite! Encerrando o sistema...\n");
            break;
        }

    } while (1);

    // Exibição do relatório final
    printf("\n========================================\n");
    printf("          RELATORIO FINAL               \n");
    printf("========================================\n");
    if (totalLeituras > 0) {
        float media = soma / totalLeituras;
        float percentual = ((float)acimaLimite / totalLeituras) * 100;
        
        printf("Total de leituras realizadas: %d\n", totalLeituras);
        printf("Media das temperaturas: %.2f C\n", media);
        printf("Maior temperatura registrada: %.2f C\n", maior);
        printf("Menor temperatura registrada: %.2f C\n", menor);
        printf("Quantidade acima do limite: %d\n", acimaLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);
    } else {
        printf("Nenhuma leitura foi registrada.\n");
    }
    printf("========================================\n");

    return 0;
}
