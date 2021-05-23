//
// Created by moomq on 2021/5/23.
//

#include "CmdParse.h"
/******************************************************************************
* 文件名称： cmd.c
* 摘 要：    命令解析器定义文件
* 当前版本： 1.0
* 作 者：    邵国际
* 完成日期： 2017年11月18日
*
* 取代版本：
* 原作者 ：
* 完成日期：
******************************************************************************/
#include <cstring>
#include <iostream>

CMD Help = {"help",help};
static CMDS commands = {
      .cmds =  {Help},
      .num = 1
};  // 全局命令列表，保存已注册命令集合

/******************************************************************************
* 函数介绍： 命令注册函数
* 输入参数： reg_cmds 待注册命令数组
*            num      待注册命令数组长度
* 输出参数： 无
* 返回值 ：  无
* 备    注： num 不得超过 MAX_CMDS_COUNT
******************************************************************************/
void register_cmds(CMD reg_cmds[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (commands.num < MAX_CMDS_COUNT)  // 命令列表未满
        {
            strcpy(commands.cmds[commands.num].cmd_name, reg_cmds[i].cmd_name);
            commands.cmds[commands.num].cmd_func = reg_cmds[i].cmd_func;
            commands.num++;
        } else
        {
            printf("commands is full");
            break;
        }
    }
}

/******************************************************************************
* 函数介绍： 命令匹配执行函数
* 输入参数： str 待匹配命令字符串
* 输出参数： 无
* 返回值 ：  无
* 备    注： str 长度不得超过 MAX_CMD_NAME_LENGTH
******************************************************************************/
void match_cmd(const char *str)
{
    if (strlen(str) > MAX_CMD_NAME_LENGTH)
    {
        return;
    }

    for (int i = 0; i < commands.num; i++)	// 遍历命令列表
    {
        if (strcmp(commands.cmds[i].cmd_name, str) == 0)
        {
            return commands.cmds[i].cmd_func();
        }
    }
    printf("No Such Command.");
}

void help()
{
    for(int i=0;i<commands.num;i++)
    {
        printf("%s\r\n",commands.cmds[i].cmd_name);
    }
}

/********************************END OF FILE**********************************/
