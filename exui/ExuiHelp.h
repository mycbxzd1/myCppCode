#pragma once
#include "ExuiApi.h"
#include <windows.h>
#include"file2mem.h"

StrEx_P stp(LPCWSTR  estr);
LPCWSTR pts(StrEx_P  estr);
LPVOID 申请内存块(INT len);
字节集 生成字体Ex(LPCWSTR 字体名称, INT 字体大小, int 字体风格, int 绘画模式, int 渲染参数, int 渲染参数1, int 渲染参数2);
INT 组件居中取左(int 父组件宽度, INT 组件宽度);
BinEx_P dtp(字节集  ebin);
//CVolMem ptd(BinEx_P  ebin);



ImageEX_P atimage(int  ebin);

//ImageEX_P atimage(CVolMem  ebin);
BinEx_P rtp(int  rid);
BinEx_P dtpdv(字节集  ebin, int rid);


BOOL RETURN_BOOL(int p);
int RETURN_INT(int p);
//CVolString RETURN_CVolString(int p);
//CVolMem RETURN_CVolMem(int p);


#define  ControlType_WindowBoxEx  100
#define  ControlType_MenuEx  800
#define  ControlType_DownlistEx  900
#define  ControlType_WindowEx  1000
#define  ControlType_FilterEx  1100
#define  ControlType_MinutesboxEx  1200
#define  ControlType_SelectthefolderEx  1300
#define  ControlType_PictureBoxEx  1400
#define  ControlType_LabelEx  1500
#define  ControlType_ButtonEx  1600
#define  ControlType_ImagebuttonEx  1700
#define  ControlType_SuperbuttonEx  1800
#define  ControlType_MultifunctionButtonEx  1900
#define  ControlType_RadiobuttonEx  2000
#define  ControlType_ChoiceboxEx  2100
#define  ControlType_ProgressbarEx  2200
#define  ControlType_SliderbarEx  2300
#define  ControlType_ScrollbarEx  2400
#define  ControlType_EditboxEx  2500
#define  ControlType_ComboboxEx  2600
#define  ControlType_ToolbarEx  2700
#define  ControlType_ListboxEx  2800
#define  ControlType_IcoListboxEx  2900
#define  ControlType_SuperListboxEx  3000
#define  ControlType_TreeListEx  3100
#define  ControlType_WebBrowserEx  3200
#define  ControlType_CalendarBoxEx  3300
#define  ControlType_ColorPickEx  3400
#define  ControlType_RichEditEx  3500
#define  ControlType_ExtendEx  3600
#define  ControlType_AnimationbuttonEx  3700
#define  ControlType_AdvancedFormEx  3800
#define  ControlType_SlideButtonEx  3900
#define  ControlType_PieChartEx  4000
#define  ControlType_BarChartEx  4100
#define  ControlType_CurveChartEx  4200
#define  ControlType_CandleChartEx  4300
#define  ControlType_DrawPanelEx  4400
#define  WindowEx_Attr_Layout_Attr_Visual  0
#define  WindowEx_Attr_Layout_Attr_Disabled  1
#define  WindowEx_Attr_Layout_Attr_Transparency  2
#define  WindowEx_Attr_Layout_Attr_Pierced  3
#define  WindowEx_Attr_Layout_Attr_FocusWeight  4
#define  WindowEx_Attr_Layout_Attr_Cursor  5
#define  WindowEx_Attr_Layout_Attr_Tag  6
#define  WindowEx_Attr_Skin  7
#define  WindowEx_Attr_Icon  8
#define  WindowEx_Attr_Text  9
#define  WindowEx_Attr_Font  10
#define  WindowEx_Attr_FontClour  11
#define  WindowEx_Attr_LayeredTransparency  12
#define  WindowEx_Attr_DragPositionMode  13
#define  WindowEx_Attr_DragMode  14
#define  WindowEx_Attr_MaxMode  15
#define  WindowEx_Attr_ButtonData  16
#define  WindowEx_Attr_nimationParam  17
#define  WindowEx_Attr_Text_A  18
#define  WindowEx_Attr_ElemeData  19
#define  WindowEx_Attr_Layout  20
#define  LabelEx_Attr_Layout_Attr_Visual  0
#define  LabelEx_Attr_Layout_Attr_Disabled  1
#define  LabelEx_Attr_Layout_Attr_Transparency  2
#define  LabelEx_Attr_Layout_Attr_Pierced  3
#define  LabelEx_Attr_Layout_Attr_FocusWeight  4
#define  LabelEx_Attr_Layout_Attr_Cursor  5
#define  LabelEx_Attr_Layout_Attr_Tag  6
#define  LabelEx_Attr_Text  7
#define  LabelEx_Attr_Align  8
#define  LabelEx_Attr_BackColor  9
#define  LabelEx_Attr_Font  10
#define  LabelEx_Attr_FontClour  11
#define  LabelEx_Attr_Text_A  12
#define  LabelEx_Attr_Rotate  13
#define  LabelEx_Attr_ElemeData  14
#define  LabelEx_Attr_Layout  15
#define  FilterEx_Attr_Layout_Attr_Visual  0
#define  FilterEx_Attr_Layout_Attr_Disabled  1
#define  FilterEx_Attr_Layout_Attr_Transparency  2
#define  FilterEx_Attr_Layout_Attr_Pierced  3
#define  FilterEx_Attr_Layout_Attr_FocusWeight  4
#define  FilterEx_Attr_Layout_Attr_Cursor  5
#define  FilterEx_Attr_Layout_Attr_Tag  6
#define  FilterEx_Attr_FilterExMode  7
#define  FilterEx_Attr_Parameter1  8
#define  FilterEx_Attr_Parameter2  9
#define  FilterEx_Attr_Parameter3  10
#define  FilterEx_Attr_Parameter4  11
#define  FilterEx_Attr_ElemeData  12
#define  FilterEx_Attr_Layout  13
#define  ButtonEx_Attr_Layout_Attr_Visual  0
#define  ButtonEx_Attr_Layout_Attr_Disabled  1
#define  ButtonEx_Attr_Layout_Attr_Transparency  2
#define  ButtonEx_Attr_Layout_Attr_Pierced  3
#define  ButtonEx_Attr_Layout_Attr_FocusWeight  4
#define  ButtonEx_Attr_Layout_Attr_Cursor  5
#define  ButtonEx_Attr_Layout_Attr_Tag  6
#define  ButtonEx_Attr_Skin  7
#define  ButtonEx_Attr_Text  8
#define  ButtonEx_Attr_Font  9
#define  ButtonEx_Attr_FontClour  10
#define  ButtonEx_Attr_AnimationParam  11
#define  ButtonEx_Attr_Text_A  12
#define  ButtonEx_Attr_ElemeData  13
#define  ButtonEx_Attr_Layout  14
#define  ImagebuttonEx_Attr_Layout_Attr_Visual  0
#define  ImagebuttonEx_Attr_Layout_Attr_Disabled  1
#define  ImagebuttonEx_Attr_Layout_Attr_Transparency  2
#define  ImagebuttonEx_Attr_Layout_Attr_Pierced  3
#define  ImagebuttonEx_Attr_Layout_Attr_FocusWeight  4
#define  ImagebuttonEx_Attr_Layout_Attr_Cursor  5
#define  ImagebuttonEx_Attr_Layout_Attr_Tag  6
#define  ImagebuttonEx_Attr_Skin  7
#define  ImagebuttonEx_Attr_Selected  8
#define  ImagebuttonEx_Attr_AnimationParam  9
#define  ImagebuttonEx_Attr_ElemeData  10
#define  ImagebuttonEx_Attr_Layout  11
#define  SuperbuttonEx_Attr_Layout_Attr_Visual  0
#define  SuperbuttonEx_Attr_Layout_Attr_Disabled  1
#define  SuperbuttonEx_Attr_Layout_Attr_Transparency  2
#define  SuperbuttonEx_Attr_Layout_Attr_Pierced  3
#define  SuperbuttonEx_Attr_Layout_Attr_FocusWeight  4
#define  SuperbuttonEx_Attr_Layout_Attr_Cursor  5
#define  SuperbuttonEx_Attr_Layout_Attr_Tag  6
#define  SuperbuttonEx_Attr_Skin  7
#define  SuperbuttonEx_Attr_Selected  8
#define  SuperbuttonEx_Attr_Icon  9
#define  SuperbuttonEx_Attr_IconWidth  10
#define  SuperbuttonEx_Attr_IconHeight  11
#define  SuperbuttonEx_Attr_IconResidence  12
#define  SuperbuttonEx_Attr_Text  13
#define  SuperbuttonEx_Attr_Font  14
#define  SuperbuttonEx_Attr_FontClour  15
#define  SuperbuttonEx_Attr_AnimationParam  16
#define  SuperbuttonEx_Attr_Text_A  17
#define  SuperbuttonEx_Attr_ElemeData  18
#define  SuperbuttonEx_Attr_Layout  19
#define  ChoiceboxEx_Attr_Layout_Attr_Visual  0
#define  ChoiceboxEx_Attr_Layout_Attr_Disabled  1
#define  ChoiceboxEx_Attr_Layout_Attr_Transparency  2
#define  ChoiceboxEx_Attr_Layout_Attr_Pierced  3
#define  ChoiceboxEx_Attr_Layout_Attr_FocusWeight  4
#define  ChoiceboxEx_Attr_Layout_Attr_Cursor  5
#define  ChoiceboxEx_Attr_Layout_Attr_Tag  6
#define  ChoiceboxEx_Attr_Skin  7
#define  ChoiceboxEx_Attr_Selected  8
#define  ChoiceboxEx_Attr_Text  9
#define  ChoiceboxEx_Attr_Font  10
#define  ChoiceboxEx_Attr_FontClour  11
#define  ChoiceboxEx_Attr_AnimationParam  12
#define  ChoiceboxEx_Attr_Text_A  13
#define  ChoiceboxEx_Attr_SelectState  14
#define  ChoiceboxEx_Attr_ElemeData  15
#define  ChoiceboxEx_Attr_Layout  16
#define  RadiobuttonEx_Attr_Layout_Attr_Visual  0
#define  RadiobuttonEx_Attr_Layout_Attr_Disabled  1
#define  RadiobuttonEx_Attr_Layout_Attr_Transparency  2
#define  RadiobuttonEx_Attr_Layout_Attr_Pierced  3
#define  RadiobuttonEx_Attr_Layout_Attr_FocusWeight  4
#define  RadiobuttonEx_Attr_Layout_Attr_Cursor  5
#define  RadiobuttonEx_Attr_Layout_Attr_Tag  6
#define  RadiobuttonEx_Attr_Skin  7
#define  RadiobuttonEx_Attr_Selected  8
#define  RadiobuttonEx_Attr_Text  9
#define  RadiobuttonEx_Attr_Font  10
#define  RadiobuttonEx_Attr_FontClour  11
#define  RadiobuttonEx_Attr_AnimationParam  12
#define  RadiobuttonEx_Attr_Text_A  13
#define  RadiobuttonEx_Attr_ElemeData  14
#define  RadiobuttonEx_Attr_Layout  15
#define  EditboxEx_Attr_Layout_Attr_Visual  0
#define  EditboxEx_Attr_Layout_Attr_Disabled  1
#define  EditboxEx_Attr_Layout_Attr_Transparency  2
#define  EditboxEx_Attr_Layout_Attr_Pierced  3
#define  EditboxEx_Attr_Layout_Attr_FocusWeight  4
#define  EditboxEx_Attr_Layout_Attr_Cursor  5
#define  EditboxEx_Attr_Layout_Attr_Tag  6
#define  EditboxEx_Attr_Skin  7
#define  EditboxEx_Attr_Content  8
#define  EditboxEx_Attr_Align  9
#define  EditboxEx_Attr_InputMode  10
#define  EditboxEx_Attr_MaxInput  11
#define  EditboxEx_Attr_PasswordSubstitution  12
#define  EditboxEx_Attr_CursorColor  13
#define  EditboxEx_Attr_Font  14
#define  EditboxEx_Attr_FontClour  15
#define  EditboxEx_Attr_SelectedFontColor  16
#define  EditboxEx_Attr_SelectedColor  17
#define  EditboxEx_Attr_LeftReservation  18
#define  EditboxEx_Attr_RightReservation  19
#define  EditboxEx_Attr_Multiline  20
#define  EditboxEx_Attr_Wrapped  21
#define  EditboxEx_Attr_ScrollBarMode  22
#define  EditboxEx_Attr_MenuTableWidth  23
#define  EditboxEx_Attr_MenuTableHeight  24
#define  EditboxEx_Attr_MenuFont  25
#define  EditboxEx_Attr_MenuFontClour  26
#define  EditboxEx_Attr_MenuDisabledFontClour  27
#define  EditboxEx_Attr_MenuTransparency  28
#define  EditboxEx_Attr_MenuLanguage  29
#define  EditboxEx_Attr_Content_A  30
#define  EditboxEx_Attr_PasswordSubstitution_A  31
#define  EditboxEx_Attr_ElemeData  32
#define  EditboxEx_Attr_Layout  33
#define  ComboboxEx_Attr_Layout_Attr_Visual  0
#define  ComboboxEx_Attr_Layout_Attr_Disabled  1
#define  ComboboxEx_Attr_Layout_Attr_Transparency  2
#define  ComboboxEx_Attr_Layout_Attr_Pierced  3
#define  ComboboxEx_Attr_Layout_Attr_FocusWeight  4
#define  ComboboxEx_Attr_Layout_Attr_Cursor  5
#define  ComboboxEx_Attr_Layout_Attr_Tag  6
#define  ComboboxEx_Attr_Skin  7
#define  ComboboxEx_Attr_Content  8
#define  ComboboxEx_Attr_Align  9
#define  ComboboxEx_Attr_InputMode  10
#define  ComboboxEx_Attr_MaxInput  11
#define  ComboboxEx_Attr_PasswordSubstitution  12
#define  ComboboxEx_Attr_CursorColor  13
#define  ComboboxEx_Attr_Font  14
#define  ComboboxEx_Attr_FontClour  15
#define  ComboboxEx_Attr_SelectedFontColor  16
#define  ComboboxEx_Attr_SelectedColor  17
#define  ComboboxEx_Attr_LeftReservation  18
#define  ComboboxEx_Attr_RightReservation  19
#define  ComboboxEx_Attr_MenuTableWidth  20
#define  ComboboxEx_Attr_MenuTableHeight  21
#define  ComboboxEx_Attr_MenuFont  22
#define  ComboboxEx_Attr_MenuFontClour  23
#define  ComboboxEx_Attr_MenuDisabledFontClour  24
#define  ComboboxEx_Attr_MenuTransparency  25
#define  ComboboxEx_Attr_MenuLanguage  26
#define  ComboboxEx_Attr_DownListWidth  27
#define  ComboboxEx_Attr_DownListMaxHeight  28
#define  ComboboxEx_Attr_DownListCurrentSelection  29
#define  ComboboxEx_Attr_DownListIconWidth  30
#define  ComboboxEx_Attr_DownListIconHeight  31
#define  ComboboxEx_Attr_DownListFont  32
#define  ComboboxEx_Attr_DownListAlternate  33
#define  ComboboxEx_Attr_DownListScrollBarMode  34
#define  ComboboxEx_Attr_DownListAttributeTransparency  35
#define  ComboboxEx_Attr_DownListItemData  36
#define  ComboboxEx_Attr_Content_A  37
#define  ComboboxEx_Attr_PasswordSubstitution_A  38
#define  ComboboxEx_Attr_ElemeData  39
#define  ComboboxEx_Attr_Layout  40
#define  MinutesboxEx_Attr_Layout_Attr_Visual  0
#define  MinutesboxEx_Attr_Layout_Attr_Disabled  1
#define  MinutesboxEx_Attr_Layout_Attr_Transparency  2
#define  MinutesboxEx_Attr_Layout_Attr_Pierced  3
#define  MinutesboxEx_Attr_Layout_Attr_FocusWeight  4
#define  MinutesboxEx_Attr_Layout_Attr_Cursor  5
#define  MinutesboxEx_Attr_Layout_Attr_Tag  6
#define  MinutesboxEx_Attr_Skin  7
#define  MinutesboxEx_Attr_Picture  8
#define  MinutesboxEx_Attr_IconWidth  9
#define  MinutesboxEx_Attr_IconHeight  10
#define  MinutesboxEx_Attr_Text  11
#define  MinutesboxEx_Attr_TextMode  12
#define  MinutesboxEx_Attr_Font  13
#define  MinutesboxEx_Attr_FontClour  14
#define  MinutesboxEx_Attr_Text_A  15
#define  MinutesboxEx_Attr_ElemeData  16
#define  MinutesboxEx_Attr_Layout  17
#define  MultifunctionButtonEx_Attr_Layout_Attr_Visual  0
#define  MultifunctionButtonEx_Attr_Layout_Attr_Disabled  1
#define  MultifunctionButtonEx_Attr_Layout_Attr_Transparency  2
#define  MultifunctionButtonEx_Attr_Layout_Attr_Pierced  3
#define  MultifunctionButtonEx_Attr_Layout_Attr_FocusWeight  4
#define  MultifunctionButtonEx_Attr_Layout_Attr_Cursor  5
#define  MultifunctionButtonEx_Attr_Layout_Attr_Tag  6
#define  MultifunctionButtonEx_Attr_Skin  7
#define  MultifunctionButtonEx_Attr_ButtonStyles  8
#define  MultifunctionButtonEx_Attr_PartnerSize  9
#define  MultifunctionButtonEx_Attr_BackColor  10
#define  MultifunctionButtonEx_Attr_Icon  11
#define  MultifunctionButtonEx_Attr_IconWidth  12
#define  MultifunctionButtonEx_Attr_IconHeight  13
#define  MultifunctionButtonEx_Attr_IconResidence  14
#define  MultifunctionButtonEx_Attr_Text  15
#define  MultifunctionButtonEx_Attr_Font  16
#define  MultifunctionButtonEx_Attr_FontClour  17
#define  MultifunctionButtonEx_Attr_Text_A  18
#define  MultifunctionButtonEx_Attr_ElemeData  19
#define  MultifunctionButtonEx_Attr_Layout  20
#define  PictureBoxEx_Attr_Layout_Attr_Visual  0
#define  PictureBoxEx_Attr_Layout_Attr_Disabled  1
#define  PictureBoxEx_Attr_Layout_Attr_Transparency  2
#define  PictureBoxEx_Attr_Layout_Attr_Pierced  3
#define  PictureBoxEx_Attr_Layout_Attr_FocusWeight  4
#define  PictureBoxEx_Attr_Layout_Attr_Cursor  5
#define  PictureBoxEx_Attr_Layout_Attr_Tag  6
#define  PictureBoxEx_Attr_Skin  7
#define  PictureBoxEx_Attr_Picture  8
#define  PictureBoxEx_Attr_MapMode  9
#define  PictureBoxEx_Attr_Angle  10
#define  PictureBoxEx_Attr_PlayAnimation  11
#define  PictureBoxEx_Attr_AllFrame  12
#define  PictureBoxEx_Attr_CurrentFrame  13
#define  PictureBoxEx_Attr_Rotate  14
#define  PictureBoxEx_Attr_ElemeData  15
#define  PictureBoxEx_Attr_Layout  16
#define  ProgressbarEx_Attr_Layout_Attr_Visual  0
#define  ProgressbarEx_Attr_Layout_Attr_Disabled  1
#define  ProgressbarEx_Attr_Layout_Attr_Transparency  2
#define  ProgressbarEx_Attr_Layout_Attr_Pierced  3
#define  ProgressbarEx_Attr_Layout_Attr_FocusWeight  4
#define  ProgressbarEx_Attr_Layout_Attr_Cursor  5
#define  ProgressbarEx_Attr_Layout_Attr_Tag  6
#define  ProgressbarEx_Attr_Skin  7
#define  ProgressbarEx_Attr_Position  8
#define  ProgressbarEx_Attr_MiniPosition  9
#define  ProgressbarEx_Attr_MaxiPosition  10
#define  ProgressbarEx_Attr_Style  11
#define  ProgressbarEx_Attr_Direction  12
#define  ProgressbarEx_Attr_ElemeData  13
#define  ProgressbarEx_Attr_Layout  14
#define  ScrollbarEx_Attr_Layout_Attr_Visual  0
#define  ScrollbarEx_Attr_Layout_Attr_Disabled  1
#define  ScrollbarEx_Attr_Layout_Attr_Transparency  2
#define  ScrollbarEx_Attr_Layout_Attr_Pierced  3
#define  ScrollbarEx_Attr_Layout_Attr_FocusWeight  4
#define  ScrollbarEx_Attr_Layout_Attr_Cursor  5
#define  ScrollbarEx_Attr_Layout_Attr_Tag  6
#define  ScrollbarEx_Attr_Skin  7
#define  ScrollbarEx_Attr_Position  8
#define  ScrollbarEx_Attr_MiniPosition  9
#define  ScrollbarEx_Attr_MaxiPosition  10
#define  ScrollbarEx_Attr_PageLength  11
#define  ScrollbarEx_Attr_RowChangeValue  12
#define  ScrollbarEx_Attr_PageChangeValue  13
#define  ScrollbarEx_Attr_ScrollChangeValue  14
#define  ScrollbarEx_Attr_DragTrace  15
#define  ScrollbarEx_Attr_schedule  16
#define  ScrollbarEx_Attr_ElemeData  17
#define  ScrollbarEx_Attr_Layout  18
#define  SliderbarEx_Attr_Layout_Attr_Visual  0
#define  SliderbarEx_Attr_Layout_Attr_Disabled  1
#define  SliderbarEx_Attr_Layout_Attr_Transparency  2
#define  SliderbarEx_Attr_Layout_Attr_Pierced  3
#define  SliderbarEx_Attr_Layout_Attr_FocusWeight  4
#define  SliderbarEx_Attr_Layout_Attr_Cursor  5
#define  SliderbarEx_Attr_Layout_Attr_Tag  6
#define  SliderbarEx_Attr_Skin  7
#define  SliderbarEx_Attr_Position  8
#define  SliderbarEx_Attr_Progress  9
#define  SliderbarEx_Attr_MiniPosition  10
#define  SliderbarEx_Attr_MaxiPosition  11
#define  SliderbarEx_Attr_RowChangeValue  12
#define  SliderbarEx_Attr_PageChangeValue  13
#define  SliderbarEx_Attr_DragTrace  14
#define  SliderbarEx_Attr_Style  15
#define  SliderbarEx_Attr_ElemeData  16
#define  SliderbarEx_Attr_Layout  17
#define  SelectthefolderEx_Attr_Layout_Attr_Visual  0
#define  SelectthefolderEx_Attr_Layout_Attr_Disabled  1
#define  SelectthefolderEx_Attr_Layout_Attr_Transparency  2
#define  SelectthefolderEx_Attr_Layout_Attr_Pierced  3
#define  SelectthefolderEx_Attr_Layout_Attr_FocusWeight  4
#define  SelectthefolderEx_Attr_Layout_Attr_Cursor  5
#define  SelectthefolderEx_Attr_Layout_Attr_Tag  6
#define  SelectthefolderEx_Attr_Skin  7
#define  SelectthefolderEx_Attr_CurrentTable  8
#define  SelectthefolderEx_Attr_TableSize  9
#define  SelectthefolderEx_Attr_Direction  10
#define  SelectthefolderEx_Attr_Spacing  11
#define  SelectthefolderEx_Attr_TableStyle  12
#define  SelectthefolderEx_Attr_Retain  13
#define  SelectthefolderEx_Attr_IconWidth  14
#define  SelectthefolderEx_Attr_IconHeight  15
#define  SelectthefolderEx_Attr_Font  16
#define  SelectthefolderEx_Attr_TableData  17
#define  SelectthefolderEx_Attr_ElemeData  18
#define  SelectthefolderEx_Attr_Layout  19
#define  ToolbarEx_Attr_Layout_Attr_Visual  0
#define  ToolbarEx_Attr_Layout_Attr_Disabled  1
#define  ToolbarEx_Attr_Layout_Attr_Transparency  2
#define  ToolbarEx_Attr_Layout_Attr_Pierced  3
#define  ToolbarEx_Attr_Layout_Attr_FocusWeight  4
#define  ToolbarEx_Attr_Layout_Attr_Cursor  5
#define  ToolbarEx_Attr_Layout_Attr_Tag  6
#define  ToolbarEx_Attr_Skin  7
#define  ToolbarEx_Attr_BackMode  8
#define  ToolbarEx_Attr_schedule  9
#define  ToolbarEx_Attr_Spacing  10
#define  ToolbarEx_Attr_IconWidth  11
#define  ToolbarEx_Attr_IconHeight  12
#define  ToolbarEx_Attr_Font  13
#define  ToolbarEx_Attr_ButtonData  14
#define  ToolbarEx_Attr_ElemeData  15
#define  ToolbarEx_Attr_Layout  16
#define  ListboxEx_Attr_Layout_Attr_Visual  0
#define  ListboxEx_Attr_Layout_Attr_Disabled  1
#define  ListboxEx_Attr_Layout_Attr_Transparency  2
#define  ListboxEx_Attr_Layout_Attr_Pierced  3
#define  ListboxEx_Attr_Layout_Attr_FocusWeight  4
#define  ListboxEx_Attr_Layout_Attr_Cursor  5
#define  ListboxEx_Attr_Layout_Attr_Tag  6
#define  ListboxEx_Attr_Skin  7
#define  ListboxEx_Attr_CurrentSelection  8
#define  ListboxEx_Attr_IconWidth  9
#define  ListboxEx_Attr_IconHeight  10
#define  ListboxEx_Attr_Font  11
#define  ListboxEx_Attr_AlternateColor  12
#define  ListboxEx_Attr_ScrollBarMode  13
#define  ListboxEx_Attr_ItemData  14
#define  ListboxEx_Attr_ElemeData  15
#define  ListboxEx_Attr_Layout  16
#define  SuperListboxEx_Attr_Layout_Attr_Visual  0
#define  SuperListboxEx_Attr_Layout_Attr_Disabled  1
#define  SuperListboxEx_Attr_Layout_Attr_Transparency  2
#define  SuperListboxEx_Attr_Layout_Attr_Pierced  3
#define  SuperListboxEx_Attr_Layout_Attr_FocusWeight  4
#define  SuperListboxEx_Attr_Layout_Attr_Cursor  5
#define  SuperListboxEx_Attr_Layout_Attr_Tag  6
#define  SuperListboxEx_Attr_Skin  7
#define  SuperListboxEx_Attr_CurrentSelection  8
#define  SuperListboxEx_Attr_HeadHeight  9
#define  SuperListboxEx_Attr_HeadMode  10
#define  SuperListboxEx_Attr_AlternateColor  11
#define  SuperListboxEx_Attr_EventFilter  12
#define  SuperListboxEx_Attr_LineMode  13
#define  SuperListboxEx_Attr_ScrollBarMode  14
#define  SuperListboxEx_Attr_ItemData  15
#define  SuperListboxEx_Attr_ElemeData  16
#define  SuperListboxEx_Attr_Layout  17
#define  IcoListboxEx_Attr_Layout_Attr_Visual  0
#define  IcoListboxEx_Attr_Layout_Attr_Disabled  1
#define  IcoListboxEx_Attr_Layout_Attr_Transparency  2
#define  IcoListboxEx_Attr_Layout_Attr_Pierced  3
#define  IcoListboxEx_Attr_Layout_Attr_FocusWeight  4
#define  IcoListboxEx_Attr_Layout_Attr_Cursor  5
#define  IcoListboxEx_Attr_Layout_Attr_Tag  6
#define  IcoListboxEx_Attr_Skin  7
#define  IcoListboxEx_Attr_CurrentSelection  8
#define  IcoListboxEx_Attr_TableWidth  9
#define  IcoListboxEx_Attr_TableHeight  10
#define  IcoListboxEx_Attr_HSpacing  11
#define  IcoListboxEx_Attr_LSpacing  12
#define  IcoListboxEx_Attr_IconWidth  13
#define  IcoListboxEx_Attr_IconHeight  14
#define  IcoListboxEx_Attr_Font  15
#define  IcoListboxEx_Attr_PageLayout  16
#define  IcoListboxEx_Attr_IconResidence  17
#define  IcoListboxEx_Attr_ScrollBarMode  18
#define  IcoListboxEx_Attr_ItemData  19
#define  IcoListboxEx_Attr_ElemeData  20
#define  IcoListboxEx_Attr_Layout  21
#define  TreeListEx_Attr_Layout_Attr_Visual  0
#define  TreeListEx_Attr_Layout_Attr_Disabled  1
#define  TreeListEx_Attr_Layout_Attr_Transparency  2
#define  TreeListEx_Attr_Layout_Attr_Pierced  3
#define  TreeListEx_Attr_Layout_Attr_FocusWeight  4
#define  TreeListEx_Attr_Layout_Attr_Cursor  5
#define  TreeListEx_Attr_Layout_Attr_Tag  6
#define  TreeListEx_Attr_Skin  7
#define  TreeListEx_Attr_CurrentSelection  8
#define  TreeListEx_Attr_AutoSize  9
#define  TreeListEx_Attr_FoldBtnWidth  10
#define  TreeListEx_Attr_FoldBtnHeight  11
#define  TreeListEx_Attr_IconWidth  12
#define  TreeListEx_Attr_IconHeight  13
#define  TreeListEx_Attr_Font  14
#define  TreeListEx_Attr_ChildMigration  15
#define  TreeListEx_Attr_BackMigration  16
#define  TreeListEx_Attr_ContentMigration  17
#define  TreeListEx_Attr_LineMode  18
#define  TreeListEx_Attr_ScrollBarMode  19
#define  TreeListEx_Attr_ItemData  20
#define  TreeListEx_Attr_ElemeData  21
#define  TreeListEx_Attr_Layout  22
#define  WebBrowserEx_Attr_Layout_Attr_Visual  0
#define  WebBrowserEx_Attr_Layout_Attr_Disabled  1
#define  WebBrowserEx_Attr_Layout_Attr_Transparency  2
#define  WebBrowserEx_Attr_Layout_Attr_Pierced  3
#define  WebBrowserEx_Attr_Layout_Attr_FocusWeight  4
#define  WebBrowserEx_Attr_Layout_Attr_Cursor  5
#define  WebBrowserEx_Attr_Layout_Attr_Tag  6
#define  WebBrowserEx_Attr_BackgroundTransparent  7
#define  WebBrowserEx_Attr_MediaVolume  8
#define  WebBrowserEx_Attr_ZoomFactor  9
#define  WebBrowserEx_Attr_NavigationToNewWind  10
#define  WebBrowserEx_Attr_CookieEnabled  11
#define  WebBrowserEx_Attr_NpapiEnabled  12
#define  WebBrowserEx_Attr_MenuEnabled  13
#define  WebBrowserEx_Attr_DragEnable  14
#define  WebBrowserEx_Attr_StartPage  15
#define  WebBrowserEx_Attr_UserAgent  16
#define  WebBrowserEx_Attr_Version  17
#define  WebBrowserEx_Attr_ElemeData  18
#define  WebBrowserEx_Attr_Layout  19
#define  CalendarBoxEx_Attr_Layout_Attr_Visual  0
#define  CalendarBoxEx_Attr_Layout_Attr_Disabled  1
#define  CalendarBoxEx_Attr_Layout_Attr_Transparency  2
#define  CalendarBoxEx_Attr_Layout_Attr_Pierced  3
#define  CalendarBoxEx_Attr_Layout_Attr_FocusWeight  4
#define  CalendarBoxEx_Attr_Layout_Attr_Cursor  5
#define  CalendarBoxEx_Attr_Layout_Attr_Tag  6
#define  CalendarBoxEx_Attr_Skin  7
#define  CalendarBoxEx_Attr_MiniDate  8
#define  CalendarBoxEx_Attr_MaxDate  9
#define  CalendarBoxEx_Attr_SelectionDate  10
#define  CalendarBoxEx_Attr_TitleFont  11
#define  CalendarBoxEx_Attr_WeekFont  12
#define  CalendarBoxEx_Attr_DayFont  13
#define  CalendarBoxEx_Attr_TimeFont  14
#define  CalendarBoxEx_Attr_TitleClour  15
#define  CalendarBoxEx_Attr_WeekClour  16
#define  CalendarBoxEx_Attr_WeekendWeekClour  17
#define  CalendarBoxEx_Attr_DayClour  18
#define  CalendarBoxEx_Attr_WeekendClour  19
#define  CalendarBoxEx_Attr_OtherMonthClour  20
#define  CalendarBoxEx_Attr_TimeFontClour  21
#define  CalendarBoxEx_Attr_OnlyThisMonth  22
#define  CalendarBoxEx_Attr_TimeMode  23
#define  CalendarBoxEx_Attr_TitleHeight  24
#define  CalendarBoxEx_Attr_WeekHeight  25
#define  CalendarBoxEx_Attr_TimeRegulatorHeight  26
#define  CalendarBoxEx_Attr_PartnerHeight  27
#define  CalendarBoxEx_Attr_Language  28
#define  CalendarBoxEx_Attr_MiniDate_A  29
#define  CalendarBoxEx_Attr_MaxDate_A  30
#define  CalendarBoxEx_Attr_SelectionDate_A  31
#define  CalendarBoxEx_Attr_ElemeData  32
#define  CalendarBoxEx_Attr_Layout  33
#define  ColorPickEx_Attr_Layout_Attr_Visual  0
#define  ColorPickEx_Attr_Layout_Attr_Disabled  1
#define  ColorPickEx_Attr_Layout_Attr_Transparency  2
#define  ColorPickEx_Attr_Layout_Attr_Pierced  3
#define  ColorPickEx_Attr_Layout_Attr_FocusWeight  4
#define  ColorPickEx_Attr_Layout_Attr_Cursor  5
#define  ColorPickEx_Attr_Layout_Attr_Tag  6
#define  ColorPickEx_Attr_Skin  7
#define  ColorPickEx_Attr_Font  8
#define  ColorPickEx_Attr_FontClour  9
#define  ColorPickEx_Attr_NowClour  10
#define  ColorPickEx_Attr_DragTrace  11
#define  ColorPickEx_Attr_ClourMode  12
#define  ColorPickEx_Attr_QuickClours  13
#define  ColorPickEx_Attr_Style  14
#define  ColorPickEx_Attr_RegulatorHeight  15
#define  ColorPickEx_Attr_QuickClourSize  16
#define  ColorPickEx_Attr_PartnerHeight  17
#define  ColorPickEx_Attr_ElemeData  18
#define  ColorPickEx_Attr_Layout  19
#define  RichEditEx_Attr_Layout_Attr_Visual  0
#define  RichEditEx_Attr_Layout_Attr_Disabled  1
#define  RichEditEx_Attr_Layout_Attr_Transparency  2
#define  RichEditEx_Attr_Layout_Attr_Pierced  3
#define  RichEditEx_Attr_Layout_Attr_FocusWeight  4
#define  RichEditEx_Attr_Layout_Attr_Cursor  5
#define  RichEditEx_Attr_Layout_Attr_Tag  6
#define  RichEditEx_Attr_Skin  7
#define  RichEditEx_Attr_Content  8
#define  RichEditEx_Attr_Type  9
#define  RichEditEx_Attr_BackTransparent  10
#define  RichEditEx_Attr_BackClour  11
#define  RichEditEx_Attr_CursorColor  12
#define  RichEditEx_Attr_DefaultCharFormat  13
#define  RichEditEx_Attr__DefaultParaFormat  14
#define  RichEditEx_Attr_InputMode  15
#define  RichEditEx_Attr_MaxInput  16
#define  RichEditEx_Attr_PasswordSubstitution  17
#define  RichEditEx_Attr_Multiline  18
#define  RichEditEx_Attr_Wrapped  19
#define  RichEditEx_Attr_ScrollBarMode  20
#define  RichEditEx_Attr_MenuTableWidth  21
#define  RichEditEx_Attr_MenuTableHeight  22
#define  RichEditEx_Attr_MenuFont  23
#define  RichEditEx_Attr_MenuFontClour  24
#define  RichEditEx_Attr_MenuDisabledFontClour  25
#define  RichEditEx_Attr_MenuTransparency  26
#define  RichEditEx_Attr_MenuLanguage  27
#define  RichEditEx_Attr_Content_A  28
#define  RichEditEx_Attr_PasswordSubstitution_A  29
#define  RichEditEx_Attr_ElemeData  30
#define  RichEditEx_Attr_Layout  31
#define  ExtendEx_Attr_Layout_Attr_Visual  0
#define  ExtendEx_Attr_Layout_Attr_Disabled  1
#define  ExtendEx_Attr_Layout_Attr_Transparency  2
#define  ExtendEx_Attr_Layout_Attr_Pierced  3
#define  ExtendEx_Attr_Layout_Attr_FocusWeight  4
#define  ExtendEx_Attr_Layout_Attr_Cursor  5
#define  ExtendEx_Attr_Layout_Attr_Tag  6
#define  ExtendEx_Attr_ExtendAttr  7
#define  ExtendEx_Attr_ElemeData  8
#define  ExtendEx_Attr_Layout  9
#define  AnimationbuttonEx_Attr_Layout_Attr_Visual  0
#define  AnimationbuttonEx_Attr_Layout_Attr_Disabled  1
#define  AnimationbuttonEx_Attr_Layout_Attr_Transparency  2
#define  AnimationbuttonEx_Attr_Layout_Attr_Pierced  3
#define  AnimationbuttonEx_Attr_Layout_Attr_FocusWeight  4
#define  AnimationbuttonEx_Attr_Layout_Attr_Cursor  5
#define  AnimationbuttonEx_Attr_Layout_Attr_Tag  6
#define  AnimationbuttonEx_Attr_Skin  7
#define  AnimationbuttonEx_Attr_Selected  8
#define  AnimationbuttonEx_Attr_Icon  9
#define  AnimationbuttonEx_Attr_IconWidth  10
#define  AnimationbuttonEx_Attr_IconHeight  11
#define  AnimationbuttonEx_Attr_IconResidence  12
#define  AnimationbuttonEx_Attr_Text  13
#define  AnimationbuttonEx_Attr_Font  14
#define  AnimationbuttonEx_Attr_FontClour  15
#define  AnimationbuttonEx_Attr_ElemeData  16
#define  AnimationbuttonEx_Attr_Layout  17
#define  AdvancedFormEx_Attr_Layout_Attr_Visual  0
#define  AdvancedFormEx_Attr_Layout_Attr_Disabled  1
#define  AdvancedFormEx_Attr_Layout_Attr_Transparency  2
#define  AdvancedFormEx_Attr_Layout_Attr_Pierced  3
#define  AdvancedFormEx_Attr_Layout_Attr_FocusWeight  4
#define  AdvancedFormEx_Attr_Layout_Attr_Cursor  5
#define  AdvancedFormEx_Attr_Layout_Attr_Tag  6
#define  AdvancedFormEx_Attr_Skin  7
#define  AdvancedFormEx_Attr_CurrentSelection  8
#define  AdvancedFormEx_Attr_CurrentSelectionColumn  9
#define  AdvancedFormEx_Attr_HeaderRowNum  10
#define  AdvancedFormEx_Attr_HeaderColumnNum  11
#define  AdvancedFormEx_Attr_BottomFixedRow  12
#define  AdvancedFormEx_Attr_RightFixedColumn  13
#define  AdvancedFormEx_Attr_AdjustmentMode  14
#define  AdvancedFormEx_Attr_AutoSelect  15
#define  AdvancedFormEx_Attr_EntireLine  16
#define  AdvancedFormEx_Attr_LineMode  17
#define  AdvancedFormEx_Attr_ScrollBarMode  18
#define  AdvancedFormEx_Attr_ItemData  19
#define  AdvancedFormEx_Attr_ElemeData  20
#define  AdvancedFormEx_Attr_Layout  21
#define  SlideButtonEx_Attr_Layout_Attr_Visual  0
#define  SlideButtonEx_Attr_Layout_Attr_Disabled  1
#define  SlideButtonEx_Attr_Layout_Attr_Transparency  2
#define  SlideButtonEx_Attr_Layout_Attr_Pierced  3
#define  SlideButtonEx_Attr_Layout_Attr_FocusWeight  4
#define  SlideButtonEx_Attr_Layout_Attr_Cursor  5
#define  SlideButtonEx_Attr_Layout_Attr_Tag  6
#define  SlideButtonEx_Attr_Skin  7
#define  SlideButtonEx_Attr_Selected  8
#define  SlideButtonEx_Attr_ElemeData  9
#define  SlideButtonEx_Attr_Layout  10
#define  PieChartEx_Attr_Layout_Attr_Visual  0
#define  PieChartEx_Attr_Layout_Attr_Disabled  1
#define  PieChartEx_Attr_Layout_Attr_Transparency  2
#define  PieChartEx_Attr_Layout_Attr_Pierced  3
#define  PieChartEx_Attr_Layout_Attr_FocusWeight  4
#define  PieChartEx_Attr_Layout_Attr_Cursor  5
#define  PieChartEx_Attr_Layout_Attr_Tag  6
#define  PieChartEx_Attr_Skin  7
#define  PieChartEx_Attr_Leftretain  8
#define  PieChartEx_Attr_Topretain  9
#define  PieChartEx_Attr_Rightretain  10
#define  PieChartEx_Attr_bottomretain  11
#define  PieChartEx_Attr_hotGraph  12
#define  PieChartEx_Attr_GraphStar  13
#define  PieChartEx_Attr_GraphWidth  14
#define  PieChartEx_Attr_Zoom  15
#define  PieChartEx_Attr_ItemData  16
#define  PieChartEx_Attr_ElemeData  17
#define  PieChartEx_Attr_Layout  18
#define  BarChartEx_Attr_Layout_Attr_Visual  0
#define  BarChartEx_Attr_Layout_Attr_Disabled  1
#define  BarChartEx_Attr_Layout_Attr_Transparency  2
#define  BarChartEx_Attr_Layout_Attr_Pierced  3
#define  BarChartEx_Attr_Layout_Attr_FocusWeight  4
#define  BarChartEx_Attr_Layout_Attr_Cursor  5
#define  BarChartEx_Attr_Layout_Attr_Tag  6
#define  BarChartEx_Attr_Skin  7
#define  BarChartEx_Attr_ChartStyle  8
#define  BarChartEx_Attr_TemplateH  9
#define  BarChartEx_Attr_ColorHA  10
#define  BarChartEx_Attr_GridStyleH  11
#define  BarChartEx_Attr_GridColorH  12
#define  BarChartEx_Attr_FontH  13
#define  BarChartEx_Attr_FontColorH  14
#define  BarChartEx_Attr_TemplateV  15
#define  BarChartEx_Attr_MiniV  16
#define  BarChartEx_Attr_MaxV  17
#define  BarChartEx_Attr_ColorVA  18
#define  BarChartEx_Attr_GridStyleV  19
#define  BarChartEx_Attr_GridColorV  20
#define  BarChartEx_Attr_FontV  21
#define  BarChartEx_Attr_FontColorV  22
#define  BarChartEx_Attr_Leftretain  23
#define  BarChartEx_Attr_Topretain  24
#define  BarChartEx_Attr_Rightretain  25
#define  BarChartEx_Attr_bottomretain  26
#define  BarChartEx_Attr_hotcolumn  27
#define  BarChartEx_Attr_GraphWidth  28
#define  BarChartEx_Attr_GraphSpace  29
#define  BarChartEx_Attr_TemplateH_A  30
#define  BarChartEx_Attr_TemplateV_A  31
#define  BarChartEx_Attr_ItemData  32
#define  BarChartEx_Attr_ElemeData  33
#define  BarChartEx_Attr_Layout  34
#define  CurveChartEx_Attr_Layout_Attr_Visual  0
#define  CurveChartEx_Attr_Layout_Attr_Disabled  1
#define  CurveChartEx_Attr_Layout_Attr_Transparency  2
#define  CurveChartEx_Attr_Layout_Attr_Pierced  3
#define  CurveChartEx_Attr_Layout_Attr_FocusWeight  4
#define  CurveChartEx_Attr_Layout_Attr_Cursor  5
#define  CurveChartEx_Attr_Layout_Attr_Tag  6
#define  CurveChartEx_Attr_Skin  7
#define  CurveChartEx_Attr_ChartStyle  8
#define  CurveChartEx_Attr_TemplateH  9
#define  CurveChartEx_Attr_ColorHA  10
#define  CurveChartEx_Attr_GridStyleH  11
#define  CurveChartEx_Attr_GridColorH  12
#define  CurveChartEx_Attr_FontH  13
#define  CurveChartEx_Attr_FontColorH  14
#define  CurveChartEx_Attr_TemplateV  15
#define  CurveChartEx_Attr_MiniV  16
#define  CurveChartEx_Attr_MaxV  17
#define  CurveChartEx_Attr_ColorVA  18
#define  CurveChartEx_Attr_GridStyleV  19
#define  CurveChartEx_Attr_GridColorV  20
#define  CurveChartEx_Attr_FontV  21
#define  CurveChartEx_Attr_FontColorV  22
#define  CurveChartEx_Attr_Leftretain  23
#define  CurveChartEx_Attr_Topretain  24
#define  CurveChartEx_Attr_Rightretain  25
#define  CurveChartEx_Attr_bottomretain  26
#define  CurveChartEx_Attr_hotcolumn  27
#define  CurveChartEx_Attr_TemplateH_A  28
#define  CurveChartEx_Attr_TemplateV_A  29
#define  CurveChartEx_Attr_ItemData  30
#define  CurveChartEx_Attr_ElemeData  31
#define  CurveChartEx_Attr_Layout  32
#define  CandleChartEx_Attr_Layout_Attr_Visual  0
#define  CandleChartEx_Attr_Layout_Attr_Disabled  1
#define  CandleChartEx_Attr_Layout_Attr_Transparency  2
#define  CandleChartEx_Attr_Layout_Attr_Pierced  3
#define  CandleChartEx_Attr_Layout_Attr_FocusWeight  4
#define  CandleChartEx_Attr_Layout_Attr_Cursor  5
#define  CandleChartEx_Attr_Layout_Attr_Tag  6
#define  CandleChartEx_Attr_Skin  7
#define  CandleChartEx_Attr_ChartStyle  8
#define  CandleChartEx_Attr_TemplateH  9
#define  CandleChartEx_Attr_ColorHA  10
#define  CandleChartEx_Attr_GridStyleH  11
#define  CandleChartEx_Attr_GridColorH  12
#define  CandleChartEx_Attr_FontH  13
#define  CandleChartEx_Attr_FontColorH  14
#define  CandleChartEx_Attr_TemplateV  15
#define  CandleChartEx_Attr_MiniV  16
#define  CandleChartEx_Attr_MaxV  17
#define  CandleChartEx_Attr_ColorVA  18
#define  CandleChartEx_Attr_GridStyleV  19
#define  CandleChartEx_Attr_GridColorV  20
#define  CandleChartEx_Attr_FontV  21
#define  CandleChartEx_Attr_FontColorV  22
#define  CandleChartEx_Attr_Leftretain  23
#define  CandleChartEx_Attr_Topretain  24
#define  CandleChartEx_Attr_Rightretain  25
#define  CandleChartEx_Attr_bottomretain  26
#define  CandleChartEx_Attr_hotcolumn  27
#define  CandleChartEx_Attr_GraphWidth  28
#define  CandleChartEx_Attr_NegativeHollow  29
#define  CandleChartEx_Attr_NegativeColor  30
#define  CandleChartEx_Attr_PositiveHollow  31
#define  CandleChartEx_Attr_PositiveColor  32
#define  CandleChartEx_Attr_TemplateH_A  33
#define  CandleChartEx_Attr_TemplateV_A  34
#define  CandleChartEx_Attr_ItemData  35
#define  CandleChartEx_Attr_ElemeData  36
#define  CandleChartEx_Attr_Layout  37
#define  DrawPanelEx_Attr_Layout_Attr_Visual  0
#define  DrawPanelEx_Attr_Layout_Attr_Disabled  1
#define  DrawPanelEx_Attr_Layout_Attr_Transparency  2
#define  DrawPanelEx_Attr_Layout_Attr_Pierced  3
#define  DrawPanelEx_Attr_Layout_Attr_FocusWeight  4
#define  DrawPanelEx_Attr_Layout_Attr_Cursor  5
#define  DrawPanelEx_Attr_Layout_Attr_Tag  6
#define  DrawPanelEx_Attr_BackColor  7
#define  DrawPanelEx_Attr_LineColor  8
#define  DrawPanelEx_Attr_ElemeData  9
#define  DrawPanelEx_Attr_Layout  10
#define  Event_Control_L_Click  660
#define  Event_Control_R_Click  661
#define  Event_Control_L_DOWN  662
#define  Event_Control_R_DOWN  663
#define  Event_Control_L_UP  664
#define  Event_Control_R_UP  665
#define  Event_Control_L_DClick  666
#define  Event_Control_R_DClick  667
#define  Event_Control_Move  668
#define  Event_Control_Track  669
#define  Event_Control_Wheel  670
#define  Event_Control_keyEvent  671
#define  Event_Control_CharInput  672
#define  Event_Control_Focus  673
#define  Event_Control_Other  674
#define  Event_Control_Other_WindowEx_Minmaxinfo  675
#define  FocusMode_LoseFocus  0
#define  FocusMode_GetFocus  2
#define  Focusrc_L_DOWN  0
#define  Focusrc_api_set  0
#define  Focusrc_change  0
#define  Event_Control_MBUTTONUP  1001
#define  Event_Control_MBUTTONDBLCLK  1002
#define  Event_Control_MBUTTONDOWN  1003
#define  Event_Control_SETCURSOR  1004
#define  Event_Control_GETMINMAXINFO  1005
#define  Event_Control_PositionChange  1006
#define  Event_Control_SizeChenge  1007
#define  Event_Control_Refresh  1008
#define  Event_Control_RefreshToWindow  1009
#define  Event_Control_Disabled  1010
#define  Event_Control_Visual  1011
#define  Event_Control_CreateOver  1012
#define  Event_Control_Destroy  1013
#define  Event_Control_SettleContainer  1014
#define  Event_MenuEx_ExtendPop  642
#define  Event_MenuEx_ExtendClose  643
#define  Event_MenuEx_ExtendMmeasure  644
#define  Event_MenuEx_ExtendDraw  645
#define  Event_MenuEx_WillPop  646
#define  Event_MenuEx_Pop  647
#define  Event_MenuEx_WillClose  648
#define  Event_MenuEx_Close  649
#define  Event_MenuEx_L_Click  650
#define  Event_MenuEx_R_Click  651
#define  Event_MenuEx_L_Up  652
#define  Event_MenuEx_R_Up  653
#define  Event_MenuEx_L_Down  654
#define  Event_MenuEx_R_Down  655
#define  Event_MenuEx_L_DClick  656
#define  Event_MenuEx_R_DClick  657
#define  Event_MenuEx_MouseIn  658
#define  Event_MenuEx_MouseOut  659
#define  Event_DownlistEx_ExtendPop  642
#define  Event_DownlistEx_ExtendClose  643
#define  Event_DownlistEx_ExtendMmeasure  644
#define  Event_DownlistEx_ExtendDraw  645
#define  Event_DownlistEx_WillPop  646
#define  Event_DownlistEx_Pop  647
#define  Event_DownlistEx_WillClose  648
#define  Event_DownlistEx_Close  649
#define  Event_DownlistEx_L_Click  650
#define  Event_DownlistEx_R_Click  651
#define  Event_DownlistEx_L_Up  652
#define  Event_DownlistEx_R_Up  653
#define  Event_DownlistEx_L_Down  654
#define  Event_DownlistEx_R_Down  655
#define  Event_DownlistEx_L_DClick  656
#define  Event_DownlistEx_R_DClick  657
#define  Event_DownlistEx_MouseIn  658
#define  Event_DownlistEx_MouseOut  659
#define  Event_WindowEx_FeedBackEvent  649
#define  Event_WindowEx_L_Click  650
#define  Event_WindowEx_R_Click  651
#define  Event_WindowEx_L_Up  652
#define  Event_WindowEx_R_Up  653
#define  Event_WindowEx_L_Down  654
#define  Event_WindowEx_R_Down  655
#define  Event_WindowEx_L_DClick  656
#define  Event_WindowEx_R_DClick  657
#define  Event_WindowEx_MouseIn  658
#define  Event_WindowEx_MouseOut  659
#define  Event_EditboxEx_ContentChanged  659
#define  Event_ComboboxEx_ContentChanged  658
#define  Event_ComboboxEx_ItemSelected  659
#define  Event_MultifunctionButtonEx_L_Click  650
#define  Event_MultifunctionButtonEx_R_Click  651
#define  Event_MultifunctionButtonEx_L_Up  652
#define  Event_MultifunctionButtonEx_R_Up  653
#define  Event_MultifunctionButtonEx_L_Down  654
#define  Event_MultifunctionButtonEx_R_Down  655
#define  Event_MultifunctionButtonEx_L_DClick  656
#define  Event_MultifunctionButtonEx_R_DClick  657
#define  Event_MultifunctionButtonEx_MouseIn  658
#define  Event_MultifunctionButtonEx_MouseOut  659
#define  Event_ScrollbarEx_Position  659
#define  Event_SliderbarEx_Position  659
#define  Event_SelectthefolderEx_TabWillChanged  648
#define  Event_SelectthefolderEx_TabChanged  649
#define  Event_SelectthefolderEx_L_Click  650
#define  Event_SelectthefolderEx_R_Click  651
#define  Event_SelectthefolderEx_L_Up  652
#define  Event_SelectthefolderEx_R_Up  653
#define  Event_SelectthefolderEx_L_Down  654
#define  Event_SelectthefolderEx_R_Down  655
#define  Event_SelectthefolderEx_L_DClick  656
#define  Event_SelectthefolderEx_R_DClick  657
#define  Event_SelectthefolderEx_MouseIn  658
#define  Event_SelectthefolderEx_MouseOut  659
#define  Event_ToolbarEx_L_Click  650
#define  Event_ToolbarEx_R_Click  651
#define  Event_ToolbarEx_L_Up  652
#define  Event_ToolbarEx_R_Up  653
#define  Event_ToolbarEx_L_Down  654
#define  Event_ToolbarEx_R_Down  655
#define  Event_ToolbarEx_L_DClick  656
#define  Event_ToolbarEx_R_DClick  657
#define  Event_ToolbarEx_MouseIn  658
#define  Event_ToolbarEx_MouseOut  659
#define  Event_ListboxEx_L_Click  650
#define  Event_ListboxEx_R_Click  651
#define  Event_ListboxEx_L_Up  652
#define  Event_ListboxEx_R_Up  653
#define  Event_ListboxEx_L_Down  654
#define  Event_ListboxEx_R_Down  655
#define  Event_ListboxEx_L_DClick  656
#define  Event_ListboxEx_R_DClick  657
#define  Event_ListboxEx_MouseIn  658
#define  Event_ListboxEx_MouseOut  659
#define  Event_SuperListboxEx_L_Click  649
#define  Event_SuperListboxEx_R_Click  650
#define  Event_SuperListboxEx_L_Up  651
#define  Event_SuperListboxEx_R_Up  652
#define  Event_SuperListboxEx_L_Down  653
#define  Event_SuperListboxEx_R_Down  654
#define  Event_SuperListboxEx_L_DClick  655
#define  Event_SuperListboxEx_R_DClick  656
#define  Event_SuperListboxEx_MouseIn  657
#define  Event_SuperListboxEx_MouseOut  658
#define  Event_SuperListboxEx_ItemSizeChanged  659
#define  Event_IcoListboxEx_L_Click  650
#define  Event_IcoListboxEx_R_Click  651
#define  Event_IcoListboxEx_L_Up  652
#define  Event_IcoListboxEx_R_Up  653
#define  Event_IcoListboxEx_L_Down  654
#define  Event_IcoListboxEx_R_Down  655
#define  Event_IcoListboxEx_L_DClick  656
#define  Event_IcoListboxEx_R_DClick  657
#define  Event_IcoListboxEx_MouseIn  658
#define  Event_IcoListboxEx_MouseOut  659
#define  Event_TreeListEx_L_Click  649
#define  Event_TreeListEx_R_Click  650
#define  Event_TreeListEx_L_Up  651
#define  Event_TreeListEx_R_Up  652
#define  Event_TreeListEx_L_Down  653
#define  Event_TreeListEx_R_Down  654
#define  Event_TreeListEx_L_DClick  655
#define  Event_TreeListEx_R_DClick  656
#define  Event_TreeListEx_MouseIn  657
#define  Event_TreeListEx_MouseOut  658
#define  Event_TreeListEx_FoldChanged  659
#define  Event_WebBrowserEx_Navigation  646
#define  Event_WebBrowserEx_CreateView  647
#define  Event_WebBrowserEx_URLChanged  648
#define  Event_WebBrowserEx_TitleChanged  649
#define  Event_WebBrowserEx_DocumentReady  650
#define  Event_WebBrowserEx_LoadingFinish  651
#define  Event_WebBrowserEx_Download  652
#define  Event_WebBrowserEx_AlertBox  653
#define  Event_WebBrowserEx_ConfirmBox  654
#define  Event_WebBrowserEx_PromptBox  655
#define  Event_WebBrowserEx_LoadUrlBegin  656
#define  Event_WebBrowserEx_LoadUrlFail  657
#define  Event_WebBrowserEx_LoadUrlEnd  658
#define  Event_WebBrowserEx_NetResponse  659
#define  Event_CalendarBoxEx_L_Click  650
#define  Event_CalendarBoxEx_R_Click  651
#define  Event_CalendarBoxEx_L_Up  652
#define  Event_CalendarBoxEx_R_Up  653
#define  Event_CalendarBoxEx_L_Down  654
#define  Event_CalendarBoxEx_R_Down  655
#define  Event_CalendarBoxEx_L_DClick  656
#define  Event_CalendarBoxEx_R_DClick  657
#define  Event_CalendarBoxEx_MouseIn  658
#define  Event_CalendarBoxEx_MouseOut  659
#define  Event_ColorPickEx_ColorChang  659
#define  Event_RichEditEx_ContentChanged  657
#define  Event_RichEditEx_SelectionChanged  658
#define  Event_RichEditEx_OtherExtendEvent  659
#define  Event_ExtendEx_UserEvent  659
#define  Event_AdvancedFormEx_L_Click  649
#define  Event_AdvancedFormEx_R_Click  650
#define  Event_AdvancedFormEx_L_Up  651
#define  Event_AdvancedFormEx_R_Up  652
#define  Event_AdvancedFormEx_L_Down  653
#define  Event_AdvancedFormEx_R_Down  654
#define  Event_AdvancedFormEx_L_DClick  655
#define  Event_AdvancedFormEx_R_DClick  656
#define  Event_AdvancedFormEx_MouseIn  657
#define  Event_AdvancedFormEx_MouseOut  658
#define  Event_AdvancedFormEx_ItemSizeChanged  659
#define  Event_SlideButtonEx_SelectChang  659
#define  Event_PieChartEx_ChartEvent  659
#define  Event_BarChartEx_ChartEvent  659
#define  Event_CandleChartEx_ChartEvent  659
#define  Event_CurveChartEx_ChartEvent  659
#define  Event_DrawPanelEx_DrawEvent  659
#define  Rc_Skin_Msgbox  700
#define  Rc_Skin_MsgboxCtrlBtn  701
#define  Rc_Skin_MenuEx  800
#define  Rc_Skin_DownlistEx  900
#define  Rc_Skin_WindowEx  1000
#define  Rc_Skin_WindowExBtn  1001
#define  Rc_Skin_LogoEx  1002
#define  Rc_Cur_WindowEx  1099
#define  Rc_Skin_FilterEx  1100
#define  Rc_Skin_MinutesboxEx  1200
#define  Rc_Skin_SelectthefolderEx  1300
#define  Rc_Skin_PictureBoxEx  1400
#define  Rc_Skin_LabelEx  1500
#define  Rc_Skin_ButtonEx  1600
#define  Rc_Skin_ImagebuttonEx  1700
#define  Rc_Skin_SuperbuttonEx  1800
#define  Rc_Skin_MultifunctionButtonEx  1900
#define  Rc_Skin_RadiobuttonEx  2000
#define  Rc_Skin_ChoiceboxEx  2100
#define  Rc_Skin_ProgressbarEx  2200
#define  Rc_Skin_SliderbarEx  2300
#define  Rc_Skin_ScrollbarEx  2400
#define  Rc_Skin_EditboxEx  2500
#define  Rc_Cur_EditboxEx  2599
#define  Rc_Skin_ComboboxEx  2600
#define  Rc_Cur_ComboboxEx  2699
#define  Rc_Skin_ToolbarEx  2700
#define  Rc_Skin_ListboxEx  2800
#define  Rc_Skin_IcoListboxEx  2900
#define  Rc_Skin_SuperListboxEx  3000
#define  Rc_Cur_SuperListboxEx  3001
#define  Rc_Skin_TreeListEx  3100
#define  Rc_Skin_WebBrowserEx  3200
#define  Rc_Cur_WebBrowserEx  3299
#define  Rc_Skin_CalendarBoxEx  3300
#define  Rc_Skin_ColorPickEx  3400
#define  Rc_Skin_RichEditEx  3500
#define  Rc_Cur_RichEditEx  3599
#define  Rc_Skin_ExtendEx  3600
#define  Rc_Cur_ExtendEx  3601
#define  Rc_Skin_AnimationbuttonEx  3700
#define  Rc_Skin_AdvancedFormEx  3800
#define  Rc_Cur_AdvancedFormEx  3801
#define  Rc_Skin_SlideButtonEx  3900
#define  Rc_Skin_PieChartEx  4000
#define  Rc_Skin_BarChartEx  4100
#define  Rc_Skin_CurveChartEx  4200
#define  Rc_Skin_CandleChartEx  4300
#define  Rc_Skin_DrawPanelEx  4400

struct 布局
{
	int x, y, wigth, hight;
};

struct FontInfo
{	
	字节集 名称;

	int 大小, 风格, 渲染模式,渲染模式1,渲染模式2;
};









class BaseEx
{

public:
	int control=0;
	virtual INT GetControlType()
	{
		return (0);
	}
	int Handle() {

		return control;

	}
};



class WindowBoxEx : public BaseEx
{
public:
	INT Create(INT 模式 = 0, INT 位置 = 1, INT 左边 = 50, INT 顶边 = 50, INT 宽度 = 380, INT 高度 = 250, void* 回调函数 = 0, BOOL 可视 = true, BOOL 禁止 = false, LPCSTR 图标 = "", LPCWSTR 标题 = L"", BOOL 总在最前 = false, BOOL 任务栏显示 = true, BOOL 退出键关闭 = false, LPCWSTR 类名 = L"", INT 类风格 = 0, INT 扩展风格 = 0, INT 窗口风格 = 268959744, INT 标识值 = 0);
	virtual INT GetControlType();
	//回掉函数4参（见下）
	//static INT CALLBACK Eventpro_WindowBoxEx(INT hwnd, INT msg, INT wParam, INT lParam);
		bool isCreate() {
		return IsWindow_WindowBoxEx((HWND)control);

	}
void MessageLoop() {
		MessageLoop_WindowBoxEx();
	}
INT getwidth() {
	return GetWidth_WindowBoxEx((HWND)control);
}
void setwidth(INT 宽度) {
	SetWidth_WindowBoxEx((HWND)control, 宽度);
}
INT gethight() {
	return GetHeight_WindowBoxEx((HWND)control);

}
void sethight(INT 高度) {
	SetHeight_WindowBoxEx((HWND)control, 高度);
}


};






class WindowEx:public BaseEx
{
public:
	//INT CALLBACK WindowEx::Eventpro_WindowEx(int ctrhandle, int msg, int Parameter1, int Parameter2, int Parameter3, int Parameter4)
	//回调函数6参数
	
	int Create(BaseEx& 父级组件, INT 左边 = 10, INT 顶边 = 40, INT 宽度 = 100, INT 高度 = 100, BOOL 可视 = true, BOOL 禁止 = false, void* 回调函数 = 0, INT 透明度 = 255, INT 穿透模式 = 0, INT 焦点权重 = 0, LPCSTR 鼠标光标 = "", INT 标识值 = 0, LPCSTR 皮肤 = "", LPCSTR 图标 = "", LPCWSTR 标题 = L"test", LPCSTR 字体 = "", INT 字体色 = 0, INT 分层透明 = 256, INT 拖动模式 = 1, INT 尺寸调整模式 = 0, INT 最大化模式 = 0, LPCSTR 控制钮 = "", INT 控制钮动画参数 = 0, LPCSTR 扩展元素 = "", LPCSTR 布局器 = "");
	LPCWSTR Gettittle();


private:


	

};
class MinutesboxEx :public BaseEx 
{
public:
	

	int GetHeight();

	void SetHeight(int high);

	void SetWidth(int width);

	int GetWidth();


	int Create(BaseEx& 父级组件, INT 左边=10, INT 顶边=40, INT 宽度=100, INT 高度=100, BOOL 可视=1, BOOL 禁止=0, void* 回调函数=0, INT 透明度=255, INT 穿透模式=0, INT 焦点权重=0, LPCSTR 鼠标光标="", INT 标识值=0, LPCSTR 皮肤="", LPCSTR 图标="", INT 图标宽=20, INT 图标高=20, LPCWSTR 标题=L"", INT 标题对齐方式=0, 字节集 字体=生成字体Ex(L"",0,0,0,0,0,0), INT 字体色 = -33554432, LPCSTR 扩展元素="", LPCSTR 布局器="");
	
};



class LabelEx :public BaseEx
{
public:



	int Create(BaseEx& 父级组件, INT 左边 = 10, INT 顶边 = 40, INT 宽度 = 100, INT 高度 = 40, BOOL 可视 = true, BOOL 禁止 = false, void* 回调函数 = 0, INT 透明度 = 255, INT 穿透模式 = 0, INT 焦点权重 = 0, LPCSTR 鼠标光标 = "", INT 标识值 = 0, LPCWSTR 标题 = L"", INT 对齐方式 = 0, INT 背景色 = 0, LPCSTR 字体 = "", INT 字体色 = -33554432, INT 旋转角度 = 0, LPCSTR 扩展元素 = "", LPCSTR 布局器 = "");

};

class PictureBoxEx :public BaseEx
{
public:



	int Create(BaseEx& 父级组件, INT 左边 = 10, INT 顶边 = 40, INT 宽度 = 100, INT 高度 = 40, BOOL 可视 = true, BOOL 禁止 = false, void* 回调函数 = 0, INT 透明度 = 255, INT 穿透模式 = 0, INT 焦点权重 = 0, LPCSTR 鼠标光标 = "", INT 标识值 = 0, LPCSTR 皮肤 = "", LPCSTR 图片 = "", INT 底图方式 = 0, INT 圆角度 = 0, BOOL 播放动画 = false, INT 总帧数 = 0, INT 当前帧 = 0, INT 旋转角度 = 0, LPCSTR 扩展元素 = "", LPCSTR 布局器 = "");

	int GetHeight();

	void SetHeight(int high);

	void SetWidth(int width);

	int GetWidth();

	
	
	
};