/*
Given the meeting times of a calender entry for a single day for an individual,
find the aggregate time slots the person is busy

UNDERSTAND THE PROBLEM

Restate problem in your own words:
Create a function that takes in meeting times in a day
Return time blocks where this person is unavailable

What are the inputs that go into the problem:
Calender entries: Start and End time in hhmm in a 24hr clock format
Array of arrays (jagged arrays), 0 idx is start time 1 idx is end time
[[hhmm,hhmm],[hhmm,hhmm],[hhmm,hhmm],[hhmm,hhmm]]

What are the outputs that should come from the solution:
Return an array of array that include two elements a start and end time

Can the outputs be determined from the inputs? 
In other words, do I have enough information to solve the problem?
Are the calender times sorted already - if not should we sort

How should I label the important pieces of data that are a part of the problem?
CalenderEntry = [Start,End]
return AggregatedTime = [[StartTime, EndTime]]]

EXPLORE EXAMPLES

Example where there are invalid inputs
-- invalid input where times are not existing times
-- invalid inputs where end times are earlier than start times

Input: [[0930,1100],[3300,1200],[1330,1400],[1400,2830]]
Output: Calender event [1400,2830] is not a valid time entry

Example where there are empty inputs
Input: []
Output:[]

Example where calender times do no over lap
Input:[[0930,1100],[1100,1200],[1330,1400],[1400,1430]]
Output:[[0930,1200],[1330,1430]]

Example where calender times overlap
Input:[[0930,1100],[1045,1200],[1130,1400],[1400,1430]]
Output:[[0930,1430]]

BREAK IT DOWN


*/
