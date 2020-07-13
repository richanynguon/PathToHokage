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
1)
Iterate over array
For each element:
I need to check if s and e times are valid
s time is earlier than e time
  else throw error Calender event [hhmm,hhmm] is not a valid time entry
Current s time is later than prev s time
  else organize (will have to find a strategy to organize) 
  - Possible structures to store data - Array, 
   -pros easy to manipulate, 
   -cons space and time complexity is bleh due to resizing and copy array
    -can be helped by sorting in place
  - Linked list
    -pros do not have to worry about time and space complexity with resizing array
    -cons would have to convert from array to linked list
  
  Use the same array
  - To merge sort in place - o(nlogn)
  - insertion sort - o(n**2)
  - Comparision, since the number of elements are small the diff before nlogn vs n**2 really small
  - The implementation for each, insertion sort bubble down input to the correct placement

  Do I really need to sort prior merging times?
  [[1130,1400],[0930,1100],[1400,1430], [1045,1200]]
  [1130,1400] - [0930,1100]
  [0930,1100], [1130,1400] - [1400,1430]
  [0930,1100], [1130,1430] - [1045,1200] - if its possible check if next elment start time is less than end time then merge
  [0930,1200], [1130,1430]
  [0930,1430]


  Store the last time of the schedule

2) If time a.end is the same of b.start or if a.end later than b.start
    return [a.start, b.end]

    I can use the same array rewrite it then once you find last time in the schedule
*/

function checkEventTimesValidity(entry) {
	if (Array.isArray(entry) && entry.length === 2) {
		if (
			entry[0] < entry[1] &&
			entry[0] >= 0000 &&
			entry[0] <= 2359 &&
			entry[0][2] < 6 &&
			entry[1] >= 0000 &&
			entry[1] <= 2359 &&
			entry[1][2] < 6
		) {
			return true;
		} else {
			return false;
		}
	}
}

function findMid(length) {
	return Math.floor(length / 2);
}

function combineElements(arrA, arrB) {
	if (arrA[0] < arrB[0]) {
		return [arrA[0], arrB[1]];
	} else {
		return [arrB[0], arrA[1]];
	}
}

function elementInRange(arr, value, start) {
	if (start) {
		if (arr[0] <= value && arr[1] >= value) {
			return true;
		} else {
			return false;
		}
	} else {
		if (arr[1] <= value) {
			return true;
		} else {
			return false;
		}
	}
}

function swap(arrA, arrB) {
	let temp = arrA;
	arrA = arrB;
	arrB = temp;
}

function elementsInRangeCombine(arr, element) {
	let low = 0;
	let high = arr.length - 1;
	let value = undefined;
	let lastIdx = undefined;
	while (high >= low) {
		let mid = findMid(low + high);
		lastIdx = mid;
		const midArrEl = arr[mid];
		const elStart = element[0];
		let elEnd = element[1];
		const midArrElStart = midArrEl[0];
		const midArrElEnd = midArrEl[1];
		if (elementInRange(midArrEl, elStart, true)) {
			const nextArrEl = arr[mid + 1];
			if (nextArrEl && elementInRange(nextArrEl, elEnd)) {
				let counter = 1;
				while (
					arr[mid + counter] !== undefined &&
					arr[mid + counter][1] < elEnd &&
					counter < arr.length
				) {
					counter += 1;
				}
				let lastInRangArrEL = arr[mid + counter];
				const newEl = combineElements(midArrEl, lastInRangArrEL);
				arr[mid] = newEl;
				arr = arr.splice(mid + counter, counter);
				value = true;
				break;
			} else {
				const newEl = combineElements(midArrEl, element);
				arr[mid] = newEl;
				value = true;
				break;
			}
		} else if (midArrElEnd > elStart && midArrElStart > elStart) {
			high = mid - 1;
		} else if (midArrElEnd < elStart) {
			low = mid + 1;
		}
	}
	if (value) {
		return arr;
	} else {
		if (arr[0][0] > element[0]) {
			arr.unshift(element);
		} else {
			arr.push(element);
		}
		return arr;
	}
}

function aggregateTimeSlots(calenderEntries) {
	if (calenderEntries.length > 1) {
		let aggregateTime = [];
		for (let i = 0; i < calenderEntries.length; i++) {
			const entry = calenderEntries[i];
			if (checkEventTimesValidity(entry)) {
				if (aggregateTime.length === 0) {
					aggregateTime.push(entry);
				} else {
					aggregateTime = elementsInRangeCombine(aggregateTime, entry);
				}
			} else {
				return `Calender event [${entry[0]},${entry[1]}] is not a valid time entry`;
			}
		}
		const newArr = [];
		for (let j = 0; j < aggregateTime.length; j++) {
			let obj = aggregateTime[j + 1];
			if (aggregateTime[j + 1] !== undefined) {
				if (aggregateTime[j][1] > aggregateTime[j + 1][0]) {
					const newEl = combineElements(aggregateTime[j], aggregateTime[j + 1]);
					newArr.push(newEl);
				} else {
					newArr.push(aggregateTime[j]);
				}
			}
		}
		return newArr;
	} else {
		return calenderEntries;
	}
}

console.log(
	aggregateTimeSlots([
		["1130", "1400"],
		["0930", "1100"],
		["1400", "1430"],
		["1045", "1200"],
		["1530", "2300"],
		["0000", "0001"],
	])
);


