Drawable::Draw(camera)
{
  // Lock the concurrent particle data object
  this.concurrentParticleData->Lock();

  // Activate the newly emitted particles in the static billboard  
  for(int index : this.concurrentParticleData->GetNewParticleIndices())
  {
    ActivateParticleInBillboard(index);
  }

  // Unlock the concurrent particle data object
  this.concurrentParticleData->Unlock();

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData->GetParticleArray(), camera);
}

StaticBillboardDrawable::DrawParticles(particleArray, camera)
{
  // Copy over all particles to the member particle array
  for(i = 0 to particleArray.size())
  {
    // Retrieve the particle, but we don't have ownership of it yet
    currentParticle = particleArray[i];
    gotOwnershipOfParticle = false;

    // Keep spinning if *isContended* is true.
    // Set it to true once it is false.
    while(gotOwnershipOfParticle is false)
    {
      gotOwnershipOfParticle = currParticle.isContended
                                           .CompareAndSet(false, true);
    }

    // Render the particle if it is active and is activated in the billboard
    if(currentParticle is active and currentParticle is in particleBillboard)
    {
      Render(currentParticle);
    }

    // Release the particle
    currentParticle.isContended = false;
  }
}