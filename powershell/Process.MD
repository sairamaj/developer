

## Begin
<pre>
This block is used to provide optional one-time pre-processing for the function. 
The PowerShell runtime uses the code in this block one time for each instance of the function in the pipeline.
</pre>

## Process
<pre>
This block is used to provide record-by-record processing for the function. This block might be used any number of times, or not at all, depending on the input to the function. For example, if the function is the first command in the pipeline, the Process block will be used one time. If the function is not the first command in the pipeline, the Process block is used one time for every input that the function receives from the pipeline. If there is no pipeline input, the Process block is not used.


A __Filter__ is a shorthand representation of a function whose body is composed entirely of a process block.

This block must be defined if a function parameter is set to accept pipeline input. If this block is not defined and the parameter accepts input from the pipeline, the function will miss the values that are passed to the function through the pipeline.

Also, if the function/cmdlet supports confirmation requests (the -SupportsShouldProcess parameter is set to $True), the call to the ShouldProcess method must be made from within the Process block.
</pre>

## End
<pre>
This block is used to provide optional one-time post-processing for the function.
</pre>

[Process](https://ss64.com/ps/syntax-function-input.html)

```powershell
Function Test-Process1{
    Process{ 
        write-host "Entered Test-Process1"
        write-host "processing1 .." $_

        for( $x = 1; $x -le 2 ; $x++)
        {
            write-host "Test-Process1 loop..."
            $x
        }

        write-host "Leaving Test-Process1"
    }
}

Function Test-Process2{
    Process{ 
        write-host "Entering Test-Process2"
        write-host "processing2 .." $_
        write-host "Leaving Test-Process2"
    }
}



Function Test-Process3{
        write-host "Entered Test-Process3"
        write-host "processing3 .." $_

        for( $x = 1; $x -le 2 ; $x++)
        {
            write-host "Test-Process3 loop..."
            $x
        }

        write-host "Leaving Test-Process3"
}

Function Test-Process4{
        write-host "Entering Test-Process4"
        write-host "processing4 .." $_
        write-host "Leaving Test-Process4"
}

 @("hello","hai") | Test-Process1 | Test-Process2
Write-host '----------------------------------------'
@("hello","hai") | Test-Process3 | Test-Process4
```

## Output

<pre>
Entered Test-Process1
processing1 .. hello
Test-Process1 loop...
Entering Test-Process2
processing2 .. 1
Leaving Test-Process2
Test-Process1 loop...
Entering Test-Process2
processing2 .. 2
Leaving Test-Process2
Leaving Test-Process1
Entered Test-Process1
processing1 .. hai
Test-Process1 loop...
Entering Test-Process2
processing2 .. 1
Leaving Test-Process2
Test-Process1 loop...
Entering Test-Process2
processing2 .. 2
Leaving Test-Process2
Leaving Test-Process1


Entered Test-Process3
processing3 .. 
Test-Process3 loop...
Test-Process3 loop...
Leaving Test-Process3
Entering Test-Process4
processing4 .. 
Leaving Test-Process4
</pre>

