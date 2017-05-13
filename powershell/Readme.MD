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


