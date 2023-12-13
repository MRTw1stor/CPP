#include <iostream>
#include <string>
using namespace std;

const int numAthletes = 10;
const int numSports = 5;

// Структура для хранения данных о спортсмене
struct Athlete {
    string name;
    int scores[numSports];
};

// Функция для вычисления общего балла спортсмена
int getTotalScore(const Athlete& athlete) {
    int total = 0;
    for (int i = 0; i < numSports; i++) {
        total += athlete.scores[i];
    }
    return total;
}

int main() {
    // Инициализация данных спортсменов
    Athlete athletes[numAthletes] = {
        {"Иванов", {10, 5, 8, 7, 9}},
        {"Петров", {8, 7, 6, 5, 9}},
        {"Сидоров", {9, 8, 7, 6, 5}},
        {"Козлов", {8, 7, 8, 9, 10}},
        {"Михайлов", {7, 7, 7, 7, 7}},
        {"Александров", {10, 9, 8, 7, 6}},
        {"Дмитриев", {5, 6, 7, 8, 9}},
        {"Андреев", {8, 8, 8, 8, 8}},
        {"Сергеев", {7, 6, 8, 5, 9}},
        {"Павлов", {9, 6, 8, 7, 5}}
    };

    // Вывод информации о баллах каждого участника
    cout << "Информация о баллах участников:" << endl;
    for (int i = 0; i < numAthletes; i++) {
        int totalScore = getTotalScore(athletes[i]);
        cout << athletes[i].name << ": " << totalScore << " очков" << endl;
    }

    // Поиск спортсмена с наибольшим общим баллом
    int maxScore = getTotalScore(athletes[0]);
    string winner = athletes[0].name;

    for (int i = 1; i < numAthletes; i++) {
        int totalScore = getTotalScore(athletes[i]);
        if (totalScore > maxScore) {
            maxScore = totalScore;
            winner = athletes[i].name;
        }
    }

    // Вывод результата
    cout << "Победитель: " << winner << ", с набранными баллами: " << maxScore << " очков." << endl;
}