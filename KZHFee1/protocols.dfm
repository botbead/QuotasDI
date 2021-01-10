object UniForm1: TUniForm1
  Left = 0
  Top = 0
  ClientHeight = 502
  ClientWidth = 804
  Caption = ''
  BorderStyle = bsNone
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  AlignmentControl = uniAlignmentClient
  ClientEvents.UniEvents.Strings = (
    
      'window.beforeInit=function window.beforeInit(sender, config)'#13#10'{'#13 +
      #10'  config.baseCls = '#39'UniLoginForm1'#39';'#13#10'}'
    
      'form.beforeInit=function form.beforeInit(sender, config)'#13#10'{'#13#10'  c' +
      'onfig.bodyCls = '#39'UniloginFormPanel'#39';'#13#10'}')
  OnCreate = UniFormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object UniImage2: TUniImage
    Left = 772
    Top = 8
    Width = 24
    Height = 24
    Cursor = crHandPoint
    Hint = ''
    Center = True
    Stretch = True
    Proportional = True
    Url = 'files/images/cross_646197.svg'
    OnClick = UniImage2Click
  end
  object UniMemo1: TUniMemo
    Left = 32
    Top = 64
    Width = 744
    Height = 409
    Hint = ''
    ParentFont = False
    Font.Height = -13
    TabOrder = 1
  end
end
