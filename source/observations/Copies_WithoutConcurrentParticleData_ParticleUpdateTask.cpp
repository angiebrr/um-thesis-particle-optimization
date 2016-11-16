ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a task to update the particle in the background
  ApplicationTaskScheduler.ScheduleTask
  ({
    // Lock the mutex for the whole task
    using lock(this.mutex)
    {
      ParticleUpdateTask(copiedAtts);
    }
  });
}

ParticleUpdateTask(copiedAtts)
{
  // Update particles if they are active
  for(particle : copiedAtts.particleArray)
  {
    if(particle.isActive)
    {
      particle.UpdateValues();
    }
  }
  
  // Apply affectors
  for(affector : copiedAtts.particleAffectors)
  {
    affector.AffectParticles();
  }
  
  // Try to emit
  newParticleIndices = copiedAtts.particleEmitter.EmitParticles();
  
  // Append the new indices to the member new indices array
  copiedAtts.newParticleIndices.append( newParticleIndices.copy() );
  
  // Update member bounding shapes; lock the bounding shapes mutex
  using lock(copiedAtts.boundingMutex)
  {
    copiedAtts.AABB, copiedAtts.Sphere = CalculateBoundingShapes();
  }
}