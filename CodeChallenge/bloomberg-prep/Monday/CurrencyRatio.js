/*
Given stocks and conversion ratios such as USD/INR 1.3, EUR/CAD 2.3 
find the shortest coversion between any two currencies.
There may not necessarily be a direct conversaion
between the two currencies and so multiple conversaions may be required


Find a way to convert currencies with the least amounts of conversions

Input = startingNode destinationNode - Nodes{}
output = conversion path = Str[]

I require the information of countries and currency conversion rates
The fastest way to convert money

USD/INR
EUR/CAD 

if empty or invalid throw a error

EUR/USD=>1.2
USD/GBP=>0.75
GBP/AUD=>1.7
AUD/JPY=>90
GBP/JPY=>150
JPY/INR=>0.6

*/

class WeightedGraph {
	constructor() {
			this.adjacencyList = {};
	}
	addVertex(vertex){
			if(!this.adjacencyList[vertex]) this.adjacencyList[vertex] = [];
	}
	addEdge(vertex1,vertex2, weight){
			this.adjacencyList[vertex1].push({node:vertex2,weight});
			this.adjacencyList[vertex2].push({node:vertex1, weight});
	}
	Dijkstra(start, finish){
			const nodes = new PriorityQueue();
			const distances = {};
			const previous = {};
			let path = [] //to return at end
			let smallest;
			//build up initial state
			for(let vertex in this.adjacencyList){
					if(vertex === start){
							distances[vertex] = 0;
							nodes.enqueue(vertex, 0);
					} else {
							distances[vertex] = Infinity;
							nodes.enqueue(vertex, Infinity);
					}
					previous[vertex] = null;
			}
			// as long as there is something to visit
			while(nodes.values.length){
					smallest = nodes.dequeue().val;
					if(smallest === finish){
							//WE ARE DONE
							//BUILD UP PATH TO RETURN AT END
							while(previous[smallest]){
									path.push(smallest);
									smallest = previous[smallest];
							}
							break;
					} 
					if(smallest || distances[smallest] !== Infinity){
							for(let neighbor in this.adjacencyList[smallest]){
									//find neighboring node
									let nextNode = this.adjacencyList[smallest][neighbor];
									//calculate new distance to neighboring node
									let candidate = distances[smallest] + nextNode.weight;
									let nextNeighbor = nextNode.node;
									if(candidate < distances[nextNeighbor]){
											//updating new smallest distance to neighbor
											distances[nextNeighbor] = candidate;
											//updating previous - How we got to neighbor
											previous[nextNeighbor] = smallest;
											//enqueue in priority queue with new priority
											nodes.enqueue(nextNeighbor, candidate);
									}
							}
					}
			}
			return path.concat(smallest).reverse();     
	}
}

class PriorityQueue {
	constructor(){
			this.values = [];
	}
	enqueue(val, priority){
			let newNode = new Node(val, priority);
			this.values.push(newNode);
			this.bubbleUp();
	}
	bubbleUp(){
			let idx = this.values.length - 1;
			const element = this.values[idx];
			while(idx > 0){
					let parentIdx = Math.floor((idx - 1)/2);
					let parent = this.values[parentIdx];
					if(element.priority >= parent.priority) break;
					this.values[parentIdx] = element;
					this.values[idx] = parent;
					idx = parentIdx;
			}
	}
	dequeue(){
			const min = this.values[0];
			const end = this.values.pop();
			if(this.values.length > 0){
					this.values[0] = end;
					this.sinkDown();
			}
			return min;
	}
	sinkDown(){
			let idx = 0;
			const length = this.values.length;
			const element = this.values[0];
			while(true){
					let leftChildIdx = 2 * idx + 1;
					let rightChildIdx = 2 * idx + 2;
					let leftChild,rightChild;
					let swap = null;

					if(leftChildIdx < length){
							leftChild = this.values[leftChildIdx];
							if(leftChild.priority < element.priority) {
									swap = leftChildIdx;
							}
					}
					if(rightChildIdx < length){
							rightChild = this.values[rightChildIdx];
							if(
									(swap === null && rightChild.priority < element.priority) || 
									(swap !== null && rightChild.priority < leftChild.priority)
							) {
								 swap = rightChildIdx;
							}
					}
					if(swap === null) break;
					this.values[idx] = this.values[swap];
					this.values[swap] = element;
					idx = swap;
			}
	}
}

class Node {
	constructor(val, priority){
			this.val = val;
			this.priority = priority;
	}
}


let g = new WeightedGraph();
// USD/INR
// EUR/CAD
// EUR/USD=>1.2
// USD/GBP=>0.75
// GBP/AUD=>1.7
// AUD/JPY=>90
// GBP/JPY=>150
// JPY/INR=>0.6

g.addVertex("EUR");
g.addVertex("USD");
g.addVertex("GBP");
g.addVertex("AUD");
g.addVertex("JPY");
g.addVertex("INR");
g.addEdge("EUR", "USD", 1.2);
g.addEdge("USD", "GBP", 0.75);
g.addEdge("GBP", "AUD", 1.7);
g.addEdge("AUD", "JPY", 90);
g.addEdge("GBP", "JPY", 150);
g.addEdge("JPY", "INR", 1.2);
console.log(g.Dijkstra("USD", "INR"));
