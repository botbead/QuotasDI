object UniPagePayment: TUniPagePayment
  Left = 0
  Top = 0
  ClientHeight = 690
  ClientWidth = 1024
  Caption = ''
  BorderStyle = bsNone
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  AlignmentControl = uniAlignmentClient
  ClientEvents.UniEvents.Strings = (
    
      'window.beforeInit=function window.beforeInit(sender, config)'#13#10'{'#13 +
      #10'   config.baseCls = '#39'UniLoginForm1'#39';'#13#10'}'
    
      'form.beforeInit=function form.beforeInit(sender, config)'#13#10'{'#13#10'   ' +
      'config.bodyCls = '#39'UniloginFormPanel'#39';'#13#10'}')
  Layout = 'vbox'
  OnCreate = UniFormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object UniContainerPanel1: TUniContainerPanel
    Left = 8
    Top = 0
    Width = 1008
    Height = 41
    Hint = ''
    ParentColor = False
    TabOrder = 1
    LayoutConfig.Width = '100%'
    object UniLabel1: TUniLabel
      Left = 19
      Top = 3
      Width = 46
      Height = 13
      Hint = ''
      Caption = 'UniLabel1'
      TabOrder = 1
    end
    object UniImage2: TUniImage
      Left = 984
      Top = 6
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
  end
  object UniURLFrame1: TUniURLFrame
    Left = 8
    Top = 40
    Width = 1008
    Height = 642
    Hint = ''
    LayoutConfig.Flex = 1
    LayoutConfig.Width = '100%'
    TabOrder = 0
    ParentColor = False
    Color = clBtnFace
    OnFrameLoaded = UniURLFrame1FrameLoaded
  end
end
