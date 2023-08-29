#include <iostream>
#include <string>
#include <unordered_set>

std::unordered_set<std::string> ContarPalavrasUnicas(std::istream& entrada) {
    std::unordered_set<std::string> palavrasUnicas;
    std::string palavra;

    while (entrada >> palavra) {
        // Remova pontuações e converta para minúsculas, se necessário

        // Adicione a palavra limpa ao conjunto
        palavrasUnicas.insert(palavra);
    }

    return palavrasUnicas;
}

int main() {
    std::cout << "Digite uma lista de palavras (Ctrl+D ou Ctrl+Z para encerrar a entrada):\n";
    std::unordered_set<std::string> palavrasUnicas = ContarPalavrasUnicas(std::cin);

    std::cout << "Palavras únicas na entrada:\n";
    for (const std::string& palavra : palavrasUnicas) {
        std::cout << palavra << "\n";
    }

    return 0;
}
