from typing import List

class Solution:

    def encode(self, strs: List[str]) -> str:
        out_str = "";
        for s in strs:
            out_str += f"{s}willywonka"
        return out_str

    def decode(self, s: str) -> List[str]:
        str_list = s.split('willywonka')
        str_list.pop()
        return str_list
    
def main():
    solution = Solution()

    # Example 1
    input1 = ["neet", "code", "love", "you"]
    encoded1 = solution.encode(input1)
    decoded1 = solution.decode(encoded1)
    print(decoded1)  # should print: ['neet', 'code', 'love', 'you']

    # Example 2
    input2 = ["we", "say", ":", "yes"]
    encoded2 = solution.encode(input2)
    decoded2 = solution.decode(encoded2)
    print(decoded2)  # should print: ['we', 'say', ':', 'yes']

if __name__ == "__main__":
    main()