import sys
import pygame
import math
import random

if len(sys.argv) < 5:
    print("Usage: histogram.py [n] [lo] [hi] [bins]")
    sys.exit(1)

n = int(sys.argv[1])
lo = float(sys.argv[2])
hi = float(sys.argv[3])
bins = int(sys.argv[4])

data = sorted([random.randint(lo, hi) for _ in range(n)])

bin_width = (hi - lo) / bins
freqs = [0 for _ in range(bins)]
dataIdx = 0
for i in range(bins):
    left = bin_width * i
    right = left + bin_width
    freq = 0
    while dataIdx < len(data) and data[dataIdx] <= right:
        dataIdx += 1
        freq += 1
    freqs[i] = freq
print("Data:", data)
print("BinWidth:", bin_width)
print("Freqs:", freqs)

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

# draw the histogram
# maximum frequency to scale the bins
max_freq = max(freqs)

# 25px margin
left_margin = 25
top_margin = 25
# 25 padding for each side
graph_bin_width = (WIDTH - 2 * left_margin) // bins
for i in range(bins):
    left = graph_bin_width * i
    right = left + graph_bin_width
    height = freqs[i] / max_freq * HEIGHT // 2
    pygame.draw.rect(
        screen,
        WHITE,
        (
            left_margin + left,
            HEIGHT // 2 - height + top_margin,
            graph_bin_width,
            height,
        ),
        1,
    )


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
