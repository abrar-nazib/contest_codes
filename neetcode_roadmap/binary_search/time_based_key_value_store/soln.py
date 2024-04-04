class TimeMap:

    def __init__(self):
        self.t = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if not key in self.t:
            self.t[key] = []
            self.t[key].append((timestamp, value))
        else:
            self.t[key].append((timestamp, value))

        # print(self.t)

    def get(self, key: str, timestamp: int) -> str:
        if key in self.t:
            arr = self.t[key]
            if arr[0][0] > timestamp:
                return ""
            l, r = 0, len(arr) - 1

            while(l <= r):
                mid = (l+r) // 2
                if(arr[mid][0] > timestamp):
                    r = mid - 1
                elif(arr[mid][0] < timestamp):
                    l = mid + 1
                else:
                    return arr[mid][1]
            return arr[l-1][1]
        else:
            return ""
timemap = TimeMap()
timemap.set("a","bar",1)
timemap.set("x","b",3)
print(timemap.get("b",3))  # Add print here
timemap.set("foo","bar2",4)
print(timemap.get("foo",4))  # Add print here
print(timemap.get("foo",5))  # Add print here
