# CSE-4334_Lab_1
Our members: Sam Trinh and Charles A-Darfah

Compilation should look similar to:
gcc part_a.c -std=c99 -o part_a.exe

For Part A:
  To run the program, simply compile and run. The program generates 50,000 random numbers and organizes them in an array twice. The first time it shall be through the unoptimized algorithm, which for us is bubble sort.
  Once that is completed, the program will do it again with the optimized algorithm, which is quick sort for us. Afterwards, it shall list the processing and total time for both algorithms. 
  We then calculate the proportion of optimizable code, the speedup of the optimized code, the overall measured speedup, and then the theortical speedup. 

For Part B:
  To run the program compile and run. The program shall give you a prompt asking you which operation you want. The operations are NOT case-sensitive. Based on the operation it shall ask for one or two 8 digit binary numbers. The result of the operation will be given a prompt again. This loop keeps on going until you enter exit.
