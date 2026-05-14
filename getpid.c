#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int stricmp(const char* str1,const char* str2){
 while(true){
    int d =(int)tolower((unsigned char)*str1)-(int)tolower((unsigned char)*str2);
    if(d!=0 || !*str1){
        return d;
    }
    str1++; str2++;
 };

}


DWORD GetProcessPID(const char* target){
HANDLE SnapHandle = CreateToolhelp32Snapshot(0x00000002,0);
PROCESSENTRY32 P_Config;
P_Config.dwSize = sizeof(PROCESSENTRY32);
Process32First(SnapHandle,&P_Config);
do{    
if(!stricmp(P_Config.szExeFile,target)) {    
    return P_Config.th32ProcessID;
}
}
while (Process32Next(SnapHandle,&P_Config));
return 0;
}

