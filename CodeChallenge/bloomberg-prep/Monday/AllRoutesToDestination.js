/*
Print all paths from a given source to a destination
Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print all paths from given ‘s’ to ‘d’.
Consider the following directed graph. Let the s be 2 and d be 3. There are 4 different paths from 2 to 3.
[/home/creator/Desktop/bloomberg-prep/ChallengeAssets/allPaths.png]

Given a source node of 2 and a destination node of 3 print all possible paths from the image


User stories, someone wants to know all train paths to pick the most preferred one

Inputs: source, destination, directedGraph
output: paths [[2,1,3],[2,0,3],[2,0,1,3]]

Inputs: source, destination, directedGraph <-- empty or invalid
output: Unable to get paths with given inputs

Edge cases, if graph cyclic (have to detect)
DFS I need to detect cycles and its used to find paths between two nodes
How large will the graph be

*/

class Graph {
	constructor() {
		this.vertices = {};
		this.numV = 0;
		this.paths = [];
	}
	addVertex(vId, value) {
		this.vertices[vId] = new Set();
		this.numV += 1;
	}

	addEdge(v1, v2) {
		if (this.vertices[v1] && this.vertices[v2]) {
			this.vertices[v1].add(v2);
		}
	}
	getNeighbors(vId) {
		return this.vertices[vId];
	}
	dfsContainer(sV, dV) {
		this.paths = [];
		this.dfs(sV, dV);
		return this.paths;
	}
	dfs(sV, dV, currentPath = new Set(), curr = undefined) {
		if (curr === undefined) {
			curr = sV;
		}
		currentPath.add(curr);
		if (curr === dV) {
			this.paths.push(currentPath);
		} else {
			const neighbors = this.getNeighbors(curr);
			for (let neighbor of neighbors) {
				if (neighbor != sV && !currentPath.has(neighbor)) {
					const newPath = new Set(currentPath);
					this.dfs(sV, dV, newPath, neighbor);
				}
			}
		}
	}
}

const G = new Graph();
G.addVertex(2, 2);
G.addVertex(1, 1);
G.addVertex(0, 0);
G.addVertex(3, 3);
G.addEdge(2, 1);
G.addEdge(2, 0);
G.addEdge(0, 1);
G.addEdge(0, 2);
G.addEdge(1, 3);
G.addEdge(0, 3);
console.log(G.dfsContainer(2, 3));
