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

//====================================================================================

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
    TCell human{CROSS};
    TCell ai{ZERO};
    size_t turn{ 0 }; // Чётные - человек, нечётные - компьютер
    TProgress progress{ IN_PROGRESS };
};

//====================================================================================

inline void clearScr()
{
    system("cls");
    //cout << "\x1B[2j\x1B[H";
}

int32_t __fastcall getRendomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

//====================================================================================

void __fastcall initGame(TGame & g)
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

    if (getRendomNum(0, 1000) > 500)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
}


void __fastcall deinitGame(TGame & g)
{
    for (size_t i = 0; i < g.size; i++)
    {
        delete [] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

void __fastcall printGame(const TGame& g)
{
    cout << "     ";
    for (size_t x = 0; x < g.size; x++)
    {
        cout << x + 1 << "   ";
    }
    cout << endl;
    for (size_t y = 0; y < g.size; y++)
    {
        cout << " " << y + 1 << " | ";
        for (size_t x = 0; x < g.size; x++)
        {
            cout << g.ppField[y][x] << " | ";
        }
        cout << endl;
    }
    cout << endl << "Human: " << g.human << endl << "Computer: " << g.ai << endl << endl;
}

TProgress __fastcall getWon(const TGame& g)
{
    //Выигрыш в строках
    for (size_t y = 0; y < g.size; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
            {
                return WON_HUMAN;
            }
            if (g.ppField[y][0] == g.ai)
            {
                return WON_AI;
            }
        }
    }
    //Выигрыш в столбцах:
    for (size_t x = 0; x < g.size; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
            {
                return WON_HUMAN;
            }
            if (g.ppField[0][x] == g.ai)
            {
                return WON_AI;
            }
        }
    }
    //Выигрыш в диагоналях:
    if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
    {
        if (g.ppField[0][0] == g.human)
        {
            return WON_HUMAN;
        }
        if (g.ppField[0][0] == g.ai)
        {
             return WON_AI;
        }
    }
    if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[0][2])
    {
        if (g.ppField[1][1] == g.human)
        {
            return WON_HUMAN;
        }
        if (g.ppField[1][1] == g.ai)
        {
            return WON_AI;
        }
    }
    //Ничья:
    bool draw{ true };
    for (size_t y = 0; y < g.size; y++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return DRAW;
   
    return IN_PROGRESS;
}

TCoord __fastcall getHumanCoord(const TGame& g)
{
    TCoord c;
    do {
        cout << "Enter X (1..3): ";
        cin >> c.x;
        cout << "Enter Y (1..3): ";
        cin >> c.y;
        c.x--;
        c.y--;
    } while (c.x > 2 || c.y > 2 || g.ppField[c.y][c.x] != EMPTY);
    return c;
}

TCoord __fastcall getAICoord(TGame& g)
{
    // 1 PRE WIN SITUATION

    for (size_t y = 0; y < g.size; y++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    // 2 PRE FAIL SITUATION

    for (size_t y = 0; y < g.size; y++)
    {
        for (size_t x = 0; x < g.size; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    // 3 Ходы по приоритетам  и рандомайз по ним
    //Центр:
    if (g.ppField[1][1] == EMPTY)
    {
        return { 1, 1 };
    }

    //Углы:
    TCoord buf[4];
    size_t num{ 0 };
    if (g.ppField[0][0] == EMPTY)
    {
        buf[num] = { 0,0 };
        num++;
    }
    if (g.ppField[2][2] == EMPTY)
    {
        buf[num] = { 2,2 };
        num++;
    }
    if (g.ppField[0][2] == EMPTY)
    {
        buf[num] = { 0,2 };
        num++;
    }
    if (g.ppField[2][0] == EMPTY)
    {
        buf[num] = { 2,0 };
        num++;
    }
    if (num > 0)
    {
        const size_t index = rand() % num;
        return buf[index];
    }

    //Не углы:
    num = 0;
    if (g.ppField[0][1] == EMPTY)
    {
        buf[num] = { 0,1 };
        num++;
    }
    if (g.ppField[1][0] == EMPTY)
    {
        buf[num] = { 1,0 };
        num++;
    }
    if (g.ppField[1][2] == EMPTY)
    {
        buf[num] = { 1,2 };
        num++;
    }
    if (g.ppField[2][1] == EMPTY)
    {
        buf[num] = { 2,1 };
        num++;
    }
    if (num > 0)
    {
        const size_t index = rand() % num;
        return buf[index];
    }
}

inline void congrats(const TGame& g)
{
    if (g.progress == WON_HUMAN)
    {
        cout << "Human won! =)" << endl;
    }
    else if (g.progress == WON_AI)
    {
        cout << "Computer won! =/" << endl;
    }
    else if (g.progress == DRAW)
    {
        cout << "Draw =(" << endl;
    }
}

//====================================================================================

int main()
{
    TGame g;
    initGame(g);

    clearScr();
    printGame(g);

    do {
        if (g.turn % 2 == 0)
        {
            //Ходит человек
            TCoord c = getHumanCoord(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            //Ходит компьютер
            TCoord c = getAICoord(g);
            g.ppField[c.y][c.x] = g.ai;
        }

        clearScr();
        printGame(g);
        g.turn++;
        g.progress = getWon(g);

    } while (g.progress == IN_PROGRESS);

    congrats(g);
    deinitGame(g);
    

}

//====================================================================================