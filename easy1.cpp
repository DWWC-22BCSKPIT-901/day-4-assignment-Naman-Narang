#include <iostream>
#include <queue>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue, sandwichQueue;
    int count = 0;
    for (int student : students) {
        studentQueue.push(student);
    }
    for (int sandwich : sandwiches) {
        sandwichQueue.push(sandwich);
    }

    while (!studentQueue.empty() && count < studentQueue.size()) {
        if (studentQueue.front() == sandwichQueue.front()) {
            studentQueue.pop();
            sandwichQueue.pop();
            count = 0; 
        } else {
            int frontStudent = studentQueue.front();
            studentQueue.pop();
            studentQueue.push(frontStudent);
            count++;
        }
    }

    return studentQueue.size();
}

int main() {
    int n; 
    cout << "Enter the number of students and sandwiches: ";
    cin >> n;

    vector<int> students(n), sandwiches(n);
    cout << "Enter students' preferences (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cout << "Enter sandwiches stack (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> sandwiches[i];
    }

    cout << "Number of students unable to eat: " << countStudents(students, sandwiches) << endl;

    return 0;
}
