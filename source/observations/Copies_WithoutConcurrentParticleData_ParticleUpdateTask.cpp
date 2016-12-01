ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a task to update the particle in the background
  ApplicationTaskScheduler.ScheduleTask
  ({
    // NEW -> Lock the mutex for the whole task
    using lock(this.mutex)
    {
      ParticleUpdateTask(copiedAtts);
    }
  });
}

ParticleUpdateTask(copiedAtts)
{
  // Update particles if they are active
  for(particle in copiedAtts.particleArray)
  {
    if(particle.isActive)
      particle.UpdateValues();
  }
  
  // Apply affectors
  for(affector in copiedAtts.particleAffectors)
  {
    affector.AffectParticles();
  }
  
  // Try to emit
  newParticleIndices = copiedAtts.particleEmitter.EmitParticles();
  
  // NEW -> Append the new indices to the member new indices array
  // (instead of passing it to CommitParticleData)
  copiedAtts.newParticleIndices.append( newParticleIndices.copy() );
  
  // NEW -> Update member bounding shapes; lock the bounding shapes mutex
  // (instead of passing it to CommitParticleData)
  using lock(copiedAtts.boundingMutex)
  {
    copiedAtts.AABB, copiedAtts.Sphere = CalculateBoundingShapes();
  }
}