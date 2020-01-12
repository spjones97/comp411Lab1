##Reading
Prior to beginning this tutorial, complete the following readings:

Perry and Miller (C textbook) Chapters 1-5, 7-10 and 14.
##Accessing the CS Dept server (comp411-1sp20.cs.unc.edu)
###Your CS account information
Your first task is to familiarize yourself with logging in to the virtual machine server for this course/section (comp411-1sp20.cs.unc.edu). Your login name and password on this server are the same as your UNC ONYEN and its password. If you do not know your ONYEN or password, please contact campus IT Services (919-962-HELP or https://help.unc.edu/sp).

###Logging in
#####NOTE: You must be connected to campus WiFi (or wired network) to be able to log in to our class server. If you are trying to access the server from off-campus, you must first use a VPN connection to campus, and then log in to the server. For more information on VPN, please seek help from IT services, or see here.

There are different ways to log in to the sever depending on the OS on your personal computer:

Windows: If your computer is running Windows, please use PuTTY (download from here, select the 64-bit "MSI Windows Installer"). Launch PuTTY and enter comp411-1sp20.cs.unc.edu for "Host Name", select "SSH" for connection type, leave the default "Port" value of 22, and click "Open". When prompted with "login as", enter your ONYEN, and then enter your password when prompted. Remember that you will not see your password as you are typing, not even dots, and the cursor will not move either; just enter your password and hit enter.
###Transferring files
You will also frequently need to transfer files between your personal computer and the server. Again, there are different ways of doing so, depending on the OS on your personal computer:

Windows users should use WinSCP (download for free). Use the same host and user names as for logging in. Drag and drop to copy files between your laptop and the server.

###Exercise 0: Unix Tutorial
Go through the UNIX tutorial in its entirety, try all of the UNIX commands described, and do all of the embedded tasks. If you do not follow the entire tutorial now, you will have difficulty with UNIX commands throughout the semester.

Specifically, go through all of the following sections of the tutorial:

Introduction to the UNIX operating system
Tutorial One: files and folders
Tutorial Two: copying, moving and deleting files/folders, and viewing file contents
Tutorial Three: input/output redirection and pipes
Tutorial Four: using wildcards in file names
Tutorial Five: processes and jobs
Tutorial Six: a few misc useful commands
####Getting Set Up
Log in to comp411-1sp20.cs.unc.edu.

Next, create a subdirectory (i.e., folder) comp411lab in your home directory by typing the following commands. Note: In these instructions, the % at the beginning of every line is simply the prompt that the command interpreter prints for you. So, in the following, you are only to type whatever is shown after the % prompt.

`% cd ~`

`% mkdir comp411lab`

Inside it, create a subfolder lab1 and make it your current working directory:

`% cd ~/comp411lab`

`% mkdir lab1`

`% cd lab1`

As a convenience, we have set the prompt to indicate the current working directory. Thus, at the end of the last command, your prompt will looks like ~/comp411lab/lab1%. This feature is helpful to remind you where you are currently working.

Copy the sample program intro.c into the lab1 subfolder using the copy (cp) command:

`% cp /home/montek/public/intro.c .`

Note: Do not ignore the trailing "." after the "intro.c" in the command above! The dot indicates that the file intro.c must be copied into the current folder.

For this tutorial, you will edit files using the editor pico (actually, it is mapped to a clone by GNU called nano, but you can use either name to launch it). View the C file using using pico as follows:

`% pico intro.c`

This editor is text-based, and you will need to use Control-key combinations to navigate the menu. Here are a couple of useful pico references:

Wikipedia article, including basic navigation commands
Detailed listing of pico navigation commands
Quit the editor, and enter the following Unix command to compile the program:

`% gcc intro.c`

Or,

`% cc intro.c`

Note: cc stands for "C Compiler", which on our department's systems is linked (i.e., aliased) to gcc, which is the GNU C Compiler, an open-source implementation.

What do you think has happened? Have a look at the contents of your current working directory. Find out what type of data is contained in the file a.out (Hint: use the file command you learned in the Unix Tutorial Lab 1).

Execute the program by typing

`% ./a.out`

and see what happens. Do you understand the C text of the program?

NOTE: Always put a "./" before the program name when executing a program in your working directory.

Remove the file a.out and try compiling the program in a slightly different way:

`% rm a.out`

`% gcc intro.c -o intro`

What is the difference? This time, the result of compilation produced an executable file called intro instead of a.out. Can you run the program now? You would run it by typing

`% ./intro`

Run the program again, but this time redirect its output into the file intro.out (using ">" to redirect its output, as described in the Unix Tutorial). What has happened to the prompting message? Have a look into the file intro.out and make sure that you understand what is there and why. You can view the contents of the file intro.out by typing

`% cat intro.out`

Or, you can view intro.out by opening it in pico:

`% pico intro.out`

Create file intro.in with a value of the radius and run the program so that it takes its input from intro.in and writes the output into intro.out:

`% ./intro < intro.in > intro.out`

Carefully note the syntax of the above command to run the program with its standard input redirected from a file, and its standard output redirected to a file. The order of the two files does not matter, so ./intro > intro.out < intro.in would also be okay, but listing the input file first makes the command easier to read. Note however that intro.in > ./intro > intro.out is not a correct way to accomplish the same; the executable file always comes first.

###Exercise 1
Modify the program so that it prompts you to enter the radius value as input in centimeters using the prompt "Enter radius (in cm):\n", but displays the result in square inches. (One inch is 2.54 cm exactly.) Use pico to edit the file to make this modification, and save the file as ex1.c inside your lab1 subfolder under the comp411lab folder in your home directory.

Compile this program to create an executable file called ex1 by typing

`% gcc ex1.c -o ex1`

Run the executable ex1 on a couple of different inputs to verify that it is working correctly. The inputs and outputs can be from the keyboard/terminal; you do not need to use redirection of input/output from/to files for this exercise. Here is an example execution scenario (user input is shown in red, and program output in blue):

`% ./ex1`

Enter radius (in cm):

2.54

Circle's area is 3.14 (sq in).

Reminder: We always put a "./" before the name of the executable when executing a program in your current working directory, hence ./ex1 above.

###Exercise 2
Copy the file ex1.c to ex2.c (so you do not accidentally edit ex1.c any further). Modify the program in ex2.c to also compute and display the circumference. Compile it to an executable called ex2, and run it. Here is an example execution scenario:

`% ./ex2`

Enter radius (in cm):

2.54

Circle's area is 3.14 (sq in).

Its circumference is 6.28 (in).

###Exercise 3
Copy the file ex2.c to ex3.c. Modify the program in ex3.c to make it work on multiple inputs. In particular, it should repeatedly ask for a radius value (in centimeters), and print the corresponding area (in square inches) and circumference (in inches), until the user enters the value 0 as radius. At that point, the program should print the area and circumference (both 0), and then terminate.

Compile this program to make an executable called ex3, and run it, feeding it several radius values from the keyboard, and verifying that the values it displays are correct. A single run of the program should be able to compute as many of these calculations as you want, until you enter 0.

`% ./ex3`

Enter radius (in cm):

2.54

Circle's area is 3.14 (sq in).

Its circumference is 6.28 (in).

Enter radius (in cm):

5.08

Circle's area is 12.57 (sq in).

Its circumference is 12.57 (in).

Enter radius (in cm):

0

Circle's area is 0.00 (sq in).

Its circumference is 0.00 (in).

Test Inputs
Sample inputs and corresponding outputs are provided under /home/montek/comp411/samples/lab1. You should try running your program on the sample input files provided, and make sure the program's output is identical to that in the sample output files. For example, the sample input files for Exercise 1 are called ex1in1 and ex1in2. Their corresponding outputs are in the files ex1out1 and ex1out2. You can, of course, manually type or cut-and-paste the contents of the input files onto your terminal when running the program. Or, you could feed that sample input to your program using input redirection (./ex1 < ex1in1). To verify that your program is working correctly, compare its output to the test output provided. Again, you could do this comparison manually, or you could use a very useful UNIX command called diff.

The full sequence of steps to run your program and verify its output is as follows. First, copy the sample input and output files to your lab1 folder:

`% cd ~/comp411lab/lab1`

`% cp /home/montek/comp411/samples/lab1/* .`

Then do the following:

`% ./ex1 < ex1in1 > ex1result1`

`% diff ex1result1 ex1out1`

The diff command prints any differences it finds between your program's output (which you redirected into the file ex1result1) and the correct output provided to you (in the file ex1out1). Only those lines that do not match are shown. Each line in the output is prepended with "<" if it belongs to the first file, and with ">" if it belongs to the second file. See Wikipedia page on diff for more information.

The variation diff -y prints the two files side-by-side (the first one on the left, the second on the right), and highlights lines where they differ. Watch out for extra spaces at end of lines, etc.!

`% diff -y ex1result1 ex1out1`

If you only want to see the lines that differ, you can use the following command:

`% diff --suppress-common-lines -y ex1result1 ex1out1`

If there are no differences, it prints nothing.

Before submitting your work, be sure that your compiled program runs correctly on all of the sample inputs provided exactly, i.e., diff produces no output at all. You may receive zero credit if your program's output does not exactly match the sample outputs provided. For example, for Exercise 1, two input files are provided: ex1in1 and ex1in2. Their corresponding outputs are also provided: ex1out1 and ex1out2. To check that your program works correctly on both, you may do the following:

`% ./ex1 < ex1in1 > ex1result1`

`% diff --suppress-common-lines -y ex1result1 ex1out1`

`% ./ex1 < ex1in2 > ex1result2`

`% diff --suppress-common-lines -y ex1result2 ex1out2`

Once you become familiar with diff, you may prefer to invoke it simply without any of the modifiers:

`% ./ex1 < ex1in1 > ex1result1`

`% diff ex1result1 ex1out1`

`% ./ex1 < ex1in2 > ex1result2`

`% diff ex1result2 ex1out2`

If neither of the diff commands showed mismatches between your program's output and the desired output, then your program is assumed to work fine. If your output happens to have one or more extra space characters at the end of a line, they can be hard to tell. In that case, use the hexdump -c command to display all the characters in your file:

`% hexdump -c ex1result1`

The hexdump -c command will show all spaces (as spaces), tabs (as \t), newlines (as \n), returns (as \r), etc., thereby making it easier to see whitespace characters.

Repeat such tests for Exercises 2 and 3 using all the input and output sample files provided for each.