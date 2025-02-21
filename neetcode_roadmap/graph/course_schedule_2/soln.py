from typing import List

# 3 possible states of a course
# visited -> Course has been added to output
# visiting -> Course has been added to cycle
# unvisited -> Course has not been added to anything


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Build Adjacency list
        adj_list = {i: [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            adj_list[crs].append(pre)

        visited = set()
        cycle = set()
        output = []

        def dfs(crs):
            # Base Case 1
            if crs in cycle:
                return False
            # Base Case 2: Course already judged
            if crs in visited:
                return True

            cycle.add(crs)
            for prereq in adj_list[crs]:
                if not dfs(prereq):
                    return False
            cycle.remove(
                crs
            )  # Remove from cycle so that future iterations don't find this
            visited.add(crs)  # This node is visitable
            output.append(crs)
            return True

        for c in range(len(adj_list)):
            if not dfs(c):
                return []
        return output


soln = Solution()
numCourses = 2
prerequisites = [[1, 0]]
print(soln.findOrder(numCourses, prerequisites))
numCourses = 4
prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
print(soln.findOrder(numCourses, prerequisites))
numCourses = 1
prerequisites = []
print(soln.findOrder(numCourses, prerequisites))
print()
numCourses = 2
prerequisites = [[0, 1]]
print(soln.findOrder(numCourses, prerequisites))
