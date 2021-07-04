#include <iostream>
#include <map>
#include <tuple>
#include <string>



using namespace std;


// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const{
  	return base.at(person);
  };
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
  	if(base.count(person)==0){
  		base[person][TaskStatus::NEW] = 0;
	  	base[person][TaskStatus::IN_PROGRESS] = 0;
	  	base[person][TaskStatus::TESTING] = 0;
	  	base[person][TaskStatus::DONE] = 0;
  	}
  	base[person][TaskStatus::NEW]++;
  };
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count){
  	TasksInfo shifted_tasks, old_tasks;
  	shifted_tasks[TaskStatus::NEW] = 0;
  	shifted_tasks[TaskStatus::IN_PROGRESS] = 0;
  	shifted_tasks[TaskStatus::TESTING] = 0;
  	shifted_tasks[TaskStatus::DONE] = 0;
  	if(base.count(person) == 0){
  		return tie(shifted_tasks, shifted_tasks);
  	}
  	old_tasks = base[person];
	if(task_count - old_tasks[TaskStatus::NEW] > 0){
	  	shifted_tasks[TaskStatus::IN_PROGRESS] = old_tasks[TaskStatus::NEW]; 
	  	task_count -= old_tasks[TaskStatus::NEW];
	  	if(task_count - old_tasks[TaskStatus::IN_PROGRESS] > 0){
	  		shifted_tasks[TaskStatus::TESTING] = old_tasks[TaskStatus::IN_PROGRESS]; 
		  	task_count -= old_tasks[TaskStatus::IN_PROGRESS];
		  	if(task_count - old_tasks[TaskStatus::TESTING] > 0){
		  		shifted_tasks[TaskStatus::DONE] = old_tasks[TaskStatus::TESTING]; 
			  	task_count -= old_tasks[TaskStatus::TESTING];
			} else {
			  	shifted_tasks[TaskStatus::DONE] = old_tasks[TaskStatus::TESTING] - task_count;
			}
		} else {
		  	shifted_tasks[TaskStatus::TESTING] = old_tasks[TaskStatus::IN_PROGRESS] - task_count;
		}
	} else {
		shifted_tasks[TaskStatus::IN_PROGRESS] = old_tasks[TaskStatus::NEW] - task_count; 
	}
	base[person][TaskStatus::NEW] -= shifted_tasks[TaskStatus::IN_PROGRESS];
	old_tasks[TaskStatus::NEW] -= shifted_tasks[TaskStatus::IN_PROGRESS];
	base[person][TaskStatus::IN_PROGRESS] += shifted_tasks[TaskStatus::IN_PROGRESS];
	base[person][TaskStatus::IN_PROGRESS] -= shifted_tasks[TaskStatus::TESTING];
	old_tasks[TaskStatus::IN_PROGRESS] -= shifted_tasks[TaskStatus::TESTING];
	base[person][TaskStatus::TESTING] += shifted_tasks[TaskStatus::TESTING];
	base[person][TaskStatus::TESTING] -= shifted_tasks[TaskStatus::TESTING];
	old_tasks[TaskStatus::TESTING] -= shifted_tasks[TaskStatus::TESTING];
	base[person][TaskStatus::DONE] += shifted_tasks[TaskStatus::TESTING];


	return tie(shifted_tasks, old_tasks);

  };

private:
	map<string, TasksInfo> base;
};



// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
