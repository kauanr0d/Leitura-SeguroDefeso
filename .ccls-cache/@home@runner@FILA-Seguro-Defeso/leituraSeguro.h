#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256


int carregar_para_fila(char* nome_arquivo, tipo_fila *f) {
   elemento e;
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo!\n");
        return 0;
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
                if(strlen(field)>0 && field!=NULL){
                  e.MES = atoi(field);
                }
            } else if (field_count == 1) {
                // UF
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  strcpy(e.UF,field);
                }else{
                  strcpy(e.UF,"NULL");
                }
            } else if (field_count == 2) {
                // Código do município SIAFI
                field = token;
              if(strlen(field)>0 && field!=NULL){
                e.COD_SIAFI = atoi(field);
              }else{
                e.COD_SIAFI = 0;
              }
            } else if (field_count == 3) {
                // Nome do município
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  strcpy(e.MUNICIPIO,field);
                }else{
                  strcpy(e.MUNICIPIO," ");
                }
            } else if (field_count == 4) {
                // CPF do favorecido
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  strcpy(e.CPF,field);
                }else{
                  strcpy(e.CPF,"NULL");
                }
            } else if (field_count == 5) {
                // NIS do favorecido
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  e.NIS = atoi(field);
                  }else{
                    e.NIS = 0;
                  }
            } else if (field_count == 6) {
                // RGP do favorecido
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  strcpy(e.RGP,field);
                }else{
                  strcpy(e.RGP,"NULL");
                }
            } else if (field_count == 7) {
                // Nome do favorecido
                field = token;
                if(strlen(field)>0 && field!=NULL){
                  strcpy(e.NOME,field);
                }else{
                  strcpy(e.NOME,"NULL");
                }
            } else if (field_count == 8) {
                // Valor da parcela
                field = token;
              if(strlen(field)>0 && field!=NULL){
                 e.VALOR = atoi(field);
                }else{
                  e.VALOR = 0;
              }
            }
            // Lê o próximo campo
            token = strtok(NULL, ";");
            field_count++;
        }
        entrarElemento(f,e);

        line_count++;
    }

    // Fecha o arquivo
    fclose(file);


    return 1;
}