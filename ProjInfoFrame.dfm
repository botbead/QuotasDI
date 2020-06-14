object UniFrame1: TUniFrame1
  Left = 0
  Top = 0
  Width = 833
  Height = 628
  OnCreate = UniFrameCreate
  TabOrder = 0
  object UniLabel1: TUniLabel
    Left = 61
    Top = 72
    Width = 48
    Height = 13
    Caption = #24037#31243#24207#21495
    TabOrder = 0
  end
  object UniLabel2: TUniLabel
    Left = 61
    Top = 112
    Width = 48
    Height = 13
    Caption = #24037#31243#22270#21495
    TabOrder = 1
  end
  object UniLabel3: TUniLabel
    Left = 61
    Top = 152
    Width = 48
    Height = 13
    Caption = #35774#35745#38454#27573
    TabOrder = 2
  end
  object UniLabel4: TUniLabel
    Left = 61
    Top = 192
    Width = 48
    Height = 13
    Caption = #23454#26045#24773#20917
    TabOrder = 3
  end
  object UniLabel5: TUniLabel
    Left = 61
    Top = 232
    Width = 68
    Height = 13
    Caption = #39044#31639#37329#39069'('#19975')'
    TabOrder = 4
  end
  object UniButton1: TUniButton
    Left = 243
    Top = 285
    Width = 75
    Height = 25
    Caption = #20462#25913
    TabOrder = 5
  end
  object UniDBGrid1: TUniDBGrid
    Left = 372
    Top = 45
    Width = 401
    Height = 281
    DataSource = UniMainModule.ds_proj_task
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgCheckSelectCheckOnly, dgConfirmDelete, dgMultiSelect, dgAutoRefreshRow, dgRowNumbers]
    LoadMask.Message = 'Loading data...'
    TabOrder = 6
    Summary.Enabled = True
    Columns = <
      item
        FieldName = 'task'
        Title.Caption = #20316#19994
        Width = 64
        Editor = UniEdit6
        DisplayMemo = True
      end
      item
        FieldName = 'task_quota'
        Title.Caption = #27604#20363
        Width = 64
        ShowSummary = True
      end
      item
        FieldName = 'projNo'
        Title.Caption = 'projNo'
        Width = 64
        Visible = False
      end>
  end
  object UniDBNavigator1: TUniDBNavigator
    Left = 372
    Top = 332
    Width = 273
    Height = 25
    DataSource = UniMainModule.ds_proj_task
    TabOrder = 7
  end
  object UniEdit6: TUniEdit
    Left = 212
    Top = 228
    Width = 121
    Visible = False
    TabOrder = 8
  end
  object UniEdit1: TUniEdit
    Left = 142
    Top = 68
    Width = 191
    TabOrder = 9
  end
  object UniEdit2: TUniEdit
    Left = 142
    Top = 108
    Width = 191
    TabOrder = 10
  end
  object UniEdit3: TUniEdit
    Left = 142
    Top = 149
    Width = 191
    TabOrder = 11
  end
  object UniEdit4: TUniEdit
    Left = 142
    Top = 186
    Width = 191
    TabOrder = 12
  end
  object UniEdit5: TUniEdit
    Left = 142
    Top = 228
    Width = 191
    TabOrder = 13
  end
  object UniDBGrid2: TUniDBGrid
    Left = 60
    Top = 397
    Width = 713
    Height = 160
    DataSource = UniMainModule.ds_quotas
    LoadMask.Message = 'Loading data...'
    TabOrder = 14
    Columns = <
      item
        FieldName = 'employee'
        Title.Caption = #21592#24037
        Width = 64
        DisplayMemo = True
      end
      item
        FieldName = 'work_employee_quota'
        Title.Caption = #27604#20363
        Width = 64
      end
      item
        FieldName = 'work'
        Title.Caption = #20219#21153#25551#36848
        Width = 64
        DisplayMemo = True
      end
      item
        FieldName = 'projNo'
        Title.Caption = 'projNo'
        Width = 64
        Visible = False
      end
      item
        FieldName = 'task'
        Title.Caption = 'task'
        Width = 64
        Visible = False
      end>
  end
  object UniDBNavigator2: TUniDBNavigator
    Left = 60
    Top = 563
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_quotas
    TabOrder = 15
  end
end
