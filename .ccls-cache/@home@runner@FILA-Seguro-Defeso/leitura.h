int carregar_txt(char* nome_arquivo,tipo_fila* f){
  FILE* arquivo = fopen(nome_arquivo,"r");
  elemento e;
  if(arquivo==NULL){
    printf("Erro ao abrir arquivo!\n");
    return 0;
  }
  while(fscanf(arquivo,"%d %s %d %s %s %d %s %s %d",&e.mes,&e.UF,e.cod_SIAFI,&e.municipio,&e.cpf,&e.nis,&e.rgp,&e.nome,&e.valor)!=-1){
    entrarElemento(f,e);
  }
  return 1;
}