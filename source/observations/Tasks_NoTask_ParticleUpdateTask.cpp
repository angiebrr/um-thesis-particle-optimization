ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Do not schedule a task
  ParticleUpdateTask(copiedAtts);
}