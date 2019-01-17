<#
   Don't know from which site: need to findout the url and document here.
#>
Function GetTLSData() # Pulls relevant TLS related data
{ 
 
    Write-host "Collecting Relevant TLS-Related Data..."
   
     $NativeResultsCollection = New-Object System.Object
     
     $RegistryResults = New-Object System.Object
     
     $ResultsArray = @()
     
     $type = [Microsoft.Win32.RegistryHive]::LocalMachine
     
     $reg = [Microsoft.Win32.RegistryKey]::OpenRemoteBaseKey($type, 'localhost')
     
     $ProtocolNames = [System.Security.Authentication.SslProtocols] |
     Get-Member -Static -MemberType Property |
     Where-Object -Filter { @("Default","None" -notcontains $_.Name ) }  # Pulls existing protocols
     
     $ProtocolNameValues = $ProtocolNames | Select-object -Property Name -ExpandProperty Name
        
        If($ProtocolNameValues -ne $null)
        
            {
        
                Foreach($protocol in $ProtocolNameValues)
                    {
                    
                        $protocoltitle = "$protocol Capable"
                    
                        $RegistryResults | Add-Member -type NoteProperty -name $protocoltitle -Value "Yes" -force
                        
                    }
                 
                 If($ProtocolNameValues -notcontains "Tls11")
                    {
                    
                        $RegistryResults | Add-Member -type NoteProperty -name "Tls11 Capable" -Value "No" -force
                        
                    }
                    
                 If($ProtocolNameValues -notcontains "Tls12")
                    {
                    
                        $RegistryResults | Add-Member -type NoteProperty -name "Tls12 Capable" -Value "No" -force
                        
                    }
                    
            }
            
     $type = [Microsoft.Win32.RegistryHive]::LocalMachine
     
     $reg = [Microsoft.Win32.RegistryKey]::OpenRemoteBaseKey($type, 'localhost')
     
     $DotnetregKey = $reg.OpenSubKey("SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Full")
     
     $DotNetVersion = $DotnetregKey.GetValue("Version")
          $DotNetRelease = $DotnetregKey.GetValue("Release")
     $RegistryResults | Add-Member -type NoteProperty -name NETVersion -Value $DotNetVersion -force
     $RegistryResults | Add-Member -type NoteProperty -name NETRelease -Value $DotNetRelease -force
     $TLSregKey = $reg.OpenSubKey("SYSTEM\CurrentControlSet\Control\SecurityProviders\SCHANNEL\Protocols")
     
     $Subkeys = $TLSregKey.GetSubKeyNames()
     
        Foreach($key in $subkeys) #Iterates through protocols found and creates and array of the results
            {
                
                $CurrentPath = "SYSTEM\CurrentControlSet\Control\SecurityProviders\SCHANNEL\Protocols\" + $key
                
                $ResultregKey = $reg.OpenSubKey($CurrentPath)
                
                $ResultSubKeys = $ResultregKey.GetSubKeyNames()
                
                    Foreach($resultkey in $ResultSubKeys)
                        {
                        
                          $ResultCurrentPath = "SYSTEM\CurrentControlSet\Control\SecurityProviders\SCHANNEL\Protocols\" + $key + "\" + $resultkey
                
                          $ResultregKey = $reg.OpenSubKey($ResultCurrentPath)
                          
                          $EnabledValue = $Resultregkey.GetValue("Enabled")
                          
                          
                          
                           If($EnabledValue -eq "1")
                                {
                          
                                    $Enabledresult = "Yes"
                                    
                                }
                                
                             If($EnabledValue -eq "0")
                                {
                          
                                    $Enabledresult = "No"
                                    
                                }
                          
                          If([string]::IsNullOrEmpty($EnabledValue ))
                            {
                            
                                $EnabledResult = "Not Present"
                                
                            }
                          
                          $DisabledByDefaultValue = $Resultregkey.GetValue("DisabledByDefault")
                          
                            If($DisabledByDefaultValue -eq "1")
                                {
                          
                                    $DisabledByDefaultresult = "Yes"
                                    
                                }
                                
                             If($DisabledByDefaultValue -eq "0")
                                {
                          
                                    $DisabledByDefaultresult = "No"
                                    
                                }
                                
                            If([string]::IsNullOrEmpty($DisabledByDefaultValue))
                            {
                            
                                $DisabledByDefaultValue= "Not Present"
                                
                            }
                          
                          $TitleE = $key + " " + $resultkey + " Reg Enabled"
                          
                          $RegistryResults | Add-Member -type NoteProperty -name $TitleE -Value $Enabledresult -force
                          
                          $TitleDBD = $key + " " + $resultkey + " Reg DisabledByDefault"
                          
                          $RegistryResults | Add-Member -type NoteProperty -name $TitleDBD -Value $DisabledByDefaultresult -force
                          
                        }
                     
             }         
            
If($RegistryResults -ne $null)
    {
    
        Write-host "Data Gathering complete on" $server
        
       $RegistryResults
        
    }
 
}
 
[string]$SSLInfo = GetTLSData | out-string

write-host $SSLInfo.ToString()

            if ($SSLInfo -match "TLS 1\.0 Server.*:.*No")
            {
                write-host $computer "TLS 1.0 Server Disabled" -ForegroundColor Red
            } 
                
            

            if ($SSLInfo -match "TLS 1\.0 Client.*:.*No")
            {
                write-host $computer "TLS 1.0 Client Disabled" -ForegroundColor Red
            }

            if ($SSLInfo -match "TLS 1\.1 Client.*:.*No")
            {
                write-host $computer "TLS 1.1 Client Disabled" -ForegroundColor Red
            }      


            if ($SSLInfo -match "TLS 1\.1 Server.*:.*No")
            {
                write-host $computer "TLS 1.1 Server Disabled" -ForegroundColor Red
            }  
              