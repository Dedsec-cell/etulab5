
#include <iostream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;


void mirrorBitsChar(char &num, int startBit, int bitCount) {
    unsigned char mask = 0;
    unsigned char mirroredGroup = 0;

    // Создаем маску для выделения группы битов
    for (int i = 0; i < bitCount; ++i) {
        mask |= (1 << (startBit - i));  // Маска для битов с конца группы
    }

    mirroredGroup = num & mask;  // Выделяем группу битов
    mirroredGroup = ((mirroredGroup >> (startBit - bitCount + 1)) & ((1 << bitCount) - 1));  // Сдвигаем группу в начало

    // Зеркально переставляем биты
    unsigned char reversedGroup = 0;
    for (int i = 0; i < bitCount; ++i) {
        if (mirroredGroup & (1 << i)) {
            reversedGroup |= (1 << (bitCount - 1 - i));
        }
    }

    // Убираем старые биты и вставляем зеркально переставленные
    num &= ~mask;
    num |= (reversedGroup << (startBit - bitCount + 1));  // Вставляем обратно в число
}

// Функция для зеркальной перестановки битов для long double
void mirrorBitsLongDouble(long double &num, int startBit, int bitCount) {
    unsigned long long *ptr = reinterpret_cast<unsigned long long*>(&num);  // Интерпретируем как 64-битное целое число

    unsigned long long mask = 0;
    unsigned long long mirroredGroup = 0;

    // Создаем маску для выделения группы битов
    for (int i = 0; i < bitCount; ++i) {
        mask |= (1ULL << (startBit - i));  // Маска для битов с конца группы
    }

    mirroredGroup = *ptr & mask;  // Выделяем группу битов
    mirroredGroup = ((mirroredGroup >> (startBit - bitCount + 1)) & ((1ULL << bitCount) - 1));  // Сдвигаем группу в начало

    // Зеркально переставляем биты
    unsigned long long reversedGroup = 0;
    for (int i = 0; i < bitCount; ++i) {
        if (mirroredGroup & (1ULL << i)) {
            reversedGroup |= (1ULL << (bitCount - 1 - i));
        }
    }

    // Убираем старые биты и вставляем зеркально переставленные
    *ptr &= ~mask;
    *ptr |= (reversedGroup << (startBit - bitCount + 1));  // Вставляем обратно в число
}

// Функция для вывода двоичного представления char
void printBinaryChar(char num) {
    bitset<8> binary(num);  // Представление как 8-битное
    cout << binary << endl;
}

// Функция для вывода двоичного представления long double
void printBinaryLongDouble(long double num) {
    unsigned long long *ptr = reinterpret_cast<unsigned long long*>(&num);  // Интерпретируем как 64-битное целое число
    bitset<64> binary(*ptr);  // Представление как 64-битное
    cout << binary << endl;
}

// Функция для проверки правильности ввода числа
bool isValidInput(const string& input) {
    for (char c : input) {
        if (!isdigit(c) && c != '.') {  // Если встречается нецифровой символ или не точка
            return false;    // Некорректный ввод
        }
    }
    return true;
}

int main() {
    // Ввод данных с проверкой
    char charNum;
    long double longDoubleNum;
    string input;
    int attempts = 0;  // Счётчик попыток
    const int maxAttempts = 5; // Максимальное количество попыток

    // Ввод char с проверкой
    while (attempts < maxAttempts) {
        cout << "Введите char: ";
        cin >> input;

        if (input.size() == 1) {
            charNum = input[0];  // Получаем символ
            break;
        } else {
            attempts++;
            cout << "Ошибка! Некорректный ввод. Попыток осталось: " << maxAttempts - attempts << endl;
        }
    }

    if (attempts == maxAttempts) {
        cout << "Ваш интеллект низок для данной программы, попробуйте в другой раз." << endl;
        return 0;
    }

    attempts = 0;  // Сбросить количество попыток

    // Ввод long double с проверкой
    while (attempts < maxAttempts) {
        cout << "Введите long double: ";
        cin >> input;

        if (isValidInput(input)) {
            longDoubleNum = stod(input);  // Преобразуем строку в число
            break;
        } else {
            attempts++;
            cout << "Ошибка! Некорректный ввод. Попыток осталось: " << maxAttempts - attempts << endl;
        }
    }

    if (attempts == maxAttempts) {
        cout << "Ваш интеллект низок для данной программы, попробуйте в другой раз." << endl;
        return 0;
    }

    // Ввод дополнительных параметров для зеркальной перестановки битов с проверкой
    int startBit, bitCount;

    attempts = 0;  // Сбросить количество попыток

    // Ввод номера старшего бита для изменения
    while (attempts < maxAttempts) {
        cout << "Введите номер старшего бита для изменения: ";
        cin >> input;

        if (isValidInput(input)) {
            startBit = stoi(input);  // Преобразуем строку в число
            break;
        } else {
            attempts++;
            cout << "Ошибка! Некорректный ввод. Попыток осталось: " << maxAttempts - attempts << endl;
        }
    }

    if (attempts == maxAttempts) {
        cout << "Ваш интеллект низок для данной программы, попробуйте в другой раз." << endl;
        return 0;
    }

    attempts = 0;  // Сбросить количество попыток

    // Ввод количества битов для изменения
    while (attempts < maxAttempts) {
        cout << "Введите количество бит для изменения: ";
        cin >> input;

        if (isValidInput(input)) {
            bitCount = stoi(input);  // Преобразуем строку в число
            break;
        } else {
            attempts++;
            cout << "Ошибка! Некорректный ввод. Попыток осталось: " << maxAttempts - attempts << endl;
        }
    }

    if (attempts == maxAttempts) {
        cout << "Ваш интеллект низок для данной программы, попробуйте в другой раз." << endl;
        return 0;
    }

    // Вывод результата до изменений для char
    cout << "\nДля char:" << endl;
    cout << "До изменения: ";
    printBinaryChar(charNum);  // Выводим двоичное представление для char

    // Зеркальная перестановка для char
    mirrorBitsChar(charNum, startBit, bitCount);

    // Вывод результата после изменений для char
    cout << "После изменения: ";
    printBinaryChar(charNum);  // Выводим двоичное представление после изменения

    // Выводим результат до изменений для long double
    cout << "\nДля long double:" << endl;
    cout << "До изменения: ";
    printBinaryLongDouble(longDoubleNum);  // Выводим двоичное представление для long double

    // Зеркальная перестановка для long double
    mirrorBitsLongDouble(longDoubleNum, startBit, bitCount);

    // Вывод результата после изменений для long double
    cout << "После изменения: ";
    printBinaryLongDouble(longDoubleNum);  // Выводим двоичное представление после изменения

    return 0;
}

