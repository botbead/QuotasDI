object UniForm7: TUniForm7
  Left = 0
  Top = 0
  ClientHeight = 431
  ClientWidth = 768
  Caption = #22312#32844#21592#24037#28165#21333
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  DesignSize = (
    768
    431)
  PixelsPerInch = 96
  TextHeight = 13
  object UniDBGrid1: TUniDBGrid
    Left = 24
    Top = 16
    Width = 721
    Height = 337
    DataSource = UniMainModule.ds_emp
    LoadMask.Message = #21152#36733#25968#25454'...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    Columns = <
      item
        FieldName = 'empno'
        Title.Caption = #24037#21495'*'
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'name'
        Title.Caption = #22995#21517'*'
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'department'
        Title.Caption = #37096#38376
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'speciality'
        Title.Caption = #19987#19994
        Width = 150
        Editor = UniEdit1
        DisplayMemo = True
      end
      item
        FieldName = 'kpi_current'
        Title.Caption = #24403#21069#21097#20313#20540#65288#20803#65289'*'
        Width = 100
      end>
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 24
    Top = 359
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_emp
    Anchors = [akLeft, akBottom]
    TabOrder = 1
  end
  object UniButton1: TUniButton
    Left = 670
    Top = 393
    Width = 75
    Height = 25
    Caption = #20851#38381
    Anchors = [akRight, akBottom]
    TabOrder = 2
    OnClick = UniButton1Click
  end
  object UniHiddenPanel1: TUniHiddenPanel
    Left = 432
    Top = 72
    Width = 160
    Height = 256
    Visible = True
    object UniEdit1: TUniEdit
      Left = 28
      Top = 104
      Width = 121
      TabOrder = 1
    end
  end
end
