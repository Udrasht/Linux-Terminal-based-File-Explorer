# Linux based File Explorer
A file explorer for linux systems that runs on terminal
## Prerequisites

**1. Platform:** Linux 

**2. Software Requirement:**
* G++ compiler
   * **To install G++ :** ```sudo apt-get install g++```

## Steps to run the project
- Open your terminal with present working directory as the project folder. Then compile main.cpp file.

    ```g++ main.cpp```
- Then finally run the project as shown below.

     ``` ./a.out```

### 1. Normal Mode:
1.1 **Read and display list of files and directories in the current folder**
* File explorer show each file in the directory (one entry per line). The following attributes are visible for each file
    * File Name
    * File size (Human readable format similar to ls -lh)
    * Ownership (User & Group) & Permissions
    * Last modified

* The File explorer also handle scrolling (vertical overflow) in case the directory has a lot of files.
* The file explorer also show the entries “.” & “..” for current and parent directory respectively.
* User is able to navigate up & down the file list using corresponding arrow keys.


1.2 **Open files & directories**
* When enter is pressed
    * Directory​ - It will Clear the screen and Navigate into the directory and shows the files & directories inside it as specified in point 1
    * Files​ - It will open files using the corresponding default application.

### 2. Command Mode:
The application is enter the command mode whenever the ```:``` (colon) key
is pressed. 
<br/>
Upon entering the command mode the user should be able to enter
different commands. All commands should appear in a bottom status bar

**2.1 copy, move and rename** 
```
copy <source_file(s)> <destination_directory>
move <source_file(s)> <destination_directory>
```

```
Eg:
copy foo.txt bar.txt baz.mp4 ~/foobar
move foo.txt bar.txt baz.mp4 ~/foobar
rename foo.txt bar.txt
```
Copying / Moving of directories is also be implemented

**2.2 create files and directories** 
```
create_file <file_name> <destination_path>
create_dir <dir_name> <destination_path>
```

```
Eg:
create_file foo.txt ~/foobar
create_file foo.txt .
create_dir folder_name ~/foobar
```

**2.3 delete files and directories** 
```
delete_file <file_path>
delete_dir <directory_path>
```

```
Eg:
delete_file ~/foobar/foo.txt.
delete_dir ~/foobar/folder_name
```

**2.4 goto** 
```
goto <directory_path>
```

```
Eg:
goto /home/udrasht/
goto ~
```

**2.5 Search a file or folder given fullname.** 
```
search <filename>
```

```
Eg:
search foo.txt
```
Search for the given filename under the current directory recursively


**2.6 Snapshotting the filesystem and dump into a file** 
```
snapshot <folder> <dumpfile>​
```

```
Eg:
snapshot ~/foobar/ dumpimg
```
Given a base directory this command recursively crawl the directory and store the output in dumpfile.

**2.7 On pressing ‘ESC’ key the application should go to Normal Mode**