import unittest
from soln import Solution


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_example1(self):
        nums = [1, 2, 3]
        expected = [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
        result = self.solution.permute(nums)
        print(f"Result: {sorted(result)}")
        print(f"Expected: {sorted(expected)}")
        self.assertEqual(sorted(result), sorted(expected))

    def test_example2(self):
        nums = [0, 1]
        expected = [[0, 1], [1, 0]]
        result = self.solution.permute(nums)
        print(f"Result: {sorted(result)}")
        print(f"Expected: {sorted(expected)}")
        self.assertEqual(sorted(result), sorted(expected))

    def test_example3(self):
        nums = [1]
        expected = [[1]]
        result = self.solution.permute(nums)
        print(f"Result: {result}")
        print(f"Expected: {expected}")
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
