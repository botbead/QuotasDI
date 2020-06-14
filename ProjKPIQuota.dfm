object UniForm2: TUniForm2
  Left = 0
  Top = 0
  ClientHeight = 540
  ClientWidth = 826
  Caption = #32489#25928#28165#21333
  OnShow = UniFormShow
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  PixelsPerInch = 96
  TextHeight = 13
  object UniDBGrid1: TUniDBGrid
    Left = 56
    Top = 48
    Width = 705
    Height = 417
    DataSource = UniMainModule.ds_sum_quotas
    LoadMask.Message = #27491#22312#21152#36733#25968#25454'...'
    TabOrder = 0
    Summary.Enabled = True
    OnColumnSummary = UniDBGrid1ColumnSummary
    OnColumnSummaryResult = UniDBGrid1ColumnSummaryResult
    Columns = <
      item
        FieldName = 'employee'
        Title.Caption = #21592#24037
        Width = 120
        ReadOnly = True
        Sortable = True
        DisplayMemo = True
        ShowSummary = True
      end
      item
        FieldName = 'employee_quota_sum'
        Title.Caption = #27604#20363
        Width = 90
        ReadOnly = True
        Sortable = True
        ShowSummary = True
      end
      item
        FieldName = 'pay_for_performance'
        Title.Caption = #32489#25928#24037#36164'('#20803')'
        Width = 120
        ReadOnly = True
        Sortable = True
        ShowSummary = True
      end
      item
        FieldName = 'extra_reward'
        Title.Caption = #39069#22806#22870#21169'('#20803')'
        Width = 120
        ShowSummary = True
      end
      item
        FieldName = 'projNo'
        Title.Caption = ' '
        Width = 64
        Visible = False
      end>
  end
  object UniButton1: TUniButton
    Left = 686
    Top = 496
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 1
    OnClick = UniButton1Click
  end
  object UniLabel1: TUniLabel
    Left = 56
    Top = 16
    Width = 48
    Height = 13
    Caption = #24037#31243#24207#21495
    TabOrder = 2
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 56
    Top = 471
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_sum_quotas
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbPost, nbCancel, nbRefresh]
    TabOrder = 3
  end
end
