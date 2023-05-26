#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Dados{
  int MES;
  char UF[2];
  int COD_SIAFI;
  char MUNICIPIO[40];
  char CPF[14];
  long int NIS;
  char RGP[12];
  char NOME[50];
  int VALOR;
}Dados;

typedef Dados elemento;

#include"tad_fila2.h"
#include "leituraSeguro.h"
tipo_fila f;

void pesquisar_valor(){
  int acm=0;
  float valor;
  elemento e;
  printf("Insira o valor:");
  scanf("%f",&valor);
  while(!filaVazia(f)){
  sairElemento(&f, &e);
    if(valor == e.VALOR){
      acm = acm+1; 
    }
  }
  printf("Quantidade de benefícios existentes:%d",acm);
}
void pagamentos_possiveis(){
  int qtd_salarios_pagos=0,acm_verba=0;
  float verba_governo=0,salario_pesca=0;
  elemento e;
  printf("\nInsira o valor da verba disponível:");
  scanf("%f",&verba_governo);
    do{
      sairElemento(&f, &e);
      //salario_pesca = verba_governo/qtd_salarios_pagos;
      if(e.VALOR>0){
        salario_pesca = e.VALOR;
        acm_verba = acm_verba+salario_pesca;
        qtd_salarios_pagos = qtd_salarios_pagos+1;
      }
    }while(acm_verba<verba_governo && !(filaVazia(f)));
  
  printf("\nVALOR DE CADA SALÁRIO: %2.f",salario_pesca);
  printf("\nQUANTIDADE DE SALÁRIOS PAGOS: %d",qtd_salarios_pagos);
}

void listar(){
  elemento e2;
  while(!filaVazia(f)){
    sairElemento(&f,&e2);
    printf("\nMES:%d",e2.MES);
    printf("\nUF:%s",e2.UF);
    printf("\nCOD:%d",e2.COD_SIAFI);
    printf("\nMUNICIPIO:%s",e2.MUNICIPIO);
    printf("\nCPF:%s",e2.CPF);
    printf("\nNIS:%ld",e2.NIS);
    printf("\nRGP:%s",e2.RGP);
    printf("\nNOME:%s",e2.NOME);
    printf("\nVALOR:R$%d\n",e2.VALOR);
    sleep(2);
  }
}
void menu(){
  int op=0;
  printf("\n\t\t### SEGURO DEFESO ###");
  printf("\n\t\t 1-PESQUISAR VALOR DE BENEFÍCIO ENTRE OS CADASTRADOS");
  printf("\n\t\t 2-CALCULAR QUANTIDADE DE BENEFICIOS POSSÍVEIS");
  printf("\n\t\t 3-LISTAR BENEFICIÁRIOS");
  printf("\n\t\t 9-SAIR\n->");
  scanf("%d",&op);
  switch(op){
    case 1:
      pesquisar_valor();
    break;
    case 2:
      pagamentos_possiveis();
    break;
    case 3:
      listar();
    break;
    case 9:
      exit(1);
    break;
    default:
      printf("OPÇÃO INVÁLIDA");
  }
}

int main(){
  carregar_para_fila("202201_SeguroDefeso.csv", &f);
  menu();
  return 0;
}

