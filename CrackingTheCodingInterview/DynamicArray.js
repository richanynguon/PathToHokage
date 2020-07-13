class DynamicArray {
	constructor(value) {
		this.length = 0;
		this.size = value ? value * 2 : this.length * 2;
		this.storage = Array(this.size);
	}
	returnVal() {
		return this.storage.filter((element) => element != undefined);
	}
	resize() {
		this.size = this.length * 2;
		return Array(this.size);
	}
	splice(index, quantRemoved, ...insertedItems) {
		const restCount = arguments.length - 2;
		this.length += restCount - quantRemoved;
		if (this.length > this.size) {
			const newArr = this.resize();
			for (let i = 0; i < this.length; i++) {
				if (i === index) {
					let nextIdx = i;
					for (let j = 0; j < restCount; j++) {
						newArr[nextIdx] = insertedItems[j];
						nextIdx += 1;
					}
					i += restCount;
				} else {
					newArr[i] = this.storage[i];
				}
			}
			this.storage = newArr;
		} else {
			const newArr = Array(this.size);
			for (let i = 0; i < this.length; i++) {
				if (i === index) {
					let nextIdx = i ;
					for (let j = 0; j < restCount; j++) {
						newArr[nextIdx] = insertedItems[j];
						nextIdx += 1;
					}
					i += restCount;
				} else {
					newArr[i] = this.storage[i];
				}
			}
			this.storage = newArr;
		}
	}
	slice(start = 0, end = this.length) {
		const diff = end - start;
		const newArr = Array(diff);
		let counter = 0;
		let begin = Math.sign(start) == -1 ? this.length + start + 1 : start;
		let stop = Math.sign(end) == -1 ? this.length + end + 1 : end;
		for (let i = begin; i < stop; i++) {
			newArr[counter] = this.storage[i];
			counter += 1;
		}
		return newArr;
	}
	shift() {
		const firstVal = this.storage[0];
		let counter = 0;
		while (counter < this.length) {
			const nextIdx = counter + 1;
			this.storage[counter] = this.storage[nextIdx];
			counter += 1;
		}
		this.length -= 1;
		return firstVal;
	}
	unshift(...value) {
		const restCount = arguments.length > 1 ? arguments.length : 1;
		this.length += restCount;
		if (this.length > this.size) {
			const newArr = this.resize();
			for (let i = 0; i < restCount; i++) {
				newArr[i] = value[i];
			}
			let counter = 0;
			for (let i = restCount; i < this.length; i++) {
				newArr[i] = this.storage[counter];
				counter += 1;
			}
			this.storage = newArr;
		} else {
			for (let i = this.length; i < 0; i--) {
				this.storage[i] = this.storage[i - 1];
				if (i == restCount) {
					this.storage[i] = value[i];
				}
			}
		}
	}
	pop() {
		const lastIdx = this.length;
		this.length -= 1;
		const tempVal = this.storage[lastIdx];
		this.storage[lastIdx] = undefined;
		return tempVal;
	}
	push(...value) {
		const lastIdx = this.length;
		const restCount = arguments.length > 1 ? arguments.length : 1;
		this.length += restCount;
		if (this.length > this.size) {
			const newArr = this.resize();
			for (let i = 0; i < lastIdx; i++) {
				newArr[i] = this.storage[i];
			}
			for (let i = 0; i < restCount; i++) {
				newArr[lastIdx + i] = value[i];
			}
			this.storage = newArr;
		} else {
			for (let i = 0; i < restCount; i++) {
				this.storage[lastIdx + i] = value[i];
			}
		}
	}
	concat(value) {}
}
const arr = new DynamicArray();
arr.push(1);
arr.push(1);
arr.unshift(1, 2, 3);
console.log(arr.storage, arr.size, arr.length);
arr.splice(2, 1, 2,3,4,5,6,7,8,8,9)
console.log(arr.storage, arr.size, arr.length);
