#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhacao, manin! *" << endl;
    cout << "**************************************" << endl;
    cout << "Escolha o seu nivel de dificuldade:" << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute, chefe? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute e: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto, manin!" << endl<< endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto, chefe!" << endl<< endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente! Sem arroz com lentilha pra vc" << endl;
    }
    else{
        cout << "Voce acertou o número secreto em " << tentativas << " tentativas! Vamos comer arroz com lentilha?" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
}
