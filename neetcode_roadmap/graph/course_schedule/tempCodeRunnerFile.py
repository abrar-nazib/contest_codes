class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Convert edges into adjoint list
        adj_list = {i: [] for i in range(numCourses)}
        for prerequisite in prerequisites:
            adj_list[prerequisite[0]].append(prerequisite[1])
        visited = set()

        def is_finishable(key):
            if key in visited:
                return False
            visited.add(key)
            if adj_list[key] == []:
                return True
            finishable = all(is_finishable(neighbor) for neighbor in adj_list[key])
            if finishable:
                adj_list[key] = []
            return finishable

        for key in adj_list.keys():
            visited = set()
            if not is_finishable(key):
                return False

        return True