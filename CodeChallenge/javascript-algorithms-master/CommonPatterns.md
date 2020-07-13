http://www.rosettacode.org/wiki/Rosetta_Code

Master Common Patterns
Frequency Counter
Multiple Pointers
Sliding Windows
Divide and Conquer
Dynamic Programing
Greedy Algorithms
Backtracking

Frequency Counter
This pattern uses objects or sets to collect values/frequencies of values. This can often avoid the need for nested loops or O(N^2) operations with arrays/string

----

Multiple Pointer
Creating pointers or values that correspond to an index or position and move towards the beginning, end or middle based on a certain condition
Very efficient for solving problems with minimal space complexity

---- 

Sliding Window
This patern involves creating a window which can be either an array of number from on position to another

Depending on a certain condition, the window either increases or closes(and a new window is created)

Very useful for keeping track of a subset of data in an arry/string

----

Divide and Conquer
This pattern involes dividing a data set insto smaller chunchs and then repeating a process with a subset of data
This can tremendously decrease time complexity


----

Two essential parts of a recursive function

Base case - the condition when the recursion ends
Different Input - when calling the same function you need to insert different data

Common recursion pitfalls
Base call not existant or is wrong
Forgetting to return or returning the wrong thing
When the callstack gets over flow

Helper function method recursion 

----