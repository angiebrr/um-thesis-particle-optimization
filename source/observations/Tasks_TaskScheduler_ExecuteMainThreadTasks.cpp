TaskScheduler::ExecuteMainThreadTasks()
{
	// Use a lock, mutex, and condition variable to wait
	// until we are notified to continue.
	using lock(this.gameLogicMutex) as lock
	{
		while(this.gameLogicTaskCount is not 0)
			this.gameLogicCondition.wait(lock);
	}

	this.mainThreadTaskPool.PerformTasks();
}