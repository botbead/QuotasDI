object UniServerModule: TUniServerModule
  OldCreateOrder = False
  OnCreate = UniGUIServerModuleCreate
  TempFolder = 'temp\'
  Port = 80
  Title = ' '
  SuppressErrors = []
  Bindings = <>
  CustomCSS.Strings = (
    '#ext-element-1{'
    
      ' background: url(files/images/bg.jpg) no-repeat center center fi' +
      'xed;'
    ' background-size: cover;'
    '}'
    ''
    '.pnlRight{'
    ' background: rgba(32,124,229,1);'
    
      ' background: -moz-linear-gradient(left, rgba(32,124,229,1) 0%, r' +
      'gba(73,155,234,1) 100%);'
    
      ' background: -webkit-gradient(left top, right top, color-stop(0%' +
      ', rgba(32,124,229,1)), color-stop(100%, rgba(73,155,234,1)));'
    
      ' background: -webkit-linear-gradient(left, rgba(32,124,229,1) 0%' +
      ', rgba(73,155,234,1) 100%);'
    
      ' background: -o-linear-gradient(left, rgba(32,124,229,1) 0%, rgb' +
      'a(73,155,234,1) 100%);'
    
      ' background: -ms-linear-gradient(left, rgba(32,124,229,1) 0%, rg' +
      'ba(73,155,234,1) 100%);'
    
      ' background: linear-gradient(to right, rgba(32,124,229,1) 0%, rg' +
      'ba(73,155,234,1) 100%);'
    
      ' filter: progid:DXImageTransform.Microsoft.gradient( startColors' +
      'tr='#39'#207ce5'#39', endColorstr='#39'#499bea'#39', GradientType=1 );'
    '}'
    ''
    '.UniLoginForm1{'
    ' -webkit-box-shadow: 0px 10px 20px 0px rgba(0,0,0,0.49);'
    ' -moz-box-shadow: 0px 10px 20px 0px rgba(0,0,0,0.49);'
    ' box-shadow: 0px 10px 20px 0px rgba(0,0,0,0.49);'
    '}'
    ''
    '.UniLoginForm1 .x-window-body{'
    '}'
    ''
    '.UniloginFormPanel{'
    ' background-color: #fff !important;'
    ' border-radius: 0px;'
    ' border: 0px solid #fff !important;'
    '}'
    ''
    '.loginInput .x-form-cb-label-default, .x-form-text-default { '
    ' font-size: 11px;'
    ' background: none;'
    '}'
    '.loginInput .x-form-text-wrap-default {'
    ' border-width: 0px;'
    '}'
    '.loginInput .x-form-empty-field{'
    ' -webkit-text-fill-color: #aecbed;'
    '}'
    ''
    '.btnLogin{'
    ' border-radius: 25px; '
    '}'
    '.btnLoginIcon{'
    ' background-size: 14px auto;'
    '}'
    ''
    '.MainFormTopPanel'
    '{'
    ' background: rgba(73,155,234,1);'
    
      ' background: -moz-linear-gradient(left, rgba(73,155,234,1) 0%, r' +
      'gba(32,124,229,1) 100%);'
    
      ' background: -webkit-gradient(left top, right top, color-stop(0%' +
      ', rgba(73,155,234,1)), color-stop(100%, rgba(32,124,229,1)));'
    
      ' background: -webkit-linear-gradient(left, rgba(73,155,234,1) 0%' +
      ', rgba(32,124,229,1) 100%);'
    
      ' background: -o-linear-gradient(left, rgba(73,155,234,1) 0%, rgb' +
      'a(32,124,229,1) 100%);'
    
      ' background: -ms-linear-gradient(left, rgba(73,155,234,1) 0%, rg' +
      'ba(32,124,229,1) 100%);'
    
      ' background: linear-gradient(to right, rgba(73,155,234,1) 0%, rg' +
      'ba(32,124,229,1) 100%);'
    
      ' filter: progid:DXImageTransform.Microsoft.gradient( startColors' +
      'tr='#39'#499bea'#39', endColorstr='#39'#207ce5'#39', GradientType=1 );'
    '}'
    ''
    '.MainFormMiddlePanel'
    '{'
    ' background-color: #d9e0ea;'
    '}'
    ''
    '.productBackgroud'
    '{'
    ' background-color: #f3f4f8;'
    '}'
    ''
    '.productBarHead'
    '{'
    ' background: #7a96bb;'
    '}'
    ''
    '.cardStyle'
    '{'
    ' border-radius: 10px 10px 10px 10px;'
    ' -moz-border-radius: 10px 10px 10px 10px;'
    ' -webkit-border-radius: 10px 10px 10px 10px;'
    ' border: 0px solid #000000;'
    ' -webkit-box-shadow: 0px 0px 8px 0px rgba(185,187,199,1);'
    ' -moz-box-shadow: 0px 0px 8px 0px rgba(185,187,199,1);'
    ' box-shadow: 0px 0px 8px 0px rgba(185,187,199,1);'
    '}'
    ''
    '.redline'
    '{'
    ' text-decoration: line-through;'
    ' text-decoration-color: red;'
    '}'
    ''
    '.example_f {'
    'color: #20bf6b !important;'
    'text-transform: uppercase;'
    'background: #ffffff;'
    'padding: 20px;'
    'border: 4px solid #20bf6b !important;'
    'border-radius: 6px;'
    'display: inline-block;'
    'transition: all 0.3s ease 0s;'
    '}'
    '.example_f:hover {'
    'color: #494949 !important;'
    'border-radius: 50px;'
    'border-color: #494949 !important;'
    'transition: all 0.3s ease 0s;'
    '}')
  ServerMessages.LoadingMessage = #21162#21147#21152#36733#20013'...'
  SSL.SSLOptions.RootCertFile = 'root.pem'
  SSL.SSLOptions.CertFile = 'cert.pem'
  SSL.SSLOptions.KeyFile = 'key.pem'
  SSL.SSLOptions.Method = sslvTLSv1_1
  SSL.SSLOptions.SSLVersions = [sslvTLSv1_1]
  SSL.SSLOptions.Mode = sslmUnassigned
  SSL.SSLOptions.VerifyMode = []
  SSL.SSLOptions.VerifyDepth = 0
  ConnectionFailureRecovery.ErrorMessage = 'Connection Error'
  ConnectionFailureRecovery.RetryMessage = 'Retrying...'
  Height = 396
  Width = 540
  object MySQLUniProvider1: TMySQLUniProvider
    Left = 464
    Top = 40
  end
  object UniConnection1: TUniConnection
    Left = 464
    Top = 112
  end
  object UniScript1: TUniScript
    Connection = UniConnection1
    Left = 464
    Top = 176
  end
end
