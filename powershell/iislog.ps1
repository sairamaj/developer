param(
	    [string]
	    [parameter(mandatory=$true)]
	    $LogPath,
	    [string]
	    [parameter(mandatory=$true)]
	    $OutputPath,	    
	    [datetime]
	    [parameter(mandatory=$true)]
	    $FromLocalDate,
	    [parameter(mandatory=$true)]
	    [datetime]
	    $ToLocalDate
)
<#
    Gets the time query part used in log parser.
#>
Function Get-TimeQuery
{
    param(
        [datetime]
        $FromUtcDate,
        [datetime]
        $ToUtcDate
    )
      $fromDateString = "'" + $FromUtcDate.ToString('yyyy-MM-dd HH:mm:ss') + "'"
      $toDateString = "'" + $ToUtcDate.ToString('yyyy-MM-dd HH:mm:ss') + "'"
      "where to_timestamp(date,time) between timestamp($fromDateString , 'yyyy-MM-dd hh:mm:ss') and timestamp($toDateString, 'yyyy-MM-dd hh:mm:ss')"
}

# set parser tool and time clause which will be used.
$LogParserTool = Join-Path (Get-Location) 'logparser'


$FromLocalDate
$ToLocalDate
$TimeClause = Get-TimeQuery -FromUtcDate $FromLocalDate.ToUniversalTime() -ToUtcDate $ToLocalDate.ToUniversalTime()


<#
   Extracts the logs for the timings. 
#>
Function Extract-LogFile
{
    param(
        [PSObject]
        $LogPath,
        [string]
        $OutputPath
    )
       $input = $LogPath
       $output = $OutputPath

       write-host "    Generating..."        
       write-host "                 parsing $input -> $output"
       #$cmdLine = """select date, time, TO_TIME(TO_LOCALTIME(SYSTEM_TIMESTAMP())) AS LTime,cs-uri-stem,sc-status,time-taken into $output from $($input) $TimeClause "" -q:ON"
       $runCmd = "$LogParserTool $cmdLine"
       $runCmd
       CMD /C $runCmd 

}


Extract-LogFile -LogPath $LogPath -OutputPath $OutputPath
