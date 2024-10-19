import os
import sys
import threading

id = sys.argv[1]
num = sys.argv[2]
print("Problem Id: " + id)
print("Number of threads: " + num)
def runn(ThreadId, ProblemId) -> None:
    print("Thread " + str(ThreadId) + " started.")
    os.system("node main.js" + " " + str(ProblemId))
    print("Thread " + str(ThreadId) + " ended.")

print("Starting multi-threading work.")

for i in range(1, int(num) + 1):
    t = threading.Thread(target=runn, args=(i, id))
    t.start()