/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function (points) {
    let width = points[0].length;
    let current = new Array(width).fill(0);
    let previous = new Array(width);


    for (let i = 0; i < width; i++) {
        previous[i] = points[0][i];
    }

    for (let row = 1; row < points.length; row++) {
        let peak = 0;

        // Forward sweep
        for (let col = 0; col < width; col++) {
            peak = Math.max(peak - 1, previous[col]);
            current[col] = points[row][col] + peak;
        }

        peak = 0;

        // Backward sweep
        for (let col = width - 1; col >= 0; col--) {
            peak = Math.max(peak - 1, previous[col]);
            current[col] = Math.max(current[col], points[row][col] + peak);
        }


        [previous, current] = [current, previous];
    }


    return Math.max(...previous);
};

