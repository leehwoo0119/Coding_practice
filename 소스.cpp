#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#define SIZE 16
using namespace std;

struct Logic {
    int** dat;              //�ٵ��� ���� 2�����迭
          

    void MakeBoard();       //���� �޸� �Ҵ�
     
         //�¸�üũ
    void DeleteBoard();     //���� �޸� ����
};

struct Render {

    int** dat;
    char position[2];   
    int turn;               //���� ����

    int WinCheck();
    void CheckTurn();       //�� ��ũ  
    void InputPosition();   //������ �Է�
    void CheckPosition();   //������ üũ (������ ������ �� ����)   
    void DrawBoard();       //���� �׸���
    void DrawPiece();       //�ٵϾ� �׸���

};
//���� �޸� �Ҵ�
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
//�� ��ũ
void Render::CheckTurn()
{
    //��
    if (turn == 0)
        turn = 1;
    //��
    else
        turn = 0;
}
//������ üũ (������ ������ �� ����)
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
//�¸�üũ
int Render::WinCheck()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //�鵹
            //����
            if (dat[i][j] == 1 && dat[i][j + 1] == 1 && dat[i][j + 2] == 1 && dat[i][j + 3] == 1 && dat[i][j + 4] == 1)
                return 1;
            //����
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j] == 1 && dat[i + 2][j] == 1 && dat[i + 3][j] == 1 && dat[i + 4][j] == 1)
                return 1;
            //���� �밢��
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j + 1] == 1 && dat[i + 2][j + 2] == 1 && dat[i + 3][j + 3] == 1 && dat[i + 4][j + 4] == 1)
                return 1;
            //���� �밢��
            else if (i < 12 && dat[i][j] == 1 && dat[i + 1][j - 1] == 1 && dat[i + 2][j - 2] == 1 && dat[i + 3][j - 3] == 1 && dat[i + 4][j - 4] == 1)
                return 1;
            //�浹
            //����
            if (dat[i][j] == 2 && dat[i][j + 1] == 2 && dat[i][j + 2] == 2 && dat[i][j + 3] == 2 && dat[i][j + 4] == 2)
                return 2;
            //����
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j] == 2 && dat[i + 2][j] == 2 && dat[i + 3][j] == 2 && dat[i + 4][j] == 2)
                return 2;
            //���� �밢��
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j + 1] == 2 && dat[i + 2][j + 2] == 2 && dat[i + 3][j + 3] == 2 && dat[i + 4][j + 4] == 2)
                return 2;
            //���� �밢��
            else if (i < 12 && dat[i][j] == 2 && dat[i + 1][j - 1] == 2 && dat[i + 2][j - 2] == 2 && dat[i + 3][j - 3] == 2 && dat[i + 4][j - 4] == 2)
                return 2;
        }
    }
    return 0;
}
//���� �޸� ����
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
//������ �Է�
void Render::InputPosition()
{
    cout << "Input Position: ";
    for (int i = 0; i < 2; i++)
        cin >> position[i];
}
//���� �׸���
void Render::DrawBoard()
{
    system("cls");
    int t = 0;
    //�ٵ��� �� ����
    for (int i = 0; i < 16; i++)
    {
        if (i < 10)cout << i << setw(2);
        else cout << (char)(i + 'a' - 10) << setw(2);
    }
    cout << endl;

    //�ٵ��� ����

    if (dat[0][0] == 0)
        cout << "�� ";
    else if (dat[0][0] == 1)
        cout << "��";
    else
        cout << "��";

    for (int i = 1; i < 15; i++)
    {
        if (dat[0][i] == 0)
            cout << "�� ";
        else if (dat[0][i] == 1)
            cout << "��";
        else
            cout << "��";
    }

    if (dat[0][15] == 0)
        cout << "��";
    else if (dat[0][15] == 1)
        cout << "��";
    else
        cout << "��";

    cout << setw(2) << t++ << endl;

    //�ٵ��� �߾�
    for (int i = 1; i < 15; i++) {
        if (dat[i][0] == 0)
            cout << "�� ";
        else if (dat[i][0] == 1)
            cout << "��";
        else
            cout << "��";
        for (int j = 1; j < 15; j++)
        {
            if (dat[i][j] == 0)
                cout << "�� ";
            else if (dat[i][j] == 1)
                cout << "��";
            else
                cout << "��";
        }
        if (i <= 9)
        {
            if (dat[i][15] == 0)
                cout << "��";
            else if (dat[i][15] == 1)
                cout << "��";
            else
                cout << "��";
            cout << setw(2) << t++ << endl;
        }
        else
        {
            if (dat[i][15] == 0)
                cout << "��";
            else if (dat[i][15] == 1)
                cout << "��";
            else
                cout << "��";
            cout << setw(2) << (char)(t++ + 'a' - 10) << endl;
        }
    }
    //������ �ǾƷ�
    if (dat[15][0] == 0)
        cout << "�� ";
    else if (dat[15][0] == 1)
        cout << "��";
    else
        cout << "��";

    for (int i = 1; i < 15; i++)
    {
        if (dat[15][i] == 0)
            cout << "�� ";
        else if (dat[15][i] == 1)
            cout << "��";
        else
            cout << "��";
    }
    if (dat[15][15] == 0)
        cout << "��";
    else if (dat[15][15] == 1)
        cout << "��";
    else
        cout << "��";
    cout << setw(2) << (char)(t + 'a' - 10) << endl;
}
//�ٵϾ� �׸���
void Render::DrawPiece()
{
    if (turn == 1)
    {
        if (dat[position[0]][position[1]] == 0)
            dat[position[0]][position[1]] = 2;
        else
        {
            //cout << "�̹� �Էµ��ִ� �������Դϴ�."<<endl;
            turn = 0;
        }
    }
    else if (turn == 0)
    {
        if (dat[position[0]][position[1]] == 0)
            dat[position[0]][position[1]] = 1;
        else
        {
            //cout << "�̹� �Էµ��ִ� �������Դϴ�." << endl;
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
        cout << "�鵹�� �¸�";
    else if (winCheck == 2)
        cout << "�浹�� �¸�";

    //����
    logic.DeleteBoard();
    if (render != NULL)
        delete render;
}