#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
//biblioteca padrão de entrada e saída de dados
#include <string>
#include <map>
//biblioteca que permite criar um mapa de dados

class Harl{
//classe Harl que possui um atributo name e um método attack
    private:
    //variáveis e métodos privados que só podem ser acessados pelos membros da classe

        typedef void (Harl::*LevelFunction)(void);
        //cria um tipo de dado LevelFunction que é um ponteiro para um método da classe Harl que não retorna nada e não recebe parâmetros. Isso serve para criar um mapa de dados que armazena strings e ponteiros para métodos da classe Harl.
        std::map<std::string, LevelFunction> level_functions;
        //cria um mapa de dados que armazena strings e ponteiros para métodos da classe Harl.

        void debug( void );
        //método da classe Harl que serve para fazer o Harl debugar
        void info( void );
        //método da classe Harl que serve para fazer o Harl informar
        void warning( void );
        //método da classe Harl que serve para fazer o Harl avisar
        void error( void );
        //método da classe Harl que serve para fazer o Harl mostrar um erro

    public:
    //métodos públicos da classe Harl que podem ser acessados por qualquer classe
    Harl();
    //construtor da classe Harl que serve para inicializar a variável de membro da classe
    ~Harl();
    //destrutor da classe Harl que serve para destruir o Harl passado.
    void complain( std::string level );
    //método da classe Harl que serve para fazer o Harl reclamar
};

#endif