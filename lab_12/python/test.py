import lib
from lib import *

def check(expt, real, i):
    if expt == real: print(i, " : PASS")
    else: print(i , " : FAIL")

def test1():
    expt = [1]
    real = [1]

    bycyclic(expt, 4)
    check(expt, real, 1)

def test2():
    expt = [1, 3, 2, 4]
    real = [2, 4, 1, 3]

    bycyclic(expt, 2)
    check(expt, real, 2)

def test3():
    expt = [1, 2, 3, -1, 3, -5]
    real = [-1, 3, -5, 1, 2, 3]
    
    bycyclic(expt, 21)
    check(expt, real, 3)    

def test4():
    inarr = [1, 4, 9, 16, 25, 36]
    expt = [1, 4, 9, 16, 25, 36]
    real = [0]*6
    
    squares(expt, real)
    check(expt, real, 1)

def test7():
    inarr = [1, 5, 9, 17, 25, -36]
    expt = [1, 9, 25]
    real = [0]*3
    
    squares(expt, real)
    check(expt, real, 4)

def test5():
    inarr = [0]*2
    expt = [0, 0]
    real = [0]*2
    
    squares(expt, real)
    check(expt, real, 2)   

def test6():
    inarr = []
    expt = []
    real = []

    squares(expt, real)
    check(expt, real, 3)

def main():
    print("{:^79}".format("Tests cyrcle shift run >> "))
    test1()
    test2()
    test3()
    
    print("{:^79}".format("Tests find squares run >> "))
    test4()
    test5()
    test6()
    test7()
    
if __name__ == '__main__':
    main()   
