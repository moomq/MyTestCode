//
// Created by moomq on 2021/5/23.
//

#ifndef TESTCODE_CMDPARSE_H
#define TESTCODE_CMDPARSE_H


#define     MAX_CMD_NAME_LENGTH     20    // 最大命令名长度，过大 51 内存会炸
#define     MAX_CMDS_COUNT          10    // 最大命令数，过大 51 内存会炸
#define ARRAY_SIZE(x)	(sizeof(x) / (sizeof((x)[0])))

typedef void (*CmdFunc_Type)(void);        // 命令操作函数指针类型

/* 命令结构体类型 */
typedef struct{
    char cmd_name[MAX_CMD_NAME_LENGTH + 1];   // 命令名
    CmdFunc_Type cmd_func;                      // 命令操作函数
} CMD;

/* 命令列表结构体类型 */
typedef struct cmds
{
    CMD cmds[MAX_CMDS_COUNT];                 // 列表内容
    int num;	                              // 列表长度
} CMDS;

/* 外部函数声明 */
void register_cmds(CMD reg_cmds[], int num);
void match_cmd(const char *str);
void help();
class CmdParse {

};


#endif //TESTCODE_CMDPARSE_H
