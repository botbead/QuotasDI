object UniForm4: TUniForm4
  Left = 0
  Top = 0
  ClientHeight = 438
  ClientWidth = 769
  Caption = #29992#25143#31649#29702
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  DesignSize = (
    769
    438)
  PixelsPerInch = 96
  TextHeight = 13
  object UniDBGrid1: TUniDBGrid
    Left = 32
    Top = 8
    Width = 705
    Height = 345
    DataSource = UniMainModule.ds_users
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgAutoRefreshRow]
    LoadMask.Message = #21152#36733#25968#25454'...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    Columns = <
      item
        FieldName = 'usrNo'
        Title.Caption = #32534#21495
        Width = 100
      end
      item
        FieldName = 'name'
        Title.Caption = #29992#25143
        Width = 100
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'department'
        Title.Caption = #31185#23460
        Width = 150
        Visible = False
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'password'
        Title.Caption = #23494#30721
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'priority'
        Title.Caption = #26435#32423
        Width = 100
        Editor = UniComboBox1
      end>
  end
  object UniHiddenPanel1: TUniHiddenPanel
    Left = 528
    Top = 72
    Width = 160
    Height = 256
    Visible = True
    object UniComboBox1: TUniComboBox
      Left = 12
      Top = 64
      Width = 145
      Style = csDropDownList
      Text = '2'
      Items.Strings = (
        '1'
        '2'
        '3')
      ItemIndex = 1
      TabOrder = 1
      IconItems = <>
    end
    object UniEdit1: TUniEdit
      Left = 32
      Top = 168
      Width = 121
      TabOrder = 2
    end
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 32
    Top = 361
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_users
    Anchors = [akLeft, akBottom]
    TabOrder = 2
  end
  object UniButton1: TUniButton
    Left = 662
    Top = 392
    Width = 75
    Height = 25
    Caption = #20851#38381
    Anchors = [akRight, akBottom]
    TabOrder = 3
    OnClick = UniButton1Click
  end
end
