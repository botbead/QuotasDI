object UniForm8: TUniForm8
  Left = 0
  Top = 0
  ClientHeight = 474
  ClientWidth = 798
  Caption = #25903#20986#22266#23450#39033
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  DesignSize = (
    798
    474)
  PixelsPerInch = 96
  TextHeight = 13
  object UniDBGrid1: TUniDBGrid
    Left = 24
    Top = 16
    Width = 752
    Height = 393
    DataSource = UniMainModule.ds_fixed_expense
    LoadMask.Message = #21152#36733#25968#25454'...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    Columns = <
      item
        FieldName = 'item_name'
        Title.Caption = #25903#20986#39033'*'
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'item_expense'
        Title.Caption = #36153#29992#65288#20803#65289'*'
        Width = 150
      end>
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 24
    Top = 415
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_fixed_expense
    Anchors = [akLeft, akBottom]
    TabOrder = 1
  end
  object 关闭: TUniButton
    Left = 701
    Top = 441
    Width = 75
    Height = 25
    Caption = #20851#38381
    Anchors = [akRight, akBottom]
    TabOrder = 2
    OnClick = 关闭Click
  end
  object UniHiddenPanel1: TUniHiddenPanel
    Left = 560
    Top = 72
    Width = 160
    Height = 256
    Visible = True
    object UniEdit1: TUniEdit
      Left = 36
      Top = 112
      Width = 121
      TabOrder = 1
    end
  end
end
