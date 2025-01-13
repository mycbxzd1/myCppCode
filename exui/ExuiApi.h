
#pragma once


#include "windows.h"

/*------------------------------------------EXUI数据类型------------------------------------------*/



#define ImageEX_P void *
struct  ImageEX;
#define BinEx_P void *
struct  BinEx;
#define Control_P void *
struct  Control;
#define StrEx_P void *
struct  StrEx;
#define MenuEx_P void *
struct  MenuEx;
#define MenuInfo_P void *
struct  MenuInfo;
#define MenuInfo_P_P void *
struct  MenuInfo;
#define DownlistEx_P void *
struct  DownlistEx;
#define WindowEx_P void *
struct  WindowEx;
#define LabelEx_P void *
struct  LabelEx;
#define FilterEx_P void *
struct  FilterEx;
#define ButtonEx_P void *
struct  ButtonEx;
#define ImagebuttonEx_P void *
struct  ImagebuttonEx;
#define SuperbuttonEx_P void *
struct  SuperbuttonEx;
#define ChoiceboxEx_P void *
struct  ChoiceboxEx;
#define RadiobuttonEx_P void *
struct  RadiobuttonEx;
#define EditboxEx_P void *
struct  EditboxEx;
#define ComboboxEx_P void *
struct  ComboboxEx;
#define MinutesboxEx_P void *
struct  MinutesboxEx;
#define MultifunctionButtonEx_P void *
struct  MultifunctionButtonEx;
#define PictureBoxEx_P void *
struct  PictureBoxEx;
#define ProgressbarEx_P void *
struct  ProgressbarEx;
#define ScrollbarEx_P void *
struct  ScrollbarEx;
#define SliderbarEx_P void *
struct  SliderbarEx;
#define SelectthefolderEx_P void *
struct  SelectthefolderEx;
#define ToolbarEx_P void *
struct  ToolbarEx;
#define ListboxEx_P void *
struct  ListboxEx;
#define SuperListboxEx_P void *
struct  SuperListboxEx;
#define IcoListboxEx_P void *
struct  IcoListboxEx;
#define TreeListEx_P void *
struct  TreeListEx;
#define WebBrowserEx_P void *
struct  WebBrowserEx;
#define CalendarBoxEx_P void *
struct  CalendarBoxEx;
#define ColorPickEx_P void *
struct  ColorPickEx;
#define RichEditEx_P void *
struct  RichEditEx;
#define ExtendEx_P void *
struct  ExtendEx;
#define AnimationbuttonEx_P void *
struct  AnimationbuttonEx;
#define AdvancedFormEx_P void *
struct  AdvancedFormEx;
#define SlideButtonEx_P void *
struct  SlideButtonEx;
#define PieChartEx_P void *
struct  PieChartEx;
#define BarChartEx_P void *
struct  BarChartEx;
#define CurveChartEx_P void *
struct  CurveChartEx;
#define  CandleChartEx_P void *
struct   CandleChartEx;

#define  DrawPanelEx_P void *
struct   DrawPanelEx;



#define StructEx_P void *
struct  StructEx;



/*------------------------------------------EXUI常量------------------------------------------*/



/*------------------------------------------EXUI命令------------------------------------------*/

/*--------------Category1--------------*/

#define 	EX_UI_CMDINFO_Category1(CMDINFO)  \
    /*--------调用exui内部功能--------*/\
    CMDINFO( int ,  CallInternalFunction_Ex , ( int msg,int parameter1,int parameter2,int parameter3,int parameter4 ) ); \
    \
    /*--------装载位图--------*/\
    CMDINFO( ImageEX_P ,  LoadImageEx , ( BinEx_P data ,int Mode,int Width,int Height,int Angle,int LineClour, int LineWidth, int Alignment) ); \
    \
    /*--------销毁位图--------*/\
    CMDINFO( void ,  DestroyImageEx , ( ImageEX_P image ) ); \
    \
    /*--------取位图属性--------*/\
    CMDINFO( int ,  GetImageAttributeEx , ( ImageEX_P image, int Type ) ); \
    \
    /*--------取位图数据--------*/\
    CMDINFO( BinEx_P ,  GetImageData , ( ImageEX_P image ) ); \
    \
    /*--------创建内存Ex--------*/\
    CMDINFO( BinEx_P ,  CreateBinEx , ( void * data,int datalength ) ); \
    \
    /*--------销毁内存Ex--------*/\
    CMDINFO( void ,  DeleteBinEx , ( BinEx_P binex ) ); \
    \
    /*--------取内存Ex数据地址--------*/\
    CMDINFO( void * ,  GetBinExDataPointer , ( BinEx_P binex ) ); \
    \
    /*--------取内存Ex数据长度--------*/\
    CMDINFO( int ,  GetBinExDatalength , ( BinEx_P binex ) ); \
    \
    /*--------取内存Ex缓存指针 CMDINFO( BinEx*GetBInExCache--------*/\
    CMDINFO( BinEx_P ,  GetBInExCache , ( BinEx_P binex ) ); \
    \
    /*--------组件创建--------*/\
    CMDINFO( BOOL ,  ControlCreate , ( Control_P control,Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,BOOL Visual,BOOL Disabled,int Transparency,void * Callback,void * PrivateEvent,int controlType,int Penetrate,BinEx_P Cursor,int focusweight,int sign ,BinEx_P Layout) ); \
    \
    /*--------组件销毁--------*/\
    CMDINFO( void ,  ControlDestroy , ( Control_P control ) ); \
    \
    /*--------组件是否已创建--------*/\
    CMDINFO( BOOL ,  ControlIsCreate , ( Control_P control ) ); \
    \
    /*--------组件发送消息--------*/\
    CMDINFO( int ,  ControlSendMessage , ( Control_P control,int msg,int Parameter1,int Parameter2,int Parameter3,int Parameter4 ) ); \
    \
    /*--------组件发送子级消息--------*/\
    CMDINFO( void ,  ControlSendChildMessage , ( Control_P control,int msg,int Parameter1,int Parameter2,int Parameter3,int Parameter4 ) ); \
    \
    /*--------组件更新缓存--------*/\
    CMDINFO( BOOL ,  ControlUpdateCache , (  ) ); \
    \
    /*--------组件取距窗口顶边--------*/\
    CMDINFO( int ,  ControlGetWindowTop , ( Control_P control ) ); \
    \
    /*--------组件取距窗口左边--------*/\
    CMDINFO( int ,  ControlGetWindowLeft , ( Control_P control ) ); \
    \
    /*--------组件置左边--------*/\
    CMDINFO( void ,  ControlSetLeft , ( Control_P control,int Left ) ); \
    \
    /*--------组件取左边--------*/\
    CMDINFO( int ,  ControlGetLeft , ( Control_P control ) ); \
    \
    /*--------组件置顶边--------*/\
    CMDINFO( void ,  ControlSetTop , ( Control_P control,int Top ) ); \
    \
    /*--------组件取顶边--------*/\
    CMDINFO( int ,  ControlGetTop , ( Control_P control ) ); \
    \
    /*--------组件置宽度--------*/\
    CMDINFO( void ,  ControlSetWidth , ( Control_P control,int Width ) ); \
    \
    /*--------组件取宽度--------*/\
    CMDINFO( int ,  ControlGetWidth , ( Control_P control ) ); \
    \
    /*--------组件置高度--------*/\
    CMDINFO( void ,  ControlSetHeight , ( Control_P control,int Height ) ); \
    \
    /*--------组件取高度--------*/\
    CMDINFO( int ,  ControlGetHeight , ( Control_P control ) ); \
    \
    /*--------组件取矩形--------*/\
    CMDINFO( void ,  ControlGetRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------组件置矩形--------*/\
    CMDINFO( void ,  ControlSetRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------组件取真实可视--------*/\
    CMDINFO( BOOL ,  ControlGetTrueVisual , ( Control_P control ) ); \
    \
    /*--------组件取可视--------*/\
    CMDINFO( BOOL ,  ControlGetVisual , ( Control_P control ) ); \
    \
    /*--------组件置可视--------*/\
    CMDINFO( void ,  ControlSetVisual , ( Control_P control,BOOL Visual ) ); \
    \
    /*--------组件取真实禁止--------*/\
    CMDINFO( BOOL ,  ControlGetTrueDisabled , ( Control_P control ) ); \
    \
    /*--------组件取禁止--------*/\
    CMDINFO( BOOL ,  ControlGetDisabled , ( Control_P control ) ); \
    \
    /*--------组件置禁止--------*/\
    CMDINFO( void ,  ControlSetDisabled , ( Control_P control,BOOL UpdateDisabled ) ); \
    \
    /*--------组件置光标--------*/\
    CMDINFO( void ,  ControlSetCursor , ( Control_P control,BinEx_P Cursor ) ); \
    \
    /*--------组件取光标--------*/\
    CMDINFO( BinEx_P ,  ControlGetCursor , ( Control_P control ) ); \
    \
    /*--------组件置光标id--------*/\
    CMDINFO( void ,  ControlSetCursorId , ( Control_P control,int CursorId ) ); \
    \
    /*--------组件取光标id--------*/\
    CMDINFO( int ,  ControlGetCursorId , ( Control_P control ) ); \
    \
    /*--------组件取鼠标穿透--------*/\
    CMDINFO( int ,  ControlGetPenetrate , ( Control_P control ) ); \
    \
    /*--------组件置鼠标穿透--------*/\
    CMDINFO( void ,  ControlSetPenetrate , ( Control_P control,int Penetrate ) ); \
    \
    /*--------组件取透明度--------*/\
    CMDINFO( int ,  ControlGetTransparency , ( Control_P control ) ); \
    \
    /*--------组件置透明度--------*/\
    CMDINFO( void ,  ControlSetTransparency , ( Control_P control,int Transparency ) ); \
    \
    /*--------组件置焦点权重--------*/\
    CMDINFO( void ,  ControlSetFocusWeight , ( Control_P control,int FocusWeight ) ); \
    \
    /*--------组件取焦点权重--------*/\
    CMDINFO( int ,  ControlGetFocusWeight , ( Control_P control ) ); \
    \
    /*--------组件置焦点组件--------*/\
    CMDINFO( void ,  ControlSetFocusControl , ( Control_P control ) ); \
    \
    /*--------组件取焦点组件--------*/\
    CMDINFO( Control_P ,  ControlGetFocusControl , (  ) ); \
    \
    /*--------组件取上一焦点组件--------*/\
    CMDINFO( Control_P ,  ControlGetMaxFocusWeightControl , ( Control_P control ) ); \
    \
    /*--------组件取下一焦点组件--------*/\
    CMDINFO( Control_P ,  ControlGetNextFocusControl , ( Control_P control ) ); \
    \
    /*--------组件取鼠标捕获组件--------*/\
    CMDINFO( Control_P ,  ControlGetCaptureControl , (  ) ); \
    \
    /*--------组件置鼠标捕获组件--------*/\
    CMDINFO( void ,  ControlSetCaptureControl , ( Control_P control ) ); \
    \
    /*--------组件取热点组件--------*/\
    CMDINFO( Control_P ,  ControlGetHotControl , (  ) ); \
    \
    /*--------组件取左键按下组件--------*/\
    CMDINFO( Control_P ,  ControlGetLeftPressControl , (  ) ); \
    \
    /*--------组件取右键按下组件--------*/\
    CMDINFO( Control_P ,  ControlGetRightPressControl , (  ) ); \
    \
    /*--------组件置类型--------*/\
    CMDINFO( void ,  ControlSetcontrolType , ( Control_P control,int controlType ) ); \
    \
    /*--------组件取类型--------*/\
    CMDINFO( int ,  ControlGetcontrolType , ( Control_P control ) ); \
    \
    /*--------组件置标识--------*/\
    CMDINFO( void ,  ControlSetsign , ( Control_P control,int sign ) ); \
    \
    /*--------组件取标识--------*/\
    CMDINFO( int ,  ControlGetsign , ( Control_P control ) ); \
    \
    /*--------组件置回调--------*/\
    CMDINFO( int ,  ControlSetCallback , ( Control_P control,void * PublicCallback, void * PrivateCallback ) ); \
    \
    /*--------组件取回调--------*/\
    CMDINFO( void * ,  ControlGetCallback , ( Control_P control, int GetMode ) ); \
    \
    /*--------组件调用回调--------*/\
    CMDINFO( int ,  ControInvokeCallback , ( Control_P control, int msg, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4 ,void * Callback )); \
    \
    /*--------组件取所在窗口句柄--------*/\
    CMDINFO( int ,  ControlGetWindow , ( Control_P control ) ); \
    \
    /*--------组件取组件绑定窗口--------*/\
    CMDINFO( int ,  ControlGetBindWin , ( Control_P control ) ); \
    \
    /*--------组件取窗口绑定组件--------*/\
    CMDINFO( Control_P ,  ControlGetBindControl , ( HWND WindowHandle ) ); \
    \
    /*--------组件取设备上下文--------*/\
    CMDINFO( int ,  ControlGetDc , ( Control_P control ) ); \
    \
    /*--------组件取图形--------*/\
    CMDINFO( int ,  ControlGetGraphics , ( Control_P control ) ); \
    \
    /*--------组件取位图--------*/\
    CMDINFO( int ,  ControlGetHBITMAP , ( Control_P control ) ); \
    \
    /*--------组件添加重绘区--------*/\
    CMDINFO( void ,  ControlAddRedrawRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------组件请求重绘--------*/\
    CMDINFO( void ,  ControlRedraw , ( Control_P control ) ); \
    \
    /*--------组件暂停重画--------*/\
    CMDINFO( int ,  ControlLockUpdate , ( Control_P control ) ); \
    \
    /*--------组件容许重画--------*/\
    CMDINFO( int ,  ControlUnlockUpdate , ( Control_P control ) ); \
    \
    /*--------组件取重画锁定计数--------*/\
    CMDINFO( int ,  ControlGetLockUpdateCount , ( Control_P control ) ); \
    \
    /*--------组件取父组件--------*/\
    CMDINFO( Control_P ,  ControlGetParentControl , ( Control_P control ) ); \
    \
    /*--------组件置父组件--------*/\
    CMDINFO( BOOL ,  ControlSetParentControl , ( Control_P control,Control_P Parentcontrol,BOOL mode,int NewLeft,int NewTop ) ); \
    \
    /*--------组件可有子级--------*/\
    CMDINFO( BOOL ,  ControlHaveChild , ( Control_P control ) ); \
    \
    /*--------组件取子级组件数--------*/\
    CMDINFO( int ,  ControlGetChildCount , ( Control_P control, BOOL mode ) ); \
    \
    /*--------组件枚举子级组件--------*/\
    CMDINFO( BinEx_P ,  ControlEnumerateChild , ( Control_P control, BOOL mode  ) ); \
    \
    /*--------组件取上一组件--------*/\
    CMDINFO( Control_P ,  ControlGetLastcontrol , ( Control_P control ) ); \
    \
    /*--------组件取下一组件--------*/\
    CMDINFO( Control_P ,  ControlGetNextcontrol , ( Control_P control ) ); \
    \
    /*--------组件取嵌套层次--------*/\
    CMDINFO( int ,  ControlGetNestingLevel , ( Control_P control ) ); \
    \
    /*--------组件取层次组件--------*/\
    CMDINFO( Control_P ,  ControlGetlevelcontrol , ( int level ) ); \
    \
    /*--------组件置层次--------*/\
    CMDINFO( void ,  ControlSetlevel , ( Control_P control,Control_P RelativeControl ) ); \
    \
    /*--------组件取层次--------*/\
    CMDINFO( int ,  ControlGetlevel , ( Control_P control ) ); \
    \
    /*--------组件置所在窗口分层透明--------*/\
    CMDINFO( void ,  ControlSetWinLayered , ( Control_P control,int Layered ) ); \
    \
    /*--------组件取所在窗口分层透明--------*/\
    CMDINFO( int ,  ControlGetWinLayered , ( Control_P control ) ); \
    \
    /*--------组件取所在窗口图形--------*/\
    CMDINFO( int ,  ControlGetWinGraphics , ( Control_P control ) ); \
    \
    /*--------组件取所在窗口位图--------*/\
    CMDINFO( int ,  ControlGetWinHBITMAP , ( Control_P control ) ); \
    \
    /*--------组件取所在窗口设备上下文--------*/\
    CMDINFO( int ,  ControlGetWinDc , ( Control_P control ) ); \
    \
    /*--------组件置所在窗口刷新回调--------*/\
    CMDINFO( int ,  ControlSetWinRefreshCallBack , ( Control_P control,int CallBack ) ); \
    \
    /*--------组件取所在窗口刷新回调--------*/\
    CMDINFO( int ,  ControlGetWinRefreshCallBack , ( Control_P control ) ); \
    \
    /*--------组件刷新所在窗口--------*/\
    CMDINFO( void ,  ControlRefreshWin , ( Control_P control ) ); \
    \
    /*--------组件暂停重画所在窗口--------*/\
    CMDINFO( int ,  ControlLockWinUpdate , ( Control_P control ) ); \
    \
    /*--------组件容许重画所在窗口--------*/\
    CMDINFO( int ,  ControlUnlockWinUpdate , ( Control_P control ) ); \
    \
    /*--------组件取所在窗口重画锁定状态--------*/\
    CMDINFO( int ,  ControlGetWinLockUpdateCount , ( Control_P control ) ); \
    /*--------组件取所在页面--------*/\
	CMDINFO(int ,  ControlGetPage,(Control_P    control)); \
	/*--------组件置所在页面--------*/\
	CMDINFO(void,   ControlSetPage,(Control_P   control, int Page)); \
	/*--------组件取当前页面--------*/\
	CMDINFO(int ,  ControlGetCurrentPage,(Control_P    control)); \
	/*--------组件置当前页面--------*/\
	CMDINFO(void,   ControlSetCurrentPage,(Control_P    control, int Page)); \
	/*--------组件取布局器--------*/\
	CMDINFO(BinEx_P, ControlGetLayoutConfig, (Control_P    control)); \
	/*--------组件置布局器--------*/\
	CMDINFO(void, ControlSetLayoutConfig, (Control_P    control, BinEx_P Layout)); \
	/*--------组件提交任务--------*/\
	CMDINFO(int, ControlSubmitTask, (Control_P    control, int type,int cmd,  int sign, int Parame)); \





/*--------------Category2--------------*/

#define 	EX_UI_CMDINFO_Category2(CMDINFO)  \
/*--------组件执行元素命令--------*/\
CMDINFO(int , ControlRunElemCmd, (Control_P control, int Type, int   index, int  ColumnId, int   CtrId, int Cmd, int parameter1, int parameter2, int parameter3, int parameter4)); \
\
/*--------置底层元素数量--------*/\
CMDINFO(void, ControlSetUnderlyElemCount, (Control_P control, int Type, int  cloid, int Num ) ); \
\
/*--------取底层元素数量--------*/\
CMDINFO(int, ControlGetUnderlyElemCount, (Control_P control, int Type, int  cloid ) ); \
\
/*--------组件插入元素--------*/\
    CMDINFO( int ,  ControlInsertElem , ( Control_P control,int Type,int cloid,int ctrlindex,int addnum ) ); \
    \
    /*--------组件删除元素--------*/\
    CMDINFO( void ,  ControlDeleteElem , ( Control_P control,int Type,int cloid,int delindex,int deletenum ) ); \
    \
    /*--------组件取元素数量--------*/\
    CMDINFO( int ,  ControlGetElemCount , ( Control_P control,int Type,int cloid ) ); \
    \
    /*--------组件重置元素--------*/\
    CMDINFO( void ,  ControlResetElem , ( Control_P control,int Type,int cloid,int delindex,int deletenum ) ); \
    \
    /*--------组件置元素属性_图片--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Imsge , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle ) ); \
    \
    /*--------组件取元素属性_图片--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Imsge , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_图片--------*/\
    CMDINFO( void ,  ControlSetElemData_Imsge , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,ImageEX_P IcoData ) ); \
    \
    /*--------组件取元素内容_图片--------*/\
    CMDINFO( int ,  ControlGetElemData_Imsge , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------组件置元素属性_文本--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Text , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Font,int Align ) ); \
    \
    /*--------组件取元素属性_文本--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Text , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_文本--------*/\
    CMDINFO( void ,  ControlSetElemData_Text , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor ) ); \
    \
    /*--------组件取元素内容_文本--------*/\
    CMDINFO( int ,  ControlGetElemData_Text , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------组件置元素属性_按钮--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Button , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,BinEx_P Font ) ); \
    \
    /*--------组件取元素属性_按钮--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Button , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_按钮--------*/\
    CMDINFO( void ,  ControlSetElemData_Button , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor,BOOL Select ) ); \
    \
    /*--------组件取元素内容_按钮--------*/\
    CMDINFO( int ,  ControlGetElemData_Button , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------组件置元素属性_选择框--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Select , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,BinEx_P Font,int IconWidth,int IconHeight ) ); \
    \
    /*--------组件取元素属性_选择框--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Select , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_选择框--------*/\
    CMDINFO( void ,  ControlSetElemData_Select , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor,int Select ) ); \
    \
    /*--------组件取元素内容_选择框--------*/\
    CMDINFO( int ,  ControlGetElemData_Select , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------组件置元素属性_编辑文本--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_EditText , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,int ShowMode, BinEx_P  Skin, BinEx_P  Font, int  Align, StrEx_P  PasswordSubstitution, BinEx_P Cursor, BOOL  Multiline, int InputMode, int  MaxInput, BinEx_P  EditFont, int  EditFontColor, int  CursorColor, int  SelectedFontColor, int SelectedColor, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuLanguage) ); \
    \
    /*--------组件取元素属性_编辑文本--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_EditText , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_编辑文本--------*/\
    CMDINFO( void ,  ControlSetElemData_EditText , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Content,int FontColor ) ); \
    \
    /*--------组件取元素内容_编辑文本--------*/\
    CMDINFO( int ,  ControlGetElemData_EditText , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
     \
    /*--------组件置元素属性_组合按钮--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_ComboButton , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P  Skin, BinEx_P  Font, int  IconWidth, int  IconHeight, int  Align) ); \
    \
    /*--------组件取元素属性_组合按钮--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_ComboButton , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_组合按钮--------*/\
    CMDINFO( void ,  ControlSetElemData_ComboButton , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  BackColor, int    image,  StrEx_P Content, int FontColor, int PartnerStay ) ); \
    \
    /*--------组件取元素内容_组合按钮--------*/\
    CMDINFO( int ,  ControlGetElemData_ComboButton , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------组件置元素属性_进度条--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Progressbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,int  Style ) ); \
    \
    /*--------组件取元素属性_进度条--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Progressbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_进度条--------*/\
    CMDINFO( void ,  ControlSetElemData_Progressbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  Position) ); \
    \
    /*--------组件取元素内容_进度条--------*/\
    CMDINFO( int ,  ControlGetElemData_Progressbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	\
    /*--------组件置元素属性_滑块条--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Sliderbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,int  Style) ); \
    \
    /*--------组件取元素属性_滑块条--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Sliderbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_滑块条--------*/\
    CMDINFO( void ,  ControlSetElemData_Sliderbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  Position ) ); \
    \
    /*--------组件取元素内容_滑块条--------*/\
    CMDINFO( int ,  ControlGetElemData_Sliderbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	\
    /*--------组件置元素属性_颜色--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Colour , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle) ); \
    \
    /*--------组件取元素属性_颜色--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Colour , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_颜色--------*/\
    CMDINFO( void ,  ControlSetElemData_Colour , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,int Stay,int   Colour) ); \
    \
    /*--------组件取元素内容_颜色--------*/\
    CMDINFO( int ,  ControlGetElemData_Colour , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	 \
    /*--------组件置元素属性_直线--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Line , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,int  LineWidth) ); \
    \
    /*--------组件取元素属性_直线--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Line , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------组件置元素内容_直线--------*/\
    CMDINFO( void ,  ControlSetElemData_Line , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int Stay,int   Colour ) ); \
    \
    /*--------组件取元素内容_直线--------*/\
    CMDINFO( int ,  ControlGetElemData_Line , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \


/*--------------Category3--------------*/

#define 	EX_UI_CMDINFO_Category3(CMDINFO)  \
    /*--------信息框Ex--------*/\
    CMDINFO( int ,  MsgBox_Ex , ( BinEx_P Ico,StrEx_P Title,BinEx_P TipIco,StrEx_P TipTitle,StrEx_P Button,int DefaultBtn,HWND hWndParent,int Style,BinEx_P Skin,void * callback,int Parameter ) ); \
    \
    /*--------输入框Ex--------*/\
    CMDINFO( StrEx_P ,  InputBox_Ex , ( BinEx_P Ico,StrEx_P Title,BinEx_P TipIco,StrEx_P TipTitle,StrEx_P Button,int DefaultBtn,StrEx_P Conten,int InputMode,StrEx_P PasswordSubstitution,int MaxInput,BOOL Multiline,int * SelectResult,HWND hWndParent,int Style,BinEx_P Skin,void * callback,int Parameter_ ) ); \
    \
    /*--------弹出提示框Ex--------*/\
    CMDINFO( int ,  PopUpTipBoxEx , (  BinEx_P Ico, StrEx_P TipTitle, int 	PopUpMode, int x, int  y, int width, int height, int  AutoCloseTime, int  Angle,   int BackColor, int BorderColor, int LineWidth, BinEx_P Font, int  FontColor, int  Align, int  Transparency) ); \
    \
    /*--------关闭提示框Ex--------*/\
    CMDINFO( void ,  CloseTipBoxEx , (  ) ); \
    \
	 /*--------精简输入框Ex--------*/\
    CMDINFO( StrEx_P ,  PopUpLiteInputEx , ( int X, int Y, int nWidth, int nHeight, int callback, StrEx_P Content, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, int  Align, BOOL  Multiline, BOOL  Wrapped,BinEx_P Skin, BinEx_P  Cursor, BinEx_P  Font, int  FontClour, int  SelectedFontColor, int  SelectedColor, int  CursorColor, int  ScrollBarMode,int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage)); \
    \
	/*--------时间选择框--------*/\
    CMDINFO( int ,  TimePickBox_Ex , ( BinEx_P Ico, StrEx_P  TipTitle, StrEx_P Button, int  DefaultBtn, int  Width, int  Height, StrEx_P  SelectionDate,  StrEx_P  MiniDate, StrEx_P  MaxDate, BOOL  OtherMonthClour, int TimeMode,  int  Language,  int * SelectResult, HWND hWndParent, int Style, BinEx_P  Skin, int   Callback, int  Parameter )   ); \
    \
    /*--------颜色选择框--------*/\
    CMDINFO( int ,  ColorPickExBox_Ex , (  BinEx_P  Ico, StrEx_P  TipTitle, StrEx_P Button, int  DefaultBtn, int  Width, int  Height,int  NowClour,   BinEx_P  QuickClours, int ClourMode,  int  ColorPickStyle ,   int * SelectResult,  HWND hWndParent, int Style, BinEx_P  Skin,   int   Callback, int  Parameter  ) ); \
    \
    /*--------弹出时间选择器--------*/\
    CMDINFO( int ,  PopUpTimePick_Ex , ( int LEFT, int  Top,int  Width, int  Height,  StrEx_P Button, int  DefaultBtn, StrEx_P  SelectionDate,  StrEx_P  MiniDate, StrEx_P  MaxDate, BOOL  OtherMonthClour, int TimeMode,  int  Language,   int * SelectResult, HWND hWndParent, int Style, BinEx_P  Skin, int   Callback, int  Parameter )   ); \
    \
    /*--------弹出颜色选择器--------*/\
    CMDINFO( int ,  PopUpColorPick_Ex , (int LEFT, int  Top, int  Width, int  Height, StrEx_P Button, int  DefaultBtn,  int  NowClour,   BinEx_P  QuickClours, int ClourMode,  int  ColorPickStyle ,   int * SelectResult,  HWND hWndParent, int Style, BinEx_P  Skin,   int   Callback, int  Parameter  ) ); \
    \
    /*--------文件选择框--------*/\
    CMDINFO( int ,  FileSelectionbox_Ex , (  ) ); \
    \
    /*--------弹出项目标题编辑器Ex--------*/\
    CMDINFO( StrEx_P ,  PopUpItemInputEx , ( Control_P     control, int index, int  cloid, int retain,int mode , StrEx_P  Content, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, int  Align, BOOL  Multiline, BOOL  Wrapped, BinEx_P  Skin,BinEx_P Cursor, BinEx_P  Font, int  FontClour, int  SelectedFontColor, int  SelectedColor, int  CursorColor, int  ScrollBarMode, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage) ); \



/*--------------Category4--------------*/

#define 	EX_UI_CMDINFO_Category4(CMDINFO)  \
    /*--------创建_菜单Ex--------*/\
    CMDINFO( MenuEx_P ,  Create_MenuEx , ( int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,int Transparency,void * callback,int MenuTag ) ); \
    \
    /*--------置属性_菜单Ex--------*/\
    CMDINFO( void ,  SetAttribute_MenuEx , ( MenuEx_P control,int index, int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,int Transparency,void * callback,int MenuTag ) ); \
    \
    /*--------取属性_菜单Ex--------*/\
    CMDINFO( int ,  GetAttribute_MenuEx , ( MenuEx_P control,int index ) ); \
    \
    /*--------销毁_菜单Ex--------*/\
    CMDINFO( void ,  Destroy_MenuEx , ( MenuEx_P control ) ); \
    \
    /*--------是否已弹出_菜单Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------弹出_菜单Ex--------*/\
    CMDINFO( void ,  PopUp_MenuEx , ( MenuEx_P menuEx,int MenuId,int left,int top,HWND hWndParent,BOOL Modal , Control_P ExceptionControl) ); \
    \
    /*--------关闭_菜单Ex--------*/\
    CMDINFO( void ,  Close_MenuEx , ( MenuEx_P contro,MenuInfo_P MenuIdl, BOOL Mode ) ); \
    \
    /*--------插入_菜单Ex--------*/\
    CMDINFO( int ,  InsertItem_MenuEx , ( MenuEx_P menuEx,MenuInfo_P ParentMenu,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int DisabledFontColor,int Width,int Size,int Type,BOOL Disabled ) ); \
    \
    /*--------删除_菜单Ex--------*/\
    CMDINFO( void ,  DeleteItem_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------取数量_菜单Ex--------*/\
    CMDINFO( int ,  GetItemCount_MenuEx , ( MenuEx_P control ) ); \
    \
    /*--------置图标_菜单Ex--------*/\
    CMDINFO( void ,  SetItemIco_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,ImageEX_P Ico ) ); \
    \
    /*--------取图标_菜单Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------置标题_菜单Ex--------*/\
    CMDINFO( void ,  SetItemTitle_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,StrEx_P Title ) ); \
    \
    /*--------取标题_菜单Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------取附加值_菜单Ex--------*/\
    CMDINFO( int ,  GetItemData_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------置附加值_菜单Ex--------*/\
    CMDINFO( void ,  SetItemData_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int Data ) ); \
    \
    /*--------取字体色_菜单Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------置字体色_菜单Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int FontColor ) ); \
    \
    /*--------取禁止字体色_菜单Ex--------*/\
    CMDINFO( int ,  GetItemDisabledFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------置禁止字体色_菜单Ex--------*/\
    CMDINFO( void ,  SetItemDisabledFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int DisabledFontColor ) ); \
    \
    /*--------置项目信息_菜单Ex--------*/\
    CMDINFO( void ,  SetItemInfo_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Type,int Size ) ); \
    \
    /*--------取项目信息_菜单Ex--------*/\
    CMDINFO( int ,  GetItemInfo_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId , int Type) ); \
    \
    /*--------置类型_菜单Ex--------*/\
    CMDINFO( void ,  SetItemType_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int Type ) ); \
    \
    /*--------取类型_菜单Ex--------*/\
    CMDINFO( int ,  GetItemType_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------取禁止_菜单Ex--------*/\
    CMDINFO( BOOL ,  GetItemDisabled_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------置禁止_菜单Ex--------*/\
    CMDINFO( void ,  SetItemDisabled_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,BOOL Disabled ) ); \
    \
	/*--------置项目宽度_菜单Ex--------*/\
    CMDINFO( void ,  SetItemWidth_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Width ) ); \
    \
    /*--------取项目宽度_菜单Ex--------*/\
    CMDINFO( int ,  GetItemWidth_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
	/*--------置项目高度_菜单Ex--------*/\
    CMDINFO( void ,  SetItemHeight_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Height ) ); \
    \
    /*--------取项目高度_菜单Ex--------*/\
    CMDINFO( int ,  GetItemHeight_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------取子菜单数量_菜单Ex--------*/\
    CMDINFO( int ,  GetSubItemCount_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------取子菜单_菜单Ex--------*/\
    CMDINFO( MenuInfo_P_P ,  GetSubItem_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int index ) ); \
    \



/*--------------Category5--------------*/

#define 	EX_UI_CMDINFO_Category5(CMDINFO)  \
    /*--------创建_下拉列表Ex--------*/\
    CMDINFO( DownlistEx_P ,  Create_DownlistEx , ( int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,BOOL AlternateColor,int ScrollBarMode,    int  CurrentSelection,  int Transparency,void * callback,int Tag ) ); \
    \
    /*--------销毁_下拉列表Ex--------*/\
    CMDINFO( void ,  Destroy_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------置属性_下拉列表Ex--------*/\
    CMDINFO( void ,  SetAttribute_DownlistEx , ( DownlistEx_P control,int index,  int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,BOOL AlternateColor,int ScrollBarMode,    int  CurrentSelection,  int Transparency,void * callback,int Tag ) ); \
    \
    /*--------取属性_下拉列表Ex--------*/\
    CMDINFO( int ,  GetAttribute_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------弹出_下拉列表Ex--------*/\
    CMDINFO( void ,  PopUp_DownlistEx , ( DownlistEx_P control,int X,int Y,int nWidth,int nHeight,HWND hWndParent,BOOL Modal ) ); \
    \
    /*--------关闭_下拉列表Ex--------*/\
    CMDINFO( void ,  Close_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------是否已弹出_下拉列表Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------插入_下拉列表Ex--------*/\
    CMDINFO( int ,  InsertItem_DownlistEx , ( DownlistEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------删除_下拉列表Ex--------*/\
    CMDINFO( void ,  DeleteItem_DownlistEx , ( DownlistEx_P control,int index,int deletenum ) ); \
    \
    /*--------取数量_下拉列表Ex--------*/\
    CMDINFO( int ,  GetItemCount_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------置附加值_下拉列表Ex--------*/\
    CMDINFO( void ,  SetItemData_DownlistEx , ( DownlistEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_下拉列表Ex--------*/\
    CMDINFO( int ,  GetItemData_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------置图标_下拉列表Ex--------*/\
    CMDINFO( void ,  SetItemIco_DownlistEx , ( DownlistEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_下拉列表Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------置标题_下拉列表Ex--------*/\
    CMDINFO( void ,  SetItemTitle_DownlistEx , ( DownlistEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取标题_下拉列表Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------置字体色_下拉列表Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_DownlistEx , ( DownlistEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_下拉列表Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------置项目高度_下拉列表Ex--------*/\
    CMDINFO( void ,  SetItemSize_DownlistEx , ( DownlistEx_P control,int index,int Size ) ); \
    \
    /*--------取项目高度_下拉列表Ex--------*/\
    CMDINFO( int ,  GetItemSize_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------保证显示_下拉列表Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_DownlistEx , ( DownlistEx_P control,int index,int mode ) ); \
    \


/*--------------Category6--------------*/

#define 	EX_UI_CMDINFO_Category6(CMDINFO)  \
    /*--------创建缓动任务--------*/\
    CMDINFO( int ,  CreateSlowMotionTaskEx , ( int Num, int  Mode, int Star, int End, int FrameDelay, int Step, int  Callback, int parameter, BOOL   Wait, BOOL AutoDestroy) ); \
    \
    /*--------置缓动任务配置--------*/\
    CMDINFO( void ,  SetSlowMotionTaskConfigEx , ( int Task_Queue, int  index, int  Mode, int Star, int End) ); \
    \
    /*--------等待缓动队列执行完毕--------*/\
    CMDINFO( int ,  SetSlowMotionTaskProgresEx , ( int Task_Queue, int Progres ) ); \
    \
    /*--------销毁缓动队列任务--------*/\
    CMDINFO( void ,  DestroySlowMotionTaskEx , (int Task_Queue  ) ); \
    /*--------播放窗口动画--------*/\
    CMDINFO(BOOL, PlayWindowAnimationEx , (Control_P control,  int scale, int AnimationType, int AlgorithmMode, int FrameDelay, int Step, BOOL FadeInAndOut, BOOL  Wait, BOOL DestroyControl) ); \
    \
    /*--------载入组件--------*/\
    CMDINFO(BOOL, LoadControlEx , (Control_P Parent,  HWND  Window, int  mode, int Parameter1, int Parameter2, BinEx_P bin, int   Callback, int  CallbackParameter) ); \
    \
    /*--------保存组件--------*/\
    CMDINFO(BinEx_P, packControlEx , (Control_P control,   HWND  Window,int  mode, int Parameter1, int Parameter2, int retain, int   Callback, int  CallbackParameter) ); \
	/*--------测量文本--------*/\
	CMDINFO(BinEx_P  , RexMeasureStringEx,(StrEx_P string, BinEx_P Font, int StringFormat, float x, float y, float width, float height, int mode)); \
	/*--------创建定时器--------*/\
	CMDINFO( int ,    CreateTimerEx,(int  DueTime, int  Period, int  TimeCallBack, int Parameter, BOOL  Reentry, BOOL wait,int Flags));\
	/*--------销毁定时器--------*/\
	CMDINFO(void,   DeleteTimerEx, (int time));\
	/*--------置定时器配置--------*/\
	CMDINFO(void, SetConfigTimerEx, (int 	time, int  DueTime, int  Period));\
	/*--------取定时器配置--------*/\
	CMDINFO(int,  GetConfigTimerEx, (int  time, int  type));\
	/*--------异常捕获--------*/\
	CMDINFO(void,  ExceptionCaptureEx, (int  callback,int callback2));\
	/*--------载入主题--------*/\
	CMDINFO(BOOL,  LoadThemeEx, (BinEx_P  Theme, HWND hwnd, int Callback,int Param));\
	/*--------创建窗口--------*/\
	CMDINFO(HWND,  Create_WindowBoxEx, ( int mode, int Location, HWND hWndParent, int X, int Y, int nWidth, int nHeight, int   WndProc, BOOL Visual, BOOL  Disabled,  BinEx_P Icon, StrEx_P Title,	BOOL AlwaysTop,BOOL Taskbar, BOOL EscClose, StrEx_P ClassName, int classstyle, int  dwExStyle, int   dwStyle, int Sign));\
	/*--------是否已创建--------*/\
CMDINFO(BOOL, IsWindow_WindowBoxEx, (HWND hwnd)); \
/*--------销毁窗口--------*/\
CMDINFO(void, Destroy_WindowBoxEx, (HWND hwnd)); \
/*--------窗口置左边--------*/\
CMDINFO(void, SetLeft_WindowBoxEx, (HWND hwnd, int   Left)); \
/*--------窗口取左边--------*/\
CMDINFO(int, GetLeft_WindowBoxEx, (HWND hwnd)); \
/*--------窗口置顶边--------*/\
CMDINFO(void, SetTop_WindowBoxEx, (HWND hwnd, int   Top)); \
/*--------窗口取顶边--------*/\
CMDINFO(int, GetTop_WindowBoxEx, (HWND hwnd)); \
/*--------窗口置宽度--------*/\
CMDINFO(void, SetWidth_WindowBoxEx, (HWND hwnd, int   Width)); \
/*--------窗口取宽度--------*/\
CMDINFO(int, GetWidth_WindowBoxEx, (HWND hwnd)); \
/*--------窗口置高度--------*/\
CMDINFO(void, SetHeight_WindowBoxEx, (HWND hwnd, int   Height)); \
/*--------窗口取高度--------*/\
CMDINFO(int, GetHeight_WindowBoxEx, (HWND hwnd)); \
/*--------置矩形--------*/\
CMDINFO(void, SetRect_WindowBoxEx, (HWND hwnd, int left, int top, int Width, int Height)); \
/*--------取矩形--------*/\
CMDINFO(void, GetRect_WindowBoxEx, (HWND hwnd, int  * Left, int  * Top, int   * Width, int  * Height)); \
/*--------置位置--------*/\
CMDINFO(void, SetLocation_WindowBoxEx, (HWND hwnd, int Location)); \
/*--------取位置--------*/\
CMDINFO(int, GetLocation_WindowBoxEx, (HWND hwnd)); \
/*--------取可视--------*/\
CMDINFO(BOOL, GetVisual_WindowBoxEx, (HWND hwnd)); \
/*--------置可视--------*/\
CMDINFO(void, SetVisual_WindowBoxEx, (HWND hwnd, BOOL  Visual)); \
/*--------取禁止--------*/\
CMDINFO(BOOL, GetDisabled_WindowBoxEx, (HWND hwnd)); \
/*--------置禁止--------*/\
CMDINFO(void, SetDisabled_WindowBoxEx, (HWND hwnd, BOOL  Disabled)); \
/*--------窗口置标识--------*/\
CMDINFO(void, SetSign_WindowBoxEx, (HWND hwnd, int   Sign)); \
/*--------窗口取标识--------*/\
CMDINFO(int, GetSign_WindowBoxEx, (HWND hwnd)); \
/*--------置父窗口--------*/\
CMDINFO(void, SetParent_WindowBoxEx, (HWND hwnd, HWND  Parent)); \
/*--------取父窗口--------*/\
CMDINFO(HWND, GetParent_WindowBoxEx, (HWND hwnd)); \
/*--------取图标--------*/\
CMDINFO(BinEx_P, GetIco_WindowBoxEx, (HWND hwnd)); \
/*--------置图标--------*/\
CMDINFO(void, SetIco_WindowBoxEx, (HWND hwnd, BinEx_P  icon)); \
/*--------取标题--------*/\
CMDINFO(StrEx_P, GetTitle_WindowBoxEx, (HWND hwnd)); \
/*--------置标题--------*/\
CMDINFO(void, SetTitle_WindowBoxEx, (HWND hwnd, StrEx_P  Title)); \
/*--------取风格 --------*/\
CMDINFO(int, GetStyle_WindowBoxEx, (HWND hwnd)); \
/*--------置风格--------*/\
CMDINFO(void, Setstyle_WindowBoxEx, (HWND hwnd, int   style)); \
/*--------取扩展风格--------*/\
CMDINFO(BOOL, GetExStyle_WindowBoxEx, (HWND hwnd)); \
/*--------置扩展风格--------*/\
CMDINFO(void, SetExStyle_WindowBoxEx, (HWND hwnd, int   ExStyle)); \
/*--------置任务栏显示--------*/\
CMDINFO(void, SetTaskbar_WindowBoxEx, (HWND hwnd, BOOL show)); \
/*--------取任务栏显示--------*/\
CMDINFO(BOOL, GetTaskbar_WindowBoxEx, (HWND hwnd)); \
/*--------置总在最前--------*/\
CMDINFO(void, SetAlwaysTop_WindowBoxEx, (HWND hwnd, BOOL AlwaysTop)); \
/*--------取总在最前--------*/\
CMDINFO(BOOL, GetAlwaysTop_WindowBoxEx, (HWND hwnd)); \
/*--------置退出键关闭--------*/\
CMDINFO( void,SetEscClose_WindowBoxEx,(HWND hwnd, BOOL EscClose)); \
/*--------取退出键关闭--------*/\
CMDINFO(BOOL,  GetEscClose_WindowBoxEx,(HWND hwnd)); \
/*--------启用文件拖放--------*/\
CMDINFO(void, EnableDragDrop_WindowBoxEx, (HWND hwnd)); \
/*--------关闭文件拖放--------*/\
CMDINFO(void, CloseDragDrop_WindowBoxEx, (HWND hwnd)); \
/*--------置焦点--------*/\
CMDINFO(void, SetFocus_WindowBoxEx, (HWND hwnd)); \
/*--------可有焦点--------*/\
CMDINFO(BOOL, GetFocus_WindowBoxEx, (HWND hwnd)); \
/*--------调整层次--------*/\
CMDINFO(void, SetLevel_WindowBoxEx, (HWND hwnd, int Level)); \
/*--------置托盘图标--------*/\
CMDINFO(void, SetNotifyIcon_WindowBoxEx, (HWND hwnd, BinEx_P Icon, StrEx_P Tip)); \
/*--------发送消息--------*/\
CMDINFO(int, SendMessage_WindowBoxEx, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)); \
/*--------投递消息--------*/\
CMDINFO(int, PostMessage_WindowBoxEx, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)); \
/*--------消息循环--------*/\
CMDINFO(void, MessageLoop_WindowBoxEx, ()); \
/*创建*/\
CMDINFO(StructEx_P, Create_StructEx, ()); \
	/*销毁*/\
	CMDINFO(void,  Destroy_StructEx, ( StructEx_P   Struct ) ); \
	/*载入 */\
	CMDINFO(BOOL ,Load_StructEx, ( StructEx_P    Struct, BinEx_P Data) ); \
	/*打包*/\
	CMDINFO( BinEx_P, Pack_StructEx, ( StructEx_P    Struct) ); \
	/*插入 */\
	CMDINFO(  int ,   InsertMember_StructEx, ( StructEx_P    Struct, int Member, int addnum) ); \
	/*删除  */\
	CMDINFO(  void ,   DeleteMember_StructEx, ( StructEx_P    Struct, int delMember, int deletenum) ); \
	/*取数量*/\
	CMDINFO(  int  ,  GetMemberCount_StructEx, ( StructEx_P    Struct) ); \
	/*取类型*/\
	CMDINFO(int, GetMemberType_StructEx, (StructEx_P    Struct, int Member)); \
	/*置名称*/\
	CMDINFO(void, SetMemberName_StructEx, (StructEx_P    Struct, int Member, StrEx_P Name)); \
	/*取名称*/\
	CMDINFO(StrEx_P, GetMemberName_StructEx, (StructEx_P    Struct, int Member)); \
	/*置逻辑*/\
	CMDINFO(void, SetMemberBool_StructEx, (StructEx_P    Struct, int Member, BOOL  logic)); \
	/*取逻辑*/\
	CMDINFO(BOOL, GetMemberBool_StructEx, (StructEx_P    Struct, int Member)); \
	/*置整数*/\
	CMDINFO(void, SetMemberInt_StructEx, (StructEx_P    Struct, int Member, int  integer)); \
	/*取整数*/\
	CMDINFO(int, GetMemberInt_StructEx, (StructEx_P    Struct, int Member)); \
	/*置长整数*/\
	CMDINFO(void, SetMemberLongInt_StructEx, (StructEx_P    Struct, int Member, INT64  longinteger)); \
	/*取长整数*/\
	CMDINFO(INT64, GetMemberLongInt_StructEx, (StructEx_P    Struct, int Member)); \
	/*置小数*/\
	CMDINFO(void, SetMemberFloat_StructEx, (StructEx_P    Struct, int Member, float  decimal)); \
	/*取小数*/\
	CMDINFO(float, GetMemberFloat_StructEx, (StructEx_P    Struct, int Member)); \
	/*置双精度小数*/\
	CMDINFO(void, SetMemberDouble_StructEx, (StructEx_P    Struct, int Member, double  DoubleDecimal)); \
	/*取双精度小数*/\
	CMDINFO(double, GetMemberDouble_StructEx, (StructEx_P    Struct, int Member)); \
	/*置文本*/\
	CMDINFO(void, SetMemberText_StructEx, (StructEx_P    Struct, int Member, StrEx_P Text)); \
	/*取文本*/\
	CMDINFO(StrEx_P, GetMemberText_StructEx, (StructEx_P    Struct, int Member)); \
	/*置数据*/\
	CMDINFO(void, SetMemberBin_StructEx, (StructEx_P    Struct, int Member, BinEx_P Bin)); \
	/*取数据*/\
	CMDINFO(BinEx_P, GetMemberBin_StructEx, (StructEx_P    Struct, int Member)); \
	/*置结构体*/\
	CMDINFO(void, SetMemberStruct_StructEx, (StructEx_P    Struct, int Member, StructEx_P    StructInfo)); \
	/*取结构体*/\
	CMDINFO(StructEx_P, GetMemberStruct_StructEx, (StructEx_P  Struct, int Member)); \
	/*插入 */\
	CMDINFO(  int ,   InsertAttr_StructEx, ( StructEx_P    Struct, int Attr, int addnum) ); \
	/*删除  */\
	CMDINFO(  void ,   DeleteAttr_StructEx, ( StructEx_P    Struct, int delAttr, int deletenum) ); \
	/*取数量*/\
	CMDINFO(  int  ,  GetAttrCount_StructEx, ( StructEx_P    Struct) ); \
	/*取类型*/\
	CMDINFO(int, GetAttrType_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置名称*/\
	CMDINFO(void, SetAttrName_StructEx, (StructEx_P    Struct, int Attr, StrEx_P Name)); \
	/*取名称*/\
	CMDINFO(StrEx_P, GetAttrName_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置逻辑*/\
	CMDINFO(void, SetAttrBool_StructEx, (StructEx_P    Struct, int Attr, BOOL  logic)); \
	/*取逻辑*/\
	CMDINFO(BOOL, GetAttrBool_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置整数*/\
	CMDINFO(void, SetAttrInt_StructEx, (StructEx_P    Struct, int Attr, int  integer)); \
	/*取整数*/\
	CMDINFO(int, GetAttrInt_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置长整数*/\
	CMDINFO(void, SetAttrLongInt_StructEx, (StructEx_P    Struct, int Attr, INT64  longinteger)); \
	/*取长整数*/\
	CMDINFO(INT64, GetAttrLongInt_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置小数*/\
	CMDINFO(void, SetAttrFloat_StructEx, (StructEx_P    Struct, int Attr, float  decimal)); \
	/*取小数*/\
	CMDINFO(float, GetAttrFloat_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置双精度小数*/\
	CMDINFO(void, SetAttrDouble_StructEx, (StructEx_P    Struct, int Attr, double  DoubleDecimal)); \
	/*取双精度小数*/\
	CMDINFO(double, GetAttrDouble_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置文本*/\
	CMDINFO(void, SetAttrText_StructEx, (StructEx_P    Struct, int Attr, StrEx_P Text)); \
	/*取文本*/\
	CMDINFO(StrEx_P, GetAttrText_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置数据*/\
	CMDINFO(void, SetAttrBin_StructEx, (StructEx_P    Struct, int Attr, BinEx_P Bin)); \
	/*取数据*/\
	CMDINFO(BinEx_P, GetAttrBin_StructEx, (StructEx_P    Struct, int Attr)); \
	/*置结构体*/\
	CMDINFO(void, SetAttrStruct_StructEx, (StructEx_P    Struct, int Attr, StructEx_P    StructInfo)); \
	/*取结构体*/\
	CMDINFO(StructEx_P, GetAttrStruct_StructEx, (StructEx_P  Struct, int Attr)); \


/*--------------Category7--------------*/

#define 	EX_UI_CMDINFO_Category7(CMDINFO)  \
    /*--------创建组件_窗口EX--------*/\
    CMDINFO( Control_P ,  CreateControl_WindowEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Icon,StrEx_P Text,BinEx_P Font,int FontClour,int LayeredTransparency,int DragPositionMode,int DragSizeMode,int MaxMode,BinEx_P ButtonData, int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_窗口EX--------*/\
    CMDINFO( void ,  SetAttribute_WindowEx , ( WindowEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_窗口EX--------*/\
    CMDINFO( int ,  GetAttribute_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------插入控制纽_窗口EX--------*/\
    CMDINFO( int ,  InsertButton_WindowEx , ( WindowEx_P control,int index,int Data,int Type,BinEx_P skin,BOOL Visual,BOOL Disabled,BOOL Selected ) ); \
    \
    /*--------删除_窗口EX--------*/\
    CMDINFO( void ,  DeleteButton_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置类型_窗口EX--------*/\
    CMDINFO( void ,  SetButtonType_WindowEx , ( WindowEx_P control,int index,int Type ) ); \
    \
    /*--------取类型_窗口EX--------*/\
    CMDINFO( int ,  GetButtonType_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置按钮皮肤_窗口EX--------*/\
    CMDINFO( void ,  SetButtonskin_WindowEx , ( WindowEx_P control,int index,BinEx_P skin ) ); \
    \
    /*--------取按钮皮肤_窗口EX--------*/\
    CMDINFO( BinEx_P ,  GetButtonskin_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置可视_窗口EX--------*/\
    CMDINFO( void ,  SetButtonVisual_WindowEx , ( WindowEx_P control,int index,BOOL Show ) ); \
    \
    /*--------取可视_窗口EX--------*/\
    CMDINFO( BOOL ,  GetButtonVisual_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置禁止_窗口EX--------*/\
    CMDINFO( void ,  SetButtonDisabled_WindowEx , ( WindowEx_P control,int index,BOOL Disabled ) ); \
    \
    /*--------取禁止_窗口EX--------*/\
    CMDINFO( BOOL ,  GetButtonDisabled_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置选中_窗口EX--------*/\
    CMDINFO( void ,  SetButtonSelected_WindowEx , ( WindowEx_P control,int index,BOOL Selected ) ); \
    \
    /*--------取选中_窗口EX--------*/\
    CMDINFO( BOOL ,  GetButtonSelected_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------取数量_窗口EX--------*/\
    CMDINFO( int ,  GetButtonCount_WindowEx , ( WindowEx_P control ) ); \
    \
    /*--------取数值_窗口EX--------*/\
    CMDINFO( int ,  GetButtonData_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------置数值_窗口EX--------*/\
    CMDINFO( void ,  SetButtonData_WindowEx , ( WindowEx_P control,int index,int Data ) ); \
    \
    /*--------添加组件_窗口EX--------*/\
    CMDINFO( BOOL ,  InsertControl_WindowEx , ( WindowEx_P control,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------移除组件_窗口EX--------*/\
    CMDINFO( BOOL ,  RemoveControl_WindowEx , ( WindowEx_P control,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------调用反馈事件_窗口EX--------*/\
    CMDINFO( int ,  CallFeedBackEvent_WindowEx , ( WindowEx_P control,int Relevant1,int Relevant2,BOOL Mode ) ); \
    \
    /*--------创建组件_标签EX--------*/\
    CMDINFO( Control_P ,  CreateControl_LabelEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,StrEx_P Text,int Align,int BackColor,BinEx_P Font,int FontClour,int Rotate, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_标签Ex--------*/\
    CMDINFO( void ,  SetAttribute_LabelEx , ( LabelEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_标签Ex--------*/\
    CMDINFO( int ,  GetAttribute_LabelEx , ( LabelEx_P control,int index ) ); \
    \
    /*--------创建组件_滤镜EX--------*/\
    CMDINFO( Control_P ,  CreateControl_FilterEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,int  FilterExMode, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_滤镜Ex--------*/\
    CMDINFO( void ,  SetAttribute_FilterEx , ( FilterEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_滤镜Ex--------*/\
    CMDINFO( int ,  GetAttribute_FilterEx , ( FilterEx_P control,int index ) ); \
    \
    /*--------创建组件_按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_按钮Ex--------*/\
    CMDINFO( void ,  SetAttribute_ButtonEx , ( ButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_按钮Ex--------*/\
    CMDINFO( int ,  GetAttribute_ButtonEx , ( ButtonEx_P control,int index ) ); \
    \
    /*--------创建组件_图片按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ImagebuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_图片按钮Ex--------*/\
    CMDINFO( void ,  SetAttribute_ImagebuttonEx , ( ImagebuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_图片按钮Ex--------*/\
    CMDINFO( int ,  GetAttribute_ImagebuttonEx , ( ImagebuttonEx_P control,int index ) ); \
    \
    /*--------创建组件_超级按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SuperbuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected,BinEx_P Icon,int IconWidth,int IconHeight,BOOL IconResidence,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_超级按钮Ex--------*/\
    CMDINFO( void ,  SetAttribute_SuperbuttonEx , ( SuperbuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_超级按钮Ex--------*/\
    CMDINFO( int ,  GetAttribute_SuperbuttonEx , ( SuperbuttonEx_P control,int index ) ); \
    \
    /*--------创建组件_选择框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ChoiceboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Selected,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_选择框Ex--------*/\
    CMDINFO( void ,  SetAttribute_ChoiceboxEx , ( ChoiceboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_选择框Ex--------*/\
    CMDINFO( int ,  GetAttribute_ChoiceboxEx , ( ChoiceboxEx_P control,int index ) ); \
    \
    /*--------创建组件_单选框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_RadiobuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_单选框Ex--------*/\
    CMDINFO( void ,  SetAttribute_RadiobuttonEx , ( RadiobuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_单选框Ex--------*/\
    CMDINFO( int ,  GetAttribute_RadiobuttonEx , ( RadiobuttonEx_P control,int index ) ); \
    \
    /*--------创建组件_编辑框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_EditboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Content,int Align,int InputMode,int MaxInput,StrEx_P PasswordSubstitution,int CursorColor,BinEx_P Font,int FontClour,int SelectedFontColor,int SelectedColor,int LeftReservation,int RightReservation,BOOL Multiline,BOOL Wrapped,int ScrollBarMode,int MenuTableWidth,int MenuTableHeight,BinEx_P MenuFont,int MenuFontClour,int MenuDisabledFontClour,int MenuAttributeTransparency,int MenuLanguage , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_编辑框Ex--------*/\
    CMDINFO( void ,  SetAttribute_EditboxEx , ( EditboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_编辑框Ex--------*/\
    CMDINFO( int ,  GetAttribute_EditboxEx , ( EditboxEx_P control,int index ) ); \
    \
    /*--------插入文本_编辑框Ex--------*/\
    CMDINFO( void ,  InsertText_EditboxEx , ( EditboxEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------删除文本_编辑框Ex--------*/\
    CMDINFO( void ,  DeleteText_EditboxEx , ( EditboxEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------置光标位置_编辑框Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_EditboxEx , ( EditboxEx_P control,int index ) ); \
    \
    /*--------取光标位置_编辑框Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_EditboxEx , ( EditboxEx_P control ) ); \
    \
    /*--------置选择文本长度_编辑框Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_EditboxEx , ( EditboxEx_P control,int SelectLeng ) ); \
    \
    /*--------取选择文本长度_编辑框Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_EditboxEx , ( EditboxEx_P control ) ); \
    \
    /*--------保证显示字符_编辑框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_EditboxEx , ( EditboxEx_P control,int index,int mode ) ); \
    \
    /*--------创建组件_组合框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ComboboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Content,int Align,int InputMode,int MaxInput,StrEx_P PasswordSubstitution,int CursorColor,BinEx_P Font,int FontClour,int SelectedFontColor,int SelectedColor,int LeftReservation,int RightReservation,int MenuTableWidth,int MenuTableHeight,BinEx_P MenuFont,int MenuFontClour,int MenuDisabledFontClour,int MenuAttributeTransparency,int MenuLanguage,int DownListWidth,int DownListMaxHeight,int DownListCurrentSelection,int DownListIconWidth,int DownListIconHeight,BinEx_P DownListFont,BOOL DownListAlternate,int DownListScrollBarMode,int DownListAttributeTransparency,BinEx_P DownListItemData, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_组合框Ex--------*/\
    CMDINFO( void ,  SetAttribute_ComboboxEx , ( ComboboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_组合框Ex--------*/\
    CMDINFO( int ,  GetAttribute_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------插入文本_组合框Ex--------*/\
    CMDINFO( void ,  InsertText_ComboboxEx , ( ComboboxEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------删除文本_组合框Ex--------*/\
    CMDINFO( void ,  DeleteText_ComboboxEx , ( ComboboxEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------置光标位置_组合框Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------取光标位置_组合框Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------置选择文本长度_组合框Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_ComboboxEx , ( ComboboxEx_P control,int SelectLeng ) ); \
    \
    /*--------取选择文本长度_组合框Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------保证显示字符_组合框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_ComboboxEx , ( ComboboxEx_P control,int index,int mode ) ); \
    \
    /*--------弹出_组合框Ex--------*/\
    CMDINFO( void ,  PopUp_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------关闭_组合框Ex--------*/\
    CMDINFO( void ,  Close_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------是否已弹出_组合框Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------插入_组合框Ex--------*/\
    CMDINFO( int ,  InsertItem_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------删除_组合框Ex--------*/\
    CMDINFO( void ,  DeleteItem_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int deletenum ) ); \
    \
    /*--------取数量_组合框Ex--------*/\
    CMDINFO( int ,  GetItemCount_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------置附加值_组合框Ex--------*/\
    CMDINFO( void ,  SetItemData_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_组合框Ex--------*/\
    CMDINFO( int ,  GetItemData_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------置图标_组合框Ex--------*/\
    CMDINFO( void ,  SetItemIco_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_组合框Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------置标题_组合框Ex--------*/\
    CMDINFO( void ,  SetItemTitle_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取标题_组合框Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------置字体色_组合框Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_组合框Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------置项目高度_组合框Ex--------*/\
    CMDINFO( void ,  SetItemSize_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int Size ) ); \
    \
    /*--------取项目高度_组合框Ex--------*/\
    CMDINFO( int ,  GetItemSize_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------保证显示_组合框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int mode ) ); \
    \
    /*--------创建组件_分组框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_MinutesboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Picture,int IconWidth,int IconHeight,StrEx_P Text,int TextMode,BinEx_P Font,int FontClour , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_分组框Ex--------*/\
    CMDINFO( void ,  SetAttribute_MinutesboxEx , ( MinutesboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_分组框Ex--------*/\
    CMDINFO( int ,  GetAttribute_MinutesboxEx , ( MinutesboxEx_P control,int index ) ); \
    \
    /*--------添加组件_分组框Ex--------*/\
    CMDINFO( BOOL ,  InsertControl_MinutesboxEx , ( MinutesboxEx_P control,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------移除组件_分组框Ex--------*/\
    CMDINFO( BOOL ,  RemoveControl_MinutesboxEx , ( MinutesboxEx_P control,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------创建组件_多功能按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_MultifunctionButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int ButtonStyles,int PartnerSize,int BackColor,BinEx_P Icon,int IconWidth,int IconHeight,BOOL IconResidence,StrEx_P Text,BinEx_P Font,int FontClour , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_多功能按钮EX--------*/\
    CMDINFO( void ,  SetAttribute_MultifunctionButtonEx , ( MultifunctionButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_多功能按钮EX--------*/\
    CMDINFO( int ,  GetAttribute_MultifunctionButtonEx , ( MultifunctionButtonEx_P control,int index ) ); \
    \
    /*--------创建组件_图片框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_PictureBoxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Picture,int MapMode,int Rotate,int Angle,BOOL PlayAnimation,int AllFrame,int CurrentFrame, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_图片框Ex--------*/\
    CMDINFO( void ,  SetAttribute_PictureBoxEx , ( PictureBoxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_图片框Ex--------*/\
    CMDINFO( int ,  GetAttribute_PictureBoxEx , ( PictureBoxEx_P control,int index ) ); \
    \
    /*--------创建组件_进度条EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ProgressbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int MiniPosition,int MaxiPosition,int Style,int Direction , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_进度条Ex--------*/\
    CMDINFO( void ,  SetAttribute_ProgressbarEx , ( ProgressbarEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_进度条Ex--------*/\
    CMDINFO( int ,  GetAttribute_ProgressbarEx , ( ProgressbarEx_P control,int index ) ); \
    \
    /*--------创建组件_滚动条EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ScrollbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int MiniPosition,int MaxiPosition,int PageLength,int RowChangeValue,int PageChangeValue,int ScrollChangeValue,BOOL DragTrace,BOOL schedule , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_滚动条Ex--------*/\
    CMDINFO( void ,  SetAttribute_ScrollbarEx , ( ScrollbarEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_滚动条Ex--------*/\
    CMDINFO( int ,  GetAttribute_ScrollbarEx , ( ScrollbarEx_P control,int index ) ); \
    \
    /*--------创建组件_滑块条EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SliderbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int Progress,int MiniPosition,int MaxiPosition,int RowChangeValue,int PageChangeValue,BOOL DragTrace,int Style , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_滑块条Ex--------*/\
    CMDINFO( void ,  SetAttribute_SliderbarEx , ( SliderbarEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_滑块条Ex--------*/\
    CMDINFO( int ,  GetAttribute_SliderbarEx , ( SliderbarEx_P control,int index ) ); \
    \
    /*--------创建组件_选择夹EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SelectthefolderEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentTable,int TableSize,int Direction,int Spacing,int TableStyle,int Retain,int IconWidth,int IconHeight,BinEx_P Font,BinEx_P TableData, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_选择夹Ex--------*/\
    CMDINFO( void ,  SetAttribute_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_选择夹Ex--------*/\
    CMDINFO( int ,  GetAttribute_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------插入_选择夹Ex--------*/\
    CMDINFO( int ,  InsertTab_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------删除_选择夹Ex--------*/\
    CMDINFO( void ,  DeleteTab_SelectthefolderEx , ( SelectthefolderEx_P control,int delindex ) ); \
    \
    /*--------取数量_选择夹Ex--------*/\
    CMDINFO( int ,  GetTabCount_SelectthefolderEx , ( SelectthefolderEx_P control ) ); \
    \
    /*--------取关联数值_选择夹Ex--------*/\
    CMDINFO( int ,  GetTabData_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------置关联数值_选择夹Ex--------*/\
    CMDINFO( void ,  SetTabData_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Data ) ); \
    \
    /*--------置图标_选择夹Ex--------*/\
    CMDINFO( void ,  SetTabIco_SelectthefolderEx , ( SelectthefolderEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_选择夹Ex--------*/\
    CMDINFO( ImageEX_P ,  GetTabIco_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------置文本_选择夹Ex--------*/\
    CMDINFO( void ,  SetTabTitle_SelectthefolderEx , ( SelectthefolderEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取文本_选择夹Ex--------*/\
    CMDINFO( StrEx_P ,  GetTabTitle_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------置字体色_选择夹Ex--------*/\
    CMDINFO( void ,  SetTabFontColor_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_选择夹Ex--------*/\
    CMDINFO( int ,  GetTabFontColor_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------置尺寸_选择夹Ex--------*/\
    CMDINFO( void ,  SetTabSize_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Size ) ); \
    \
    /*--------取尺寸_选择夹Ex--------*/\
    CMDINFO( int ,  GetTabSize_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------保证显示_选择夹Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int DisplayMode ) ); \
    \
    /*--------添加组件_选择夹Ex--------*/\
    CMDINFO( BOOL ,  InsertControl_SelectthefolderEx , ( SelectthefolderEx_P control,int Table,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------移除组件_选择夹Ex--------*/\
    CMDINFO( BOOL ,  RemoveControl_SelectthefolderEx , ( SelectthefolderEx_P control,int Table,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------创建组件_工具条EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ToolbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int BackMode,BOOL schedule,int Spacing,int IconWidth,int IconHeight,BinEx_P Font,BinEx_P ButtonData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_工具条Ex--------*/\
    CMDINFO( void ,  SetAttribute_ToolbarEx , ( ToolbarEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_工具条Ex--------*/\
    CMDINFO( int ,  GetAttribute_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------插入_工具条Ex--------*/\
    CMDINFO( int ,  InsertButton_ToolbarEx , ( ToolbarEx_P control,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size,int Type,int Align,BOOL Disabled,BOOL Selected ) ); \
    \
    /*--------删除_工具条Ex--------*/\
    CMDINFO( void ,  DeleteButton_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------取数量_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonCount_ToolbarEx , ( ToolbarEx_P control ) ); \
    \
    /*--------置关联数值_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonData_ToolbarEx , ( ToolbarEx_P control,int index,int Data ) ); \
    \
    /*--------取关联数值_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonData_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置图标_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonIco_ToolbarEx , ( ToolbarEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_工具条Ex--------*/\
    CMDINFO( ImageEX_P ,  GetButtonIco_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置文本_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonTitle_ToolbarEx , ( ToolbarEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取文本_工具条Ex--------*/\
    CMDINFO( StrEx_P ,  GetButtonTitle_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置字体色_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonFontColor_ToolbarEx , ( ToolbarEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonFontColor_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置尺寸_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonSize_ToolbarEx , ( ToolbarEx_P control,int index,int Size ) ); \
    \
    /*--------取尺寸_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonSize_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置类型_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonType_ToolbarEx , ( ToolbarEx_P control,int index,int Type ) ); \
    \
    /*--------取类型_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonType_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置对齐方式_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonAlign_ToolbarEx , ( ToolbarEx_P control,int index,int Align ) ); \
    \
    /*--------取对齐方式_工具条Ex--------*/\
    CMDINFO( int ,  GetButtonAlign_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置选中_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonSelected_ToolbarEx , ( ToolbarEx_P control,int index,BOOL Selected ) ); \
    \
    /*--------取选中_工具条Ex--------*/\
    CMDINFO( BOOL ,  GetButtonSelected_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------置禁止_工具条Ex--------*/\
    CMDINFO( void ,  SetButtonDisabled_ToolbarEx , ( ToolbarEx_P control,int index,BOOL Disabled ) ); \
    \
    /*--------取禁止_工具条Ex--------*/\
    CMDINFO( BOOL ,  GetButtonDisabled_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------保证显示_工具条Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_ToolbarEx , ( ToolbarEx_P control,int index,int DisplayMode ) ); \
    \
    /*--------创建组件_列表框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int IconWidth,int IconHeight,BinEx_P Font,BOOL AlternateColor,int ScrollBarMode,BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_列表框Ex--------*/\
    CMDINFO( void ,  SetAttribute_ListboxEx , ( ListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_列表框Ex--------*/\
    CMDINFO( int ,  GetAttribute_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------插入_列表框Ex--------*/\
    CMDINFO( int ,  InsertItem_ListboxEx , ( ListboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------删除_列表框Ex--------*/\
    CMDINFO( void ,  DeleteItem_ListboxEx , ( ListboxEx_P control,int index,int deletenum ) ); \
    \
    /*--------取数量_列表框Ex--------*/\
    CMDINFO( int ,  GetItemCount_ListboxEx , ( ListboxEx_P control ) ); \
    \
    /*--------置附加值_列表框Ex--------*/\
    CMDINFO( void ,  SetItemData_ListboxEx , ( ListboxEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_列表框Ex--------*/\
    CMDINFO( int ,  GetItemData_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------置图标_列表框Ex--------*/\
    CMDINFO( void ,  SetItemIco_ListboxEx , ( ListboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_列表框Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------置标题_列表框Ex--------*/\
    CMDINFO( void ,  SetItemTitle_ListboxEx , ( ListboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取标题_列表框Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------取字体色_列表框Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------置字体色_列表框Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_ListboxEx , ( ListboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------置项目高度_列表框Ex--------*/\
    CMDINFO( void ,  SetItemSize_ListboxEx , ( ListboxEx_P control,int index,int Size ) ); \
    \
    /*--------取项目高度_列表框Ex--------*/\
    CMDINFO( int ,  GetItemSize_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------保证显示_列表框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_ListboxEx , ( ListboxEx_P control,int index,int mode ) ); \
    \
    /*--------创建组件_超级列表框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SuperListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int HeadHeight,int HeadMode,BOOL AlternateColor,BOOL EntireLine,int LineMode,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_超级列表框Ex--------*/\
    CMDINFO( void ,  SetAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_超级列表框Ex--------*/\
    CMDINFO( int ,  GetAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------插入列_超级列表框Ex--------*/\
    CMDINFO( int ,  InsertColumn_SuperListboxEx , ( SuperListboxEx_P control,int cloid,int addnum,ImageEX_P Ico,StrEx_P Title,int FontColor,int wight,int min,int max,BinEx_P Font,int IcoW,int IcoH,int Align,BinEx_P ItemFont,int ItemIcoW,int ItemIcoH,int ItemAlign ) ); \
    \
    /*--------删除列_超级列表框Ex--------*/\
    CMDINFO( void ,  DeleteColumn_SuperListboxEx , ( SuperListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取列数量_超级列表框Ex--------*/\
    CMDINFO( int ,  GetColumnCount_SuperListboxEx , ( SuperListboxEx_P control ) ); \
    \
    /*--------置列属性_超级列表框Ex--------*/\
    CMDINFO( void ,  SetColumnAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int AttributeId, ImageEX_P Ico,StrEx_P Title,int FontColor,int wight,int min,int max,BinEx_P Font,int IcoW,int IcoH,int Align,BinEx_P ItemFont,int ItemIcoW,int ItemIcoH,int ItemAlign ) ); \
    \
    /*--------取列属性_超级列表框Ex--------*/\
    CMDINFO( int ,  GetColumnAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int AttributeId ) ); \
    \
    /*--------插入项目_超级列表框Ex--------*/\
    CMDINFO( int ,  InsertItem_SuperListboxEx , ( SuperListboxEx_P control,int index,int addnum,int Data,int Size ) ); \
    \
    /*--------删除项目_超级列表框Ex--------*/\
    CMDINFO( void ,  DeleteItem_SuperListboxEx , ( SuperListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取数量_超级列表框Ex--------*/\
    CMDINFO( int ,  GetItemCount_SuperListboxEx , ( SuperListboxEx_P control ) ); \
    \
    /*--------置附加值_超级列表框Ex--------*/\
    CMDINFO( void ,  SetItemData_SuperListboxEx , ( SuperListboxEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_超级列表框Ex--------*/\
    CMDINFO( int ,  GetItemData_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------置图标_超级列表框Ex--------*/\
    CMDINFO( void ,  SetItemIco_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,ImageEX_P Ico ) ); \
    \
    /*--------取图标_超级列表框Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------置文本_超级列表框Ex--------*/\
    CMDINFO( void ,  SetItemTitle_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,StrEx_P Title ) ); \
    \
    /*--------取文本_超级列表框Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------置字体色_超级列表框Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,int FontColor ) ); \
    \
    /*--------取字体色_超级列表框Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------置项目高度_超级列表框Ex--------*/\
    CMDINFO( void ,  SetItemSize_SuperListboxEx , ( SuperListboxEx_P control,int index,int Size ) ); \
    \
    /*--------取项目高度_超级列表框Ex--------*/\
    CMDINFO( int ,  GetItemSize_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------保证显示_超级列表框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_SuperListboxEx , ( SuperListboxEx_P control,int index,int cid,int mode ) ); \
    \
    /*--------创建组件_图标列表框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_IcoListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int TableWidth,int TableHeight,int HSpacing,int LSpacing,int IconWidth,int IconHeight,BinEx_P Font,int PageLayout,BOOL IconResidence,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_图标列表框Ex--------*/\
    CMDINFO( void ,  SetAttribute_IcoListboxEx , ( IcoListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_图标列表框Ex--------*/\
    CMDINFO( int ,  GetAttribute_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------插入项目_图标列表框Ex--------*/\
    CMDINFO( int ,  InsertItem_IcoListboxEx , ( IcoListboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor ) ); \
    \
    /*--------删除项目_图标列表框Ex--------*/\
    CMDINFO( void ,  DeleteItem_IcoListboxEx , ( IcoListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取项目数量_图标列表框Ex--------*/\
    CMDINFO( int ,  GetItemCount_IcoListboxEx , ( IcoListboxEx_P control ) ); \
    \
    /*--------置附加值_图标列表框Ex--------*/\
    CMDINFO( void ,  SetItemData_IcoListboxEx , ( IcoListboxEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_图标列表框Ex--------*/\
    CMDINFO( int ,  GetItemData_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------置图标_图标列表框Ex--------*/\
    CMDINFO( void ,  SetItemIco_IcoListboxEx , ( IcoListboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_图标列表框Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------置文本_图标列表框Ex--------*/\
    CMDINFO( void ,  SetItemTitle_IcoListboxEx , ( IcoListboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取文本_图标列表框Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------置字体色_图标列表框Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_IcoListboxEx , ( IcoListboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_图标列表框Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------保证显示_图标列表框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_IcoListboxEx , ( IcoListboxEx_P control,int index,int mode ) ); \
    \
    /*--------创建组件_树形列表框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_TreeListEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,BOOL AutoSize,int FoldBtnWidth,int FoldBtnHeight,int IconWidth,int IconHeight,BinEx_P Font,int ChildMigration,int BackMigration,int ContentMigration,int LineMode,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_树形框Ex--------*/\
    CMDINFO( void ,  SetAttribute_TreeListEx , ( TreeListEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_树形框Ex--------*/\
    CMDINFO( int ,  GetAttribute_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------插入_树形框Ex--------*/\
    CMDINFO( int ,  InsertItem_TreeListEx , ( TreeListEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Width,int Size,int ItemType,BOOL SetFold,int InsMode ) ); \
    \
    /*--------删除_树形框Ex--------*/\
    CMDINFO( void ,  DeleteItem_TreeListEx , ( TreeListEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取数量_树形框Ex--------*/\
    CMDINFO( int ,  GetItemCount_TreeListEx , ( TreeListEx_P control ) ); \
    \
    /*--------置附加值_树形框Ex--------*/\
    CMDINFO( void ,  SetItemData_TreeListEx , ( TreeListEx_P control,int index,int Data ) ); \
    \
    /*--------取附加值_树形框Ex--------*/\
    CMDINFO( int ,  GetItemData_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置图标_树形框Ex--------*/\
    CMDINFO( void ,  SetItemIco_TreeListEx , ( TreeListEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------取图标_树形框Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置文本_树形框Ex--------*/\
    CMDINFO( void ,  SetItemTitle_TreeListEx , ( TreeListEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------取文本_树形框Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置字体色_树形框Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_TreeListEx , ( TreeListEx_P control,int index,int FontColor ) ); \
    \
    /*--------取字体色_树形框Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置项目宽度_树形框Ex--------*/\
    CMDINFO( void ,  SetItemWidth_TreeListEx , ( TreeListEx_P control,int index,int Width ) ); \
    \
    /*--------取项目宽度_树形框Ex--------*/\
    CMDINFO( int ,  GetItemWidth_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置项目高度_树形框Ex--------*/\
    CMDINFO( void ,  SetItemSize_TreeListEx , ( TreeListEx_P control,int index,int Size ) ); \
    \
    /*--------取项目高度_树形框Ex--------*/\
    CMDINFO( int ,  GetItemSize_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置项目风格_树形框Ex--------*/\
    CMDINFO( void ,  SetItemType_TreeListEx , ( TreeListEx_P control,int index,int style ) ); \
    \
    /*--------取项目风格_树形框Ex--------*/\
    CMDINFO( int ,  GetItemType_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------置折叠状态_树形框Ex--------*/\
    CMDINFO( void ,  SetItemFold_TreeListEx , ( TreeListEx_P control,int index,BOOL Fold ) ); \
    \
    /*--------取折叠状态_树形框Ex--------*/\
    CMDINFO( BOOL ,  GetItemFold_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取缩进层次_树形框Ex--------*/\
    CMDINFO( int ,  GetItemLevel_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取子项目数_树形框Ex--------*/\
    CMDINFO( int ,  GetSubItemCount_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取下一级子项目数_树形框Ex--------*/\
    CMDINFO( int ,  GetNextSubItemCount_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取祖宗项目_树形框Ex--------*/\
    CMDINFO( int ,  GetAncestorItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取父项目_树形框Ex--------*/\
    CMDINFO( int ,  GetFatherItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取上一同层项目_树形框Ex--------*/\
    CMDINFO( int ,  GetLastItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------取下一同层项目_树形框Ex--------*/\
    CMDINFO( int ,  GetNextItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------保证显示_树形框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_TreeListEx , ( TreeListEx_P control,int index,int mode ) ); \
    \
    /*--------创建组件_浏览框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_WebBrowserEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BOOL BackgroundTransparent,int MediaVolume,int ZoomFactor,BOOL NavigationToNewWind,BOOL CookieEnabled,BOOL NpapiEnabled,BOOL MenuEnabled,int DragEnable,StrEx_P StartPage,StrEx_P UserAgent,int Version, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_浏览框Ex--------*/\
    CMDINFO( void ,  SetAttribute_WebBrowserEx , ( WebBrowserEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_浏览框Ex--------*/\
    CMDINFO( int ,  GetAttribute_WebBrowserEx , ( WebBrowserEx_P control,int index ) ); \
    \
    /*--------取内核句柄_浏览框Ex--------*/\
    CMDINFO( int ,  GetWebView_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------载入_浏览框Ex--------*/\
    CMDINFO( void ,  Load_WebBrowserEx , ( WebBrowserEx_P control,StrEx_P url,StrEx_P baseUrl,int Loadmode ) ); \
    \
    /*--------后退_浏览框Ex--------*/\
    CMDINFO( BOOL ,  GoBack_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------前进_浏览框Ex--------*/\
    CMDINFO( BOOL ,  GoForward_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------可否后退_浏览框Ex--------*/\
    CMDINFO( BOOL ,  GoCanBack_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------可否前进_浏览框Ex--------*/\
    CMDINFO( BOOL ,  GoCanForward_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------重载_浏览框Ex--------*/\
    CMDINFO( void ,  ReLoad_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------停止_浏览框Ex--------*/\
    CMDINFO( void ,  StopLoading_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------取地址_浏览框Ex--------*/\
    CMDINFO( StrEx_P ,  GetUrl_WebBrowserEx , ( WebBrowserEx_P control,int frameId ) ); \
    \
    /*--------取标题_浏览框Ex--------*/\
    CMDINFO( StrEx_P ,  GetTitle_WebBrowserEx , ( WebBrowserEx_P control,int frameId ) ); \
    \
    /*--------取源码_浏览框Ex--------*/\
	 \
	 CMDINFO( StrEx_P ,  GetSource_WebBrowserEx , ( WebBrowserEx_P control ) ); \
	\
	 /*--------执行命令_浏览框Ex--------*/\
    CMDINFO( int ,  RunCmd_WebBrowserEx , ( WebBrowserEx_P control,int  Cmd, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4) ); \
    \
	 /*--------取cookie_浏览框Ex--------*/\
    CMDINFO( StrEx_P ,  GetCookie_WebBrowserEx , ( WebBrowserEx_P control) ); \
    \
	 /*--------置cookie_浏览框Ex--------*/\
    CMDINFO( void ,  SetCookie_WebBrowserEx , ( WebBrowserEx_P control,  StrEx_P   url, StrEx_P cookie ) ); \
    \
	 /*--------执行js_浏览框Ex--------*/\
    CMDINFO( StrEx_P ,  RunJS_WebBrowserEx , ( WebBrowserEx_P control,  StrEx_P JavaScript, int frameId, BOOL isInClosure ) ); \
    \
	 /*--------绑定js_浏览框Ex--------*/\
	CMDINFO( void ,  BindFunction_WebBrowserEx , ( WebBrowserEx_P control, StrEx_P jscmd, void * mycmd, int argcount,int mode) ); \
    \
    /*--------否正在加载_浏览框Ex--------*/\
    CMDINFO( BOOL ,  IsLoading_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------是否载入失败_浏览框Ex--------*/\
    CMDINFO( BOOL ,  IsLoadingSucceeded_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------是否载入完毕_浏览框Ex--------*/\
    CMDINFO( BOOL ,  IsLoadingCompleted_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------是否加载完成_浏览框Ex--------*/\
    CMDINFO( BOOL ,  IsDocumentReady_WebBrowserEx , ( WebBrowserEx_P control ) ); \
	 \
	/*--------启用开发者工具_浏览框Ex--------*/\
    CMDINFO( void ,  ShowDevtools_WebBrowserEx , ( WebBrowserEx_P control , StrEx_P  path ) ); \
	\
	/*--------创建组件_日历框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_CalendarBoxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag, BinEx_P Skin, StrEx_P  MiniDate, StrEx_P  MaxDate,StrEx_P  SelectionDate,BinEx_P  TitleFont, BinEx_P  WeekFont, BinEx_P DayFont, BinEx_P TimeFont, int  TitleClour, int  WeekClour, int  WeekendWeekClour, int  DayClour, int  WeekendClour, int  OtherMonthClour, int  TimeFontClour, BOOL  OnlyThisMonth, int TimeMode, int  TitleHeight, int  WeekHeight, int  TimeRegulatorHeight, int  PartnerHeight, int  Language , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_日历框Ex--------*/\
    CMDINFO( void ,  SetAttribute_CalendarBoxEx , ( CalendarBoxEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_日历框Ex--------*/\
    CMDINFO( int ,  GetAttribute_CalendarBoxEx , ( CalendarBoxEx_P control,int index ) ); \
    \
    /*--------创建组件_选色板EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ColorPickEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P   Skin, BinEx_P  Font, int  FontClour, int  NowClour, BOOL  DragTrace, int ClourMode, BinEx_P QuickClours, int  Style, int RegulatorHeight, int QuickClourSize, int  PartnerHeigh , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_选色板EX--------*/\
    CMDINFO( void ,  SetAttribute_ColorPickEx , ( ColorPickEx_P control,int index,int attribute ) ); \
     \
    /*--------取属性_选色板EX--------*/\
    CMDINFO( int ,  GetAttribute_ColorPickEx , ( ColorPickEx_P control,int index ) ); \
    \
    /*--------创建组件_富文本框EX--------*/\
    CMDINFO( Control_P ,  CreateControl_RichEditEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin, StrEx_P  Content, int  Type, BOOL BackTransparent, int BackClour,int CursorColor, BinEx_P	DefaultCharFormat, BinEx_P  DefaultParaFormat, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, BOOL  Multiline, BOOL  Wrapped, int  ScrollBarMode, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_富文本框EX--------*/\
    CMDINFO( void ,  SetAttribute_RichEditEx , ( RichEditEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_富文本框EX--------*/\
    CMDINFO( int ,  GetAttribute_RichEditEx , ( RichEditEx_P control,int index ) ); \
	/*--------插入文本_编辑框Ex--------*/\
    CMDINFO( void ,  InsertText_RichEditEx , ( RichEditEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------删除文本_编辑框Ex--------*/\
    CMDINFO( void ,  DeleteText_RichEditEx , ( RichEditEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------置光标位置_编辑框Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_RichEditEx , ( RichEditEx_P control,int index ) ); \
    \
    /*--------取光标位置_编辑框Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_RichEditEx , ( RichEditEx_P control ) ); \
    \
    /*--------置选择文本长度_编辑框Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_RichEditEx , ( RichEditEx_P control,int SelectLeng ) ); \
    \
    /*--------取选择文本长度_编辑框Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_RichEditEx , ( RichEditEx_P control ) ); \
    \
    /*--------保证显示字符_编辑框Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_RichEditEx , ( RichEditEx_P control,int index,int mode ) ); \
   \
   /*--------置选择区字符格式--------*/\
    CMDINFO(BOOL , SetSelCharFormat_RichEditEx,(RichEditEx_P control, BinEx_P  CharFormat) ); \
    \
   /*--------取选择区字符格式--------*/\
	CMDINFO(BinEx_P , GetSelCharFormat_RichEditEx,(RichEditEx_P control) ); \
    \
   /*--------置选择区段落方式--------*/\
	CMDINFO(BOOL  , SetSelParaFormat_RichEditEx,(RichEditEx_P control, BinEx_P  CharFormat) ); \
    \
   /*--------取选择区段落方式--------*/\
	CMDINFO(BinEx_P , GetSelParaFormat_RichEditEx,(RichEditEx_P control) ); \
    \
   /*--------执行接口命令--------*/\
	CMDINFO(int  , RunServicesCmd_RichEditEx,(RichEditEx_P control, int msg, int wparam, int lparam, int  plresult) ); \
    \
  /*--------创建组件_扩展组件EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ExtendEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P AttrEx, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_扩展组件Ex--------*/\
    CMDINFO( void ,  SetAttribute_ExtendEx , ( ExtendEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_扩展组件Ex--------*/\
    CMDINFO( int ,  GetAttribute_ExtendEx , ( ExtendEx_P control,int index ) ); \
    \
	/*--------启用开发者工具_扩展组件Ex--------*/\
    CMDINFO( int ,  ShowDevtools_ExtendEx , ( ExtendEx_P control,  StrEx_P  ToolsPath ) ); \
    \
    /*--------执行扩展命令_扩展组件Ex--------*/\
    CMDINFO( StrEx_P ,  RunExtendCmd_ExtendEx , ( ExtendEx_P control, StrEx_P  JavaScript) ); \
	\
    /*--------创建组件_动画按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_AnimationbuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL  Selected, StrEx_P  Icon, int  IconWidth, int  IconHeight, BOOL  IconResidence,StrEx_P  Text, StrEx_P  Font, int  FontClour, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_动画按钮EX--------*/\
    CMDINFO( void ,  SetAttribute_AnimationbuttonEx , ( AnimationbuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_动画按钮EX--------*/\
    CMDINFO( int ,  GetAttribute_AnimationbuttonEx , ( AnimationbuttonEx_P control,int index ) ); \
    \
    /*--------创建组件_高级表格EX--------*/\
    CMDINFO( Control_P ,  CreateControl_AdvancedFormEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin, int  CurrentSelection, int  CurrentSelectionColumn, int HeaderRowNum, int HeaderColumnNum, int	BottomFixedRow, int RightFixedColumn, int  AdjustmentMode, BOOL  AutoSelect, BOOL  EntireLine, int  LineMode, int  ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------置属性_高级表格Ex--------*/\
    CMDINFO( void ,  SetAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_高级表格Ex--------*/\
    CMDINFO( int ,  GetAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------插入列_高级表格Ex--------*/\
    CMDINFO( int ,  InsertColumn_AdvancedFormEx , (AdvancedFormEx_P    control, int  cloid, int addnum, int wight, int min, int max, BinEx_P  ItemFont, int ItemIcoW, int ItemIcoH, int ItemAlign) ); \
    \
    /*--------删除列_高级表格Ex--------*/\
    CMDINFO( void ,  DeleteColumn_AdvancedFormEx , ( AdvancedFormEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取列数量_高级表格Ex--------*/\
    CMDINFO( int ,  GetColumnCount_AdvancedFormEx , ( AdvancedFormEx_P control ) ); \
    \
    /*--------置列属性_高级表格Ex--------*/\
    CMDINFO( void ,  SetColumnAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int Endindex,int AttributeId,int wight, int min, int max, BinEx_P  ItemFont, int ItemIcoW, int ItemIcoH, int ItemAlign ) ); \
    \
    /*--------取列属性_高级表格Ex--------*/\
    CMDINFO( int ,  GetColumnAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int AttributeId ) ); \
    \
    /*--------插入项目_高级表格Ex--------*/\
    CMDINFO( int ,  InsertItem_AdvancedFormEx , ( AdvancedFormEx_P control,int index, int  addnum, int  Data, int Height,int MinHeight, int MaxHeight ) ); \
    \
    /*--------删除项目_高级表格Ex--------*/\
    CMDINFO( void ,  DeleteItem_AdvancedFormEx , ( AdvancedFormEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------取数量_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemCount_AdvancedFormEx , ( AdvancedFormEx_P control ) ); \
    \
    /*--------置附加值_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemData_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Data ) ); \
    \
    /*--------取附加值_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemData_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------置图标_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemIco_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn,ImageEX_P Ico ) ); \
    \
    /*--------取图标_高级表格Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------置文本_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemTitle_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn,StrEx_P Title ) ); \
    \
    /*--------取文本_高级表格Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------置字体色_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int EndRow, int EndColumn, int  FontColor ) ); \
    \
    /*--------取字体色_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------置项目高度_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------取项目高度_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------置项目最大高度_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemMaxHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------取项目最大高度_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemMaxHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------置项目最小高度_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemMinHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------取项目最小高度_高级表格Ex--------*/\
    CMDINFO( int ,  GetItemMinHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------合并单元格_高级表格Ex--------*/\
    CMDINFO( void ,  MergeCell_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn ) ); \
    \
    /*--------分解单元格_高级表格Ex--------*/\
    CMDINFO( void ,  BreakCell_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn) ); \
    \
    /*--------取单元格合并信息_高级表格Ex--------*/\
    CMDINFO( int ,  GetMergeInfo_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int Type) ); \
    \
    /*--------置背景方案_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemColorScheme_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn, BinEx_P  ColorScheme ) ); \
    \
    /*--------取背景方案_高级表格Ex--------*/\
    CMDINFO( BinEx_P ,  GetItemColorScheme_AdvancedFormEx , ( AdvancedFormEx_P control, int index, int  cloid) ); \
    \
    /*--------置选中状态_高级表格Ex--------*/\
    CMDINFO( void ,  SetItemSelect_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int EndRow, int EndColumn, BOOL Select ) ); \
    \
	/*--------取选中状态_高级表格Ex--------*/\
    CMDINFO( BOOL ,  GetItemSelect_AdvancedFormEx , ( AdvancedFormEx_P control, int index, int  cloid) ); \
    \
    /*--------保证显示_高级表格Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cid,int mode ) ); \
    \
    /*--------创建组件_滑动按钮EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SlideButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------置属性_滑动按钮Ex--------*/\
    CMDINFO( void ,  SetAttribute_SlideButtonEx , ( SlideButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------取属性_滑动按钮Ex--------*/\
    CMDINFO( int ,  GetAttribute_SlideButtonEx , ( SlideButtonEx_P control,int index ) ); \
    \
    /*--------创建组件_饼形图Ex--------*/\
    CMDINFO( int ,  CreateControl_PieChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Pierced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain,  int hotGraph, int  GraphStar, int GraphWidth, BOOL Zoom, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------置属性_饼形图Ex--------*/\
    CMDINFO( void ,  SetAttribute_PieChartEx , ( PieChartEx_P control,int index , int  attribute) ); \
    /*--------取属性_饼形图Ex--------*/\
    CMDINFO( int ,  GetAttribute_PieChartEx , ( PieChartEx_P control,int index ) ); \
    /*--------置图例数量_饼形图Ex--------*/\
    CMDINFO( void ,  SetGraphCount_PieChartEx , ( PieChartEx_P control,int Count) ); \
    /*--------取图例数量_饼形图Ex--------*/\
    CMDINFO( int ,  GetGraphCount_PieChartEx , ( PieChartEx_P control) ); \
    /*--------置图例属性_饼形图Ex--------*/\
    CMDINFO( void ,  SetGraphAttr_PieChartEx , ( PieChartEx_P control,int index, int AttrId, int  color ) );\
	/*--------取图例属性_饼形图Ex--------*/\
    CMDINFO( int ,  GetGraphAttr_PieChartEx , ( PieChartEx_P control,int index, int AttrId ) );  \
    /*--------置图例值_饼形图Ex--------*/\
    CMDINFO( void ,  SetGraphValue_PieChartEx , ( PieChartEx_P control,int index, int  Value ) ); \
    /*--------取图例值_饼形图Ex--------*/\
    CMDINFO( int ,  GetGraphValue_PieChartEx , ( PieChartEx_P control,int index ) ); \
    /*--------创建组件_柱状图Ex--------*/\
    CMDINFO( int ,  CreateControl_BarChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Barrced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA, int GridStyleV, int GridColorV,BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, int GraphWidth, int GraphSpace, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------置属性_柱状图Ex--------*/\
    CMDINFO( void ,  SetAttribute_BarChartEx , ( BarChartEx_P control,int index , int  attribute) ); \
    /*--------取属性_柱状图Ex--------*/\
    CMDINFO( int ,  GetAttribute_BarChartEx , ( BarChartEx_P control,int index ) ); \
    /*--------置图例数量_柱状图Ex--------*/\
    CMDINFO( void ,  SetGraphCount_BarChartEx , ( BarChartEx_P control,int Count) ); \
    /*--------取图例数量_柱状图Ex--------*/\
    CMDINFO( int ,  GetGraphCount_BarChartEx , ( BarChartEx_P control) ); \
    /*--------置图例属性_柱状图Ex--------*/\
    CMDINFO( void ,  SetGraphAttr_BarChartEx , ( BarChartEx_P control,int index, int  Attr, int  Colour, int Rgn) );\
	/*--------取图例属性_柱状图Ex--------*/\
    CMDINFO( int ,  GetGraphAttr_BarChartEx , ( BarChartEx_P control,int index, int  Attr ) );  \
    /*--------置图例值_柱状图Ex--------*/\
    CMDINFO( void ,  SetGraphValue_BarChartEx , ( BarChartEx_P control,int index, int  Cid, int  Value ) ); \
    /*--------取图例值_柱状图Ex--------*/\
    CMDINFO( int ,  GetGraphValue_BarChartEx , ( BarChartEx_P control,int index , int  Cid) ); \
    /*--------创建组件_曲线图Ex--------*/\
    CMDINFO( int ,  CreateControl_CurveChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Curverced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin,  int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA,int GridStyleV, int GridColorV, BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------置属性_曲线图Ex--------*/\
    CMDINFO( void ,  SetAttribute_CurveChartEx , ( CurveChartEx_P control,int index , int  attribute) ); \
    /*--------取属性_曲线图Ex--------*/\
    CMDINFO( int ,  GetAttribute_CurveChartEx , ( CurveChartEx_P control,int index ) ); \
    /*--------置图例数量_曲线图Ex--------*/\
    CMDINFO( void ,  SetGraphCount_CurveChartEx , ( CurveChartEx_P control,int Count) ); \
    /*--------取图例数量_曲线图Ex--------*/\
    CMDINFO( int ,  GetGraphCount_CurveChartEx , ( CurveChartEx_P control) ); \
    /*--------置图例属性_曲线图Ex--------*/\
    CMDINFO( void ,  SetGraphAttr_CurveChartEx , ( CurveChartEx_P control,int index, int  Attr,  int Colour, int Tension, int  width, int style, int  PointSize, int HotPointSize) );\
	/*--------取图例属性_曲线图Ex--------*/\
    CMDINFO( int ,  GetGraphAttr_CurveChartEx , ( CurveChartEx_P control,int index , int  Attr) );  \
    /*--------置图例值_曲线图Ex--------*/\
    CMDINFO( void ,  SetGraphValue_CurveChartEx , ( CurveChartEx_P control,int index, int  Cid, int  Value ) ); \
    /*--------取图例值_曲线图Ex--------*/\
    CMDINFO( int ,  GetGraphValue_CurveChartEx , ( CurveChartEx_P control,int index , int  Cid) ); \
    /*--------创建组件_烛线图Ex--------*/\
    CMDINFO( int ,  CreateControl_CandleChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Curverced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA,int GridStyleV, int GridColorV,BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, int GraphWidth, BOOL NegativeHollow, int NegativeColor, BOOL PositiveHollow, int PositiveColor, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------置属性_烛线图Ex--------*/\
    CMDINFO( void ,  SetAttribute_CandleChartEx , ( CandleChartEx_P control,int index , int  attribute) ); \
    /*--------取属性_烛线图Ex--------*/\
    CMDINFO( int ,  GetAttribute_CandleChartEx , ( CandleChartEx_P control,int index ) ); \
    /*--------置图例值_烛线图Ex--------*/\
    CMDINFO( void ,  SetGraphValue_CandleChartEx , ( CandleChartEx_P control,int index,  int DataId, int  openVal, int closeVal, int lowVal, int heighVal) ); \
    /*--------取图例值_烛线图Ex--------*/\
    CMDINFO( int ,  GetGraphValue_CandleChartEx , ( CandleChartEx_P control,int index,  int DataId ) ); \
/*--------创建组件_画板EX--------*/\
CMDINFO( 	Control  * ,   CreateControl_DrawPanelEx ,(Control_P Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Pierced, int  FocusWeight, StrEx_P Cursor, int  Tag,int BackColor,int LineColor,  StrEx_P ElemeData, StrEx_P Layout ) ); \
/*--------置属性_画板EX--------*/\
CMDINFO(void	 ,  	SetAttribute_DrawPanelEx , (DrawPanelEx_P   control, int   index, int  attribute ) ); \
/*--------取属性_画板EX--------*/\
CMDINFO(int		 ,  GetAttribute_DrawPanelEx , (DrawPanelEx_P   control, int   index ) ); \
/*--------画图片_画板EX--------*/\
CMDINFO(void ,  DrawImage_DrawPanelEx , (DrawPanelEx_P   control, ImageEX_P Image, float dstX, float dstY, float dstWidth, float dstHeight, float srcx, float srcy, float srcwidth, float srcheight, int Alpha ) ); \
/*--------画文本_画板EX--------*/\
CMDINFO(void  ,  DrawString_DrawPanelEx , (DrawPanelEx_P   control, StrEx_P string, float dstX, float dstY, float dstWidth, float dstHeight, BinEx_P font, int StringFormat, int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画路径_画板EX--------*/\
CMDINFO(void  ,  DrawPath_DrawPathEx , (DrawPanelEx_P   control, int Path, int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画多边形_画板EX--------*/\
CMDINFO(void  ,  DrawPolygon_DrawPanelEx , (DrawPanelEx_P   control, float * Points, int count,  int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画矩形_画板EX--------*/\
CMDINFO(void  ,  DrawRect_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height,  int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画椭圆_画板EX--------*/\
CMDINFO(void  ,  DrawEllipse_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height,  float Rgn, int DrawMode, int  DrawParame, int color, int  auxcolor ) ); \
/*--------画饼_画板EX--------*/\
CMDINFO(void  ,  DrawPie_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, float starAngle, float sweepAngle, int DrawMode, int  DrawParame, int color, int  auxcolor ) ); \
/*--------画曲线_画板EX--------*/\
CMDINFO(void  ,  DrawCurve_DrawPanelEx , (DrawPanelEx_P   control, float * Points, int count, float tension, int linemode , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画弧线_画板EX--------*/\
CMDINFO(void  ,  DrawArc_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, float starAngle, float sweepAngle , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------画直线_画板EX--------*/\
CMDINFO(void  ,  DrawLine_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------清除_画板EX--------*/\
CMDINFO(void  ,  Clear_DrawPanelEx , (DrawPanelEx_P   control, int colour, float X, float Y, float Width, float Height, BOOL mode  ) ); \
/*--------更新_画板EX--------*/\
CMDINFO(void ,   Update_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, BOOL mode ) ); \
/*--------置剪辑区_画板EX--------*/\
CMDINFO(void ,   SetClip_DrawPanelEx , (DrawPanelEx_P  control,int CombineMd,int cliptype,int  Clip ,float X, float Y, float Width, float Height, float Rgn ) ); \
/*--------置绘图质量_画板EX--------*/\
CMDINFO(void ,   SetGraphicsquality_DrawPanelEx , (DrawPanelEx_P   control,int Smoothing, int Interpolation, int PixelOffset) ); \
/*--------取绘图数据_画板EX--------*/\
CMDINFO(int ,   GetGraphicsData_DrawPanelEx , (DrawPanelEx_P   control,int Type, float X, float Y, float Width, float Height) ); \



/*------------------------------------------EXUI接口结束------------------------------------------*/



/*------------------------------------------以下代码无需关注-----------------------------------------*/
#define 	Definition2( returnVal  ,  name  , parameter )    \
		   	__declspec(selectany)  PFN_##name    name = NULL;\

#define 	Definition( returnVal  ,  name  , parameter )    \
typedef  	returnVal   (WINAPI  * PFN_##name )   parameter  ;\
		extern 	   PFN_##name    name;\

#define		Initial( returnVal  ,  name  , parameter  )  name## = (PFN_##name)GetProcAddressmy(exuihDllInst, #name);\
//if ( ! name    ) {MessageBoxA(((HWND)0), #name,  "Ex_ui api not found", 0);}


typedef   int (WINAPI * FUN_GetProcAddressmy)(HMODULE hModule, LPCSTR lpProcName);

int * InitExui(char * data, int datalong);
extern HINSTANCE exuihDllInst;

EX_UI_CMDINFO_Category1(Definition)
EX_UI_CMDINFO_Category2(Definition)
EX_UI_CMDINFO_Category3(Definition)
EX_UI_CMDINFO_Category4(Definition)
EX_UI_CMDINFO_Category5(Definition)
EX_UI_CMDINFO_Category6(Definition)
EX_UI_CMDINFO_Category7(Definition)


#ifdef _NoExuiDll

#define		Memdll1  if(datalong!=4) {int MemLoadExuiLibrary();  exuihDllInst= (HINSTANCE)MemLoadExuiLibrary(); GetProcAddressmy = (FUN_GetProcAddressmy)MemGetProcAddress;   if (exuihDllInst) {info[0]=(int)exuihDllInst; info[1]= 1; info[2]=(int)MemLoadLibrary; info[3]=(int)MemGetProcAddress; info[4]=(int)MemFreeDll;} }

#endif

#ifndef _NoExuiDll 

#define		Memdll1   

#endif


#ifdef __E_STATIC_LIB

#define	 strcat_s strcat

#endif


//装载切换器 请求切换器加载

#define		EX_UI_CMDINFO \
EX_UI_CMDINFO_Category1(Definition2)\
EX_UI_CMDINFO_Category2(Definition2)\
EX_UI_CMDINFO_Category3(Definition2)\
EX_UI_CMDINFO_Category4(Definition2)\
EX_UI_CMDINFO_Category5(Definition2)\
EX_UI_CMDINFO_Category6(Definition2)\
EX_UI_CMDINFO_Category7(Definition2)\
\
\
 HINSTANCE exuihDllInst = NULL; \
int* InitExui(char * data,int datalong){\
HINSTANCE WINAPI  MemLoadLibrary(const BYTE * lpFileData , int DataLength); 	FARPROC WINAPI  MemGetProcAddress(HINSTANCE  Dll, LPCSTR lpProcName);	void WINAPI MemFreeDll(HINSTANCE *   MemDll);\
   static int info[5]={0,0,0,0,0};  \
  if (datalong==4){exuihDllInst=NULL;   }\
  if (exuihDllInst) { return info; }\
  FUN_GetProcAddressmy   GetProcAddressmy = NULL;  \
if (exuihDllInst == NULL ) { Memdll1 }\
if (exuihDllInst == NULL ){\
if (data){\
	if (datalong == 4) {memcpy(info, (void*)(*(int*)data),20);  exuihDllInst= (HINSTANCE)info[0];  GetProcAddressmy =(FUN_GetProcAddressmy)info[3]; }             \
	else if (datalong) {exuihDllInst = MemLoadLibrary((BYTE *)data, datalong); if (exuihDllInst) { GetProcAddressmy = (FUN_GetProcAddressmy)MemGetProcAddress;   info[0]=(int)exuihDllInst; info[1]= 1; info[2]=(int)MemLoadLibrary; info[3]=(int)MemGetProcAddress; info[4]=(int)MemFreeDll;  } }\
	else { exuihDllInst = LoadLibrary((TCHAR *)data);    if (exuihDllInst) {GetProcAddressmy = (FUN_GetProcAddressmy)GetProcAddress; info[0]=(int)exuihDllInst; info[1]= 0; info[2]=(int)LoadLibrary; info[3]=(int)GetProcAddress; info[4]=(int)FreeLibrary ;} }\
}\
}\
/*-------------若载入失败则从ExuiKrnln.dll文件载入---------------*/ \
if (exuihDllInst == NULL){\
	if (exuihDllInst == NULL) {\
		char path2[255];\
		GetCurrentDirectoryA(254, path2);\
		strcat_s(path2, "\\ExuiKrnln.dll");\
		exuihDllInst = LoadLibraryA(path2);\
	if (exuihDllInst == NULL) { \
		GetCurrentDirectoryA(254, path2); \
		strcat_s(path2, "\\lib\\ExuiKrnln\\ExuiKrnln.dll"); \
		exuihDllInst = LoadLibraryA(path2); \
	}\
	}\
	if (exuihDllInst == NULL) { exuihDllInst = LoadLibraryA("ExuiKrnln.dll"); }\
	if (exuihDllInst == NULL) { exuihDllInst = LoadLibraryA("lib\\ExuiKrnln\\ExuiKrnln.dll");}\
	if (exuihDllInst == NULL){\
	HANDLE	handle = CreateFile(TEXT("C:\\ExuiKrnln.ini"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);\
	if (handle == NULL) { handle = CreateFile(TEXT("D:\\ExuiKrnln.ini"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL); }\
	if (handle)	{\
				char 	readBuf[256];   DWORD  len = 256;\
				if (ReadFile(handle, &readBuf[0], 255, &len, NULL) != 0) {\
					readBuf[len / sizeof(char)] = L'\0';\
					exuihDllInst = LoadLibraryA(readBuf);\
				}\
				CloseHandle(handle);\
			}\
	}\
	if (exuihDllInst) { GetProcAddressmy = (FUN_GetProcAddressmy)GetProcAddress; info[0]=(int)exuihDllInst; info[1]= 0; info[2]=(int)LoadLibraryA; info[3]=(int)GetProcAddress; info[4]=(int)FreeLibrary;}\
}\
if (exuihDllInst && GetProcAddressmy) {	\
		EX_UI_CMDINFO_Category1(Initial)\
		EX_UI_CMDINFO_Category2(Initial)\
		EX_UI_CMDINFO_Category3(Initial)\
		EX_UI_CMDINFO_Category4(Initial)\
		EX_UI_CMDINFO_Category5(Initial)\
		EX_UI_CMDINFO_Category6(Initial)\
		EX_UI_CMDINFO_Category7(Initial)\
		if (CallInternalFunction_Ex) { exuihDllInst= (HINSTANCE) CallInternalFunction_Ex(2008, (int)exuihDllInst, 0, 0, 20220128); }\
}\
if (exuihDllInst) {return info; }\
return NULL; \
\
}


/*if (exuihDllInst == NULL) { return NULL; / * MessageBoxA(((HWND)0), "程序缺少界面运行库必须依赖的 ExuiKrnln.dll 文件", "Warning", 0);  return NULL;* / }*/\
















