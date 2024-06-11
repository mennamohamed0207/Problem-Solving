
# 
#  *  Sayed has a distributed system that consists of multiple machines. Each machine requires a specific amount
#  of RAM, CPU and Disk units in order to run. So for example, Sayed knows that a single machine might
#  need 5 units of RAM (let’s call that R), 2 units of CPU (let’s call that C) and 1 unit of disk space (let’s
#  call that D) to run.
#  The cluster Sayed is working with has a maximum capacity of NR RAM units, NC CPU units and ND
#  disk units.
#  Help Sayed figure out the maximum number of machines he can run in his cluster.
#  Input
#  First line of input contains an integer T (1 T 30), representing the number of test cases, then T test
#  cases follow.
#  The first line of each test case contains 3 integers R, C, D representing the requirements needed by each
#  machine to run for RAM, CPU and Disk units respectively, where (1 RCD 100).
#  The second line of each test case contains 3 integers NR, NC, ND representing the maximum capacity for
#  RAM, CPU and Disk units available in the cluster respectively, where (1 NRNCND 100).
#  Output
#  For each test case, print a single integer representing the maximum number of machines that Sayed can
#  have in his cluster given the requirements.
#  Example
#  standard input
#  2
#  2 5 3
#  11 14 6
#  6 1 2
#  25 1 15
# standard output

#  2
#  1
# */
# /**
#  *  After you helped Sayed solve the easy version, he was able to find the maximum number of machines
#  he can have based on the requirements and the cluster capacity. But unfortunately, the numbers are not
#  good. So Sayed went to management and got a budget approved to purchase extra RAM, CPU and Disk
#  resources in order to get a higher number of machines.
#  So again, given a machine requires R RAM, C CPU and D Disk to run, and given that the current cluster
#  capacity is NR RAM units, NC CPU units and ND disk units. And this time, we are also given the price
#  of a RAM unit (PR), the price of a CPU unit(PC) and the price of a Disk unit (PD) and the total budget
#  Sayed has is N dollars.
#  Help Sayed figure out the maximum number of machines he can run in his cluster using the new budget
#  he has.
#  Input
#  First line of input contains an integer T (1 T 30), representing the number of test cases, then T test
#  cases follow.
#  The first line of each test case contains 3 integers R, C, D representing the requirements needed by each
#  machine to run for RAM, CPU and Disk units respectively, where (1 RCD 100).
#  The second line of each test case contains 3 integers NR, NC, ND representing the maximum capacity for
#  RAM, CPU and Disk units available in the cluster respectively, where (1 NRNCND 100).
#  The third line of each test case contains 3 integers PR, PC, PD representing the price of a single RAM,
#  CPU or Disk unit respectively, where (1 PRPCPD 100).
#  The forth line of each test case contains a single integer N representing the budget that Sayed has to buy
#  extra resources, where (1 N 109).
#  Output
#  For each test case, print a single integer representing the maximum number of machines that Sayed can
#  have in his cluster given the requirements and the budget he has.
#  Example
#  standard input
#  2
#  2 5 3
#  11 14 6
#  2 2 5
#  70
#  6 1 2
#  25 1 15
#  2 2 2
#  1
#   standard output

#  5
#  1
#  Note
#  Download the input.txt file and run your code locally, then upload an output.txt file with your answers
#  like in the output section

def solve(r, c, d, nr, nc, nd):
    return min(nr // r, nc // c, nd // d)

def solve_with_budget(r, c, d, nr, nc, nd, pr, pc, pd, n):
    max_machines = solve(r, c, d, nr, nc, nd)
    for i in range(1, n+1):
        for j in range(1, n+1):
            for k in range(1, n+1):
                cost = i * pr + j * pc + k * pd
                if cost <= n:
                    max_machines = max(max_machines, solve(r, c, d, nr+i, nc+j, nd+k))
    return max_machines

testcases = int(input())
results=[]
for _ in range(testcases):
    r, c, d = map(int, input().split())
    nr, nc, nd = map(int, input().split())
    pr, pc, pd = map(int, input().split())
    n = int(input())
    results.append(solve_with_budget(r, c, d, nr, nc, nd, pr, pc, pd, n))

for i in results:
    print(i)