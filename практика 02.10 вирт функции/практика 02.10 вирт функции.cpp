// практика 02.10 вирт функции.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//базовый (родительский) класс
class Animal
{
protected:
    string Title; //кличка животного
public:
    //конструктор с параметром
    Animal (string T): Title{T} {}
    //virtual void Speak() //виртуальный метод, который будет перегружен в дочерних классах
    //{
    //    cout << "Издает звук" << endl;
    //}
    virtual void Speak() = 0; //чисто виртуал метод (без реализации)
    //с ним класс стал абстрактным и нельзя создать его объект
    //!!он обязан быть перегруженным в каждом дочернем классе
    //! 
    virtual ~Animal() {} //виртуал деструктор, при уничтожении дчених классов ч/з указатель на родительский класс
    //будут вызываться деструкторы дочерних классов, а не родительский
};
//дочерние классы
class Dog : virtual public Animal
{
    //Title унаследована от родителя
public:
    //конструктор дочернего класса Дог явно вызывает конструктор родительского класса
    //Animal для инициализации поля Титл
    Dog(string T): Animal (T) {}
    virtual  void Speak() override //проверяет на соответствие с родительским классом
    {
        cout << Title << " говорит ГАВ-ГАВ" << endl;
    }

};
class Cat : virtual public Animal
{
    //Title унаследована от родителя
public:
    //конструктор дочернего класса Дог явно вызывает конструктор родительского класса
    //Animal для инициализации поля Титл
    Cat(string T) : Animal(T) {}
    virtual  void Speak() override
    {
        cout << Title << " говорит МЯУ-МЯУ" << endl;
    }

};
class Frog : public Animal
{
    //Title унаследована от родителя
public:
    //конструктор дочернего класса Дог явно вызывает конструктор родительского класса
    //Animal для инициализации поля Титл
    Frog(string T) : Animal(T) {}
    virtual  void Speak() override
    {
        cout << Title << " говорит КВА-КВА" << endl;
    }

};
class Lion : public Cat
{
    //Title унаследована от родителя
public:
    Lion(string T) : Cat(T), Animal(T) {}
    virtual  void Speak() override
    {
        cout << Title << " говорит РРРР" << endl;
    }
    //собственный метод класса Lion, может быть унаследован дочерними классами Lion
    void Speak(int)
    {
        cout << Title << " говорит Аум-Аум" << endl;
    }

};

class CatDog : public Cat, public Dog
{
public:
    //конструктор
    //CatDog(string T): Cat(T), Dog(T), Animal(T) {}
    CatDog(string TitleCat, string TitleDog) : Cat (TitleCat), Dog (TitleDog), Animal(TitleCat+"о"+TitleDog) {}
   //конструктор дочернего класса Котопес явно вызывает родительские классы и конструктор класса Animal
    virtual  void Speak() override
    {
        //cout << Animal::Title << "говорит МЯУ-ГАВ" << endl;
        cout << Animal::Title << " говорит МЯУ-ГАВ" << endl;
    }
};

//ДОМАШНЕЕ ЗАДАНИЕ
class Tiger : public Cat
{
public:
    Tiger(string T) : Cat(T), Animal(T) {}
    virtual  void Speak() override
    {
        cout << Title << " рычит РРРР" << endl;
    }
    void Speak(int)
    {
        cout << Title << " издает рык РРР" << endl;
    }

};
class Ligr : public Lion, public Tiger
{
public:
    Ligr(string T): Lion(T), Tiger(T), Animal(T) {}
    virtual  void Speak() override
    {
        cout << Animal::Title << " говорит РРР-АУМ" << endl;
    }
};

int main()
{
    system("chcp 1251");
    system("cls");
    const int Size = 7;
    //статический массив указателей на родительский класс Animal
    //хранит адреса объектов дочерних классов
    Animal* ZOO[Size] =
    {
        new Dog("Бобик"),
        new Cat("Пушок"),
        new Frog("Жаба"),
        new Lion("Симба"),
        new CatDog("Кот", "Пес"),
        new Tiger ("Тигра"),
        new Ligr("Лигр")
    };

    //ZOO[3]->Speak(); //вызов родительского метода, реализованного в дочернем классе 
    //через указатель на род класс Animal можно вызвать ТОЛЬКО виртуал метод родит класса 
  /*  Lion Lev ("Муфаса");
    Lev.Speak(10);*/




    int index = 0;
    do
    {
        system("cls");
        cout << R"(Выберете животное: 
            1. "Бобик"
            2. "Пушок"
            3. "Жаба"
            4. "Симба"
            5. "Котопес"
            6. "Тигра"
            7. Что за лев этот тигр?
            0. ВЫХОД
            )";
        do
        {
            cin >> index;
            if (index <0 || index > Size) cout << "error" << endl;
        } while (index <0 || index > Size);
            if (index == 0) break;
            ZOO[index - 1]->Speak();
            system("pause");

    } while (index != 0);

    //освобождение памяти
    for (int i = 0; i < Size; i++)
    {
        delete ZOO[i]; //деструктор класса Animal
        ZOO[i] = nullptr;
    }
}

