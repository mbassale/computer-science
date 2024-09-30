import random

def estimate_pi(num_samples):
    num_inside_circle = 0

    for _ in range(num_samples):
        x = random.uniform(0, 1)
        y = random.uniform(0, 1)
        distance_squared = x**2 + y**2

        if distance_squared <= 1:
            num_inside_circle += 1

    pi_estimate = 4 * num_inside_circle / num_samples
    return pi_estimate

# Example usage
num_samples = 10000000
pi_estimate = estimate_pi(num_samples)
print(f"Estimated Pi = {pi_estimate}")

