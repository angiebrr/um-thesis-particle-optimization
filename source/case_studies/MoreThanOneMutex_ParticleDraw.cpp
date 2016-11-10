Drawable::Draw(camera)
{
  // Lock the particle new indices array
  this.concurrentParticleData->LockNewParticleIndices();

  // Activate the newly emitted particles in the static billboard  
  for(int index : this.concurrentParticleData->GetNewParticleIndices())
  {
    ActivateParticleInBillboard(index);
  }

  // Unlock the particle new indices array
  this.concurrentParticleData->UnlockParticleIndices();

  // Lock the particles array
  this.concurrentParticleData->LockParticles();

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData->GetParticleArray(), camera);

  // Unlock the particles array
  this.concurrentParticleData->UnlockParticles();
}