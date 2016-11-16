ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a small task to update the particle in the background
  ApplicationTaskScheduler.ScheduleTask(TaskType::small, 
  {
    ParticleUpdateTask(copiedAtts);
  });
}