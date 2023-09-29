#include "PmergeMe.hpp"

//O intuito desse exercício serve para fazer uma comparação entre o vector e o deque, eles funcionam de maneira semelhantes
//suas principais diferenças são:	
// Alocação de Memória:

// std::vector: Armazena seus elementos em um único bloco de memória contíguo. Isso significa que a alocação de memória é contígua, o que pode resultar em desempenho eficiente para acessos sequenciais e aleatórios. No entanto, realocar e redimensionar um vetor pode ser caro, pois pode exigir a cópia de todos os elementos para um novo bloco de memória.

// std::deque: Usa uma estrutura de dados de blocos separados para armazenar seus elementos. Cada bloco é alocado de forma independente e, em seguida, os ponteiros para esses blocos são mantidos em uma estrutura de controle. Isso permite que os deques cresçam de maneira mais eficiente, pois a inserção e remoção de elementos em ambas as extremidades não requerem realocações massivas. No entanto, o acesso aleatório pode ser menos eficiente do que em um vetor devido à falta de continuidade de memória.

// Inserção e Remoção no Início:

// std::vector: Inserir ou remover elementos no início do vetor pode ser ineficiente, pois todos os elementos subsequentes precisam ser deslocados para abrir espaço ou preencher o espaço vazio.

// std::deque: Inserir ou remover elementos no início de um deque é eficiente, pois não requer realocações maciças. Os blocos podem ser facilmente adicionados ou removidos na extremidade inicial.

// Acesso Aleatório:

// std::vector: Oferece acesso aleatório eficiente devido à memória contígua. Os elementos podem ser acessados diretamente por índice.

// std::deque: O acesso aleatório em um deque pode ser um pouco mais lento do que em um vetor devido à natureza dos blocos separados. No entanto, a diferença geralmente não é significativa, a menos que você esteja fazendo um número muito grande de acessos aleatórios.

// Desempenho de Realocação:

// std::vector: A realocação de um vetor pode ser cara, especialmente quando o vetor cresce além da capacidade atual. É importante reservar espaço com antecedência se você souber que seu vetor vai crescer para evitar realocações frequentes.

// std::deque: Devido à sua estrutura de blocos, os deques têm melhor desempenho em termos de realocação, pois geralmente envolvem a alocação de um novo bloco em vez de realocar todo o conteúdo.

// Uso Recomendado:

// Use std::vector quando precisar de acesso rápido aos elementos e não planejar inserções ou remoções frequentes no início.

// Use std::deque quando precisar de inserções e remoções eficientes no início e no final ou quando não souber antecipadamente o tamanho máximo do contêiner.

// A escolha entre std::vector e std::deque deve ser baseada nos requisitos específicos do seu programa e nas operações que você planeja realizar com os dados armazenados.


int main(int argc, char **argv) {

    if(argc < 2)
    //se o argc for menor do que 2, ou seja, se o usuário não passar os números, imprimo a mensagem de erro
    {
        std::cerr << "Usage: integers in arguments. Example: 0 3 2 5 6 7" << std::endl;
        return 1;
        //retorno 1 para indicar que houve um erro
    }

    try
    {
        int nb_element = argc - 1; 
        //o int nb_element é igual ao argc - 1, ou seja, o número de elementos passados via terminal
        std::vector<int> unsorted;
        //declaro um vector de int
        for (int i = 1; i < argc; i++)
        //enquanto não chegar no final do argc
            unsorted.push_back(atoi(argv[i]));
            //adiciono os números passados via terminal ao vector
        
        for (size_t i = 0; i < unsorted.size(); i++)
        //enquanto não chegar no final do vector
        {
            if (std::count(unsorted.begin(), unsorted.end(), unsorted[i]) > 1)
            //se o número aparecer mais de uma vez no vector, imprimo a mensagem de erro
            {
                std::cerr << "Are duplicate " << unsorted[i] << " in sequence" << std::endl;
                return 1;
                //retorno 1 para indicar que houve um erro
            }
        }

        std::deque<int> deque;
        //declaro um deque de int
        for (size_t i = 0; i < unsorted.size(); i++)
        //enquanto não chegar no final do deque
            deque.push_back(unsorted[i]);
            //adiciono os números do vector ao deque

        std::cout << std::string(80, '-') << std::endl << std::endl;
        //coloco duas linhas para ficar mais fácil de ver o resultado
        std::cout << "Before: ";
        //imprimo a mensagem
        for (int i = 0; i < argc - 1; i++){
            //enquanto não chegar no final do argc
            
            std::cout << unsorted[i] << " ";
            //imprimo os números passados via terminal
            if (i == argc - 2)
            //se chegar no final do argc
                std::cout << "Number elements" << i + 1 << std::endl;
                //imprimo o número de elementos
        }
        std::cout << std::endl << std::endl;
        std::cout << std::string(80, '-') << std::endl << std::endl;
        //coloco duas linhas para ficar mais fácil de ver o resultado

        //vector unsorted
		std::cout << "VECTOR TESTING" << std::endl;
        PmergeMe pmergeme;
        //declaro a classe PmergeMe
        clock_t start_time_v = clock();
        //declaro a variável start_time_v e atribuo a ela o clock para medir o tempo de execução
        Comparator comp = compare;
        //declaro a classe Comparator e atribuo a ela a função compare
        std::vector<int> sorted = pmergeme.mergeInsertionSort(comp, unsorted);
        //declaro um vector de int e atribuo a ele o resultado da função mergeInsertionSort da classe PmergeMe
        clock_t end_time_v = clock();
        //declaro a variável end_time_v e atribuo a ela o clock para medir o tempo de execução

        //vector sorted
        std::cout << "After: ";
        for (size_t i = 0; i < sorted.size(); i++){
            //enquanto não chegar no final do vector
            
            std::cout << sorted[i] << " ";
            //imprimo os números do vector
            if (i == sorted.size() - 1)
            //se chegar no final do vector
                std::cout << "Number elements" << i + 1 << std::endl;
        }
        std::cout << std::endl << std::endl;

        // Check VECTOR SORTED order
        for (size_t i = 0; i < sorted.size() - 1; i++){
            //enquanto não chegar no final do vector menos 1
            
            if (sorted[i] > sorted[i + 1]){
                //se o número atual for maior do que o próximo número
                std::cout << "incorret order" << std::endl;
                //imprimo a mensagem de erro
                return 1;
                //retorno 1 para indicar que houve um erro
            }
        }
        std::cout << "CHECK VECTOR ORDER - All in correct order!!!" << std::endl << std::endl;
        //imprimo a mensagem
        std::cout << "Time to process a range of " << nb_element << " elements with std::vector sort: " << ((double)
        (end_time_v - start_time_v) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
        //imprimo o tempo de execução da função mergeInsertionSort da classe PmergeMe


        // -------------------------------- DEQUE --------------------------------
        // deque testing
        std::cout << std::string(80, '-') << std::endl;
        //coloco duas linhas para ficar mais fácil de ver o resultado
		std::cout << "DEQUE TESTING" << std::endl << std::endl;
        clock_t start_time_d = clock();
        //declaro a variável start_time_d e atribuo a ela o clock para medir o tempo de execução
        Comparator comp_d = compare;
        //declaro a classe Comparator e atribuo a ela a função compare
        std::deque<int> sorted_d = pmergeme.mergeInsertionSort_deque(comp_d, deque);
        //declaro um deque de int e atribuo a ele o resultado da função mergeInsertionSort_deque da classe PmergeMe
        clock_t end_time_d = clock();
        //declaro a variável end_time_d e atribuo a ela o clock para medir o tempo de execução
        
        std::cout << "After: ";
        for (size_t i = 0; i < sorted_d.size(); i++){
            //enquanto não chegar no final do deque
            std::cout << sorted_d[i] << " ";
            //imprimo os números do deque
            if (i == sorted.size() - 1)
            //se chegar no final do deque
                std::cout << "Number elements" << i + 1 << std::endl;
                //imprimo o número de elementos
        }
        std::cout << std::endl << std::endl;
        
        // Check order
        for (size_t i = 0; i < sorted_d.size() - 1; i++){
            //enquanto não chegar no final do deque menos 1
            
            if (sorted_d[i] > sorted_d[i + 1]){
                //se o número atual for maior do que o próximo número
                std::cout << "incorret order" << std::endl;
                return 1;
                //retorno 1 para indicar que houve um erro
            }
        }
        std::cout << "CHECK DEQUE ORDER - All in correct order!!!" << std::endl << std::endl;
        std::cout << "Time to process a range of " << nb_element << " elements with std::deque sort:   " << ((double)(end_time_d - start_time_d) / CLOCKS_PER_SEC) * 1000000 << " us" << std::endl;
        //imprimo o tempo de execução da função mergeInsertionSort_deque da classe PmergeMe
        std::cout << std::string(80, '-') << std::endl;
        

        // Analysis of the results vector and deque
        std::cout << std::string(80, '-') << std::endl;

        if (end_time_v - start_time_v > end_time_d - start_time_d)
        //se o tempo de execução da função mergeInsertionSort da classe PmergeMe for maior do que o tempo de execução da função mergeInsertionSort_deque da classe PmergeMe
            std::cout << "RESULT: std::deque is " << (end_time_v - start_time_v) - (end_time_d - start_time_d) << "us faster than std::vector" << std::endl;
            //imprimo a mensagem
        if (end_time_v - start_time_v < end_time_d - start_time_d)
        //se o tempo de execução da função mergeInsertionSort da classe PmergeMe for menor do que o tempo de execução da função mergeInsertionSort_deque da classe PmergeMe
            std::cout << "RESULT: std::vector is  " << (end_time_d - start_time_d) - (end_time_v - start_time_v) << "us faster than std::deque" << std::endl;
            //imprimo a mensagem
        if ((end_time_v - start_time_v) == (end_time_d - start_time_d))
        //se o tempo de execução da função mergeInsertionSort da classe PmergeMe for igual ao tempo de execução da função mergeInsertionSort_deque da classe PmergeMe
            std::cout << "RESULT: std::vector and std::deque works in same time" << std::endl;
            //imprimo a mensagem
        std::cout << std::string(80, '-') << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
    catch(std::exception& e)
    //se cair na exceção, imprimo a mensagem de erro
    {
        std::cerr << e.what() << std::endl;
        return 1;
        //retorno 1 para indicar que houve um erro
    }
}
