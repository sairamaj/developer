param(
    $Name,
    $Age
)

$date = [System.DateTime]::Now
"Before $date $Name  $Age " | out-file -FilePath "c:\\temp\\test1.txt" -Append -Encoding ascii
Start-Sleep -Seconds 5
"After $date $Name  $Age " | out-file -FilePath "c:\\temp\\test1.txt" -Append -Encoding ascii