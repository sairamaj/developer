### finding windows group
``` powershell
$query = "Select * from Win32_Group where Domain=""domainname"" and Name=""groupname"""
get-wmiobject -query  $query
```

### Event log query
``` powershell
get-eventlog Application -newest 1000| where {$_.Source -eq "SourceName" -and $_.EntryType -eq "Warning"} | %{$_.Message} |out-file c:\temp\out.txt
```
### Check whether a user is valid windows user or not
``` powershell
function Get-FullName
{
  param([string]$userName)

  $strFilter = "(&(objectCategory=User)(samAccountName=$userName))"

  $properties = [System.String[]] { "fullname" };
  $objSearcher = New-Object System.DirectoryServices.DirectorySearcher
  $objSearcher.SearchScope = [System.DirectoryServices.SearchScope]::Subtree;
  $objSearcher.Filter = $strFilter
  $objSearcher.PropertiesToLoad.AddRange($properties);

  $objResult = $objSearcher.FindOne()
  if($objResult -eq $null )
  {
    $false
  }
  else
  {
      $directoryEntry = $objResult.GetDirectoryEntry();
      # $directoryEntry.Properties["name"].Value
      $true
  }
}

Get-FullName "usernamehere"
```

## Poweshell class

```powershell
class TestResult
{
    [datetime]$dateTime
    [hashtable]$responses
}
```

#### using -split option to remove white spaces
```powershell
  ("abc   xyz" -split " {2,}")[1]
```
#### transforming a string
```powershell
(Get-content .\capitals.txt)  | % { ($_ -split "`t")[0] + " capital is " + ($_ -split "`t")[1]}
```

#### ignoring the certificate errors.
```powershell
add-type @"
    using System.Net;
    using System.Security.Cryptography.X509Certificates;
    public class TrustAllCertsPolicy : ICertificatePolicy {
        public bool CheckValidationResult(
            ServicePoint srvPoint, X509Certificate certificate,
            WebRequest request, int certificateProblem) {
            return true;
        }
    }
"@
[System.Net.ServicePointManager]::CertificatePolicy = New-Object TrustAllCertsPolicy
```
### Script root directory
```powershell
$RootDirectory = split-path $SCRIPT:MyInvocation.MyCommand.Path -parent
```

### Specifying validation set on input parameters.
```powershell
param(
    [Parameter()]
    [ValidateSet('foo','bar','baz')]
    [string[]]
    $Item
)
```
### adding xml in powershell
```powershell
    $configHttpHandlerElement = $doc.CreateElement("add")
    $nameAttribute = $doc.CreateAttribute("name")
    $nameAttribute.Value = "Configuration"
    $configHttpHandlerElement.Attributes.Append($nameAttribute)
```    
### removing xml in powershell
```powershell
  $node.RemoveChild($configHandler)
```

### Get-Unique
* Use -AsString (on objects to get unique items for given path.)

### skip last in array
```powershell
    $List = "A","B","C","1","2","3";
    ($List[0..($List.Length-2)] -join '') + ';';
```


