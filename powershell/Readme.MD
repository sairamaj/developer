# Select with calculated properties
Get-Service | Select-Object -Property *,@{Name = 'PathName'; Expression = { $serviceName = $_.Name; (@($wmiServices).where({ $_.Name -eq $serviceName })).PathName }}

You give hashtable with name and expression as key value pairs.
