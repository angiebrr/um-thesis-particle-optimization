ParticleUpdateTask(copiedAtts)
{
  // Use Shiny macro to profile the entire block
  PROFILE_SHARED_BLOCK(ParticleUpdateTask);

  // Use Shiny macros to profile outside and inside of the 
  // particle iteration loop
  PROFILE_SHARED_BEGIN(ParticleIter_OuterLoop);
  for(particle : copiedAtts.particleArray)
  {
    PROFILE_SHARED_BEGIN(ParticleIter_InnerLoop);
    if(particle.isActive)
    {
      particle.UpdateValues();
    }
    PROFILE_END();
  }
   PROFILE_END();
  
  // ... and so on
}