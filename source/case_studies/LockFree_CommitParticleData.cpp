ConcurrentParticleData::CommitParticleData(particleArray, 
                                           newParticleIndicesArray, 
                                           AABB, Sphere)
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

    // Copy the particle now that we have ownership of it
    this.particleArray[i] = currentParticle.copySubset();

    // NEW -> Release the particle
    currentParticle.isContended = false;
  }
  
  // NEW -> Lock the mutex for the remainder of the function
  using lock(this.mutex)
  {  
    // Append the new indices to the member new indices array
    this.newParticleIndices.append( newParticleIndices.copy() );

    // Copy the bounding information to the member variables
    this.AABB = AABB.copy();
    this.Sphere = Sphere.copy();
  }
}