from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        car_arr = []
        fleet_stack=[]
        for i in range(len(position)):
            car_arr.append([position[i], speed[i]])

        car_arr.sort()
        for i in range(len(car_arr)-1, -1, -1):
            t_car = (target - car_arr[i][0])/car_arr[i][1]
            if fleet_stack == []:
                fleet_stack.append(t_car)
                continue
            t_top_car = fleet_stack[-1]
            
            if(t_car > t_top_car):
                fleet_stack.append(t_car)
        # print(fleet_stack)
        return len(fleet_stack)

def main():
    solution = Solution()

    # Example 1
    target1 = 12
    position1 = [10, 8, 0, 5, 3]
    speed1 = [2, 4, 1, 1, 3]
    output1 = solution.carFleet(target1, position1, speed1)
    print("Output 1: ", output1)  # Should print 3
    
    # Example 2
    target2 = 10
    position2 = [3]
    speed2 = [3]
    output2 = solution.carFleet(target2, position2, speed2)
    print("Output 2: ", output2)  # Should print 1

    # Example 3
    target3 = 100
    position3 = [0, 2, 4]
    speed3 = [4, 2, 1]
    output3 = solution.carFleet(target3, position3, speed3)
    print("Output 3: ", output3)  # Should print 1

if __name__ == "__main__":
    main()