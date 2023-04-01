// Запрограммировать игру крестики нолики на поле 3х3. Прислать cpp или ссылку на гит репозиторий.
// Для джуниоров : не обязательно делать крутой искусственный интеллект в игре.
// Но у вас должны корректно работать все основные моменты в игре, как например и главный цикл игры в main.
// Челендж для опытных и продвинутых : сделать решение на поле 4х4 или 5х5 или на динамическом поле, 
// размер которого ввел пользователь.
// Также можно запросить у пользователя количество фигур необходимое для выигрыша, 3 - 5.
//

#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

enum TCell : char {
    CROSS = 'X',
    ZERO = 'O',
    EMPTY = '_'

};

enum TProgress {
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct TCoord
{
    size_t y;
    size_t x;
};

struct TGame {
    TCell** ppField{nullptr};
    const size_t size{ 3 }; // 3x3
    TCell humsn;
    TCell ai;
    size_t turn{ 0 }; // Чётные - человек, нечётные - компьютер
    TProgress progress{ IN_PROGRESS };
};

void clearScr()
{
    // system("cls");
    cout << "\x1B[2j\x1B[H";
}

int32_t getRendomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void initGame(TGame & g)
{
    g.ppField = new TCell * [g.size];
    for (size_t i = 0; i < g.size; i++)
    {
        g.ppField[i] = new TCell[g.size];
    }

    for (size_t y = 0; y  < g.size; y ++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }
}


void deinitGame(TGame & g)
{
    
}

int main()
{
    TGame g;
    initGame(g);


    deinitGame(g);

}
