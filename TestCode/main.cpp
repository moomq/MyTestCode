#include <iostream>
#include "src/CmdParse/CmdParse.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

void hello()
{
    cout<<"hello"<<endl;
}

void good()
{
    cout<<"good"<<endl;
}

/* 填充命令结构体数组 */
CMD my_cmds[] = {
        {"hello", hello},
        {"good", good},
};

int main(int argc, char *argv[]) {

    /* 注册命令 */
    register_cmds(my_cmds, ARRAY_SIZE(my_cmds));

    while (true)
    {
        /* 获取命令字符串 */
        string str;
        cout<<"please input your cmd."<<endl;
        getline(cin,str);

        /* 匹配命令并执行 */
        match_cmd(str.c_str());
    }
    return 0;
}
