#include <vector>
#include <optional>
#include <iostream>

using namespace std;

class Task
{
public:
    int d, p;
    Task(int d, int p);
};

Task::Task(int d, int p) : d(d), p(p) {}

class TaskHeap
{
public:
    TaskHeap(vector<Task> tasks);
    optional<Task> pop();

private:
    vector<Task> heap;
    void swap(int i, int j);
    void heapify_down(int i);
};

TaskHeap::TaskHeap(vector<Task> tasks)
{
    this->heap = tasks;
    for (int i = this->heap.size() - 1; i >= 0; i--)
    {
        this->heapify_down(i);
    }
}

optional<Task> TaskHeap::pop()
{
    if (this->heap.size() == 0)
    {
        return optional<Task>();
    }

    this->swap(0, this->heap.size() - 1);
    Task t = this->heap.back();
    this->heap.pop_back();
    this->heapify_down(0);
    return t;
}

void TaskHeap::swap(int i, int j)
{
    Task tmp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = tmp;
}

void TaskHeap::heapify_down(int i)
{
    int j = i;
    for (int k = 1; k <= 2; k++)
    {
        int c = 2 * i + k;
        if (c < this->heap.size() && this->heap[c].d < this->heap[j].d)
        {
            j = c;
        }
    }

    if (j == i)
    {
        return;
    }

    this->swap(i, j);
    this->heapify_down(j);
}

int solve(vector<Task> tasks)
{
    TaskHeap th = TaskHeap(tasks);
    int ans = 0;
    while (auto t = th.pop())
    {
        ans = max<int>(ans, t->d) + t->p;
    }

    return ans;
}

int main()
{
    string line;
    while (getline(cin, line) && !line.empty())
    {
        int n = stoi(line);

        vector<Task> tasks;
        for (auto i = 0; i < n; i++)
        {
            getline(cin, line);
            int d, p;
            sscanf(line.c_str(), "%d %d", &d, &p);
            tasks.push_back(Task(d, p));
        }

        cout << solve(tasks) << endl;
    }

    return 0;
}
