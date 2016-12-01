Drawable::Draw(camera)
{
  // NEW -> Lock the particle new indices array
  this.concurrentParticleData.LockNewParticleIndices();

  // Activate the newly emitted particles in the static billboard  
  for(particleIndex in this.concurrentParticleData.GetNewParticleIndices())
  {
    ActivateParticleInBillboard(particleIndex);
  }

  // NEW -> Unlock the particle new indices array
  this.concurrentParticleData.UnlockParticleIndices();

  // NEW -> Lock the particles array
  this.concurrentParticleData.LockParticles();

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData.GetParticleArray(), camera);

  // NEW -> Unlock the particles array
  this.concurrentParticleData.UnlockParticles();
}