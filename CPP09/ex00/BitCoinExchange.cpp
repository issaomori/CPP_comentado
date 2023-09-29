#include "BitCoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
//construtor padrão da classe
{
    std::cout << "[BitcoinExchange] create!!!" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
//destrutor da classe
{
    std::cout << "[BitcoinExchange] delete!!!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
//construtor de cópia da classe
{
    std::cout << "[BitcoinExchange] copy!!!" << std::endl;
    *this = copy;
    //copia o conteúdo de um objeto para o outro
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
//sobrecarga do operador de atribuição, serve para copiar o conteúdo de um objeto para o outro
{
    std::cout << "[BitcoinExchange] operator=!!!" << std::endl;
    if (this != &rhs)
    //se o objeto passado como parâmetro for diferente do objeto que chamou a função
    {
        this->db = rhs.db;
        //copia o conteúdo de um objeto para o outro
    }
    return *this;
    //retorna o objeto que chamou a função
}

void BitcoinExchange::LoadData()
//método responsável por carregar os dados do arquivo data.csv para o map db
{
    std::ifstream file;
    //cria um objeto ifstream para ler o arquivo. O ifstream é um tipo de stream de entrada que lê dados de um arquivo.
    std::string line;
    //cria uma string para armazenar cada linha do arquivo

    try {
        file.open("./data.csv");
        //tento abrir o arquivo data.csv
        if (!file.is_open()) {
            //se o arquivo não foi aberto
            throw std::runtime_error("Error to open file");
            //lança uma exceção
        }

        file >> line;
        //lê a primeira linha do arquivo e armazena na string line
        while (!file.eof()) {
            //enquanto não chegar no final do arquivo
            file >> line;
            //lê a linha e armazena na string line
            std::string date = line.substr(0, line.find(','));
            //cria uma string para armazenar a data
            std::string price = line.substr(line.find(',') + 1, line.length());
            //cria uma string para armazenar o preço
            this->db.insert(std::make_pair(date.substr(0, 10).erase(4, 1).erase(6, 1), strtod(price.c_str(), NULL)));
            //insere no map db a data e o preço
            //a função make_pair cria um par de valores, a substring serve para pegar apenas a data sem a hora, o erase serve para remover os caracteres '-' da data, a função strtod converte a string price para double e a função c_str() retorna um ponteiro para a string price
        }

        file.close();
        //fecha o arquivo
    }
    catch (const std::exception& e) {
        //se ocorrer uma exceção
        std::cout << e.what() << std::endl;
        //imprime a mensagem de erro
    }
}

void BitcoinExchange::PrintData()
//método responsável por imprimir os dados do map db
{
    std::map<std::string, double>::iterator it = this->db.begin();
    //cria um iterador para percorrer o map db, e o inicializa com o primeiro elemento do map
    while (it != this->db.end())
    //enquanto o iterador não chegar no último elemento do map
    {
        std::cout << it->first << " " << it->second << std::endl;
        //imprime a data e o preço
        ++it;
        //incrementa o iterador
    }
}

bool isNumeric(const std::string& str)
//função que verifica se uma string é numérica
//Por que preciso verificar se uma string é numérica? Porque o arquivo data.csv possui linhas com datas e preços, e eu preciso verificar se o preço é numérico para inserir no map db
{
    std::string::const_iterator it = str.begin();
    //cria um iterador para percorrer a string
    while (it != str.end() && (isdigit(*it) || *it == '.')) {
        //enquanto o iterador não chegar no final da string e o caractere for um dígito ou um ponto
        ++it;
        //incrementa o iterador
    }
    return it == str.end();
    //retorna true se o iterador chegou no final da string, ou seja, se a string é numérica
}

void BitcoinExchange::InputHandler(std::string filename)
//método responsável por ler o arquivo passado como parâmetro e imprimir o resultado
{
    std::ifstream file(filename.c_str());
    //cria um objeto ifstream para ler o arquivo. O ifstream é um tipo de stream de entrada que lê dados de um arquivo.

    if (!file.is_open())
    //se o arquivo não foi aberto
    {
        std::cout << "Error: Unable to open file" << std::endl;
        return;
        //imprime uma mensagem de erro e retorna
    }

    std::string line;
    //cria uma string para armazenar cada linha do arquivo

    std::getline(file, line);
    //lê a primeira linha do arquivo e armazena na string line
    if (line != "date | value")
    //se a linha for diferente de "date | value"
    {
        std::cerr << "Error: Expected 'date | value'" << std::endl;
        file.close();
        return;
        //imprime uma mensagem de erro, fecha o arquivo e retorna
    }

    while (std::getline(file, line))
    //enquanto não chegar no final do arquivo
    {
        if (line.length() < 14 || CountWords(line) != 2)
        //se a linha tiver menos de 14 caracteres ou se tiver mais de 2 palavras
        //Para que serve essa verificação? Para verificar se a linha possui o formato correto, ou seja, se a linha possui uma data e um preço
        {
            std::cerr << "Error: " << line << std::endl;
            continue;
            //imprime uma mensagem de erro e continua o loop
        }

        std::string year = line.substr(0, 4);
        //cria uma string para armazenar o ano, a função substr retorna uma substring da string line, o primeiro parâmetro é a posição inicial e o segundo parâmetro é a quantidade de caracteres
        std::string month = line.substr(5, 2);
        //cria uma string para armazenar o mês, a função substr retorna uma substring da string line, o primeiro parâmetro é a posição inicial e o segundo parâmetro é a quantidade de caracteres
        std::string day = line.substr(8, 2);
        //cria uma string para armazenar o dia, a função substr retorna uma substring da string line, o primeiro parâmetro é a posição inicial e o segundo parâmetro é a quantidade de caracteres
        std::string price = line.substr(13, line.length());
        //cria uma string para armazenar o preço, a função substr retorna uma substring da string line, o primeiro parâmetro é a posição inicial e o segundo parâmetro é a quantidade de caracteres

        if (!isNumeric(year) || !isNumeric(month) || !isNumeric(day) || !isNumeric(price))
        //se o ano, o mês, o dia ou o preço não forem numéricos
        {
            std::cerr << "Error: " << line << std::endl;
            continue;
            //imprime uma mensagem de erro e continua o loop
        }

        int day_int = atoi(day.c_str());
        //converte a string day para inteiro
        int month_int = atoi(month.c_str());
        //converte a string month para inteiro
        int year_int = atoi(year.c_str());
        //converte a string year para inteiro
        double price_double = strtod(price.c_str(), NULL);
        //converte a string price para double

        if (ParseInput(year_int, month_int, day_int, price_double, line) != -1)
        //se a função ParseInput retornar -1, significa que ocorreu um erro
        {
            std::ostringstream oss;
            //cria um objeto ostringstream para armazenar a data no formato YYYYMMDD
            //Para que serve a ostringstream? Para criar uma string a partir de outros tipos de dados
            oss << year_int;
            //insere o ano no objeto ostringstream
            if (month_int < 10)
            //se o mês for menor que 10
                oss << "0";
            //insere um 0 no objeto ostringstream
            oss << month_int;
            //insere o mês no objeto ostringstream
            if (day_int < 10)
            //se o dia for menor que 10
                oss << "0";
            //insere um 0 no objeto ostringstream
            //Por que eu insiro um 0 no objeto ostringstream? Porque a data deve ter 8 caracteres, e se o dia ou o mês for menor que 10, a data terá apenas 7 caracteres
            oss << day_int;
            //insere o dia no objeto ostringstream
            std::string fulldate = oss.str();
            //converte o objeto ostringstream para string
            PrintExchangeInfo(fulldate, price_double);
            //imprime o resultado
        }
    }

    file.close();
    //fecha o arquivo
}

int BitcoinExchange::ParseInput(int year, int month, int day, double value, std::string line)
//método responsável por verificar se a data e o preço são válidos
{
    if (line.substr(4, 1) != "-" || line.substr(7, 1) != "-")
    //se a linha não tiver o formato YYYY-MM-DD
    {
        std::cerr << "Error: Invalid text format" << std::endl;
        return -1;
        //imprime uma mensagem de erro e retorna -1
    }

    size_t pos = line.find('|');
    //cria uma variável para armazenar a posição do caractere '|'
    if (line[pos - 1] != ' ' || line[pos + 1] != ' ')
    //se o caractere anterior ou posterior ao '|' não for espaço
    {
        std::cerr << "Error: Invalid pipe" << std::endl;
        return -1;
        //imprime uma mensagem de erro e retorna -1
    }

    if (value < 0.00 || value > 1000.00)
    //se o preço for menor que 0 ou maior que 1000
    {
        std::cerr << "Error: Value outside the permitted range" << std::endl;
        return -1;
        //imprime uma mensagem de erro e retorna -1
    }

    if (year < 2009 || month < 1 || month > 12)
    //se o ano for menor que 2009 ou se o mês for menor que 1 ou maior que 12
    {
        std::cerr << "Error: Date is invalid" << std::endl;
        return -1;
        //imprime uma mensagem de erro e retorna -1
    }

    int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //cria um vetor para armazenar a quantidade de dias de cada mês, mas por que eu não criei um vetor com 12 posições? Porque o vetor começa na posição 0, então a posição 0 representa o mês 1, a posição 1 representa o mês 2, e assim por diante. E também por que são esses valores? Porque são os valores de dias de cada mês, por exemplo, o mês 1 tem 31 dias, o mês 2 tem 28 dias, e assim por diante

    if (day > month_limits[month - 1] || day < 1)
    //se o dia for maior que a quantidade de dias do mês ou se o dia for menor que 1
    {
        std::cerr << "Error: Non-existent date" << std::endl;
        return -1;
        //imprime uma mensagem de erro e retorna -1
    }

    return 0;
    //retorna 0
}

void BitcoinExchange::PrintExchangeInfo(std::string date, double exchangeRate)
//método responsável por imprimir o resultado
{
    if (date < this->db.begin()->first)
    //se a data for menor que a primeira data do map db
    {
        std::cout << "Error: Date is earlier than the earliest date in the database." << std::endl;
        return;
        //imprime uma mensagem de erro e retorna
    }

    std::map<std::string, double>::iterator it = this->db.upper_bound(date);
    //cria um iterador para percorrer o map db, e o inicializa com o primeiro elemento maior que a data passada como parâmetro
    it--;

    std::string formattedDate = date;
    //cria uma string para armazenar a data no formato YYYY-MM-DD
    formattedDate.insert(4, "-").insert(7, "-");
    //insere o caractere '-' na posição 4 e 7 da string formattedDate

    double result = exchangeRate * it->second;
    //multiplica o preço pelo valor do bitcoin na data passada como parâmetro

    std::cout << formattedDate << " => " << exchangeRate << " = " << std::fixed << std::setprecision(2) << result << std::endl;
    //imprime o resultado
}

int BitcoinExchange::CountWords(std::string line)
//método responsável por contar a quantidade de palavras de uma string
{
    std::string delimiter = " ";
    //cria uma string para armazenar o delimitador
    size_t pos = 0;
    //cria uma variável para armazenar a posição do delimitador
    int wordCount = 0;
    //cria uma variável para armazenar a quantidade de palavras

    while ((pos = line.find(delimiter)) != std::string::npos) {
        //enquanto não chegar no final da string
        wordCount++;
        //incrementa a quantidade de palavras
        line.erase(0, pos + delimiter.length());
        //remove a palavra da string
    }

    return wordCount;
    //retorna a quantidade de palavras
}
