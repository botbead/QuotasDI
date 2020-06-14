object MainForm: TMainForm
  Left = 0
  Top = 0
  ClientHeight = 608
  ClientWidth = 1035
  Caption = #35774#35745#38498#21592#24037#32489#25928
  OnShow = UniFormShow
  OldCreateOrder = False
  Menu = UniMainMenu1
  MonitoredKeys.Keys = <>
  Layout = 'border'
  OnCreate = UniFormCreate
  OnDestroy = UniFormDestroy
  DesignSize = (
    1035
    608)
  PixelsPerInch = 96
  TextHeight = 13
  object UniStatusBar1: TUniStatusBar
    Left = 0
    Top = 586
    Width = 1035
    Panels = <
      item
        Width = 250
      end
      item
        Width = 250
      end
      item
        Alignment = taRightJustify
        Text = #30001'BotBead'#25552#20379#25216#26415#25903#25345
        Width = 50
      end>
    SizeGrip = False
    Align = alBottom
    ParentColor = False
    Color = clWindow
  end
  object UniPanel1: TUniPanel
    Left = 288
    Top = 543
    Width = 100
    Height = 21
    Visible = False
    Constraints.MaxWidth = 250
    Constraints.MinWidth = 100
    TabOrder = 1
    Layout = 'fit'
    LayoutConfig.Split = True
    LayoutConfig.Region = 'west'
    object UniTreeView1: TUniTreeView
      Left = 16
      Top = 80
      Width = 25
      Height = 41
      Visible = False
      Items.NodeData = {
        0302000000220000000000000000000000FFFFFFFFFFFFFFFF00000000000000
        00000000000102E55D0B7A220000000000000000000000FFFFFFFFFFFFFFFF00
        000000000000000000000001025854E55D}
      Items.FontData = {0102000000FFFFFFFF00000000FFFFFFFF00000000}
      TabOrder = 1
      Color = clWindow
      OnDblClick = UniTreeView1DblClick
    end
  end
  object UniPanel2: TUniPanel
    Left = 943
    Top = 567
    Width = 86
    Height = 13
    Visible = False
    TabOrder = 2
    Layout = 'fit'
    LayoutConfig.Region = 'center'
    object UniPageControl1: TUniPageControl
      Left = 336
      Top = 296
      Width = 49
      Height = 9
      Visible = False
      LayoutConfig.Padding = '5'
      TabOrder = 1
    end
  end
  object UniDBNavigator2: TUniDBNavigator
    Left = 24
    Top = 547
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_quotas
    Anchors = [akLeft, akBottom]
    TabOrder = 3
  end
  object UniDBGrid2: TUniDBGrid
    Left = 24
    Top = 360
    Width = 987
    Height = 181
    DataSource = UniMainModule.ds_quotas
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgAutoRefreshRow]
    LoadMask.Message = #27491#22312#21152#36733#25968#25454'...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 4
    Columns = <
      item
        FieldName = 'employee'
        Title.Caption = #21592#24037
        Width = 110
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
        Width = 110
        Visible = False
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
  object UniDBNavigator1: TUniDBNavigator
    Left = 738
    Top = 308
    Width = 273
    Height = 25
    DataSource = UniMainModule.ds_proj_task
    Anchors = [akTop, akRight]
    TabOrder = 5
  end
  object UniDBGrid1: TUniDBGrid
    Left = 738
    Top = 21
    Width = 273
    Height = 281
    DataSource = UniMainModule.ds_proj_task
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgAutoRefreshRow]
    LoadMask.Message = #27491#22312#21152#36733#25968#25454'...'
    Anchors = [akTop, akRight]
    TabOrder = 6
    OnSelectionChange = UniDBGrid1SelectionChange
    Columns = <
      item
        FieldName = 'task'
        Title.Caption = #20316#19994
        Width = 150
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
  object UniDBGrid3: TUniDBGrid
    Left = 24
    Top = 21
    Width = 681
    Height = 281
    DataSource = UniMainModule.ds_proj_info
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgConfirmDelete, dgAutoRefreshRow]
    LoadMask.Message = #27491#22312#21152#36733#25968#25454'...'
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 7
    OnSelectionChange = UniDBGrid3SelectionChange
    Columns = <
      item
        FieldName = 'projNo'
        Title.Caption = #24037#31243#24207#21495
        Width = 110
        DisplayMemo = True
      end
      item
        FieldName = 'blueprintNo'
        Title.Caption = #24037#31243#22270#21495
        Width = 110
        DisplayMemo = True
      end
      item
        FieldName = 'stage'
        Title.Caption = #35774#35745#38454#27573
        Width = 110
        DisplayMemo = True
      end
      item
        FieldName = 'achievement'
        Title.Caption = #23454#26045#24773#20917
        Width = 100
        DisplayMemo = True
      end
      item
        FieldName = 'amount'
        Title.Caption = ' '#39044#31639#37329#39069'('#19975')'
        Width = 110
      end
      item
        FieldName = 'pay_for_performance'
        Title.Caption = #24037#31243#24635#32489#25928'('#20803')'
        Width = 110
      end>
  end
  object UniDBNavigator3: TUniDBNavigator
    Left = 24
    Top = 308
    Width = 241
    Height = 25
    DataSource = UniMainModule.ds_proj_info
    TabOrder = 8
  end
  object UniHiddenPanel1: TUniHiddenPanel
    Left = 521
    Top = 176
    Width = 160
    Height = 256
    Visible = True
    object UniEdit1: TUniEdit
      Left = 24
      Top = 80
      Width = 121
      TabOrder = 1
    end
  end
  object UniMainMenu1: TUniMainMenu
    Left = 952
    Top = 8
    object N1: TUniMenuItem
      Caption = #24037#31243
      object N2: TUniMenuItem
        Caption = #21333#24037#31243#32489#25928
        OnClick = N2Click
      end
      object N3: TUniMenuItem
        Caption = #32489#25928#27719#24635
        OnClick = N3Click
      end
    end
    object N13: TUniMenuItem
      Caption = #31649#29702
      object N14: TUniMenuItem
        Caption = #29992#25143#31649#29702
        OnClick = N14Click
      end
      object N4: TUniMenuItem
        Caption = #21592#24037#31649#29702
        OnClick = N4Click
      end
      object N5: TUniMenuItem
        Caption = #25903#20986#22266#23450#39033
        OnClick = N5Click
      end
    end
  end
end
