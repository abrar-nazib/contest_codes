import sys

def print_calender(date, month, year, week_day):
    week_dict = {
        'Sun': 0,
        'Mon': 1,
        'Tue': 2,
        'Wed': 3,
        'Thu': 4,
        'Fri': 5,
        'Sat': 6
    }
    # Check the how many days in the month of that year including the leap year
    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        leap_year = True
    else:
        leap_year = False

    if month in [1, 3, 5, 7, 8, 10, 12]:
        days = 31
    elif month in [4, 6, 9, 11]:
        days = 30
    elif leap_year:
        days = 29
    else:
        days = 28
    
    # Create the calender list
    calender = [' - '] * (5*7)
    week_day_index = week_dict[week_day]

    # Find out which day of the week is the first day of the month given the week_day and the date
    first_day_index = (week_day_index - (date - 1) % 7) % 7

    # print(first_day_index)
    x=1
    while(days > 0):
        if first_day_index >= (5*7):
            first_day_index = 0
        calender[first_day_index] = " " + str(x) if x >= 10 else "  " + str(x)
        x+=1
        first_day_index+=1
        days -= 1



    # Print the calender
    print("|---------------------------|")
    print("|Sun|Mon|Tue|Wed|Thu|Fri|Sat|")
    print("|---------------------------|")
    for i in range(0, len(calender), 7):
        print(f"|{calender[i]}|{calender[i+1]}|{calender[i+2]}|{calender[i+3]}|{calender[i+4]}|{calender[i+5]}|{calender[i+6]}|")
        print("|---------------------------|")
    print()


def main():
    # Input Format
    # 2

    # Read the number of test cases using sys.stdin.readline()
    t = int(sys.stdin.readline().strip()) 
    for a0 in range(t):
        # Read line using sys.stdin.readline()
        # Input format
        # 20/02/2024 Tue
        # 01/01/2000 Sat
        
        line = sys.stdin.readline().strip()
        date_str, week_day = line.split(" ")
        date, month, year = map(int, date_str.split("/"))
        print_calender(date, month, year, week_day)

main()
