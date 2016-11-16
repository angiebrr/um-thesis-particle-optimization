ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a game logic task to update the particle in the background
  ApplicationTaskScheduler.ScheduleTask(TaskType::gameLogic, 
  {
    ParticleUpdateTask(copiedAtts);
  });
}