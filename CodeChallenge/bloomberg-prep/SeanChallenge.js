/*
https://leetcode.com/problems/move-zeroes/
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Input: [0,0,0,0,0]
Output: [0,0,0,0,0]

Input: [1,2,3,4,5]
Output: [1,2,3,4,5]


You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

function moveZeros(arr) {
	let nextPlacement = 0;
	for (let i = 0; i < arr.length; i++) {
		//o(n)
		if (arr[i] === 0) {
			let elCount = 1;
			for (let j = i + 1; j < arr.length - 1; j++) {
				//o(n)
				if (arr[j] !== 0) {
					arr[nextPlacement] = arr[j];
					nextPlacement += 1;
					break;
				}
				elCount += 1;
			}
			i += elCount;
		} else {
			arr[nextPlacement] = arr[i];
			nextPlacement += 1;
		}
	}
	for (let k = nextPlacement; k < arr.length; k++) {
		arr[k] = 0;
	}
	return arr;
}

// console.log(moveZeros([0,1,0,3,12]))

/*
void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

const nums = [0, 1, 0, 12, 15, 0, 3, 0, 0, 1, 0, 0];
 
function moveZeros(arr) {
  let nextIdx = 0;
  for (let i = 0; i < arr.length; i++) {
    // axiom: nextIdx is always <= i
    if (arr[i] === 0) {
      // keep nextIdx where it is
      continue;
    }
    // move the next non-zero number to the next appropriate index
    arr[nextIdx] = arr[i];
    arr[i] = 0;
    nextIdx++; // and advance
  }
  return arr
}
 
console.log(moveZeros(nums))

*/

/*
https://leetcode.com/problems/group-anagrams/
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

/* 

1) iterate through the array
["eat", "tea", "tan", "ate", "nat", "bat"]
[
  "eat": ["eat","tea", "ate"]
  "tan": ["tan", "nat"]
  "bat": ["bat"]
]

2)
["eat", "tea", "tan", "ate", "nat", "bat"]

output: [["eat"][]]

*/

function groupAnagrams(arr) {
	let groupedAnagrams = [];
	for (let val of arr) {
		if (groupedAnagrams.length < 1) {
			groupedAnagrams.push([val]);
		} else {
			let isLost = true;
			for (let group of groupedAnagrams) {
				const resultSet = new Set([...group[0], ...val]);
				if (resultSet.size === group[0].length) {
					group.push(val);
					isLost = false;
				}
			}
			if (isLost) {
				groupedAnagrams.push([val]);
			}
		}
	}
	return groupedAnagrams;
}
console.log(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

/*
https://leetcode.com/problems/validate-binary-search-tree/
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

function validateBST() {
	continue;
}
// console.log(validateBST([5,1,4,null,null,3,6]))

/*
https://leetcode.com/problems/design-underground-system/
Implement the class UndergroundSystem that supports three methods:

1. checkIn(int id, string stationName, int t)

A customer with id card equal to id, gets in the station stationName at time t.
A customer can only be checked into one place at a time.
2. checkOut(int id, string stationName, int t)

A customer with id card equal to id, gets out from the station stationName at time t.
3. getAverageTime(string startStation, string endStation) 

Returns the average time to travel between the startStation and the endStation.
The average time is computed from all the previous traveling from startStation to endStation that happened directly.
Call to getAverageTime is always valid.
You can assume all calls to checkIn and checkOut methods are consistent. That is, if a customer gets in at time t1 at some station, then it gets out at time t2 with t2 > t1. All events happen in chronological order.

 

Example 1:

Input
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Output
[null,null,null,null,null,null,null,14.00000,11.00000,null,11.00000,null,12.00000]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);
undergroundSystem.checkOut(27, "Waterloo", 20);
undergroundSystem.checkOut(32, "Cambridge", 22);
undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.00000. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.00000
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000
undergroundSystem.checkOut(10, "Waterloo", 38);
undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 12.00000
Example 2:

Input
["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]
[[],[10,"Leyton",3],[10,"Paradise",8],["Leyton","Paradise"],[5,"Leyton",10],[5,"Paradise",16],["Leyton","Paradise"],[2,"Leyton",21],[2,"Paradise",30],["Leyton","Paradise"]]

Output
[null,null,null,5.00000,null,null,5.50000,null,null,6.66667]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(10, "Leyton", 3);
undergroundSystem.checkOut(10, "Paradise", 8);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000
undergroundSystem.checkIn(5, "Leyton", 10);
undergroundSystem.checkOut(5, "Paradise", 16);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000
undergroundSystem.checkIn(2, "Leyton", 21);
undergroundSystem.checkOut(2, "Paradise", 30);
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667
 

Constraints:

There will be at most 20000 operations.
1 <= id, t <= 10^6
All strings consist of uppercase, lowercase English letters and digits.
1 <= stationName.length <= 10
Answers within 10^-5 of the actual value will be accepted as correct.
*/

function undergroundSystem() {
	continue;
}
// console.log(undergroundSystem([]))
// ["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]
// [[],[10,"Leyton",3],[10,"Paradise",8],["Leyton","Paradise"],[5,"Leyton",10],[5,"Paradise",16],["Leyton","Paradise"],[2,"Leyton",21],[2,"Paradise",30],["Leyton","Paradise"]]

/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/

function removeAdjacentDuplicates() {
	continue;
}
// console.log(removeAdjacentDuplicates("pbbcggttciiippooaais", 2))
