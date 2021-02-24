// 《数独解算程序》

// 文章地址： https://blog.csdn.net/u011146504/article/details/114001662

//原作：风休住 @2018.8.31
//bg4uvr 修改完善了一些逻辑，填加了一些注释 @2021.2.23

#include <iostream>
using namespace std;

//数独二维数组
int board[9][9];

//声明Check函数，用以检查所填的数是否合法
bool Check(int check_number, int check_now_line, int check_now_column);

//输入函数
void Input();

//工作函数
bool Work(int now_line, int now_column);

//输出函数
void Output();

//迭代计数器
int cnt;

//主函数
int main()
{
    cout << "\n\t\t《数独解算》\n"
         << endl;
    cnt = 0;
    Input();
    if (Work(0, 0))
        Output(); //如果有解，则调用输出函数
    else
        cout << "本题无解" << endl; //如果无解，则输出“No Answer.”
    return 0;
}

//声明Check函数，用以检查所填的数是否合法
//check_number为待检查的数字，check_now_line和check_now_column为待检查的坐标
bool Check(int check_number, int check_now_line, int check_now_column)
{
    for (int i = 0; i <= 8; ++i) //检查当前坐标同行或同列是否已经有相同数字
    {
        if (board[check_now_line][i] == check_number || board[i][check_now_column] == check_number)
            return false;
    }

    int check_block_line = (check_now_line / 3) * 3; //计算当前坐标所在小九宫格的左上角坐标
    int check_block_column = (check_now_column / 3) * 3;

    for (int i = 0; i <= 2; ++i) //检查当前坐标所在的小九宫格是否已经有相同数字
    {
        for (int j = 0; j <= 2; ++j)
        {
            if (board[check_block_line + i][check_block_column + j] == check_number)
                return false;
        }
    }
    return true; //通过所有检查，返回true
}

//读入数独矩阵
void Input()
{
    char temp[9][9];
    cout << "请输入一个9*9数独，每行连续9个数字，空位用0表示:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> temp[i][j];
            board[i][j] = temp[i][j] - '0';
        }
    }
}

//回溯算法核心逻辑函数
bool Work(int now_line, int now_column)
{
    cnt++; //用于计算实际迭代次数的计数器，+1

    if (now_line < 9) //如果还没运算完，则开始运算
    {
        int next_line;                    //下一格的行号
        int next_column = now_column + 1; //下一格的列号，等于当前格列号+1
        if (next_column >= 9)             //如果下格列号已经超过最后列
        {
            next_line = now_line + 1; //下一行的行号，等于当前行号+1
            next_column = 0;          //列号返回到最左侧
        }
        else
            next_line = now_line;

        //如果当前坐标有数字，则对下一个坐标进行工作
        if (board[now_line][now_column] != 0)
        {
            if (Work(next_line, next_column)) //如果下一格有解，则向前返回true
                return true;
            //运行到此处时，说明下一格运算失败了，下一步将运行本函数最后一条返回失败的语句
        }
        else //当前坐标为空格，进对当前格行运算
        {
            //分别尝试1-9这9种数字
            for (int i = 1; i <= 9; ++i)
            {
                if (Check(i, now_line, now_column)) //只去尝试实际可用的合法数值
                {
                    board[now_line][now_column] = i;  //尝试值 i 先临时填入本格
                    if (Work(next_line, next_column)) //然后对下一个坐标进行计算
                        return true;                  //如果下一格有解，则向前返回true

                    //代码运行到此处，说明本格在本次的i值情况下，下一格已经尝试失败(因为成功的情况时已经在上一行return了)
                }
                //所以再换下一个i值来重试
            }
            //程序运行到此处时，本格已经尝试完1-9，但后面的格计算均不能成功，说明前面的格尝试值不正确
            //所以本格恢复为空格（因为前面尝试时本格已临时填入了i值）
            board[now_line][now_column] = 0;
        }
        //本格非空，但一下格运算失败；或者本格为空，但试遍了1-9，后面的格均不能成功
        return false; //向前返回false
    }
    else
        return true; //已经计算完了最后一行，工作已完成
}

void Output()
{
    cout << endl;
    for (int i = 0; i <= 8; ++i)
    {
        for (int j = 0; j <= 8; ++j)
        {
            cout << board[i][j]
                 << " ";
        }
        cout << endl;
    }

    cout << '\n'
         << "本题迭代运算总次数: " << cnt << endl;
}

/*
示例数独：
1、号称史上最难的数独
800000000
003600000
070090200
050007000
000045700
000100300
001000068
008500010
090000400

2、一个普通的数独示例
615730000
392480000
704216953
900002317
150897426
267341598
570163842
831000000
426570139

*/