$here = Split-Path -Parent $MyInvocation.MyCommand.Path
$sut = (Split-Path -Leaf $MyInvocation.MyCommand.Path).Replace(".Tests.", ".")
. "$here\$sut"
 
Describe “Get-HelloWorld Should return true." {
    It "does something useful" {
        Get-HelloWorld | Should Be 'Hello world!'
    }
}