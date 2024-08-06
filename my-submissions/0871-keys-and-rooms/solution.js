/**
 * @param {number[][]} rooms
 * @return {boolean}
 */

function DFS(v, rooms,visited,result) {
    visited[v] = true;
    result.push(v);
    // now go recursiverly on the v adjacent nodes;
    for(let i = 0;i<rooms[v].length;i++){
        if(!visited[rooms[v][i]]){
            DFS(rooms[v][i],rooms,visited,result);
        }
    }
}

var canVisitAllRooms = function (rooms) {
    let V = rooms.length;
    let result = [];
    let visited = new Array(V);
    for (let i = 0; i < V; i++) visited[i] = false
    DFS(0,rooms,visited,result) // 0 means start the DFS from the 0 node
    // now check if result have all the elements or not;
    result.sort((a,b) => {
        return a-b;
    })
    if(result.length != V) return false;
    for(let i = 0;i<V;i++){
        if(result[i] != i) return false;
    }
    return true;
};
