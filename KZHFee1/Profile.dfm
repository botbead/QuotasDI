object UniFormSignUp_1: TUniFormSignUp_1
  Left = 0
  Top = 0
  HorzScrollBar.Smooth = True
  VertScrollBar.Smooth = True
  ClientHeight = 580
  ClientWidth = 930
  Caption = ''
  BorderStyle = bsNone
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  AlignmentControl = uniAlignmentClient
  ClientEvents.UniEvents.Strings = (
    
      'window.beforeInit=function window.beforeInit(sender, config)'#13#10'{'#13 +
      #10'   config.baseCls = '#39'UniLoginForm1'#39';'#13#10'}'
    
      'form.beforeInit=function form.beforeInit(sender, config)'#13#10'{'#13#10'  c' +
      'onfig.bodyCls = '#39'UniloginFormPanel'#39';'#13#10'}')
  OnCreate = UniFormCreate
  OnDestroy = UniFormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object UniImage2: TUniImage
    Left = 906
    Top = 9
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
  object UniLabel1: TUniLabel
    Left = 24
    Top = 31
    Width = 46
    Height = 13
    Hint = ''
    Caption = 'UniLabel1'
    TabOrder = 1
    LayoutConfig.Flex = 1
  end
  object UniLabel2: TUniLabel
    Left = 580
    Top = 55
    Width = 46
    Height = 13
    Hint = ''
    Caption = 'UniLabel1'
    TabOrder = 2
  end
  object UniRadioGroup1: TUniRadioGroup
    Left = 8
    Top = 86
    Width = 1033
    Height = 49
    Hint = ''
    Enabled = False
    Visible = False
    ScreenMask.ShowMessage = False
    ClientEvents.ExtEvents.Strings = (
      
        'boxready=function boxready(sender, width, height, eOpts)'#13#10'{'#13#10'   ' +
        ' if (sender.legend) '#13#10'    {'#13#10'      if (sender.legend.el) '#13#10'     ' +
        ' {'#13#10'         var legend=sender.legend.el;'#13#10'         legend.dom.s' +
        'etAttribute('#39'align'#39', '#39'center'#39'); //left, right'#13#10'         legend.d' +
        'om.style['#39'width'#39']="auto";'#13#10'         legend.dom.style['#39'margin-bot' +
        'tom'#39']="0px";'#13#10'         legend.dom.style['#39'border-bottom'#39']="0px";'#13 +
        #10'    '#13#10'         var legendText=legend.select('#39'.x-fieldset-header' +
        '-text'#39').elements[0];'#13#10'         legendText.style['#39'color'#39']="black"' +
        ';'#13#10'         legendText.style['#39'font-size'#39']="17px";'#13#10'         lege' +
        'ndText.style['#39'font-weight'#39']="bold";'#13#10'         legend.dom.style['#39 +
        'text-align'#39']='#39'center'#39';'#13#10'    }'#13#10'  }'#13#10'}')
    Caption = ''
    TabOrder = 3
    ParentFont = False
    Font.Color = clDefault
    Font.Height = -15
    Vertical = False
    OnChangeValue = UniRadioGroup1ChangeValue
  end
  object UniSimplePanel1: TUniSimplePanel
    Left = 24
    Top = 107
    Width = 905
    Height = 450
    Hint = ''
    ParentColor = False
    TabOrder = 4
    Layout = 'fit'
    object UniContainerPanel_student: TUniContainerPanel
      Left = 3
      Top = 3
      Width = 886
      Height = 380
      Hint = ''
      ParentColor = False
      TabOrder = 1
      object UniComboBox1: TUniComboBox
        Left = 103
        Top = 19
        Width = 753
        Hint = ''
        Text = ''
        TabOrder = 1
        AnyMatch = True
        ClearButton = True
        CacheQueryResults = True
        IconItems = <>
        OnSelect = UniComboBox1Select
        OnChange = UniComboBox1Change
      end
      object UniComboBox2: TUniComboBox
        Left = 103
        Top = 67
        Width = 202
        Hint = ''
        Text = ''
        TabOrder = 2
        IconItems = <>
        OnChange = UniComboBox2Change
      end
      object UniComboBox3: TUniComboBox
        Left = 333
        Top = 67
        Width = 250
        Hint = ''
        Text = ''
        TabOrder = 3
        IconItems = <>
      end
      object UniComboBox4: TUniComboBox
        Left = 607
        Top = 67
        Width = 249
        Hint = ''
        Text = ''
        TabOrder = 4
        IconItems = <>
      end
      object UniEdit1: TUniEdit
        Left = 103
        Top = 205
        Width = 753
        Height = 25
        Hint = ''
        Text = ''
        TabOrder = 5
      end
      object UniEdit2: TUniEdit
        Left = 103
        Top = 253
        Width = 753
        Hint = ''
        Text = ''
        TabOrder = 6
      end
      object UniEdit3: TUniEdit
        Left = 103
        Top = 298
        Width = 753
        Hint = ''
        Text = ''
        TabOrder = 7
      end
      object UniLabel3: TUniLabel
        Left = 32
        Top = 19
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 8
      end
      object UniLabel4: TUniLabel
        Left = 32
        Top = 68
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 9
      end
      object UniLabel5: TUniLabel
        Left = 32
        Top = 206
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 10
      end
      object UniLabel6: TUniLabel
        Left = 32
        Top = 254
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 11
      end
      object UniLabel7: TUniLabel
        Left = 32
        Top = 299
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 12
      end
      object UniLabel9: TUniLabel
        Left = 32
        Top = 343
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 13
      end
      object UniEdit5: TUniEdit
        Left = 103
        Top = 342
        Width = 753
        Hint = ''
        Text = ''
        TabOrder = 14
      end
      object UniEdit4: TUniEdit
        Left = 103
        Top = 111
        Width = 753
        Height = 25
        Hint = ''
        Text = ''
        TabOrder = 15
      end
      object UniLabel8: TUniLabel
        Left = 32
        Top = 112
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 16
      end
      object UniEdit10: TUniEdit
        Left = 103
        Top = 158
        Width = 753
        Height = 25
        Hint = ''
        Text = ''
        TabOrder = 17
      end
      object UniLabel10: TUniLabel
        Left = 32
        Top = 159
        Width = 46
        Height = 13
        Hint = ''
        Caption = 'UniLabel3'
        TabOrder = 18
      end
    end
    object UniContainerPanel_school: TUniContainerPanel
      Left = 505
      Top = 361
      Width = 650
      Height = 366
      Hint = ''
      Visible = False
      ParentColor = False
      TabOrder = 2
      object UniEdit6: TUniEdit
        Left = 103
        Top = 17
        Width = 514
        Height = 25
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 1
      end
      object UniEdit7: TUniEdit
        Left = 103
        Top = 146
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 2
      end
      object UniEdit8: TUniEdit
        Left = 103
        Top = 192
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 3
      end
      object UniLabel11: TUniLabel
        Left = 17
        Top = 19
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 4
      end
      object UniLabel14: TUniLabel
        Left = 17
        Top = 147
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 5
      end
      object UniLabel15: TUniLabel
        Left = 17
        Top = 193
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 6
      end
      object UniLabel16: TUniLabel
        Left = 17
        Top = 243
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 7
      end
      object UniEdit9: TUniEdit
        Left = 103
        Top = 240
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 8
      end
      object UniCheckBox3: TUniCheckBox
        Tag = 101
        Left = 309
        Top = 61
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 9
        OnClick = UniCheckBox3Click
      end
      object UniCheckBox4: TUniCheckBox
        Tag = 102
        Left = 513
        Top = 61
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 10
        OnClick = UniCheckBox4Click
      end
      object UniLabel13: TUniLabel
        Left = 17
        Top = 100
        Width = 52
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel12'
        TabOrder = 11
      end
      object UniCheckBox5: TUniCheckBox
        Left = 103
        Top = 103
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 12
        OnClick = UniCheckBox5Click
      end
      object UniCheckBox6: TUniCheckBox
        Left = 206
        Top = 103
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 13
        OnClick = UniCheckBox6Click
      end
      object UniCheckBox7: TUniCheckBox
        Left = 422
        Top = 103
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 14
        OnClick = UniCheckBox7Click
      end
      object UniCheckBox8: TUniCheckBox
        Left = 309
        Top = 103
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 15
        OnClick = UniCheckBox8Click
      end
      object UniCheckBox2: TUniCheckBox
        Tag = 100
        Left = 103
        Top = 61
        Width = 97
        Height = 17
        Hint = ''
        Visible = False
        Caption = 'UniCheckBox2'
        TabOrder = 16
        OnClick = UniCheckBox2Click
      end
      object UniLabel12: TUniLabel
        Left = 17
        Top = 61
        Width = 52
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel12'
        TabOrder = 17
      end
      object UniLabel19: TUniLabel
        Left = 17
        Top = 289
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 18
      end
      object UniEdit11: TUniEdit
        Left = 103
        Top = 286
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 19
      end
    end
    object UniContainerPanel_agent: TUniContainerPanel
      Left = 171
      Top = 399
      Width = 1043
      Height = 340
      Hint = ''
      Visible = False
      ParentColor = False
      TabOrder = 3
      object UniComboBox6: TUniComboBox
        Left = 103
        Top = 67
        Width = 146
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 1
        IconItems = <>
      end
      object UniEdit12: TUniEdit
        Left = 103
        Top = 109
        Width = 514
        Height = 25
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 2
      end
      object UniEdit13: TUniEdit
        Left = 103
        Top = 158
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 3
      end
      object UniLabel20: TUniLabel
        Left = 32
        Top = 19
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 4
      end
      object UniLabel21: TUniLabel
        Left = 32
        Top = 68
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 5
      end
      object UniLabel22: TUniLabel
        Left = 32
        Top = 110
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 6
      end
      object UniLabel23: TUniLabel
        Left = 32
        Top = 159
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 7
      end
      object UniLabel25: TUniLabel
        Left = 32
        Top = 206
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 8
      end
      object UniEdit15: TUniEdit
        Left = 103
        Top = 203
        Width = 514
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 9
      end
      object UniEdit16: TUniEdit
        Left = 103
        Top = 21
        Width = 514
        Height = 25
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 10
      end
      object UniListBox1: TUniListBox
        Left = 641
        Top = 16
        Width = 394
        Height = 305
        Hint = ''
        Visible = False
        Items.Strings = (
          'dd'
          '44')
        TabOrder = 11
        MultiSelect = True
        ShowCheckBoxes = True
      end
      object UniLabel27: TUniLabel
        Left = 32
        Top = 246
        Width = 46
        Height = 13
        Hint = ''
        Visible = False
        Caption = 'UniLabel3'
        TabOrder = 12
      end
      object UniComboBox5: TUniComboBox
        Left = 103
        Top = 246
        Width = 146
        Hint = ''
        Visible = False
        Text = ''
        TabOrder = 13
        IconItems = <>
      end
    end
  end
  object UniButton1: TUniButton
    Left = 805
    Top = 516
    Width = 75
    Height = 25
    Hint = ''
    Caption = 'UniButton1'
    TabOrder = 5
    OnClick = UniButton1Click
  end
  object UniLabel18: TUniLabel
    Left = 53
    Top = 123
    Width = 52
    Height = 13
    Hint = ''
    Visible = False
    Caption = 'UniLabel18'
    TabOrder = 6
  end
  object UniCheckBox9: TUniCheckBox
    Left = 176
    Top = 63
    Width = 97
    Height = 17
    Hint = ''
    Visible = False
    Caption = 'UniCheckBox9'
    TabOrder = 7
    OnClick = UniCheckBox9Click
  end
  object UniCheckBox10: TUniCheckBox
    Left = 352
    Top = 63
    Width = 97
    Height = 17
    Hint = ''
    Visible = False
    Caption = 'UniCheckBox9'
    TabOrder = 8
    OnClick = UniCheckBox10Click
  end
  object UniCheckBox11: TUniCheckBox
    Left = 529
    Top = 63
    Width = 97
    Height = 17
    Hint = ''
    Visible = False
    Caption = 'UniCheckBox9'
    TabOrder = 9
    OnClick = UniCheckBox11Click
  end
end
