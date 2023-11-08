import sys
import pygame
import math
import random

if len(sys.argv) < 3:
    print("Usage: random-connections.py [number of points] [probability]")
    sys.exit(1)

n = int(sys.argv[1])
p = float(sys.argv[2])

# Initialize
pygame.init()
WIDTH, HEIGHT = 640, 480
RADIUS = 100
WHITE = (255, 255, 255)
GREY = (127, 127, 127)
BLACK = (0, 0, 0)

# Create the window
screen = pygame.display.set_mode((WIDTH, HEIGHT))

# Fill the window with black color
screen.fill(BLACK)

# draw the circle
points = []
for i in range(n):
    angle = 2 * math.pi * i / n
    # x coordinate
    x = WIDTH // 2 + RADIUS * math.cos(angle)
    # y coordinate
    y = HEIGHT // 2 + RADIUS * math.sin(angle)
    # save the points for later
    points.append((x, y))

    # draw a point with circle
    pygame.draw.circle(screen, WHITE, (int(x), int(y)), 5)

# connect with probability p each of the points.
for i in range(0, len(points), 2):
    if random.random() <= p:
        pygame.draw.line(screen, GREY, points[i], points[i + 1], 3)


# Update the display
pygame.display.flip()

# Run until the user asks to quit
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

# Quitting
pygame.quit()
