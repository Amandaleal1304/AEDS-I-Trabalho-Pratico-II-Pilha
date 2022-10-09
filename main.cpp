#include <iostream>
#include "funcoes.cpp"

using namespace std;

int main()
{
    Pilha pilha;
    Pedido pedido;
    CriaPilhaVazia(&pilha);//cria pilha vazia

    int CodPedido = 0;  // Codigo do pedido(ID automatico)
    int CodProduto = 0; // Codigo do produto escolhido
    int TamP = 0;       // Tamanho da pilha de pedidos
    int op = 0;         // Opcao do menu escolhida

    FILE *file = fopen("lanchonete.bin", "r"); // Cria o arquivo e abre
    if (file != NULL)
    {
        while (fread(&pedido, sizeof(Pedido), 1, file)) // le cada linha
            // muda o codigo para o maior que encontrar
            if (pedido.Codigo > CodPedido)
            {
                CodPedido = pedido.Codigo;
            }
        Empilha(pedido, &pilha); // Empilha na pilha
    }

    CodPedido++;//atualiza o codigo do pedido para usar nos proximos
    system("cls");//limpa a tela

    do
    {
        menu(); // exibe as opcoes do programa
        cout << endl;
        cout << "Digite uma opcao: ";
        cin >> op;//salva a escolha de opcao
        system("cls");//limpa a tela

        // vai executar de acordo com a opcao escolhida a cima
        switch (op)//caso
        {
        case 1:    //novo pedido                    
         pedido.Codigo = CodPedido; // Codigo do pedido vai ser 1 depois 2 ...
            pedido.tamanhoProdutos = 0;
            pedido.valor_pedido = 0;

            do
            {
                Cardapio(); // Exibe os produtos disponiveis
                cout << endl
                     << "Escolha um produto: ";
                cin >> CodProduto;

                if (CodProduto > 7)
                {
                    cout << "O produto selecionado nao existe!";
                }

                if (CodProduto != 0)
                {
                    pedido.produtos[pedido.tamanhoProdutos] = CodProduto;
                    // tabela de precos
                    if (CodProduto == 1) // Suco
                    {
                        pedido.valor_pedido += 2;
                    }
                    else if (CodProduto == 2) // Refrigerante
                    {
                        pedido.valor_pedido += 3;
                    }
                    else if (CodProduto == 3) // hamburguer
                    {
                        pedido.valor_pedido += 7;
                    }
                    else if (CodProduto == 4) // X-Egg
                    {
                        pedido.valor_pedido += 9;
                    }
                    else if (CodProduto == 5) // X-Bacon
                    {
                        pedido.valor_pedido += 10;
                    }
                    else if (CodProduto == 6) // X-EggBacon
                    {
                        pedido.valor_pedido += 12;
                    }
                    else if (CodProduto == 7)
                    {
                        pedido.valor_pedido += 14;
                    }
                    pedido.tamanhoProdutos++;
                }
                //vai perguntar se quer adicionar mais produtos se não voltar para o menu
                if (CodProduto != 0)
                {
                    cout << "Deseja adicionar mais produtos? (1 - Sim / 0 - Nao): ";
                    cin >> CodProduto;//salva a escolha do usuario
                }
                system("cls");//limpa a tela
            } while (CodProduto != 0);

            cout << "Distancia em km: ";//pede a distancia da lanchonete e da casa
            cin >> pedido.distancia;//armazena a distancia

            Empilha(pedido, &pilha);   // Empilha o pedido
            CodPedido = CodPedido + 1; // Atualiza o codigo de pedido
            system("pause");//pausa
            system("cls"); // limpa a tela
            break;         // termina

        case 2:                     // Listar pedidos
            if (PilhaVazia(&pilha)) // Verifica se a pilha esta vazia
            {
                cout << "Vazio!"; // A pilha esta vazia
                system("pause");//pausa
                system("cls"); // limpa a tela
            }
            else
            {
                ExibePilha(&pilha); // Vai mostrar todos os pedidos feitos
                system("pause");//pausa
                system("cls"); // limpa a tela
            }
            break; // termina

        case 3:         // Cardapio
            Cardapio(); // Exibe as opcoes de produtos
            system("pause");//pausa
            system("cls"); // limpa a tela
            break;         // termina

        case 4: // Consulta Pedido
            int cod;//variavel
            cout << "Informe o codigo do pedido: ";//pede o codigo que deseja consultar
            cin >> cod;//armazena o codigo de consulta

            ConsultaPedido(&pilha, cod); // vai buscar e exibir o pedido procurado
            system("pause");//pausa
            system("cls"); // limpa a tela
            break;         // termina

        case 5:                            // Lista de entrega
            OrganizaPilha(&pilha, pedido); // organiza a pilha e exibe
            system("pause");//pausa
            system("cls"); // limpa a tela
            break;         // termina

        case 6: // Lancar entrega
                //  verifica se a pilha esta vazia
            if (PilhaVazia(&pilha))
            {
                cout << "Pilha Vazia!" << endl;//exibe mensagem
            }
            else
            {
                Desempilha(&pedido, &pilha);                                              // Entrega o pedido do topo
                cout << "Codigo do pedido: " << pedido.Codigo << " saiu para a entrega!"; // pedido entregue
            }
            system("pause");//pausa
            system("cls"); // limpa a tel
            break;         // termina

        }              // termina o swit
    } while (op != 7); // termina a repeticao do menu

    Salva(&pilha);//salva em lanchonete.bin
    return 0;
}
