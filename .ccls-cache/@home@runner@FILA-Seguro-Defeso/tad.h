typedef struct nodo *ptrNodo;
struct nodo {
		elemento elem;
		ptrNodo prox;
	    };

typedef struct {
		ptrNodo inicio;
    ptrNodo fim;
		int tamanho;
	} fila;

typedef fila tipo_fila;

int tamanhoFila(fila f) {
   return f.tamanho;
}

void criarFila(fila *f) {
	f->tamanho = 0;
	f->inicio  = NULL;
	f->fim     = NULL;
}

int filaVazia(fila f) {
     return (f.inicio==NULL);
}

int primeiroFila(fila f, elemento *e) {
   if (!filaVazia(f)) {
      *e = (f.inicio)->elem;
      return 1;
   }
   else
      return 0;
}

int entrarElemento(fila *f, elemento e) {
	ptrNodo pnodo;
   	pnodo = (ptrNodo) malloc(sizeof(struct nodo));
	if (pnodo == NULL)
		return 0;
	else {
		pnodo->elem = e;
		pnodo->prox = NULL;

		if (f->fim != NULL)
			f->fim->prox = pnodo;
	  f->fim = pnodo;

		if (f->inicio == NULL)
			f->inicio = pnodo;
		f->tamanho++;
		return 1;
	}
}

int sairElemento(fila *f, elemento *e) {
	ptrNodo pnodo;
	if (filaVazia(*f))
		return 0;
	else {
		pnodo = f->inicio;
		f->inicio = f->inicio->prox;
		*e = pnodo->elem;
		free(pnodo);
		if (f->inicio == NULL)
			f->fim = NULL;
		f->tamanho--;
		return 1;
	}
}
/*void obter_elemento(fila *f, elemento *e){
  ptrNodo pnodo;
  pnodo = f->inicio;
  if(!filaVazia(*f)){
    for(int i=1;i<=tamanho(*f);i++){
      pnodo = pnodo->prox;
    }
    *e = pnodo->elem;
  }*/
//}*/