# 1. The most junior henchman (with the least seniority) gets exactly 1 LAMB.  (There will always be at least 1 henchman on a team.)
#     2. A henchman will revolt if the person who ranks immediately above them gets more than double the number of LAMBs they do.
#     3. A henchman will revolt if the amount of LAMBs given to their next two subordinates combined is more than the number of LAMBs they get.  (Note that the two most junior henchmen won't have two subordinates, so this rule doesn't apply to them.  The 2nd most junior henchman would require at least as many LAMBs as the most junior henchman.)
#     4. You can always find more henchmen to pay - the Commander has plenty of employees.  If there are enough LAMBs left over such that another henchman could be added as the most senior while obeying the other rules, you must always add and pay that henchman.

# Write a function called solution(total_lambs), where total_lambs is the integer number of LAMBs in the handout you are trying to divide. It should return an integer which represents the difference between the minimum and maximum number of henchmen who can share the LAMBs (that is, being as generous as possible to those you pay and as stingy as possible, respectively) while still obeying all of the above rules to avoid a revolt.  For instance, if you had 10 LAMBs and were as generous as possible, you could only pay 3 henchmen (1, 2, and 4 LAMBs, in order of ascending seniority), whereas if you were as stingy as possible, you could pay 4 henchmen (1, 1, 2, and 3 LAMBs). Therefore, solution(10) should return 4-3 = 1.


# A0 = 1
# An >= An1*2
# An >= An1+An2
# lim = 10 ^ 9

# def max_payout(lambs):
#   pass

# def min_payout(lambs):
#   pass

# def solution(lambs):
#   return max_payout(lambs) - min_payout(lambs)

# import base64
# from itertools import cycle

# message = input("Enter the encrypted message: ")

# key = bytes(input("Enter your Google username: "), "utf8")

# print(bytes(a ^ b for a, b in zip(base64.b64decode(message), cycle(key))))

def timeConversion(s):
    if s[-2:] == "PM":
        if s[1] == "8":
            return "20"+s[2:-2] 
        elif s[1] =="9":
            return "21"+s[2:-2]
        else:
            time = str(int(s[0])+1) + str(int(s[1])+2)+s[2:-2]
            return time
    else:
        if s[0] == "1" and s[1] == "2":
            return "00"+s[2:-2]
        else:
            return s[:-2]

print(timeConversion("12:05:45PM"))