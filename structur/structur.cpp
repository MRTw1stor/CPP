/* Известны баллы, набранные каждым из 10 спортсменов-пятиборцев в каждом из пяти видов
спорта. Определить фамилию спортсмена-победителя соревнований.*/

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
        {"Козлов", {6, 7, 8, 9, 10}},
        {"Михайлов", {7, 7, 7, 7, 7}},
        {"Александров", {10, 9, 8, 7, 6}},
        {"Дмитриев", {5, 6, 7, 8, 9}},
        {"Андреев", {8, 8, 8, 8, 8}},
        {"Сергеев", {7, 6, 8, 5, 9}},
        {"Павлов", {9, 6, 8, 7, 5}}
    };

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

/* №1
Описание структур в языке C:
Структуры в языке C описываются с использованием ключевого слова struct, 
после которого идет имя структуры и фигурные скобки, в которых объявляются поля структуры.
*/

/* №2
Доступ к элементам структуры:
Доступ к элементам структуры осуществляется с использованием 
оператора точки (.), и имя структуры, за которым следует точка и имя поля.
*/

/* №3
Указатель на структуру:
Указатель на структуру - это переменная, которая содержит адрес памяти структуры. 
Она позволяет получить доступ к полям структуры и выполнять операции 
с самой структурой, используя указатель и оператор разыменования (*).
*/