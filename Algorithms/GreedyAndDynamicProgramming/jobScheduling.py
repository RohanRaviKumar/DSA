def schedule_jobs(job, n):
    timeline = [" " for _ in range(n+1)]
    res = []
    total_profit = 0
    job.sort(key = lambda x : x[2], reverse = True)

    for j in job:
        for slot in range(min(n, j[1]), 0, -1):
            if (timeline[slot] == " "):
                timeline[slot] = j[0]
                total_profit += j[2]
                res.append(j)
                break

    return res, total_profit

jobs = [
    ['a', 2, 100], 
    ['b', 1, 19], 
    ['c', 2, 27], 
    ['d', 1, 25], 
    ['e', 3, 15]
]

n = 2

ans, pro = schedule_jobs(jobs, n)

print("Scheduled jobs : ")

for i in ans:
    print("Job ID : ", i[0], ", Deadline : ", i[1], ", Profit : ", i[2])