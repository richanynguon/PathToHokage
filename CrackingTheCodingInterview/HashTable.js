class LinkedPair {
	constructor(key, value, next = undefined) {
		this.key = key;
		this.value = value;
		this.next = next;
	}
}

// worst case run time is o(n) good implementation will have o(1) look up - with a BST look up system it could give us a O(logn) which is good on space too

class HashTable {
	constructor(capacity) {
		this.capacity = capacity;
		this.storage = Array(capacity);
	}

	hash(key, max) {
		// http://www.cse.yorku.ca/~oz/hash.html
		let hash = 5381;
		for (let char in key) {
			// /* hash * 33 + c */
			//https://stackoverflow.com/questions/1579721/why-are-5381-and-33-so-important-in-the-djb2-algorithm#:~:text=33%20was%20chosen%20because%3A,This%20helps%20produce%20good%20avalanching.
			//
			hash = (hash << 5) + hash + key.charCodeAt(char);
		}
		return hash % max;
	}

	insert(key, value) {
		const index = this.hash(key, this.capacity);
		let current = this.storage[index];
		let last;

		while (current && current.key != key) {
			last = current;
			current = last.next;
		}
		if (current) {
			current.value = value;
		} else {
			let next = new LinkedPair(key, value);
			next.next = this.storage[index];
			this.storage[index] = next;
		}
	}

	remove(key) {
		const index = this.hash(key, this.capacity);
		let current = this.storage[index];
		let last;

		while (current && current.key != key) {
			last = current;
			current = last.next;
		}
		if (!current) {
			return -1;
		} else {
			if (last) {
				this.storage[index] = current.next;
			} else {
				last.next = current.next;
			}
		}
	}

	retrieve(key) {
		const index = this.hash(key, this.capacity);
		let current = this.storage[index];
		while (current) {
			if (current.key == key) {
				return current.value;
			}
			current = current.next;
		}
	}

	resize() {
		const newTable = new HashTable(2 * this.capacity);
		let current;
		for (entry in this.storage) {
			current = this.storage[entry];
			while (current) {
				newTable.insert(current.key, current.value);
				current = current.next;
			}
		}
		return newTable;
	}
}

const t = new HashTable(10);
t.insert("a", 341);
t.insert("b", 341);
t.insert("c", 341);
t.insert("e", 341);
t.insert("d", 341);
t.insert("f", 341);
t.insert("bakk", 341);
t.insert("akk", 341);
console.log(t.storage);
