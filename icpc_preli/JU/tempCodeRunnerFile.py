
    Print the calender
    print("|---------------------------|")
    print("|Sun|Mon|Tue|Wed|Thu|Fri|Sat|")
    print("|---------------------------|")
    for i in range(0, len(calender), 7):
        print("|" + "|".join(calender[i:i+7]) + "|")
        print("|---------------------------|")
