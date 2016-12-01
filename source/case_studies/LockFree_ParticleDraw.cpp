Drawable::Draw(camera)
{
  // NEW -> Lock the concurrent particle data object only for new indices
  this.concurrentParticleData.Lock();

  // Activate the newly emitted particles in the static billboard  
  for(particleIndex in this.concurrentParticleData.GetNewParticleIndices())
  {
    ActivateParticleInBillboard(particleIndex);
  }

  // NEW -> Unlock the concurrent particle data object only for new indices
  this.concurrentParticleData.Unlock();

  // Iterate through all of the particles and draw each one
  DrawParticles(this.concurrentParticleData.GetParticleArray(), camera);
}

StaticBillboardDrawable::DrawParticles(particleArray, camera)
{
  // Copy over all particles to the member particle array
  for(i = 0 to particleArray.size())
  {
    // NEW -> Retrieve the particle, but we don't have ownership of it yet
    currentParticle = particleArray[i];
    gotOwnershipOfParticle = false;

    // NEW -> Keep spinning if *isContended* is true.
    // Set it to true once it is false.
    while(gotOwnershipOfParticle is false)
    {
      gotOwnershipOfParticle = currParticle.isContended
                                           .CompareExchange(false, true);
    }

    // Render the particle if it is active and is activated in the billboard
    if(currentParticle.isActive and currentParticle is in particleBillboard)
    {
      Render(currentParticle);
    }

    // NEW -> Release the particle
    currentParticle.isContended = false;
  }
}