[Getting Started with Windows Powershell Workflow](https://technet.microsoft.com/en-us/library/jj134242(v=ws.11).aspx)
## Overview
* Can be used the Visual studio workflow designer which generates XAML.

## Activities
* An activity is a specific task that you want a workflow to perform. Just as a script is composed of one or more commands, a workflow is composed of one or more activities that are carried out in a sequence. A script can also be used as a single command in another script, and a workflow can be used as an activity within another workflow.

## Windows Powershell workflow vs Powershell scripts
* In a script, the entire script runs in the same __runspace__, the operating environment that defines which commands, variables, and other elements are available.
* In a workflow, each activity within the workflow can run in a different runspace. Variables that are created at the top level of the entire workflow are available throughout the workflow; if they are created at the script or command level, they are available for the command or script, but not available to the entire workflow.

## When to use workflow?
* Need to perform a long-running task that combines m ult iple steps in a sequence.
* Need to perform a task that runs on multiple devices.
* Need to perform a task that requires checkpointing or persistence.
* Need to perform long-running task that is asynchronous, restartable, parallelizable, or interruptible.
* Need to run a task on a large scale, o in high availability environments, potentially requiring throttling and connection pooling

```powershell
    workflow Test-Workflow
    {
        "Hello World"
    }
```

View the xaml associated with workflow: 
```powershell
Get-Command Test-Workflow | select XamlDefinition -ExpandProperty XamlDefinition
```

## Resources
[Windows PowerShell: When to Choose Workflow Versus Script Functions](http://www.informit.com/articles/article.aspx?p=2481897)
