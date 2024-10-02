class Task:
    def __init__(self, d: int, p: int) -> None:
        self.d = d
        self.p = p

class TaskHeap:
    def __init__(self, tasks: list[Task]) -> None:
        self.heap = tasks
        for i in range(len(tasks)-1, -1, -1):
            self.min_heapify_down(i)

    def swap(self, i: int, j: int) -> None:
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def min_heapify_down(self, i: int) -> None:
        j = i
        while True:
            for c in [2*i+1, 2*i+2]:
                if c < len(self.heap) and self.heap[c].d < self.heap[j].d:
                    j = c
            
            if j == i: break

            self.swap(i, j)
            i = j
    
    def pop(self) -> Task:
        if len(self.heap) == 0:
            return None
        
        self.swap(0, len(self.heap)-1)
        t = self.heap.pop()
        self.min_heapify_down(0)
        return t

def solve(tasks: list[Task]) -> int:
    th = TaskHeap(tasks)

    end_time = 0
    while t := th.pop():
        end_time = max(end_time, t.d) + t.p
    
    return end_time

while True:
    try:
        inp = input()
        if inp == '': break

        num_tasks = int(inp)

        tasks = []
        for _ in range(num_tasks):
            d, p = input().split(' ')
            tasks.append(Task(int(d), int(p)))
        
        print(solve(tasks))

    except EOFError:
        break
