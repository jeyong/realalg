function Graph() {
    this.vertexs = [ [1, 2], [0, 3, 4], [0, 4], [1, 4], [1, 2, 3] ];
    this.BFTraversal = BFTraversal;
}

function BFTraversal(source) {
    q = [];
    visited = [];
    q.push(source);

    while(q.length > 0) {
        cur = q.shift();
        if (visited[cur] == true) {
            continue;
        }
        console.log(cur.toString())
        visited[cur] = true;
        neighbors = this.vertexs[cur];
        var i;
        for (i=0; i<neighbors.length; i++){
            n = neighbors[i];
            if (visited[n] != true) {
                q.push(n)
            }
        }
    }
}

g = new Graph();

g.BFTraversal(0);
