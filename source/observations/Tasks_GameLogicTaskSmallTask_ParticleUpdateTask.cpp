ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a SMALL TASK
  if (currTaskType is TaskType::small)
  {
  	ApplicationTaskScheduler.ScheduleTask(TaskType::small, 
    {
      ParticleUpdateTask(copiedAtts);
    });
  }
  // Schedule a GAME LOGIC TASK
  else if (currTaskType is TaskType::gameLogic)
  {
  	ApplicationTaskScheduler.ScheduleTask(TaskType::gameLogic, 
    {
      ParticleUpdateTask(copiedAtts);
    });
  }
}