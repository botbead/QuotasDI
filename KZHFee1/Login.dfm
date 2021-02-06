object UniLoginForm1: TUniLoginForm1
  Left = 0
  Top = 0
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  ClientHeight = 400
  ClientWidth = 700
  Caption = ''
  BorderStyle = bsNone
  Position = poDesktopCenter
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  AlignmentControl = uniAlignmentClient
  ClientEvents.UniEvents.Strings = (
    
      'window.beforeInit=function window.beforeInit(sender, config)'#13#10'{'#13 +
      #10'   config.baseCls = '#39'UniLoginForm1'#39';'#13#10'}'
    
      'form.beforeInit=function form.beforeInit(sender, config)'#13#10'{'#13#10'  c' +
      'onfig.bodyCls = '#39'UniloginFormPanel'#39';'#13#10'}')
  Layout = 'hbox'
  PixelsPerInch = 96
  TextHeight = 13
  object UniPanel1: TUniPanel
    Left = 0
    Top = 0
    Width = 369
    Height = 400
    Hint = ''
    TabOrder = 0
    BorderStyle = ubsNone
    Caption = ''
    Color = clWhite
    LayoutConfig.Flex = 1
    LayoutConfig.Height = '100%'
    object UniImage3: TUniImage
      Left = 116
      Top = 40
      Width = 155
      Height = 155
      Hint = ''
      Enabled = False
      Visible = False
      Stretch = True
    end
    object UniLabel5: TUniLabel
      Left = 78
      Top = 152
      Width = 231
      Height = 39
      Hint = ''
      Caption = #19968#26495#36890#26381#21153#24179#21488
      ParentFont = False
      Font.Color = 12280084
      Font.Height = -32
      Font.Style = [fsBold]
      TabOrder = 2
    end
    object UniLabel6: TUniLabel
      Left = 111
      Top = 199
      Width = 180
      Height = 16
      Hint = ''
      Caption = #23665#19996#24314#20139#25945#32946#31185#25216#26377#38480#20844#21496
      ParentFont = False
      Font.Color = 9276813
      Font.Height = -13
      TabOrder = 3
    end
    object UniPanel5: TUniPanel
      Left = 1
      Top = 371
      Width = 360
      Height = 1
      Hint = ''
      TabOrder = 4
      BorderStyle = ubsNone
      Caption = ''
      Color = 16440540
    end
    object UniLabel8: TUniLabel
      Left = 225
      Top = 384
      Width = 130
      Height = 13
      Hint = ''
      Caption = #26381#21153#28909#32447#65306'0533-8795237'
      ParentFont = False
      Font.Color = 9276813
      TabOrder = 5
    end
    object UniLabel7: TUniLabel
      Left = 10
      Top = 384
      Width = 101
      Height = 13
      Hint = ''
      Caption = #40065'ICP'#22791'19062511'#21495
      ParentFont = False
      Font.Color = 9276813
      TabOrder = 6
    end
  end
  object UniPanel2: TUniPanel
    Left = 400
    Top = 0
    Width = 300
    Height = 400
    Hint = ''
    TabOrder = 1
    ClientEvents.UniEvents.Strings = (
      
        'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.cls ' +
        '= '#39'pnlRight'#39';'#13#10'}')
    BorderStyle = ubsNone
    Caption = ''
    Color = clNone
    LayoutConfig.Height = '100%'
    object UniLabel1: TUniLabel
      Left = 55
      Top = 40
      Width = 32
      Height = 19
      Hint = ''
      Caption = #30331#24405
      ParentFont = False
      Font.Color = clWhite
      Font.Height = -16
      TabOrder = 1
    end
    object UniLabel2: TUniLabel
      Left = 55
      Top = 65
      Width = 120
      Height = 14
      Hint = ''
      Caption = #27426#36814#20351#29992#24314#20139#25945#32946#26381#21153
      ParentFont = False
      Font.Color = clWhite
      Font.Height = -12
      TabOrder = 2
    end
    object UniPanel3: TUniPanel
      Left = 55
      Top = 195
      Width = 200
      Height = 24
      Hint = ''
      TabOrder = 3
      ClientEvents.UniEvents.Strings = (
        
          'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.styl' +
          'e={'#39'border-bottom'#39':'#39'1px solid #73b0ed'#39'};'#13#10'}')
      BorderStyle = ubsNone
      Caption = ''
      Color = clNone
      object UniEdit1: TUniEdit
        Left = 0
        Top = 0
        Width = 187
        Hint = ''
        Text = ''
        ParentFont = False
        Font.Color = clWhite
        Font.Height = -13
        TabOrder = 1
        EmptyText = #24744#30340#29992#25143#21517#25110#37038#31665
        ClientEvents.UniEvents.Strings = (
          
            'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.cls=' +
            #39'loginInput'#39';'#13#10'}')
      end
      object UniImage1: TUniImage
        Left = 188
        Top = 4
        Width = 12
        Height = 12
        Hint = ''
        Stretch = True
        Url = 'files/images/user.svg'
      end
    end
    object UniPanel4: TUniPanel
      Left = 55
      Top = 246
      Width = 200
      Height = 24
      Hint = ''
      TabOrder = 4
      ClientEvents.UniEvents.Strings = (
        
          'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.styl' +
          'e={'#39'border-bottom'#39':'#39'1px solid #73b0ed'#39'};'#13#10'}')
      BorderStyle = ubsNone
      Caption = ''
      Color = clNone
      object UniImage2: TUniImage
        Left = 188
        Top = 4
        Width = 12
        Height = 12
        Hint = ''
        Stretch = True
        Url = 'files/images/key.svg'
      end
      object UniEdit2: TUniEdit
        Left = 0
        Top = 0
        Width = 187
        Hint = ''
        PasswordChar = '*'
        Text = ''
        ParentFont = False
        Font.Color = clWhite
        Font.Height = -13
        TabOrder = 2
        EmptyText = #23494#30721
        ClientEvents.UniEvents.Strings = (
          
            'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.cls=' +
            #39'loginInput'#39';'#13#10'}')
      end
    end
    object UniButton1: TUniButton
      Left = 188
      Top = 310
      Width = 63
      Height = 25
      Hint = ''
      Caption = #30331#24405
      TabOrder = 5
      Default = True
      ClientEvents.UniEvents.Strings = (
        
          'beforeInit=function beforeInit(sender, config)'#13#10'{'#13#10'  config.cls=' +
          #39'btnLogin'#39';'#13#10'  //config.iconCls='#39'btnLoginIcon'#39';'#13#10'  //config.icon' +
          '='#39'files/images/arrow.svg'#39';'#13#10'}')
      OnClick = UniButton1Click
    end
    object UniLabel4: TUniLabel
      Left = 120
      Top = 316
      Width = 26
      Height = 13
      Cursor = crHandPoint
      Hint = ''
      Caption = #27880#20876
      ParentFont = False
      Font.Color = clWhite
      Font.Style = [fsBold]
      TabOrder = 6
      OnClick = UniLabel4Click
    end
    object UniLabel3: TUniLabel
      Left = 55
      Top = 316
      Width = 72
      Height = 13
      Hint = ''
      Caption = #36824#27809#26377#36134#21495#65311
      ParentFont = False
      Font.Color = 15584174
      TabOrder = 7
    end
  end
end
