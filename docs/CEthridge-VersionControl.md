# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project and Portfolio I: Computer Science - Online - Term C202611 Section 01]

- **[ Connor Ethridge]**
- **[ 11/1/26 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ cls ]: Clear the Screen
- [ dir ]: Print the "Working Directory"
- [ dir ]: List files and folders
- [ dir /a ]: List files and folders, including invisible files
- [ dir ]: List all files and folders, in human readable form
- [ cd [foldername] ]: Change directory
- [ cd \ ]: Change directory, go to root directory
- [ cd %USERPROFILE% ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ..\.. ]: Change directory, go up two folder levels
- [ cd Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ Dragging the folder into command prompt populates that folder's location in the command field. Pressing enter changes the directory to that folder's location.]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local - keeps all versions on a single computer;  Centralized - all files and versions are kept on a single server, which is accessed by developers for file modification;  Distributed - each developer has a local repository, which requires pushes/pulls to the main repository for changes to be visible to others]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone [url] ]: Clone a repository
- [ git config --global user.name “[firstname lastname]” ]: Set-up a global user name
- [ git config --global user.email “[valid-email]” ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add [file] ]: Add modified files to the next commit
- [ git commit -m “[descriptive message]” ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ Download and install the GitHub CLI. Once installed, the CLI can access the command line to connect to GitHub and run Git commands. Using the "htpps://" URL provided from the hosted GitHub repository from the command line, Git will request the GitHub username and password. Once provided, command line will connect to the GitHub repository and complete the command. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [Files and directories listed in a .gitignore file are not included when making a commit.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [An Apple OS exclusive file type that stands for Desktop Services Store. macOS creates these automatically when opening or customizing a folder. Including one sometimes creates merge issues when different operating systems are working together on a project.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [Any zipped or packaged file should be committed unpacked, as Git has built in compression.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ The cheat sheet for Windows terminal commands seems most useful, as the provided cheat sheet from the class resources was for macOS. Powershell has some built-in conversions/shortcuts allowing some crossover with macOS commands, but Windows CMD does not. ]

**Terminal Commands**  
[Windows Terminal Commands Cheat Sheet For Beginners](https://dev.to/techwebster/windows-terminal-commands-cheat-sheet-for-beginners-e8l)

**Three Types of Version Control**  
[Version Control Systems](https://www.geeksforgeeks.org/git/version-control-systems/)

**Git Commands**  
[GIT CHEAT SHEET](https://education.github.com/git-cheat-sheet-education.pdf))

**Connecting to GitHub using Terminal**  
[Set up Git](https://docs.github.com/en/get-started/git-basics/set-up-git#connecting-over-https-recommended)
[About remote repositories](https://docs.github.com/en/get-started/git-basics/about-remote-repositories#cloning-with-https-urls)
[About GitHub CLI](https://docs.github.com/en/github-cli/github-cli/about-github-cli)

**Using .gitignore and Why it's Important**  
[Ignoring files](https://docs.github.com/en/get-started/git-basics/ignoring-files)
[Stop Committing ".DS_Store" Files to Git](https://dev.to/samuelbruk/stop-committing-dsstore-files-to-git-4op1)
[Some common .gitignore configurations](https://gist.github.com/octocat/9257657)