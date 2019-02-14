### Some common commands
* .logopen c:\temp\log.txt
* .logclose
* .loadby sos clr  ( loading clr for managed commands)
* !clrstack 
* ~*e !clrstack  ( ~*e means do for all threads and then following is actual command)
* sxe clr ( stop for all __CLR__ exceptions )
* sxd clr ( removing the breakpoint for all __CLR__ exceptions)

### Searching for strings and printing them
``` script
.block
{
	.foreach( address { s -[1]u 00000000 L?ffffffff "stringtoSearch" } )
	{
		dt wchar_t[1000] ${address} 
		.printf "\n"
	}
}
```
### Dumping array
```
.foreach ( o { !do ${$arg1} -v -short }) { !do ${o} }
```
### For each loop
```
 .foreach( logger {!dumpheap -type .NETTypeHere -short} )
 ```
### Dumping field as string
!dumpfield -field fieldName address -string

### Reading a value at given address
* poi(address)

### Connection strings 
```
.block
{
                .foreach( obj {!dumpheap -type System.Data.SqlClient.SqlConnectionString -short} )
                {
                                !df -field _encryptedUsersConnectionString ${obj}
                }
}
```

### Dump Http Application
```
$$

$$ =============================================================================
$$ Gets HttpApplicationState 
$$
$$
$$
$$ Example: $$>a<<path>\dumphttpapplicationstate.wds
$$
$$
$$ Sairama K Jamalapuram
$$
$$ All my scripts are provided "AS IS" with no warranties, and confer no rights. 

$$ =============================================================================

ad /q*
$$ ---------------------------------------------------------------------------------------
$$	Get info of System.Web.HttpApplicationState
$$ ---------------------------------------------------------------------------------------
.printf "Getting System.Web.HttpApplicationState...\n";
.symfix;
.reload
.load clr10\sos
.block
{
	.foreach( httpApplicationState {!dumpheap -type System.Web.HttpApplicationState -short} )
	{
		$$    .printf "--------------------------------------------------\n"
		$$    .printf "System.Web.HttpApplicationState address,%#X\n", ${httpApplicationState}
		$$    .printf "--------------------------------------------------\n"
     
      		r @$t1 = ${httpApplicationState} + @$ptrsize * 4;
     
		$$    .printf "--------------------------------------------------\n"
		$$    .printf "_entriesTable address,%#X\n", @$t1
		$$    .printf "--------------------------------------------------\n"
     
		$$    Get Hashable address.     
      		r @$t0 = poi(@$t1)
     
     
     		!do @$t0
	}
}

  .printf "Getting Bucket information from hashtable...%#X\n",@$t0
  .block
  {
      $$ ---------------------------------------------
      $$ buckets:System.Collections.Hashtable/bucket[]
      $$ ---------------------------------------------
      r @$t1 = poi(@$t0+ @$ptrsize)



      $$ change the default format base 10 as we are reading the output of object
      n 10

      $$ ---------------------------------------------
      $$ bucket size from buckets to t2
      $$ ---------------------------------------------
      r @$t2 = poi(@$t1 + @$ptrsize)

      $$ ---------------------------------------------
      $$ count factor from hashtable to t3
      $$ ---------------------------------------------
      .foreach( obj {!dumpfield -field count @$t0} )
      {
        r @$t3 = ${obj}
      }

      $$ change back to hex.
      n 16
  }


  $$ ---------------------------------------------------------------------------------------
  $$ Print for debugging
  $$ ---------------------------------------------------------------------------------------
  .printf "Priting Hashtable and bucket information...\n";
  .block
  {
      .printf "---------------------------------------------------\n"
      .printf "Hashtable address:%d\n",@$t0;
      !do @$t0

      .printf "\tbucket:%d\n",@$t1
      !do @$t1

      .printf "\tcount---->:%d\n",@$t3
      .printf "\tloadsize---->:%d\n",@$t2

      .printf "---------------------------------------------------\n"
  }

  $$ iterator to keep track of count of users
  r @$t4 = 1

  $$ ----------------------------------------------
  $$ Starting of first key:value
  $$ ----------------------------------------------

  r @$t5 = @$t1 + @$ptrsize*2


  .for (r eax=0; @eax < @$t2; reax=eax+1;) 
  { 
    .block 
    { 
      $$ ============================================== 
      $$ Get address_hash_coll 
      $$ ============================================== 
      r @$t11 = poi(@$t5 + @$ptrsize * 2) 
      
      .if( @$t11 = 0xffffffff`80000000 )
      {
        $$ another hashcoll and ignore it.
      } 
      .elsif( poi(@$t5) > 0 )
      {
        r @$t15 = poi(@$t5)

        .printf "Key:" ;
        	!do poi(@$t5)
$$        .printf "Value:" ;
	  $$ -------------------------------------------------------------
	  $$		Remove the below line to see the value.
	  $$ -------------------------------------------------------------
$$        	!do poi(@$t5+@$ptrsize)
        	
        $$ =============================================
        $$ If we get to the count of hashtable then break.
        $$ =============================================
        .if( @$t19 > @$t2 )
        {
          .break;
        }

          r @$t4 = @$t4 + 1;
        }
        r $t5 = @$t5+@$ptrsize*3

      }

  }
```

### Stop on exception
* !soe -create System.NullReferenceException 1

### Sample config file to get memory dump on access violation
```
<ADPlus>

    <!--

    Configuring ADPlus to log and list the stack for only first chance AVs
    Will still create full dump for any type of second chance exceptions

    To define an output directory uncomment the line in the Settings section
      changing the directory to the one you want to use
      
      Syntax to run:
      ADPlus -c tmp.cfg -p <PID>

    -->

  <Settings>
      <RunMode> CRASH </RunMode>
      <!-- <OutputDir> c:\Dumps </OutputDir>  -->
  </Settings>

  <Exceptions>
     <Config>
       <Code>AllExceptions</Code>
       <Actions1> Log </Actions1> 
     </Config>
     <Config>
       <Code> av </Code>
       <Actions1> Log;Stack;FullDump </Actions1>
     </Config>
  </Exceptions>

</ADPlus>
```
### Save all modules 
* use !sam with psscor2 extension
* or  
```
    !for_each_module !savemodule ${@#Base} f:\blog\modules\${@#ModuleName}.dll
```

### Putting a breakpoint on returns to see what function is returing
* Get method description of the function
* !dumpmt -md <methoddescription>
* !bpmd -md <particular method>
* when breakpoint hits
  * use kpL
  * get the retAddress
  * bp <retAddress>
  * go
* Now it will stop when function returned
* use __r__ to list the address
* then return value will be at eax register ( !do eax)
## [MEX](https://www.microsoft.com/en-us/download/details.aspx?id=53304)
* To load module
  * !ilspy -t -p <path to ilspy.exe here> <.NET type here.>
  

