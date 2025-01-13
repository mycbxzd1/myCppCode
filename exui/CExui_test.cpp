
#include "ExuiHelp.h"
#include <iostream>
INT 打分界面高度;
WindowBoxEx Win;
WindowEx 窗口_EX;
MinutesboxEx 分组框;
PictureBoxEx 顶标题;
PictureBoxEx 背景图;

class 主界面
{
public:
    static void 创建() {

        窗口_EX.Create(Win, 10, 40, 100, 100, 1, 0, &Callback_winex , 255, 0, 0, "", 0, "UImaterial\\tkdgame_vs\\skin\\mainbgk.sk", "", L"", "", -1, 255, 1, 1, 0, "UImaterial\\tkdgame_vs\\skin\\empty_conbutt.sk");
        整体组件创建();
        
        当前比赛积分面板();
        
    }
    
private:
    static void 当前比赛积分面板() {
        INT 字体大小, 姓名标签宽度, 姓名标签高度, 道馆标签宽度, 道馆标签高度;
        布局 红方无比分布局, 蓝方无比分布局;
        字节集 道馆字体, 对局时间字体, 比分字体, 冒号字体, 当前回合字体;
 }
     
    
    static void 整体组件创建() {
        //顶标题
        
        顶标题.Create(窗口_EX, 组件居中取左(Win.getwidth(), Win.getwidth()/ 5), Win.gethight()/50, Win.getwidth() / 5, Win.gethight() / 12,1,0, &Callback_MinutesboxEx,255,0,0,"",0, "UImaterial\\tkdgame_vs\\skin\\toptittle.sk");
       //顶标题
        分组框.Create(窗口_EX, 0,Win.gethight()/7,Win.getwidth(),Win.gethight()*0.77,1,0,0,255,0,0,"",0,"UImaterial\\tkdgame_vs\\skin\\groupbox.sk");
      //背景图
        背景图.Create(分组框, 0, (分组框.GetHeight() - Win.gethight()) / 2, Win.getwidth() +4, Win.gethight(), 1, 0, 0, 255, 0, 0, "", 0, "");

        

    
    }
    static INT CALLBACK Callback_MinutesboxEx(int ctrhandle, int msg, int Parameter1, int Parameter2, int Parameter3, int Parameter4) {
        switch (msg)
        {
        default:
            break;
        }
        return(0);
    }

    static INT CALLBACK Callback_winex(int ctrhandle, int msg, int Parameter1, int Parameter2, int Parameter3, int Parameter4) {
        switch (msg)
        {
        default:
            break;
        }
        return(0);

    }
    
};

void 界面初始化() {
    打分界面高度 = Win.gethight() * 6 / 7;

}


INT CALLBACK Callback_win(INT hwnd, INT msg, INT wParam, INT lParam)
{
    switch (msg)
    {
    case  WM_CREATE:
    {
        界面初始化();

        主界面::创建();
        break;
    }   
    default:
        break;
    }
    return(0);



    return (0);

}
int main()
{
    InitExui(NULL, NULL);
    Win.Create(0,1,50,50,960,540, &Callback_win,true,false,"",L"比赛投屏");  
    Win.MessageLoop();
    return 0;
    



}






   