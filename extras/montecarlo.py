import random
import sys
import time
import math

TARGET = 42

maxValue = int(sys.argv[1])

tries = 0

start = time.time()

while True:
    tries += 1
    x = random.randrange(0,maxValue)
    sqrtx = math.sqrt(x)
    powerx = math.pow(x,4.5)
    if x == TARGET:
        break

print "IT TOOK ME",tries,"IN",time.time()-start
