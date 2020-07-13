# Write a function solution(area) that takes as its input a single unit of measure representing the total area of solar panels you have (between 1 and 1000000 inclusive) and returns a list of the areas of the largest squares you could make out of those panels, starting with the largest squares first. So, following the example above, solution(12) would return [9, 1, 1, 1]


# -- Python cases --
# Input:
# solution.solution(15324)
# Output:
#     15129,169,25,1

# Input:
# solution.solution(12)
# Output:
#     9,1,1,1

# Python
# ======
# Your code will run inside a Python 2.7.13 sandbox. All tests will be run by calling the solution() function.

# Standard libraries are supported except for bz2, crypt, fcntl, mmap, pwd, pyexpat, select, signal, termios, thread, time, unicodedata, zipimport, zlib.

# Input/output operations are not allowed.

# Your solution must be under 32000 characters in length including new lines and and other non-printing characters.
import math
from performance_tester import performance_tester

def solution(area):
    largest_squares = []
    def find_squares(number):
      if number > 0:
          rounded_square= int(math.sqrt(number))
          left_overs = (number-(rounded_square)**2)
          largest_squares.append(rounded_square**2)
          find_squares(left_overs) 
    find_squares(area)
    return largest_squares

print(solution(12))
print(sum(solution(12)))
# performance_tester([solution], [80, 400, 7000, 133940, 9999999, 19021908389248923])
