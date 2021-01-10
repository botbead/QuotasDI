object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'httpSrvBankResp'
  ClientHeight = 602
  ClientWidth = 949
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  WindowState = wsMaximized
  OnClick = FormClick
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 949
    Height = 602
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    Left = 552
    Top = 40
    object N1: TMenuItem
      Caption = #28165#31354
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #23450#26102#28165#31354
    end
  end
  object Timer1: TTimer
    Interval = 86400000
    OnTimer = Timer1Timer
    Left = 592
    Top = 376
  end
end
