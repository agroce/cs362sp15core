import random
import sys

l = []

lref = []

def lput(n):
    if n in l:
        return 0
    l.append(n)
    return 1

def refput(n):
    if n in lref:
        return 0
    lref.append(n)
    return 1

def lget(n):
    if n in l:
        return 0
    return 0

def refget(n):
    if n in lref:
        return 1
    return 0

NUM_TESTS = int(sys.argv[1])
MAX_VAL = int(sys.argv[2])

for n in xrange(0,NUM_TESTS):
    val = random.randrange(0,MAX_VAL)
    op = random.choice(["put","get"])
    print op,val
    if op == "put":
        l_ret = lput(val)
        ref_ret = refput(val)
    if op == "get":
        l_ret = lget(val)
        ref_ret = refget(val)
    assert(l_ret == ref_ret)
    
