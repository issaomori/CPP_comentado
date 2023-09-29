#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
//construtor padrão
}

PmergeMe::~PmergeMe(){
//destrutor padrão
}

PmergeMe::PmergeMe(PmergeMe const &copy){
    //construtor de cópia parametrizado
	*this = copy;
    //chamo o operador de atribuição sobrecarregado
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs){
    //operador de atribuição sobrecarregado para atribuir um objeto a outro
	(void)rhs;
    //declaro o rhs void para não dar warning
	return (*this);
    //retorno o objeto que chamou a função
}

int compare(int x, int y) {
    //função para comparar dois números
    if (x < y) return -1;
    //se x for menor que y, retorno -1
    if (x > y) return 1;
    //se x for maior que y, retorno 1
    return 0;
    //se x for igual a y, retorno 0
}

int PmergeMe::jacobsthal(int n) {
    // Função para calcular o n-ésimo número de Jacobsthal.
    // Os números de Jacobsthal são uma sequência de números inteiros definida da seguinte forma:
    // J(0) = 0
    // J(1) = 1
    // Para n >= 2, J(n) = J(n-1) + 2*J(n-2), ou seja, cada número é a soma dos dois números anteriores multiplicados por 2.
    // Exemplo: Para n = 5, a sequência de Jacobsthal é [0, 1, 1, 3, 5, ...].
    // O cálculo é realizado através da fórmula J(n) = round((2^n + (-1)^(n-1)) / 3).

    return round((std::pow(2, n) + std::pow(-1, n - 1)) / 3);
    // Retorna o valor calculado para o n-ésimo número de Jacobsthal.
}

std::vector<int> PmergeMe::pendingElementOrder(int number) {
    // Função para calcular a ordem dos elementos pendentes.
    std::vector<int> response;
    // Inicialize o vetor response com os números de Jacobsthal até o primeiro número maior que number.
    for (int i = 0; jacobsthal(i) > number; ++i) {
        //enquanto o número de Jacobsthal for maior que o número passado como parâmetro
        response.push_back(jacobsthal(i));
        //adiciono o número de Jacobsthal ao vetor response
    }
    response.push_back(number);
    //adiciono o número passado como parâmetro ao vetor response
    std::vector<int> output_vector;
    //declaro um vetor de inteiros output_vector
    for (size_t i = 1; i < response.size(); ++i) {
        //enquanto o tamanho do vetor response for menor que o tamanho do vetor response
        int start_range = response[i - 1];
        //declaro a variável start_range e atribuo a ela o valor do elemento anterior do vetor response
        int end_range = response[i];
        //declaro a variável end_range e atribuo a ela o valor do elemento atual do vetor response
        for (int j = end_range - 1; j >= start_range; --j) {
            //enquanto o end_range for maior ou igual ao start_range
            output_vector.push_back(j);
            //adiciono o valor de j ao vetor output_vector
        }
    }
    return output_vector;
    //retorno o vetor output_vector
}

std::deque<int> PmergeMe::pendingElementOrder_deque(int number) {
    // Função para calcular a ordem dos elementos pendentes.
    std::deque<int> output_deque;
    //inicializo o deque output_deque com os números de Jacobsthal até o primeiro número maior que number

    // Inicialize o vetor response com os números de Jacobsthal até o primeiro número maior que number.
    std::vector<int> response;
    int i = 0;
    while (jacobsthal(i) > number) {
    //enquanto o número de Jacobsthal for maior que o número passado como parâmetro
        response.push_back(jacobsthal(i));
        //adiciono o número de Jacobsthal ao vetor response
        ++i;
        //incremento o i
    }

    // Adiciono o número à resposta.
    response.push_back(number);

    // Construa a ordem diretamente no deque.
    for (size_t idx = 1; idx < response.size(); ++idx) {
    //enquanto o tamanho do vetor response for menor que o tamanho do vetor response
        int start_range = response[idx - 1];
        //declaro a variável start_range e atribuo a ela o valor do elemento anterior do vetor response
        int end_range = response[idx];
        //declaro a variável end_range e atribuo a ela o valor do elemento atual do vetor response
        for (int j = end_range - 1; j >= start_range; --j) {
        //enquanto o end_range for maior ou igual ao start_range
            output_deque.push_back(j);
            //adiciono o valor de j ao deque output_deque
        }
    }

    return output_deque;
    //retorno o deque output_deque
}

int PmergeMe::binarySearchInsertionPoint(Comparator comp, int value, const std::vector<int>& collection, int startIdx, int endIdx) {
    // Função para encontrar o ponto de inserção de um valor em uma coleção ordenada com vector.
    if (startIdx <= endIdx) {
        //enquanto o startIdx for menor ou igual ao endIdx
        int midIdx = (startIdx + endIdx) / 2;
        //declaro a variável midIdx e atribuo a ela o valor da média entre o startIdx e o endIdx
        int compResult = comp(value, collection[midIdx]);
        //declaro a variável compResult e atribuo a ela o valor da comparação entre o valor passado como parâmetro e o elemento do meio da coleção

        if (compResult == 0) {
            //se o compResult for igual a 0
            return midIdx;
            //retorno o midIdx
        } else if (compResult == -1) {
            //se o compResult for igual a -1
            return binarySearchInsertionPoint(comp, value, collection, startIdx, midIdx - 1);
            //retorno a função binarySearchInsertionPoint passando como parâmetros a função comp, o valor, a coleção, o startIdx e o midIdx - 1
        } else {
            //se não
            return binarySearchInsertionPoint(comp, value, collection, midIdx + 1, endIdx);
            //retorno a função binarySearchInsertionPoint passando como parâmetros a função comp, o valor, a coleção, o midIdx + 1 e o endIdx
        }
    } else {
        return startIdx;
        //se não, retorno o startIdx
    }
}

int PmergeMe::binarySearchInsertionPoint(Comparator comp, int value, const std::deque<int>& collection, int startIdx, int endIdx) {
    // Função para encontrar o ponto de inserção de um valor em uma coleção ordenada com deque.
    if (startIdx <= endIdx) {
        //enquanto o startIdx for menor ou igual ao endIdx
        int midIdx = (startIdx + endIdx) / 2;
        //declaro a variável midIdx e atribuo a ela o valor da média entre o startIdx e o endIdx
        int compResult = comp(value, collection[midIdx]);
        //declaro a variável compResult e atribuo a ela o valor da comparação entre o valor passado como parâmetro e o elemento do meio da coleção

        if (compResult == 0) {
            //se o compResult for igual a 0
            return midIdx;
            //retorno o midIdx
        } else if (compResult == -1) {
            //se o compResult for igual a -1
            return binarySearchInsertionPoint(comp, value, collection, startIdx, midIdx - 1);
            //retorno a função binarySearchInsertionPoint passando como parâmetros a função comp, o valor, a coleção, o startIdx e o midIdx - 1
        } else {
            return binarySearchInsertionPoint(comp, value, collection, midIdx + 1, endIdx);
            //retorno a função binarySearchInsertionPoint passando como parâmetros a função comp, o valor, a coleção, o midIdx + 1 e o endIdx
        }
    } else {
        return startIdx;
        //se não, retorno o startIdx
    }
}

std::vector<int> PmergeMe::mainChainUntil(int p_index, const std::vector<int>& mainChain, const std::vector<int>& position_list) {
    // Função para obter a cadeia principal até o índice p_index.
    int end = position_list[p_index];
    //declaro a variável end e atribuo a ela o valor do elemento p_index do vetor position_list
    return std::vector<int>(mainChain.begin(), mainChain.begin() + end);
    //retorno um vetor de inteiros com os elementos da mainChain do início até o end
}

void PmergeMe::binaryInsertLambda(int element_index, Comparator compare, std::vector<int>& mainChain, std::vector<int>& position_list, std::vector<int>& elements_to_insert) {
    // Função para inserir um elemento em uma cadeia principal.
    int n = elements_to_insert[element_index];
    //declaro a variável n e atribuo a ela o valor do elemento element_index do vetor elements_to_insert
    int insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChainUntil(element_index, mainChain, position_list).size() - 1);
    //declaro a variável insertIndex e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor n, a mainChain, 0 e o tamanho da função mainChainUntil(element_index, mainChain, position_list) - 1
    for (size_t i = 0; i < position_list.size(); ++i) {
        //enquanto o tamanho do vetor position_list for menor que o tamanho do vetor position_list
        if (position_list[i] >= insertIndex) {
            //se o elemento i do vetor position_list for maior ou igual ao insertIndex
            ++position_list[i];
            //incremento o elemento i do vetor position_list
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
    //insiro o elemento n na mainChain
}

std::vector<int> PmergeMe::binaryInsert(Comparator compare, int number, const std::vector<int>& coll) {
    // Função para inserir um elemento em uma coleção ordenada com vector.
    std::vector<int> newColl = coll;
    //declaro o vetor newColl e atribuo a ele o vetor coll
    int insertIndex = binarySearchInsertionPoint(compare, number, coll, 0, coll.size() - 1);
    //declaro a variável insertIndex e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor number, o vetor coll, 0 e o tamanho do vetor coll - 1
    newColl.insert(newColl.begin() + insertIndex, number);
    //insiro o elemento number no vetor newColl
    return newColl;
    //retorno o vetor newColl
}

std::deque<int> PmergeMe::binaryInsert(Comparator compare, int number, const std::deque<int>& coll) {
    // Função para inserir um elemento em uma coleção ordenada com deque.
    std::deque<int> newColl = coll;
    //declaro o deque newColl e atribuo a ele o deque coll
    int insertIndex = binarySearchInsertionPoint(compare, number, coll, 0, coll.size() - 1);
    //declaro a variável insertIndex e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor number, o deque coll, 0 e o tamanho do deque coll - 1
    newColl.insert(newColl.begin() + insertIndex, number);
    //insiro o elemento number no deque newColl
    return newColl;
    //retorno o deque newColl
}

std::vector<int> PmergeMe::mergeInsertionSort(Comparator compare, const std::vector<int>& collection) {
    // Função para ordenar uma coleção com vector.
    if (collection.size() < 2) {
        //se o tamanho da coleção for menor que 2
        return collection;
        //retorno a coleção
    } else {
        std::vector<int> sortedCollection;
        //declaro o vetor sortedCollection
        std::vector<int> elementsToInsert;
        //declaro o vetor elementsToInsert

        for (size_t i = 0; i < collection.size(); i++) {
            //enquanto o tamanho da coleção for menor que o tamanho da coleção
            int element = collection[i];
            //declaro a variável element e atribuo a ela o valor do elemento i da coleção
            size_t insertionPoint = binarySearchInsertionPoint(compare, element, sortedCollection, 0, sortedCollection.size() - 1);
            //declaro a variável insertionPoint e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor element, o vetor sortedCollection, 0 e o tamanho do vetor sortedCollection - 1
            sortedCollection.insert(sortedCollection.begin() + insertionPoint, element);
            //insiro o elemento element no vetor sortedCollection
            elementsToInsert.push_back(element);
            //adiciono o elemento element ao vetor elementsToInsert
        }

        std::vector<int> positions(sortedCollection.size());
        //declaro o vetor positions e atribuo a ele o tamanho do vetor sortedCollection
        for (size_t i = 0; i < sortedCollection.size(); ++i) {
            //enquanto o tamanho do vetor sortedCollection for menor que o tamanho do vetor sortedCollection
            positions[i] = i;
            //atribuo ao elemento i do vetor positions o valor i
        }

        std::vector<int> order = pendingElementOrder(elementsToInsert.size());
        //declaro o vetor order e atribuo a ele o valor da função pendingElementOrder passando como parâmetro o tamanho do vetor elementsToInsert
        for (size_t i = 0; i < order.size(); ++i) {
            //enquanto o tamanho do vetor order for menor que o tamanho do vetor order
            binaryInsertLambda(order[i], compare, sortedCollection, positions, elementsToInsert);
            //chamo a função binaryInsertLambda passando como parâmetros o elemento i do vetor order, a função compare, o vetor sortedCollection, o vetor positions e o vetor elementsToInsert
        }

        return sortedCollection;
        //retorno o vetor sortedCollection
    }
}

std::deque<int> PmergeMe::mainChainUntilFunction(int p_index, const std::deque<int>& mainChain, const std::deque<int>& positions_list) {
    // Função para obter a string principal até o índice p_index.
    int end = positions_list[p_index];
    //declaro a variável end e atribuo a ela o valor do elemento p_index do vetor positions_list
    return std::deque<int>(mainChain.begin(), mainChain.begin() + end);
    //retorno um deque de inteiros com os elementos da mainChain do início até o end
}

void PmergeMe::binaryInsertLambda(int element_index, Comparator compare, std::deque<int>& mainChain, std::deque<int>& positions_list, std::deque<int>& pendingElements) {
    // Função para inserir um elemento em uma string principal.
    int n = pendingElements[element_index];
    //declaro a variável n e atribuo a ela o valor do elemento element_index do vetor pendingElements
    int insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChainUntilFunction(element_index, mainChain, positions_list).size() - 1);
    //declaro a variável insertIndex e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor n, a mainChain, 0 e o tamanho da função mainChainUntilFunction(element_index, mainChain, positions_list) - 1
    for (size_t i = 0; i < positions_list.size(); ++i) {
        //enquanto o tamanho do vetor positions_list for menor que o tamanho do vetor positions_list
        if (positions_list[i] >= insertIndex) {
            //se o elemento i do vetor positions_list for maior ou igual ao insertIndex
            ++positions_list[i];
            //incremento o elemento i do vetor positions_list
        }
    }
    mainChain.insert(mainChain.begin() + insertIndex, n);
    //insiro o elemento n na mainChain
}

std::deque<int> PmergeMe::mergeInsertionSort_deque(Comparator compare, const std::deque<int>& coll) {
    // Função para ordenar uma coleção com deque.
    if (coll.size() < 2) {
        //se o tamanho da coleção for menor que 2
        return coll;
        //retorno a coleção
    } else {
        std::deque<int> mainChain;
        //declaro o deque mainChain
        std::deque<int> pendingElements;
        //declaro o deque pendingElements

        for (size_t i = 0; i < coll.size(); i++) {
            //enquanto o tamanho da coleção for menor que o tamanho da coleção
            int n = coll[i];
            //declaro a variável n e atribuo a ela o valor do elemento i da coleção
            size_t insertIndex = binarySearchInsertionPoint(compare, n, mainChain, 0, mainChain.size() - 1);
            //declaro a variável insertIndex e atribuo a ela o valor da função binarySearchInsertionPoint passando como parâmetros a função compare, o valor n, o deque mainChain, 0 e o tamanho do deque mainChain - 1
            mainChain.insert(mainChain.begin() + insertIndex, n);
            //insiro o elemento n no deque mainChain
            pendingElements.push_back(n);
            //adiciono o elemento n ao deque pendingElements
        }

        std::deque<int> positions_list(mainChain.size());
        //declaro o deque positions_list e atribuo a ele o tamanho do deque mainChain
        for (size_t i = 0; i < mainChain.size(); ++i) {
            //enquanto o tamanho do deque mainChain for menor que o tamanho do deque mainChain
            positions_list[i] = i;
            //atribuo ao elemento i do deque positions_list o valor i
        }

        std::deque<int> order = pendingElementOrder_deque(pendingElements.size());
        //declaro o deque order e atribuo a ele o valor da função pendingElementOrder_deque passando como parâmetro o tamanho do deque pendingElements
        for (size_t i = 0; i < order.size(); ++i) {
            //enquanto o tamanho do deque order for menor que o tamanho do deque order
            binaryInsertLambda(order[i], compare, mainChain, positions_list, pendingElements);
            //chamo a função binaryInsertLambda passando como parâmetros o elemento i do deque order, a função compare, o deque mainChain, o deque positions_list e o deque pendingElements
        }
        return mainChain;
        //retorno o deque mainChain
    }
}
