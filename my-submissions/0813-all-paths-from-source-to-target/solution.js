/**
 * @param {number[][]} graph
 * @return {number[][]}
 */


function DFS(start, temp, graph,result) {
    let len = graph[start].length;
    temp = [...temp, start]
    for (let i = 0; i < len; i++) {
        let ele = graph[start][i];
        if (ele != graph.length - 1) {
            DFS(ele, temp, graph,result);
        } else {
            result.push([...temp, ele]);
        }
    }
    return result;
}


var allPathsSourceTarget = function (graph) {
    let start = 0;
    let result = [];
    return DFS(start, [], graph,result)
};

