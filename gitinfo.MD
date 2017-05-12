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


* to apply newly added .gitignore to already existing files on GitHub
 *	git rm -r --cached .
 *	git add .
 *	git commit -m ".gitignore is now working" 
 *	git push origin master

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


 