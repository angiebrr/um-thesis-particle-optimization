ParticleEffectComponent::Render(camera)
{
  // Use the Particle Drawable to draw particles to the screen
  if(this.playbackState is playing or this.playbackState is stopping)
    this.drawable->Draw(camera);
}

Drawable::Draw(camera)
{
  // Lock the Concurrent Particle Data object
  this.concurrentParticleData.Lock();

  // Activate the newly emitted particles in the static billboard  
  for(particleIndex in this.concurrentParticleData.GetNewParticleIndices())
  {
    ActivateParticleInBillboard(particleIndex);
  }

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData.GetParticleArray(), camera);

  // Unlock the Concurrent particle Data object
  this.concurrentParticleData.Unlock();
}