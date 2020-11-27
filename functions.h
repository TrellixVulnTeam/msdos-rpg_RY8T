#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include<windows.h>
#include<cstdio>
#include<fstream>

inline void GameInit();
bool ctrlhandler(DWORD);
void GameExit();

inline void GameInit()
{
    printf("正在启动游戏...\n");
    Sleep(500);
    if( SetConsoleCtrlHandler( (PHANDLER_ROUTINE) ctrlhandler, true ) ) 
    { 
        /*
        printf( "\nthe control handler is installed.\n" ); 
        printf( "\n -- now try pressing ctrl+c or ctrl+break, or" ); 
        printf( "\n try logging off or closing the console...\n" ); 
        printf( "\n(...waiting in a loop for events...)\n\n" );
        */
        /*while( 1 ){ Sleep(100);}*/
        printf("Control Hanler启动成功!\n");
        Sleep(300);
        system("cls");
    } 
    else
    {
        printf( "\nFatal致命错误:无法设置控件处理程序(Control Handler)\n");
        system("pause");
        exit(1);
    }
}

bool ctrlhandler( DWORD fdwctrltype ) 
{ 
    switch( fdwctrltype ) 
    { 
    // handle the ctrl-c signal. 
    case CTRL_C_EVENT: 
        //printf( "ctrl-c event\n\n" );
        return true;

    // ctrl-close: confirm that the user wants to exit. 
    case CTRL_CLOSE_EVENT: 
        //printf( "ctrl-close event\n\n" );
        
        return true; 

    // pass other signals to the next handler. 
    case CTRL_BREAK_EVENT: 
        //printf( "ctrl-break event\n\n" );
        return false; 

    case CTRL_LOGOFF_EVENT: 
        //printf( "ctrl-logoff event\n\n" );
        return false; 

    case CTRL_SHUTDOWN_EVENT: 
        //printf( "ctrl-shutdown event\n\n" );
        return false; 

    default: 
        return false; 
    } 
} 

void GameExit()
{
    MessageBox(NULL,TEXT("正在退出游戏..."),TEXT("MSDos-RPG"),MB_OK|MB_ICONINFORMATION);
    
}

#endif