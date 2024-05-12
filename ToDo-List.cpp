#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Task {
  int id;
  string Task;
  bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;
public:
    // Add
    void AddTask(const string & description){
        Task task;
        task.id = tasks.size()+1;
        task.Task = description;
        task.completed = false;
        tasks.push_back(task);
    }
    // Display
    void DisplayTask(){
        if(tasks.size()<=0){
            cout<<"To Do list is empty!"<<endl;
        }
        for(const auto &task: tasks){
         cout<<"["<<task.id<<"] "<< task.Task<<" ";
         if(task.completed==true){
            cout<<"[Completed]";
         }
         cout<<endl;   
        }
    }
    // Completed
    void CompleteTask(int task_id){
        for(auto &task:tasks){
            if(task.id == task_id){
                task.completed = true;
                cout<<"Task marked as Completed"<<endl;
                return;
            }
        }
    }

};
int main(){
    ToDoList todolist;
    todolist.AddTask("Do Homework");
    todolist.AddTask("Study for test");
    string description;
    int task_id;
// Menu
    int choice = 0;
    do{
        cout<<"-------------------------TODO LIST-------------------------"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. Display Task"<<endl;
        cout<<"3. Mark task as Completed"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1: cout<< "Task : ";
                cin>>description; 
                todolist.AddTask(description);
                break;
        
        case 2: todolist.DisplayTask();
                break;
        
        case 3: cout<<"Enter task ID to mark Completed :";
                cin>>task_id; 
                todolist.CompleteTask(task_id);
                break;
        
        case 4: exit(0);
        
        default:cout<<"Please enter a valid choice!";
            break;
        }
        
    }while (choice!=4);
    
}

