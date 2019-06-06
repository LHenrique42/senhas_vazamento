#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*
    Funcao sequencial para verificar se senhas foram vazadas no arquivo.

*/
void verificaSenhasVazadas(ifstream *senhas_verificar, ifstream *senhas_vazadas)
{
    string line_senha_verificar, line_senha_vazada;
    if( (senhas_verificar->is_open()) && (senhas_vazadas->is_open()))
    {
        while(getline(*senhas_verificar, line_senha_verificar))
        {
            while(getline(*senhas_vazadas, line_senha_vazada))
            {
                /* Verifica se as senhas sao iguais */
                if(line_senha_vazada.compare(line_senha_verificar) == 0)
                {
                    cout << "Vazou ! " << line_senha_verificar << " "<< line_senha_vazada << endl; 
                }
            }

            /*
                Reposiciona o ponteiro no inicio do arquivo.
            */
            senhas_vazadas->clear();
            senhas_vazadas->seekg(0, ios::beg);
        }
    }
}


int main(int argc, char *argv[])
{
    string line;
    ifstream senhas_vazadas(argv[1]), senhas_verificar(argv[2]);

    verificaSenhasVazadas(&senhas_verificar, &senhas_vazadas);
    return 0;
}