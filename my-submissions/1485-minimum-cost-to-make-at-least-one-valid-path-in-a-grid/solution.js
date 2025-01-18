/**
 * @param {number[][]} grid
 * @return {number}
 */
const minCost = grid => {
    const rows = grid.length;
    const cols = grid[0].length;
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]; 
    const pq = new MinPriorityQueue({ priority: (x) => x[2] });
    const costs = Array.from({ length: rows }, () => Array(cols).fill(Infinity));
    costs[0][0] = 0;

    pq.enqueue([0, 0, 0]);

    while (!pq.isEmpty()) {
        const [x, y, cost] = pq.dequeue().element;

        for (let d = 0; d < 4; d++) {
            const nx = x + directions[d][0];
            const ny = y + directions[d][1];
            const newCost = cost + (grid[x][y] === d + 1 ? 0 : 1);

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && newCost < costs[nx][ny]) {
                costs[nx][ny] = newCost;
                pq.enqueue([nx, ny, newCost]);
            }
        }
    }

    return costs[rows - 1][cols - 1];
};

