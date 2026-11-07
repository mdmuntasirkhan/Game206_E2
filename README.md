# Game206_E2

Developed with Unreal Engine 5.7.
GAME206 Exercise 3: Networked Gameplay AI.

GitHub username: mdmuntasirkhan
Release: v0.8-Exercise3.0

## What is in this build

- **Treasure chest spawner:** randomized and replicated, so both players see the same chests.
- **Mobile Sentry v1 (the sheep):** Pawn Sensing. It wanders and chases, replicated.
- **Mobile Sentry v2 (the spider):** Behaviour Tree with Explore (look around, wait, wander) and Chase. It chases both players, because the target is stored in the Blackboard.

## Creative addition

I modeled and rigged both creatures myself in Blender. The sheep has Idle, Walk and Run animations, and the spider has 8 (Idle, Creep, Walk, Skitter, Run and three Attacks). In Unreal, the sheep plays its Walk animation and the spider uses a Blend Space and an Animation Blueprint to change animation with its speed. It's working okay but not perfect yet. I'm still learning rigging and animation and how they work together, and I hope to get better over time.

In Unreal, the sheep plays its Walk animation. The spider uses a Blend Space and an Animation Blueprint, so its animation changes with how fast it moves. The extra animations (Skitter, attacks) are ready for later use.