#include <string>
#include <iostream>
#include <fstream>


int main (int argc, char **argv){

    if (argc != 4){
    //se o número de argumentos for diferente de 4
        std::cout << "Error. Incorrect numbers of arguments." << std::endl;
        //imprime na tela que o número de argumentos é inválido
        return 1;
        //retorna 1 porque o número de argumentos é inválido
    }

    std::string filename = argv[1];
    //variável para armazenar o nome do arquivo passado como parâmetro
    std::string s1 = argv[2];
    //variável para armazenar a string s1 passada como parâmetro
    std::string s2 = argv[3];
    //variável para armazenar a string s2 passada como parâmetro

    if (filename.empty() || s1.empty() || s2.empty()){
        //verifica se o nome do arquivo ou a string s1 ou a string s2 passados como parâmetro estão vazios
        std::cout << "Error. One or more arguments are empty.";
        //imprime na tela que o nome do arquivo ou a string s1 ou a string s2 passados como parâmetro estão vazios
        return 1;
        //retorna 1 porque o nome do arquivo ou a string s1 ou a string s2 passados como parâmetro estão vazios
    }
    std::ifstream file_in(filename.c_str());
    //cria um objeto ifstream para ler o arquivo passado como parâmetro. A ifstream é um tipo de stream de entrada de dados de arquivo. Stream é uma sequência de dados. O c_str() retorna um ponteiro para uma string terminada em null com os mesmos caracteres que a string do objeto.
    std::string output_filename(filename + ".replace");
    //variável para armazenar o nome do arquivo de saída com .replace no final
    std::ofstream file_out(output_filename.c_str());
    //cria um objeto ofstream para escrever no arquivo de saída. A ofstream é um tipo de stream de saída de dados de arquivo. Stream é uma sequência de dados. O c_str() retorna um ponteiro para uma string terminada em null com os mesmos caracteres que a string do objeto.


    if (file_in.fail()){
        //verifica se o arquivo passado como parâmetro existe
        std::cout << "Error. Failed to open the file." << std::endl;
        //imprime na tela que o arquivo passado como parâmetro não existe
        return 1;
        //retorna 1 porque o arquivo passado como parâmetro não existe
    }

    if (file_out.fail()){
        //verifica se o arquivo de saída existe
        std::cout << "Error. Failed to create the file." << std::endl;
        //imprime na tela que o arquivo de saída não existe
        return 1;
        //retorna 1 porque o arquivo de saída não existe
    }

    std::string buffer;
    //variável para armazenar o conteúdo do arquivo passado como parâmetro
    std::string::size_type pos;
    //variável para armazenar a posição da string s1 no arquivo passado como parâmetro
    while (getline(file_in, buffer)){
    //enquanto conseguir pegar uma linha do arquivo passado como parâmetro e armazenar na variável buffer
        while((pos = buffer.find(s1)) != std::string::npos){
        //enquanto encontrar a string s1 no arquivo passado como parâmetro
            file_out << buffer.substr(0, pos);
            //escreve no arquivo de saída o conteúdo do arquivo passado como parâmetro até a posição da string s1, a substr serve para pegar uma parte de uma string
            buffer.erase(0, pos + s1.length());
            //apaga do arquivo passado como parâmetro o conteúdo até a posição da string s1, o erase serve para apagar uma parte de uma string
            file_out << s2;
            //escreve no arquivo de saída a string s2
        }
        file_out << buffer;
        //escreve no arquivo de saída o conteúdo do arquivo passado como parâmetro
        if (!file_in.eof())
        //se não for o final do arquivo passado como parâmetro, o eof() retorna true se for o final do arquivo e ele serve para verificar se o arquivo chegou ao final, a sigla eof significa end of file.
            file_out << std::endl;
            //escreve no arquivo de saída uma quebra de linha
    }
    return 0;
}

//./Sed poema Sabiá Leticia