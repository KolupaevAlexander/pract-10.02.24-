// Practic(10.02.24).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

//Удалить каждое четное слово

//Определяет символ пунктуации
bool IsNotLetter(char symbol)
{
    char notLetter[] = { '/', ',', '-', ';', '"', ':' ,' ', '\t', '.'};
    for (int i = 0; i < sizeof(notLetter); i++)
    {
        if (symbol == notLetter[i])
        {
            return true;
        }
    }
    return false;
}

//Получает индекс начала буквенных символов
int GetStartIndex(char* string)
{
    for (int i = 0; i < sizeof(string); i++)
    {
        if (!IsNotLetter(string[i]))
            return i;
    }
}

//Редактирует строку
char* EditString(char* string)
{
    char editingString[120];
    bool isEven = true;
    int editStringCounter = GetStartIndex(string);
    strncpy_s(editingString, string, editStringCounter+1);

    for (int i = GetStartIndex(string); i < strlen(string); i++)
    {
        if (isEven || IsNotLetter(string[i]))
        {
            editingString[editStringCounter] = string[i];
            editStringCounter++;
        }

        if (IsNotLetter(string[i]) && !IsNotLetter(string[i - 1]))
        {
            isEven = !isEven;
        }
    }

    editingString[editStringCounter] = '\0';
    return editingString;
}

int main()
{
    setlocale(LC_ALL,"Rus");
    char originalString[120];
    std::cout << "Введите строку\n";
    gets_s(originalString);

    printf(EditString(originalString));
}

