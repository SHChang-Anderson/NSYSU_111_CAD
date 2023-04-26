# Test Pattern Generation Experiment on a Circuit

## Objective

The objective of this experiment is to generate a minimum set of input patterns to test various inputs and outputs stuck-at-fault.

## Methodology

1. Create a logic gate based on the given circuit diagram.
2. Record correct outputs for all input combinations.
3. Test 16 input combinations for stuck-at-0 and stuck-at-1 situations.
4. Record the results in different arrays and compare them to the correct outputs.
5. If the results do not match, the input pattern is considered a possible stuck-at-fault input pattern.
6. Use the greedy algorithm to find the minimum set of input patterns.

## Results

The experiment successfully generated a minimum set of input patterns to test various inputs and outputs stuck-at-fault. The results were recorded in different arrays and compared to the correct outputs, and any discrepancies were noted. The greedy algorithm was used to find the minimum set of input patterns, and the experiment successfully met its objective.

## Conclusion

The experiment proved successful in generating a minimum set of input patterns to test various inputs and outputs stuck-at-fault. This methodology can be applied to other circuits as well to ensure accurate testing and efficient use of resources.

GCC version used for this experiment: gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
