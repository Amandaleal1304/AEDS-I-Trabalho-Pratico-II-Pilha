#ifndef PILHA_H
#define PILHA_H

#define MAX_TAM 10
#define MAX_ENTREGA 7

struct Pedido {
    int Codigo;
    int produtos[MAX_TAM];
    int tamanhoProdutos;
    float valor_pedido;
    float distancia;
};

struct Pilha {
    Pedido pedido[MAX_ENTREGA];
    int topo;
};

void CriaPilhaVazia(Pilha *pilha);//cria pilha vazia
bool PilhaVazia(Pilha *pilha);//verifica se a pilha esta vazia
bool PilhaCheia(Pilha *pilha);//verifica se a pilha esta cheia
void Empilha(Pedido pedido, Pilha *pilha);//empilha os pedidos na pilha
void Desempilha(Pedido *pedido, Pilha *pilha);//desempilha pedido
void ExibePilha(Pilha *pilha);//exibe a pilha de pedidos
int tamanho(Pilha *pilha);//retorna o tamanho da pilha
void menu();//exibe o menu de opcoes 
void Cardapio();//exibe o cardapio
void ConsultaPedido(Pilha *pilha, int codigo);//consulta um pedido por codigo
Pedido RemovePedidoPorID(Pilha *pilha, int codigo);//remove pedido da pilha
void OrganizaPilha(Pilha *pilha, Pedido pedido);//organiza por ordem de menor distancia
void Salva(Pilha *pilha);//salva os dadados no arquivo binario
#endif