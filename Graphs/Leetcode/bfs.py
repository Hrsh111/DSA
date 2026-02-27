import matplotlib.pyplot as plt
import numpy as np
import time

def visualize_bfs(grid):
    # Helper function to plot the grid
    def plot_grid(grid, current=None, neighbors=None, title="Grid"):
        plt.clf()  # Clear the previous frame
        cmap = plt.cm.get_cmap('Greys', 2)  # Use a binary colormap (0=black, 1=white)
        plt.imshow(grid, cmap=cmap, interpolation='none')

        # Highlight the current cell
        if current:
            plt.scatter(current[1], current[0], color='red', label='Current', s=100)

        # Highlight the neighbors
        if neighbors:
            for r, c in neighbors:
                plt.scatter(c, r, color='blue', label='Neighbors', s=100)

        plt.title(title)
        plt.legend(loc="upper right")
        plt.pause(0.5)  # Pause to show animation step-by-step

    m, n = len(grid), len(grid[0])
    offsets = [0, 1, 0, -1, 0]  # Directions for BFS

    plt.figure(figsize=(6, 6))  # Initialize the figure
    plot_grid(grid, title="Initial Grid")  # Show the initial grid

    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:  # Found a new island
                queue = [(i, j)]
                grid[i][j] = 0  # Mark visited
                plot_grid(grid, current=(i, j), title=f"Start BFS at ({i}, {j})")

                while queue:
                    x, y = queue.pop(0)
                    neighbors = []  # Track neighbors to highlight
                    for k in range(4):
                        r, c = x + offsets[k], y + offsets[k + 1]
                        if 0 <= r < m and 0 <= c < n and grid[r][c] == 1:
                            grid[r][c] = 0  # Mark neighbor as visited
                            queue.append((r, c))
                            neighbors.append((r, c))
                    plot_grid(grid, current=(x, y), neighbors=neighbors,
                              title=f"Processing ({x}, {y})")

    plot_grid(grid, title="Final Grid")
    plt.show()

# Example grid for testing
grid = [
    [1, 1, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 1, 1],
]

visualize_bfs(grid)
