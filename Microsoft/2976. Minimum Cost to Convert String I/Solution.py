class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adjList = {}
        for i in range(len(original)):
            if original[i] not in adjList:
                adjList[original[i]] = {}
                #Aditya Seth.
            if changed[i] in adjList[original[i]]:
                if cost[i] < adjList[original[i]][changed[i]]:
                    adjList[original[i]][changed[i]] = cost[i]
            else:
                adjList[original[i]][changed[i]] = cost[i]
        def djik(src, dst):
            class Node:
                def __init__(self, val, weight):
                    self.val = val
                    self.weight = weight
                def __lt__(self, o):
                    return self.weight < o.weight
                def __eq__(self, o):
                    return self.weight == o.weight
            import heapq
            pq = []
            heapq.heappush(pq, Node(src, 0))
            dist = {}
            dist[src] = 0
            while (len(pq) > 0):
                curr = heapq.heappop(pq)
                if curr.val not in adjList:
                    continue
                for i in adjList[curr.val]:
                    if i not in dist:
                        dist[i] = float('inf')
                    if adjList[curr.val][i] + dist[curr.val] < dist[i[0]]:
                        dist[i] = adjList[curr.val][i]+dist[curr.val]
                        heapq.heappush(pq,Node(i, dist[i]))
            if dst not in dist:
                return -1
            return dist[dst]
        str1 = "abcdefghijklmnopqrstuvwxyz"
        find = {}
        for i in range(len(str1)):
            find[str1[i]] = {}
            for j in range(len(str1)):
                if i == j:
                    continue
                x = djik(str1[i], str1[j])
                find[str1[i]][str1[j]] = x
        res = 0
        for i in range(len(source)):
            if source[i] != target[i]:
                if target[i] not in find[source[i]] or find[source[i]][target[i]] == -1:
                    return -1
                res += find[source[i]][target[i]]  
        return res