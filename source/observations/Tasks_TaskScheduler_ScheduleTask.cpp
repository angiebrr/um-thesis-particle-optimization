TaskScheduler::ScheduleTask(taskType, task)
{
	switch(taskType)
	{
		// Add a task to the small thread task pool
		case TaskType::small: 
			this.smallTaskPool->AddTask(task); break;

		// Add a task to the large thread task pool
		case TaskType::large: 
			this.largeTaskPool->AddTask(task); break;

		// Add a task to the main thread task pool
		case TaskType::mainThread: 
			this.mainThreadTaskPool->AddTask(task); break;

		// Schedule the task as a small task, but be sure to notify when
		// all game logic tasks have been completed
		case TaskType::gameLogic
			ScheduleTask(TaskType::small,
			{
				task();
				if(--this.gameLogicTaskCount is 0)
					this.gameLogicCondition.notify();
			});

			this.gameLogicTaskCount++;

			break;

		// File tasks can also be scheduled, but how they work is unimportant
	}
}