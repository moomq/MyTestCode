#include <iostream>
#include "CmdParse/CmdParse.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
using namespace std;

#define ELPP_STL_LOGGING
// #define ELPP_FEATURE_CRASH_LOG -- Stack trace not available for MinGW GCC
#define ELPP_PERFORMANCE_MICROSECONDS
#define ELPP_LOG_STD_ARRAY
#define ELPP_LOG_UNORDERED_MAP
#define ELPP_UNORDERED_SET
#include "easylogging++.h"
#include "MultiTimerTest.h"
#include "TestBase64.h"
#include "cJsonTest.h"
INITIALIZE_EASYLOGGINGPP

//TIMED_SCOPE(appTimer, "myapplication");

void test()
{
    cout<<"good1"<<endl;
}
void easylog()
{
    LOG(INFO) << "Test " << __FILE__;
}

void Base64test()
{
    testbase64();
}

void LogInit()
{
    el::Configurations conf("../../log_cfg/console.conf");
    el::Loggers::reconfigureAllLoggers(conf);
}

/* 填充命令结构体数组 */
CMD my_cmds[] = {
        {"test", test},
        {"easylog",easylog},
        {"timer", TimerTest},
        {"base64", Base64test},
        {"json",cJSONTest},
};

int main(int argc, char *argv[]) {

    LogInit();
    /* 注册命令 */
    register_cmds(my_cmds, ARRAY_SIZE(my_cmds));


    while (true)
    {
        /* 获取命令字符串 */
        string str;
        cout<<"[cmd]$";
        getline(cin,str);

        /* 匹配命令并执行 */
        match_cmd(str.c_str());
    }
    return 0;
}
