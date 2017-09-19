```javascript
function openWebFile(name, file) {
    var fileWithPath = 'filepathhere'
    WshShell = new ActiveXObject("WScript.Shell");
    WshShell.Run('notepad.exe ' + fileWithPath, 1, false);
}

```

```html
    <a href="javascript:openWebFile( 'arg1', 'arg');">Open a file</a> <br/>
    <input type="button" value="Viewer." onclick="runToolApp('exenamehere.exe');" />
```


