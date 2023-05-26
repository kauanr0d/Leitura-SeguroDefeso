#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

int main(int argc, char *argv[]) {
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc < 2) {
        printf("Erro: nome do arquivo nao foi especificado.\n");
        return 1;
    }
    // Abre o arquivo
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo '%s'.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    // Lê cada linha do arquivo
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Remove o caractere '\n' da linha lida
        line[strcspn(line, "\n")] = 0;

        // Separa os campos da linha usando o caractere ';'
        char *field;
        char *token = strtok(line, ";");
        int field_count = 0;

        while (token != NULL) {
            // Processa cada campo da linha
            if (field_count == 0) {
                // Mês de referência
                field = token;
                printf("Mes de referencia: %s\n", field);
            } else if (field_count == 1) {
                // UF
                field = token;
                printf("UF: %s\n", field);
            } else if (field_count == 2) {
                // Código do município SIAFI
                field = token;
                printf("Codigo do municipio SIAFI: %s\n", field);
            } else if (field_count == 3) {
                // Nome do município
                field = token;
                printf("Nome do municipio: %s\n", field);
            } else if (field_count == 4) {
                // CPF do favorecido
                field = token;
                printf("CPF do favorecido: %s\n", field);
            } else if (field_count == 5) {
                // NIS do favorecido
                field = token;
                printf("NIS do favorecido: %s\n", field);
            } else if (field_count == 6) {
                // RGP do favorecido
                field = token;
                printf("RGP do favorecido: %s\n", field);
            } else if (field_count == 7) {
                // Nome do favorecido
                field = token;
                printf("Nome do favorecido: %s\n", field);
            } else if (field_count == 8) {
                // Valor da parcela
                field = token;
                printf("Valor da parcela: %s\n", field);
            }

            // Lê o próximo campo
            token = strtok(NULL, ";");
            field_count++;
        }

        line_count++;
    }

    // Fecha o arquivo
    fclose(file);

    printf("Foram lidas %d linhas do arquivo.\n", line_count);

    return 0;
}