/* Составить программу записи в файл GS всех чисел файла FS кратных 5, 
а файл HS – всех отрицательных чисел кратных 3.*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct FileData
{
    vector<int> data;
};

void createNewFile(const string& filename)
{
    cout << "Создание нового файла " << filename << endl;
    ofstream file(filename);  // Создание нового файла
    file.close();  // Закрытие файла
}

void viewFile(const string& filename)
{
    cout << "Просмотр содержимого файла " << filename << endl;
    ifstream file(filename);  // Открытие файла для чтения
    file.close();  // Закрытие файла
}

void correctFile(const string& filename)
{
    cout << "Коррекция файла " << filename << endl;
    ofstream file(filename, ios::app);  // Открытие файла для дозаписи новых данных или исправления старых
    file.close();  // Закрытие файла
}

void writeDataToFile(const string& filename, const FileData& fileData)
{
    ofstream file(filename);  // Открытие файла для записи
    if (file.is_open()) {
        for (int val : fileData.data) {
            file << val << " ";  // Запись данных в файл
        }
        file.close();  // Закрытие файла
        cout << "Данные успешно записаны в файл " << filename << endl;
    } else {
        cout << "Ошибка при открытии файла " << filename << " для записи данных" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");  // Установка локали для вывода на русском языке
    const string fsFilename = "FS.txt";
    const string hsFilename = "HS.txt";

    // Создание структуры для данных, которые будут записаны в файл
    FileData fsData;
    FileData hsData;

    // Наполнение структуры данными, кратными 5 и отрицательными числами кратными 3
    for (int i = -50; i <= 50; ++i) {
        if (i % 5 == 0) {
            fsData.data.push_back(i);
        }
        if (i % 3 == 0 && i < 0) {
            hsData.data.push_back(i);
        }
    }

    // Запись данных в соответствующие файлы
    writeDataToFile(fsFilename, fsData);
    writeDataToFile(hsFilename, hsData);

    // Пример использования создания нового файла, просмотра и коррекции
    createNewFile("example.txt");  // Пример создания нового файла
    viewFile("example.txt");  // Пример просмотра содержимого файла
    correctFile("example.txt");  // Пример коррекции файла
}