# Basics
* Local Git
  * Distributed so that connectivity does not block work
* Distributed Git
  * Team-centric so that collaboration happens naturally
* Customizable Git
  * Flexible so that it fits your need
  * Powerful to satisfy the scripting needs of the advanced developers
* Focused on Content, not files
* Journal, not backup 
* Anywhere, not just online
 
  
* git init
* git config --global user.name 'namehere' ( these are not credentials but to credit the changes.)
* git config --global user.email 'name@email.com' 
* git status
* git commit -m "comment here"
* git add *
* git rm --cache <filename>
* git remote add origin https://github.com/sairamaj/java
* git push origin master
* git clone <url> ( in new directory to get source from remote
* git checkout .   - to loose changes on working copy
* git log --graph --decorate --abbrev-commit --all --pretty=oneline
* to remove directory
 *	git rm -r one-of-the-directories
 *	git commit -m "Remove duplicated directory"
 *	git push origin <your-git-branch> (typically 'master', but not always)
* git branch -all
* git show-ref mater (shows the branch points)
* git cat-file hash


* to apply newly added .gitignore to already existing files on GitHub
*	git rm -r --cached .
*	git add .
*	git commit -m ".gitignore is now working" 
*	git push origin master
*  git diff HEAD~1  (difference between head and previous one)
*  git diff 701ae..663397
*  git diff --cached
*  git checkout readme.txt (overwrite changes and gets from HEAD.) ( revert changes.)
*  git reset --hard ( go back to HEAD and loose all local changes)
*  git reset --soft HEAD~1  (kind of getting back in to working area the changes.)
*  git log --oneline
*  git log --graph
*  git log --graph --online --decorate
*  git shortlog  
*  git shortlog -sne
*  git show HEAD    (git show HEAD~1) (git show 353e3)
*  git branch --set-upstream master origin (establishes the link)
*  git config --global alias.lga "log --graph --oneline --all --decorate"  (adding alias.)
*  git reflog  (shows all the changes of HEAD movement)
*  git stash (moving changes to temporary )
*  git stash list
*  git stash apply
*  git stash pop  ( removes from the top of stash)
*  git mergetool
## Get latest from source ignoring local changes
* git reset --hard
* git pull
  

## Git on server - Protocols
* Local ( file based: git clone /srv/git/project.git)
* HTTP/HTTPS ( HTTP based:  git clone https://example.com/gitproject.git)
* SSH ( git clone ssh://user@server/project.git  ,  git clone user@server:project.git)
* Git ( git specific . no authentication - fast)


## Git Internals
* HEAD
  * branch you currently have checked out.
* index
  * staging area information.
* objects
  * all the content for your database.
* refs
  * pointers into commit objects in that data(branches)

* echo "Apple Pie" | git hash-object --stdin -w  (Writes the file)
* git cat-file bb3918d5053fea31fc9a58fae1e5bdeabe3ec647 -p
* git count-objects 
### Git objects
* blob
* commit
* tree
* text
  * annotated tags (carries lot of information, date, who created etc.,)
  * regular tags (light weight tag)
(Tag is like branch but does not move)
### Git tools
stree
### Get URL for local repository pointing to
* git remote show origin

### Get branch commands
* Show current branch
  * git branch
* Create branch
  * git branch <name of the branch>
  * git branch <sha of commit>  ( instead of HEAD )
* Switch to branch
  * git checkout <name of the branch>
  * git checkout -b <name>  ( create and switch)
* Renaming Branch  
  * git branch m old new
* Delete branch
  * git branch -d <name>
  * git branch -D <name> ( force the delete and loose changes)


### Git concepts
pull = fetch + merge

# ![gitobjects](https://github.com/sairamaj/developer/blob/master/images/gitobjects.png)

