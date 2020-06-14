object UniLoginForm1: TUniLoginForm1
  Left = 0
  Top = 0
  ClientHeight = 243
  ClientWidth = 472
  Caption = #30331#24405
  OldCreateOrder = False
  BorderIcons = [biSystemMenu]
  MonitoredKeys.Keys = <>
  PixelsPerInch = 96
  TextHeight = 13
  object UniLabel1: TUniLabel
    Left = 128
    Top = 64
    Width = 45
    Height = 18
    Caption = #29992#25143#21517
    ParentFont = False
    Font.Height = -15
    TabOrder = 0
  end
  object UniEdit1: TUniEdit
    Left = 200
    Top = 64
    Width = 145
    TabOrder = 1
  end
  object UniLabel2: TUniLabel
    Left = 128
    Top = 104
    Width = 30
    Height = 18
    Caption = #23494#30721
    ParentFont = False
    Font.Height = -15
    TabOrder = 2
  end
  object UniEdit2: TUniEdit
    Left = 200
    Top = 104
    Width = 145
    PasswordChar = '*'
    TabOrder = 3
  end
  object UniButton1: TUniButton
    Left = 270
    Top = 160
    Width = 75
    Height = 25
    Caption = #30331#24405
    TabOrder = 4
    Default = True
    OnClick = UniButton1Click
  end
  object UniButton2: TUniButton
    Left = 128
    Top = 160
    Width = 75
    Height = 25
    Caption = #21462#28040
    TabOrder = 5
    OnClick = UniButton2Click
  end
end
