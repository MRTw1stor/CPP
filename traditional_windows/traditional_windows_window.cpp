#include <windows.h>
#include <string>
#include <ctime>
#include <cstdlib>

// Глобальные переменные
HWND hWndButtonCheck;
HWND hWndButtonClose;
HWND hWndButtonRestart;
HWND hWndEdit;
int secretNumber;
bool guessed = false;

// Функция для создания окна
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow);

// Функция для обработки сообщений окна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// Функция для обработки нажатия кнопки "Проверить"
void OnCheckButtonClicked(HWND hWnd);

// Функция для обработки нажатия кнопки "Закрыть игру"
void OnCloseButtonClicked(HWND hWnd);

// Функция для обработки нажатия кнопки "Начать заново"
void OnRestartButtonClicked(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(nullptr)); // Инициализация генератора случайных чисел
    secretNumber = rand() % 100 + 1; // Загаданное число от 1 до 100

    // Создание главного окна
    HWND hWnd = CreateMainWindow(hInstance, nCmdShow);

    // Цикл обработки сообщений
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow) {
    // Регистрация класса окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MainWindowClass";
    RegisterClass(&wc);

    // Создание окна
    HWND hWnd = CreateWindowEx(
        0,                          // Расширенные стили окна
        L"MainWindowClass",         // Имя класса окна
        L"Угадай число",            // Заголовок окна
        WS_OVERLAPPEDWINDOW,        // Стиль окна
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, // Размеры и позиция окна
        nullptr,                    // Родительское окно
        nullptr,                    // Меню окна
        hInstance,                  // Дескриптор экземпляра приложения
        nullptr                     // Дополнительные параметры создания окна
    );

    // Создание кнопки "Проверить"
    hWndButtonCheck = CreateWindow(
        L"BUTTON",                  // Имя класса кнопки
        L"Проверить",               // Текст кнопки
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Стиль кнопки
        155, 100, 80, 30,           // Размеры и позиция кнопки
        hWnd,                       // Родительское окно
        nullptr,                    // Идентификатор кнопки
        hInstance,                  // Дескриптор экземпляра приложения
        nullptr                     // Дополнительные параметры создания кнопки
    );

    // Создание кнопки "Закрыть игру"
    hWndButtonClose = CreateWindow(
        L"BUTTON",                  // Имя класса кнопки
        L"Закрыть игру",            // Текст кнопки
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Стиль кнопки
        250, 100, 100, 30,          // Размеры и позиция кнопки
        hWnd,                       // Родительское окно
        nullptr,                    // Идентификатор кнопки
        hInstance,                  // Дескриптор экземпляра приложения
        nullptr                     // Дополнительные параметры создания кнопки
    );

    // Создание кнопки "Начать заново"
    hWndButtonRestart = CreateWindow(
        L"BUTTON",                  // Имя класса кнопки
        L"Начать заново",           // Текст кнопки
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_DISABLED, // Стиль кнопки
        30, 100, 105, 30,           // Размеры и позиция кнопки
        hWnd,                       // Родительское окно
        nullptr,                    // Идентификатор кнопки
        hInstance,                  // Дескриптор экземпляра приложения
        nullptr                     // Дополнительные параметры создания кнопки
    );

    // Создание текстового поля для ввода числа
    hWndEdit = CreateWindow(
        L"EDIT",                    // Имя класса текстового поля
        L"",                        // Текст по умолчанию
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER, // Стиль текстового поля
        150, 50, 100, 30,           // Размеры и позиция текстового поля
        hWnd,                       // Родительское окно
        nullptr,                    // Идентификатор текстового поля
        hInstance,                  // Дескриптор экземпляра приложения
        nullptr                     // Дополнительные параметры создания текстового поля
    );

    // Отображение окна
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return hWnd;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_COMMAND:
        if (reinterpret_cast<HWND>(lParam) == hWndButtonCheck && HIWORD(wParam) == BN_CLICKED) {
            OnCheckButtonClicked(hwnd);
        }
        else if (reinterpret_cast<HWND>(lParam) == hWndButtonClose && HIWORD(wParam) == BN_CLICKED) {
            OnCloseButtonClicked(hwnd);
        }
        else if (reinterpret_cast<HWND>(lParam) == hWndButtonRestart && HIWORD(wParam) == BN_CLICKED) {
            OnRestartButtonClicked(hwnd);
        }
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

void OnCheckButtonClicked(HWND hWnd) {
    wchar_t buffer[10];
    GetWindowText(hWndEdit, buffer, 10);
    int guess = _wtoi(buffer);

    std::wstring message;

    if (guess > secretNumber) {
        message = L"Слишком большое число!";
    }
    else if (guess < secretNumber) {
        message = L"Слишком маленькое число!";
    }
    else {
        message = L"Поздравляю! Вы угадали число!";
        EnableWindow(hWndButtonRestart, TRUE);
        guessed = true;
    }

    MessageBox(hWnd, message.c_str(), L"Результат", MB_OK | MB_ICONINFORMATION);
}

void OnCloseButtonClicked(HWND hWnd) {
    DestroyWindow(hWnd);
}

void OnRestartButtonClicked(HWND hWnd) {
    secretNumber = rand() % 100 + 1;
    EnableWindow(hWndButtonRestart, FALSE);
    guessed = false;
    SetWindowText(hWndEdit, L"");
    MessageBox(hWnd, L"Новое число загадано! Удачи в угадывании!", L"Начать заново", MB_OK | MB_ICONINFORMATION);
}