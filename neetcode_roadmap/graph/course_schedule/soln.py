from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Convert edges into adjoint list
        adj_list = {i: [] for i in range(numCourses)}
        for prerequisite in prerequisites:
            adj_list[prerequisite[0]].append(prerequisite[1])
        visited = set()

        def is_finishable(key):
            if key in visited:
                # print(f"Key in visited: {key}")
                return False
            if adj_list[key] == []:
                return True
            visited.add(key)
            finishable = all(is_finishable(neighbor) for neighbor in adj_list[key])
            if finishable:
                adj_list[key] = []
            # print(f"Finishable: {finishable}")
            visited.remove(key)
            return finishable

        for key in adj_list.keys():
            visited = set()
            if not is_finishable(key):
                return False

        return True


soln = Solution()
numCourses = 2
prerequisites = [[1, 0]]
print(soln.canFinish(numCourses, prerequisites))
numCourses = 2
prerequisites = [[1, 0], [0, 1]]
print(soln.canFinish(numCourses, prerequisites))
numCourses = 2
prerequisites = [[0, 1], [1, 0]]
print(soln.canFinish(numCourses, prerequisites))
numCourses = 20
prerequisites = [[0, 10], [3, 18], [5, 5], [6, 11], [11, 14], [13, 1], [15, 1], [17, 4]]
print(soln.canFinish(numCourses, prerequisites))
numCourses = 3
prerequisites = [[1, 0], [0, 2], [2, 1]]
print(soln.canFinish(numCourses, prerequisites))
numCourses = 3
prerequisites = [[0, 1], [0, 2], [1, 2]]
print(soln.canFinish(numCourses, prerequisites))
