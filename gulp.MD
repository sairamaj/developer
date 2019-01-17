* Automate tasks through code (Grunt is by configuration where Gulp is by code.)
[Overview](https://scotch.io/tutorials/automate-your-tasks-easily-with-gulp-js)

* npm install --global gulp ( install global)
* npm install --save-dev gulp ( install dev dependency)
* create gulpfile.js

```javascript
var gulp = require('gulp')
var gutil = require('gulp-util')

gulp.task('default', function() {
    return gutil.log('gulp running.')
})
```
