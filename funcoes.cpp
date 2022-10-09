#include <iostream>
using namespace std;
#include "pilha.hpp" //inclui o hpp

int id = 0;

void CriaPilhaVazia(Pilha *pilha) // cria pilha vazia
{
    pilha->topo = 0; // topo recebe 0
}

bool PilhaVazia(Pilha *pilha) // verifica se a pilha esta vazia
{
    if (pilha->topo == 0) // se for igual a 0
    {
        return true; // retorna verdade se estiver
    }
    else
    {
        return false; // ou false se nao estiver vazia
    }
}

bool PilhaCheia(Pilha *pilha) // verifica se a pilha esta cheia
{
    if (pilha->topo == MAX_TAM) // se for igual a max tam que é 10
    {
        return true; // retorna verdade se estiver cheia
    }
    else
    {
        return false; // ou falso se nao estiver cheia
    }
}

void Empilha(Pedido pedido, Pilha *pilha) // empilha os pedidos na pilha
{
    if (PilhaCheia(pilha)) // verifica se esta cheia
    {
        cout << endl
             << "Pilha Cheia!" << endl; // exibe mensagem
        return;
    }

    pilha->pedido[pilha->topo] = pedido; // se nao empilha pedido
    pilha->topo++;                       // atualiza o topo
}

void Desempilha(Pedido *pedido, Pilha *pilha) // desempilha pedido
{
    if (PilhaVazia(pilha)) // verifica se esta vazia
    {
        cout << endl
             << "Pilha Vazia!" << endl; // exibe mensagem
        return;
    }

    pilha->topo--;                        // se nao atualiza o topo uma posicao apaixo
    *pedido = pilha->pedido[pilha->topo]; // desempilha
}

void ExibePilha(Pilha *pilha) // exibe a pilha de pedidos
{
    for (int i = pilha->topo - 1; i >= 0; i--) // percorre a piha
    {
        cout << "Codigo: " << pilha->pedido[i].Codigo << endl;            // exibe o codigo
        cout << "Distancia: " << pilha->pedido[i].distancia << endl;      // exibe a distancia
        cout << "Valor Final: " << pilha->pedido[i].valor_pedido << endl; // exibe o valor final do pedido

        cout << "Codigo dos produtos: ";
        for (int j = 0; j < pilha->pedido[i].tamanhoProdutos; j++) // percorre os produtos do pedido
        {
            cout << pilha->pedido[i].produtos[j] << " "; // exibe o codigo dos produtos de cada pedido
        }
        cout << endl;
    }
}

int tamanho(Pilha *pilha) // retorna o tamanho da pilha
{
    return pilha->topo + 1;
}

void menu() // exibe o menu de opcoes
{
    cout << "******************** MENU ********************\n";
    cout << "**                                          **\n";
    cout << "** 1 - Fazer novo pedido                    **\n";
    cout << "**                                          **\n";
    cout << "** 2 - Listar pedidos                       **\n";
    cout << "**                                          **\n";
    cout << "** 3 - Exibir cardapio                      **\n";
    cout << "**                                          **\n";
    cout << "** 4 - Consultar pedido                     **\n";
    cout << "**                                          **\n";
    cout << "** 5 - Imprimir lista de entrega            **\n";
    cout << "**                                          **\n";
    cout << "** 6 - Lancar entrega concluida             **\n";
    cout << "**                                          **\n";
    cout << "** 7 - Sair                                 **\n";
    cout << "**                                          **\n";
    cout << "**********************************************\n";
}

void Cardapio() // exibe o cardapio
{
    cout << "******************** CARDAPIO ********************\n";
    cout << "****                                          ****\n";
    cout << "**** 1 - Suco                      R$ 2.00    ****\n";
    cout << "****                                          ****\n";
    cout << "**** 2 - Refrigerante              R$ 3.00    ****\n";
    cout << "****                                          ****\n";
    cout << "**** 3 - Hamburguer                R$ 7.00    ****\n";
    cout << "****                                          ****\n";
    cout << "**** 4 - X-Egg                     R$ 9.00    ****\n";
    cout << "****                                          ****\n";
    cout << "**** 5 - X-Bacon                   R$ 10.00   ****\n";
    cout << "****                                          ****\n";
    cout << "**** 6 - X-EggBacon                R$ 12.00   ****\n";
    cout << "****                                          ****\n";
    cout << "**** 7 - X-Tudo                    R$ 14.00   ****\n";
    cout << "****                                          ****\n";
    cout << "**************************************************\n\n";
}

void ConsultaPedido(Pilha *pilha, int codigo) // consulta um pedido por codigo
{
    for (int i = 0; i < pilha->topo; i++) // percorre
    {
        if (pilha->pedido[i].Codigo == codigo) // busca o pedido procurado
        {
            cout << "Codigo: " << pilha->pedido[i].Codigo << endl;            // exibe o codigo do procurado
            cout << "Distancia: " << pilha->pedido[i].distancia << endl;      // exibe a distancia do procurado
            cout << "Valor Final: " << pilha->pedido[i].valor_pedido << endl; // exibe o valor final do pedido procurado

            cout << "Codigo dos Produtos: ";

            for (int j = 0; j < pilha->pedido[i].tamanhoProdutos; j++) // percorre os produtos do pedido
            {
                cout << pilha->pedido[i].produtos[j] << " "; // exibe os codigos de produtos daquele pedido
            }
            cout << endl;
            return;
        }
    }
}

Pedido RemovePedidoPorID(Pilha *pilha, int codigo) // remove pedido da pilha
{
    // Percorre a pilha procurando o codigo que vai ser excluido
    for (int i = 0; i < pilha->topo; i++)
    {
        if (pilha->pedido[i].Codigo == codigo)
        {
            Pedido excluido = pilha->pedido[i];
            for (int j = i; j < pilha->topo; j++)
            {
                pilha->pedido[j] = pilha->pedido[j + 1];
            }
            pilha->topo--;   // atualiza o topo para um posicao abaixo
            return excluido; // retorna o pedido excluido
        }
    }
}

void OrganizaPilha(Pilha *pilha, Pedido pedido) // organiza por ordem de menor distancia
{
    float maior;           // maior distancia
    int tamP;              // Tamanho da pilha
    if (PilhaVazia(pilha)) // Verifica se a pilha esta vazia
    {
        cout << "A Lista De Pedidos Esta Vazia!";
    }

    else
    {
        Pilha aux;            // pilha auxiliar
        CriaPilhaVazia(&aux); // cria pilha auxiliar vazia
        tamP = pilha->topo;   // recebe o topo da pilha
        int codigo;

        for (int i = 0; i < tamP; i++) // percorre
        {
            Desempilha(&pedido, pilha); // desempilha
            Empilha(pedido, &aux);      // empilha na auxiliar
        }
        tamP = aux.topo;
        for (int j = 0; j < tamP; j++)
        {
            maior = 0; // inicia em 0
            for (int i = 0; i < aux.topo; i++)
            {
                if (maior < aux.pedido[i].distancia)
                {
                    maior = aux.pedido[i].distancia;
                    codigo = aux.pedido[i].Codigo;
                }
            }
            Empilha(RemovePedidoPorID(&aux, codigo), pilha);
        }
        cout << "Pilha Organizada por ordem de distancia!\n\n";
        ExibePilha(pilha); // Exibe a pilha organizada
    }
}

void Salva(Pilha *pilha) // salva os dadados no arquivo binario
{
    FILE *file = fopen("lanchonete.bin", "w"); // abre o arquivo e w"(write): abertura de arquivo para escrita;

    Pedido pedido;
    int TamanhoPilha;

    TamanhoPilha = pilha->topo;
    for (int i = 0; i < TamanhoPilha; i++)
    {
        Desempilha(&pedido, pilha);
        fwrite(&pedido, sizeof(Pedido), 1, file); // fwrite retorna quantos itens são gravados o sizeof pega o tamanho e grava os dados
    }
}
