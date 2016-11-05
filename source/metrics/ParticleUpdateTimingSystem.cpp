ParticleUpdateTask(copiedAtts)
{
  // Statically call the timing system to start a timer with hash key 
  // "ParticleUpdateTask".
  pUpdateTimerKey = TimingSystem::Start("ParticleUpdateTask");

  // Use the timing system to keep track of the outer and inner loop
  // times during particle iteration.
  pOutIterTimerKey = TimingSystem::Start("ParticleIter_OuterLoop");
  for(particle : copiedAtts.particleArray)
  {
    pInIterTimerKey = TimingSystem::Start("ParticleIter_InnerLoop");
    if(particle.isActive)
    {
      particle.UpdateValues();
    }
    TimingSystem::Stop("ParticleIter_InnerLoop", pInIterTimerKey);
  }
  TimingSystem::Stop("ParticleIter_OuterLoop", pOutIterTimerKey);
  
  // ... and so on

  // Stop the timer with hash key "ParticleUpdateTask" and the outputted 
  // timer key
  TimingSystem::Stop("ParticleUpdateTask", pUpdateTimerKey);
}