ParticleEffectComponent::OnUpdate()
{
  // Get a struct containing copies (and pointers) to pass to the task
  copiedAtts = CopyUpdateAttributes();

  // Schedule a task to update the particle in the background
  ApplicationTaskScheduler.ScheduleTask
  ({
    ParticleUpdateTask(copiedAtts);
  });
}

ParticleUpdateTask(copiedAtts)
{
  // Update particles if they are active
  for(particle : copiedAtts.particleArray)
  {
    if(particle.isActive)
      particle.UpdateValues();
  }
  
  // Apply affectors
  for(affector : copiedAtts.particleAffectors)
  {
    affector.AffectParticles();
  }
  
  // Try to emit
  newParticleIndicesArray = copiedAtts.particleEmitter.EmitParticles();
  
  // Update bounding shapes
  AABB, Sphere = CalculateBoundingShapes();
  
  // Copy this updated data to the concurrent particle data object
  copiedAtts.particleConcurrentParticleData.CommitParticleData
                                            (particleArray, 
                                            newParticleIndicesArray, 
                                            AABB, Sphere);
}