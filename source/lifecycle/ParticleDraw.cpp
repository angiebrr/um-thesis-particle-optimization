ParticleEffectComponent::Render(camera)
{
  // Use the Particle Drawable to draw particles to the screen
  if(this.playbackState == playing or this.playbackState == stopping)
    this.drawable->Draw(camera);
}

Drawable::Draw(camera)
{
  // Lock the Concurrent Particle Data object
  this.concurrentParticleData->Lock();

  // Activate the newly emitted particles in the static billboard  
  for(int index : this.concurrentParticleData->GetNewParticleIndices())
  {
    ActivateParticleInBillboard(index);
  }

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData->GetParticleArray(), camera);

  // Unlock the Concurrent particle Data object
  this.concurrentParticleData->Unlock();
}