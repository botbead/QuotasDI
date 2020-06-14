object UniMainModule: TUniMainModule
  OldCreateOrder = False
  OnCreate = UniGUIMainModuleCreate
  Theme = 'crisp'
  MonitoredKeys.Keys = <>
  ServerMessages.LoadingMessage = #27491#22312#21152#36733'...'
  ServerMessages.TerminateMessage = #20250#35805#24050#32467#26463
  Height = 561
  Width = 786
  object SQLiteUniProvider1: TSQLiteUniProvider
    Left = 224
    Top = 312
  end
  object UniConnection1: TUniConnection
    Left = 96
    Top = 320
  end
  object UniQuery1: TUniQuery
    Connection = UniConnection1
    Left = 320
    Top = 329
  end
  object UniScript1: TUniScript
    Connection = UniConnection1
    Left = 336
    Top = 280
  end
  object uniq_proj_task: TUniQuery
    Connection = UniConnection1
    AfterExecute = uniq_proj_taskAfterExecute
    AfterUpdateExecute = uniq_proj_taskAfterUpdateExecute
    BeforeInsert = uniq_proj_taskBeforeInsert
    AfterInsert = uniq_proj_taskAfterInsert
    Left = 32
    Top = 16
  end
  object ds_proj_task: TUniDataSource
    DataSet = uniq_proj_task
    Left = 128
    Top = 16
  end
  object uniq_proj_info: TUniQuery
    Connection = UniConnection1
    AfterInsert = uniq_proj_infoAfterInsert
    Left = 280
    Top = 16
  end
  object ds_proj_info: TUniDataSource
    DataSet = uniq_proj_info
    Left = 384
    Top = 16
  end
  object uniq_quotas: TUniQuery
    Connection = UniConnection1
    AfterUpdateExecute = uniq_quotasAfterUpdateExecute
    Left = 296
    Top = 136
  end
  object ds_quotas: TUniDataSource
    DataSet = uniq_quotas
    Left = 376
    Top = 136
  end
  object uniq_sum_quotas: TUniQuery
    Connection = UniConnection1
    Left = 56
    Top = 152
  end
  object ds_sum_quotas: TUniDataSource
    DataSet = uniq_sum_quotas
    Left = 152
    Top = 152
  end
  object UniQuery2: TUniQuery
    Connection = UniConnection1
    Left = 392
    Top = 328
  end
  object uniq_all_quotas: TUniQuery
    Connection = UniConnection1
    Left = 304
    Top = 208
  end
  object ds_all_quotas: TUniDataSource
    DataSet = uniq_all_quotas
    Left = 392
    Top = 208
  end
  object uniq_salary_sum: TUniQuery
    Connection = UniConnection1
    Left = 56
    Top = 232
  end
  object ds_salary_sum: TUniDataSource
    DataSet = uniq_salary_sum
    Left = 144
    Top = 232
  end
  object uniq_users: TUniQuery
    Connection = UniConnection1
    Left = 560
    Top = 24
  end
  object ds_users: TUniDataSource
    DataSet = uniq_users
    Left = 640
    Top = 24
  end
  object uniq_emp: TUniQuery
    Connection = UniConnection1
    Left = 560
    Top = 88
  end
  object ds_emp: TUniDataSource
    DataSet = uniq_emp
    Left = 640
    Top = 88
  end
  object uniq_fixed_expenses: TUniQuery
    Connection = UniConnection1
    Left = 568
    Top = 160
  end
  object ds_fixed_expense: TUniDataSource
    DataSet = uniq_fixed_expenses
    Left = 672
    Top = 160
  end
end
