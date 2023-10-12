* Linux OS
  * Using WSL
  * Using Oracle Virtual box
    * OVA (Open Virtual Appliance)
________________
* Directories
 * /
 * /bin (excutables)
 * /etc (configuration - how os behaves)
 * /home (user directories)
 * /opt (optional or third party software)
 * /tmp (temporaray)
 * /usr (user related programs)
 * /var (variable data, most notably log files)
 * /boot (files needed to boot the os)
 * /dev device files
 * /mnt (used to mount external files)
 ________________
* Prompt
 * '$' normal user
 * '#' root user
 * '~' home directory
 ________________
* Essential commands
 * pwd (current working directory)
 * cd
 * ls
 * which
 * ls /bin
 * mkdir
 * rmdir 
 * rm -rf (recursive)
 * ls -t (sorted by time)
 * ls -R (recurisve)
 * tree -d
 * tree -C
 * groups (id -Gn)
 * chmod
   * chmod [ugoa] [+-=] [rwx]
   * ex:
     chmod g+w sales.data
 * chgrp
 * umask
 * find
   * -name pattern
   * -iname pattern (case insensitive)
   * -ls
   * -mtime days
   * size num
   * exec command {} \;  (run command against all the files that are found)
     * find -name *.txt -exec cat {} \;
 * locate
   * not real time (based on index and hence faster)
 * uptime
 * touch (updates the modified time, also creates if no file exists)
 * cat, more, less,tail
 * file
 * tr
________________

* Permissions
  - d |  (regular/directory/symbolic)
  rwx (read/write/execute)
  * categories
    * u - users , g = group, o-other a-all

______

* Editors
  * nano (pico)
  * vi
    * vim
    * view (readonly)
______

* Wildcards
  * '*' (0 or more occurrences)
  * '?' (exactly one character)
  * [] chacter class
    * ca[nt]*
    * [a-g]*
  * [!]  matches not any chacters
  * Named character set
    * [[:alpha:]]
    * [[:alnum:]]
    * [[:digit:]]
  * escape character (\)
____

* I/O
 * stdin  (0)
 * stdout (1)
 * stderr (2)
 * ex
   * ls files.txt not-here  1>out 2>out.err
   * ls files.txt not-here > out.both 2>&1
_____

* comparing
 * diff
 * sdiff
 * vimdiff

____

* searching
 * grep pattern file
   * -i ignore
   * -c count
   * -v invert
   * -n line numbers
 * strings (used for binaries)
____

* Pipes
 * cat file  | grep pattern
____

* Copying files over network
  * scp
  * sftp
  * ftp (not secure)


