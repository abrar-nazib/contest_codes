class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> cars;
        stack<pair<int, int>> cars_stack;
        for (int i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first > b.first; });
        for (auto &car : cars)
        {
            if (cars_stack.size() == 0)
            {
                cars_stack.push(car);
                continue;
            }
            pair<int, int> top_car = cars_stack.top();
            double t_top = (double)(target - top_car.first) / (double)top_car.second;
            double t_car = (double)(target - car.first) / (double)car.second;
            // cout << t_top << " " << t_car << "\n";
            if (t_top < t_car)
            {
                cars_stack.push(car);
            }
        }

        return cars_stack.size();
    }
};