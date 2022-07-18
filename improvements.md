# List of potential improvements for the repo
- Loop unrolling in applyModifierPPM()
- Conditionals in applyModifierPPM() might be able to be improved
- Are our assignments to struct objects adding unnecessary operations?
- Switch clamping in ycbr_to_rgb() to use QADD in assembly
- Lots of division in the colors functions, maybe try operator strength reduction and use multiplication? Maybe we could scale up by a power of 2 to get rid of the floating points and then bit shift instead of divide