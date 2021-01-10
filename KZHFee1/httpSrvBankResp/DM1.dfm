object DataModule2: TDataModule2
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 440
  Width = 522
  object IdHTTPServer1: TIdHTTPServer
    Bindings = <>
    OnCommandGet = IdHTTPServer1CommandGet
    Left = 248
    Top = 208
  end
end
