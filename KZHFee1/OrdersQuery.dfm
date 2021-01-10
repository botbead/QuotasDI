object UniForm2: TUniForm2
  Left = 0
  Top = 0
  ClientHeight = 659
  ClientWidth = 1024
  Caption = 'UniForm2'
  OnShow = UniFormShow
  BorderStyle = bsNone
  OldCreateOrder = False
  MonitoredKeys.Keys = <>
  ClientEvents.UniEvents.Strings = (
    
      'window.beforeInit=function window.beforeInit(sender, config)'#13#10'{'#13 +
      #10'   config.baseCls = '#39'UniLoginForm1'#39';'#13#10'}'
    
      'form.beforeInit=function form.beforeInit(sender, config)'#13#10'{'#13#10'   ' +
      'config.bodyCls = '#39'UniloginFormPanel'#39';'#13#10'}')
  OnCreate = UniFormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object UniImage2: TUniImage
    Left = 995
    Top = 9
    Width = 24
    Height = 24
    Cursor = crHandPoint
    Hint = ''
    Center = True
    Stretch = True
    Picture.Data = {
      0954506E67496D61676589504E470D0A1A0A0000000D49484452000000180000
      00180803000000D7A9CDCA0000000373424954080808DBE14FE0000000097048
      59730000066300000663014D881ABC0000001974455874536F66747761726500
      7777772E696E6B73636170652E6F72679BEE3C1A0000004E504C5445FFFFFF00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000C409E9310000001A74524E5300040B0F162932343738
      3B41434B5E6D7D7F949FB2C9D7DDE1E3A81141F4000000C74944415478DA7552
      D90E823010DC420B05540A688CFFFF7546413072B605A18057DC79D82633DBBD
      09CCA01EB51948AD6A351364B6A1AB946C80334ADB6278094CE8BC5FBE5AC2CE
      E522EC7859C21B41D0DC8DC0A254C327ECE4264781ECAB12BE11F8D78180B032
      F845DCE784269729AFA73B4339763D557048C9D6490D11E7CDF870911987A423
      515F18572E46C59809A135A6AE605560E5C1F7C9E9BCB6C605AC3C58475C4043
      A1C9D172970637B235AE2E7B2C0DA223C187888E1D5F14BE5AFC18FE9DCF1304
      BA76B7F9850AAD0000000049454E44AE426082}
    Proportional = True
    OnClick = UniImage2Click
  end
  object UniDBGrid1: TUniDBGrid
    Left = 23
    Top = 40
    Width = 978
    Height = 593
    Hint = ''
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColumnMove, dgColLines, dgRowLines, dgAutoRefreshRow, dgRowNumbers]
    ReadOnly = True
    LoadMask.Message = #21152#36733#25968#25454'...'
    ForceFit = True
    TabOrder = 1
    Columns = <
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end
      item
        ShowToolTipAlways = False
        Title.Caption = ' '
        Width = 64
      end>
  end
end
