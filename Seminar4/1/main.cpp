#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " input.txt output.txt" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile) {
        std::cerr << "Не удалось открыть файл " << argv[1] << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> cards[i];
    }

    // Сортируем карты
    std::sort(cards.begin(), cards.end());

    // Максимальный выигрыш - разница между максимальными и минимальными картами
    int maxWin = cards[N - 1] - cards[0];

    outputFile << maxWin << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
6
