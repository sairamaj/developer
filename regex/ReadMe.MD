[] - range
/   / - start and end of regular expression

Color code validation
---------------------
html color is: # R G B 


?  - 0 or 1
*  - 0 or more
+  - 1 or more


#[ABCDEF0123456789]+
#[A-F0-9]+   ( here starts with # )

#?[A-F0-9]+  ( # is optional )
{ }   - Used for range
	{6}  - exact six characters.
	#?[A-F0-9]{6}


|  (pipe) is used for OR

/i  - case insensitive

^  - anchros begining string
$  - anchros end of the string
^#?[A-Fa-f0-9]{6}$    (entire string has to have the format of # followed by exact 6 characters. ^ and $ will make begin and end of the string

\s  - white space.
\s* - multiple white space ( * is used 0 or more )

- regexper.com		- shows nice pictural view of the regular expression.
- http://regexstorm.net/tester	- nice way of testig.

![]()

