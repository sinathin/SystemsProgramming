Name: Sydney Anderson
 Date: 2/21/19


Project Explained: A C program that continually asks a user to enter input until user enters exit. Then, the input is split into two main "categories" based off Homework 4 specifications.
	

1) Built-in support: cd, pwd, and exit
		
-cd: is to change the current working directory. 
it's IMPORTANT TO NOTE: when typing into the command line you must enter a space after the specified directory (example below).
			
ex. NOT -> cd[space]Desktop
			
ex. DO THIS -> cd[space]Desktop[space]
		

-pwd: will show you the current working directory
		
-exit: will exit you out of the "shell"

	

2)Forked child process: all other commands that use exec call


 

Side Notes/Problems: 
	
-If youu were to run " cd /root ", you may notice no feedback is given even though there should be. 
	
-I did not personallize any error commands or handelings. Since i'm using system(), the resulting output for errors is 90% of the time what the terminal would display. I say 90%, because certain situations, like the one stated above is an exception and thus there must be more exceptions. 

All parts should work accordingly just remember:
	

-FOR CD make sure to hit the spacebar after entering the desired directory.
