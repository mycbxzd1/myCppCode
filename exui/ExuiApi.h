
#pragma once


#include "windows.h"

/*------------------------------------------EXUI��������------------------------------------------*/



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



/*------------------------------------------EXUI����------------------------------------------*/



/*------------------------------------------EXUI����------------------------------------------*/

/*--------------Category1--------------*/

#define 	EX_UI_CMDINFO_Category1(CMDINFO)  \
    /*--------����exui�ڲ�����--------*/\
    CMDINFO( int ,  CallInternalFunction_Ex , ( int msg,int parameter1,int parameter2,int parameter3,int parameter4 ) ); \
    \
    /*--------װ��λͼ--------*/\
    CMDINFO( ImageEX_P ,  LoadImageEx , ( BinEx_P data ,int Mode,int Width,int Height,int Angle,int LineClour, int LineWidth, int Alignment) ); \
    \
    /*--------����λͼ--------*/\
    CMDINFO( void ,  DestroyImageEx , ( ImageEX_P image ) ); \
    \
    /*--------ȡλͼ����--------*/\
    CMDINFO( int ,  GetImageAttributeEx , ( ImageEX_P image, int Type ) ); \
    \
    /*--------ȡλͼ����--------*/\
    CMDINFO( BinEx_P ,  GetImageData , ( ImageEX_P image ) ); \
    \
    /*--------�����ڴ�Ex--------*/\
    CMDINFO( BinEx_P ,  CreateBinEx , ( void * data,int datalength ) ); \
    \
    /*--------�����ڴ�Ex--------*/\
    CMDINFO( void ,  DeleteBinEx , ( BinEx_P binex ) ); \
    \
    /*--------ȡ�ڴ�Ex���ݵ�ַ--------*/\
    CMDINFO( void * ,  GetBinExDataPointer , ( BinEx_P binex ) ); \
    \
    /*--------ȡ�ڴ�Ex���ݳ���--------*/\
    CMDINFO( int ,  GetBinExDatalength , ( BinEx_P binex ) ); \
    \
    /*--------ȡ�ڴ�Ex����ָ�� CMDINFO( BinEx*GetBInExCache--------*/\
    CMDINFO( BinEx_P ,  GetBInExCache , ( BinEx_P binex ) ); \
    \
    /*--------�������--------*/\
    CMDINFO( BOOL ,  ControlCreate , ( Control_P control,Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,BOOL Visual,BOOL Disabled,int Transparency,void * Callback,void * PrivateEvent,int controlType,int Penetrate,BinEx_P Cursor,int focusweight,int sign ,BinEx_P Layout) ); \
    \
    /*--------�������--------*/\
    CMDINFO( void ,  ControlDestroy , ( Control_P control ) ); \
    \
    /*--------����Ƿ��Ѵ���--------*/\
    CMDINFO( BOOL ,  ControlIsCreate , ( Control_P control ) ); \
    \
    /*--------���������Ϣ--------*/\
    CMDINFO( int ,  ControlSendMessage , ( Control_P control,int msg,int Parameter1,int Parameter2,int Parameter3,int Parameter4 ) ); \
    \
    /*--------��������Ӽ���Ϣ--------*/\
    CMDINFO( void ,  ControlSendChildMessage , ( Control_P control,int msg,int Parameter1,int Parameter2,int Parameter3,int Parameter4 ) ); \
    \
    /*--------������»���--------*/\
    CMDINFO( BOOL ,  ControlUpdateCache , (  ) ); \
    \
    /*--------���ȡ�ര�ڶ���--------*/\
    CMDINFO( int ,  ControlGetWindowTop , ( Control_P control ) ); \
    \
    /*--------���ȡ�ര�����--------*/\
    CMDINFO( int ,  ControlGetWindowLeft , ( Control_P control ) ); \
    \
    /*--------��������--------*/\
    CMDINFO( void ,  ControlSetLeft , ( Control_P control,int Left ) ); \
    \
    /*--------���ȡ���--------*/\
    CMDINFO( int ,  ControlGetLeft , ( Control_P control ) ); \
    \
    /*--------����ö���--------*/\
    CMDINFO( void ,  ControlSetTop , ( Control_P control,int Top ) ); \
    \
    /*--------���ȡ����--------*/\
    CMDINFO( int ,  ControlGetTop , ( Control_P control ) ); \
    \
    /*--------����ÿ��--------*/\
    CMDINFO( void ,  ControlSetWidth , ( Control_P control,int Width ) ); \
    \
    /*--------���ȡ���--------*/\
    CMDINFO( int ,  ControlGetWidth , ( Control_P control ) ); \
    \
    /*--------����ø߶�--------*/\
    CMDINFO( void ,  ControlSetHeight , ( Control_P control,int Height ) ); \
    \
    /*--------���ȡ�߶�--------*/\
    CMDINFO( int ,  ControlGetHeight , ( Control_P control ) ); \
    \
    /*--------���ȡ����--------*/\
    CMDINFO( void ,  ControlGetRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------����þ���--------*/\
    CMDINFO( void ,  ControlSetRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------���ȡ��ʵ����--------*/\
    CMDINFO( BOOL ,  ControlGetTrueVisual , ( Control_P control ) ); \
    \
    /*--------���ȡ����--------*/\
    CMDINFO( BOOL ,  ControlGetVisual , ( Control_P control ) ); \
    \
    /*--------����ÿ���--------*/\
    CMDINFO( void ,  ControlSetVisual , ( Control_P control,BOOL Visual ) ); \
    \
    /*--------���ȡ��ʵ��ֹ--------*/\
    CMDINFO( BOOL ,  ControlGetTrueDisabled , ( Control_P control ) ); \
    \
    /*--------���ȡ��ֹ--------*/\
    CMDINFO( BOOL ,  ControlGetDisabled , ( Control_P control ) ); \
    \
    /*--------����ý�ֹ--------*/\
    CMDINFO( void ,  ControlSetDisabled , ( Control_P control,BOOL UpdateDisabled ) ); \
    \
    /*--------����ù��--------*/\
    CMDINFO( void ,  ControlSetCursor , ( Control_P control,BinEx_P Cursor ) ); \
    \
    /*--------���ȡ���--------*/\
    CMDINFO( BinEx_P ,  ControlGetCursor , ( Control_P control ) ); \
    \
    /*--------����ù��id--------*/\
    CMDINFO( void ,  ControlSetCursorId , ( Control_P control,int CursorId ) ); \
    \
    /*--------���ȡ���id--------*/\
    CMDINFO( int ,  ControlGetCursorId , ( Control_P control ) ); \
    \
    /*--------���ȡ��괩͸--------*/\
    CMDINFO( int ,  ControlGetPenetrate , ( Control_P control ) ); \
    \
    /*--------�������괩͸--------*/\
    CMDINFO( void ,  ControlSetPenetrate , ( Control_P control,int Penetrate ) ); \
    \
    /*--------���ȡ͸����--------*/\
    CMDINFO( int ,  ControlGetTransparency , ( Control_P control ) ); \
    \
    /*--------�����͸����--------*/\
    CMDINFO( void ,  ControlSetTransparency , ( Control_P control,int Transparency ) ); \
    \
    /*--------����ý���Ȩ��--------*/\
    CMDINFO( void ,  ControlSetFocusWeight , ( Control_P control,int FocusWeight ) ); \
    \
    /*--------���ȡ����Ȩ��--------*/\
    CMDINFO( int ,  ControlGetFocusWeight , ( Control_P control ) ); \
    \
    /*--------����ý������--------*/\
    CMDINFO( void ,  ControlSetFocusControl , ( Control_P control ) ); \
    \
    /*--------���ȡ�������--------*/\
    CMDINFO( Control_P ,  ControlGetFocusControl , (  ) ); \
    \
    /*--------���ȡ��һ�������--------*/\
    CMDINFO( Control_P ,  ControlGetMaxFocusWeightControl , ( Control_P control ) ); \
    \
    /*--------���ȡ��һ�������--------*/\
    CMDINFO( Control_P ,  ControlGetNextFocusControl , ( Control_P control ) ); \
    \
    /*--------���ȡ��겶�����--------*/\
    CMDINFO( Control_P ,  ControlGetCaptureControl , (  ) ); \
    \
    /*--------�������겶�����--------*/\
    CMDINFO( void ,  ControlSetCaptureControl , ( Control_P control ) ); \
    \
    /*--------���ȡ�ȵ����--------*/\
    CMDINFO( Control_P ,  ControlGetHotControl , (  ) ); \
    \
    /*--------���ȡ����������--------*/\
    CMDINFO( Control_P ,  ControlGetLeftPressControl , (  ) ); \
    \
    /*--------���ȡ�Ҽ��������--------*/\
    CMDINFO( Control_P ,  ControlGetRightPressControl , (  ) ); \
    \
    /*--------���������--------*/\
    CMDINFO( void ,  ControlSetcontrolType , ( Control_P control,int controlType ) ); \
    \
    /*--------���ȡ����--------*/\
    CMDINFO( int ,  ControlGetcontrolType , ( Control_P control ) ); \
    \
    /*--------����ñ�ʶ--------*/\
    CMDINFO( void ,  ControlSetsign , ( Control_P control,int sign ) ); \
    \
    /*--------���ȡ��ʶ--------*/\
    CMDINFO( int ,  ControlGetsign , ( Control_P control ) ); \
    \
    /*--------����ûص�--------*/\
    CMDINFO( int ,  ControlSetCallback , ( Control_P control,void * PublicCallback, void * PrivateCallback ) ); \
    \
    /*--------���ȡ�ص�--------*/\
    CMDINFO( void * ,  ControlGetCallback , ( Control_P control, int GetMode ) ); \
    \
    /*--------������ûص�--------*/\
    CMDINFO( int ,  ControInvokeCallback , ( Control_P control, int msg, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4 ,void * Callback )); \
    \
    /*--------���ȡ���ڴ��ھ��--------*/\
    CMDINFO( int ,  ControlGetWindow , ( Control_P control ) ); \
    \
    /*--------���ȡ����󶨴���--------*/\
    CMDINFO( int ,  ControlGetBindWin , ( Control_P control ) ); \
    \
    /*--------���ȡ���ڰ����--------*/\
    CMDINFO( Control_P ,  ControlGetBindControl , ( HWND WindowHandle ) ); \
    \
    /*--------���ȡ�豸������--------*/\
    CMDINFO( int ,  ControlGetDc , ( Control_P control ) ); \
    \
    /*--------���ȡͼ��--------*/\
    CMDINFO( int ,  ControlGetGraphics , ( Control_P control ) ); \
    \
    /*--------���ȡλͼ--------*/\
    CMDINFO( int ,  ControlGetHBITMAP , ( Control_P control ) ); \
    \
    /*--------�������ػ���--------*/\
    CMDINFO( void ,  ControlAddRedrawRect , ( Control_P control,int Left,int Top,int Width,int Height ) ); \
    \
    /*--------��������ػ�--------*/\
    CMDINFO( void ,  ControlRedraw , ( Control_P control ) ); \
    \
    /*--------�����ͣ�ػ�--------*/\
    CMDINFO( int ,  ControlLockUpdate , ( Control_P control ) ); \
    \
    /*--------��������ػ�--------*/\
    CMDINFO( int ,  ControlUnlockUpdate , ( Control_P control ) ); \
    \
    /*--------���ȡ�ػ���������--------*/\
    CMDINFO( int ,  ControlGetLockUpdateCount , ( Control_P control ) ); \
    \
    /*--------���ȡ�����--------*/\
    CMDINFO( Control_P ,  ControlGetParentControl , ( Control_P control ) ); \
    \
    /*--------����ø����--------*/\
    CMDINFO( BOOL ,  ControlSetParentControl , ( Control_P control,Control_P Parentcontrol,BOOL mode,int NewLeft,int NewTop ) ); \
    \
    /*--------��������Ӽ�--------*/\
    CMDINFO( BOOL ,  ControlHaveChild , ( Control_P control ) ); \
    \
    /*--------���ȡ�Ӽ������--------*/\
    CMDINFO( int ,  ControlGetChildCount , ( Control_P control, BOOL mode ) ); \
    \
    /*--------���ö���Ӽ����--------*/\
    CMDINFO( BinEx_P ,  ControlEnumerateChild , ( Control_P control, BOOL mode  ) ); \
    \
    /*--------���ȡ��һ���--------*/\
    CMDINFO( Control_P ,  ControlGetLastcontrol , ( Control_P control ) ); \
    \
    /*--------���ȡ��һ���--------*/\
    CMDINFO( Control_P ,  ControlGetNextcontrol , ( Control_P control ) ); \
    \
    /*--------���ȡǶ�ײ��--------*/\
    CMDINFO( int ,  ControlGetNestingLevel , ( Control_P control ) ); \
    \
    /*--------���ȡ������--------*/\
    CMDINFO( Control_P ,  ControlGetlevelcontrol , ( int level ) ); \
    \
    /*--------����ò��--------*/\
    CMDINFO( void ,  ControlSetlevel , ( Control_P control,Control_P RelativeControl ) ); \
    \
    /*--------���ȡ���--------*/\
    CMDINFO( int ,  ControlGetlevel , ( Control_P control ) ); \
    \
    /*--------��������ڴ��ڷֲ�͸��--------*/\
    CMDINFO( void ,  ControlSetWinLayered , ( Control_P control,int Layered ) ); \
    \
    /*--------���ȡ���ڴ��ڷֲ�͸��--------*/\
    CMDINFO( int ,  ControlGetWinLayered , ( Control_P control ) ); \
    \
    /*--------���ȡ���ڴ���ͼ��--------*/\
    CMDINFO( int ,  ControlGetWinGraphics , ( Control_P control ) ); \
    \
    /*--------���ȡ���ڴ���λͼ--------*/\
    CMDINFO( int ,  ControlGetWinHBITMAP , ( Control_P control ) ); \
    \
    /*--------���ȡ���ڴ����豸������--------*/\
    CMDINFO( int ,  ControlGetWinDc , ( Control_P control ) ); \
    \
    /*--------��������ڴ���ˢ�»ص�--------*/\
    CMDINFO( int ,  ControlSetWinRefreshCallBack , ( Control_P control,int CallBack ) ); \
    \
    /*--------���ȡ���ڴ���ˢ�»ص�--------*/\
    CMDINFO( int ,  ControlGetWinRefreshCallBack , ( Control_P control ) ); \
    \
    /*--------���ˢ�����ڴ���--------*/\
    CMDINFO( void ,  ControlRefreshWin , ( Control_P control ) ); \
    \
    /*--------�����ͣ�ػ����ڴ���--------*/\
    CMDINFO( int ,  ControlLockWinUpdate , ( Control_P control ) ); \
    \
    /*--------��������ػ����ڴ���--------*/\
    CMDINFO( int ,  ControlUnlockWinUpdate , ( Control_P control ) ); \
    \
    /*--------���ȡ���ڴ����ػ�����״̬--------*/\
    CMDINFO( int ,  ControlGetWinLockUpdateCount , ( Control_P control ) ); \
    /*--------���ȡ����ҳ��--------*/\
	CMDINFO(int ,  ControlGetPage,(Control_P    control)); \
	/*--------���������ҳ��--------*/\
	CMDINFO(void,   ControlSetPage,(Control_P   control, int Page)); \
	/*--------���ȡ��ǰҳ��--------*/\
	CMDINFO(int ,  ControlGetCurrentPage,(Control_P    control)); \
	/*--------����õ�ǰҳ��--------*/\
	CMDINFO(void,   ControlSetCurrentPage,(Control_P    control, int Page)); \
	/*--------���ȡ������--------*/\
	CMDINFO(BinEx_P, ControlGetLayoutConfig, (Control_P    control)); \
	/*--------����ò�����--------*/\
	CMDINFO(void, ControlSetLayoutConfig, (Control_P    control, BinEx_P Layout)); \
	/*--------����ύ����--------*/\
	CMDINFO(int, ControlSubmitTask, (Control_P    control, int type,int cmd,  int sign, int Parame)); \





/*--------------Category2--------------*/

#define 	EX_UI_CMDINFO_Category2(CMDINFO)  \
/*--------���ִ��Ԫ������--------*/\
CMDINFO(int , ControlRunElemCmd, (Control_P control, int Type, int   index, int  ColumnId, int   CtrId, int Cmd, int parameter1, int parameter2, int parameter3, int parameter4)); \
\
/*--------�õײ�Ԫ������--------*/\
CMDINFO(void, ControlSetUnderlyElemCount, (Control_P control, int Type, int  cloid, int Num ) ); \
\
/*--------ȡ�ײ�Ԫ������--------*/\
CMDINFO(int, ControlGetUnderlyElemCount, (Control_P control, int Type, int  cloid ) ); \
\
/*--------�������Ԫ��--------*/\
    CMDINFO( int ,  ControlInsertElem , ( Control_P control,int Type,int cloid,int ctrlindex,int addnum ) ); \
    \
    /*--------���ɾ��Ԫ��--------*/\
    CMDINFO( void ,  ControlDeleteElem , ( Control_P control,int Type,int cloid,int delindex,int deletenum ) ); \
    \
    /*--------���ȡԪ������--------*/\
    CMDINFO( int ,  ControlGetElemCount , ( Control_P control,int Type,int cloid ) ); \
    \
    /*--------�������Ԫ��--------*/\
    CMDINFO( void ,  ControlResetElem , ( Control_P control,int Type,int cloid,int delindex,int deletenum ) ); \
    \
    /*--------�����Ԫ������_ͼƬ--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Imsge , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle ) ); \
    \
    /*--------���ȡԪ������_ͼƬ--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Imsge , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_ͼƬ--------*/\
    CMDINFO( void ,  ControlSetElemData_Imsge , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,ImageEX_P IcoData ) ); \
    \
    /*--------���ȡԪ������_ͼƬ--------*/\
    CMDINFO( int ,  ControlGetElemData_Imsge , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------�����Ԫ������_�ı�--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Text , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Font,int Align ) ); \
    \
    /*--------���ȡԪ������_�ı�--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Text , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_�ı�--------*/\
    CMDINFO( void ,  ControlSetElemData_Text , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor ) ); \
    \
    /*--------���ȡԪ������_�ı�--------*/\
    CMDINFO( int ,  ControlGetElemData_Text , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------�����Ԫ������_��ť--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Button , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,BinEx_P Font ) ); \
    \
    /*--------���ȡԪ������_��ť--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Button , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_��ť--------*/\
    CMDINFO( void ,  ControlSetElemData_Button , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor,BOOL Select ) ); \
    \
    /*--------���ȡԪ������_��ť--------*/\
    CMDINFO( int ,  ControlGetElemData_Button , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------�����Ԫ������_ѡ���--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Select , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,BinEx_P Font,int IconWidth,int IconHeight ) ); \
    \
    /*--------���ȡԪ������_ѡ���--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Select , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_ѡ���--------*/\
    CMDINFO( void ,  ControlSetElemData_Select , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Title,int FontColor,int Select ) ); \
    \
    /*--------���ȡԪ������_ѡ���--------*/\
    CMDINFO( int ,  ControlGetElemData_Select , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------�����Ԫ������_�༭�ı�--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_EditText , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,int ShowMode, BinEx_P  Skin, BinEx_P  Font, int  Align, StrEx_P  PasswordSubstitution, BinEx_P Cursor, BOOL  Multiline, int InputMode, int  MaxInput, BinEx_P  EditFont, int  EditFontColor, int  CursorColor, int  SelectedFontColor, int SelectedColor, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuLanguage) ); \
    \
    /*--------���ȡԪ������_�༭�ı�--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_EditText , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_�༭�ı�--------*/\
    CMDINFO( void ,  ControlSetElemData_EditText , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,StrEx_P Content,int FontColor ) ); \
    \
    /*--------���ȡԪ������_�༭�ı�--------*/\
    CMDINFO( int ,  ControlGetElemData_EditText , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
     \
    /*--------�����Ԫ������_��ϰ�ť--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_ComboButton , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P  Skin, BinEx_P  Font, int  IconWidth, int  IconHeight, int  Align) ); \
    \
    /*--------���ȡԪ������_��ϰ�ť--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_ComboButton , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_��ϰ�ť--------*/\
    CMDINFO( void ,  ControlSetElemData_ComboButton , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  BackColor, int    image,  StrEx_P Content, int FontColor, int PartnerStay ) ); \
    \
    /*--------���ȡԪ������_��ϰ�ť--------*/\
    CMDINFO( int ,  ControlGetElemData_ComboButton , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
    \
    /*--------�����Ԫ������_������--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Progressbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,int  Style ) ); \
    \
    /*--------���ȡԪ������_������--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Progressbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_������--------*/\
    CMDINFO( void ,  ControlSetElemData_Progressbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  Position) ); \
    \
    /*--------���ȡԪ������_������--------*/\
    CMDINFO( int ,  ControlGetElemData_Progressbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	\
    /*--------�����Ԫ������_������--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Sliderbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,BinEx_P Skin,int  Style) ); \
    \
    /*--------���ȡԪ������_������--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Sliderbar , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_������--------*/\
    CMDINFO( void ,  ControlSetElemData_Sliderbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int  Position ) ); \
    \
    /*--------���ȡԪ������_������--------*/\
    CMDINFO( int ,  ControlGetElemData_Sliderbar , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	\
    /*--------�����Ԫ������_��ɫ--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Colour , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle) ); \
    \
    /*--------���ȡԪ������_��ɫ--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Colour , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_��ɫ--------*/\
    CMDINFO( void ,  ControlSetElemData_Colour , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban,int Stay,int   Colour) ); \
    \
    /*--------���ȡԪ������_��ɫ--------*/\
    CMDINFO( int ,  ControlGetElemData_Colour , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \
	 \
    /*--------�����Ԫ������_ֱ��--------*/\
    CMDINFO( void ,  ControlSetElemAttribute_Line , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId,void * callback,int Layout,int left,int top,int width,int Height,int Ctrstyle,int  LineWidth) ); \
    \
    /*--------���ȡԪ������_ֱ��--------*/\
    CMDINFO( int ,  ControlGetElemAttribute_Line , ( Control_P control,int Type,int ColumnId,int CtrId,int AttributeId ) ); \
    \
    /*--------�����Ԫ������_ֱ��--------*/\
    CMDINFO( void ,  ControlSetElemData_Line , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int AttributeId,BOOL Show,BOOL Ban, int Stay,int   Colour ) ); \
    \
    /*--------���ȡԪ������_ֱ��--------*/\
    CMDINFO( int ,  ControlGetElemData_Line , ( Control_P control,int Type,int index,int ColumnId,int CtrId,int DataId ) ); \


/*--------------Category3--------------*/

#define 	EX_UI_CMDINFO_Category3(CMDINFO)  \
    /*--------��Ϣ��Ex--------*/\
    CMDINFO( int ,  MsgBox_Ex , ( BinEx_P Ico,StrEx_P Title,BinEx_P TipIco,StrEx_P TipTitle,StrEx_P Button,int DefaultBtn,HWND hWndParent,int Style,BinEx_P Skin,void * callback,int Parameter ) ); \
    \
    /*--------�����Ex--------*/\
    CMDINFO( StrEx_P ,  InputBox_Ex , ( BinEx_P Ico,StrEx_P Title,BinEx_P TipIco,StrEx_P TipTitle,StrEx_P Button,int DefaultBtn,StrEx_P Conten,int InputMode,StrEx_P PasswordSubstitution,int MaxInput,BOOL Multiline,int * SelectResult,HWND hWndParent,int Style,BinEx_P Skin,void * callback,int Parameter_ ) ); \
    \
    /*--------������ʾ��Ex--------*/\
    CMDINFO( int ,  PopUpTipBoxEx , (  BinEx_P Ico, StrEx_P TipTitle, int 	PopUpMode, int x, int  y, int width, int height, int  AutoCloseTime, int  Angle,   int BackColor, int BorderColor, int LineWidth, BinEx_P Font, int  FontColor, int  Align, int  Transparency) ); \
    \
    /*--------�ر���ʾ��Ex--------*/\
    CMDINFO( void ,  CloseTipBoxEx , (  ) ); \
    \
	 /*--------���������Ex--------*/\
    CMDINFO( StrEx_P ,  PopUpLiteInputEx , ( int X, int Y, int nWidth, int nHeight, int callback, StrEx_P Content, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, int  Align, BOOL  Multiline, BOOL  Wrapped,BinEx_P Skin, BinEx_P  Cursor, BinEx_P  Font, int  FontClour, int  SelectedFontColor, int  SelectedColor, int  CursorColor, int  ScrollBarMode,int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage)); \
    \
	/*--------ʱ��ѡ���--------*/\
    CMDINFO( int ,  TimePickBox_Ex , ( BinEx_P Ico, StrEx_P  TipTitle, StrEx_P Button, int  DefaultBtn, int  Width, int  Height, StrEx_P  SelectionDate,  StrEx_P  MiniDate, StrEx_P  MaxDate, BOOL  OtherMonthClour, int TimeMode,  int  Language,  int * SelectResult, HWND hWndParent, int Style, BinEx_P  Skin, int   Callback, int  Parameter )   ); \
    \
    /*--------��ɫѡ���--------*/\
    CMDINFO( int ,  ColorPickExBox_Ex , (  BinEx_P  Ico, StrEx_P  TipTitle, StrEx_P Button, int  DefaultBtn, int  Width, int  Height,int  NowClour,   BinEx_P  QuickClours, int ClourMode,  int  ColorPickStyle ,   int * SelectResult,  HWND hWndParent, int Style, BinEx_P  Skin,   int   Callback, int  Parameter  ) ); \
    \
    /*--------����ʱ��ѡ����--------*/\
    CMDINFO( int ,  PopUpTimePick_Ex , ( int LEFT, int  Top,int  Width, int  Height,  StrEx_P Button, int  DefaultBtn, StrEx_P  SelectionDate,  StrEx_P  MiniDate, StrEx_P  MaxDate, BOOL  OtherMonthClour, int TimeMode,  int  Language,   int * SelectResult, HWND hWndParent, int Style, BinEx_P  Skin, int   Callback, int  Parameter )   ); \
    \
    /*--------������ɫѡ����--------*/\
    CMDINFO( int ,  PopUpColorPick_Ex , (int LEFT, int  Top, int  Width, int  Height, StrEx_P Button, int  DefaultBtn,  int  NowClour,   BinEx_P  QuickClours, int ClourMode,  int  ColorPickStyle ,   int * SelectResult,  HWND hWndParent, int Style, BinEx_P  Skin,   int   Callback, int  Parameter  ) ); \
    \
    /*--------�ļ�ѡ���--------*/\
    CMDINFO( int ,  FileSelectionbox_Ex , (  ) ); \
    \
    /*--------������Ŀ����༭��Ex--------*/\
    CMDINFO( StrEx_P ,  PopUpItemInputEx , ( Control_P     control, int index, int  cloid, int retain,int mode , StrEx_P  Content, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, int  Align, BOOL  Multiline, BOOL  Wrapped, BinEx_P  Skin,BinEx_P Cursor, BinEx_P  Font, int  FontClour, int  SelectedFontColor, int  SelectedColor, int  CursorColor, int  ScrollBarMode, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage) ); \



/*--------------Category4--------------*/

#define 	EX_UI_CMDINFO_Category4(CMDINFO)  \
    /*--------����_�˵�Ex--------*/\
    CMDINFO( MenuEx_P ,  Create_MenuEx , ( int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,int Transparency,void * callback,int MenuTag ) ); \
    \
    /*--------������_�˵�Ex--------*/\
    CMDINFO( void ,  SetAttribute_MenuEx , ( MenuEx_P control,int index, int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,int Transparency,void * callback,int MenuTag ) ); \
    \
    /*--------ȡ����_�˵�Ex--------*/\
    CMDINFO( int ,  GetAttribute_MenuEx , ( MenuEx_P control,int index ) ); \
    \
    /*--------����_�˵�Ex--------*/\
    CMDINFO( void ,  Destroy_MenuEx , ( MenuEx_P control ) ); \
    \
    /*--------�Ƿ��ѵ���_�˵�Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------����_�˵�Ex--------*/\
    CMDINFO( void ,  PopUp_MenuEx , ( MenuEx_P menuEx,int MenuId,int left,int top,HWND hWndParent,BOOL Modal , Control_P ExceptionControl) ); \
    \
    /*--------�ر�_�˵�Ex--------*/\
    CMDINFO( void ,  Close_MenuEx , ( MenuEx_P contro,MenuInfo_P MenuIdl, BOOL Mode ) ); \
    \
    /*--------����_�˵�Ex--------*/\
    CMDINFO( int ,  InsertItem_MenuEx , ( MenuEx_P menuEx,MenuInfo_P ParentMenu,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int DisabledFontColor,int Width,int Size,int Type,BOOL Disabled ) ); \
    \
    /*--------ɾ��_�˵�Ex--------*/\
    CMDINFO( void ,  DeleteItem_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------ȡ����_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemCount_MenuEx , ( MenuEx_P control ) ); \
    \
    /*--------��ͼ��_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemIco_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_�˵�Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------�ñ���_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemTitle_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,StrEx_P Title ) ); \
    \
    /*--------ȡ����_�˵�Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------ȡ����ֵ_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemData_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------�ø���ֵ_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemData_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int Data ) ); \
    \
    /*--------ȡ����ɫ_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------������ɫ_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int FontColor ) ); \
    \
    /*--------ȡ��ֹ����ɫ_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemDisabledFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------�ý�ֹ����ɫ_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemDisabledFontColor_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int DisabledFontColor ) ); \
    \
    /*--------����Ŀ��Ϣ_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemInfo_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Type,int Size ) ); \
    \
    /*--------ȡ��Ŀ��Ϣ_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemInfo_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId , int Type) ); \
    \
    /*--------������_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemType_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int Type ) ); \
    \
    /*--------ȡ����_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemType_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------ȡ��ֹ_�˵�Ex--------*/\
    CMDINFO( BOOL ,  GetItemDisabled_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------�ý�ֹ_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemDisabled_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,BOOL Disabled ) ); \
    \
	/*--------����Ŀ���_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemWidth_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Width ) ); \
    \
    /*--------ȡ��Ŀ���_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemWidth_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
	/*--------����Ŀ�߶�_�˵�Ex--------*/\
    CMDINFO( void ,  SetItemHeight_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId, int Height ) ); \
    \
    /*--------ȡ��Ŀ�߶�_�˵�Ex--------*/\
    CMDINFO( int ,  GetItemHeight_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------ȡ�Ӳ˵�����_�˵�Ex--------*/\
    CMDINFO( int ,  GetSubItemCount_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId ) ); \
    \
    /*--------ȡ�Ӳ˵�_�˵�Ex--------*/\
    CMDINFO( MenuInfo_P_P ,  GetSubItem_MenuEx , ( MenuEx_P control,MenuInfo_P MenuId,int index ) ); \
    \



/*--------------Category5--------------*/

#define 	EX_UI_CMDINFO_Category5(CMDINFO)  \
    /*--------����_�����б�Ex--------*/\
    CMDINFO( DownlistEx_P ,  Create_DownlistEx , ( int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,BOOL AlternateColor,int ScrollBarMode,    int  CurrentSelection,  int Transparency,void * callback,int Tag ) ); \
    \
    /*--------����_�����б�Ex--------*/\
    CMDINFO( void ,  Destroy_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------������_�����б�Ex--------*/\
    CMDINFO( void ,  SetAttribute_DownlistEx , ( DownlistEx_P control,int index,  int IconWidth,int IconHeight,BinEx_P Skin,BinEx_P Font,BinEx_P Cursor,BOOL AlternateColor,int ScrollBarMode,    int  CurrentSelection,  int Transparency,void * callback,int Tag ) ); \
    \
    /*--------ȡ����_�����б�Ex--------*/\
    CMDINFO( int ,  GetAttribute_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------����_�����б�Ex--------*/\
    CMDINFO( void ,  PopUp_DownlistEx , ( DownlistEx_P control,int X,int Y,int nWidth,int nHeight,HWND hWndParent,BOOL Modal ) ); \
    \
    /*--------�ر�_�����б�Ex--------*/\
    CMDINFO( void ,  Close_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------�Ƿ��ѵ���_�����б�Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------����_�����б�Ex--------*/\
    CMDINFO( int ,  InsertItem_DownlistEx , ( DownlistEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------ɾ��_�����б�Ex--------*/\
    CMDINFO( void ,  DeleteItem_DownlistEx , ( DownlistEx_P control,int index,int deletenum ) ); \
    \
    /*--------ȡ����_�����б�Ex--------*/\
    CMDINFO( int ,  GetItemCount_DownlistEx , ( DownlistEx_P control ) ); \
    \
    /*--------�ø���ֵ_�����б�Ex--------*/\
    CMDINFO( void ,  SetItemData_DownlistEx , ( DownlistEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_�����б�Ex--------*/\
    CMDINFO( int ,  GetItemData_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------��ͼ��_�����б�Ex--------*/\
    CMDINFO( void ,  SetItemIco_DownlistEx , ( DownlistEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_�����б�Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------�ñ���_�����б�Ex--------*/\
    CMDINFO( void ,  SetItemTitle_DownlistEx , ( DownlistEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ����_�����б�Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------������ɫ_�����б�Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_DownlistEx , ( DownlistEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_�����б�Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------����Ŀ�߶�_�����б�Ex--------*/\
    CMDINFO( void ,  SetItemSize_DownlistEx , ( DownlistEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ��Ŀ�߶�_�����б�Ex--------*/\
    CMDINFO( int ,  GetItemSize_DownlistEx , ( DownlistEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_�����б�Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_DownlistEx , ( DownlistEx_P control,int index,int mode ) ); \
    \


/*--------------Category6--------------*/

#define 	EX_UI_CMDINFO_Category6(CMDINFO)  \
    /*--------������������--------*/\
    CMDINFO( int ,  CreateSlowMotionTaskEx , ( int Num, int  Mode, int Star, int End, int FrameDelay, int Step, int  Callback, int parameter, BOOL   Wait, BOOL AutoDestroy) ); \
    \
    /*--------�û�����������--------*/\
    CMDINFO( void ,  SetSlowMotionTaskConfigEx , ( int Task_Queue, int  index, int  Mode, int Star, int End) ); \
    \
    /*--------�ȴ���������ִ�����--------*/\
    CMDINFO( int ,  SetSlowMotionTaskProgresEx , ( int Task_Queue, int Progres ) ); \
    \
    /*--------���ٻ�����������--------*/\
    CMDINFO( void ,  DestroySlowMotionTaskEx , (int Task_Queue  ) ); \
    /*--------���Ŵ��ڶ���--------*/\
    CMDINFO(BOOL, PlayWindowAnimationEx , (Control_P control,  int scale, int AnimationType, int AlgorithmMode, int FrameDelay, int Step, BOOL FadeInAndOut, BOOL  Wait, BOOL DestroyControl) ); \
    \
    /*--------�������--------*/\
    CMDINFO(BOOL, LoadControlEx , (Control_P Parent,  HWND  Window, int  mode, int Parameter1, int Parameter2, BinEx_P bin, int   Callback, int  CallbackParameter) ); \
    \
    /*--------�������--------*/\
    CMDINFO(BinEx_P, packControlEx , (Control_P control,   HWND  Window,int  mode, int Parameter1, int Parameter2, int retain, int   Callback, int  CallbackParameter) ); \
	/*--------�����ı�--------*/\
	CMDINFO(BinEx_P  , RexMeasureStringEx,(StrEx_P string, BinEx_P Font, int StringFormat, float x, float y, float width, float height, int mode)); \
	/*--------������ʱ��--------*/\
	CMDINFO( int ,    CreateTimerEx,(int  DueTime, int  Period, int  TimeCallBack, int Parameter, BOOL  Reentry, BOOL wait,int Flags));\
	/*--------���ٶ�ʱ��--------*/\
	CMDINFO(void,   DeleteTimerEx, (int time));\
	/*--------�ö�ʱ������--------*/\
	CMDINFO(void, SetConfigTimerEx, (int 	time, int  DueTime, int  Period));\
	/*--------ȡ��ʱ������--------*/\
	CMDINFO(int,  GetConfigTimerEx, (int  time, int  type));\
	/*--------�쳣����--------*/\
	CMDINFO(void,  ExceptionCaptureEx, (int  callback,int callback2));\
	/*--------��������--------*/\
	CMDINFO(BOOL,  LoadThemeEx, (BinEx_P  Theme, HWND hwnd, int Callback,int Param));\
	/*--------��������--------*/\
	CMDINFO(HWND,  Create_WindowBoxEx, ( int mode, int Location, HWND hWndParent, int X, int Y, int nWidth, int nHeight, int   WndProc, BOOL Visual, BOOL  Disabled,  BinEx_P Icon, StrEx_P Title,	BOOL AlwaysTop,BOOL Taskbar, BOOL EscClose, StrEx_P ClassName, int classstyle, int  dwExStyle, int   dwStyle, int Sign));\
	/*--------�Ƿ��Ѵ���--------*/\
CMDINFO(BOOL, IsWindow_WindowBoxEx, (HWND hwnd)); \
/*--------���ٴ���--------*/\
CMDINFO(void, Destroy_WindowBoxEx, (HWND hwnd)); \
/*--------���������--------*/\
CMDINFO(void, SetLeft_WindowBoxEx, (HWND hwnd, int   Left)); \
/*--------����ȡ���--------*/\
CMDINFO(int, GetLeft_WindowBoxEx, (HWND hwnd)); \
/*--------�����ö���--------*/\
CMDINFO(void, SetTop_WindowBoxEx, (HWND hwnd, int   Top)); \
/*--------����ȡ����--------*/\
CMDINFO(int, GetTop_WindowBoxEx, (HWND hwnd)); \
/*--------�����ÿ��--------*/\
CMDINFO(void, SetWidth_WindowBoxEx, (HWND hwnd, int   Width)); \
/*--------����ȡ���--------*/\
CMDINFO(int, GetWidth_WindowBoxEx, (HWND hwnd)); \
/*--------�����ø߶�--------*/\
CMDINFO(void, SetHeight_WindowBoxEx, (HWND hwnd, int   Height)); \
/*--------����ȡ�߶�--------*/\
CMDINFO(int, GetHeight_WindowBoxEx, (HWND hwnd)); \
/*--------�þ���--------*/\
CMDINFO(void, SetRect_WindowBoxEx, (HWND hwnd, int left, int top, int Width, int Height)); \
/*--------ȡ����--------*/\
CMDINFO(void, GetRect_WindowBoxEx, (HWND hwnd, int  * Left, int  * Top, int   * Width, int  * Height)); \
/*--------��λ��--------*/\
CMDINFO(void, SetLocation_WindowBoxEx, (HWND hwnd, int Location)); \
/*--------ȡλ��--------*/\
CMDINFO(int, GetLocation_WindowBoxEx, (HWND hwnd)); \
/*--------ȡ����--------*/\
CMDINFO(BOOL, GetVisual_WindowBoxEx, (HWND hwnd)); \
/*--------�ÿ���--------*/\
CMDINFO(void, SetVisual_WindowBoxEx, (HWND hwnd, BOOL  Visual)); \
/*--------ȡ��ֹ--------*/\
CMDINFO(BOOL, GetDisabled_WindowBoxEx, (HWND hwnd)); \
/*--------�ý�ֹ--------*/\
CMDINFO(void, SetDisabled_WindowBoxEx, (HWND hwnd, BOOL  Disabled)); \
/*--------�����ñ�ʶ--------*/\
CMDINFO(void, SetSign_WindowBoxEx, (HWND hwnd, int   Sign)); \
/*--------����ȡ��ʶ--------*/\
CMDINFO(int, GetSign_WindowBoxEx, (HWND hwnd)); \
/*--------�ø�����--------*/\
CMDINFO(void, SetParent_WindowBoxEx, (HWND hwnd, HWND  Parent)); \
/*--------ȡ������--------*/\
CMDINFO(HWND, GetParent_WindowBoxEx, (HWND hwnd)); \
/*--------ȡͼ��--------*/\
CMDINFO(BinEx_P, GetIco_WindowBoxEx, (HWND hwnd)); \
/*--------��ͼ��--------*/\
CMDINFO(void, SetIco_WindowBoxEx, (HWND hwnd, BinEx_P  icon)); \
/*--------ȡ����--------*/\
CMDINFO(StrEx_P, GetTitle_WindowBoxEx, (HWND hwnd)); \
/*--------�ñ���--------*/\
CMDINFO(void, SetTitle_WindowBoxEx, (HWND hwnd, StrEx_P  Title)); \
/*--------ȡ��� --------*/\
CMDINFO(int, GetStyle_WindowBoxEx, (HWND hwnd)); \
/*--------�÷��--------*/\
CMDINFO(void, Setstyle_WindowBoxEx, (HWND hwnd, int   style)); \
/*--------ȡ��չ���--------*/\
CMDINFO(BOOL, GetExStyle_WindowBoxEx, (HWND hwnd)); \
/*--------����չ���--------*/\
CMDINFO(void, SetExStyle_WindowBoxEx, (HWND hwnd, int   ExStyle)); \
/*--------����������ʾ--------*/\
CMDINFO(void, SetTaskbar_WindowBoxEx, (HWND hwnd, BOOL show)); \
/*--------ȡ��������ʾ--------*/\
CMDINFO(BOOL, GetTaskbar_WindowBoxEx, (HWND hwnd)); \
/*--------��������ǰ--------*/\
CMDINFO(void, SetAlwaysTop_WindowBoxEx, (HWND hwnd, BOOL AlwaysTop)); \
/*--------ȡ������ǰ--------*/\
CMDINFO(BOOL, GetAlwaysTop_WindowBoxEx, (HWND hwnd)); \
/*--------���˳����ر�--------*/\
CMDINFO( void,SetEscClose_WindowBoxEx,(HWND hwnd, BOOL EscClose)); \
/*--------ȡ�˳����ر�--------*/\
CMDINFO(BOOL,  GetEscClose_WindowBoxEx,(HWND hwnd)); \
/*--------�����ļ��Ϸ�--------*/\
CMDINFO(void, EnableDragDrop_WindowBoxEx, (HWND hwnd)); \
/*--------�ر��ļ��Ϸ�--------*/\
CMDINFO(void, CloseDragDrop_WindowBoxEx, (HWND hwnd)); \
/*--------�ý���--------*/\
CMDINFO(void, SetFocus_WindowBoxEx, (HWND hwnd)); \
/*--------���н���--------*/\
CMDINFO(BOOL, GetFocus_WindowBoxEx, (HWND hwnd)); \
/*--------�������--------*/\
CMDINFO(void, SetLevel_WindowBoxEx, (HWND hwnd, int Level)); \
/*--------������ͼ��--------*/\
CMDINFO(void, SetNotifyIcon_WindowBoxEx, (HWND hwnd, BinEx_P Icon, StrEx_P Tip)); \
/*--------������Ϣ--------*/\
CMDINFO(int, SendMessage_WindowBoxEx, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)); \
/*--------Ͷ����Ϣ--------*/\
CMDINFO(int, PostMessage_WindowBoxEx, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)); \
/*--------��Ϣѭ��--------*/\
CMDINFO(void, MessageLoop_WindowBoxEx, ()); \
/*����*/\
CMDINFO(StructEx_P, Create_StructEx, ()); \
	/*����*/\
	CMDINFO(void,  Destroy_StructEx, ( StructEx_P   Struct ) ); \
	/*���� */\
	CMDINFO(BOOL ,Load_StructEx, ( StructEx_P    Struct, BinEx_P Data) ); \
	/*���*/\
	CMDINFO( BinEx_P, Pack_StructEx, ( StructEx_P    Struct) ); \
	/*���� */\
	CMDINFO(  int ,   InsertMember_StructEx, ( StructEx_P    Struct, int Member, int addnum) ); \
	/*ɾ��  */\
	CMDINFO(  void ,   DeleteMember_StructEx, ( StructEx_P    Struct, int delMember, int deletenum) ); \
	/*ȡ����*/\
	CMDINFO(  int  ,  GetMemberCount_StructEx, ( StructEx_P    Struct) ); \
	/*ȡ����*/\
	CMDINFO(int, GetMemberType_StructEx, (StructEx_P    Struct, int Member)); \
	/*������*/\
	CMDINFO(void, SetMemberName_StructEx, (StructEx_P    Struct, int Member, StrEx_P Name)); \
	/*ȡ����*/\
	CMDINFO(StrEx_P, GetMemberName_StructEx, (StructEx_P    Struct, int Member)); \
	/*���߼�*/\
	CMDINFO(void, SetMemberBool_StructEx, (StructEx_P    Struct, int Member, BOOL  logic)); \
	/*ȡ�߼�*/\
	CMDINFO(BOOL, GetMemberBool_StructEx, (StructEx_P    Struct, int Member)); \
	/*������*/\
	CMDINFO(void, SetMemberInt_StructEx, (StructEx_P    Struct, int Member, int  integer)); \
	/*ȡ����*/\
	CMDINFO(int, GetMemberInt_StructEx, (StructEx_P    Struct, int Member)); \
	/*�ó�����*/\
	CMDINFO(void, SetMemberLongInt_StructEx, (StructEx_P    Struct, int Member, INT64  longinteger)); \
	/*ȡ������*/\
	CMDINFO(INT64, GetMemberLongInt_StructEx, (StructEx_P    Struct, int Member)); \
	/*��С��*/\
	CMDINFO(void, SetMemberFloat_StructEx, (StructEx_P    Struct, int Member, float  decimal)); \
	/*ȡС��*/\
	CMDINFO(float, GetMemberFloat_StructEx, (StructEx_P    Struct, int Member)); \
	/*��˫����С��*/\
	CMDINFO(void, SetMemberDouble_StructEx, (StructEx_P    Struct, int Member, double  DoubleDecimal)); \
	/*ȡ˫����С��*/\
	CMDINFO(double, GetMemberDouble_StructEx, (StructEx_P    Struct, int Member)); \
	/*���ı�*/\
	CMDINFO(void, SetMemberText_StructEx, (StructEx_P    Struct, int Member, StrEx_P Text)); \
	/*ȡ�ı�*/\
	CMDINFO(StrEx_P, GetMemberText_StructEx, (StructEx_P    Struct, int Member)); \
	/*������*/\
	CMDINFO(void, SetMemberBin_StructEx, (StructEx_P    Struct, int Member, BinEx_P Bin)); \
	/*ȡ����*/\
	CMDINFO(BinEx_P, GetMemberBin_StructEx, (StructEx_P    Struct, int Member)); \
	/*�ýṹ��*/\
	CMDINFO(void, SetMemberStruct_StructEx, (StructEx_P    Struct, int Member, StructEx_P    StructInfo)); \
	/*ȡ�ṹ��*/\
	CMDINFO(StructEx_P, GetMemberStruct_StructEx, (StructEx_P  Struct, int Member)); \
	/*���� */\
	CMDINFO(  int ,   InsertAttr_StructEx, ( StructEx_P    Struct, int Attr, int addnum) ); \
	/*ɾ��  */\
	CMDINFO(  void ,   DeleteAttr_StructEx, ( StructEx_P    Struct, int delAttr, int deletenum) ); \
	/*ȡ����*/\
	CMDINFO(  int  ,  GetAttrCount_StructEx, ( StructEx_P    Struct) ); \
	/*ȡ����*/\
	CMDINFO(int, GetAttrType_StructEx, (StructEx_P    Struct, int Attr)); \
	/*������*/\
	CMDINFO(void, SetAttrName_StructEx, (StructEx_P    Struct, int Attr, StrEx_P Name)); \
	/*ȡ����*/\
	CMDINFO(StrEx_P, GetAttrName_StructEx, (StructEx_P    Struct, int Attr)); \
	/*���߼�*/\
	CMDINFO(void, SetAttrBool_StructEx, (StructEx_P    Struct, int Attr, BOOL  logic)); \
	/*ȡ�߼�*/\
	CMDINFO(BOOL, GetAttrBool_StructEx, (StructEx_P    Struct, int Attr)); \
	/*������*/\
	CMDINFO(void, SetAttrInt_StructEx, (StructEx_P    Struct, int Attr, int  integer)); \
	/*ȡ����*/\
	CMDINFO(int, GetAttrInt_StructEx, (StructEx_P    Struct, int Attr)); \
	/*�ó�����*/\
	CMDINFO(void, SetAttrLongInt_StructEx, (StructEx_P    Struct, int Attr, INT64  longinteger)); \
	/*ȡ������*/\
	CMDINFO(INT64, GetAttrLongInt_StructEx, (StructEx_P    Struct, int Attr)); \
	/*��С��*/\
	CMDINFO(void, SetAttrFloat_StructEx, (StructEx_P    Struct, int Attr, float  decimal)); \
	/*ȡС��*/\
	CMDINFO(float, GetAttrFloat_StructEx, (StructEx_P    Struct, int Attr)); \
	/*��˫����С��*/\
	CMDINFO(void, SetAttrDouble_StructEx, (StructEx_P    Struct, int Attr, double  DoubleDecimal)); \
	/*ȡ˫����С��*/\
	CMDINFO(double, GetAttrDouble_StructEx, (StructEx_P    Struct, int Attr)); \
	/*���ı�*/\
	CMDINFO(void, SetAttrText_StructEx, (StructEx_P    Struct, int Attr, StrEx_P Text)); \
	/*ȡ�ı�*/\
	CMDINFO(StrEx_P, GetAttrText_StructEx, (StructEx_P    Struct, int Attr)); \
	/*������*/\
	CMDINFO(void, SetAttrBin_StructEx, (StructEx_P    Struct, int Attr, BinEx_P Bin)); \
	/*ȡ����*/\
	CMDINFO(BinEx_P, GetAttrBin_StructEx, (StructEx_P    Struct, int Attr)); \
	/*�ýṹ��*/\
	CMDINFO(void, SetAttrStruct_StructEx, (StructEx_P    Struct, int Attr, StructEx_P    StructInfo)); \
	/*ȡ�ṹ��*/\
	CMDINFO(StructEx_P, GetAttrStruct_StructEx, (StructEx_P  Struct, int Attr)); \


/*--------------Category7--------------*/

#define 	EX_UI_CMDINFO_Category7(CMDINFO)  \
    /*--------�������_����EX--------*/\
    CMDINFO( Control_P ,  CreateControl_WindowEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Icon,StrEx_P Text,BinEx_P Font,int FontClour,int LayeredTransparency,int DragPositionMode,int DragSizeMode,int MaxMode,BinEx_P ButtonData, int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_����EX--------*/\
    CMDINFO( void ,  SetAttribute_WindowEx , ( WindowEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_����EX--------*/\
    CMDINFO( int ,  GetAttribute_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------�������Ŧ_����EX--------*/\
    CMDINFO( int ,  InsertButton_WindowEx , ( WindowEx_P control,int index,int Data,int Type,BinEx_P skin,BOOL Visual,BOOL Disabled,BOOL Selected ) ); \
    \
    /*--------ɾ��_����EX--------*/\
    CMDINFO( void ,  DeleteButton_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------������_����EX--------*/\
    CMDINFO( void ,  SetButtonType_WindowEx , ( WindowEx_P control,int index,int Type ) ); \
    \
    /*--------ȡ����_����EX--------*/\
    CMDINFO( int ,  GetButtonType_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------�ð�ťƤ��_����EX--------*/\
    CMDINFO( void ,  SetButtonskin_WindowEx , ( WindowEx_P control,int index,BinEx_P skin ) ); \
    \
    /*--------ȡ��ťƤ��_����EX--------*/\
    CMDINFO( BinEx_P ,  GetButtonskin_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------�ÿ���_����EX--------*/\
    CMDINFO( void ,  SetButtonVisual_WindowEx , ( WindowEx_P control,int index,BOOL Show ) ); \
    \
    /*--------ȡ����_����EX--------*/\
    CMDINFO( BOOL ,  GetButtonVisual_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------�ý�ֹ_����EX--------*/\
    CMDINFO( void ,  SetButtonDisabled_WindowEx , ( WindowEx_P control,int index,BOOL Disabled ) ); \
    \
    /*--------ȡ��ֹ_����EX--------*/\
    CMDINFO( BOOL ,  GetButtonDisabled_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------��ѡ��_����EX--------*/\
    CMDINFO( void ,  SetButtonSelected_WindowEx , ( WindowEx_P control,int index,BOOL Selected ) ); \
    \
    /*--------ȡѡ��_����EX--------*/\
    CMDINFO( BOOL ,  GetButtonSelected_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------ȡ����_����EX--------*/\
    CMDINFO( int ,  GetButtonCount_WindowEx , ( WindowEx_P control ) ); \
    \
    /*--------ȡ��ֵ_����EX--------*/\
    CMDINFO( int ,  GetButtonData_WindowEx , ( WindowEx_P control,int index ) ); \
    \
    /*--------����ֵ_����EX--------*/\
    CMDINFO( void ,  SetButtonData_WindowEx , ( WindowEx_P control,int index,int Data ) ); \
    \
    /*--------������_����EX--------*/\
    CMDINFO( BOOL ,  InsertControl_WindowEx , ( WindowEx_P control,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------�Ƴ����_����EX--------*/\
    CMDINFO( BOOL ,  RemoveControl_WindowEx , ( WindowEx_P control,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------���÷����¼�_����EX--------*/\
    CMDINFO( int ,  CallFeedBackEvent_WindowEx , ( WindowEx_P control,int Relevant1,int Relevant2,BOOL Mode ) ); \
    \
    /*--------�������_��ǩEX--------*/\
    CMDINFO( Control_P ,  CreateControl_LabelEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,StrEx_P Text,int Align,int BackColor,BinEx_P Font,int FontClour,int Rotate, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_��ǩEx--------*/\
    CMDINFO( void ,  SetAttribute_LabelEx , ( LabelEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_��ǩEx--------*/\
    CMDINFO( int ,  GetAttribute_LabelEx , ( LabelEx_P control,int index ) ); \
    \
    /*--------�������_�˾�EX--------*/\
    CMDINFO( Control_P ,  CreateControl_FilterEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,int  FilterExMode, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�˾�Ex--------*/\
    CMDINFO( void ,  SetAttribute_FilterEx , ( FilterEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�˾�Ex--------*/\
    CMDINFO( int ,  GetAttribute_FilterEx , ( FilterEx_P control,int index ) ); \
    \
    /*--------�������_��ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_ButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_��ťEx--------*/\
    CMDINFO( void ,  SetAttribute_ButtonEx , ( ButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_��ťEx--------*/\
    CMDINFO( int ,  GetAttribute_ButtonEx , ( ButtonEx_P control,int index ) ); \
    \
    /*--------�������_ͼƬ��ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_ImagebuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_ͼƬ��ťEx--------*/\
    CMDINFO( void ,  SetAttribute_ImagebuttonEx , ( ImagebuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_ͼƬ��ťEx--------*/\
    CMDINFO( int ,  GetAttribute_ImagebuttonEx , ( ImagebuttonEx_P control,int index ) ); \
    \
    /*--------�������_������ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_SuperbuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected,BinEx_P Icon,int IconWidth,int IconHeight,BOOL IconResidence,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_������ťEx--------*/\
    CMDINFO( void ,  SetAttribute_SuperbuttonEx , ( SuperbuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������ťEx--------*/\
    CMDINFO( int ,  GetAttribute_SuperbuttonEx , ( SuperbuttonEx_P control,int index ) ); \
    \
    /*--------�������_ѡ���EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ChoiceboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Selected,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_ѡ���Ex--------*/\
    CMDINFO( void ,  SetAttribute_ChoiceboxEx , ( ChoiceboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_ѡ���Ex--------*/\
    CMDINFO( int ,  GetAttribute_ChoiceboxEx , ( ChoiceboxEx_P control,int index ) ); \
    \
    /*--------�������_��ѡ��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_RadiobuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected,StrEx_P Text,BinEx_P Font,int FontClour ,int	AnimationParam, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_��ѡ��Ex--------*/\
    CMDINFO( void ,  SetAttribute_RadiobuttonEx , ( RadiobuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_��ѡ��Ex--------*/\
    CMDINFO( int ,  GetAttribute_RadiobuttonEx , ( RadiobuttonEx_P control,int index ) ); \
    \
    /*--------�������_�༭��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_EditboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Content,int Align,int InputMode,int MaxInput,StrEx_P PasswordSubstitution,int CursorColor,BinEx_P Font,int FontClour,int SelectedFontColor,int SelectedColor,int LeftReservation,int RightReservation,BOOL Multiline,BOOL Wrapped,int ScrollBarMode,int MenuTableWidth,int MenuTableHeight,BinEx_P MenuFont,int MenuFontClour,int MenuDisabledFontClour,int MenuAttributeTransparency,int MenuLanguage , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�༭��Ex--------*/\
    CMDINFO( void ,  SetAttribute_EditboxEx , ( EditboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�༭��Ex--------*/\
    CMDINFO( int ,  GetAttribute_EditboxEx , ( EditboxEx_P control,int index ) ); \
    \
    /*--------�����ı�_�༭��Ex--------*/\
    CMDINFO( void ,  InsertText_EditboxEx , ( EditboxEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------ɾ���ı�_�༭��Ex--------*/\
    CMDINFO( void ,  DeleteText_EditboxEx , ( EditboxEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------�ù��λ��_�༭��Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_EditboxEx , ( EditboxEx_P control,int index ) ); \
    \
    /*--------ȡ���λ��_�༭��Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_EditboxEx , ( EditboxEx_P control ) ); \
    \
    /*--------��ѡ���ı�����_�༭��Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_EditboxEx , ( EditboxEx_P control,int SelectLeng ) ); \
    \
    /*--------ȡѡ���ı�����_�༭��Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_EditboxEx , ( EditboxEx_P control ) ); \
    \
    /*--------��֤��ʾ�ַ�_�༭��Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_EditboxEx , ( EditboxEx_P control,int index,int mode ) ); \
    \
    /*--------�������_��Ͽ�EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ComboboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,StrEx_P Content,int Align,int InputMode,int MaxInput,StrEx_P PasswordSubstitution,int CursorColor,BinEx_P Font,int FontClour,int SelectedFontColor,int SelectedColor,int LeftReservation,int RightReservation,int MenuTableWidth,int MenuTableHeight,BinEx_P MenuFont,int MenuFontClour,int MenuDisabledFontClour,int MenuAttributeTransparency,int MenuLanguage,int DownListWidth,int DownListMaxHeight,int DownListCurrentSelection,int DownListIconWidth,int DownListIconHeight,BinEx_P DownListFont,BOOL DownListAlternate,int DownListScrollBarMode,int DownListAttributeTransparency,BinEx_P DownListItemData, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetAttribute_ComboboxEx , ( ComboboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetAttribute_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------�����ı�_��Ͽ�Ex--------*/\
    CMDINFO( void ,  InsertText_ComboboxEx , ( ComboboxEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------ɾ���ı�_��Ͽ�Ex--------*/\
    CMDINFO( void ,  DeleteText_ComboboxEx , ( ComboboxEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------�ù��λ��_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------ȡ���λ��_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------��ѡ���ı�����_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_ComboboxEx , ( ComboboxEx_P control,int SelectLeng ) ); \
    \
    /*--------ȡѡ���ı�����_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------��֤��ʾ�ַ�_��Ͽ�Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_ComboboxEx , ( ComboboxEx_P control,int index,int mode ) ); \
    \
    /*--------����_��Ͽ�Ex--------*/\
    CMDINFO( void ,  PopUp_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------�ر�_��Ͽ�Ex--------*/\
    CMDINFO( void ,  Close_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------�Ƿ��ѵ���_��Ͽ�Ex--------*/\
    CMDINFO( BOOL ,  IsPopUp_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------����_��Ͽ�Ex--------*/\
    CMDINFO( int ,  InsertItem_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------ɾ��_��Ͽ�Ex--------*/\
    CMDINFO( void ,  DeleteItem_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int deletenum ) ); \
    \
    /*--------ȡ����_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetItemCount_DownlistEx_ComboboxEx , ( ComboboxEx_P control ) ); \
    \
    /*--------�ø���ֵ_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetItemData_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetItemData_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------��ͼ��_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetItemIco_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_��Ͽ�Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------�ñ���_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetItemTitle_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ����_��Ͽ�Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------������ɫ_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------����Ŀ�߶�_��Ͽ�Ex--------*/\
    CMDINFO( void ,  SetItemSize_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ��Ŀ�߶�_��Ͽ�Ex--------*/\
    CMDINFO( int ,  GetItemSize_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_��Ͽ�Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_DownlistEx_ComboboxEx , ( ComboboxEx_P control,int index,int mode ) ); \
    \
    /*--------�������_�����EX--------*/\
    CMDINFO( Control_P ,  CreateControl_MinutesboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Picture,int IconWidth,int IconHeight,StrEx_P Text,int TextMode,BinEx_P Font,int FontClour , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�����Ex--------*/\
    CMDINFO( void ,  SetAttribute_MinutesboxEx , ( MinutesboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�����Ex--------*/\
    CMDINFO( int ,  GetAttribute_MinutesboxEx , ( MinutesboxEx_P control,int index ) ); \
    \
    /*--------������_�����Ex--------*/\
    CMDINFO( BOOL ,  InsertControl_MinutesboxEx , ( MinutesboxEx_P control,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------�Ƴ����_�����Ex--------*/\
    CMDINFO( BOOL ,  RemoveControl_MinutesboxEx , ( MinutesboxEx_P control,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------�������_�๦�ܰ�ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_MultifunctionButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int ButtonStyles,int PartnerSize,int BackColor,BinEx_P Icon,int IconWidth,int IconHeight,BOOL IconResidence,StrEx_P Text,BinEx_P Font,int FontClour , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�๦�ܰ�ťEX--------*/\
    CMDINFO( void ,  SetAttribute_MultifunctionButtonEx , ( MultifunctionButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�๦�ܰ�ťEX--------*/\
    CMDINFO( int ,  GetAttribute_MultifunctionButtonEx , ( MultifunctionButtonEx_P control,int index ) ); \
    \
    /*--------�������_ͼƬ��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_PictureBoxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BinEx_P Picture,int MapMode,int Rotate,int Angle,BOOL PlayAnimation,int AllFrame,int CurrentFrame, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_ͼƬ��Ex--------*/\
    CMDINFO( void ,  SetAttribute_PictureBoxEx , ( PictureBoxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_ͼƬ��Ex--------*/\
    CMDINFO( int ,  GetAttribute_PictureBoxEx , ( PictureBoxEx_P control,int index ) ); \
    \
    /*--------�������_������EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ProgressbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int MiniPosition,int MaxiPosition,int Style,int Direction , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetAttribute_ProgressbarEx , ( ProgressbarEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetAttribute_ProgressbarEx , ( ProgressbarEx_P control,int index ) ); \
    \
    /*--------�������_������EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ScrollbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int MiniPosition,int MaxiPosition,int PageLength,int RowChangeValue,int PageChangeValue,int ScrollChangeValue,BOOL DragTrace,BOOL schedule , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetAttribute_ScrollbarEx , ( ScrollbarEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetAttribute_ScrollbarEx , ( ScrollbarEx_P control,int index ) ); \
    \
    /*--------�������_������EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SliderbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int Position,int Progress,int MiniPosition,int MaxiPosition,int RowChangeValue,int PageChangeValue,BOOL DragTrace,int Style , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetAttribute_SliderbarEx , ( SliderbarEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetAttribute_SliderbarEx , ( SliderbarEx_P control,int index ) ); \
    \
    /*--------�������_ѡ���EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SelectthefolderEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentTable,int TableSize,int Direction,int Spacing,int TableStyle,int Retain,int IconWidth,int IconHeight,BinEx_P Font,BinEx_P TableData, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_ѡ���Ex--------*/\
    CMDINFO( void ,  SetAttribute_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_ѡ���Ex--------*/\
    CMDINFO( int ,  GetAttribute_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------����_ѡ���Ex--------*/\
    CMDINFO( int ,  InsertTab_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------ɾ��_ѡ���Ex--------*/\
    CMDINFO( void ,  DeleteTab_SelectthefolderEx , ( SelectthefolderEx_P control,int delindex ) ); \
    \
    /*--------ȡ����_ѡ���Ex--------*/\
    CMDINFO( int ,  GetTabCount_SelectthefolderEx , ( SelectthefolderEx_P control ) ); \
    \
    /*--------ȡ������ֵ_ѡ���Ex--------*/\
    CMDINFO( int ,  GetTabData_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------�ù�����ֵ_ѡ���Ex--------*/\
    CMDINFO( void ,  SetTabData_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Data ) ); \
    \
    /*--------��ͼ��_ѡ���Ex--------*/\
    CMDINFO( void ,  SetTabIco_SelectthefolderEx , ( SelectthefolderEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_ѡ���Ex--------*/\
    CMDINFO( ImageEX_P ,  GetTabIco_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------���ı�_ѡ���Ex--------*/\
    CMDINFO( void ,  SetTabTitle_SelectthefolderEx , ( SelectthefolderEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_ѡ���Ex--------*/\
    CMDINFO( StrEx_P ,  GetTabTitle_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------������ɫ_ѡ���Ex--------*/\
    CMDINFO( void ,  SetTabFontColor_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_ѡ���Ex--------*/\
    CMDINFO( int ,  GetTabFontColor_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------�óߴ�_ѡ���Ex--------*/\
    CMDINFO( void ,  SetTabSize_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ�ߴ�_ѡ���Ex--------*/\
    CMDINFO( int ,  GetTabSize_SelectthefolderEx , ( SelectthefolderEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_ѡ���Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_SelectthefolderEx , ( SelectthefolderEx_P control,int index,int DisplayMode ) ); \
    \
    /*--------������_ѡ���Ex--------*/\
    CMDINFO( BOOL ,  InsertControl_SelectthefolderEx , ( SelectthefolderEx_P control,int Table,Control_P ControlHand,int left,int top ) ); \
    \
    /*--------�Ƴ����_ѡ���Ex--------*/\
    CMDINFO( BOOL ,  RemoveControl_SelectthefolderEx , ( SelectthefolderEx_P control,int Table,Control_P ControlHand,Control_P Parentcontrol,int left,int top ) ); \
    \
    /*--------�������_������EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ToolbarEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int BackMode,BOOL schedule,int Spacing,int IconWidth,int IconHeight,BinEx_P Font,BinEx_P ButtonData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetAttribute_ToolbarEx , ( ToolbarEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetAttribute_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------����_������Ex--------*/\
    CMDINFO( int ,  InsertButton_ToolbarEx , ( ToolbarEx_P control,int index,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size,int Type,int Align,BOOL Disabled,BOOL Selected ) ); \
    \
    /*--------ɾ��_������Ex--------*/\
    CMDINFO( void ,  DeleteButton_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetButtonCount_ToolbarEx , ( ToolbarEx_P control ) ); \
    \
    /*--------�ù�����ֵ_������Ex--------*/\
    CMDINFO( void ,  SetButtonData_ToolbarEx , ( ToolbarEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ������ֵ_������Ex--------*/\
    CMDINFO( int ,  GetButtonData_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------��ͼ��_������Ex--------*/\
    CMDINFO( void ,  SetButtonIco_ToolbarEx , ( ToolbarEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_������Ex--------*/\
    CMDINFO( ImageEX_P ,  GetButtonIco_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------���ı�_������Ex--------*/\
    CMDINFO( void ,  SetButtonTitle_ToolbarEx , ( ToolbarEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_������Ex--------*/\
    CMDINFO( StrEx_P ,  GetButtonTitle_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------������ɫ_������Ex--------*/\
    CMDINFO( void ,  SetButtonFontColor_ToolbarEx , ( ToolbarEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_������Ex--------*/\
    CMDINFO( int ,  GetButtonFontColor_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------�óߴ�_������Ex--------*/\
    CMDINFO( void ,  SetButtonSize_ToolbarEx , ( ToolbarEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ�ߴ�_������Ex--------*/\
    CMDINFO( int ,  GetButtonSize_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetButtonType_ToolbarEx , ( ToolbarEx_P control,int index,int Type ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetButtonType_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------�ö��뷽ʽ_������Ex--------*/\
    CMDINFO( void ,  SetButtonAlign_ToolbarEx , ( ToolbarEx_P control,int index,int Align ) ); \
    \
    /*--------ȡ���뷽ʽ_������Ex--------*/\
    CMDINFO( int ,  GetButtonAlign_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------��ѡ��_������Ex--------*/\
    CMDINFO( void ,  SetButtonSelected_ToolbarEx , ( ToolbarEx_P control,int index,BOOL Selected ) ); \
    \
    /*--------ȡѡ��_������Ex--------*/\
    CMDINFO( BOOL ,  GetButtonSelected_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------�ý�ֹ_������Ex--------*/\
    CMDINFO( void ,  SetButtonDisabled_ToolbarEx , ( ToolbarEx_P control,int index,BOOL Disabled ) ); \
    \
    /*--------ȡ��ֹ_������Ex--------*/\
    CMDINFO( BOOL ,  GetButtonDisabled_ToolbarEx , ( ToolbarEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_������Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_ToolbarEx , ( ToolbarEx_P control,int index,int DisplayMode ) ); \
    \
    /*--------�������_�б��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int IconWidth,int IconHeight,BinEx_P Font,BOOL AlternateColor,int ScrollBarMode,BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�б��Ex--------*/\
    CMDINFO( void ,  SetAttribute_ListboxEx , ( ListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�б��Ex--------*/\
    CMDINFO( int ,  GetAttribute_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------����_�б��Ex--------*/\
    CMDINFO( int ,  InsertItem_ListboxEx , ( ListboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Size ) ); \
    \
    /*--------ɾ��_�б��Ex--------*/\
    CMDINFO( void ,  DeleteItem_ListboxEx , ( ListboxEx_P control,int index,int deletenum ) ); \
    \
    /*--------ȡ����_�б��Ex--------*/\
    CMDINFO( int ,  GetItemCount_ListboxEx , ( ListboxEx_P control ) ); \
    \
    /*--------�ø���ֵ_�б��Ex--------*/\
    CMDINFO( void ,  SetItemData_ListboxEx , ( ListboxEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_�б��Ex--------*/\
    CMDINFO( int ,  GetItemData_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------��ͼ��_�б��Ex--------*/\
    CMDINFO( void ,  SetItemIco_ListboxEx , ( ListboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_�б��Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------�ñ���_�б��Ex--------*/\
    CMDINFO( void ,  SetItemTitle_ListboxEx , ( ListboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ����_�б��Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------ȡ����ɫ_�б��Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------������ɫ_�б��Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_ListboxEx , ( ListboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------����Ŀ�߶�_�б��Ex--------*/\
    CMDINFO( void ,  SetItemSize_ListboxEx , ( ListboxEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ��Ŀ�߶�_�б��Ex--------*/\
    CMDINFO( int ,  GetItemSize_ListboxEx , ( ListboxEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_�б��Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_ListboxEx , ( ListboxEx_P control,int index,int mode ) ); \
    \
    /*--------�������_�����б��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_SuperListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int HeadHeight,int HeadMode,BOOL AlternateColor,BOOL EntireLine,int LineMode,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_�����б��Ex--------*/\
    CMDINFO( void ,  SetAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�����б��Ex--------*/\
    CMDINFO( int ,  GetAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------������_�����б��Ex--------*/\
    CMDINFO( int ,  InsertColumn_SuperListboxEx , ( SuperListboxEx_P control,int cloid,int addnum,ImageEX_P Ico,StrEx_P Title,int FontColor,int wight,int min,int max,BinEx_P Font,int IcoW,int IcoH,int Align,BinEx_P ItemFont,int ItemIcoW,int ItemIcoH,int ItemAlign ) ); \
    \
    /*--------ɾ����_�����б��Ex--------*/\
    CMDINFO( void ,  DeleteColumn_SuperListboxEx , ( SuperListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ������_�����б��Ex--------*/\
    CMDINFO( int ,  GetColumnCount_SuperListboxEx , ( SuperListboxEx_P control ) ); \
    \
    /*--------��������_�����б��Ex--------*/\
    CMDINFO( void ,  SetColumnAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int AttributeId, ImageEX_P Ico,StrEx_P Title,int FontColor,int wight,int min,int max,BinEx_P Font,int IcoW,int IcoH,int Align,BinEx_P ItemFont,int ItemIcoW,int ItemIcoH,int ItemAlign ) ); \
    \
    /*--------ȡ������_�����б��Ex--------*/\
    CMDINFO( int ,  GetColumnAttribute_SuperListboxEx , ( SuperListboxEx_P control,int index,int AttributeId ) ); \
    \
    /*--------������Ŀ_�����б��Ex--------*/\
    CMDINFO( int ,  InsertItem_SuperListboxEx , ( SuperListboxEx_P control,int index,int addnum,int Data,int Size ) ); \
    \
    /*--------ɾ����Ŀ_�����б��Ex--------*/\
    CMDINFO( void ,  DeleteItem_SuperListboxEx , ( SuperListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ����_�����б��Ex--------*/\
    CMDINFO( int ,  GetItemCount_SuperListboxEx , ( SuperListboxEx_P control ) ); \
    \
    /*--------�ø���ֵ_�����б��Ex--------*/\
    CMDINFO( void ,  SetItemData_SuperListboxEx , ( SuperListboxEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_�����б��Ex--------*/\
    CMDINFO( int ,  GetItemData_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------��ͼ��_�����б��Ex--------*/\
    CMDINFO( void ,  SetItemIco_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_�����б��Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------���ı�_�����б��Ex--------*/\
    CMDINFO( void ,  SetItemTitle_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_�����б��Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------������ɫ_�����б��Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_�����б��Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_SuperListboxEx , ( SuperListboxEx_P control,int index,int cloid ) ); \
    \
    /*--------����Ŀ�߶�_�����б��Ex--------*/\
    CMDINFO( void ,  SetItemSize_SuperListboxEx , ( SuperListboxEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ��Ŀ�߶�_�����б��Ex--------*/\
    CMDINFO( int ,  GetItemSize_SuperListboxEx , ( SuperListboxEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_�����б��Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_SuperListboxEx , ( SuperListboxEx_P control,int index,int cid,int mode ) ); \
    \
    /*--------�������_ͼ���б��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_IcoListboxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,int TableWidth,int TableHeight,int HSpacing,int LSpacing,int IconWidth,int IconHeight,BinEx_P Font,int PageLayout,BOOL IconResidence,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_ͼ���б��Ex--------*/\
    CMDINFO( void ,  SetAttribute_IcoListboxEx , ( IcoListboxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_ͼ���б��Ex--------*/\
    CMDINFO( int ,  GetAttribute_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------������Ŀ_ͼ���б��Ex--------*/\
    CMDINFO( int ,  InsertItem_IcoListboxEx , ( IcoListboxEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor ) ); \
    \
    /*--------ɾ����Ŀ_ͼ���б��Ex--------*/\
    CMDINFO( void ,  DeleteItem_IcoListboxEx , ( IcoListboxEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ��Ŀ����_ͼ���б��Ex--------*/\
    CMDINFO( int ,  GetItemCount_IcoListboxEx , ( IcoListboxEx_P control ) ); \
    \
    /*--------�ø���ֵ_ͼ���б��Ex--------*/\
    CMDINFO( void ,  SetItemData_IcoListboxEx , ( IcoListboxEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_ͼ���б��Ex--------*/\
    CMDINFO( int ,  GetItemData_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------��ͼ��_ͼ���б��Ex--------*/\
    CMDINFO( void ,  SetItemIco_IcoListboxEx , ( IcoListboxEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_ͼ���б��Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------���ı�_ͼ���б��Ex--------*/\
    CMDINFO( void ,  SetItemTitle_IcoListboxEx , ( IcoListboxEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_ͼ���б��Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------������ɫ_ͼ���б��Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_IcoListboxEx , ( IcoListboxEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_ͼ���б��Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_IcoListboxEx , ( IcoListboxEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_ͼ���б��Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_IcoListboxEx , ( IcoListboxEx_P control,int index,int mode ) ); \
    \
    /*--------�������_�����б��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_TreeListEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,int CurrentSelection,BOOL AutoSize,int FoldBtnWidth,int FoldBtnHeight,int IconWidth,int IconHeight,BinEx_P Font,int ChildMigration,int BackMigration,int ContentMigration,int LineMode,int ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_���ο�Ex--------*/\
    CMDINFO( void ,  SetAttribute_TreeListEx , ( TreeListEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_���ο�Ex--------*/\
    CMDINFO( int ,  GetAttribute_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------����_���ο�Ex--------*/\
    CMDINFO( int ,  InsertItem_TreeListEx , ( TreeListEx_P control,int index,int addnum,int Data,ImageEX_P Ico,StrEx_P Title,int FontColor,int Width,int Size,int ItemType,BOOL SetFold,int InsMode ) ); \
    \
    /*--------ɾ��_���ο�Ex--------*/\
    CMDINFO( void ,  DeleteItem_TreeListEx , ( TreeListEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ����_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemCount_TreeListEx , ( TreeListEx_P control ) ); \
    \
    /*--------�ø���ֵ_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemData_TreeListEx , ( TreeListEx_P control,int index,int Data ) ); \
    \
    /*--------ȡ����ֵ_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemData_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------��ͼ��_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemIco_TreeListEx , ( TreeListEx_P control,int index,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_���ο�Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------���ı�_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemTitle_TreeListEx , ( TreeListEx_P control,int index,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_���ο�Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------������ɫ_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_TreeListEx , ( TreeListEx_P control,int index,int FontColor ) ); \
    \
    /*--------ȡ����ɫ_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------����Ŀ���_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemWidth_TreeListEx , ( TreeListEx_P control,int index,int Width ) ); \
    \
    /*--------ȡ��Ŀ���_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemWidth_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------����Ŀ�߶�_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemSize_TreeListEx , ( TreeListEx_P control,int index,int Size ) ); \
    \
    /*--------ȡ��Ŀ�߶�_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemSize_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------����Ŀ���_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemType_TreeListEx , ( TreeListEx_P control,int index,int style ) ); \
    \
    /*--------ȡ��Ŀ���_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemType_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------���۵�״̬_���ο�Ex--------*/\
    CMDINFO( void ,  SetItemFold_TreeListEx , ( TreeListEx_P control,int index,BOOL Fold ) ); \
    \
    /*--------ȡ�۵�״̬_���ο�Ex--------*/\
    CMDINFO( BOOL ,  GetItemFold_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ�������_���ο�Ex--------*/\
    CMDINFO( int ,  GetItemLevel_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ����Ŀ��_���ο�Ex--------*/\
    CMDINFO( int ,  GetSubItemCount_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ��һ������Ŀ��_���ο�Ex--------*/\
    CMDINFO( int ,  GetNextSubItemCount_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ������Ŀ_���ο�Ex--------*/\
    CMDINFO( int ,  GetAncestorItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ����Ŀ_���ο�Ex--------*/\
    CMDINFO( int ,  GetFatherItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ��һͬ����Ŀ_���ο�Ex--------*/\
    CMDINFO( int ,  GetLastItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------ȡ��һͬ����Ŀ_���ο�Ex--------*/\
    CMDINFO( int ,  GetNextItem_TreeListEx , ( TreeListEx_P control,int index ) ); \
    \
    /*--------��֤��ʾ_���ο�Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_TreeListEx , ( TreeListEx_P control,int index,int mode ) ); \
    \
    /*--------�������_�����EX--------*/\
    CMDINFO( Control_P ,  CreateControl_WebBrowserEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BOOL BackgroundTransparent,int MediaVolume,int ZoomFactor,BOOL NavigationToNewWind,BOOL CookieEnabled,BOOL NpapiEnabled,BOOL MenuEnabled,int DragEnable,StrEx_P StartPage,StrEx_P UserAgent,int Version, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_�����Ex--------*/\
    CMDINFO( void ,  SetAttribute_WebBrowserEx , ( WebBrowserEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�����Ex--------*/\
    CMDINFO( int ,  GetAttribute_WebBrowserEx , ( WebBrowserEx_P control,int index ) ); \
    \
    /*--------ȡ�ں˾��_�����Ex--------*/\
    CMDINFO( int ,  GetWebView_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------����_�����Ex--------*/\
    CMDINFO( void ,  Load_WebBrowserEx , ( WebBrowserEx_P control,StrEx_P url,StrEx_P baseUrl,int Loadmode ) ); \
    \
    /*--------����_�����Ex--------*/\
    CMDINFO( BOOL ,  GoBack_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------ǰ��_�����Ex--------*/\
    CMDINFO( BOOL ,  GoForward_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------�ɷ����_�����Ex--------*/\
    CMDINFO( BOOL ,  GoCanBack_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------�ɷ�ǰ��_�����Ex--------*/\
    CMDINFO( BOOL ,  GoCanForward_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------����_�����Ex--------*/\
    CMDINFO( void ,  ReLoad_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------ֹͣ_�����Ex--------*/\
    CMDINFO( void ,  StopLoading_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------ȡ��ַ_�����Ex--------*/\
    CMDINFO( StrEx_P ,  GetUrl_WebBrowserEx , ( WebBrowserEx_P control,int frameId ) ); \
    \
    /*--------ȡ����_�����Ex--------*/\
    CMDINFO( StrEx_P ,  GetTitle_WebBrowserEx , ( WebBrowserEx_P control,int frameId ) ); \
    \
    /*--------ȡԴ��_�����Ex--------*/\
	 \
	 CMDINFO( StrEx_P ,  GetSource_WebBrowserEx , ( WebBrowserEx_P control ) ); \
	\
	 /*--------ִ������_�����Ex--------*/\
    CMDINFO( int ,  RunCmd_WebBrowserEx , ( WebBrowserEx_P control,int  Cmd, int  Parameter1, int Parameter2, int Parameter3, int  Parameter4) ); \
    \
	 /*--------ȡcookie_�����Ex--------*/\
    CMDINFO( StrEx_P ,  GetCookie_WebBrowserEx , ( WebBrowserEx_P control) ); \
    \
	 /*--------��cookie_�����Ex--------*/\
    CMDINFO( void ,  SetCookie_WebBrowserEx , ( WebBrowserEx_P control,  StrEx_P   url, StrEx_P cookie ) ); \
    \
	 /*--------ִ��js_�����Ex--------*/\
    CMDINFO( StrEx_P ,  RunJS_WebBrowserEx , ( WebBrowserEx_P control,  StrEx_P JavaScript, int frameId, BOOL isInClosure ) ); \
    \
	 /*--------��js_�����Ex--------*/\
	CMDINFO( void ,  BindFunction_WebBrowserEx , ( WebBrowserEx_P control, StrEx_P jscmd, void * mycmd, int argcount,int mode) ); \
    \
    /*--------�����ڼ���_�����Ex--------*/\
    CMDINFO( BOOL ,  IsLoading_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------�Ƿ�����ʧ��_�����Ex--------*/\
    CMDINFO( BOOL ,  IsLoadingSucceeded_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------�Ƿ��������_�����Ex--------*/\
    CMDINFO( BOOL ,  IsLoadingCompleted_WebBrowserEx , ( WebBrowserEx_P control ) ); \
    \
    /*--------�Ƿ�������_�����Ex--------*/\
    CMDINFO( BOOL ,  IsDocumentReady_WebBrowserEx , ( WebBrowserEx_P control ) ); \
	 \
	/*--------���ÿ����߹���_�����Ex--------*/\
    CMDINFO( void ,  ShowDevtools_WebBrowserEx , ( WebBrowserEx_P control , StrEx_P  path ) ); \
	\
	/*--------�������_������EX--------*/\
    CMDINFO( Control_P ,  CreateControl_CalendarBoxEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag, BinEx_P Skin, StrEx_P  MiniDate, StrEx_P  MaxDate,StrEx_P  SelectionDate,BinEx_P  TitleFont, BinEx_P  WeekFont, BinEx_P DayFont, BinEx_P TimeFont, int  TitleClour, int  WeekClour, int  WeekendWeekClour, int  DayClour, int  WeekendClour, int  OtherMonthClour, int  TimeFontClour, BOOL  OnlyThisMonth, int TimeMode, int  TitleHeight, int  WeekHeight, int  TimeRegulatorHeight, int  PartnerHeight, int  Language , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������Ex--------*/\
    CMDINFO( void ,  SetAttribute_CalendarBoxEx , ( CalendarBoxEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������Ex--------*/\
    CMDINFO( int ,  GetAttribute_CalendarBoxEx , ( CalendarBoxEx_P control,int index ) ); \
    \
    /*--------�������_ѡɫ��EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ColorPickEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P   Skin, BinEx_P  Font, int  FontClour, int  NowClour, BOOL  DragTrace, int ClourMode, BinEx_P QuickClours, int  Style, int RegulatorHeight, int QuickClourSize, int  PartnerHeigh , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_ѡɫ��EX--------*/\
    CMDINFO( void ,  SetAttribute_ColorPickEx , ( ColorPickEx_P control,int index,int attribute ) ); \
     \
    /*--------ȡ����_ѡɫ��EX--------*/\
    CMDINFO( int ,  GetAttribute_ColorPickEx , ( ColorPickEx_P control,int index ) ); \
    \
    /*--------�������_���ı���EX--------*/\
    CMDINFO( Control_P ,  CreateControl_RichEditEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin, StrEx_P  Content, int  Type, BOOL BackTransparent, int BackClour,int CursorColor, BinEx_P	DefaultCharFormat, BinEx_P  DefaultParaFormat, int  InputMode, int  MaxInput, StrEx_P  PasswordSubstitution, BOOL  Multiline, BOOL  Wrapped, int  ScrollBarMode, int  MenuTableWidth, int  MenuTableHeight, BinEx_P  MenuFont, int  MenuFontClour, int  MenuDisabledFontClour, int  MenuTransparency, int  MenuLanguage, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_���ı���EX--------*/\
    CMDINFO( void ,  SetAttribute_RichEditEx , ( RichEditEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_���ı���EX--------*/\
    CMDINFO( int ,  GetAttribute_RichEditEx , ( RichEditEx_P control,int index ) ); \
	/*--------�����ı�_�༭��Ex--------*/\
    CMDINFO( void ,  InsertText_RichEditEx , ( RichEditEx_P control,int weizhi,StrEx_P text ) ); \
    \
    /*--------ɾ���ı�_�༭��Ex--------*/\
    CMDINFO( void ,  DeleteText_RichEditEx , ( RichEditEx_P control,int weizhi,int dellen ) ); \
    \
    /*--------�ù��λ��_�༭��Ex--------*/\
    CMDINFO( void ,  SetInsertCursor_RichEditEx , ( RichEditEx_P control,int index ) ); \
    \
    /*--------ȡ���λ��_�༭��Ex--------*/\
    CMDINFO( int ,  GetInsertCursor_RichEditEx , ( RichEditEx_P control ) ); \
    \
    /*--------��ѡ���ı�����_�༭��Ex--------*/\
    CMDINFO( void ,  SetSelectLeng_RichEditEx , ( RichEditEx_P control,int SelectLeng ) ); \
    \
    /*--------ȡѡ���ı�����_�༭��Ex--------*/\
    CMDINFO( int ,  GetSelectLeng_RichEditEx , ( RichEditEx_P control ) ); \
    \
    /*--------��֤��ʾ�ַ�_�༭��Ex--------*/\
    CMDINFO( void ,  GuaranteeVisibleText_RichEditEx , ( RichEditEx_P control,int index,int mode ) ); \
   \
   /*--------��ѡ�����ַ���ʽ--------*/\
    CMDINFO(BOOL , SetSelCharFormat_RichEditEx,(RichEditEx_P control, BinEx_P  CharFormat) ); \
    \
   /*--------ȡѡ�����ַ���ʽ--------*/\
	CMDINFO(BinEx_P , GetSelCharFormat_RichEditEx,(RichEditEx_P control) ); \
    \
   /*--------��ѡ�������䷽ʽ--------*/\
	CMDINFO(BOOL  , SetSelParaFormat_RichEditEx,(RichEditEx_P control, BinEx_P  CharFormat) ); \
    \
   /*--------ȡѡ�������䷽ʽ--------*/\
	CMDINFO(BinEx_P , GetSelParaFormat_RichEditEx,(RichEditEx_P control) ); \
    \
   /*--------ִ�нӿ�����--------*/\
	CMDINFO(int  , RunServicesCmd_RichEditEx,(RichEditEx_P control, int msg, int wparam, int lparam, int  plresult) ); \
    \
  /*--------�������_��չ���EX--------*/\
    CMDINFO( Control_P ,  CreateControl_ExtendEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P AttrEx, BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_��չ���Ex--------*/\
    CMDINFO( void ,  SetAttribute_ExtendEx , ( ExtendEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_��չ���Ex--------*/\
    CMDINFO( int ,  GetAttribute_ExtendEx , ( ExtendEx_P control,int index ) ); \
    \
	/*--------���ÿ����߹���_��չ���Ex--------*/\
    CMDINFO( int ,  ShowDevtools_ExtendEx , ( ExtendEx_P control,  StrEx_P  ToolsPath ) ); \
    \
    /*--------ִ����չ����_��չ���Ex--------*/\
    CMDINFO( StrEx_P ,  RunExtendCmd_ExtendEx , ( ExtendEx_P control, StrEx_P  JavaScript) ); \
	\
    /*--------�������_������ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_AnimationbuttonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL  Selected, StrEx_P  Icon, int  IconWidth, int  IconHeight, BOOL  IconResidence,StrEx_P  Text, StrEx_P  Font, int  FontClour, BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_������ťEX--------*/\
    CMDINFO( void ,  SetAttribute_AnimationbuttonEx , ( AnimationbuttonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������ťEX--------*/\
    CMDINFO( int ,  GetAttribute_AnimationbuttonEx , ( AnimationbuttonEx_P control,int index ) ); \
    \
    /*--------�������_�߼����EX--------*/\
    CMDINFO( Control_P ,  CreateControl_AdvancedFormEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin, int  CurrentSelection, int  CurrentSelectionColumn, int HeaderRowNum, int HeaderColumnNum, int	BottomFixedRow, int RightFixedColumn, int  AdjustmentMode, BOOL  AutoSelect, BOOL  EntireLine, int  LineMode, int  ScrollBarMode, BinEx_P ItemData , BinEx_P ElemeData,BinEx_P Layout) ); \
    \
    /*--------������_�߼����Ex--------*/\
    CMDINFO( void ,  SetAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_�߼����Ex--------*/\
    CMDINFO( int ,  GetAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------������_�߼����Ex--------*/\
    CMDINFO( int ,  InsertColumn_AdvancedFormEx , (AdvancedFormEx_P    control, int  cloid, int addnum, int wight, int min, int max, BinEx_P  ItemFont, int ItemIcoW, int ItemIcoH, int ItemAlign) ); \
    \
    /*--------ɾ����_�߼����Ex--------*/\
    CMDINFO( void ,  DeleteColumn_AdvancedFormEx , ( AdvancedFormEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ������_�߼����Ex--------*/\
    CMDINFO( int ,  GetColumnCount_AdvancedFormEx , ( AdvancedFormEx_P control ) ); \
    \
    /*--------��������_�߼����Ex--------*/\
    CMDINFO( void ,  SetColumnAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int Endindex,int AttributeId,int wight, int min, int max, BinEx_P  ItemFont, int ItemIcoW, int ItemIcoH, int ItemAlign ) ); \
    \
    /*--------ȡ������_�߼����Ex--------*/\
    CMDINFO( int ,  GetColumnAttribute_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int AttributeId ) ); \
    \
    /*--------������Ŀ_�߼����Ex--------*/\
    CMDINFO( int ,  InsertItem_AdvancedFormEx , ( AdvancedFormEx_P control,int index, int  addnum, int  Data, int Height,int MinHeight, int MaxHeight ) ); \
    \
    /*--------ɾ����Ŀ_�߼����Ex--------*/\
    CMDINFO( void ,  DeleteItem_AdvancedFormEx , ( AdvancedFormEx_P control,int delindex,int deletenum ) ); \
    \
    /*--------ȡ����_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemCount_AdvancedFormEx , ( AdvancedFormEx_P control ) ); \
    \
    /*--------�ø���ֵ_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemData_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Data ) ); \
    \
    /*--------ȡ����ֵ_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemData_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------��ͼ��_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemIco_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn,ImageEX_P Ico ) ); \
    \
    /*--------ȡͼ��_�߼����Ex--------*/\
    CMDINFO( ImageEX_P ,  GetItemIco_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------���ı�_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemTitle_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn,StrEx_P Title ) ); \
    \
    /*--------ȡ�ı�_�߼����Ex--------*/\
    CMDINFO( StrEx_P ,  GetItemTitle_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------������ɫ_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemFontColor_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int EndRow, int EndColumn, int  FontColor ) ); \
    \
    /*--------ȡ����ɫ_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemFontColor_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cloid ) ); \
    \
    /*--------����Ŀ�߶�_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------ȡ��Ŀ�߶�_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------����Ŀ���߶�_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemMaxHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------ȡ��Ŀ���߶�_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemMaxHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------����Ŀ��С�߶�_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemMinHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int EndRow,int Height ) ); \
    \
    /*--------ȡ��Ŀ��С�߶�_�߼����Ex--------*/\
    CMDINFO( int ,  GetItemMinHeight_AdvancedFormEx , ( AdvancedFormEx_P control,int index ) ); \
    \
    /*--------�ϲ���Ԫ��_�߼����Ex--------*/\
    CMDINFO( void ,  MergeCell_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn ) ); \
    \
    /*--------�ֽⵥԪ��_�߼����Ex--------*/\
    CMDINFO( void ,  BreakCell_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn) ); \
    \
    /*--------ȡ��Ԫ��ϲ���Ϣ_�߼����Ex--------*/\
    CMDINFO( int ,  GetMergeInfo_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int Type) ); \
    \
    /*--------�ñ�������_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemColorScheme_AdvancedFormEx , ( AdvancedFormEx_P control, int StarRow, int StarColumn, int EndRow, int EndColumn, BinEx_P  ColorScheme ) ); \
    \
    /*--------ȡ��������_�߼����Ex--------*/\
    CMDINFO( BinEx_P ,  GetItemColorScheme_AdvancedFormEx , ( AdvancedFormEx_P control, int index, int  cloid) ); \
    \
    /*--------��ѡ��״̬_�߼����Ex--------*/\
    CMDINFO( void ,  SetItemSelect_AdvancedFormEx , ( AdvancedFormEx_P control,int StarRow, int StarColumn, int EndRow, int EndColumn, BOOL Select ) ); \
    \
	/*--------ȡѡ��״̬_�߼����Ex--------*/\
    CMDINFO( BOOL ,  GetItemSelect_AdvancedFormEx , ( AdvancedFormEx_P control, int index, int  cloid) ); \
    \
    /*--------��֤��ʾ_�߼����Ex--------*/\
    CMDINFO( void ,  GuaranteeVisible_AdvancedFormEx , ( AdvancedFormEx_P control,int index,int cid,int mode ) ); \
    \
    /*--------�������_������ťEX--------*/\
    CMDINFO( Control_P ,  CreateControl_SlideButtonEx , ( Control_P Parent,HWND Window,int LEFT,int Top,int Width,int Height,void * Callback,int * InitAttr,BOOL Visual,BOOL Disabled,int Transparency,int Pierced,int FocusWeight,BinEx_P Cursor,int Tag,BinEx_P Skin,BOOL Selected , BinEx_P ElemeData,BinEx_P Layout ) ); \
    \
    /*--------������_������ťEx--------*/\
    CMDINFO( void ,  SetAttribute_SlideButtonEx , ( SlideButtonEx_P control,int index,int attribute ) ); \
    \
    /*--------ȡ����_������ťEx--------*/\
    CMDINFO( int ,  GetAttribute_SlideButtonEx , ( SlideButtonEx_P control,int index ) ); \
    \
    /*--------�������_����ͼEx--------*/\
    CMDINFO( int ,  CreateControl_PieChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Pierced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain,  int hotGraph, int  GraphStar, int GraphWidth, BOOL Zoom, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------������_����ͼEx--------*/\
    CMDINFO( void ,  SetAttribute_PieChartEx , ( PieChartEx_P control,int index , int  attribute) ); \
    /*--------ȡ����_����ͼEx--------*/\
    CMDINFO( int ,  GetAttribute_PieChartEx , ( PieChartEx_P control,int index ) ); \
    /*--------��ͼ������_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphCount_PieChartEx , ( PieChartEx_P control,int Count) ); \
    /*--------ȡͼ������_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphCount_PieChartEx , ( PieChartEx_P control) ); \
    /*--------��ͼ������_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphAttr_PieChartEx , ( PieChartEx_P control,int index, int AttrId, int  color ) );\
	/*--------ȡͼ������_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphAttr_PieChartEx , ( PieChartEx_P control,int index, int AttrId ) );  \
    /*--------��ͼ��ֵ_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphValue_PieChartEx , ( PieChartEx_P control,int index, int  Value ) ); \
    /*--------ȡͼ��ֵ_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphValue_PieChartEx , ( PieChartEx_P control,int index ) ); \
    /*--------�������_��״ͼEx--------*/\
    CMDINFO( int ,  CreateControl_BarChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Barrced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA, int GridStyleV, int GridColorV,BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, int GraphWidth, int GraphSpace, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------������_��״ͼEx--------*/\
    CMDINFO( void ,  SetAttribute_BarChartEx , ( BarChartEx_P control,int index , int  attribute) ); \
    /*--------ȡ����_��״ͼEx--------*/\
    CMDINFO( int ,  GetAttribute_BarChartEx , ( BarChartEx_P control,int index ) ); \
    /*--------��ͼ������_��״ͼEx--------*/\
    CMDINFO( void ,  SetGraphCount_BarChartEx , ( BarChartEx_P control,int Count) ); \
    /*--------ȡͼ������_��״ͼEx--------*/\
    CMDINFO( int ,  GetGraphCount_BarChartEx , ( BarChartEx_P control) ); \
    /*--------��ͼ������_��״ͼEx--------*/\
    CMDINFO( void ,  SetGraphAttr_BarChartEx , ( BarChartEx_P control,int index, int  Attr, int  Colour, int Rgn) );\
	/*--------ȡͼ������_��״ͼEx--------*/\
    CMDINFO( int ,  GetGraphAttr_BarChartEx , ( BarChartEx_P control,int index, int  Attr ) );  \
    /*--------��ͼ��ֵ_��״ͼEx--------*/\
    CMDINFO( void ,  SetGraphValue_BarChartEx , ( BarChartEx_P control,int index, int  Cid, int  Value ) ); \
    /*--------ȡͼ��ֵ_��״ͼEx--------*/\
    CMDINFO( int ,  GetGraphValue_BarChartEx , ( BarChartEx_P control,int index , int  Cid) ); \
    /*--------�������_����ͼEx--------*/\
    CMDINFO( int ,  CreateControl_CurveChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Curverced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin,  int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA,int GridStyleV, int GridColorV, BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------������_����ͼEx--------*/\
    CMDINFO( void ,  SetAttribute_CurveChartEx , ( CurveChartEx_P control,int index , int  attribute) ); \
    /*--------ȡ����_����ͼEx--------*/\
    CMDINFO( int ,  GetAttribute_CurveChartEx , ( CurveChartEx_P control,int index ) ); \
    /*--------��ͼ������_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphCount_CurveChartEx , ( CurveChartEx_P control,int Count) ); \
    /*--------ȡͼ������_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphCount_CurveChartEx , ( CurveChartEx_P control) ); \
    /*--------��ͼ������_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphAttr_CurveChartEx , ( CurveChartEx_P control,int index, int  Attr,  int Colour, int Tension, int  width, int style, int  PointSize, int HotPointSize) );\
	/*--------ȡͼ������_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphAttr_CurveChartEx , ( CurveChartEx_P control,int index , int  Attr) );  \
    /*--------��ͼ��ֵ_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphValue_CurveChartEx , ( CurveChartEx_P control,int index, int  Cid, int  Value ) ); \
    /*--------ȡͼ��ֵ_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphValue_CurveChartEx , ( CurveChartEx_P control,int index , int  Cid) ); \
    /*--------�������_����ͼEx--------*/\
    CMDINFO( int ,  CreateControl_CandleChartEx , ( Control_P  Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Curverced, int  FocusWeight, BinEx_P Cursor, int  Tag, BinEx_P  Skin, int ChartStyle,  StrEx_P TemplateH, int  ColorHA, int GridStyleH, int GridColorH, BinEx_P FontH, int FontColorH, StrEx_P TemplateV, int  MiniV, int  MaxV,  int  ColorVA,int GridStyleV, int GridColorV,BinEx_P FontV, int FontColorV, int  Leftretain, int  Topretain, int  Rightretain, int	bottomretain, int hotcolumn, int GraphWidth, BOOL NegativeHollow, int NegativeColor, BOOL PositiveHollow, int PositiveColor, BinEx_P ItemData, BinEx_P  ElemeData,BinEx_P Layout) );   \
    /*--------������_����ͼEx--------*/\
    CMDINFO( void ,  SetAttribute_CandleChartEx , ( CandleChartEx_P control,int index , int  attribute) ); \
    /*--------ȡ����_����ͼEx--------*/\
    CMDINFO( int ,  GetAttribute_CandleChartEx , ( CandleChartEx_P control,int index ) ); \
    /*--------��ͼ��ֵ_����ͼEx--------*/\
    CMDINFO( void ,  SetGraphValue_CandleChartEx , ( CandleChartEx_P control,int index,  int DataId, int  openVal, int closeVal, int lowVal, int heighVal) ); \
    /*--------ȡͼ��ֵ_����ͼEx--------*/\
    CMDINFO( int ,  GetGraphValue_CandleChartEx , ( CandleChartEx_P control,int index,  int DataId ) ); \
/*--------�������_����EX--------*/\
CMDINFO( 	Control  * ,   CreateControl_DrawPanelEx ,(Control_P Parent, HWND Window, int LEFT, int  Top, int  Width, int  Height, void *    Callback, int *  InitAttr, BOOL Visual, BOOL Disabled, int  Transparency, int Pierced, int  FocusWeight, StrEx_P Cursor, int  Tag,int BackColor,int LineColor,  StrEx_P ElemeData, StrEx_P Layout ) ); \
/*--------������_����EX--------*/\
CMDINFO(void	 ,  	SetAttribute_DrawPanelEx , (DrawPanelEx_P   control, int   index, int  attribute ) ); \
/*--------ȡ����_����EX--------*/\
CMDINFO(int		 ,  GetAttribute_DrawPanelEx , (DrawPanelEx_P   control, int   index ) ); \
/*--------��ͼƬ_����EX--------*/\
CMDINFO(void ,  DrawImage_DrawPanelEx , (DrawPanelEx_P   control, ImageEX_P Image, float dstX, float dstY, float dstWidth, float dstHeight, float srcx, float srcy, float srcwidth, float srcheight, int Alpha ) ); \
/*--------���ı�_����EX--------*/\
CMDINFO(void  ,  DrawString_DrawPanelEx , (DrawPanelEx_P   control, StrEx_P string, float dstX, float dstY, float dstWidth, float dstHeight, BinEx_P font, int StringFormat, int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------��·��_����EX--------*/\
CMDINFO(void  ,  DrawPath_DrawPathEx , (DrawPanelEx_P   control, int Path, int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------�������_����EX--------*/\
CMDINFO(void  ,  DrawPolygon_DrawPanelEx , (DrawPanelEx_P   control, float * Points, int count,  int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------������_����EX--------*/\
CMDINFO(void  ,  DrawRect_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height,  int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------����Բ_����EX--------*/\
CMDINFO(void  ,  DrawEllipse_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height,  float Rgn, int DrawMode, int  DrawParame, int color, int  auxcolor ) ); \
/*--------����_����EX--------*/\
CMDINFO(void  ,  DrawPie_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, float starAngle, float sweepAngle, int DrawMode, int  DrawParame, int color, int  auxcolor ) ); \
/*--------������_����EX--------*/\
CMDINFO(void  ,  DrawCurve_DrawPanelEx , (DrawPanelEx_P   control, float * Points, int count, float tension, int linemode , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------������_����EX--------*/\
CMDINFO(void  ,  DrawArc_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, float starAngle, float sweepAngle , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------��ֱ��_����EX--------*/\
CMDINFO(void  ,  DrawLine_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height , int DrawMode, int  DrawParame, int color, int  auxcolor) ); \
/*--------���_����EX--------*/\
CMDINFO(void  ,  Clear_DrawPanelEx , (DrawPanelEx_P   control, int colour, float X, float Y, float Width, float Height, BOOL mode  ) ); \
/*--------����_����EX--------*/\
CMDINFO(void ,   Update_DrawPanelEx , (DrawPanelEx_P   control, float X, float Y, float Width, float Height, BOOL mode ) ); \
/*--------�ü�����_����EX--------*/\
CMDINFO(void ,   SetClip_DrawPanelEx , (DrawPanelEx_P  control,int CombineMd,int cliptype,int  Clip ,float X, float Y, float Width, float Height, float Rgn ) ); \
/*--------�û�ͼ����_����EX--------*/\
CMDINFO(void ,   SetGraphicsquality_DrawPanelEx , (DrawPanelEx_P   control,int Smoothing, int Interpolation, int PixelOffset) ); \
/*--------ȡ��ͼ����_����EX--------*/\
CMDINFO(int ,   GetGraphicsData_DrawPanelEx , (DrawPanelEx_P   control,int Type, float X, float Y, float Width, float Height) ); \



/*------------------------------------------EXUI�ӿڽ���------------------------------------------*/



/*------------------------------------------���´��������ע-----------------------------------------*/
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


//װ���л��� �����л�������

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
/*-------------������ʧ�����ExuiKrnln.dll�ļ�����---------------*/ \
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


/*if (exuihDllInst == NULL) { return NULL; / * MessageBoxA(((HWND)0), "����ȱ�ٽ������п���������� ExuiKrnln.dll �ļ�", "Warning", 0);  return NULL;* / }*/\
















