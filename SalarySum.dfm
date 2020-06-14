object UniForm3: TUniForm3
  Left = 0
  Top = 0
  ClientHeight = 543
  ClientWidth = 942
  Caption = #32489#25928#27719#24635
  OnShow = UniFormShow
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  OnCreate = UniFormCreate
  DesignSize = (
    942
    543)
  PixelsPerInch = 96
  TextHeight = 13
  object UniDBGrid1: TUniDBGrid
    Left = 32
    Top = 24
    Width = 881
    Height = 441
    DataSource = UniMainModule.ds_salary_sum
    LoadMask.Message = 'Loading data...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    OnColumnSummary = UniDBGrid1ColumnSummary
    OnColumnSummaryResult = UniDBGrid1ColumnSummaryResult
    Columns = <
      item
        FieldName = 'projNo'
        Title.Caption = #24037#31243#24207#21495
        Width = 110
        DisplayMemo = True
        ShowSummary = True
      end
      item
        FieldName = 'amount'
        Title.Caption = #24037#31243#24635#32489#25928
        Width = 110
        ShowSummary = True
      end>
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 32
    Top = 471
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_salary_sum
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbRefresh]
    Anchors = [akLeft, akBottom]
    TabOrder = 1
  end
  object UniButton1: TUniButton
    Left = 832
    Top = 496
    Width = 75
    Height = 25
    Caption = #20851#38381
    Anchors = [akRight, akBottom]
    TabOrder = 2
    OnClick = UniButton1Click
  end
  object UniButton2: TUniButton
    Left = 712
    Top = 496
    Width = 75
    Height = 25
    Caption = #36755#20986'Excel'
    Anchors = [akRight, akBottom]
    TabOrder = 3
    OnClick = UniButton2Click
  end
end
