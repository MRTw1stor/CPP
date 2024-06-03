#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

// Глобальные переменные
HINSTANCE hInst;
HWND hwndButtonClose, hwndButtonFact;

// Вспомогательная функция для получения случайного факта о C++
std::wstring GetRandomFact() {
    // Здесь можно добавить несколько фактов о C++
    std::vector<std::wstring> facts = {
        L"C++ был разработан в 1983 году Бьярном Страуструпом.",
        L"C++ - это расширение языка программирования Си.",
        L"C++ поддерживает объектно-ориентированное, процедурное и обобщенное программирование.",
        L"Стандарт C++ обновляется каждые несколько лет; последний стандарт - C++17.",
        L"C++ широко используется для создания операционных систем, игр, браузеров и других приложений.",
        L"C++ является одним из самых популярных языков программирования в мире."
    };

    // Генерируем случайный индекс для выбора факта
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % facts.size();
    return facts[index];
}

// Обработчик сообщений окна
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        // Создаем кнопку "Закрыть окно"
        hwndButtonClose = CreateWindow(
            L"BUTTON",   // класс кнопки
            L"Закрыть окно",  // текст кнопки
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // стиль кнопки
            50, 50, 150, 50,  // координаты и размеры кнопки
            hwnd,  // дескриптор родительского окна
            (HMENU)1,  // идентификатор кнопки
            hInst, NULL
        );

        // Создаем кнопку "Вывести факт"
        hwndButtonFact = CreateWindow(
            L"BUTTON",
            L"Вывести факт",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            50, 120, 150, 50,
            hwnd,
            (HMENU)2,
            hInst, NULL
        );
        break;

    case WM_COMMAND:
        // Обработка нажатий кнопок
        switch (LOWORD(wParam)) {
        case 1:
            // Нажата кнопка "Закрыть окно"
            DestroyWindow(hwnd);
            break;

        case 2:
            // Нажата кнопка "Вывести факт"
            MessageBoxW(hwnd, GetRandomFact().c_str(), L"Факт о C++", MB_OK | MB_ICONINFORMATION);
            break;
        }
        break;

    case WM_DESTROY:
        // Завершение работы приложения при закрытии окна
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Функция для создания и отображения окна
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Регистрация класса окна
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hInstance, NULL, NULL, NULL, NULL, L"WindowClass", NULL };
    RegisterClassEx(&wc);

    // Создание окна
    HWND hwnd = CreateWindowEx(0, L"WindowClass", L"Пример приложения на C++", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 350, 250, NULL, NULL, hInstance, NULL);

    // Отображение окна
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Цикл обработки сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}