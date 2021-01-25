#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#define SIZE 16
using namespace std;

struct Logic {
    int** dat;              //바둑판 정보 2차원배열
          

    void MakeBoard();       //보드 메모리 할당
     
         //승리체크
    void DeleteBoard();     //보드 메모리 제거
};

struct Render {

    int** dat;
    char position[2];   
    int turn;               //현재 순서

    int WinCheck();
    void CheckTurn();       //턴 테크  
    void InputPosition();   //포지션 입력
    void CheckPosition();   //포지션 체크 (영문자 포지션 값 변경)   
    void DrawBoard();       //보드 그리기
    void DrawPiece();       //바둑알 그리기

};
//보드 메모리 할당
void Logic::MakeBoard()
{
    if (dat == NULL)
    {
        dat = (int**) new int* [SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            dat[i] = (int*) new int[SIZE];
            memset(dat[i], 0, sizeof(int) * SIZE);
        }
    }
}
//턴 테크
void Render::CheckTurn()
{
    //백
    if (turn == 0)
        turn = 1;
    //흑
    else
        turn = 0;
}
//포지션 체크 (영문자 포지션 값 변경)
void Render::CheckPosition()
{
    for (int i = 0; i < 2; i++)
    {
        if (position[i] >= '0' && position[i] <= '9')
            position[i] -= '0';
        else if (position[i] >= 'a' && position[i] <= 'f')
            position[i] = position[i] - 'a' + 10;
    }
}
//승리체크
int Render::WinCheck()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //백돌
            //가로
            if (dat[i][j] == 1 && dat[i][j + 1] == 1 && dat[i][j + 2] == 1 && dat[i][j + 3] == 1 && dat[i][j + 4] == 1)
                return 1;
            //세로
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j] == 1 && dat[i + 2][j] == 1 && dat[i + 3][j] == 1 && dat[i + 4][j] == 1)
                return 1;
            //우측 대각선
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j + 1] == 1 && dat[i + 2][j + 2] == 1 && dat[i + 3][j + 3] == 1 && dat[i + 4][j + 4] == 1)
                return 1;
            //좌측 대각선
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j - 1] == 1 && dat[i + 2][j - 2] == 1 && dat[i + 3][j - 3] == 1 && dat[i + 4][j - 4] == 1)
                return 1;
            //흑돌
            //가로
            if (dat[i][j] == 2 && dat[i][j + 1] == 2 && dat[i][j + 2] == 2 && dat[i][j + 3] == 2 && dat[i][j + 4] == 2)
                return 2;
            //세로
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j] == 2 && dat[i + 2][j] == 2 && dat[i + 3][j] == 2 && dat[i + 4][j] == 2)
                return 2;
            //우측 대각선
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j + 1] == 2 && dat[i + 2][j + 2] == 2 && dat[i + 3][j + 3] == 2 && dat[i + 4][j + 4] == 2)
                return 2;
            //좌측 대각선
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j - 1] == 2 && dat[i + 2][j - 2] == 2 && dat[i + 3][j - 3] == 2 && dat[i + 4][j - 4] == 2)
                return 2;
        }
    }
    return 0;
}
//보드 메모리 제거
void Logic::DeleteBoard()
{
    if (dat != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            delete[] dat[i];
        }
        delete[] dat;
    }

}
//포지션 입력
void Render::InputPosition()
{
    cout << "Input Position: ";
    for (int i = 0; i < 2; i++)
        cin >> position[i];
}
//보드 그리기
void Render::DrawBoard()
{
    system("cls");
    int t = 0;
    //바둑판 위 숫자
    for (int i = 0; i < 16; i++)
    {
        if (i < 10)cout << i << setw(2);
        else cout << (char)(i + 'a' - 10) << setw(2);
    }
    cout << endl;

    //바둑판 맨위

    if (dat[0][0] == 0)
        cout << "┌ ";
    else if (dat[0][0] == 1)
        cout << "●";
    else
        cout << "○";

    for (int i = 1; i < 15; i++)
    {
        if (dat[0][i] == 0)
            cout << "┬ ";
        else if (dat[0][i] == 1)
            cout << "●";
        else
            cout << "○";
    }

    if (dat[0][15] == 0)
        cout << "┐";
    else if (dat[0][15] == 1)
        cout << "●";
    else
        cout << "○";

    cout << setw(2) << t++ << endl;

    //바둑판 중앙
    for (int i = 1; i < 15; i++) {
        if (dat[i][0] == 0)
            cout << "├ ";
        else if (dat[i][0] == 1)
            cout << "●";
        else
            cout << "○";
        for (int j = 1; j < 15; j++)
        {
            if (dat[i][j] == 0)
                cout << "┼ ";
            else if (dat[i][j] == 1)
                cout << "●";
            else
                cout << "○";
        }
        if (i <= 9)
        {
            if (dat[i][15] == 0)
                cout << "┤";
            else if (dat[i][15] == 1)
                cout << "●";
            else
                cout << "○";
            cout << setw(2) << t++ << endl;
        }
        else
        {
            if (dat[i][15] == 0)
                cout << "┤";
            else if (dat[i][15] == 1)
                cout << "●";
            else
                cout << "○";
            cout << setw(2) << (char)(t++ + 'a' - 10) << endl;
        }
    }
    //바죽판 맨아래
    if (dat[15][0] == 0)
        cout << "└ ";
    else if (dat[15][0] == 1)
        cout << "●";
    else
        cout << "○";

    for (int i = 1; i < 15; i++)
    {
        if (dat[15][i] == 0)
            cout << "┴ ";
        else if (dat[15][i] == 1)
            cout << "●";
        else
            cout << "○";
    }
    if (dat[15][15] == 0)
        cout << "┘";
    else if (dat[15][15] == 1)
        cout << "●";
    else
        cout << "○";
    cout << setw(2) << (char)(t + 'a' - 10) << endl;
}
//바둑알 그리기
void Render::DrawPiece()
{
    if (turn == 1)
    {
        if (dat[position[0]][position[1]] == 0)
            dat[position[0]][position[1]] = 2;
        else
        {
            //cout << "이미 입력되있는 포지션입니다."<<endl;
            turn = 0;
        }
    }
    else if (turn == 0)
    {
        if (dat[position[0]][position[1]] == 0)
            dat[position[0]][position[1]] = 1;
        else
        {
            //cout << "이미 입력되있는 포지션입니다." << endl;
            turn = 1;
        }
    }
}

int main() {
    Render* render = 0;
    Logic logic = { 0 };

    if (render == NULL)
        render = (Render*) new Render;

    logic.MakeBoard();
    render->dat = logic.dat;
    int winCheck = 0;
    while (1)
    {
        render->DrawBoard();
        render->InputPosition();
        render->CheckPosition();
        render->CheckTurn();
        render->DrawPiece();
        winCheck = render->WinCheck();
        if (winCheck != 0)break;
    }
    if (winCheck == 1)
        cout << "백돌의 승리";
    else if (winCheck == 2)
        cout << "흑돌의 승리";

    //해제
    logic.DeleteBoard();
    if (render != NULL)
        delete render;
}